/**
 * @file StudentDb.cpp
 *
 * @brief Implementation file for the StudentDb class.
 *
 * @date Jan 6, 2024
 * @author Azaz Hassan Khan
 */
#include "StudentDb.h"
using namespace std;

/**
 * @brief Default constructor for the StudentDb class.
 */
StudentDb::StudentDb() {}

/**
 * @brief Destructor for the StudentDb class.
 */
StudentDb::~StudentDb() {}

/**
 * @brief Function to add a new course to the database.
 *        Prompts the user to input course details and adds the course to the database.
 */
void StudentDb::addNewCourse()
{
	// Variables to store course information
	unsigned int courseKey, dd, mm, yyyy, hour, minute, second;
	string title, major;
	float creditPoints;
	char courseType;
	Poco::Data::Time startTime, endTime;

	// Input course details from the user
	cout << "Enter the Course Key : ";
	cin >> courseKey;

	cout << "Enter the Title of the course : ";
	cin.ignore();
	getline(cin, title);

	cout << "Enter the Major : ";
	cin >> major;

	cout << "Enter the Credit Points : ";
	cin >> creditPoints;

	cout << "Enter the Start time of the course (hh:mm:ss) : ";
	cin >> hour >> minute >> second;
	startTime.assign(hour, minute, second);

	cout << "Enter the End time of the course (hh:mm:ss) : ";
	cin >> hour >> minute >> second;
	endTime.assign(hour, minute, second);

	// Input the type of course (Block or Weekly)
	cout << "Enter the type of Course" << endl;
	cout << "Select 'B' for Block Course or 'W' for Weekly Course : ";
	cin >> courseType;

	if (courseType == 'B')
	{
		// Input additional details for Block Course
		Poco::Data::Date startDate, endDate;
		cout << "Enter the Start date in (dd:mm:yyyy) format : ";
		cin >> dd >> mm >> yyyy;
		startDate.assign(yyyy, mm, dd);
		cout << "Enter the End date in (dd:mm:yyyy) format : ";
		cin >> dd >> mm >> yyyy;
		endDate.assign(yyyy, mm, dd);

		// Create BlockCourse object and insert into the database
		const BlockCourse blockCourse(courseKey, title, major, creditPoints,
			startDate, endDate, startTime, endTime);
		unique_ptr<const Course > blockCoursePtr = make_unique < BlockCourse>
				(blockCourse);
		courses.insert(make_pair(courseKey, move(blockCoursePtr)));

		cout << "Block Course Added to Database" << endl;
	}
	else if (courseType == 'W')
	{
		// Input additional details for Weekly Course
		int dayOfWeek;
		cout << "Select the day of the week the course takes place:" << endl;
		cout << "SUNDAY=0, MONDAY=1, TUESDAY=2, WEDNESDAY=3, THURSDAY=4, FRIDAY=5"
		", SATURDAY=6" << endl;
		cin >> dayOfWeek;

		// Create WeeklyCourse object and insert into the database
		WeeklyCourse weeklyCourse(courseKey, title, major, creditPoints,
			(Poco::DateTime::DaysOfWeek) dayOfWeek, startTime, endTime);
		unique_ptr<const Course > weeklyCoursePtr = make_unique < WeeklyCourse>
				(weeklyCourse);
		courses.insert(make_pair(courseKey, move(weeklyCoursePtr)));

		cout << "Weekly Course Added to Database" << endl;
	}
	else
	{
		cout << "Invalid Command" << endl;
	}
}

/**
 * @brief Function to list courses in the database.
 *        Displays a list of courses present in the database.
 */
void StudentDb::listCourses() const
{
	int index = 1;
	cout << "Courses present in Database : " << endl;

	// Iterate through the courses container using a range-based for loop
	for (const auto &courseAdded: courses)
	{
		cout << index << ") ";	// Print the index of the course

		// Call the print function of the Course object
		courseAdded.second->print();

		index++;	// Increment the index for the next course
	}
}

/**
 * @brief Function to add a new student to the database.
 *        Prompts the user to input student details and adds the student to the database.
 */
