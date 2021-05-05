/* 
 * Authors: Francis Selldorff: selldorf@bc.edu and Declan Mcgranahan: mcgranad@bc.edu 
*/ 
// necessary include statements 
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <time.h> 
#include <unistd.h>
// gloabl declaration for DIM size (hard coded to 1024)
#define DIM 1024

// void init initializes the matrix with values of 0-99
void init(int n, int * matrix) {
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            matrix[i * n + j] = rand() % 100;
        }
    }
}
// multiply out the two matrices (carry out both serial and parallel multiplications) 
void multiply(int dim, int * a, int * b, char * filename, int p_num) {
    FILE *fptr;
    if((fptr = fopen(filename, "wb")) == NULL) {
        printf("File opening error on %s.\n", filename);
        exit(1);
    }
    int row_start, row_end, i, j, k;
    if (p_num == -1) {
        row_start = 0;
        row_end = dim;
    }
    else {
        row_start = (dim / 4 * p_num);
        row_end = (dim / 4 * (p_num + 1));
    }
    for (i = row_start; i < row_end; i++) {
        for (j = 0; j < dim; j++) {
            int x = 0;
            for (k = 0; k < dim; k++) {
                x += a[i * dim + k] * b[k * dim + j];
            }
            fwrite(&x, sizeof(int), 1, fptr);
        }
    }
    fclose(fptr);
}
// void read_array reads in a portion of the array for the parallel computation
void read_array(char * filename, int dim, int * array, int p_num) {
    FILE * fp = fopen(filename, "rb");
    if (p_num == -1) {
        fread(array, sizeof(int), dim * dim, fp);
    } 
    else {
        fread(array + p_num * dim * dim / 4, sizeof(int), dim * dim / 4, fp);
    }
    fclose(fp);
}
// void read_full_array reads in the full array for the serial computation  
void read_full_array(char * filename, int dim, int * array) {
    FILE * fp = fopen(filename, "rb");
    fread(array, sizeof(int), dim * dim, fp);
    fclose(fp);
}
// main function to carry out the tasks of the program
int main(void) {
    char * name = "c_serial.bin";
    int * a = (int *)malloc(DIM * DIM * sizeof(int));
    int * b = (int *)malloc(DIM * DIM * sizeof(int));
    init(DIM, a);
    init(DIM, b);
    printf("Starting serial computation.\n"); 
    // start the serial clock 
    clock_t start_serial, end_serial; 
    double cpu_time_used_serial; 
    start_serial = clock(); 
    multiply(DIM, a, b, name, -1);
    // end the serial clock and store the time to print it out
    end_serial = clock(); 
    cpu_time_used_serial = ((double) (end_serial - start_serial)) / CLOCKS_PER_SEC; 
    printf("Serial time: %f\n", cpu_time_used_serial); 
    printf("Ended serial computation."); 
    int * serial = (int *)malloc(DIM * DIM * sizeof(int));
    read_full_array(name, DIM, serial);
    printf("\n");
    pid_t pids[3];
    char file_name[32];
    int p_num;
    printf("Starting parallel computation.\n"); 
    // start the parallel clock
    clock_t start_parallel, end_parallel; 
    double cpu_time_used_parallel; 
    start_parallel = clock(); 
    for (p_num = 0; p_num < 3; p_num++) {
        pid_t pid = fork();
        if (pid == 0) {
            sprintf(file_name, "c_parallel%d.bin", p_num);
            multiply(DIM, a, b, file_name, p_num);
            exit(0);
        } 
	else {
            pids[p_num] = pid;
        }
    }
    sprintf(file_name, "c_parallel%d.bin", p_num);
    multiply(DIM, a, b, file_name, p_num);
    int i;
    for ( i = 0; i < 3; i++) {
        pid_t pid = pids[i];
        int status;
        waitpid(pid, &status, 0);
    }
    // end the parallel clock and store the time to print it out
    end_parallel = clock(); 
    cpu_time_used_parallel = ((double) (end_parallel - start_parallel)) / CLOCKS_PER_SEC; 
    printf("Parallel time: %f\n", cpu_time_used_parallel);
    printf("Ended parallel computation.\n");  
    int * parallel = (int *)malloc(DIM * DIM * sizeof(int));
    for (p_num = 0; p_num < 4; p_num++) {
        sprintf(file_name, "c_parallel%d.bin", p_num);
        read_array(file_name, DIM, parallel, p_num);
    }
    /* check to verify that *serial and *parallel are the same 
    * which validates the program */ 
    if (*serial == *parallel) { 
	printf("Verification: 1\nDone.\n"); 
    } 
    else {
	printf("Verification: 0\n Error, arrays not equal.\n"); 
    }
    // free the allocated memory
    free(a);
    free(b);
    free(serial);
    free(parallel);
    // terminate the program 
    return EXIT_SUCCESS;
}

