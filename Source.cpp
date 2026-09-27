// Project: CSCN73030 - Assignment 2
// Author: Het Nayak

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

// Struct holding standard student details
struct STUDENT_DATA {
    std::string firstName;
    std::string lastName;
#ifdef PRE_RELEASE
    std::string email;
#endif
};

int main() {
    // Print current execution mode message
#ifdef PRE_RELEASE
    std::cout << "Application running PRE-RELEASE source code." << std::endl;
#else
    std::cout << "Application running STANDARD source code." << std::endl;
#endif

    std::vector<STUDENT_DATA> students;

    // Conditionally select input file
#ifdef PRE_RELEASE
    std::ifstream file("StudentData_Emails.txt");
#else
    std::ifstream file("StudentData.txt");
#endif

    // Verify file opened successfully
    if (!file.is_open()) {
        std::cerr << "Error: Unable to open StudentData.txt" << std::endl;
        return 1;
    }

    std::string line;
    while (std::getline(file, line)) {
        if (line.empty()) continue; // Skips blank lines

        std::stringstream ss(line);

#ifdef PRE_RELEASE
        std::string firstName, lastName, email;
        // Parse comma-separated First Name, Last Name, and Email
        if (std::getline(ss, firstName, ',') && std::getline(ss, lastName, ',') && std::getline(ss, email)) {
            STUDENT_DATA student;
            student.firstName = firstName;
            student.lastName = lastName;
            student.email = email;
            students.push_back(student);
        }
#else
        std::string firstName, lastName;
        // Parse comma-separated First Name and Last Name
        if (std::getline(ss, firstName, ',') && std::getline(ss, lastName)) {
            STUDENT_DATA student;
            student.firstName = firstName;
            student.lastName = lastName;
            students.push_back(student);
        }
#endif
    }

    file.close();

    // Print student details only when compiled in DEBUG mode
#ifdef _DEBUG
    std::cout << "\n--- DEBUG MODE: PRINTING STUDENT DATA ---" << std::endl;
    for (size_t i = 0; i < students.size(); i++) {
        std::cout << "First Name: " << students[i].firstName
            << ", Last Name: " << students[i].lastName;
#ifdef PRE_RELEASE
        std::cout << ", Email: " << students[i].email;
#endif
        std::cout << std::endl;
    }
#endif

    return 1;
}