#include <iostream>
#include <string>
using namespace std;

struct Student {
    int iden;
    string firstN;
    string lastN;
    string program;
    float grades;
};


void mainMenu() {
    cout << " ------- Main Menu ------" << endl;
    cout << "1. Add a Student" << endl;
    cout << "2. Change a Student" << endl;
    cout << "3. Remove a Student" << endl;
    cout << "4. Search for a Student" << endl;
    cout << "5. Exit" << endl;
}

void addStudent(Student students[], int &count) {
    cout << " Student ID: ";
    cin >> students[count].iden;
    cout << " First Name: ";
    cin >> students[count].firstN;
    cout << " Last Name: ";
    cin >> students[count].lastN;
    cout << " Program: ";
    cin >> students[count].program;
    cout << " Grades: ";
    cin >> students[count].grades;
    count++;
    cout << "Added successfully." << endl;
}


void changeStudent(Student students[], int count) {
    int iden;
    cout << " Student ID to be changed : ";
    cin >> iden;
    for (int i = 0; i < count; i++) {
        if (students[i].iden == iden) {
            cout << " UPDATED First Name: ";
            cin >> students[i].firstN;
            cout << "UPDATED  Last Name: ";
            cin >> students[i].lastN;
            cout << "UPDATED Program: ";
            cin >> students[i].program;
            cout << "UPDATED Grades: ";
            cin >> students[i].grades;
            cout << "UPDATE COMPLETE." << endl;
            return;
        }
    }
    cout << "Student not found." << endl;
}


void removeStudent(Student students[], int &count) {
    int iden;
    cout << "Student ID :  ";
    cin >> iden;
    for (int i = 0; i < count; i++) {
        if (students[i].iden == iden) {
            for (int j = i; j < count - 1; j++) {
                students[j] = students[j + 1];
            }
            count--;
            cout << "Removed successfully." << endl;
            return;
        }
    }
    cout << "Student not found." << endl;
}


void searchStudent(Student students[], int count) {
    int iden;
    cout << "Student ID : ";
    cin >> iden;
    for (int i = 0; i < count; i++) {
        if (students[i].iden == iden) {
            cout << "Student ID : " << students[i].iden << endl;
            cout << "First Name : " << students[i].firstN << endl;
            cout << "Last Name : " << students[i].lastN << endl;
            cout << "Program : " << students[i].program << endl;
            cout << "Grades : " << students[i].grades << endl;
            return;
        }
    }
    cout << "Student ID not found." << endl;
}

int main() {
    Student students[100];
    int count = 0;
    int option;

    while (true) {
        mainMenu();
        cout << "Option : ";
        cin >> option;

        switch (option) {
            case 1:
                addStudent(students, count);
                break;
            case 2:
                changeStudent(students, count);
                break;
            case 3:
                removeStudent(students, count);
                break;
            case 4:
                searchStudent(students, count);
                break;
            case 5:
                cout << "Program ended." << endl;
                return 0;
            default:
                cout << "INVALID, TRY AGAIN. " << endl;
        }
    }
}
