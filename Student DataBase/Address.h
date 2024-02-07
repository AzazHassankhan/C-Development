
#ifndef ADDRESS_H_
#define ADDRESS_H_
#include <string>
using namespace std;

/**
 * @class Address
 * @brief Represents an address with street, postal code, city name, and
 * additional information.
 */
class Address
{
private:
    string street;			    /**< Details of the street. */
    unsigned short postalCode;  /**< Details of the postal code. */
    string cityName;            /**< Details of the city name. */
    string additionalInfo;      /**< Details of additional information. */

public:


    /**
     * @brief Constructor with parameters.
     * @param street : string - Details of the street.
     * @param postalCode : unsigned short - Details of the postal code.
     * @param cityName : string - Details of the city name.
     * @param additionalInfo : string - Details of additional information.
     */
    Address(string street="", unsigned short postalCode=0, string cityName="", string
    		additionalInfo="");

    /**
     * @brief Destructor.
     */
    virtual ~Address();

    /**
     * @brief Getter function to retrieve street details.
     * @return const string& - Street details.
     */
    const string& getStreet() const;

    /**
     * @brief Getter function to retrieve postal code details.
     * @return unsigned short - Postal code details.
     */
    unsigned short getPostalCode() const;

    /**
     * @brief Getter function to retrieve city name details.
     * @return const string& - City name details.
     */
    const string& getCityName() const;

    /**
     * @brief Getter function to retrieve additional information.
     * @return const string& - Additional information.
     */
    const string& getAdditionalInfo() const;

};

#endif /* ADDRESS_H_ */
