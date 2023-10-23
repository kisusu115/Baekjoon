#include <iostream>
#include <string>
using namespace std;

int fire[2000001];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, c;
	int count = 0;
	int student[101];

	cin >> n >> c;

	for (int i = 0; i < n; ++i) {
		cin >> student[i];
	}

	for (int i = 0; i < n; ++i) {
		for (int j = student[i]; j <= c; j += student[i]) {
			fire[j] = 1;
		}
	}

	for (int i = 0; i <= c; ++i) {
		if (fire[i] == 1) {
			++count;
		}
	}

	cout << count << endl;

	return 0;
}