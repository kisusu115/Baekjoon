#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>

using namespace std;
int N;
vector<string> V;
pair<long long, int> score[27];
int num[27];

bool compare(pair<long long, int> A, pair<long long, int> B) {
	return A.first > B.first;
}

int makeN(string str) {
	int sum = 0;
	int length = str.length();
	for (int i = 0; i < length; i++) {
		sum += num[int(str[length - 1 - i]) - int('A')] * pow(10, i);
	}
	return sum;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N;

	for (int i = 0; i < N; i++) {
		string str; cin >> str;
		V.push_back(str);
		int L = str.length();

		for (int j = 0; j < L; j++) {
			score[int(str[j]) - int('A')].first += pow(10, L- j - 1);
		}
	}
	for (int i = 0; i < 27; i++) {
		score[i].second = i;
	}
	sort(score, score + 27, compare);
	for (int i = 0; i < 10; i++) {
		num[score[i].second] = 9 - i;
	}

	int sum = 0;
	for (string str : V) {
		sum += makeN(str);
	}
	cout << sum;

	return 0;
} 