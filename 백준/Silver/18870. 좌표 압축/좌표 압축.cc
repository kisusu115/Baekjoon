#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	vector<int> vec;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int ipt;
		cin >> ipt;
		vec.push_back(ipt);
	}
	vector<int> vec2 = vec;
	sort(vec.begin(), vec.end());

	vec.erase(unique(vec.begin(), vec.end()), vec.end());
	for (int i = 0; i < n; i++){
		auto a = lower_bound(vec.begin(), vec.end(), vec2[i]);
		cout << a - vec.begin() << ' ';
	}
}