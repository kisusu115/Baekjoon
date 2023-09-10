#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int main() {
	int N;
	int B;
	string outp;

	cin >> N >> B;


	while (N) {
		int tmp = N % B;
		if (tmp > 9)
		{
			tmp = tmp - 10 + 'A';
			outp += tmp;
		}
		else
		{
			outp += ('0' + tmp);
		}
		N /= B;
	}

	reverse(outp.begin(), outp.end());
	cout << outp;
}