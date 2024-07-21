#include<iostream>

using namespace std;
int ipt[100001];
int arr[100001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> ipt[i];
	}
	arr[0] = ipt[0];
	for (int i = 1; i < n; i++) {
		arr[i] = max(ipt[i], arr[i - 1] + ipt[i]);
	}
	int maxi = ipt[0];
	for (int i = 1; i < n; i++) {
		maxi = max(maxi, arr[i]);
	}
	cout << maxi;
}