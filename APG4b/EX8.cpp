#include <bits/stdc++.h>
using namespace std;

int main() {
  int p;
  cin >> p;
  string text;
  int price;
  bool flag = false;

  // パターン1
  if (p == 1) {
    cin >> price;
  }

  // パターン2
  if (p == 2) {
    cin >> text;
	cin >> price;
	flag = true;
  }

  int N;
  cin >> N;

  if (flag){
  	cout << text << "!" << endl;
  }
  cout << price * N << endl;
}
