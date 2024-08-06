#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
vector<int> rope;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int ipt; cin >> ipt;
		rope.push_back(ipt);
	}
	
	sort(rope.begin(), rope.end());
	int m = -1;
	for (int i = 0; i < N; i++) {
		int h = (N - i) * rope[i];
		if (h > m) m = h;
	}

	cout << m;
	return 0;
}