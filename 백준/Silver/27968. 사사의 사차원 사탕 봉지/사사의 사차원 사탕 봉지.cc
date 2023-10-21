#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(int argc, char* argv[]) { // 이제부터 써 습관 ㄱㄱ
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;

	vector<long long> vect;
	long long sum = 0;

	for (int i = 0; i < m; i++) {
		long long ipt;
		cin >> ipt;
		sum += ipt;
		vect.push_back(sum);
	}

	for (int i = 0; i < n; i++) {
		long long ipt2;
		cin >> ipt2;
		if (lower_bound(vect.begin(), vect.end(), ipt2) == vect.end()) {
			cout << "Go away!\n";
		}
		else {
			cout << lower_bound(vect.begin(), vect.end(), ipt2) - vect.begin() + 1 << "\n";
		}
	}

	return 0;
}