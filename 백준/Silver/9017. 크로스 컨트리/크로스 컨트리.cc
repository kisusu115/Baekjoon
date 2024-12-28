#include<bits/stdc++.h>

using namespace std;
int order[1001];
int score[202];
int scoreCnt[202];
int people[202];
int fifth[202];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int T; cin >> T;
	while (T--) {
		memset(order, 0, sizeof(order));
		memset(score, 0, sizeof(score));
		memset(scoreCnt, 0, sizeof(scoreCnt));
		memset(people, 0, sizeof(people));
		memset(fifth, 0, sizeof(fifth));

		int N; cin >> N;
		for (int i = 0; i < N; i++) {
			cin >> order[i];
			int teamNum = order[i];
			people[teamNum]++;
			if (people[teamNum] == 5) {
				fifth[teamNum] = i;
			}
		}

		int point = 1;
		for (int i = 0; i < N; i++) {
			int teamNum = order[i];
			if (people[teamNum] != 6) continue;
			scoreCnt[teamNum]++;
			if (scoreCnt[teamNum] < 5) {
				score[teamNum] += point;
			}
			point++;
		}

		int minScore = 99999999;
		int firstTeamNum = 1;
		for (int teamNum = 1; teamNum <= 200; teamNum++) {
			if (people[teamNum] != 6) continue;
			if (minScore > score[teamNum]) {
				minScore = score[teamNum];
				firstTeamNum = teamNum;
			}
			else if (minScore == score[teamNum]) {
				if (fifth[firstTeamNum] > fifth[teamNum]) {
					firstTeamNum = teamNum;
				}
			}
		}

		cout << firstTeamNum << "\n";
	}
	return 0;
}