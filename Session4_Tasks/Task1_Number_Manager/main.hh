/**
 * @file Main.hpp
 * @brief Function declarations for basic integer manipulation operations.
 *
 * This header provides utility functions to manipulate an integer value
 * through a pointer. It also contains a helper function for clearing
 * input stream errors.
 *
 * Available operations:
 * - Increment a number
 * - Decrement a number
 * - Reset a number to zero
 * - Print the current value
 * - Clear input stream errors
 *
 * @author Sara Saad
 * @version 1.0
 * @date 2026-07-13
 */

#ifndef MAIN_HH_
#define MAIN_HH_

#include <iostream>
#include <limits>

/**
 * @brief Clears the input stream error state.
 *
 * Resets the error flags of `std::cin` and discards any invalid
 * characters remaining in the input buffer.
 */
void clearError();

/**
 * @brief Increments the given integer by one.
 *
 * @param num Pointer to the integer to increment.
 */
void increment(int *num);

/**
 * @brief Decrements the given integer by one.
 *
 * @param num Pointer to the integer to decrement.
 */
void decrement(int *num);

/**
 * @brief Resets the given integer to zero.
 *
 * @param num Pointer to the integer to reset.
 */
void reset(int *num);

/**
 * @brief Prints the current value of the integer.
 *
 * @param num Pointer to the integer to display.
 */
void printNumber(int *num);

#endif /* MAIN_HH_*/