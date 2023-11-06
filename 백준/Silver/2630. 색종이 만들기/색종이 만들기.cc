#include<iostream>
#include<algorithm>
using namespace std;

int Arr[128][128] = { 0 };
int Wcount = 0;
int Bcount = 0;

void cutPaper(int x, int y, int size) {
	int sum=0;
	if (size == 1) {
		if (Arr[x][y] == 0) {
			Wcount++;
			return;
		}
		else if (Arr[x][y] == 1) {
			Bcount++;
			return;
		}
	}
	for (int i = x; i < x + size; i++) {
		for (int j = y; j < y + size; j++) {
			sum += Arr[i][j];
		}
	}
	if (sum == 0) {
		Wcount++;
		return;
	}
	else if (sum == size*size) {
		Bcount++;
		return;
	}
	else {
		cutPaper(x, y, size / 2);
		cutPaper(x + size / 2, y, size / 2);
		cutPaper(x, y + size / 2, size / 2);
		cutPaper(x + size / 2, y + size / 2, size / 2);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> Arr[i][j];
		}
	}

	cutPaper(0,0,n);

	cout << Wcount << "\n" << Bcount;
}