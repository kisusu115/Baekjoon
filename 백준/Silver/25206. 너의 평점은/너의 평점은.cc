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

/*
vector 쓰면 왜 안됨?

#include <iostream>
#include <vector>

using namespace std;

int main() {
	vector<string> subjectNames(5);
	vector<float> credits(5);
	vector<float> grades(5);

	float creditsum = 0;
	float allsum = 0;
	int pass = 0;

	for (int i = 0; i < 5; i++) {
		string sName;
		float credit;
		string grade;
		float gradeToNum;

		cin >> sName;
		cin >> credit;
		cin >> grade;

		if (grade == "P") pass++;

		if (grade == "A+") gradeToNum = 4.5;
		else if (grade == "A0") gradeToNum = 4.0;
		else if (grade == "B+") gradeToNum = 3.5;
		else if (grade == "B0") gradeToNum = 3.0;
		else if (grade == "C+") gradeToNum = 2.5;
		else if (grade == "C0") gradeToNum = 2.0;
		else if (grade == "D+") gradeToNum = 1.5;
		else if (grade == "D0") gradeToNum = 1.0;
		else if (grade == "F") gradeToNum = 0.0;

		subjectNames.push_back(sName);
		credits.push_back(credit);
		grades.push_back(gradeToNum);
	}

	for (int i = 0; i < 5-pass; i++) {
		creditsum += credits[i];
		allsum += credits[i] * grades[i];
	}

	for (int i = 0; i < 5 - pass; i++) {
		cout << subjectNames[i];
	}

	cout << allsum / creditsum;
}
*/
