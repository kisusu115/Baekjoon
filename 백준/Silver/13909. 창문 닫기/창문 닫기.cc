#include<iostream>
#include<cmath>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	int num = 1;
	int cnt = 0;
	while ((num*num) <= n) {
		num++;
		cnt++;
	}
	cout << cnt;
}