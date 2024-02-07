/*
 * SimpleUI.h
 *
 *Created on: Jan 6, 2024
 *Author: Azaz Hassan Khan
 */

#ifndef SIMPLEUI_H_
#define SIMPLEUI_H_
#include "StudentDb.h"

class SimpleUI {
private:
	//StudentDb *dataBase;
	StudentDb &db;
public:
	/**
	 * @brief Constructor
	 * @param db : StudentDb& - reference of the StudentDb class
	 */
	SimpleUI(StudentDb &db);

	/**
	 * @brief Function to handle the database.
	 */
	void run();

	/**
	 * @brief Destructor.
	 */
	virtual ~SimpleUI();
};

#endif /* SIMPLEUI_H_ */
