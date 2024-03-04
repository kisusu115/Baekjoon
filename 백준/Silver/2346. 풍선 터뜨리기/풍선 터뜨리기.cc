#include<iostream>
#include<vector>
#include<deque>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;
	vector<int> vect;
	vector<int> vect2;
	deque<int> deq;

	for (int i = 0; i < N; i++) {
		int ipt;
		cin >> ipt;
		vect.push_back(ipt);
		deq.push_back(i+1);
	}
	int rotate = vect[0];
	deq.pop_front();

	for (int i = 0; i < N-1; i++) {
		if (rotate > 0) {
			for (int j = 0; j < rotate - 1; j++) {
				deq.push_back(deq.front());
				deq.pop_front();
			}
			rotate = vect[deq.front()-1];
			vect2.push_back(deq.front());
			deq.pop_front();
		}
		else {
			for (int j = 0; j < -1*(rotate + 1); j++) {
				deq.push_front(deq.back());
				deq.pop_back();
			}
			rotate = vect[deq.back()-1];
			vect2.push_back(deq.back());
			deq.pop_back();
		}
	}
	cout << 1;
	for (int i = 0; i < N-1; i++) {
		cout << " " << vect2[i];
	}

	return 0;
}