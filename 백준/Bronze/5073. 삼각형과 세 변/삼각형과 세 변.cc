#include<iostream>

using namespace std;

int main() {
	int a, b, c;
	while(true) {
		cin >> a >> b >> c;
		if (a == 0 && b == 0 && c == 0) return 0;
		if (a + b <= c || b + c <= a || c + a <= b) cout << "Invalid\n";
		else if (a == b && b == c) cout << "Equilateral\n";
		else if (a == b && a != c) cout << "Isosceles\n";
		else if (b == c && b != a) cout << "Isosceles\n";
		else if (c == a && c != b) cout << "Isosceles\n";
		else cout << "Scalene\n";
	}

	return 0;
}