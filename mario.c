#include <cs50.h>
#include <stdio.h>

int main(void) {
	int pyramidHeight;

	do {
		printf ("Height: ");
		pyramidHeight = GetInt();
	} while (pyramidHeight < 0 || pyramidHeight > 23);

	for (int row = 1; row <= pyramidHeight; row++) {

		for (int k = 0; k < (pyramidHeight - row); k++)
			printf(" ");

		for (int j = 0; j < row; j++)
			printf("#");

		printf("  ");

		for (int l = 0; l < row; l++)
			printf("#");

		printf("\n");
	}

	return 0;
}
