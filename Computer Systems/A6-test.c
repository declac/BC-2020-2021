/*
 * Author: Declan McGranahan - mcgranad@bc.edu
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* 
 * Function takes two arguments, a pre-defined matrix and the number of rows/columns
 * Initializes the matrix by assignming a random number from 0-10
 */ 
void init(int n, int *matrix) {
    for (int i = 0; i <n; ++i) {
        for (int j = 0; j < n; ++j) {
            *(matrix + i*n + j) = rand() % 10;
        }
    }
}
/*
 * Function that takes in 4 arguments
 * Number of columns/rows, two matrices to multiply and one to store the result
 * Loops through the columns and rows of each matrix and multiplies
 */
void multMat(int n, int *mone, int *mtwo, int *result) {
    int i,j,k;
    for (i = 0; i < n; ++i) {
        for (j = 0; j < n; ++j) {
            result[i+j*n] = 0;
            for (k = 0; k < n; ++k) {
                result[i+j*n] += mone[i+k*n]*mtwo[k+j*n];
            }
        }
    }
}
/*
 * Function that takes in 4 arguments
 * Number of columns/rows, two matrices one to store transposed and one to transpose 
 * and one to set the block size of the transposition
 * Loops through the columns and rows of each matrix and switched columns and rows
 */
void transpose( int n, int blocksize, int *dst, int *src ) {
    int i,j;
    int k,m;
    for ( i = 0; i < n; i += blocksize ) {
	    for ( j = 0; j < n; j += blocksize ) {
	        for ( k = i; (k < i + blocksize) & (k < n) ; k++ ) {
		        for ( m = j; (m < j + blocksize) & (m < n); m++ ) {
		            dst[m+k*n] = src[k+m*n];
		        }
	        }
	    }
    }
}
/*
 * Function that takes in 4 arguments
 * Number of columns/rows, two matrices to multiply and one to store the result
 * Transposes one of the matrices and then
 * Loops through the columns and rows of each matrix and multiplies
 */
void multTrans(int n, int *mone, int *mtwo, int *result) {
    int i,j,k;
    for( i = 0; i < n; ++i) {
	    for( j = 0; j < n; ++j) {
            result[i+j*n] = 0;
	        for( k = 0; k < n; ++k) {
		        result[i+j*n] += mone[k+i*n]*mtwo[j+k*n]; {
                }
            }
        }
    }
}
/* 
 * Function takes two arguments, a pre-defined matrix and the number of rows/columns
 * Loops through the columns and rows printing them out
 */ 
void print(int n, int *matrix) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            printf("%d", matrix[i+j*n]);
        }
        putchar('\n');
    }
}
/* 
 * Function takes three arguments, two matrices to compare and the number of rows/columns
 * Loops through the columns and rows checking to see if they are the same or not
 */ 
void verify(int n, int *transpose, int *original) {
    /* check correctness */
    for(int i = 0; i < n; i++ )
        for(int j = 0; j < n; j++ )
            if( transpose[j+i*n] != original[j+i*n] ) {
	            printf("Error!!!! at %d, %d Transpose Multiplication does not result in correct answer!!\n", i, j);
	            exit( -1 );
            }
    printf("Transpose Multiplication and Normal are the same");
}  
/* 
 * Function takes one arguments, the number of rows/columns
 * Creates all the matrices and calls all of the functions to do multiplication
 */ 
void run(int n) {
    printf("Size of Matrix: %d: \n", n);
        clock_t t; //Initializes the clock to track time used on processes

        //Initializes the matircies and sets there sizes
        int *mone = (int *)malloc(n*n * sizeof(int));
        int *mtwo = (int *)malloc(n*n * sizeof(int));
        int *result_std = (int *)malloc(n*n * sizeof(int));
        int *transposed = (int *)malloc(n*n * sizeof(int));
        int *result_trans = (int *)malloc(n*n * sizeof(int));
        int *result_trans2 = (int *)malloc(n*n * sizeof(int));
        int *transposed2 = (int *)malloc(n*n * sizeof(int));

        //Fills the two inital matrices with random numbers
        init(n, mone);
        init(n, mtwo);

        //Starts theclock
        t = clock();
        //Runs the matrix multiplication
        multMat(n, mone, mtwo, result_std);
        t = clock() - t; //End the clock
        double time_taken = ((double)t)/CLOCKS_PER_SEC; //Calculates Time from start to end
        printf("Mult_Standard() took %f seconds to execute \n", time_taken); //Prints time

        int blocksize = 30;
        transpose(n, blocksize, transposed, mone);
        transpose(n, blocksize, transposed2, mtwo);
        t = clock(); //Starts theclock
         //Runs the matrix multiplication with transpotation
        multTrans(n, transposed, transposed2, result_trans);
        t = clock() - t; //End the clock
        time_taken = ((double)t)/CLOCKS_PER_SEC; //Calculates Time from start to end
        printf("Mult_Transpose() took %f seconds to execute \n", time_taken); //Prints time
        transpose(n, blocksize, result_trans2, result_trans);
        
        
        print(n, result_std);
        putchar('\n');
        print(n, result_trans);
        putchar('\n');
        print(n, result_trans2);
        putchar('\n');
        
        verify(n, result_trans2, result_std); // Verifies the multiplication is correct
        //Frees the memory of the matrices
        free(mone);
        free(mtwo);
        free(result_std);
        free(transposed);
        free(result_trans);
        printf("\n\n");
}  

// Main function to call all functions and check time
int main(void) {
    int nmax = 4; //Sets the original # of rows and columns
    //Loops through all of the different iterations
    for (int k = 0; k < 9; ++k) {
        run(nmax);
        nmax = nmax << 2; //Powers the columns/rows by 2
    }

    return 0;
}