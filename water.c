#include <cs50.h>
#include <stdio.h>

int getShowerLength(void);
int calculateBottleCount(int minutes);

int main(void) {
	int showerLength = getShowerLength();

	printf("bottles: %d \n", calculateBottleCount(showerLength));
}

int getShowerLength(void) {
	int showerLength;

	while (showerLength <= 0) {
		printf("minutes: ");
		showerLength = GetInt();
	}

	return showerLength;
}

int calculateBottleCount(int minutes) {
	float gallonsPerMinute = 1.5;
	int gallonsInOunces = 128;
	int bottleInOunces = 16;

	return (minutes * (gallonsInOunces * gallonsPerMinute)) / bottleInOunces;
}
