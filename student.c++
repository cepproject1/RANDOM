#include <iostream>
#include <string>
using namespace std;

// Structure for student node
struct Student {
    int rollNo;
    string name;
    float marks;
    Student* next;
};

// Head pointer for the linked list
Student* head = nullptr;

// ---------- ADD STUDENT ----------
void addStudent(int rollNo, string name, float marks) {
    Student* newStudent = new Student();
    newStudent->rollNo = rollNo;
    newStudent->name = name;
    newStudent->marks = marks;
    newStudent->next = nullptr;

    if (head == nullptr) {
        head = newStudent;
    } else {
        Student* temp = head;
        while (temp->next != nullptr)
            temp = temp->next;
        temp->next = newStudent;
    }
    cout << " Student added successfully!\n";
}

// ---------- DISPLAY STUDENTS ----------
void displayStudents() {
    if (head == nullptr) {
        cout << "No records found.\n";
        return;
    }

    cout << "\n--- Student Records ---\n";
    cout << "Roll No\tName\t\tMarks\n";
    cout << "------------------------------\n";
    Student* temp = head;
    while (temp != nullptr) {
        cout << temp->rollNo << "\t" << temp->name << "\t\t" << temp->marks << endl;
        temp = temp->next;
    }
    cout << "------------------------------\n";
}

// ---------- SEARCH STUDENT ----------
void searchStudent(int rollNo) {
    Student* temp = head;
    while (temp != nullptr) {
        if (temp->rollNo == rollNo) {
            cout << "\nRecord Found:\n";
            cout << "Roll No: " << temp->rollNo << "\nName: " << temp->name << "\nMarks: " << temp->marks << endl;
            return;
        }
        temp = temp->next;
    }
    cout << " Student not found!\n";
}

// ---------- UPDATE STUDENT ----------
void updateStudent(int rollNo) {
    Student* temp = head;
    while (temp != nullptr) {
        if (temp->rollNo == rollNo) {
            cout << "Enter new name: ";
            cin.ignore();
            getline(cin, temp->name);
            cout << "Enter new marks: ";
            cin >> temp->marks;
            cout << " Record updated successfully!\n";
            return;
        }
        temp = temp->next;
    }
    cout << "Student not found!\n";
}

// ---------- DELETE STUDENT ----------
void deleteStudent(int rollNo) {
    if (head == nullptr) {
        cout << "No records to delete.\n";
        return;
    }

    if (head->rollNo == rollNo) {
        Student* temp = head;
        head = head->next;
        delete temp;
        cout << "Record deleted successfully!\n";
        return;
    }

    Student* temp = head;
    Student* prev = nullptr;

    while (temp != nullptr && temp->rollNo != rollNo) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == nullptr) {
        cout << "Student not found!\n";
        return;
    }

    prev->next = temp->next;
    delete temp;
    cout << "Record deleted successfully!\n";
}

// ---------- MAIN FUNCTION ----------
int main() {
    int choice, rollNo;
    string name;
    float marks;

    do {
        cout << "\n===== Student Record Management System =====\n";
        cout << "1. Add Student\n";
        cout << "2. Display All Students\n";
        cout << "3. Search Student\n";
        cout << "4. Update Student\n";
        cout << "5. Delete Student\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter Roll No: ";
            cin >> rollNo;
            cin.ignore();
            cout << "Enter Name: ";
            getline(cin, name);
            cout << "Enter Marks: ";
            cin >> marks;
            addStudent(rollNo, name, marks);
            break;

        case 2:
            displayStudents();
            break;

        case 3:
            cout << "Enter Roll No to search: ";
            cin >> rollNo;
            searchStudent(rollNo);
            break;

        case 4:
            cout << "Enter Roll No to update: ";
            cin >> rollNo;
            updateStudent(rollNo);
            break;

        case 5:
            cout << "Enter Roll No to delete: ";
            cin >> rollNo;
            deleteStudent(rollNo);
            break;

        case 0:
            cout << "Exiting program... Goodbye!\n";
            break;

        default:
            cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 0);

    return 0;
}
