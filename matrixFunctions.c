/*
* Author: Bennett Kahn
* Date Began: 7/23/20
* Program Description: A simple matrix calculator that can perform all basic Linear Algebra functions
	* The purpose of this project is to gain some experience with C and GitHub
*/


#include "matrixFunctions.h"


#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>


void destroy2DArray(int **arr, int r, int c) {
	// free memory at each row
	for (int i = 0; i < r; i++) {
		free(arr[i]);
	}
	// free whole pointer variable
	free(arr);
}

void displaySubMenu() {
	char choice1 = ' ';
    	printf("Press \'m\' to return to main menu\n");
    	while (choice1 != 'm') {
    		scanf(" %c", &choice1);
    		;
    	}
}

// FOR SOME REASON WHEN M = 3 AND N = 2, I GET A SEG FAULT!?
int** enterArray(int m, int n) {
	int **matrix = (int **)malloc(sizeof(int*) * n);
	for (int j = 0; j < m; j++) {
		// each element is a pointer (int *) to an array of n ints
        matrix[j] = (int *)malloc(n * sizeof(int)); 
      }

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			printf("Enter entry (row %d, col %d): ", i + 1, j + 1);
			scanf("%d", &matrix[i][j]);
		}
	}

	for(int k = 0; k < m; k++) {
        for(int l = 0; l < n; l++) {
            printf("%3d ", matrix[k][l] );
        }
        printf("\n");
    }
	return matrix;
}

void displayMatrix(int **matrix, int m, int n) {
	for(int k = 0; k < m; k++) {
        for(int l = 0; l < n; l++) {
            printf("%3d ", matrix[k][l] );
        }
        printf("\n");
    }
    printf("\n\n");
}

int** matrixAddition(int **a, int rows_a, int cols_a, int **b, int rows_b, int cols_b) {
	if ((rows_a != rows_b) || (cols_a != cols_b)) {
		printf("Matrix dimensions do not match, so the two matrices cannot be added.\n");
		return 0;
	}
	int **matrix = (int **)malloc(sizeof(int*) * rows_a);
	for (int j = 0; j < rows_a; j++) {
         matrix[j] = (int *)malloc(cols_a * sizeof(int));
     }

    for (int i = 0; i < rows_a; i++) {
    	for (int j = 0; j < cols_a; j++) {
    		matrix[i][j] = a[i][j] + b[i][j];
    	}
    }

    return matrix;
}

int** matrixScalarMult(int **a, int r, int c, int x) {
    int **matrix = (int **)malloc(sizeof(int*) * r);
    for (int j = 0; j < r; j++) {
        matrix[j] = (int *)malloc(c * sizeof(int));
    }

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
           matrix[i][j] = x * a[i][j];
        }
    }

    return matrix;
}


// WHY IS THIS FUNCTION GOING INTO AN INFINITE LOOP
int** matrixMult(int **a, int rows_a, int cols_a, int **b, int rows_b, int cols_b) {
    if (cols_a != rows_b) {
        printf("These two matrices cannot be multiplied together. \n");
        return 0;
    }
    // our product matrix has dimensions rows_a * cols_b
    // we create space for a matrix of those dimensions
    int **matrix = (int **)malloc(sizeof(int*) * rows_a);
    for (int j = 0; j < rows_a; j++) {
        matrix[j] = (int *)malloc(cols_b * sizeof(int));
    }

    // int to store dot product at each step
    int dot_product;
    // we need to loop over rows of matrix a and get the dot product of row i of a and col i of b
    for (int i = 0; i < rows_a; i++) {

    	for (int j = 0; j < cols_b; j++) {
 
    		dot_product = 0;
	        for (int k = 0; k < rows_b; k++) {
	        	// get product of entry (i, j) of a and (j, i), add to dot product
	        	dot_product += a[i][k] * b[k][j];
	        }
	        matrix[i][j] = dot_product;
	    }

    }

    return matrix;
}



