#include<iostream>

using namespace std;

int arr[46] = {0,};

int fibo(int m) {
	if (arr[m] != -1) return arr[m];
	int ret = fibo(m - 1) + fibo(m - 2);
	arr[m] = ret;
	return ret;
}

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
	for (int i = 0; i < 46; i++) arr[i] = -1;

	arr[0] = 0;
	arr[1] = 1;
	int n;
	cin >> n;
	cout << fibo(n);

	return 0;
}