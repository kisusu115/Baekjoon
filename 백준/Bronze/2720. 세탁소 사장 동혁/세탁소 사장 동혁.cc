#include<iostream>

using namespace std;

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int ith_cost;
		int output[4] = { 0 };

		cin >> ith_cost;
		output[0] = ith_cost / 25;
		ith_cost = ith_cost % 25;
		output[1] = ith_cost / 10;
		ith_cost = ith_cost % 10;
		output[2] = ith_cost / 5;
		ith_cost = ith_cost % 5;
		output[3] = ith_cost;

		cout << output[0] << " " << output[1] << " " << output[2] << " " << output[3] << "\n";
	}

	return 0;
}