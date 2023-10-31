#include<iostream>
#include<algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int a[3];
	cin >> a[0] >> a[1] >> a[2];
	sort(a, a + 3);
	if (a[0] + a[1] > a[2]) cout << a[0] + a[1] + a[2];
	else cout << (a[0] + a[1]) * 2 - 1;
}