void StudentDb::addNewStudent()
{
	// Variables to store student information
	string firstName, lastName;
	Poco::Data::Date dateOfBirth;
	int dd, mm, yyyy;
	string street, cityName, additionalInfo;
	unsigned short postalCode;

	// Input new student details from the user
	cout << "***New Student Profile***" << endl;

	// Get First Name
	cout << "Enter First Name: ";
	cin >> firstName;

	// Get Last Name
	cout << "Enter Last Name: ";
	cin >> lastName;

	// Get Date of Birth
	cout << "Enter Date of Birth (dd:mm:yyyy): ";
	cin >> dd >> mm >> yyyy;
	dateOfBirth.assign(yyyy, mm, dd);

	// Get Street Name
	cout << "Enter Street name: ";
	cin.ignore();
	getline(cin, street);

	// Get City Name
	cout << "Enter City name: ";
	cin >> cityName;

	// Get Postal Code
	cout << "Enter Postal-Code: ";
	cin >> postalCode;

	// Get Additional Info
	cout << "Enter Additional Info: ";
	cin.ignore();
	getline(cin, additionalInfo);

	// Create Address object with the provided details
	Address address(street, postalCode, cityName, additionalInfo);

	// Create a new Student object with the provided details
	Student student(firstName, lastName, dateOfBirth, address);

	// Insert the new student into the database
	students.insert(make_pair(student.getMatrikelNumber(), student));

	// Display confirmation message
	cout << "Student Added to Database@@@" << endl;
}

/**
 * @brief Function to print student information based on matriculation number.
 *        Displays the information of a student with a given matriculation number.
 * @param matrikelNumber The matriculation number of the student.
 */
void StudentDb::printStudent(unsigned int matrikelNumber) const
{
	students.at(matrikelNumber).print();
}

/**
 * @brief Function to enroll a student in a specific course.
 *        Prompts the user for matriculation number, course ID, and semester,
 *        then adds an enrollment for the student in the specified course.
 */
void StudentDb::AddEnrollment()
{
	// Get user input for Matrikel Number, Course ID, and Semester
	unsigned int matrikelNumber, courseKey;

	cout << "Please enter your Matrikel Number: ";
	cin >> matrikelNumber;
	cout << endl;

	cout << "Please enter the Course ID: ";
	cin >> courseKey;
	cout << endl;

	string semester;
	cout << "Please enter the Semester: ";
	cin >> semester;
	cout << endl;

	// Find the student and course based on provided keys
	auto studentFound = students.find(matrikelNumber);
	auto courseFound = courses.find(courseKey);

	// Check if both the student and course are found
	if (studentFound != students.end() && courseFound != courses.end())
	{
		/*Create a new Enrollment object with initial grade 0.0, provided
    	semester, and the found course*/
		Enrollment newEnrollment(0.0, semester, courseFound->second.get());

		// Update the student's enrollments with the new enrollment
		students.at(matrikelNumber).updateEnrollments(newEnrollment);

		cout << "Enrollment Added Successfully@@@" << endl;
	}
	else
	{
		// Display an error message if the course or student is not found
		cout << "!!!Course not found or Immatriculation number is wrong!!!" << endl;
	}
}

/**
 * @brief Function to search for a student by name in the database.
 *        Prompts the user to enter a student's name and searches for a match.
 */
void StudentDb::searchStudent()
{
	// Prompt the user to enter the student's name to be searched
	string name;
	cout << "Enter the student's name to be searched: ";
	cin >> name;

	bool StudentFound = false;	// Initialize a flag to track the student is found

	// Iterate through the students in the database
	for (auto student: students)
	{
		// Check if the entered name is found in either the first name or last name
		if (student.second.getFirstName().find(name) != string::npos ||
			student.second.getLastName().find(name) != string::npos)
		{
			// Display information about the found student
			cout << "***Student found***" << endl << "First Name: " <<
				student.second.getFirstName() << endl << "Last Name: " <<
				student.second.getLastName() << endl << "Matrikel Number: " <<
				student.second.getMatrikelNumber() << endl;

			StudentFound = true;	// Set the flag to true since the student found
		}
	}

	// Display a message if the student is not found by the entered name
	if (!StudentFound)
	{
		cout << "Student not found by the entered name." << endl;
	}
}

