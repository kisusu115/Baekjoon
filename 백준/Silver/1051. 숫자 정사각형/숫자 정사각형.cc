#include<iostream>
#include<vector>
#include<map>
#include<string>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	char arr[50][50];
	int n, m;
	cin >> n >> m;
	int min;
	if (n <= m ? min = n : min = m);

	for (int i = 0; i < n; i++) {
		string ipt;
		cin >> ipt;
		for (int j = 0; j < m; j++) {
			arr[i][j] = ipt[j];
		}
	}

	int maxleng = 1;

	for (int leng = 0; leng < min; leng++) {
		for (int i = 0; i < n-leng; i++) {
			for (int j = 0; j < m-leng; j++) {
				if (arr[i][j] == arr[i + leng][j] && arr[i][j] == arr[i][j + leng] && arr[i][j] == arr[i + leng][j + leng]) {
					maxleng = leng + 1;
				}
			}
		}
	}

	cout << maxleng*maxleng;
}