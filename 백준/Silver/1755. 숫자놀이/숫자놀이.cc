#include<bits/stdc++.h>

using namespace std;
map<int, string> strMap;

bool cmp(int n1, int n2) {
	int f1, s1, f2, s2;

	if (n1 >= 10) { f1 = n1 / 10; s1 = n1 % 10; }
	else { f1 = n1 % 10; s1 = 0; }

	if (n2 >= 10) { f2 = n2 / 10; s2 = n2 % 10; }
	else { f2 = n2 % 10; s2 = 0; }

	if (n1 < 10) s1 = -1;
	if (n2 < 10) s2 = -1;

	if(f1 == f2) return strMap[s1] < strMap[s2];
	else return strMap[f1] < strMap[f2];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	strMap.insert({ -1, " " });
	strMap.insert({ 1, "one" });
	strMap.insert({ 2, "two" });
	strMap.insert({ 3, "three" });
	strMap.insert({ 4, "four" });
	strMap.insert({ 5, "five" });
	strMap.insert({ 6, "six" });
	strMap.insert({ 7, "seven" });
	strMap.insert({ 8, "eight" });
	strMap.insert({ 9, "nine" });
	strMap.insert({ 0, "zero" });

	int M, N;
	cin >> M >> N;

	vector<int> nums;
	for (int i = M; i <= N; i++) nums.push_back(i);
	sort(nums.begin(), nums.end(), cmp);

	for (int i = 0; i < nums.size(); i++) {
		cout << nums[i] << " ";
		if (i % 10 == 9) cout << "\n";
	}

	return 0;

}