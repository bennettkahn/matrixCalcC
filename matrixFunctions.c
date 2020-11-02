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



