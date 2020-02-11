/****************************************************************************
Title:			C++ Programming Assignment 6: Monkey Food
Author:			Allison Crenshaw
Status:			In Progress
Date Started:	11/21/2019
Revised:
	<date>
	<date>

Program Description:
	This program uses a two-dimensional array to track data for how many 
	pounds of food three monkeys eat each day during a week. 
	
The program outputs a formatted table that displays:
		-each monkey's food intake for each day of the week 
		-average amount of food eaten per day by the whole group of monkeys
		-least amount of food eaten by any monkey during the week
		-greatest amount of food eaten by any monkey during the week
	
****************************************************************************/

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// PROGRAM CONSTANTS
const int NUM_OF_MONKEYS = 3;	// each row reps a monkey
const int NUM_OF_DAYS = 7; 		// each column reps a day of the week

/****************************************************************************
Function: dataInput
*****************************************************************************
Description: takes input for two dimensional array of monkey food data
Calls: 
Parameters: none
Returns: 0
****************************************************************************/
void dataInput(double monkeys[][NUM_OF_DAYS]) 
{
	cout << "Please enter the number of pounds of food eaten ";
	cout << "by each monkey for each day of the week." << endl;
	
	// take input for each monkey on each day
	// start for loop
	for (int monkey = 0; monkey < NUM_OF_MONKEYS; monkey++) {
		cout << endl;
		cout << "Data for Monkey " << monkey+1 << ":" << endl;
		cout << "********************" << endl;
		// start for loop
		for (int day = 0; day < NUM_OF_DAYS; day++) {
			cout << "Day " << day+1 << ": ";
			cin >> monkeys[monkey][day];
			
			// while loop to validate data (do not accept negative nums)
			// start while loop
			while (monkeys[monkey][day] < 0) {
				cout << "Error! Please enter a positive number: ";
				cin >> monkeys[monkey][day];
				cout << endl << endl;
			} // end while loop
			
		} // end day for loop
	} // end monkey for loop
	cout << endl;
} // end dataInput()



/****************************************************************************
Function: calculateAverage()
*****************************************************************************
Description: 
Calls: 
Parameters: none
Returns: 0
****************************************************************************/
double calculateAverage(double monkeys[][NUM_OF_DAYS]) 
{
	// function member variables
	double total = 0;		// total # of pounds eaten in week by all monkeys
	double average = 0;		// average of pounds of food eaten by the three
							// monkeys per day
	
	// loop through each day within monkey1, 2, and 3 and add to total
	// start for loop
	for (int monkey = 0; monkey < NUM_OF_MONKEYS; monkey++) {
		// start for loop
		for (int day = 0; day < NUM_OF_DAYS; day++) {
			total += monkeys[monkey][day];
		} // end day for loop
	} // end monkey for loop
	
	// calculate and return average
	average = total / NUM_OF_DAYS;
	return average;
} // end calculateAverage()



/****************************************************************************
Function: findMost()
*****************************************************************************
Description: 
Calls: 
Parameters: none
Returns: 0
****************************************************************************/
double findMost(double monkeys[][NUM_OF_DAYS]) 
{
	// function member variables
	double mostFood = 0;
	double newAmount = 0;
	
	// assign mostFood value of first monkey, first day to start comparisons
	mostFood = monkeys[0][0];
	
	// loop through each day within monkey1, 2, and 3 to compare values
	// start for loop
	for (int monkey = 0; monkey < NUM_OF_MONKEYS; monkey++) {
		// start for loop
		for (int day = 0; day < NUM_OF_DAYS; day++) {
			// assign current iteration's amount to newAmount
			newAmount = monkeys[monkey][day];
			
			// start if to reassign mostFood if newAmount is higher
			if (newAmount > mostFood) {
				mostFood = newAmount;
			}
		
		} // end day for loop
	} // end monkey for loop
	
	return mostFood;
} // end findMost()



/****************************************************************************
Function: findLeast()
*****************************************************************************
Description: 
Calls: 
Parameters: none
Returns: 0
****************************************************************************/
double findLeast(double monkeys[][NUM_OF_DAYS]) 
{
	// function member variables
	double leastFood = 0;
	double newAmount = 0;
	
	// assign leastFood value of first monkey, first day to start comparisons
	leastFood = monkeys[0][0];
	
	// loop through each day within monkey1, 2, and 3 to compare values
	// start for loop
	for (int monkey = 0; monkey < NUM_OF_MONKEYS; monkey++) {
		// start for loop
		for (int day = 0; day < NUM_OF_DAYS; day++) {
			// assign current iteration's amount to newAmount
			newAmount = monkeys[monkey][day];
			
			// start if to reassign leastFood if newAmount is lower
			if (newAmount < leastFood) {
				leastFood = newAmount;
			}
		
		} // end day for loop
	} // end monkey for loop
	
	return leastFood;
} // end findLeast()



/****************************************************************************
Function: createTable()
*****************************************************************************
Description: 
Calls: 
Parameters: none
Returns: 0
****************************************************************************/
void createTable(double monkeys[][NUM_OF_DAYS]) 
{
	// function member variables
	
	// title for table
	cout << endl;
	cout << "Pounds of Food Eaten by Monkey and Day of Week" << endl;
	cout << endl;
	
	// column headers
	cout << setw(10) << "          " << setw(8) << "Sun" << setw(8) << "Mon" << setw(8) << "Tue" << setw(8) << "Wed" 
									 << setw(8) << "Thur" << setw(8) << "Fri" << setw(8) << "Sat" << endl;
	
	// start for loop
	for (int monkey = 0; monkey < NUM_OF_MONKEYS; monkey++) {
		// row labels
		cout << setw(8) << "Monkey" << monkey+1 << ":";
		// start for loop
		for (int day = 0; day < NUM_OF_DAYS; day++) {
			cout << setw(8) << setprecision(2) << fixed << monkeys[monkey][day];
		} // end day for loop
		cout << endl;
	} // end monkey for loop
	
} // end createTable()


/****************************************************************************
Function: main
*****************************************************************************
Description: driver for monkey food program
Calls: 
Parameters: none
Returns: 0
****************************************************************************/
int main() {
	// main function member variables
	double dailyAverage = 0;		// stores average # of pounds eaten per day
	double mostFood= 0;
	double leastFood = 0;
	
	// intro message 
	cout << "Welcome to Monkey Managers, the best monkey food ";
	cout << "tracking system available." << endl;
	cout << endl;
	
	// create array to store data for monkeys
	double monkeys[NUM_OF_MONKEYS][NUM_OF_DAYS];	// 3 rows, 7 columns
	int monkey1 = 0;
	int monkey2 = 1;
	int monkey3 = 2;
	
	// call function to take input for monkeys' food data
	dataInput(monkeys);
	
	// call function to calculate average & print results
	dailyAverage = calculateAverage(monkeys);
	cout << endl;
	cout << "The average food eaten per day by all monkeys: ";
	cout << dailyAverage << endl;
	
	// call functions to find mostFood and leastFood & print results
	mostFood = findMost(monkeys);
	cout << "The largest amount of food eaten by any monkey: ";
	cout << mostFood << endl;
	leastFood = findLeast(monkeys);
	cout << "The least amount of food eaten by any monkey: ";
	cout << leastFood << endl;
	cout << endl;
	
	createTable(monkeys);
	
	// end message and return
	cout << endl;
	cout << "fin." << endl;
	return 0;
} // end main 



