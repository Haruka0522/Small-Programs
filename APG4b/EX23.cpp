#include <bits/stdc++.h>
using namespace std;

int main(){
	int N;
	cin >> N;

	vector<int> A_vec(N);

	for (int i=0;i<N;i++){
		cin >> A_vec.at(i);
	}

	map<int,int> count_char;
	for (int a:A_vec){
		if (count_char.count(a))
			count_char.at(a)++;
		else
			count_char[a] = 1;
	}

	int max_count = 0;
	int ans = -1;

	for (int a:A_vec){
		if (max_count < count_char.at(a)){
			max_count = count_char.at(a);
			ans = a;
		}
	}

	cout << ans << " " << max_count << endl;
}
