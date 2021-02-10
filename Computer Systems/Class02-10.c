#include <stdio.h> 
#define SIZE 10

int main(int argc, char * argv[]) {
    int nums[SIZE];
    nums[0] = 1;
    nums[1] = 2;
    nums[2] = 3;
    nums[3] = 4;
    nums[4] = 5;
    nums[5] = 6;
    nums[6] = 7;
    nums[7] = 8;
    nums[8] = 9;
    nums[9] = 10;
    printf("%d\n", nums[SIZE -1]);
    printf("%d\n", * (nums + SIZE -1));
    return 0;
}