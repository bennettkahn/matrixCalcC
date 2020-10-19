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
	printf("m1: %p\n", m1);
	printf("*m1: %d\n", *m1);
	/*
	printf("*m1: %d\n", **m1);
	printf("m1: %p\n", m1);
	
	printf("*m2: %d\n", *m3);
	printf("m2: %p\n", m3);
	*/
	
	

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
			// int to store number of rows in matrix
			int m;
			printf("Enter the number of rows in your matrix:\n");
			scanf("%d", &m);
			// int to store number of columns in matrix
			int n;
			printf("Enter the number of rows in your matrix:\n");
			scanf("%d", &n);
			// how much memory we need to allocate to each pointer
			int len = sizeof(int *) * m + sizeof(int) * m * n;
			//printf("*m1: %d\n", **m1);
			printf("m1: %p\n", m1);

			// pointer to store array returned by enterArray()
			if (*m1 == 0) {
				m1 = (int **)malloc(len);
				printf("In first block");
				m1 = enterArray(m, n);
				for(int k = 0; k < m; k++) {
       	 			for(int l = 0; l < n; l++) {
            			printf("%3d ", m1[k][l] );
        			}
        			printf("\n");
        		}

			} else if (*m2 == 0) {
				m2 = (int **)malloc(len);
				printf("In second block");
				m2 = enterArray(m, n);
			} else if (*m3 == 0) {
				printf("In third block");
				m3 = enterArray(m, n);
			} else if (*m4 == 0) {
				m4 = enterArray(m, n);
			} else if (*m5 == 0) {
				m5 = enterArray(m, n);
			} else {
				printf("In else block");
				// if somebody enters more than five arrays, all five originals are deleted
					// i.e. we free the memory we originally allocated
				// and we assign the entered array to m1
				free(m1);
				free(m2);
				free(m3);
				free(m4);
				free(m5);

				// we have gone with the 'better' above approach of freeing all of the pointers instead of below
					//*m1, *m2, *m3, *m4, *m5 = 0;
				m1 = enterArray(m, n);
			}
			
		}
	}
	return 0;
	
	
}