#include <stdio.h>
#include <stdint.h>
#include <stddef.h>

int32_t f(int32_t x);
void print_fx(int32_t x, int32_t y);
int32_t scan_x(int32_t* x);

int main()
{
	// (I) Simulate input (TODO: Replace with proper input)
	int32_t x =0;
	int32_t result = scan_x(&x);
	//printf("Read %i parameters, output is:",result);

	int8_t check = (result != 0);// && (result != EOF);

	if (check){
		printf("Read %i parameters, output is:", result);
		int32_t y1 = f(1 * x);
		int32_t y2 = f(2 * x);
		int32_t y3 = f(3 * x);
		int32_t y4 = f(4 * x);
		print_fx(1 * x, y1);
		print_fx(2 * x, y2);
		print_fx(3 * x, y3);
		print_fx(4 * x, y4);
	}
	else if(result==EOF){
		printf("IO Error");
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

int32_t scan_x(int32_t* x) {
	
	printf("Please Enter a number:");
	return scanf_s("%li", x);

}
