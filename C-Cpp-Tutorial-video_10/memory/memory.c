#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <memory.h>
#include <string.h>
#include <inttypes.h>
int main() {
	int32_t arrayA[32];

	int32_t arrayB[32];

	for (int8_t i = 0; i < 32; i++)
	{
		arrayA[i] = i * 11;
	}

	memset(arrayB, 0xFF , 32*sizeof(int32_t));

	int abEqual = memcmp(arrayA,arrayB,32*sizeof(int32_t)) == 0;
	printf("Arrays before copy %i\n", abEqual);

	memcpy(arrayB, arrayA, 32 * sizeof(int32_t));

	abEqual = memcmp(arrayA, arrayB, 32 * sizeof(int32_t)) == 0;
	printf("Arrays after copy %i\n", abEqual);


}