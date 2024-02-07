
/**
 * @file Address.cpp
 *
 * @brief Implementation file for the Address class.
 *
 * @date Jan 6, 2024
 * @author Azaz Hassan Khan
 */

#include "Address.h"



/**
 * @brief Parameterized constructor for the Address class.
 *
 * @param street Street name.
 * @param postalCode Postal code.
 * @param cityName City name.
 * @param additionalInfo Additional information about the address.
 */
Address::Address(string street, unsigned short postalCode, string cityName,
		string additionalInf)
{
	this->street = street;
	this->postalCode = postalCode;
	this->cityName = cityName;
	this->additionalInfo = additionalInfo;
}

/**
 * @brief Get additional information about the address.
 *
 * @return const string& Additional information.
 */
const string& Address::getAdditionalInfo() const
{
	return additionalInfo;
}

/**
 * @brief Get the city name of the address.
 *
 * @return const string& City name.
 */
const string& Address::getCityName() const
{
	return cityName;
}

/**
 * @brief Get the postal code of the address.
 *
 * @return unsigned short Postal code.
 */
unsigned short Address::getPostalCode() const
{
	return postalCode;
}

/**
 * @brief Get the street name of the address.
 *
 * @return const string& Street name.
 */
const string& Address::getStreet() const
{
	return street;
}

/**
 * @brief Destructor for the Address class.
 */
Address::~Address()
{}

