#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {

    string course;
    float credit;
    string grade;
    float totalGrade = 0.0;
    float totalCredit = 0.0;

    for (int i = 0; i < 20; i++) {
        cin >> course >> credit >> grade;
        if (grade == "P") { continue; }
        else if (grade == "A+") { totalGrade += 4.5 * credit; }
        else if (grade == "A0") { totalGrade += 4 * credit; }
        else if (grade == "B+") { totalGrade += 3.5 * credit; }
        else if (grade == "B0") { totalGrade += 3 * credit; }
        else if (grade == "C+") { totalGrade += 2.5 * credit; }
        else if (grade == "C0") { totalGrade += 2 * credit; }
        else if (grade == "D+") { totalGrade += 1.5 * credit; }
        else if (grade == "D0") { totalGrade += 1 * credit; }
        totalCredit += credit;
    }

    cout << totalGrade/totalCredit; 

    return 0;
}