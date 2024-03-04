#include<iostream>
#include<vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	vector<int> QorS;
	vector<int> queuestack;
	vector<int> secondIpt;
	vector<int> shelf;

	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int ipt1;
		cin >> ipt1;
		QorS.push_back(ipt1);
	}
	for (int i = 0; i < N; i++) {
		int ipt2;
		cin >> ipt2;
		queuestack.push_back(ipt2);
	}

	int num_of_zero = 0;
	for (int i = N-1; i >=0 ; i--) {
		if (QorS[i] == 0) {
			num_of_zero++;
			shelf.push_back(queuestack[i]);
		}
	}

	int M;
	cin >> M;
	for (int i = 0; i < M; i++) {
		int ipt;
		cin >> ipt;
		secondIpt.push_back(ipt);
	}

	if (M <= num_of_zero) {
		for (int i = 0; i < M; i++) {
			cout << shelf[i] << " ";
		}
	}
	else {
		for (int i = 0; i < shelf.size(); i++) {
			cout << shelf[i] << " ";
		}
		for (int i = 0; i < M - shelf.size(); i++) {
			cout << secondIpt[i] << " ";
		}
	}

	return 0;
}