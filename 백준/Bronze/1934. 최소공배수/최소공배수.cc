#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int T;
	cin >> T;

	while (T--) {
		int a, b;
		cin >> a >> b;
		int mini = min(a, b);
		int cy;

		for (int i = mini; i >=1; i--) {
			if (a % i == 0 && b % i == 0) {
				cy = i;
				break;
			}
		}
		cout << a * b / cy << "\n";
	}
}