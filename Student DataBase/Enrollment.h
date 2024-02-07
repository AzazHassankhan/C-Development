/*
 * Enrollment.h
 *
 *Created on: Jan 6, 2024
 *Author: Azaz Hassan Khan
 */

#ifndef ENROLLMENT_H_
#define ENROLLMENT_H_
#include <string>
using namespace std;
#include "Course.h"
#include <fstream>

class Enrollment
{
private:
	/**
	 * @brief grade : float - stores the grade of the course
	 */
	float grade;

	/**
	 * @brief semester : string - stores the semester of the enrolled course
	 */
	string semester;

	/**
	 * @brief course : Course* - pointer of the class Course
	 */
	const Course *course;


public:
	/**
	 * @brief Constructor of the enrollment
	 * @param semester : string - stores the semester of the enrolled course
	 * @param course : Course* - pointer of the class Course
	 * @param grade : float - stores the grade of the course
	 */
	Enrollment(float grade, string semester, const Course *course);

	Enrollment();

	/**
	 * @brief Destructor
	 */
	virtual ~Enrollment();

	/**
	 * @brief Function to get the semester
	 */
	const string& getSemester() const;

	/**z
	 * @brief Function to get the object of the Course
	 */
	const Course* getCourse() const;

	/**
	 * @brief Function to get the grade
	 */
	float getGrade() const;

	/**
	 * @brief Function to set the grade
	 * @param grade : float - stores the grade of the course
	 */
	void setGrade(float grade);

	/**
	 * @brief Function to overload the == operator for Enrollment type objects
	 * @param other : Enrollment - object of the Class Enrollment
	 */
	bool operator==(Enrollment other) const;

	/**
	 * @brief  writeFile function to write data in File as Required
	 * @param std::ostream & out
	 */
	void write(std::ostream &out)const;

    /**
      * @brief Function to read from file
      * @param fin : ifstream& - read the file from database file
      */
	Enrollment read(std::ifstream &fin, const Course* course) const;

};

#endif /* ENROLLMENT_H_ */
