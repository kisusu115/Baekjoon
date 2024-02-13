#include<iostream>

using namespace std;

int main() {
	int a, b, c;
	cin >> a >> b >> c;
	if (a + b + c != 180) cout << "Error";
	else if (a == b && b == c) cout << "Equilateral";
	else if (a == b && a != c) cout << "Isosceles";
	else if (b == c && b != a) cout << "Isosceles";
	else if (c == a && c != b) cout << "Isosceles";
	else cout << "Scalene";

	return 0;
}