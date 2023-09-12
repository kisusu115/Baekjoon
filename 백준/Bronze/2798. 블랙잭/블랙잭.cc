#include <iostream>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	int max = 0;

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int cards[100];

	for (int i = 0; i < n; i++) {
		cin >> cards[i];
	}

	for (int i = 0; i < n-2; i++) {
		for (int j = i + 1; j < n-1; j++) {
			for (int k = j + 1; k < n; k++) {
				if (cards[i] + cards[j] + cards[k] > max && cards[i] + cards[j] + cards[k] <= m) {
					max = cards[i] + cards[j] + cards[k];
				}
			}
		}
	}

	cout << max;
}