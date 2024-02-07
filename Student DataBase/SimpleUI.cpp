/**
 * @file SimpleUI.cpp
 *
 * @brief Implementation file for the SimpleUI class.
 *
 * @date Jan 6, 2024
 * @author Azaz Hassan Khan
 */

#include "SimpleUI.h"
#include <iostream>
using namespace std;

/**
 * @brief Constructor for the SimpleUI class.
 *
 * @param db Reference to the Student Database.
 */
SimpleUI::SimpleUI(StudentDb & db): db{db}
{}

/**
 * @brief Run the database user interface.
 */
void SimpleUI::run()
{
    bool exitFlag = true;

    while (exitFlag)

    {
        // Menu for Database
    	cout << "<================================>" << endl;
        cout << "1. Add new Course" << endl;
        cout << "2. List courses" << endl;
        cout << "3. Add new student" << endl;
        cout << "4. Add enrollment" << endl;
        cout << "5. Print student" << endl;
        cout << "6. Search student" << endl;
        cout << "7. Update student" << endl;
        cout << "8. Write to Database file" << endl;
        cout << "9. Read from Database file" << endl;
        cout << "10. Connect to server & extract student data" << endl;
        cout << "0. Exit DataBase" << endl;

        // Enter command for Database
        int command;
        cout << "Enter the command: ";
        cin >> command;
        cout << endl;

        // State Machine
        switch (command)
        {
            // Exit Data Base
            case 0:
                cout << "*****Exit Data Base*****" << endl;
                exitFlag = false;
                break;

            // Add new Course
            case 1:
                cout << "*****Enter New Course Details*****" << endl;
                db.addNewCourse();
                cout << "New course added." << endl;
                break;

            // List courses
            case 2:
                cout << "*****All Available Courses*****" << endl;
                db.listCourses();
                break;

            // Add new student
            case 3:
                cout << "*****Enter New Student Information*****" << endl;
                db.addNewStudent();
                break;

            // Add enrollment
            case 4:
                {cout << "*****Add Enrollment Information*****" << endl;
                db.AddEnrollment();

                break;}

            // Print student
            case 5:
                cout << "*****Print Student Information*****" << endl;

                unsigned int matrikelNumber;
                cout << "Enter the matrikel number: ";
                cin >> matrikelNumber;

                if (db.checkMatrikelNumber(matrikelNumber))
                {
                    db.printStudent(matrikelNumber);
                }
                else
                {
                    cout << "Please enter a valid Matrikel Number" << endl;
                }

                break;

            // Search student
            case 6:
                cout << "*****Search Student*****" << endl;
                db.searchStudent();
                break;

            // Update student
            case 7:
                cout << "*****Update Student Information*****" << endl;
                db.updateStudentData();
                break;

            // Write to Database File
            case 8:
                db.write();
                cout << "Write to file successful@@@" << endl;
                break;

            // Read from Database File
            case 9:
                db.read();
                cout << "Read from file successfully@@@" << endl;
                break;

            // Fetch Data & add to Database
            case 10:
                db.ConnectToServer();
                break;

            default:
                cout << "Wrong Command!!! Try Again" << endl;
                break;

    }

    }
}

/**
 * @brief Destructor for the SimpleUI class.
 */
SimpleUI::~SimpleUI()
{
	// TODO: Implement the destructor
}
