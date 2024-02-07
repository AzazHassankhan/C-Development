
#ifndef STUDENTDB_H_
#define STUDENTDB_H_

#include "Student.h"
#include "BlockCourse.h"
#include "WeeklyCourse.h"
#include "Enrollment.h"
#include "Course.h"
#include <Poco/Data/Date.h>
#include <Poco/Data/Time.h>
#include <map>
#include <memory>
#include <iostream>
#include <fstream>
#include <boost/asio.hpp>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
/**
 * @class StudentDb
 * @brief Represents a database of students and courses.
 */
class StudentDb {
private:
	/**< Map of student objects with matrikel number as key. */
	std::map<int, Student> students;

	/**< Map of course objects with course key as key. */
    std::map<int, std::unique_ptr<const Course>> courses;
public:
    /**
     * @brief Constructor for the StudentDb class.
     */
    StudentDb();

    /**
     * @brief Destructor for the StudentDb class.
     */
    virtual ~StudentDb();

    /**
     * @brief Adds a new course to the database.
     */
    void addNewCourse();

    /**
     * @brief Lists all courses in the database.
     */
    void listCourses() const;

    /**
     * @brief Adds a new student to the database.
     */
    void addNewStudent();

    /**
     * @brief Prints information of a student with a particular matrikel number.
     * @param matrikelNumber The matrikel number of the student.
     */
    void printStudent(unsigned int matrikelNumber) const;

    /**
     * @brief Enrolls a student into a course in the database.
     */
    void AddEnrollment();

    /**
     * @brief Searches for a student in the database by name.
     */
    void searchStudent();

    /**
     * @brief Updates the information of students in the database.
     */
    void updateStudentData();

    /**
     * @brief Checks if a matrikel number is present in the database.
     * @param matrikelNumber The matrikel number to check.
     * @return True if matrikel number is present, false otherwise.
     */
    bool checkMatrikelNumber(unsigned int matrikelNumber) const;

    /**
     * @brief Writes content to a database.csv file.
     */
    void write() const;

    /**
     * @brief Reads content from a database.csv file.
     */
    void read();

    /**
     * @brief Connects to the server.
     */
    void ConnectToServer();

    /**
     * @brief Parses the received data in JSON format.
     * @param data The JSON data to parse.
     */
    void JsonParser(std::string data);
};

#endif /* STUDENTDB_H_ */

