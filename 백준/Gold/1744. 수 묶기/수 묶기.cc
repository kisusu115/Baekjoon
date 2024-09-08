#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
vector<int> Parr;
int N1;
int N0;
vector<int> NParr;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N; cin >> N; int ipt;
	for (int i = 0; i < N; i++) {
		cin >> ipt;
		if (ipt > 1) Parr.push_back(ipt);
		else if (ipt == 1) N1++;
		else if (ipt == 0) N0++;
		else if (ipt < 0) NParr.push_back(ipt);
	}
	sort(Parr.begin(), Parr.end(), greater<int>());
	sort(NParr.begin(), NParr.end());

	int sum = 0;
	for (int i = 0; i < Parr.size(); i += 2) {
		if (i + 1 == Parr.size()) sum += Parr[i];
		else sum += Parr[i] * Parr[i + 1];
	}
	sum += N1;
	for (int i = 0; i < NParr.size(); i += 2) {
		if (i + 1 == NParr.size()) {
			if (N0 > 0);
			else sum += NParr[i];
		}
		else sum += NParr[i] * NParr[i + 1];
	}
	cout << sum;
	return 0;
}