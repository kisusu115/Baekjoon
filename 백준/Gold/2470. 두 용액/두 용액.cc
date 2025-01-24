#include<bits/stdc++.h>
#define ABSMAX 2000000001;

using namespace std;

int N, ipt; 
vector<int> M, P;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> ipt;
		if (ipt >= 0) P.push_back(ipt);
		else M.push_back(ipt);
	}

	sort(M.begin(), M.end(), greater<>());
	sort(P.begin(), P.end());

	if (M.size() == 0) {
		cout << P[0] << " " << P[1];
		return 0;
	}
	if (P.size() == 0) {
		cout << M[1] << " " << M[0];
		return 0;
	}

	int mAbs = ABSMAX; int pAbs = ABSMAX;
	if (M.size() != 1) mAbs = (M[0] + M[1]) * -1;
	if (P.size() != 1) pAbs = P[0] + P[1];

	int crossAbs = ABSMAX;
	int pm = 0; int pp = 0;
	int retPM = 0; int retPP = 0;

	while (1) {
		int hap = M[pm] + P[pp];

		if (abs(hap) < crossAbs) {
			crossAbs = abs(hap);
			retPM = pm;
			retPP = pp;
			if (hap == 0) break;
		}

		if (hap > 0) pm++;
		else pp++;

		if (pm >= M.size()) {
			pm--;
			break;
		}

		if (pp >= P.size()) {
			pp--;
			break;
		}
	}

	if (crossAbs > mAbs) cout << M[1] << " " << M[0];
	else if (crossAbs > pAbs) cout << P[0] << " " << P[1];
	else cout << M[retPM] << " " << P[retPP];
	return 0;
}