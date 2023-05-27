#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

int main() {
    srand(2); //use current time as seed for random generator
    float random_variable = ((float)rand()/(float)RAND_MAX)*100;
    printf("Random value on [0,%d]: %f\n", RAND_MAX, random_variable);
    
}