/**
 * @brief Function to update student information in the database.
 *        Prompts the user to enter the matriculation number and attribute to update.
 */
void StudentDb::updateStudentData()
{
	bool studentFoundFlag = true;
	unsigned int matrikelNumber, attribute;

	cout << "Please enter the Matrikel Number of the Student : ";
	cin >> matrikelNumber;

	auto studentFound = students.find(matrikelNumber);

	if (studentFound != students.end())
	{
		studentFoundFlag = true;
	}
	else
	{
		studentFoundFlag = false;
	}

	if (studentFoundFlag)
	{
		cout << "Student Found" << endl;
		while (studentFoundFlag)
		{
			cout << "Please select the Attribute you wish to update : " << endl <<
				"0 - Exit" << endl <<
				"1 - First Name" << endl <<
				"2 - Last Name" << endl <<
				"3 - Date Of Birth" << endl <<
				"4 - Enrollment" << endl <<
				"5 - Address" << endl;

			cin >> attribute;
			switch (attribute)
			{
			 	// 0 - Exit
				case 0:
					studentFoundFlag = false;
					cout << "***Exit***" << endl;
					break;

					// 1 - First Name
				case 1:
					{
						string newFirstName;
						cout << "Enter the new First Name : ";
						cin >> newFirstName;
						studentFound->second.setFirstName(newFirstName);
						cout << "***First Name Updated***" << endl;
						break;
					}

					// 2 - Last Name
				case 2:
					{
						string newLastName;
						cout << "Enter the new Last Name : ";
						cin >> newLastName;
						studentFound->second.setLastName(newLastName);
						cout << "***Last Name Updated***" << endl;
						break;
					}

					// 3 - Date Of Birth
				case 3:
					{
						int newDate, newMonth, newYear;
						cout << "Enter the new date of birth (dd mm yyyy) : ";
						cin >> newDate >> newMonth >> newYear;
						cout << "***Birth Day Updated***" << endl;
						studentFound->second.setDateOfBirth(Poco::Data::Date(newYear, newMonth, newDate));
						break;
					}

					// 4 - Enrollment
				case 4:
					{
						unsigned int courseKey, enrollmentAction;
						float newGrade;

						cout << "Select an Option : " << endl <<
						"1. Delete Enrollment" << endl <<
						"2. Update Grade " << endl;
						cin >> enrollmentAction;
						cout << "Enter the Course Key : ";
						cin >> courseKey;
						switch (enrollmentAction)
						{
						 				// Delete Enrollment
							case 1:
								studentFound->second.deleteEnrollment(courseKey);
								break;

								// Update Grade
							case 2:
								cout << "Please enter the new grade : ";
								cin >> newGrade;
								studentFound->second.updateGrade(courseKey,
									newGrade);
								break;
						}

						break;
					}

					// 5 - Address
				case 5:
					{
						string newStreetName, newCityName, newAdditionalInfo;
						unsigned int newPostalCode;
						cout << "Enter the new address : " << endl;

						cout << "Street Name : ";
						cin >> newStreetName;

						cout << "City Name : ";
						cin >> newCityName;

						cout << "Postal Code : ";
						cin >> newPostalCode;

						cout << "Additional Info : ";
						cin >> newAdditionalInfo;

						studentFound->second.setAddress(Address(newStreetName,
							newPostalCode, newCityName, newAdditionalInfo));
						break;
					}
			}
		}
	}
	else
	{
		cout << "Student Not found!!!";
	}
}

/**
 * @brief Function to check if a given matriculation number is present in the database.
 * @param matrikelNumber The matriculation number to check.
 * @return True if the matriculation number is found, false otherwise.
 */
bool StudentDb::checkMatrikelNumber(unsigned int matrikelNumber) const
{
	// Flag to store the result of the search
	bool isStudentFound = false;

	// Search for the student with the given Matrikel Number in the database
	auto studentIterator = students.find(matrikelNumber);

	// Check if the student was found
	if (studentIterator != students.end())
	{
		// Student with the given Matrikel Number found in the database
		isStudentFound = true;
	}
	else
	{
		// Student with the given Matrikel Number not found in the database
		isStudentFound = false;
	}

	// Return the result of the search
	return isStudentFound;
}

