#include <stdio.h>
#include <stdint.h>
#include <stddef.h>

typedef struct accumulatedata{// using accumulate here allows using struct keyword while definif the var
    int64_t sum;
    int64_t num;
}accumulatedata;//using it here doesn't allow struct keyword use both for both 

void accumulate(accumulatedata* data, int64_t value)
{
    data->sum += value;
    (data->num)++;
}

int main()
{
    accumulatedata d;
    d.sum = 0;
    d.num = 0;

    accumulate(&d, 10);
    accumulate(&d, 20);

    int64_t avg = d.sum/d.num;
    printf("The average is: %lli\n", avg);
    printf("The max value of int 64 is %lli", INT64_MAX);

    //size_t is the max size of the computer for example for 32 bit it will be 32
}
