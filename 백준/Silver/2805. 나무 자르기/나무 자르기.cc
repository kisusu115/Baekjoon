#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	long long n, m;
	cin >> n >> m;
	vector<long long> vec;
	stack<long long> stk;
	

	for (int i = 0; i < n; i++) {
		long long ipt;
		cin >> ipt;

		vec.push_back(ipt);
	}
	sort(vec.begin(), vec.end());

	stk.push(vec[0]);
	for (int i = 1; i < n; i++) {
		stk.push(vec[i] - vec[i - 1]);
	}

	long long treeNum = 0;
	long long treeTall = 0;
	long long sum = 0;
	while (!stk.empty()) {
		treeNum++;
		sum += treeNum * stk.top();
		treeTall += stk.top();
		long long tmp = stk.top();
		stk.pop();
		if (sum > m) {
			sum -= treeNum * tmp;
			treeTall -= tmp;
			while (sum < m) {
				treeTall++;
				sum += treeNum;
			}
			break;
		}
	}
	cout << vec[n-1] - treeTall;
}
