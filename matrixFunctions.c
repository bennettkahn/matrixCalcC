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


int** enterArray(int m, int n) {
	int **matrix;
	matrix = malloc(sizeof(int*) * n);
	for (int j = 0; j < m; j++) 
         matrix[j] = (int *)malloc(n * sizeof(int)); 

	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			printf("Enter entry (row %d, col %d): ", i + 1, j + 1);
			scanf("%d", &matrix[i][j]);
		}
	}

	for(int k = 0; k < m; k++)
    {
        for(int l = 0; l < n; l++)
        {
            printf("%3d ", matrix[k][l] );
        }
        printf("\n");
    }
	return matrix;
}
/*
double* matrixAddition(double *arr1, double *arr2) {
	static 
}
*/


