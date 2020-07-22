#include <bits/stdc++.h>
using namespace std;

int main() {
	int N;
	cin >> N;

	vector<pair<int,int>> pair_list(N);

	for (int i=0;i<N;i++){
		int a,b;
		cin >> a >> b;
		pair_list.at(i) = make_pair(b,a);

	}

	sort(pair_list.begin(),pair_list.end());

	for (int i=0;i<N;i++){
		int a,b;
		tie(b,a) = pair_list.at(i);
		cout << a << " " << b << endl;
	}

}
