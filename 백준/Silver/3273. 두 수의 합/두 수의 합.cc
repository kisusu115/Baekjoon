#include<bits/stdc++.h>

using namespace std;
vector<int> nums;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int ipt, N; cin >> N;
	while (N--) {
		cin >> ipt;
		nums.push_back(ipt);
	}
	int X; cin >> X;

	sort(nums.begin(), nums.end());

	int p1 = 0; int p2 = nums.size() - 1;
	int pair = 0;

	while (1) {
		int cal = nums[p1] + nums[p2];

		if (cal > X) p2--;
		else if (cal < X) p1++;

		else {
			pair++;
			p1++; p2--;
		}

		if (p1 >= p2) break;
	}

	cout << pair;
	return 0;
}