#include<iostream>
#include<vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N, M;
	cin >> N >> M;
	int add = 0;

	vector<int> vect;
	vect.push_back(0);
	for (int i = 0; i < N; i++) {
		int ipt;
		cin >> ipt;
		add += ipt;
		vect.push_back(add);
	}

	for (int i = 0; i < M; i++) {
		int ipt1, ipt2;
		cin >> ipt1 >> ipt2;
		cout << vect[ipt2] - vect[ipt1-1] << "\n";
	}
}