
/**
 * @file WeeklyCourse.cpp
 *
 * @brief Implementation file for the WeeklyCourse class.
 *
 * @date Jan 6, 2024
 * @author Azaz Hassan Khan
 */

#include "WeeklyCourse.h"
using namespace std;

/**
 * @brief Constructor for WeeklyCourse class.
 * @param courseKey The key for the course.
 * @param title The title of the course.
 * @param major The major associated with the course.
 * @param creditPoints The credit points for the course.
 * @param dayOfWeek The day of the week the course takes place.
 * @param startTime The start time of the course.
 * @param endTime The end time of the course.
 */
WeeklyCourse::WeeklyCourse(unsigned int courseKey, std::string title,
    std::string major, float creditPoints,
    Poco::DateTime::DaysOfWeek dayOfWeek,
    Poco::Data::Time startTime, Poco::Data::Time endTime)
    : Course(courseKey, title, major, creditPoints),
      dayOfWeek(dayOfWeek), startTime(startTime), endTime(endTime)
{}

/**
 * @brief Default constructor for WeeklyCourse class.
 */
WeeklyCourse::WeeklyCourse()// @suppress("Class members should be properly initialized")
{ }

/**
 * @brief Getter for the day of the week.
 * @return The day of the week.
 */
Poco::DateTime::DaysOfWeek WeeklyCourse::getDayOfWeek() const {
    return dayOfWeek;
}

/**
 * @brief Getter for the end time of the course.
 * @return The end time of the course.
 */
const Poco::Data::Time& WeeklyCourse::getEndTime() const {
    return endTime;
}

/**
 * @brief Getter for the start time of the course.
 * @return The start time of the course.
 */
const Poco::Data::Time& WeeklyCourse::getStartTime() const {
    return startTime;
}

/**
 * @brief Function to print details of the weekly course.
 */
void WeeklyCourse::print() const
{
    string weekDay;

    cout << "   Course type: Weekly Course" << endl;
    Course::print();
    switch(dayOfWeek)
    {
    case 0:
        weekDay = "Sunday";
        break;
    case 1:
        weekDay = "Monday";
        break;
    case 2:
        weekDay = "Tuesday";
        break;
    case 3:
        weekDay = "Wednesday";
        break;
    case 4:
        weekDay = "Thursday";
        break;
    case 5:
        weekDay = "Friday";
        break;
    case 6:
        weekDay = "Saturday";
        break;
    default:
        weekDay = "N/A";
        break;
    }

    cout << "Classes take place every: " << weekDay << endl;

    int hour = startTime.hour();
    int minute = startTime.minute();
    int second = startTime.second();
    cout << "Start Time: " << hour << ":" << minute << ":" << second << endl;

    hour = endTime.hour();
    minute = endTime.minute();
    second = endTime.second();
    cout << "End Time: " << hour << ":" << minute << ":" << second << endl;
    cout << endl;
}

/**
 * @brief Function to write details of the weekly course to the file.
 * @param out The output stream to write to.
 */
void WeeklyCourse::write(std::ostream &out) const
{
    out << 'W' << ";";
    Course::write(out);
    out << dayOfWeek << ";" << startTime.hour() << ":" << startTime.minute() <<
        ";" << endTime.hour() << ":" << endTime.minute() << ";" << endl;
}

/**
 * @brief Function to read details of the weekly course from the file.
 * @param fin The input file stream to read from.
 * @param courseKey The key for the course.
 * @return The constructed WeeklyCourse object.
 */
WeeklyCourse WeeklyCourse::read(std::ifstream &fin, unsigned int courseKey) const
{
    string line;
    unsigned int second = 0;

    getline(fin, line, ';');  //get the subject
    string subject = line;

    getline(fin, line, ';');  //get the major
    string major = line;

    getline(fin, line, ';');  //get the Credit points
    float credits = stoi(line);

    getline(fin, line, ';');  //get the Dayofweek
    int days = stoi(line);

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

    WeeklyCourse weeklycourse(courseKey, subject, major, credits,
        (Poco::DateTime::DaysOfWeek) days, startTime, endTime);

    return weeklycourse;
}

/**
 * @brief Destructor for WeeklyCourse class.
 */
WeeklyCourse::~WeeklyCourse() {
}

