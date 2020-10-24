/*
* Author: Bennett Kahn
* Date Began: 7/23/20
* Program Description: A simple matrix calculator that can perform all basic Linear Algebra functions
	* The purpose of this project is to gain some experience with C and GitHub

* Compile with: gcc -o progg matrixFunctions.c main.c
* run with ./progg
*/

#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "matrixFunctions.h"

int main() {

	char choice = ' ';
	/* we will initialize five pointer variables, allowing our program to store five matrices
	* Note that a matrix is a two-dimensional array
	* here we are using a single pointer to STORE a two dimensional array
	*/
	int **m1;
	int **m2;
	int **m3;
	int **m4;
	int **m5;
	// we will use a 5x5 as our dummy values
	int len = sizeof(int *) * 5 + sizeof(int) * 5 * 5;
	m1 = (int **)malloc(len);
	m2 = (int **)malloc(len);
	m3 = (int **)malloc(len);
	m4 = (int **)malloc(len);
	m5 = (int **)malloc(len);

	printf("m1: %p\n", m1);
	printf("*m1: %p\n", *m1);
	
	int num_matrices = 0;
	while (choice != 'q') {
		printf("Please type the chracter corresponding to the operation you wish to perform\n");
		printf("MENU\n\n");
		printf("e - Enter New Matrix\n");
		printf("a - Matrix Addition\n");
		printf("s - Matrix Scalar Multiplication\n");
		printf("m - Matrix Multiplication\n");
		printf("t - Matrix Transpose\n");
		printf("d - Matrix Determinant\n");
		printf("r - Matrix RREF\n");
		printf("q - QUIT\n\n");
		// ALWAYS USE & FOR SCANF!!!!
		scanf(" %c", &choice);
		

		if (choice == 'e') {
			printf("num_matrices is: %d\n", num_matrices);
			// int to store number of rows in matrix
			int m;
			printf("Enter the number of rows in your matrix:\n");
			scanf("%d", &m);
			// int to store number of columns in matrix
			int n;
			printf("Enter the number of rows in your matrix:\n");
			scanf("%d", &n);
			// how much memory we need to allocate to each pointer
			//int len = sizeof(int *) * m + sizeof(int) * m * n;
			// pointer to store array returned by enterArray()
			len = sizeof(int *) * 5 + sizeof(int) * 5 * 5;
			if (num_matrices == 0) {
				m1 = (int **)realloc(m1, len);
				printf("In first block\n");
				m1 = enterArray(m, n);
				printf("**m1: %d\n", **m1);

        	// for some reaon *m2 == 0 causes a segmentation fault but *m1 == 0 does not
			} else if (num_matrices == 1) {
				m2 = (int **)realloc(m2, len);
				printf("In second block\n");
				m2 = enterArray(m, n);
			} else if (num_matrices == 2) {
				m3 = (int **)realloc(m3, len);
				printf("In third block\n");
				m3 = enterArray(m, n);
			} else if (num_matrices == 3) {
				m4 = (int **)realloc(m4, len);
				printf("In fourth block\n");
				m4 = enterArray(m, n);
			} else if (num_matrices == 4) {
				m5 = (int **)realloc(m5, len);
				printf("In fifth block\n");
				m5 = enterArray(m, n);
			} else {
				printf("In else block\n");
				// if somebody enters more than five arrays, all five originals are deleted

				// we have gone with the 'better' above approach of freeing all of the pointers instead of below
					//*m1, *m2, *m3, *m4, *m5 = 0;
				// and we assign the entered array to m1
				num_matrices = 0;
				m1 = (int **)realloc(m1, len);
				m1 = enterArray(m, n);
			}
			num_matrices++;
			
		}
	}
	return 0;
	
	
}