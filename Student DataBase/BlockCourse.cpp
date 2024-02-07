/**
 * @file BlockCourse.cpp
 *
 * @brief Implementation file for the BlockCourse class.
 *
 * @date Jan 6, 2024
 * @author Azaz Hassan Khan
 */

#include "BlockCourse.h"
using namespace std;

/**
 * @brief Constructor for the BlockCourse class.
 *
 * @param courseKey Course key of the block course.
 * @param title Title of the block course.
 * @param major Major associated with the block course.
 * @param creditPoints Credit points for the block course.
 * @param startDate Start date of the block course.
 * @param endDate End date of the block course.
 * @param startTime Start time of the block course.
 * @param endTime End time of the block course.
 */
BlockCourse::BlockCourse(unsigned int courseKey, std::string title,
    std::string major, float creditPoints, Poco::Data::Date startDate,
    Poco::Data::Date endDate, Poco::Data::Time startTime,
    Poco::Data::Time endTime):Course(courseKey, title, major, creditPoints),
    startDate(startDate), endDate(endDate), startTime(startTime), endTime(endTime)
{}

/**
 * @brief Default Constructor for the BlockCourse class.
 */
BlockCourse::BlockCourse() {}

/**
 * @brief Destructor for the BlockCourse class.
 */
BlockCourse::~BlockCourse()
{}

/**
 * @brief Get the end date of the block course.
 *
 * @return const Poco::Data::Date& End date of the block course.
 */
const Poco::Data::Date& BlockCourse::getEndDate() const {
    return endDate;
}

/**
 * @brief Get the end time of the block course.
 *
 * @return const Poco::Data::Time& End time of the block course.
 */
const Poco::Data::Time& BlockCourse::getEndTime() const {
    return endTime;
}

/**
 * @brief Get the start date of the block course.
 *
 * @return const Poco::Data::Date& Start date of the block course.
 */
const Poco::Data::Date& BlockCourse::getStartDate() const {
    return startDate;
}

/**
 * @brief Get the start time of the block course.
 *
 * @return const Poco::Data::Time& Start time of the block course.
 */
const Poco::Data::Time& BlockCourse::getStartTime() const {
    return startTime;
}

/**
 * @brief Print details of the block course.
 */
void BlockCourse::print() const
{
    cout << "   Course type: Block Course" << endl;
    Course::print();

    cout << "Start Date : ";
    int day = startDate.day();
    int month = startDate.month();
    int year = startDate.year();
    cout << day << "/" << month << "/" << year << endl;

    cout << "End Date : ";
    day = endDate.day();
    month = endDate.month();
    year = endDate.year();
    cout << day << "/" << month << "/" << year << endl;

    cout << "Start Time : ";
    int hour = startTime.hour();
    int minute = startTime.minute();
    int second = startTime.second();
    cout << hour << ":" << minute << ":" << second << endl;

    cout << "End Time : ";
    hour   = endTime.hour();
    minute = endTime.minute();
    second = endTime.second();
    cout << hour << ":" << minute << ":" << second << endl;
    cout << endl;
}

/**
 * @brief Write details of the block course to the output stream.
 *
 * @param out Output stream to write to.
 */
void BlockCourse::write(ostream &out) const
{
    out << 'B' << ";";
    Course::write(out);
    out << startDate.day() << "." << startDate.month() << "." << startDate.year()
        << ";"<< endDate.day() << "." << endDate.month() << "." << endDate.year()
        << ";"<< startTime.hour() << ":" << startTime.minute() << ";"
        << endTime.hour() << ":" << endTime.minute() << endl;
}

/**
 * @brief Read block course data from the input stream.
 *
 * @param fin Input stream to read from.
 * @param courseKey Course key of the block course.
 * @return BlockCourse Block course read from the input stream.
 */
BlockCourse BlockCourse::read(std::ifstream &fin,unsigned int courseKey)
const {
    string line;
    unsigned int second=0;

    getline(fin, line, ';');  //get the subject
    string subject = line;

    getline(fin, line, ';');  //get the major
    string major = line;

    getline(fin, line, ';');  //get the Credit points
    float credits = stoi(line);

    getline(fin, line, '.');   //Get the starting day
    unsigned int dd = stoi(line);

    getline(fin, line, '.');    //Get the starting month
    unsigned int mm = stoi(line);

    getline(fin, line, ';');    //Get the starting year
    unsigned int yyyy = stoi(line);

    Poco::Data::Date startDate;
    startDate.assign(yyyy, mm, dd);

    getline(fin, line, '.'); //Get the ending day
    dd = stoi(line);
    getline(fin, line, '.'); //Get the ending month
    mm = stoi(line);
    getline(fin, line, ';'); //Get the ending year
    yyyy = stoi(line);

    Poco::Data::Date endDate;
    endDate.assign(yyyy, mm, dd);

    getline(fin, line, ':');  //get the starting hour
    unsigned int hour = stoi(line);

    getline(fin, line, ';');    //get the starting minute
    unsigned int minute = stoi(line);

    Poco::Data::Time startTime;
    startTime.assign(hour, minute, second);

    getline(fin, line, ':'); //get the ending hour
    hour = stoi(line);

    getline(fin, line);       //get the ending minute
    minute = stoi(line);

    Poco::Data::Time endTime;
    endTime.assign(hour, minute, second);

    BlockCourse blockcourse(courseKey, subject, major,
    credits, startDate, endDate, startTime, endTime);

    return blockcourse;
}
