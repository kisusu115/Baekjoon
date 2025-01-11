#include<bits/stdc++.h>

using namespace std;

int k, nums[14], output[6];

void dfs(int start, int selectedN) {
	if (selectedN == 6) {
		for (int i = 0; i < 6; i++) {
			cout << output[i] << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = start; i < k; i++) {
		output[selectedN] = nums[i];
		dfs(i + 1, selectedN + 1);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	while (1) {
		memset(nums, 0, sizeof(nums));
		cin >> k; 
		if (k == 0) break;

		for (int i = 0; i < k; i++) cin >> nums[i];
		dfs(0, 0);
		cout << "\n";
	}

	return 0;
}