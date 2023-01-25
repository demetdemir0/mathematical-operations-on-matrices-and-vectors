#include <stdio.h>

#include <math.h>

#include <stdlib.h>

#include <malloc.h>

#include "matrixLib.h"

void printVector(float * vec, int N) {
  //scans all elements of the vector
  int i;
  for (i = 0; i < N; i++) {
  	//prints i-th element
    printf("%f ", vec[i]);
  }

}
void printMatrix(float ** mat, int row, int col) {
  int i, j;
  //scans all elemetns by starting with the row
  for (i = 0; i < row; ++i) {
    for (j = 0; j < col; ++j) {
      printf("%f  ", mat[i][j]);
    }
    printf("\n");
  }
}
float * returnVector(int size) {
  //initiliaze a vector pointer, seedValue and i.
  float * vec;
  int seedValue;
  int i;
  //allocates memory multiply by size
  vec = (float * ) malloc(size * sizeof(float));
  // Check if the memory has been successfully allocated by malloc or not
  if (vec == NULL) {
    printf("Memory not allocated.\n");
    exit(0); //exit from the program
  } else {
  	//requires for seed value to user
    printf("Enter the seed value = ");
    //takes seedValue from user 
    scanf("%d", & seedValue);
    srand(seedValue);
    //creates random variables starting from seedValue
    for (i = 0; i < size; ++i) {
      vec[i] = rand() % 10 + seedValue;

    }
  }	
  return vec;
  //frees the memory;
  free(vec);
}

float ** returnMatrix(int row, int col) {
  float ** matrix;
  int i, j, seedValue;
  //allocates memory multiply by row for matrix
  matrix = (float ** ) malloc(sizeof(float * ) * row);
  //allocates memory for each row (col times)
  for (i = 0; i < row; i++)
    matrix[i] = (float * ) malloc(sizeof(float) * col);
  //takes seed value from user
  printf("Enter the seed value = ");
  scanf("%d", & seedValue);
  srand(seedValue);
  //creates random variables for matrix[i][j] starting from seedValue
  for (i = 0; i < row; ++i) {
    for (j = 0; j < col; ++j) {
      matrix[i][j] = (rand() % 10) + seedValue;
    }
  }
  return matrix;
  free(matrix);
}

void freeMatrix(float ** mat, int row) {
  //traverses all elements in the matrix
  int i, j;
  for (i = 0; i < row; i++)
  //frees the row by row
    free(mat[i]);
  //makes empty matrix allocation
  free(mat);
}
float mean(float * vec, int size) {
  int i;
  //initiallize sum (=0) of vector and average(=sum/size)
  float sum_of_vec = 0, avg = 0;
  //traverse array and add value of them into the sum_of_vec
  for (i = 0; i < size; i++)
    sum_of_vec = sum_of_vec + * (vec + i);
  //calculate the average = mean of the vector
  return avg = sum_of_vec / size;
  // printf("\nMean of array is: %f",avg);

}
float correlation(float * vec, float * vec2, int size) {

  float sum_vec = 0, sum_vec2 = 0, sum_vectors = 0;
  float squareSum_vec = 0, squareSum_vec2 = 0;
  int i;
  for (i = 0; i < size; i++) {
    // sum of elements of array X.
    sum_vec = sum_vec + * (vec + i);

    // sum of elements of array Y.
    sum_vec2 = sum_vec2 + * (vec2 + i);

    // sum of X[i] * Y[i].
    sum_vectors = sum_vectors + ( * (vec + i)) * ( * (vec2 + i));

    // sum of square of array elements.
    squareSum_vec = squareSum_vec + ( * (vec + i)) * ( * (vec + i));
    squareSum_vec2 = squareSum_vec2 + ( * (vec2 + i)) * ( * (vec2 + i));
  }

  // use formula for calculating correlation.
  float corr = (size * sum_vectors - sum_vec * sum_vec2) /
    sqrt((size * squareSum_vec - sum_vec * sum_vec) *
      (size * squareSum_vec2 - sum_vec2 * sum_vec2));
  printf("%f", corr);
  // return corr;
}

float covariance(float * vec1, float * vec2, int size) {
  float sum = 0;
  //for vec1, calculate its mean
  float mean_vec1 = mean(vec1, size);
  //for vec2, calculate its mean
  float mean_vec2 = mean(vec2, size);
  int i;
  for (i = 0; i < size; i++)
    //applies covariance formula
    sum = sum + (vec1[i] - mean_vec1) * (vec2[i] - mean_vec2);
  return sum / (size - 1);
  //returns covariance of them.
}