/**
 * @brief Function to write the database to a file.
 *        Writes information about courses, students, and enrollments to a CSV file.
 */
void StudentDb::write() const
{
	// Create an output file stream to write to the CSV file
	ofstream fout;

	// Open the CSV file for writing
	fout.open("C:/Users/Azaz/Lab/StudentDb/StudentDataBase.csv");

	// Check if the file is opened successfully
	if (fout.is_open())
	{
		cout << "File Opened Successfully@@@" << endl;

		// Write the total number of courses to the file
		fout << courses.size() << "\n";

		// Write information about each course to the file
		if (courses.size() != 0)
		{
			for (const auto &course: courses)
			{
				course.second->write(fout);
			}
		}

		// Write the total number of students to the file
		fout << students.size() << "\n";

		// Write information about each student to the file
		if (students.size() != 0)
		{
			for (const auto &student: students)
			{
				student.second.write(fout);
			}
		}

		// Calculate total number of enrollments
		unsigned short EnrollmentSize = 0;
		for (const auto &student: students)
		{
			EnrollmentSize += student.second.getEnrollments().size();
		}

		// Write the total number of enrollments for the student
		fout << EnrollmentSize << "\n";

		// Iterate through each student to check and write enrollments
		if (EnrollmentSize != 0)
		{
			for (const auto &student: students)
			{
			 	// Write information about each enrollment for the student
				for (const auto &enrollment: student.second.getEnrollments())
				{
					fout << student.second.getMatrikelNumber() << ";";
					enrollment.write(fout);
					fout << "\n";
				}
			}
		}
	}
	else
	{
		// Display an error message if the file cannot be opened
		cout << "!!!Unable to open file" << endl;
	}

	// Close the file stream
	fout.close();
}

/**
 * @brief Function to read the database from a file.
 *        Reads information about courses, students, and enrollments from a CSV file.
 */
void StudentDb::read()
{
	std::ifstream fin;
	fin.open("StudentDataBase.csv");

	if (fin.is_open())
	{
		std::cout << "File Opened Successfully@@@" << std::endl;

		students.clear();	// Clear student map
		courses.clear();	// Clear courses map

		std::string line;
		getline(fin, line);	// Get the first line of the CSV file

		if (!line.empty())
		{
			// Read the number of courses
			int noOfCourses = std::stoi(line);

			// Loop through each course in the CSV file
			for (int i = 0; i < noOfCourses; i++)
			{
				getline(fin, line, ';');	// Get the type of course
				std::string courseType = line;

				getline(fin, line, ';');	// Get the course key
				unsigned int courseKey = std::stoi(line);

				// Read and construct the appropriate course type
				if (courseType == "W")
				{
					WeeklyCourse weeklyCourse;
					weeklyCourse = weeklyCourse.read(fin, courseKey);

					// Create a unique_ptr and insert it into the courses map
					std::unique_ptr<const Course > weeklyCoursePtr =
							std::make_unique<WeeklyCourse> (weeklyCourse);

					courses.insert(std::make_pair(courseKey, std::move(weeklyCoursePtr)));
				}
				else if (courseType == "B")
				{
					BlockCourse blockCourse;
					blockCourse = blockCourse.read(fin, courseKey);

					// Create a unique_ptr and insert it into the courses map
					std::unique_ptr<const Course > blockCoursePtr =
							std::make_unique<BlockCourse> (blockCourse);

					courses.insert(std::make_pair(courseKey, std::move(blockCoursePtr)));
				}
			}
		}

		// Read the number of students
		getline(fin, line);
		if (!line.empty())
		{
			int noOfStudents = std::stoi(line);
			Student student;
			// Loop through each student in the CSV file
			for (int i = 0; i < noOfStudents; i++)
			{
				student = student.read(fin);

				// Insert the student into the students map
				students.insert(std::make_pair(student.getMatrikelNumber(),
					student));
			}
		}

		// Read the total enrollments

		getline(fin, line);
		if (!line.empty())
		{
			int noOfEnrollments = std::stoi(line);

			// Loop through each enrollment in the CSV file
			for (int i = 0; i < noOfEnrollments; i++)
			{
				getline(fin, line, ';');	// Get matriculate number
				unsigned int matrikelNumber = std::stoi(line);

				getline(fin, line, ';');	// Get course key
				unsigned int courseKey = std::stoi(line);

				// Find the course with the specific key to pass through the
				// enrollment class
				auto courseFound = courses.find(courseKey);

				// Create Enrollment Class
				Enrollment newEnrollment;

				newEnrollment = newEnrollment.read(fin, courseFound->second.get());

				// Add Enrollment Class to the specific Matriculate number
				students.at(matrikelNumber).updateEnrollments(newEnrollment);
			}
		}
	}
	else
	{
		std::cout << "!!!Unable to open file" << std::endl;
	}

	fin.close();
}

