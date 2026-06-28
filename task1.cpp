#include <iostream>
#include <iomanip>
using namespace std;

// Function to calculate CGPA
void calculateCGPA()
{
    int n;
    cout << "Enter the number of courses: ";
    cin >> n;

    string courseName[n];
    float grade[n], credit[n];

    float totalCredits = 0;
    float totalGradePoints = 0;

    // Input course details
    for (int i = 0; i < n; i++)
    {
        cout << "\nCourse " << i + 1 << endl;

        cout << "Enter Course Name: ";
        cin >> courseName[i];

        cout << "Enter Grade Point (0 - 10): ";
        cin >> grade[i];

        cout << "Enter Credit Hours: ";
        cin >> credit[i];

        totalCredits += credit[i];
        totalGradePoints += grade[i] * credit[i];
    }

    float cgpa = totalGradePoints / totalCredits;

    // Display Result
    cout << "\n========== RESULT ==========\n";
    cout << left << setw(20) << "Course"
         << setw(15) << "Grade"
         << setw(15) << "Credits" << endl;

    for (int i = 0; i < n; i++)
    {
        cout << left << setw(20) << courseName[i]
             << setw(15) << grade[i]
             << setw(15) << credit[i] << endl;
    }

    cout << "\nTotal Credits : " << totalCredits << endl;
    cout << "Total Grade Points : " << totalGradePoints << endl;
    cout << fixed << setprecision(2);
    cout << "Final CGPA : " << cgpa << endl;
}

int main()
{
    cout << "===== CGPA Calculator =====" << endl;
    calculateCGPA();

    return 0;
}