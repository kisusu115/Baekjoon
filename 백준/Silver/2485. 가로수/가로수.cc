#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

long long uclidean(long long n1, long long n2) {
	if (n1 == n2) return n1;
	while (1) {
		n1 = n1 % n2;
		if (n1 == 0) {
			return n2;
		}
		swap(n1, n2);
	}
}

int main() {
	int N;
	long long point_before;
	vector<long long> vect;
	int ret_val = 0;

	cin >> N >> point_before;

	long long reduced_d = 1;
	for (int i = 0; i < N-1; i++) {
		long long point;
		cin >> point;

		vect.push_back(point - point_before);

		if (i == 0) reduced_d = vect[i];
		else reduced_d = uclidean(reduced_d, vect[i]);

		point_before = point;
	}

	for (int i = 0; i < N-1; i++) {
		ret_val += (vect[i] / reduced_d - 1);
	}

	cout << ret_val;
}