#include <iostream>
#include <vector>
using namespace std;

int main() {
	while (true) {
		vector<int> vect;
		int sum = 0;
		int n;
		cin >> n;

		if (n == -1) break;
		for (int i = 1; i < n; i++) {
			if (n % i == 0) {
				sum += i;
				vect.push_back(i);
			}
		}
		if (sum == n) {
			cout << n << " = " << vect[0];
			for (int i = 1; i < vect.size(); i++) {
				cout << " + " << vect[i];
			}
			cout << "\n";
		}	
		else {
			cout << n << " is NOT perfect." << "\n";
		}
	}

	return 0;
}