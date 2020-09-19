#include <bits/stdc++.h>
using namespace std;

int main() {
	int vals[] = {4,7,11};
	int *valptr;
	valptr = vals;
	cout << vals[0] << endl;
	cout << *(valptr+1) << endl;
	cout << vals << endl;
	cout << *(vals) << endl;
	string a = "0x7ffe589397ec";
	cout << *(&a) << endl;
}
