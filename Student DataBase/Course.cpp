/**
 * @file Course.cpp
 *
 * @brief Implementation file for the Course class.
 *
 * @date Jan 6, 2024
 * @author Azaz Hassan Khan
 */

#include "Course.h"
using namespace std;

/**
 * @brief Constructor for the Course class.
 *
 * @param courseKey Unique identifier for the course.
 * @param title Title of the course.
 * @param major Major of the course.
 * @param creditPoints Credit points associated with the course.
 */
Course::Course(unsigned int courseKey, std::string title, std::string major,
        float creditPoints)
{
    this->courseKey = courseKey;
    this->title = title;
    this->major = major[0];
    this->creditPoints = creditPoints;
    this->majorById.insert(pair<unsigned char, string>(this->major, major));
}

/**
 * @brief Get the course key.
 *
 * @return unsigned int Course key.
 */
unsigned int Course::getCourseKey() const {
    return courseKey;
}

/**
 * @brief Get the credit points of the course.
 *
 * @return float Credit points.
 */
float Course::getCreditPoints() const {
    return creditPoints;
}

/**
 * @brief Get the major of the course.
 *
 * @return unsigned char Major.
 */
unsigned char Course::getMajor() const {
    return major;
}

/**
 * @brief Get the major mapping by ID.
 *
 * @return std::map<unsigned char, std::string> Major mapping.
 */
std::map<unsigned char, std::string> Course::getMajorById() const {
    return majorById;
}

/**
 * @brief Get the title of the course.
 *
 * @return const std::string& Course title.
 */
const std::string& Course::getTitle() const {
    return title;
}

/**
 * @brief Print the details of the course.
 */
void Course::print() const
{
	cout << "Course title: " << title << endl << "Course Key : " << courseKey <<
	endl << "Major : " << getMajor() << endl << "Credit Points : "<<creditPoints
	<< endl;
}

/**
 * @brief Write course data to the Database file.
 *
 * @param out std::ostream& Output stream for writing.
 */
void Course::write(ostream& out) const
{
	out << courseKey << ";" << title << ";" << majorById.at(major)
			<< ";" << creditPoints << ";";
}

/**
 * @brief Destructor for the Course class.
 */
Course::~Course() {
}

