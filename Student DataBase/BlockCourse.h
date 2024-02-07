#ifndef BLOCKCOURSE_H_
#define BLOCKCOURSE_H_

#include <Poco/Data/Date.h>
#include <Poco/Data/Time.h>

#include "Course.h"
#include <iostream>
#include <fstream>

/**
 * @class BlockCourse
 * @brief Represents a block course, a derived class of the Course class.
 */
class BlockCourse : public Course {
private:
    /**
     * @brief startDate : Poco::Data::Date - start date of the block course
     */
    Poco::Data::Date startDate;

    /**
     * @brief endDate : Poco::Data::Date - end date of the block course
     */
    Poco::Data::Date endDate;

    /**
     * @brief startTime : Poco::Data::Time - start time of the block course
     */
    Poco::Data::Time startTime;

    /**
     * @brief endTime : Poco::Data::Time - end time of the block course
     */
    Poco::Data::Time endTime;

public:
    /**
     * @brief Constructor for BlockCourse
     * @param courseKey : unsigned int - course ID
     * @param title : std::string - title of the course
     * @param major : std::string - major of the course
     * @param creditPoints : float - credit points of the course
     * @param startDate : Poco::Data::Date - start date of the block course
     * @param endDate : Poco::Data::Date - end date of the block course
     * @param startTime : Poco::Data::Time - start time of the block course
     * @param endTime : Poco::Data::Time - end time of the block course
     */
    BlockCourse(unsigned int courseKey, std::string title, std::string major,
        float creditPoints, Poco::Data::Date startDate, Poco::Data::Date endDate,
        Poco::Data::Time startTime, Poco::Data::Time endTime);

    /**
      * @brief Default Constuctor for BlockCourse.
      */
    BlockCourse();
    /**
     * @brief Destructor for BlockCourse
     */
    virtual ~BlockCourse();

    /**
     * @brief Get the end date of the block course.
     * @return The end date.
     */
    const Poco::Data::Date& getEndDate() const;

    /**
     * @brief Get the end time of the block course.
     * @return The end time.
     */
    const Poco::Data::Time& getEndTime() const;

    /**
     * @brief Get the start date of the block course.
     * @return The start date.
     */
    const Poco::Data::Date& getStartDate() const;

    /**
     * @brief Get the start time of the block course.
     * @return The start time.
     */
    const Poco::Data::Time& getStartTime() const;

    /**
     * @brief Function to print details of the block course.
     */
    void print() const;

    /**
     * @brief Function to write block course data in a text file in a semicolon
     *  delimited fashion.
     */
    void write(std::ostream& out) const;

    /**
      * @brief Function to read from file
      * @param fin : ifstream& - read the file from database file
      * @param courseKey : unsigned int - course ID
      * @return BlockCourse - block course read from file
      */
    BlockCourse read(std::ifstream& fin, unsigned int courseKey) const;

};

#endif /* BLOCKCOURSE_H_ */
