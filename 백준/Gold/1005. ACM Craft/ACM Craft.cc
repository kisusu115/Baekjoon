#include<iostream>
#include<queue>
#include<vector>

using namespace std;
int times[1001];
int graph[1001][1001];
int Rgraph[1001][1001];
int toCheck[1001][1001];
int DP[1001];

queue<int> Q;

void init() {
	for (int i = 0; i <= 1000; i++) {
		times[i] = 0; DP[i] = 0;
		for (int j = 0; j <= 1000; j++) graph[i][j] = 0;
		for (int j = 0; j <= 1000; j++) Rgraph[i][j] = 0;
		for (int j = 0; j <= 1000; j++) toCheck[i][j] = 0;
	}
	
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int T; cin >> T;
	while (T--) {
		int N, K, goal; cin >> N >> K;
		for (int i = 1; i <= N; i++) cin >> times[i];
		for (int i = 1; i <= K; i++) {
			int from, togo; cin >> from >> togo;
			graph[from][togo] = 1;
			Rgraph[togo][from] = 1;
			toCheck[togo][from] = 1;
		}
		cin >> goal;

		for (int i = 1; i <= N; i++) {
			bool startNode = true;
			for (int j = 1; j <= N; j++) {
				if (toCheck[i][j] == 1) startNode = false;
			}
			if (startNode) Q.push(i);
		}

		vector<int> V;
		while (!Q.empty()) {
			int node = Q.front(); Q.pop();
			V.push_back(node);
			for (int i = 1; i <= N; i++) {
				if (graph[node][i]) {
					Rgraph[i][node] = 0;
					bool nowIsStart = true;
					for (int j = 1; j <= N; j++) if(Rgraph[i][j] == 1) nowIsStart = false;
					if (nowIsStart) Q.push(i); 
				}
			}
		}

		for (int i = 0; i < N; i++) {
			int CN = V[i];
			DP[CN] = times[CN];
			int maxT = 0;
			for (int i = 1; i <= N; i++) {
				if (toCheck[CN][i]) maxT = max(maxT, DP[i]);
			}
			DP[CN] += maxT;
		}

		cout << DP[goal] << "\n";

		init();
	}
	return 0;
}