/**
 * @brief Function to connect to a server, send requests, and receive data.
 *        Establishes a connection to the server and interacts based on user input.
 */
void StudentDb::ConnectToServer()
{
	try
	{
		// Establish a connection to the server using boost::asio::ip::tcp::iostream
		boost::asio::ip::tcp::iostream stream("www.hhs.users.h-da.cloud", "4242");

		// Check if the connection is successful
		if (!stream)
		{
			cerr << "Failed to connect to the server" << endl;
			return;	// Exit the function if the connection fails
		}

		// Get the number of students' data to be extracted
		int students;
		cout << "Enter the Number of Students data to be extracted: ";
		cin >> students;

		string responseData;

		// Loop to request and process data for the specified number of students
		for (int i = 0; i < students; i++)
		{
			// Write data to the server to initiate a "generate" operation
			stream << "generate" << endl;

			// Read and print the first line of the response from the server
			getline(stream, responseData);

			// Read and print the second line of the response from the server
			getline(stream, responseData);

			// Json Data Parser
			JsonParser(responseData);

			// Read and print the third line of the response from the server
			getline(stream, responseData);
		}

		// Send "quit" to the server to close the connection
		stream << "quit" << endl;

		// Read and print the response after sending "quit"
		getline(stream, responseData);
	}

	catch (const exception &e)
	{
		cout << "Error in Server" << endl;
	}
}

/**
 * @brief Function to parse JSON data and add information to the database.
 *        Parses JSON data and adds student information to the database.
 * @param data The JSON data to be parsed.
 */
void StudentDb::JsonParser(string data)
{
	// Create a Json Parser object using Boost Library
	boost::property_tree::ptree DataAccess;

	// Create an object to store JSON parsed data
	std::istringstream Parser(data);

	// Json function to access parsed data using DataAccess object
	boost::property_tree::read_json(Parser, DataAccess);

	// Access first and last name
	string FirstName = DataAccess.get<string> ("name.firstName");
	string LastName = DataAccess.get<string> ("name.lastName");

	// Access date of birth
	unsigned int Day = DataAccess.get < unsigned int > ("dateOfBirth.day");
	unsigned int Month = DataAccess.get < unsigned int > ("dateOfBirth.month");
	unsigned int Year = DataAccess.get < unsigned int > ("dateOfBirth.year");

	// Handle potential zero values in day, month, or year
	if (Day == 0)
	{
		Day = 1;
	}

	if (Month == 0)
	{
		Month = 1;
	}

	if (Year == 0)
	{
		Year = 1;
	}

	// Create a Date object for date of birth
	Poco::Data::Date dateOfBirth;
	dateOfBirth.assign(Year, Month, Day);

	// Access address information
	string Street = DataAccess.get<string> ("location.street");
	string City = DataAccess.get<string> ("location.city");
	string PostalCode = DataAccess.get<string> ("location.postCode");
	string AdditionalInfo = DataAccess.get<string> ("location.state");

	// Convert postal code to an unsigned integer, handling invalid input
	unsigned int postalCode = 0;
	try
	{
		postalCode = std::stoul(PostalCode);
	}

	catch (const std::invalid_argument &e)
	{
		postalCode = 0;
	}

	// Add information to the database
	Address address(Street, postalCode, City, AdditionalInfo);
	Student student(FirstName, LastName, dateOfBirth, address);
	students.insert(make_pair(student.getMatrikelNumber(), student));
}
