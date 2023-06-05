#include <iostream>
#include <fstream>
#include <string>

using namespace std;


struct Student {
    int rollNumber;
    string name;
    string division;
    string address;
};


void addStudentInfo() {
    ofstream file("student_info.txt", ios::app); // Open file in append mode

    if (!file) {
        cout << "Error opening file!" << endl;
        return;
    }

    Student student;
    cout << "Enter Roll Number: ";
    cin >> student.rollNumber;
    cout << "Enter Name: ";
    cin.ignore();
    getline(cin, student.name);
    cout << "Enter Division: ";
    getline(cin, student.division);
    cout << "Enter Address: ";
    getline(cin, student.address);

    
    file << student.rollNumber << " "
         << student.name << " "
         << student.division << " "
         << student.address << endl;

    file.close();
}

void deleteStudentInfo() {
    int rollNumberToDelete;
    cout << "Enter Roll Number of student to delete: ";
    cin >> rollNumberToDelete;

    ifstream inputFile("student_info.txt");
    ofstream tempFile("temp.txt");

    if (!inputFile || !tempFile) {
        cout << "Error opening file!" << endl;
        return;
    }

    bool found = false;
    Student student;

    // Copy all records 
    while (inputFile >> student.rollNumber >> student.name >> student.division >> student.address) {
        if (student.rollNumber != rollNumberToDelete) {
            tempFile << student.rollNumber << " "
                     << student.name << " "
                     << student.division << " "
                     << student.address << endl;
        } else {
            found = true;
        }
    }

    inputFile.close();
    tempFile.close();

    if (!found) {
        cout << "Student record not found!" << endl;
        remove("temp.txt"); // Delete the temporary file
        return;
    }

    remove("student_info.txt");      // Delete the original file
    rename("temp.txt", "student_info.txt"); // Rename the temporary file to original file
    cout << "Student record deleted successfully." << endl;
}

void display_All_record() {
    Student student;
    ifstream infile("student_info.txt");
    
    while (infile >> student.rollNumber >> student.name >> student.division >> student.address)
    {
        cout<< "Roll Number: "<<student.rollNumber<<endl;
        cout<< "Name: "<<student.name<<endl;
        cout<< "Division: "<<student.division<<endl;
        cout<< "Address: "<<student.address<<endl;
    }
    
    cout<<"\nThat's All";
    
}


void displayStudentInfo() {
    int rollNumberToDisplay;
    cout << "Enter Roll Number of student to display: ";
    cin >> rollNumberToDisplay;

    ifstream file("student_info.txt");

    if (!file) {
        cout << "Error opening file!" << endl;
        return;
    }

    Student student;
    bool found = false;

    
    while (file >> student.rollNumber >> student.name >> student.division >> student.address) {
        if (student.rollNumber == rollNumberToDisplay) {
            found = true;
            break;
        }
    }

    file.close();

    if (!found) {
        cout << "Student record not found!" << endl;
        return;
    }

    cout << "Roll Number: " << student.rollNumber << endl;
    cout << "Name: " << student.name << endl;
    cout << "Division: " << student.division << endl;
    cout << "Address: " << student.address << endl;
}

int main() {
    int choice;

    do {
        cout << "\n1. Add Student Information" << endl;
        cout << "2. Delete Student Information" << endl;
        cout << "3. Display Student Information" << endl;
        cout << "4. Display All records" << endl;
        cout << "5. Quit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addStudentInfo();
                break;
            case 2:
                deleteStudentInfo();
                break;
            case 3:
                displayStudentInfo();
                break;
            case 4:
                display_All_record();
                break;
            case 5:
                cout << "Exiting program. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    } while (choice != 5);

    return 0;
}
