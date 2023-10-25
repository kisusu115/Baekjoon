#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	vector<int> vectx;
	vector<int> vecty;

	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;

		vectx.push_back(x);
		vecty.push_back(y);
	}

	sort(vectx.begin(), vectx.end());
	sort(vecty.begin(), vecty.end());

	cout << (vectx[vectx.size() - 1] - vectx[0]) * (vecty[vecty.size() - 1] - vecty[0]);

	return 0;
}