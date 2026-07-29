/**
 * @file Main.hpp
 * @brief Function declarations for the Student Grade Calculator.
 *
 * This header declares the functions required to input student marks,
 * calculate the average score, determine the corresponding letter grade,
 * generate a student report, and handle invalid user input.
 *
 * Features:
 * - Input marks for three subjects
 * - Calculate the average mark
 * - Determine the letter grade
 * - Display a student report
 * - Validate user input
 *
 * @author Sara Saad
 * @version 1.0
 * @date 2026-07-13
 */

#ifndef _MAIN_HH_
#define _MAIN_HH_

/*================================= include Libraries ==================================*/
#include <iostream>
#include <limits>
#include <string>

/**
 * @brief Reads the student's marks for all subjects.
 *
 * Prompts the user to enter marks for Mathematics, Physics,
 * and English.
 *
 * @param math Pointer to the Mathematics mark.
 * @param physics Pointer to the Physics mark.
 * @param english Pointer to the English mark.
 */
void inputMarks(int *math, int *physics, int *english);

/**
 * @brief Calculates the average of the student's marks.
 *
 * Computes the arithmetic mean of the three subject marks.
 *
 * @param math Pointer to the Mathematics mark.
 * @param physics Pointer to the Physics mark.
 * @param english Pointer to the English mark.
 *
 * @return double The average mark.
 */
double calculateAverage(int *math, int *physics, int *english);

/**
 * @brief Determines the student's letter grade.
 *
 * Assigns a letter grade based on the calculated average.
 *
 * @param average The student's average mark.
 *
 * @return char The corresponding letter grade.
 */
char calculateGrade(double average);

/**
 * @brief Displays the student's report.
 *
 * Prints the student's name, marks for each subject,
 * average score, and letter grade.
 *
 * @param name Student's name.
 * @param math Pointer to the Mathematics mark.
 * @param physics Pointer to the Physics mark.
 * @param english Pointer to the English mark.
 */
void printReport(std::string name, int *math, int *physics, int *english);

/**
 * @brief Clears the input stream error state.
 *
 * Resets the error flags of `std::cin` and removes any
 * remaining invalid characters from the input buffer.
 */
void clearError();

# endif /* _MAIN_HH_ */