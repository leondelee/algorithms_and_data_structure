#include<iostream>

#include "decl.h"

using namespace std;

int main() {
	string s1 = "2*4*2-(1+3)";
	Mid2Post mid2Post(s1);
	mid2Post.transformer();
	string res_string = mid2Post.res_string;
	cout << "Post exp is \"" << res_string << "\"." << endl;
	Calculator clt(res_string);
	clt.calculate();
	return 0;
}
