#include<iostream>
#include<algorithm>

using namespace std;

int main() {
	int n;
	cin >> n;
	int P[1000];

	for (int i = 0; i < n; i++) {
		cin >> P[i];
	}
	sort(P, P+n);

	int sum = P[0];
	for (int i = 1; i < n; i++) {
		P[i] = P[i-1] + P[i];
		sum += P[i];
	}
	cout << sum;
	return 0;
}