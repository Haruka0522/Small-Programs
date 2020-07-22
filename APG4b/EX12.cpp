#include <bits/stdc++.h>
using namespace std;

int main() {
  string S;
  cin >> S;

  // ここにプログラムを追記
  int sum = 1;
  for (int i=1;i<S.size();i+=2){
	  if (S.at(i) == '+')
		  sum ++;
	  else
		  sum --;
  }
  cout << sum << endl;

}
