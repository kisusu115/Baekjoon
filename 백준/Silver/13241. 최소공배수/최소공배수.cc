#include<iostream>
#include<string>

using namespace std;

int main() {
	int a, b;
	cin >> a >> b;

	if (a == b) {
		cout << a; return 0;
	}

	if (a > 1000 && b > 1000) {
		long long a_mult_big = a; 
		long long b_mult_big = b;
		while (a_mult_big != b_mult_big) {
			if (a_mult_big < b_mult_big) a_mult_big += a;
			else b_mult_big += b;
		}
		cout << a_mult_big;
	}
	else {
		int a_mult_small = a;
		int b_mult_small = b;
		while (a_mult_small != b_mult_small) {
			if (a_mult_small < b_mult_small) a_mult_small += a;
			else b_mult_small += b;
		}
		cout << a_mult_small;
	}

	return 0;
}