#include<iostream>
#include<cmath>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;

	while (N--) {
		long long iptn;
		cin >> iptn;

		if (iptn == 0 || iptn == 1) {
			cout << 2 << "\n";
			continue;
		}
		while (1) {
			bool approved = true;
			for (int i = 2; i <= sqrt(iptn); i++) {
				if (iptn % i == 0) {
					approved = false;
					break;
				}
			}
			if (approved) break;
			iptn++;
		}
		cout << iptn << "\n";
	}

	return 0;
}