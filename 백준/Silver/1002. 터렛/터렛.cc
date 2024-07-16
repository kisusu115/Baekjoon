#include<iostream>
#include<cmath>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int x1, y1, d1, x2, y2, d2;
	double p2p = 0;
	int T;
	cin >> T;
	while (T--) {
		cin >> x1 >> y1 >> d1;
		cin >> x2 >> y2 >> d2;

		p2p = sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));
		if(x1 == x2 && y1 == y2 && d1 == d2){
			cout << -1 << "\n";
		}
		else if (p2p < d1 + d2 && p2p > (d1 - d2 >= 0 ? d1 - d2 : d2 - d1)) {
			cout << 2 << "\n";
		}
		else if (p2p == d1 + d2 || p2p == (d1 - d2 >= 0 ? d1 - d2 : d2 - d1)) {
			cout << 1 << "\n";
		}
		else{
			cout << 0 << "\n";
		}
	}
}