
/**
 * @file Student.cpp
 *
 * @brief Implementation file for the Student class.
 *
 * @date Jan 6, 2024
 * @author Azaz Hassan Khan
 */

#include "Student.h"

using namespace std;

// Initialize the static member variable nextMatrikelNumber
unsigned int Student::nextMatrikelNumber = 100000;

/**
 * @brief Constructor for the Student class.
 *
 * @param firstName First name of the student.
 * @param lastName Last name of the student.
 * @param dateOfBirth Date of birth of the student.
 * @param address Address of the student.
 */
Student::Student(string firstName, string lastName, Poco::Data::Date dateOfBirth,
        Address address)
{
    this->firstName = firstName;
    this->lastName = lastName;
    this->dateOfBirth = dateOfBirth;
    this->address = address;
    this->matrikelNumber = nextMatrikelNumber++;
}

/**
 * @brief Default Constructor for the Student class.
 */
Student::Student() { Student::nextMatrikelNumber = 100000; } // @suppress("Class members should be properly initialized")

/**
 * @brief Destructor for the Student class.
 */
Student::~Student()
{}

/**
 * @brief Set the first name of the student.
 *
 * @param firstName First name of the student.
 */
void Student::setFirstName(const string &firstName)
{
    this->firstName = firstName;
}

/**
 * @brief Set the last name of the student.
 *
 * @param lastName Last name of the student.
 */
void Student::setLastName(const string &lastName)
{
    this->lastName = lastName;
}

/**
 * @brief Set the date of birth of the student.
 *
 * @param dateOfBirth Date of birth of the student.
 */
void Student::setDateOfBirth(const Poco::Data::Date &dateOfBirth)
{
    this->dateOfBirth = dateOfBirth;
}

/**
 * @brief Get the first name of the student.
 *
 * @return const string& First name of the student.
 */
const string &Student::getFirstName() const
{
    return firstName;
}

/**
 * @brief Get the last name of the student.
 *
 * @return const string& Last name of the student.
 */
const string &Student::getLastName() const
{
    return lastName;
}

/**
 * @brief Get the date of birth of the student.
 *
 * @return const Poco::Data::Date& Date of birth of the student.
 */
const Poco::Data::Date &Student::getDateOfBirth() const
{
    return dateOfBirth;
}

/**
 * @brief Get the matrikel number of the student.
 *
 * @return unsigned int Matrikel number of the student.
 */
unsigned int Student::getMatrikelNumber() const
{
    return matrikelNumber;
}

/**
 * @brief Get the enrollments of the student.
 *
 * @return const vector<Enrollment>& List of enrollments for the student.
 */
const vector<Enrollment> &Student::getEnrollments() const
{
    return enrollments;
}

/**
 * @brief Get the address of the student.
 *
 * @return const Address& Address of the student.
 */
const Address &Student::getAddress() const
{
    return address;
}

/**
 * @brief Set the address of the student.
 *
 * @param address Address of the student.
 */
void Student::setAddress(const Address &address)
{
    this->address = address;
}

/**
 * @brief Print student information.
 */
void Student::print() const
{
    cout << "============>Student Information<============" << endl;
    cout << "Name : " << firstName << " " << lastName << endl;
    cout << "Matrikel Number: " << getMatrikelNumber() << endl;

    int day = dateOfBirth.day(), month = dateOfBirth.month(), year = dateOfBirth.year();
    cout << "Date of Birth : " << day << "/" << month << "/" << year << endl;

    cout << "Address " << endl;
    cout << "Street : " << address.getStreet() << endl;
    cout << "City name : " << address.getCityName() << endl;
    cout << "Postal code : " << address.getPostalCode() << endl;
    cout << "Additional information : " << address.getAdditionalInfo() << endl;

    cout << "============>Enrolled Courses<============: " << endl;

    if (enrollments.empty())
    {
        cout << "No Enrollments." << endl;
        cout << "============>******<============" << endl;
    }
    else
    {
        // Iterate through enrolled courses and print details
        for (const auto& enrol : enrollments)
        {
            enrol.getCourse()->print();
            cout << "Semester: " << enrol.getSemester() << endl;
            cout << "Course Grade: " << enrol.getGrade() << endl;
            cout << "----------------------------------" << endl;
        }
    }
}

/**
 * @brief Update the enrollments of the student.
 *
 * @param newEnrollment Enrollment information to be updated.
 */
