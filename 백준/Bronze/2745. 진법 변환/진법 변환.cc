#include<iostream>
#include<cmath>

using namespace std;

int main() {
	string N;
	int B;

	char c = '5';

	long long outp = 0;

	cin >> N >> B;

	for (int i=0; i < N.length(); i++) {
		if('A'<=N[i] && N[i]<='Z') outp += (N[i] - 'A' + 10) * pow(B, N.length() - i - 1);
		else if('0' <=N[i] && N[i]<='9') outp += (N[i]-int('0')) * pow(B, N.length() - i - 1);
	}

	cout << outp << endl;
}