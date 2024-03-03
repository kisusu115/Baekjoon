#include<iostream>
#include<stack>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	stack<int> sline;
	int sline_max = -1;
	bool available = true;
	int num_to_in = 1;

	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		int ipt;
		cin >> ipt;

		while (sline.size() != 0) {
			if (sline.top() == num_to_in) {
				sline.pop();
				num_to_in++;
			}
			else {
				break;
			}
		}

		if (ipt == num_to_in) {
			num_to_in++;
		}
		else {
			if (sline.size() == 0) {
				sline.push(ipt);
				sline_max = ipt;
			}
			else {
				if (sline_max < ipt) {
					available = false;
					break;
				}
				sline.push(ipt);
			}
		}
	}

	while (sline.size() != 0) {
		sline.pop();
		num_to_in++;
	}

	(available && num_to_in == N + 1) ? cout << "Nice" : cout << "Sad";
}