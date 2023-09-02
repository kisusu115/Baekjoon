#include <iostream>
#include <vector>

using namespace std;

int main() {
	float credits[20];
	float grades[20];

	float creditsum = 0;
	float allsum = 0;
	int pass = 0;

	for (int i = 0; i < 20; i++) {
		string sName;
		float credit;
		string grade;
		float gradeToNum = 0;

		cin >> sName;
		cin >> credit;
		cin >> grade;

		if (grade == "P") {
			pass++;
			continue;
		}

		if (grade == "A+") gradeToNum = 4.5;
		else if (grade == "A0") gradeToNum = 4.0;
		else if (grade == "B+") gradeToNum = 3.5;
		else if (grade == "B0") gradeToNum = 3.0;
		else if (grade == "C+") gradeToNum = 2.5;
		else if (grade == "C0") gradeToNum = 2.0;
		else if (grade == "D+") gradeToNum = 1.5;
		else if (grade == "D0") gradeToNum = 1.0;
		else if (grade == "F") gradeToNum = 0.0;

		creditsum += credit;
		allsum += credit * gradeToNum;
	}

	cout << allsum / creditsum;
}