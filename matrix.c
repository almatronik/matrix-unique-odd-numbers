#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "matrix.h"

#define min 0
#define max 1000

// A function to print the average per row to the terminal.
void print_avg_array(int len, int *array1d, char *text)
{
    printf("%s:\n", text);
    for (int i = 0; i < len; i++)
    {
        printf("Row %d Average: %d\n", i + 1, *(array1d + i));
    }
    printf("\n\n");
}

// A function to calculate the average per row and feed it to the average array.
void average_calc(int R, int C, int (*matrix)[C], int *avg_array)
{
    for (int i = 0, k = 0; i < R; i++)
    {
        int avg = 0;
        for (int j = 0; j < C; j++)
        {
            avg += *(*(matrix + i) + j);
        }
        avg /= (float)C;
        *(avg_array + k++) = avg;
    }
}

// A function to tranfer the odd number to a new dedublicated array.
void tranfer_odd_to_unique(int len1, int *array1, int len2, int *array2)
{
    for (int i = 0, k = 0; i < len1; i++)
    {
        if (*(array1 + i) != -1)
        {
            if (k > len2)
            {
                printf("OUT OF BOUNDS!!!\n"); // Boundaries check.
                exit(1);                      // Exit in case of out of bounds.
            }
            else
            {
                *(array2 + k++) = *(array1 + i); // k is incremented indipendendly from the source array only if the value is not -1
            }
        }
    }
}

// A function to check for dublicates
int check_dublicates(int len, int *array1d)
{
    int dbl_count = 0;
    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j < len - i; j++)
        {
            if ((*(array1d + i) == *(array1d + j)) && (i != j) && *(array1d + i) != -1)
            {
                printf("odd_array[%d] = odd_array[%d] = %d\nSetting the second element to -1.\n", i, j, *(array1d + i));
                *(array1d + j) = -1;
                dbl_count++;
            }
        }
    }
    printf("\n");
    return dbl_count;
}

// A function to tranfer the odd number of the matrix to the odd_array.
void tranfer_odd_num(int R, int C, int (*matrix)[C], int *array1d)
{
    for (int i = 0, k = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            if (*(*(matrix + i) + j) % 2 == 1)
            {
                *(array1d + k++) = *(*(matrix + i) + j);
            }
        }
    }
}

// A generic function to initialise every 1d array. Not needed here since we assign values directly but a good practice nevertheless.
void initialize_array1d(int len, int *array1d)
{
    for (int i = 0; i < len; i++)
    {
        *(array1d + i) = 0;
    }
}

// A generic function to print the elements of a 1d array with the title passed during the call.
void print_array1d(int len, int *array1d, char *text)
{
    printf("%s:\n", text);
    for (int i = 0; i < len; i++)
    {
        printf("%d ", *(array1d + i));
    }
    printf("\n\n");
}

// A function to count the number of odd numbers in the matrix and return the total for later use.
int count_odd_num(int R, int C, int (*matrix)[C])
{
    int count = 0;
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            if (*(*(matrix + i) + j) % 2 == 1)
            {
                count++;
            }
        }
    }
    return count;
}

// A generic function to print any 2d array to the terminal with a title passed partially during the call.
void print_matrix(int R, int C, int (*matrix)[C], char *text)
{
    printf("Matrix%s:\n", text);
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            printf("%d\t", *(*(matrix + i) + j));
        }
        printf("\n");
    }
    printf("\n\n");
}

// A function to populate the array with random numbers. The srand function is used to feed the rand algorithm with the current time.
void populate_matrix(int R, int C, int (*matrix)[C])
{
    srand(time(NULL));
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            *(*(matrix + i) + j) = min + rand() % (max - min);
        }
    }
}

// A generic function to initialise the values of the matrix to zero. Technically not needed here but good practice nevertheless.
void initialize_matrix(int R, int C, int (*matrix)[C])
{
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            *(*(matrix + i) + j) = 0;
        }
    }
}

// A function to get an integer from the user and return it to the caller. In case of invalid input the buffer is sanitized and the user has to repeat the process.
int get_integer(char *text)
{
    int tmp = 0;
    do
    {
        printf("Enter the number of %s: ", text);
        if (1 == (scanf("%d", &tmp)))
        {
            ;
        }
        else
        {
            char c;
            while ((c = getchar()) && c != '\n' && c != EOF)
                ;
            {
                ;
            }
        }
    } while (tmp <= 0 && printf("The number must be positive and > 0\n"));
    return tmp;
}
