#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

class BigInteger
{
private:
    int data[500];
    int length;
    int sign;
    bool first_big(const int *x, int lenx, const int *y, int leny) const;
    BigInteger mysum(const int *x, int lenx, const int *y, int leny) const;
    BigInteger myminus(const int *x, int lenx, const int *y, int leny) const;
    BigInteger numxarray(const int *x, int lenx, int num) const;

public:
    BigInteger()
    {
        length = 1;
        sign = 1;
        memset(data, 0, sizeof(data));
    }
    BigInteger(const char*);

    BigInteger& operator=(const BigInteger &);
    BigInteger operator+(const BigInteger &) const;
    BigInteger operator-(const BigInteger &) const;
    BigInteger operator*(const BigInteger &) const;
    void show();
};

BigInteger::BigInteger(const char *array)
{
    length = strlen(array);
    sign = 1;
    memset(data, 0, sizeof(data));
    for(int i = 0; i < length; i ++) data[i] = array[i] - '0';
}

bool BigInteger::first_big(const int *x, int lenx, const int *y, int leny) const
{
    if(lenx > leny) return true;
    else if(lenx < leny) return false;
    for(int i = 0; i < lenx; i ++) if(x[i] < y[i]) return false;
    return true;
}

BigInteger BigInteger::mysum(const int *x, int lenx, const int *y, int leny) const
{
    int curx = lenx - 1, cury = leny - 1,curres = 0;
    char *resarray = new char[(lenx > leny ? lenx : leny) + 1];
    int sup = 0, tmp = 0;
    while(curx >= 0 && cury >= 0) {
        tmp = x[curx --] + y[cury --] + sup;
        sup = tmp / 10;
        tmp = tmp % 10;
        resarray[curres ++] = (char)tmp + '0';
    }
    while(curx >= 0) {
        tmp = x[curx --] + sup;
        sup = tmp / 10;
        tmp = tmp % 10;
        resarray[curres ++] = (char)tmp + '0';
    }
    while(cury >= 0) {
        tmp = y[cury --] + sup;
        sup = tmp / 10;
        tmp = tmp % 10;
        resarray[curres ++] = (char)tmp + '0';
    }
    if(sup) resarray[curres ++] = (char)sup + '0';
    resarray[curres] = '\0';
    reverse(resarray, resarray + curres);
    BigInteger res(resarray);
    delete resarray;
    return res;
}

BigInteger BigInteger::myminus(const int *x, int lenx, const int *y, int leny) const
{
    int curx = lenx - 1, cury = leny - 1,curres = 0;
    char *resarray = new char[lenx];
    int tmp = 0;
    int *xcpy = new int[lenx];
    for(int i = 0; i < lenx; i ++) xcpy[i] = x[i];
    while(curx >= 0 && cury >= 0) {
        int xdigit = xcpy[curx --], ydigit = y[cury --];
        if(xdigit < ydigit) {
            int tcurx = curx;
            while(tcurx >= 0 && xcpy[tcurx] == 0) xcpy[tcurx --] = 9;
            xcpy[tcurx] --;
            xdigit += 10;
        }
        tmp = xdigit - ydigit;
        resarray[curres ++] = (char)tmp + '0';
    }
    while(curx >= 0) resarray[curres ++] = (char) xcpy[curx --] + '0';
    while(-- curres > 0 && resarray[curres] == '0') resarray[curres] = '\0';
    resarray[curres + 1] = '\0';
    reverse(resarray, resarray + curres + 1);
    BigInteger res(resarray);
    delete[] xcpy;
    return res;
}

BigInteger BigInteger::numxarray(const int *x, int lenx, int num) const
{
    char *tmparray = new char[lenx + 1];
    int sup = 0, cur = 0;
    for(int i = lenx - 1; i >= 0; i --) {
        int tmp = x[i] * num + sup;
        sup = tmp / 10;
        tmp = tmp % 10;
        tmparray[cur ++] = tmp + '0';
    }
    if(sup) tmparray[cur ++] = sup + '0';
    tmparray[cur] = '\0';
    reverse(tmparray, tmparray + cur);
    BigInteger res(tmparray);
    delete[] tmparray;
    return res;
}

BigInteger& BigInteger::operator=(const BigInteger &Y)
{
    length = Y.length;
    sign = Y.sign;
    for(int i = 0; i < length; i ++) data[i] = Y.data[i];
    return (* this);
}

BigInteger BigInteger::operator+(const BigInteger &Y) const
{
    const int *x = data;
    const int *y = Y.data;
    int lenx = length, leny = Y.length;
    return mysum(x, lenx, y, leny);
}

BigInteger BigInteger::operator-(const BigInteger &Y) const
{
    const int *x = data;
    const int *y = Y.data;
    int lenx = length, leny = Y.length;
    bool flag = first_big(x, lenx, y, leny);
    BigInteger res;
    if(flag) res = myminus(x, lenx, y, leny);
    else {
        res = myminus(y, leny, x, lenx);
        res.sign = - 1;
    }
    return res;
}

BigInteger BigInteger::operator*(const BigInteger &Y) const
{
    const int *x = data;
    const int *y = Y.data;
    int lenx = length, leny = Y.length;
    BigInteger last("0");
    if((lenx == 1 && x[0] == 0) || (leny == 1 && y[0] == 0)) return last;
    for(int i = leny - 1; i >= 0; i --) {
        BigInteger current = numxarray(x, lenx, y[i]);
        current.length += leny - 1 - i;
        last = last + current;
    }
    return last;
}

void BigInteger::show()
{
    if(sign == - 1) cout << '-';
    for(int i = 0; i < length; i ++) cout << data[i];
    cout << endl;
}

int main(void)
{
    int i, n;
    char op;
    char num1[500] = {0};
    char num2[500] = {0};
    while (cin >> num1 >> op >> num2)
    {
        BigInteger a(num1), b(num2), c;
        switch (op)
        {
            case '+':
                c = a + b;
                break;
            case '-':
                c = a - b;
                break;
            case '*':
                c = a * b;
                break;
        }
        c.show();
        memset(num1, 0, sizeof(num1));
        memset(num2, 0, sizeof(num2));
    }
}
