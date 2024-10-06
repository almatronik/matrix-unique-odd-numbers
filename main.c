/**
 * @file module.h
 * @author Alexander Markantonis (alexander.markantonis@ya.se)
 * @brief A program to make some operations on a variably declared matrix with the use of functions and the number of rows and columns entered by the user.
 *			1. A function to build and fill the matrix with random numbers in the range of 0 and 999.
 *			2. A function to print the matrix to the terminal.
 *			3. A function to find odd numbers in the matrix and put them in another array (odd_array).
 *			4. A function to print odd_array.
 *			5. A function to check  if odd_array has any duplicated numbers, remove the duplication and print the doublicate count to the terminal.
 *			6. A function to print the odd_number array after removing the dublicates.
 *			7. A function to calculate the average of every row in the matrix, feed it in avg_array and then print it to the terminal.
 *
 * @version 0.1
 * @date 2023-12-15
 *
 * @copyright None
 *
 */

#include <stdlib.h>
#include "matrix.h"

int main(void)
{
    int R = get_integer("rows");
    int C = get_integer("cols");
    printf("\n");

    int matrix[R][C];
    initialize_matrix(R, C, matrix);
    // print_matrix(R, C, matrix, " initialization");

    populate_matrix(R, C, matrix);
    print_matrix(R, C, matrix, "");

    int odd_counter = count_odd_num(R, C, matrix);
    // int odd_array[odd_counter];                                        //Commented out since I allocated memory dynamically but leaving it as a backup solution.
    int *odd_array = (int *)malloc(sizeof(int) * odd_counter);
    if (odd_array == NULL)
    {
        printf("Failed to allocate memory. Exiting...");
        exit(1);
    }
    initialize_array1d(odd_counter, odd_array);
    // print_array1d(odd_counter, odd_array, "Odd_array initialization");
    tranfer_odd_num(R, C, matrix, odd_array);
    print_array1d(odd_counter, odd_array, "Odd Numbers");

    int dbl_counter = check_dublicates(odd_counter, odd_array);
    printf("Total number of Dublications in Odd Numbers: %d\n\n", dbl_counter);
    // int unique_odd_num[odd_counter-dbl_counter];                              //Commented out since I allocated memory dynamically but leaving it as a backup solution.
    int *unique_odd_num = (int *)malloc(sizeof(int) * (odd_counter - dbl_counter));
    if (unique_odd_num == NULL)
    {
        printf("Failed to allocate memory. Exiting...");
        free(odd_array);
        exit(1);
    }
    initialize_array1d(odd_counter - dbl_counter, unique_odd_num);
    // print_array1d(odd_counter-dbl_counter, unique_odd_num, "Odd Numbers (After Removing Dublicates), initialization");
    tranfer_odd_to_unique(odd_counter, odd_array, odd_counter - dbl_counter, unique_odd_num);
    print_array1d(odd_counter - dbl_counter, unique_odd_num, "Odd Numbers (After Removing Dublicates)");

    // int avg_array1d[R];                               //Commented out since I allocated memory dynamically but leaving it as a backup solution.
    int *avg_array1d = (int *)malloc(sizeof(int) * R);
    if (avg_array1d == NULL)
    {
        printf("Failed to allocate memory. Exiting...");
        free(odd_array);
        free(unique_odd_num);
        exit(1);
    }
    initialize_array1d(R, avg_array1d);
    // print_array1d(R, avg_array1d, "Average array initialization");
    average_calc(R, C, matrix, avg_array1d);
    print_avg_array(R, avg_array1d, "Row averages");

    free(odd_array);
    free(unique_odd_num);
    free(avg_array1d);

    return 0;
}
