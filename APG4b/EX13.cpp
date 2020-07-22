#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> a_vec(N);
  int sum = 0;

  for (int i=0;i<N;i++){
	  cin >> a_vec.at(i);
	  sum += a_vec.at(i);
  }
  int ave = sum / N;

  for (int i=0;i<N;i++){
	  cout << abs(ave-a_vec.at(i)) << endl;
  }

}
