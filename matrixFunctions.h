/*
* Author: Bennett Kahn
* Date Began: 7/23/20
* Program Description: A simple matrix calculator that can perform all basic Linear Algebra functions
	* The purpose of this project is to gain some experience with C and GitHub
*/

#ifndef MATRIXFUNCTIONS_H_INCLUDED
#define MATRIXFUNCTIONS_H_INCLUDED

#include <stdbool.h>


/*
* Function: enterArray()
* ----------------------
* allows for user to enter array
* first prompts user to enter number of rows and columns of matrix
* then takes input of entries 1 by 1 starting from entry (1,1) and traversing right/down the matrix
*/
int **enterArray(int m, int n);

/*
* Function: matrixAddition()
* --------------------------
*
* arr1: 

double* matrixAddition(double *arr1, double *arr2);
*/

#endif