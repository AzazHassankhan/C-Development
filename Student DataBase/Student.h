/*
 * Student.h
 *
 * Created on: Jan 6, 2024
 * Author: Azaz Hassan Khan
 */

#ifndef STUDENT_H_
#define STUDENT_H_

#include <string>
#include <Poco/Data/Date.h>
#include <vector>
#include "Enrollment.h"
#include "Address.h"
#include "Course.h"
#include "BlockCourse.h"
#include "WeeklyCourse.h"
#include <iostream>
#include <fstream>

/**
 * @class Student
 * @brief Represents a student with personal and enrollment information.
 */
class Student {
private:
    static unsigned int nextMatrikelNumber; ///< Next available matriculation number.
    unsigned int matrikelNumber; ///< Matriculation number of the student.
    std::string firstName; ///< First name of the student.
    std::string lastName; ///< Last name of the student.
    Poco::Data::Date dateOfBirth; ///< Date of birth of the student.
    std::vector<Enrollment> enrollments; ///< List of enrollments for the student.
    Address address; ///< Address of the student.

public:
    /**
     * @brief Constructor
     * @param firstName : std::string - stores the first name of the student
     * @param lastName : std::string - stores the last name of the student
     * @param dateOfBirth : Poco::Data::Date - stores the date of birth of student
     * @param address : Address - stores the address of the student
     */
    Student(std::string firstName, std::string lastName, Poco::Data::Date
    		dateOfBirth, Address address);
    /**
      * @brief Default Constuctor for Student.
      */
    Student();
    /**
     * @brief Destructor
     */
    virtual ~Student();

    /**
     * @brief Function to get the first name
     */
    const std::string& getFirstName() const;

    /**
     * @brief Function to set the first name
     * @param firstName : std::string - stores the first name
     */
    void setFirstName(const std::string &firstName);

    /**
     * @brief Function to get the last name
     */
    const std::string& getLastName() const;

    /**
     * @brief Function to set the last name
     * @param lastname : std::string - stores the last name
     */
    void setLastName(const std::string &lastName);

    /**
     * @brief Function to get the date of the birth of the student
     */
    const Poco::Data::Date& getDateOfBirth() const;

    /**
     * @brief Function to set the date of birth of the student
     * @param dateOfBirth : Poco::Data::Date - stores the date of birth of the student
     */
    void setDateOfBirth(const Poco::Data::Date &dateOfBirth);

    /**
     * @brief Function to get the matrikel number
     */
    unsigned int getMatrikelNumber() const;

    /**
     * @brief Function to get the enrollments of the student
     */
    const std::vector<Enrollment>& getEnrollments() const;

    /**
     * @brief Function to update the enrollments of the student
     * @param enrollment : Enrollment& - enrollment information to be updated
     */
    void updateEnrollments(Enrollment& enrollment);

    /**
     * @brief Function to get the address of the student
     */
    const Address& getAddress() const;

    /**
     * @brief Function to set the address of the student
     * @param address : Address - stores the address of the student
     */
    void setAddress(const Address &address);

    /**
     * @brief Function to delete the enrollment
     * @param courseKey : unsigned int - stores the course key
     */
    void deleteEnrollment(unsigned int courseKey);

    /**
     * @brief Function to update the grade of the student
     * @param courseKey : unsigned int - stores the course key
     * @param newGrade : float - new grade
     */
    void updateGrade(unsigned int courseKey, float newGrade);

    /**
     * @brief Function to print the student data
     */
    void print() const;

    /**
     * @brief Function to write to the file
     * @param out : std::ostream& - stores the file to be written to
     */
    void write(std::ostream &out) const;

    /**
      * @brief Function to read from file
      * @param fin : std::ifstream& - read the file from database file
      * @return Student - student read from file
      */
    Student read(std::ifstream &fin) const;
};

#endif /* STUDENT_H_ */
