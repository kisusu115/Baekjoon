#include<iostream>
#include<cmath>

using namespace std;

int get_binary_1(int n) {
	int ret_val = 0;
	while (n != 0)
	{
		if (n == 1) { ret_val++; break; }
		if (n == 2) { ret_val++; break; }
		if (n % 2 == 1) ret_val++;
		n /= 2;
	}
	return ret_val;
}

int get_min_jump(int n) {
	if (n == 1) return 1;
	if (n == 2) return 1;
	int tmp = 1;
	while (tmp < n) {
		tmp *= 2;
	}
	return min(get_binary_1(n), get_min_jump(tmp - n) + 1);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N, K;
	cin >> N >> K;

	int num_over;
	N == 0 ? num_over = 1 : num_over = N;
	int jump_stk = 0;

	if (num_over == K) { N == 0 ? cout << 1 : cout << 0; return 0; }
	if (num_over > K) { cout << N - K; return 0; }

	while (num_over <= K) {
		num_over *= 2;
		jump_stk++;
	}
	int t1 = 0; int t2 = 0;
	int d1 = K - (num_over / 2);
	int d2 = num_over - K;
	int j_distance = pow(2, jump_stk);
	if (d1 == 0) { cout << 0; return 0; }

	t1 += (2 * d1) / j_distance;
	t2 += d2 / j_distance;

	int d1_remain = d1 % (j_distance / 2);
	int d2_remain = d2 % j_distance;

	int teleport_1 = t1 + get_min_jump(d1_remain);
	int teleport_2 = t2 + get_min_jump(d2_remain);
	if (N == 0) { teleport_1++; teleport_2++; }

	teleport_1 <= teleport_2 ? cout << teleport_1 : cout << teleport_2;
	return 0;
}