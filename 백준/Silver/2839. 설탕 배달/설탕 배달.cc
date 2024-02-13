#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int sArr[5000] = { 0 };

int bring(int kg) {
	if (sArr[kg] != 0) return sArr[kg];
	int ret = min(bring(kg - 3), bring(kg - 5)) + 1;
	sArr[kg] = ret;
	return ret;
}

int main() {
	int ipt, ret;
	sArr[3] = 1;
	sArr[5] = 1;
	sArr[1] = 1667;
	sArr[2] = 1667;
	sArr[4] = 1667;
	cin >> ipt;
	ret = bring(ipt);
	if (ret >= 1667) cout << -1;
	else cout << ret;
}