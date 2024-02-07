
/**
 * @file Enrollment.cpp
 *
 * @brief Implementation file for the Enrollment class.
 *
 * @date Jan 6, 2024
 * @author Azaz Hassan Khan
 */

#include "Enrollment.h"

/**
 * @brief Constructor for the Enrollment class.
 *
 * @param grade Grade obtained in the course.
 * @param semester Enrolled semester.
 * @param course Pointer to the enrolled course.
 */
Enrollment::Enrollment(float grade, string semester, const Course *course)
{
    this->grade = grade;
    this->semester = semester;
    this->course = course;
}

/**
 * @brief Default constructor for the Enrollment class.
 */
Enrollment::Enrollment() {} // @suppress("Class members should be properly initialized")

/**
 * @brief Get the grade obtained in the course.
 *
 * @return Grade obtained in the course.
 */
float Enrollment::getGrade() const
{
    return this->grade;
}

/**
 * @brief Get the enrolled semester.
 *
 * @return Enrolled semester.
 */
const string& Enrollment::getSemester() const
{
    return semester;
}

/**
 * @brief Get the enrolled course.
 *
 * @return Pointer to the enrolled course.
 */
const Course* Enrollment::getCourse() const
{
    return course;
}

/**
 * @brief Set the grade obtained in the course.
 *
 * @param grade Grade to set.
 */
void Enrollment::setGrade(float grade)
{
    this->grade = grade;
}

/**
 * @brief Overload the == operator for Enrollment type objects.
 *
 * @param other Another Enrollment object for comparison.
 * @return True if the objects are equal, false otherwise.
 */
bool Enrollment::operator ==(Enrollment other) const
{
    bool query;

    if (grade == other.grade && semester == other.semester && course == other.course)
    {
        query = true;
    }
    else
    {
        query = false;
    }
    return query;
}

/**
 * @brief Write enrollment details to an output stream.
 *
 * @param out Output stream to write to.
 */
void Enrollment::write(std::ostream &out) const
{
    out << course->getCourseKey() << ";" << semester << ";" << grade;
}

/**
 * @brief Destructor for the Enrollment class.
 */
Enrollment::~Enrollment()
{}

/**
 * @brief Read student data from a Database file.
 *
 * @param fin Input file stream to read from.
 * @param course Pointer to the enrolled course.
 * @return Enrollment object read from the file.
 */
Enrollment Enrollment::read(std::ifstream &fin, const Course* course) const {
    string line;

    getline(fin, line, ';'); // Get semester string
    std::string semester = line;

    getline(fin, line);      // Get credit points
    float credits = std::stof(line);

    // Create Enrollment Class
    Enrollment newEnrollment(credits, semester, course);
    return newEnrollment;
}

