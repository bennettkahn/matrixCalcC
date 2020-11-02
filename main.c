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
	/* we will initialize five double pointer variables, allowing our program to store five matrices
	* Note that a matrix is a two-dimensional array
	* here we are using a double pointer to STORE a two dimensional array
	*/
	int **m1;
	int **m2;
	int **m3;
	int **m4;
	int **m5;
	// we use malloc now on the double pointers with dummy dimensions so that we can use these same pointers later
	// for matrices of different length, allocation space with realloc
	// we will use a 5x5 as our dummy values
	int len = sizeof(int *) * 5 + sizeof(int) * 5 * 5;
	m1 = (int **)malloc(len);
	m2 = (int **)malloc(len);
	m3 = (int **)malloc(len);
	m4 = (int **)malloc(len);
	m5 = (int **)malloc(len);
	// this is our main array
	// it will store all five of our matrices throughout the program so that a user can easily
	// select which matrices they want to use for a certain operation
	// main is essentially acting as a 3-dimensional array
	// consider adding memory allocation to a function
	// do I even need all of my double pointers now???

	// in this line, the 5 is for storing 5 matrices
	// allocate enough memory to store FIVE int** AKA FIVE matrices
	int ***main = malloc(5 * sizeof(int**));
	int y, z;
	for (y = 0; y < 5; y++) {
		// 5 is a dummy value here
		main[y] = malloc(5 * sizeof(int*));
		for (z = 0; z < 5; z++) {
			// 5 is a dummy value here
			main[y][z] = malloc(5 * sizeof(int));
		}
	}
	// we need to dynamically allocate memory

	printf("m1: %p\n", m1);
	printf("*m1: %p\n", *m1);
	
	int num_matrices = 0;
	// an array of 10 ints to store the dimensions of the maximum five matrices we can have stored in memory
	// we will want to have the dimensions on hand later on so that we can perform matrix operations
	int dimensions[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

	// one double array to STORE the matrix that results from our computations
	int **result;
	while (choice != 'q') {
		printf("Main: \n");
		for (int a = 0; a < 5; a++) {
			for (int b = 0; b < dimensions[2 * a]; b++) {
				for (int c = 0; c < dimensions[2 * a + 1]; c++) {
					printf("%3d", main[a][b][c]);
				}
				printf("\n");
			}
			printf("\n\n");

		}
		// display all the available matrices the user has to pick from
		printf("Matrix 1 is: \n");
		displayMatrix(m1, dimensions[0], dimensions[1]);
		printf("Matrix 2 is: \n");
		displayMatrix(m2, dimensions[2], dimensions[3]);
		printf("Matrix 3 is: \n");
		displayMatrix(m3, dimensions[4], dimensions[5]);
		printf("Matrix 4 is: \n");
		displayMatrix(m4, dimensions[6], dimensions[7]);
		printf("Matrix 5 is: \n");
		displayMatrix(m5, dimensions[8], dimensions[9]);
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
			printf("Enter the number of columns in your matrix:\n");
			scanf("%d", &n);
			printf("Number of rows: %d\n", m);
			printf("Number of columns: %d\n", n);
			// how much memory we need to allocate to each pointer
			//int len = sizeof(int *) * m + sizeof(int) * m * n;
			// pointer to store array returned by enterArray()
			len = sizeof(int *) * m + sizeof(int) * m * n;
			//main[num_matrices] = (int **)realloc(main[num_matrices], len);
			if (num_matrices == 0) {
				m1 = (int **)realloc(m1, len);
				printf("In first block\n");
				m1 = enterArray(m, n);
				main[num_matrices] = m1;
        	// for some reaon *m2 == 0 causes a segmentation fault but *m1 == 0 does not
			} else if (num_matrices == 1) {
				m2 = (int **)realloc(m2, len);
				printf("In second block\n");
				m2 = enterArray(m, n);
				main[num_matrices] = m2;
			} else if (num_matrices == 2) {
				m3 = (int **)realloc(m3, len);
				printf("In third block\n");
				m3 = enterArray(m, n);
				main[num_matrices] = m3;
			} else if (num_matrices == 3) {
				m4 = (int **)realloc(m4, len);
				printf("In fourth block\n");
				m4 = enterArray(m, n);
				main[num_matrices] = m4;
			} else if (num_matrices == 4) {
				m5 = (int **)realloc(m5, len);
				printf("In fifth block\n");
				m5 = enterArray(m, n);
				main[num_matrices] = m5;
			} else {
				printf("In else block\n");
				// if somebody enters more than five arrays, all five originals are deleted

				// we have gone with the 'better' above approach of freeing all of the pointers instead of below
					//*m1, *m2, *m3, *m4, *m5 = 0;
				// and we assign the entered array to m1
				num_matrices = 0;
				m1 = (int **)realloc(m1, len);
				m1 = enterArray(m, n);
				main[num_matrices] = m1;
			}
			// add number of rows of matrix to list
			dimensions[2 * num_matrices] = m;
			// add number of columns of matrix to list
			dimensions[2 * num_matrices + 1] = n;
			num_matrices++;
			
		}
		if (choice == 'a') {
			printf("Please enter which two matrices you would like to add, \nseparated by a comma and a space (ex: 1, 3): ");
			int mat1, mat2;
			scanf("%d, %d", &mat1, &mat2);
			// ints to store the dimensions of the two matrices we are adding
			int r1, c1, r2, c2;
			r1 = dimensions[(2 * mat1) - 2];
			c1 = dimensions[(2 * mat1) - 1];
			r2 = dimensions[(2 * mat2) - 2];
			c2 = dimensions[(2 * mat2) - 1];

			result = matrixAddition(main[mat1 - 1], r1, c1, main[mat2 - 1], r2, c2);
			if (result != 0) {
				printf("Your resulting matrix is: \n");
				displayMatrix(result, r1, c1);
			}
			
    		//free the memory of the temporary matrix we created to get the sum
    		for(int i = 0; i < r1; i++) {
        		free(result[i]);
    		}
    		free(result);
    		char choice1 = ' ';
    		printf("Press \'m\' to return to main menu\n");
    		while (choice1 != 'm') {
    			scanf(" %c", &choice1);
    			;
    		}
		}

		if (choice == 's') {
			printf("Please enter your constant and your matrix \n(ex: 4*3 for '4 times matrix 3): ");
			// x is the constant we are multiplying by, mat1 is the matrix
			int x, mat1;
			scanf("%d * %d", &x, &mat1);
			int r1, c1;
			r1 = dimensions[(2 * mat1) - 2];
			c1 = dimensions[(2 * mat1) - 1];
			result = matrixScalarMult(main[mat1 - 1], r1, c1, x);
			displayMatrix(result, r1, c1);

			// CONSIDER PUTTING BOTH THE MATRIX FREEING AND the MENU PART INTO A FUNCTION!!!

			//free the memory of the temporary matrix we created to get the sum
    		for(int i = 0; i < r1; i++) {
        		free(result[i]);
    		}
    		free(result);
    		char choice1 = ' ';
    		printf("Press \'m\' to return to main menu\n");
    		while (choice1 != 'm') {
    			scanf(" %c", &choice1);
    			;
    		}

		}
	}
	return 0;
	
	
}