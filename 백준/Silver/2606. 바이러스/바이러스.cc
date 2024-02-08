#include<iostream>
#include<string>

using namespace std;

int visited[101] = { 0 };		   //해당 N번째 컴퓨터 방문여부 저장
int PC_linkedNum[101] = { 0 };	   //해당 N번째 컴퓨터의 다른 컴퓨터 연결 시 인덱스 저장
int linked_data[101][100] = { 0 }; //해당 N번째 컴퓨터의 연결된 컴퓨터 M들을 저장

void dfs(int n) {
	if (visited[n]) return;
	visited[n] = 1;

	while (linked_data[n][PC_linkedNum[n]] != 0) {
		PC_linkedNum[n]++;
		dfs(linked_data[n][PC_linkedNum[n]-1]);
	}
}

int main() {
	int PC, links;

	cin >> PC;
	cin >> links;
	for (int i = 1; i <= links; i++) {
		int ipt1, ipt2;
		cin >> ipt1 >> ipt2;
		linked_data[ipt1][PC_linkedNum[ipt1]++] = ipt2;
		linked_data[ipt2][PC_linkedNum[ipt2]++] = ipt1;
	}

	for (int i = 0; i <= PC; i++) {
		PC_linkedNum[i] = 0;
	}
	
	dfs(1);

	int virus_count = 0;
	for (int i = 2; i <= PC; i++) {
		if (visited[i] == 1) virus_count++;
	}
	cout << virus_count;

	return 0;
}