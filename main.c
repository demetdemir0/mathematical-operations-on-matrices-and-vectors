#include <stdio.h>

#include <stdlib.h>

#include "matrixLib.h"


int main() {  
    int col = 3, row = 3, size = 4;
    float * vec, * vec2;
    float  ** matrix2, ** mult_matrix, ** matrix;

    //prints which function is running.
    printf("CREATING 2 VECTORS:\n");
    //generates a vector has size (= 4)
    vec = returnVector(size);
    vec2 = returnVector(size);
    // Get the elements of the array.
    printVector(vec, size);
    printf("\n");
    printVector(vec2, size);



    printf("\nCREATING 2 MATRICES:\n");
    //generates a matrix (row=3,col=3)
    matrix = returnMatrix(row, col);
    matrix2 = returnMatrix(row, col);
    //prints matrix elements.
    printMatrix(matrix, row, col);
    printf("\n");
    printMatrix(matrix2, row, col);
  
    printf("\n");
  
    float m = mean(vec, size);
    printf("\nMEAN of the VECTOR1: %f", m);
   
    printf("\n");
 
    printf("\nCORRELATION of 2 VECTORS: ");
    correlation(vec, vec2, size);
    
    printf("\n");
    
    float cov = covariance(vec, vec2, size);
    printf("\nCOVARIANCE of 2 VECTORS: %f ", cov);
    
    
    printf("\n");
    
    printf("\nRow means:\n");
    rowMeans(matrix, row, col);
    

    printf("\n");
    
    printf("\nColumn means:\n");
    columnMeans(matrix, row, col);
   
   
    printf("\n");
   
    printf("\nCOVARIANCE of the MATRIX1:\n");
    float **mat = covarianceMatrix(matrix, row, col);
   	printMatrix(mat, row, col);
    
    printf("\n");
    
    printf("\nDETERMINANT of MATRIX1:\n");
    float a = determinant(matrix, row);
    printf("%f ", a);
    
    printf("\n");
    
    
    printf("\nTRANSPOSE of MATRIX1\n");
    matrixTranspose(matrix, row, col);
    
    
    
    printf("\n");
   
    printf("\nMATRIX IS FREED:\n");
    freeMatrix(matrix, row);
      
      
    printf("\n");
    
    printf("\nMULTIPLICATION of 2 MATRICES:\n");
    
    mult_matrix = matrixMultiplication(matrix, matrix2, row, col, row, col);
    printMatrix(mult_matrix, row, col);
   
 

}
