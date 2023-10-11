
#include <bits/stdc++.h>
using namespace std;

struct Student
{
    char name[50];
    int id;
    float cgpa;
};

int main()
{
    int numStudents;
    cout << "Please, Enter the number of students: ";
    cin >> numStudents;

    Student *students = new Student[numStudents];

    for (int i = 0; i < numStudents; i++)
    {
        cout << "Please, Enter the information of the student" << i + 1 << endl;
        cout << "Name: ";
        cin >> students[i].name;
        cout << "ID: ";
        cin >> (students[i].id);
        cout << "CGPA: ";
        cin >> (students[i].cgpa);
        cout << endl;
    }

    float maxCGPA = students[0].cgpa;
    int maxIndex = 0;
    for (int i = 1; i < numStudents; i++)
    {
        if (students[i].cgpa > maxCGPA)
        {
            maxCGPA = students[i].cgpa;
            maxIndex = i;
        }
    }

    cout << "The Student with the highest CGPA: " << endl;
    cout << "Name: " << students[maxIndex].name << endl;
    cout << "ID: " << students[maxIndex].id << endl;
    cout << "CGPA: " << students[maxIndex].cgpa << endl;

    delete[] students;

    return 0;
}
