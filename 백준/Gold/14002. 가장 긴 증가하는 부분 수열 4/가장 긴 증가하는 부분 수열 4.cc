#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

int DP[1001];
string SDP[1001];
int arr[1001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N; cin >> N;
	for (int i = 0; i < N; i++) cin >> arr[i];

	int longest = 0;
	int longidx = 0;
	for (int i = 0; i < N; i++) {
		int maxi = 0;
		string str = "";

		for (int j = 0; j < i; j++)
		{
			if (arr[i] <= arr[j]) continue;
			if (maxi < DP[j]) {
				maxi = DP[j];
				str = SDP[j];
			}
		}

		DP[i] = maxi + 1;
		SDP[i] = str + to_string(arr[i]) + " ";

		if (longest < DP[i]) {
			longest = DP[i];
			longidx = i;
		}
	}

	cout << longest << "\n" << SDP[longidx];
	return 0;
}