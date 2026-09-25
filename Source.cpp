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
};

int main() {
    std::vector<STUDENT_DATA> students;
    std::ifstream file("StudentData.txt");

    // Verify file opened successfully
    if (!file.is_open()) {
        std::cerr << "Error: Unable to open StudentData.txt" << std::endl;
        return 1;
    }

    std::string line;
    while (std::getline(file, line)) {
        if (line.empty()) continue; // Skips blank lines

        std::stringstream ss(line);
        std::string firstName, lastName;

        // Parse comma-separated first and last name
        if (std::getline(ss, firstName, ',') && std::getline(ss, lastName)) {
            STUDENT_DATA student;
            student.firstName = firstName;
            student.lastName = lastName;
            students.push_back(student);
        }
    }

    file.close();

    // Print student details only when compiled in DEBUG mode
    #ifdef _DEBUG
         std::cout << "--- DEBUG MODE: PRINTING STUDENT DATA ---" << std::endl;
         for (size_t i = 0; i < students.size(); i++) {
           std::cout << "First Name: " << students[i].firstName
                     << ", Last Name: " << students[i].lastName << std::endl;
         }
    #endif

    return 1;
}