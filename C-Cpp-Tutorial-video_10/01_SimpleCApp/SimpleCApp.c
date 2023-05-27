#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <memory.h>
#include <string.h>

int32_t f(int32_t x);
void print_fx(int32_t x, int32_t y);
int32_t scan_int(int32_t* x);
void accurate_print(int32_t x, int32_t count);

int main()
{
	// (I) Simulate input (TODO: Replace with proper input)
	int32_t x =0;
	int32_t count;
	int32_t r0 = scan_int(&x);
	int32_t r1 = scan_int(&count);
	//printf("Read %i parameters, output is:",result);

	// && (result != EOF);

	if (r0 == 1 && r1 == 1 && count>0){
		printf("Read %i parameters, output is:", r0);
		accurate_print(x,count);
		
	}
	else if(r0==EOF || r1==EOF){
		printf("IO Error");
	}
	else if (r1 == 1 && count <=0) {
		printf("The second value must be greater than 0");
	}
	else {
		printf("Invalid value");
	};


	// (P) 
	/*int32_t y1 = f(1 * x);
	int32_t y2 = f(2 * x);
	int32_t y3 = f(3 * x);
	int32_t y4 = f(4 * x);*/

	// (O)
	/*print_fx(1 * x, y1);
	print_fx(2 * x, y2);
	print_fx(3 * x, y3);
	print_fx(4 * x, y4);*/
}

int32_t f(int32_t x)
{
	return x * x + 5 * x + 5;
}

void print_fx(int32_t x, int32_t y)
{
	printf("f(%i) = %i, ", x, y);
}

int32_t scan_int(int32_t* x) {
	
	printf("Please Enter a number:");
	return scanf_s("%li", x);

}

void accurate_print(int32_t x, int32_t count) {

	int32_t* y_value = malloc(count*4);

	for(int32_t i = 0 ; i<count ; i++) {
		y_value[i] = f(i * x);
	}
	for (int32_t i = 0; i < count; i++) {
		printf(" f(%li)=%li ",i*x, y_value[i]);
	}
}
