#include <cs50.h>
#include <stdio.h>

int main(void)
{
	printf("Height: ");
	int pyramidHeight = GetInt();

	printf("A half-pyramid will be generated %i blocks high\n", pyramidHeight);
}
