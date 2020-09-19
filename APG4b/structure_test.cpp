#include <bits/stdc++.h>
using namespace std;

struct MyPair{
	int x;
	string y;

	MyPair(int _x,string _y){
		cout << "constructor called !!!" << endl;
		x = _x;
		y = _y;
	}

	void print(){
		cout << "x = " << x << endl;
		cout << "y = " << y << endl;
	}
};

int main(){
	MyPair p(6789,"hikisu");
	//p.x = 12345;
	//p.y = "text";
	p.print();
}
