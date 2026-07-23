#include <iostream>
#include <vector>
#include <limits>
#include <bits/stdc++.h>

/**
 * @brief Finds the maximum and minimum values in a vector.
 *
 * Traverses the vector and updates the values pointed to by
 * max and min.
 *
 * @param vec Reference to the input vector.
 * @param max Pointer to store the maximum value.
 * @param min Pointer to store the minimum value.
 */
void get_max_min(std::vector<int> &vec, int *max, int*min);

/**
 * @brief Prints the maximum and minimum values.
 *
 * Displays the maximum and minimum values stored in the provided pointers.
 * If either pointer is nullptr, an error message is displayed.
 *
 * @param max Pointer to the maximum value.
 * @param min Pointer to the minimum value.
 */
void print_min_max(int *max, int*min);

/**
 * @brief Reverses a vector manually.
 *
 * Swaps the first and last elements repeatedly until the
 * vector is completely reversed.
 *
 * @param vec Reference to the vector.
 */
void revers_vector(std::vector<int> &vec);

/**
 * @brief Prints all elements of a vector.
 *
 * Displays each element separated by tabs.
 *
 * @param vec Reference to the vector.
 */
void print_vector(std::vector<int> &vec);

/**
 * @brief Searches for duplicate elements in a vector.
 *
 * The vector is sorted first, then adjacent elements are compared.
 * If a duplicate is found, its index is returned through the pointer.
 *
 * @note This function modifies the original vector because it sorts it.
 *
 * @param vec Reference to the vector.
 * @param index Pointer used to store the index of the duplicate element.
 */
void check_repetation(std::vector<int> &vec, int *index);