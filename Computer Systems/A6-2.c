/*
 * Author: Declan McGranahan - mcgranad@bc.edu
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void init(int n, int *matrix) {
    for (int i = 0; i <n; ++i) {
        for (int j = 0; j < n; ++j) {
            *(matrix + i*n + j) = rand() % 10;
        }
    }
}

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


void multTrans(int n, int *mone, int *mtwo, int *result, int *transposed) {
    int i,j,k;
    int blocksize = 30;
    transpose(n, blocksize, transposed, mtwo);
    for( i = 0; i < n; ++i) {
	    for( j = 0; j < n; ++j) {
            result[i+j*n] = 0;
	        for( k = 0; k < n; ++k) {
		        result[i+j*n] += mone[i+k*n]*transposed[j+k*n]; {
                }
            }
        }
    }
}


void print(int n, int *matrix) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            printf("%d", matrix[i+j*n]);
        }
        putchar('\n');
    }
}

void verify(int n, int *transpose, int *original) {
    /* check correctness */
    for(int i = 0; i < n; i++ )
        for(int j = 0; j < n; j++ )
            if( transpose[j+i*n] != original[j+i*n] ) {
	            printf("Error!!!! at %d, %d Transpose Multiplication does not result in correct answer!!\n", i, j);
	            exit( -1 );
            }
    printf("\nTranspose Multiplication and Normal are the same");
}     

int main(void) {
    int nmax = 4;
    clock_t t;


    int *mone = (int *)malloc( nmax*nmax * sizeof(int));
    int *mtwo = (int *)malloc( nmax*nmax * sizeof(int));
    int *result_std = (int *)malloc( nmax*nmax * sizeof(int));
    int *transposed = (int *)malloc( nmax*nmax * sizeof(int));
    int *result_trans = (int *)malloc( nmax*nmax * sizeof(int));

    init(nmax, mone);
    init(nmax, mtwo);
    
        for (int k = 0; k < 7; ++k) {
        t = clock();
        multMat(nmax, mone, mtwo, result_std);
        //print(nmax, C);
        //putchar('\n');
        t = clock() - t;
        double time_taken = ((double)t)/CLOCKS_PER_SEC;
        printf("Mult_Standard() took %f seconds to execute \n", time_taken);

        t = clock();
        multTrans(nmax, mone, mtwo, result_trans, transposed);
        //print(nmax, C);
        t = clock() - t;
        time_taken = ((double)t)/CLOCKS_PER_SEC;
        printf("Mult_Transpose() took %f seconds to execute \n", time_taken);

        nmax = nmax << 2;
    }

    verify(nmax, result_trans, result_std);
    free(mone);
    free(mtwo);
    free(result_std);
    printf("\n\n");
    return 0;
}