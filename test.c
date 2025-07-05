#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <limits.h>

int main()
{
    // long long int jb;

    // jb = -78474624536863526324;
    // printf("The value of jb is: %ld\n", jb);
    printf("The max of long int is:      %ld\n", LONG_MAX);
    printf("The max of long long int is: %lld\n", LLONG_MAX);
    printf("The min of long int is:      %ld\n", LONG_MIN);
    printf("The min of long long int is: %lld\n", LLONG_MIN);
}