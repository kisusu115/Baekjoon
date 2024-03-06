#include <iostream>
#include <algorithm>

using namespace std;

long long get_lowmult(int a, int b) {
	if (a == b)return a;
	long long a_mult = a; long long b_mult = b;
	while (a_mult != b_mult) {
		a_mult < b_mult ? a_mult += a : b_mult += b;
	}
	return a_mult;
}

long long get_slice_num(int n1, int n2) {
	if (n1 == n2) return n1;
	int ret_num = 1;
	for (int i = 2; i <= min(n1, n2); i++) {
		if (n1 % i == 0 && n2 % i == 0) {
			n1 /= i; n2 /= i;
			ret_num *= i;
			i--;
		}
	}
	return ret_num;
}

int main() {
	int a1, a2, b1, b2;
	cin >> a1 >> a2 >> b1 >> b2;

	int cut_a = get_slice_num(a1, a2);
	a1 /= cut_a; a2 /= cut_a;
	int cut_b = get_slice_num(b1, b2);
	b1 /= cut_b; b2 /= cut_b;

	long long below = get_lowmult(a2, b2);

	long long over = ((long long)a1 * below / a2) + ((long long)b1 * below / b2);

	long long cut_ret = get_slice_num(over, below);
	cout << over / cut_ret << " " << below / cut_ret;

	return 0;
}