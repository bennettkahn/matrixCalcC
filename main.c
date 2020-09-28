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
	// we will initialize five pointer variables, allowing our program to store five matrices
	int* m1 = malloc(sizeof(*m1));
	int* m2 = malloc(sizeof(*m2));
	int *m3 = malloc(sizeof(*m3));
	int *m4 = malloc(sizeof(*m4));
	int *m5 = malloc(sizeof(*m5));
	printf("*m1: %d\n", *m1);
	printf("m1: %p\n", m1);
	printf("*m2: %d\n", *m2);
	printf("m2: %p\n", m2);
	

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
			// pointer to store array returned by enterArray()
			if (*m1 == 0) {
				m1 = enterArray(m, n);
			} else if (*m2 == 0) {
				m2 = enterArray(m, n);
			} else if (*m3 == 0) {
				m3 = enterArray(m, n);
			} else if (*m4 == 0) {
				m4 = enterArray(m, n);
			} else if (*m5 == 0) {
				m5 = enterArray(m, n);
			} else {
				// if somebody enters more than five arrays, all five originals are deleted
				// and we assign the entered array to m1
				*m1, *m2, *m3, *m4, *m5 = 0;
				m1 = enterArray(m, n);
			}
			
		}
	}
	return 0;
	
	
}