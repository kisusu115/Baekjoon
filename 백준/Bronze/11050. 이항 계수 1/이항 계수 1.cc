#include<iostream>

using namespace std;

int facto(int n) {
	if (n == 0) return 1;
	else return n*facto(n - 1);
}

int main() {
	int n, k;
	cin >> n >> k;
	cout << facto(n) / facto(k) / facto(n - k);
}