void Student::updateEnrollments(Enrollment& newEnrollment)
{
    // Flag to determine whether the student is already enrolled
    bool isAlreadyEnrolled = false;

    // Check whether the enrollments list is empty
    if (enrollments.empty())
    {
        enrollments.push_back(newEnrollment);
    }
    else
    {
        // Iterate through existing enrollments to check for duplicates
        for (const auto& enrol : enrollments)
        {
            if (newEnrollment == enrol)
            {
                // Student is already enrolled in the course
                cout << "Student is already Enrolled." << endl;
                isAlreadyEnrolled = true;
                break;
            }
        }

        // If the student is not already enrolled, add the new enrollment
        if (!isAlreadyEnrolled)
        {
            enrollments.push_back(newEnrollment);
        }
    }
}

/**
 * @brief Delete the enrollment of the student for a specific course.
 *
 * @param courseKey Course key of the course to be deleted.
 */
void Student::deleteEnrollment(unsigned int courseKey)
{
    // Flag to determine whether the enrollment is found and deleted
    bool isEnrollmentDeleted = false;

    // Check whether the enrollments list is empty
    if (enrollments.empty())
    {
        cout << "Student is not enrolled in any subject" << endl;
    }
    else
    {
        // Iterate through the enrollments to find the specific course
        auto enrol = enrollments.begin();

        while (enrol != enrollments.end()) {
            if ((*enrol).getCourse()->getCourseKey() == courseKey) {
                // Delete the enrollment and indicate deletion
                cout << "Enrollment Deleted" << endl;
                enrol = enrollments.erase(enrol);  // Iterator is valid after erasing
                isEnrollmentDeleted = true;
                break;
            } else {
                ++enrol;
            }
        }

        // Check whether the enrollment is found and deleted
        if (!isEnrollmentDeleted)
        {
            cout << "Student is not enrolled in this subject" << endl;
        }
    }
}

/**
 * @brief Update the grade of the student for a specific course.
 *
 * @param courseKey Course key of the course for which the grade is to be updated.
 * @param newGrade New grade to be updated.
 */
void Student::updateGrade(unsigned int courseKey, float newGrade)
{
    // Flag to determine whether the student is enrolled in the specific subject
    bool isEnrolled = false;

    // Check whether the enrollments list is empty
    if (enrollments.empty())
    {
        cout << "Student is not enrolled in any subject" << endl;
    }
    else
    {
        // Iterate through the enrollments to find the specific course
        for (auto& enrollment : enrollments)
        {
            if (enrollment.getCourse()->getCourseKey() == courseKey)
            {
                // Update the grade for the specific course
                enrollment.setGrade(newGrade);
                cout << "Grade Updated@@@" << endl;
                isEnrolled = true;
                break;
            }
        }

        // Check whether the student is enrolled in the specific subject
        if (!isEnrolled)
        {
            cout << "Student is not enrolled in this subject" << endl;
        }
    }
}

/**
 * @brief Write student data to the output stream.
 *
 * @param out Output stream to write to.
 */
void Student::write(ostream &out) const
{
    out << matrikelNumber << ";" << lastName << ";" << firstName  << ";"
    << dateOfBirth.day() << "." << dateOfBirth.month() << "." <<dateOfBirth.year()
    <<";"<< address.getStreet() << ";" << address.getPostalCode() << ";"
    << address.getCityName() << ";" << address.getAdditionalInfo() << endl;
}

/**
 * @brief Read student data from the input stream.
 *
 * @param fin Input stream to read from.
 * @return Student Student read from the input stream.
 */
Student Student::read(ifstream &fin) const {
    string line;

    getline(fin, line, ';');  // get matriculate number

    getline(fin, line, ';');  // get last name
    string lastName = line;

    getline(fin, line, ';');  // get first name
    string firstName = line;

    getline(fin, line, '.');   // get day of birth
    unsigned int dd = stoi(line);

    getline(fin, line, '.');   // get month of birth
    unsigned int mm = stoi(line);

    getline(fin, line, ';');   // get year of birth
    unsigned int yyyy = stoi(line);

    Poco::Data::Date dateOfBirth;
    dateOfBirth.assign(yyyy, mm, dd);

    getline(fin, line, ';');   // get street name
    string street = line;

    getline(fin, line, ';');   // get postal code
    string postalCode = line;

    getline(fin, line, ';');   // get city Name
    string cityName = line;

    getline(fin, line);       // get additioanl info
    string additionalInfo = line;

    Address address(street, stoul(postalCode), cityName, additionalInfo);

    return Student(firstName, lastName, dateOfBirth, address);
}