float ** matrixMultiplication(float ** mat1, float ** mat2, int row1, int col1, int row2, int col2) {
  //controls for multiplication rule
  if (col1 != row2) {
    printf("ERROR! Column of matrix1 must be equal to row of matrix2.");
  }
  //creates a matrix to hold multiplication of matrices
  float ** mul;
  mul = (float ** ) malloc(sizeof(float) * row1);
  //applies formula
  int i, j, k;
  for (i = 0; i < row1; i++) {
    for (j = 0; j < col2; j++) {
      mul[i][j] = 0;
      for (k = 0; k < row2; k++) {
        mul[i][j] += mat1[i][k] * mat2[k][j];
      }
    }
  }
  //returns mul
  return mul;
  free(mul);
}
float ** matrixTranspose(float ** mat, int row, int col) {
  int i, j;
  //memory allocation for transpose matrix
  float ** transpose = (float ** ) malloc(row * sizeof(float * ));
  for (i = 0; i < row; i++)
    transpose[i] = (float * ) malloc(col * sizeof(float));

   //apply formula
    for (i = 0; i < row; i++) {
     	printf("/n");
     	for (j = 0; j < col; j++) {
      		*( * (transpose + i) + j) = * ( * (mat + j) + i);
      		printf("%f ", transpose[i][j]);
    }
   		printf("/n");
  }

  return transpose;
  free(transpose);
}
float * rowMeans(float ** mat, int row, int col) {
  //allocate memory to hold a matrix 1x3 
  float * avg_of_rows = (float * ) malloc(col * sizeof(float));
  int i, j;
  float row_total = 0;
  //add row_total sum of i-th j variables
  for (i = 0; i < row; ++i) {
    for (j = 0; j < col; ++j) {
      row_total += mat[i][j];
    }
    //calculate its average
    avg_of_rows[j] = (row_total / col);
    printf("%f ", avg_of_rows[j]);
    //clear row_total to calculate next i-th row
    row_total = 0;
  }

  return avg_of_rows;
  free(avg_of_rows);
}
float * columnMeans(float ** mat, int row, int col) {
  //allocate memory to hold a matrix 3x1
  float * avg_of_cols = (float * ) malloc(row * sizeof(float));
  int i, j;
  float avg, col_total;
  //traverse row
  for (i = 0; i < row; i++) {
    col_total = 0; //clear value of col_total
    for (j = 0; j < col; j++) {
    	//add row_total sum of j-th i variables
    	col_total += mat[j][i];
    }
    //calculate average
    avg = col_total / row;
    printf(" %f \n", avg);
  }

  return 0;
  free(avg_of_cols);
}

float variance(float * vec1, float * vec2, int size) {
  float sum = 0;
  int i,j;
  // taking sum of all the elements in both arrays
  for (i = 0; i < size; i++) {
    sum += vec1[i];
    sum += vec2[i];
  }
  float mean = sum / (2 * size); // calculating mean

  // calculating variance
  float sum1 = 0;
  for (i = 0; i < size; i++) {
    sum1 = sum1 + pow((vec1[i] - mean), 2);
    sum1 = sum1 + pow((vec2[i] - mean), 2);
  }
  //return variance
  float variance = sum1 / (2 * size);

  return variance;
}
float ** covarianceMatrix(float ** mat, int row, int col) {
	int i,j;
  //create matrix for caculate mat covariance
  float **c = (float ** ) malloc(sizeof(float * ) * row);
  //allocates memory for each row (col times)
  for (i = 0; i < row; i++)
    c[i] = (float * ) malloc(sizeof(float) * col);

  //creates random variables for matrix[i][j] starting from seedValue
  for (i = 0; i < row; ++i) {
    for (j = 0; j < col; ++j) {
      c[i][j] =0;
    }
  
  //traverse the mat 
  for (i = 0; i < row; i++) {
    for (j = 0; j < col; j++) {
      //add c variance of each row and column
      c[i][j] = variance(mat[i], mat[j], row);
    }
  }

  return c;
  free(c);
}
}

float determinant(float ** mat, int row) {

  int i, j, k;
  float factor = 1, det = 0;
  float ** newm;
  if (mat == NULL) return -1;
  if (row == 1) return ** mat; //when matrix is a number, determinant is the number
  for (i = 0; i < row; i++) {
    if (NULL == (newm = (float ** ) malloc((row - 1) * sizeof(float)))) return -1;
    for (j = 0; j < row - 1; j++)
      if (NULL == (newm[j] = (float * ) malloc((row - 1) * sizeof(float)))) return -1;
    for (j = 1; j < row; j++) {
      //skip first row as we dont need it for the adjunt matrixes
      for (k = 0; k < row; k++) {
        if (k == i) continue; //skip same column
        newm[j - 1][k < i ? k : (k - 1)] = mat[j][k]; //asign the number to new matrix
      }
    }
    det += factor * mat[0][i] * determinant(newm, row - 1); //recursivity, determinant of the adjunt matrix
    factor *= -1;
    for (j = 0; j < row - 1; j++) free(newm[j]);
    free(newm);
  }
  return det;
}
