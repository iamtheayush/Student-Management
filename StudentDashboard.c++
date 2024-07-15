#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

struct Student {
    string firstName;
    string lastName;
    string course;
    string section;
    string address;
};

vector<Student> students;

// Function to load student records from file
void loadRecords() {
    ifstream file("students.txt");
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            Student student;
            stringstream ss(line);
            getline(ss, student.firstName, ' ');
            getline(ss, student.lastName, ' ');
            getline(ss, student.course, ' ');
            getline(ss, student.section, ' ');
            getline(ss, student.address, '\n');
            students.push_back(student);
        }
        file.close();
    }
}

// Function to save student records to file
void saveRecords() {
    ofstream file("students.txt");
    if (file.is_open()) {
        for (const auto& student : students) {
            file << student.firstName << " " << student.lastName << " " << student.course << " " << student.section << " " << student.address << "\n";
        }
        file.close();
    }
}

// Function prototypes
void loginScreen();
void mainMenu();
void addRecords();
void viewRecords();
void modifyRecords();
void removeRecords();

void loginScreen() {
    string username, password;
    cout << "Login Screen\n";
    cout << "Username: ";
    cin >> username;
    cout << "Password: ";
    cin >> password;

    if (username == "admin" && password == "password") {
        cout << "Login successful!\n";
        mainMenu();
    } else {
        cout << "Invalid login credentials. Try again.\n";
        loginScreen();
    }
}

void mainMenu() {
    int choice;
    cout << "Main Menu\n";
    cout << "1. Add Records\n";
    cout << "2. View Records\n";
    cout << "3. Modify Records\n";
    cout << "4. Remove Records\n";
    cout << "5. Exit Program\n";
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice) {
        case 1:
            addRecords();
            break;
        case 2:
            viewRecords();
            break;
        case 3:
            modifyRecords();
            break;
        case 4:
            removeRecords();
            break;
        case 5:
            cout << "Exiting program...\n";
            saveRecords();
            exit(0);
        default:
            cout << "Invalid choice. Try again.\n";
            mainMenu();
    }
}

void addRecords() {
    Student student;
    cout << "Add Records\n";
    cout << "Enter first name: ";
    cin >> student.firstName;
    cout << "Enter last name: ";
    cin >> student.lastName;
    cout << "Enter course: ";
    cin >> student.course;
    cout << "Enter section: ";
    cin >> student.section;
    cout << "Enter address: ";
    cin >> student.address;

    students.push_back(student);
    cout << "Record added successfully!\n";
    mainMenu();
}

void viewRecords() {
    cout << "View Records\n";
    for (int i = 0; i < students.size(); i++) {
        cout << "Student " << i + 1 << ":\n";
        cout << "First Name: " << students[i].firstName << "\n";
        cout << "Last Name: " << students[i].lastName << "\n";
        cout << "Course: " << students[i].course << "\n";
        cout << "Section: " << students[i].section << "\n";
        cout << "Address: " << students[i].address << "\n\n";
    }
    mainMenu();
}

void modifyRecords() {
    string firstName, lastName;
    cout << "Modify Records\n";
    cout << "Enter first name of student to modify: ";
    cin >> firstName;
    cout << "Enter last name of student to modify: ";
    cin >> lastName;

    for (int i = 0; i < students.size(); i++) {
        if (students[i].firstName == firstName && students[i].lastName == lastName) {
            cout << "Enter new details (press enter to keep current value):\n";
            cout << "First Name [" << students[i].firstName << "]: ";
            string newFirstName;
            getline(cin, newFirstName);
            if (!newFirstName.empty()) {
                students[i].firstName = newFirstName;
            }

            cout << "Last Name [" << students[i].lastName << "]: ";
            string newLastName;
            getline(cin, newLastName);
            if (!newLastName.empty()) {
                students[i].lastName = newLastName;
            }

            cout << "Course [" << students[i].course << "]: ";
            string newCourse;
            getline(cin, newCourse);
            if (!newCourse.empty()) {
                students[i].course = newCourse;
            }

            cout << "Section [" << students[i].section << "]: ";
            string newSection;
            getline(cin, newSection);
            if (!newSection.empty()) {
                students[i].section = newSection;
            }

            cout << "Address [" << students[i].address << "]: ";
            string newAddress;
            getline(cin, newAddress);
            if (!newAddress.empty()) {
                students[i].address = newAddress;
            }

            cout << "Record modified successfully!\n";
            return;
        }
    }
    cout << "Student not found.\n";
    mainMenu();
}
void removeRecords() {
    string lastName;
    cout << "Remove Records\n";
    cout << "Enter last name of student to remove: ";
    cin >> lastName;

    for (int i = 0; i < students.size(); i++) {
        if (students[i].lastName == lastName) {
            students.erase(students.begin() + i);
            cout << "Record removed successfully!\n";
            return;
        }
    }
    cout << "Student not found.\n";
    mainMenu();
}
int main() {
    loadRecords();
    loginScreen();
    saveRecords();
    return 0;
}
