#include<iostream>
#include<cmath>

using namespace std;

int main() {
	int n;
	cin >> n;

	int output = pow(pow(2, n)+1,2);
	cout << output;
}