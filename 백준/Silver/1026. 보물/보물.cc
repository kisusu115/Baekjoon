#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
vector<int> v1;
vector<int> v2;

bool compare(int i, int j) {
	return i > j;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		int ipt; cin >> ipt;
		v1.push_back(ipt);
	}
	for (int i = 0; i < N; i++) {
		int ipt; cin >> ipt;
		v2.push_back(ipt);
	}
	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end(), compare);
	
	int s = 0;
	for (int i = 0; i < N; i++) {
		s += v1[i] * v2[i];
	}

	cout << s;
	return 0;
}