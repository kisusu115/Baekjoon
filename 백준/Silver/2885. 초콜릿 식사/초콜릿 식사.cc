#include<bits/stdc++.h>

using namespace std;
vector<int> bits;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int K; cin >> K;
	while (K != 0) {
		int b = K % 2;
		bits.push_back(b);
		K = K / 2;
	}

	int lastOneIdx = bits.size();
	for (int i = 0; i < bits.size(); i++) {
		if (bits[i] == 1) {
			lastOneIdx = i;
			break;
		}
	}
	int minV = pow(2, bits.size());
	int resultDiv = bits.size() - lastOneIdx;

	if (lastOneIdx == bits.size() - 1) {
		minV /= 2;
		resultDiv--;
	}

	cout << minV << " " << resultDiv;
	return 0;
}