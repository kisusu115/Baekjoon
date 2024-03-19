#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;

		vector<int> vt1; vector<int> vt2; //스티커 값 저장 배열
		vector<int> mx1; vector<int> mx2; //스티커 인덱스 별 최대값 저장 배열

		for (int i = 0; i < n; i++) {
			int ipt;
			cin >> ipt;
			vt1.push_back(ipt);
		}
		for (int i = 0; i < n; i++) {
			int ipt;
			cin >> ipt;
			vt2.push_back(ipt);
		}

		//최대값 도출 과정
		for (int i = 0; i < n; i++) {
			if (i == 0) {
				mx1.push_back(vt1[i]);
				mx2.push_back(vt2[i]);
			}
			else if (i == 1) {
				mx1.push_back(vt2[i - 1] + vt1[i]);
				mx2.push_back(vt1[i - 1] + vt2[i]);
			}
			else {
				mx1.push_back(max(mx2[i - 1] + vt1[i], mx2[i - 2] + vt1[i]));
				mx2.push_back(max(mx1[i - 1] + vt2[i], mx1[i - 2] + vt2[i]));
			}
		}
		cout << max(mx1[n-1], mx2[n-1]) << "\n";
	}

	return 0;
}