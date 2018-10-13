#include<iostream>

#include "decl.h"

using namespace std;

int main() {
	string s1 = "2*(9+6/3-5)+4";
	Mid2Post mid2Post(s1);
	mid2Post.transformer();
	return 0;
}
