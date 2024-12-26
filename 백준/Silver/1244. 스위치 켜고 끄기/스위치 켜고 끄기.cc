#include<bits/stdc++.h>

using namespace std;
vector<bool> switches;
vector<int> students_G, students_N;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int N, ipt; 
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> ipt;
		switches.push_back(ipt);
	}

	int S, ipt1, ipt2;
	cin >> S;
	for (int i = 0; i < S; i++) {
		cin >> ipt1 >> ipt2;
		students_G.push_back(ipt1);
		students_N.push_back(ipt2 - 1);
	}

	for (int i = 0; i < students_G.size(); i++) {
		if (students_G[i] == 1) {
			int idx = students_N[i];
			while (idx < N) {
				switches[idx] = !switches[idx];
				idx += students_N[i] + 1;
			}
		}
		else {
			int idx = students_N[i];
			switches[idx] = !switches[idx];

			int idx1 = idx - 1, idx2 = idx + 1;
			while (idx1 >= 0 && idx2 < N) {
				if (switches[idx1] == switches[idx2]) {
					switches[idx1] = !switches[idx1];
					switches[idx2] = !switches[idx2];
					idx1--; idx2++;
				}
				else break;
			}
		}
	}

	for (int i = 0; i < switches.size(); i++) {
		int s = switches[i];
		cout << s << " ";
		if ((i + 1) % 20 == 0) cout << "\n";
	}
	return 0;
}