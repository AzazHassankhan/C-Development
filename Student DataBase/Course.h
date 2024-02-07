
/*
 * Course.h
 *
 *Created on: Jan 6, 2024
 *Author: Azaz Hassan Khan
 */

#ifndef COURSE_H_
#define COURSE_H_

#include <string>
#include <map>
#include <iostream>
#include <fstream>

/**
 * @class Course
 * @brief Represents a course with key attributes.
 */
class Course {
private:
	/**
	 * @brief majorById : static map<unsigned char, string> -
	 *  stores the major mapped with the first letter of the major
	 */
	std::map<unsigned char, std::string> majorById;

	/**
	 * @brief courseKey : unsigned int - stores the course ID of the course
	 */
	unsigned int courseKey;

	/**
	 * @brief title : string - stores the title of the course
	 */
	std::string title;

	/**
	 * @brief major : unsigned char - stores the first letter of the major
	 */
	unsigned char major;

	/**
	 * @brief creditPoints : float - stores the credit points of the course
	 */
	float creditPoints;

public:
	/**
	 * @brief Constructor
	 * @param courseKey : unsigned int - course ID
	 * @param title : string - title of the course
	 * @param major : string - first letter of the major
	 * @param creditPoints : float - credit points of the course
	 */
	Course(unsigned int courseKey=0, std::string title="N/A", std::string major=
			"N/A",float creditPoints=0.0);

	/**
	 * @brief Destructor
	 */
	virtual ~Course();

	/**
	 * @brief Getter for courseKey
	 * @return unsigned int - course ID
	 */
	unsigned int getCourseKey() const;

	/**
	 * @brief Getter for creditPoints
	 * @return float - credit points of the course
	 */
	float getCreditPoints() const;

	/**
	 * @brief Getter for major
	 * @return unsigned char - first letter of the major
	 */
	unsigned char getMajor() const;

	/**
	 * @brief Getter for majorById
	 * @return std::map<unsigned char, std::string> - map of major IDs
	 */
	std::map<unsigned char, std::string> getMajorById() const;

	/**
	 * @brief Getter for title
	 * @return const std::string& - title of the course
	 */
	const std::string& getTitle() const;

	/**
	 * @brief Function to print the course details
	 */
	virtual void print() const;

	/**
	 * @brief Function to write to Database file
	 * @param out : ostream& - stores the file to be written to
	 */
	virtual void write(std::ostream &out) const;

};

#endif /* COURSE_H_ */

