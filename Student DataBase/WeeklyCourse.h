/*
 * WeeklyCourse.h
 *
 * Created on: Jan 6, 2024
 * Author: Azaz Hassan Khan
 */

#ifndef WEEKLYCOURSE_H_
#define WEEKLYCOURSE_H_

#include <Poco/Data/Date.h>
#include <Poco/Data/Time.h>
#include "Course.h"
#include <iostream>
#include <fstream>
#include <memory>

/**
 * @class WeeklyCourse
 * @brief Represents a weekly course that extends the base Course class.
 *
 * This class includes information about the day of the week, start time, and
 * end time for a weekly recurring course.
 */
class WeeklyCourse: public Course {
private:
    Poco::DateTime::DaysOfWeek dayOfWeek; ///< Day of the week for the course.
    Poco::Data::Time startTime; ///< Start time of the course.
    Poco::Data::Time endTime;   ///< End time of the course.

public:
    /**
     * @brief Constructor for WeeklyCourse.
     * @param courseKey The unique identifier for the course.
     * @param title The title of the course.
     * @param major The major associated with the course.
     * @param creditPoints The credit points assigned to the course.
     * @param dayOfWeek The day of the week for the weekly course.
     * @param startTime The start time of the weekly course.
     * @param endTime The end time of the weekly course.
     */
    WeeklyCourse(unsigned int courseKey, std::string title, std::string major,
                 float creditPoints, Poco::DateTime::DaysOfWeek dayOfWeek,
                 Poco::Data::Time startTime, Poco::Data::Time endTime);

    /**
      * @brief Default Constuctor for WeeklyCourse.
      */
    WeeklyCourse();
    /**
     * @brief Destructor for WeeklyCourse.
     */
    virtual ~WeeklyCourse();

    /**
     * @brief Get the day of the week for the course.
     * @return The day of the week.
     */
    Poco::DateTime::DaysOfWeek getDayOfWeek() const;

    /**
     * @brief Get the end time of the course.
     * @return The end time.
     */
    const Poco::Data::Time& getEndTime() const;

    /**
     * @brief Get the start time of the course.
     * @return The start time.
     */
    const Poco::Data::Time& getStartTime() const;

    /**
     * @brief Function to print the course details
     */
    void print() const;

    /**
     * For writing BlockCourse data in a text file in a semicolon delimited
     * fashion.
     */
    void write(std::ostream& out) const;

    /**
      * @brief Function to read from file
      * @param fin : std::ifstream& - read the file from the database file
      * @param courseKey : unsigned int - course key
      * @return WeeklyCourse - weekly course read from the file
      */
    WeeklyCourse read(std::ifstream &fin, unsigned int courseKey) const;
};

#endif /* WEEKLYCOURSE_H_ */
