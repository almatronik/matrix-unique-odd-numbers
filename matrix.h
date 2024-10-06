#ifndef MATRIX_H
#define MATRIX_H

#include <stdio.h>

/**
 * @brief This function is used to get an integer from the user and return it to the caller.
 * 		  The input is validated and the buffer sanitized in case of invalid input.
 *
 * @param text The text "rows" or "cols" provided to seperate the two calls since the same function is used for both.
 *
 * @return int The rows or columns provided by the user.
 */
int get_integer(char *text);

/**
 * @brief This function is used for initialization of all values of the array to 0.
 *
 * @param R The number of rows.
 * @param C The number of columns.
 * @param matrix The 2 dimension array itself as a pointer with the number of columns appended to the pointer.
 *
 * return void
 */
void initialize_matrix(int R, int C, int (*matrix)[C]);

/**
 * @brief This function is used to fill the matrix with random values. The range of the random values is defined at the top.
 *
 * @param R The number of rows.
 * @param C The number of columns.
 * @param matrix The 2 dimension array itself as a pointer with the number of columns appended to the pointer.
 *
 * return void
 */
void populate_matrix(int R, int C, int (*matrix)[C]);

/**
 * @brief This function is used to print the matrix to the terminal.
 *
 * @param R The number of rows.
 * @param C The number of columns.
 * @param matrix The 2 dimension array itself as a pointer with the number of columns appended to the pointer.
 * @param text The text to be printed as a title.
 *
 * return void
 */
void print_matrix(int R, int C, int (*matrix)[C], char *text);

/**
 * @brief This function is used to count the odd numbers present in the matrix.
 *
 * @param R The number of rows.
 * @param C The number of columns.
 * @param matrix The 2 dimension array itself as a pointer with the number of columns appended to the pointer.
 *
 * return int The total count of dublicates
 */
int count_odd_num(int R, int C, int (*matrix)[C]);

/**
 * @brief This function is used to print a 1 dimension array to the terminal.
 *
 * @param len The length of the array.
 * @param array1d The 1 dimension array itself as a pointer
 * @param text The text to be printed as a title.
 *
 * return void
 */
void print_array1d(int len, int *array1d, char *text);

/**
 * @brief This function is used for initialization of all values of the array to 0.
 *
 * @param len The length of the array.
 * @param array1d The 1 dimension array itself as a pointer
 *
 * return void
 */
void initialize_array1d(int len, int *array1d);

/**
 * @brief This function is used for tranfering the odd numbers to a new array with length the dublicate count.
 *
 * @param R The number of rows.
 * @param C The number of columns.
 * @param matrix The 2 dimension array itself as a pointer with the number of columns appended to the pointer.
 * @param array1d The 1 dimension array that will hold the dedublicated odd numbers passed as a pointer.
 *
 * return void
 */
void tranfer_odd_num(int R, int C, int (*matrix)[C], int *array1d);

/**
 * @brief This function is used for checking the odd array for dublicates and setting them to -1.
 *
 * @param len The length of the odd_array.
 * @param array1d The 1 dimension array itself as a pointer
 *
 * return void
 */
int check_dublicates(int len, int *array1d);

/**
 * @brief This function is used for tranfering all the unique odd number to a new array. Values of -1 are skipped.
 *
 * @param len1 The length of the odd_array before removing the dublicates passed as a pointer.
 * @param array1 The array of odd numbers before the dublication.
 * @param len2 The length of the odd_array after removing the dublicates.
 * @param array2 The array of odd number after the dedublication passed as a pointer.
 *
 * return void
 */
void tranfer_odd_to_unique(int len1, int *array1, int len2, int *array2);

/**
 * @brief This function is used for calculating the average of each row and feeding it to the average array.
 *
 * @param R The number of rows.
 * @param C The number of columns.
 * @param matrix The 2 dimension array itself as a pointer with the number of columns appended to the pointer.
 * @param average_array The 1 dimension array that will hold the average per row passed as a pointer.
 *
 * return void
 */
void average_calc(int R, int C, int (*matrix)[C], int *average_array);

/**
 * @brief This function is used for printing the average array to the terminal. A seperate function is needed due to the unique prints.
 *
 * @param len The length of the array.
 * @param array1d The array that holds the average per row is passed by reference.
 * @param text The title to be printed on the top of the array.
 *
 * return void
 */
void print_avg_array(int len, int *array1d, char *text);

#endif // MATRIX_H