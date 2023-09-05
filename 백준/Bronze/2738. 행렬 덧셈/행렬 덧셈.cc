#include<iostream>

using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	int arr1[100][100], arr2[100][100], arr3[100][100];

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr1[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr2[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			arr3[i][j] = arr1[i][j] + arr2[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << arr3[i][j] << ' ';
		}
		cout << endl;
	}
}