#include <cs50.h>
#include <stdio.h>

int calculateOddNumber(int n);
int countDigits(long long n);

int main(void) {
	printf("Number: ");
	// long long cardNumber = GetLongLong();
	long long cardNumber = 378282246310005;
	int cardNumberLength = countDigits(cardNumber);

	if (cardNumberLength < 13 || cardNumberLength > 16) {
		return printf("INVALID count: %i \n", cardNumberLength);
	}

	int evenTotal = 0;
	int oddTotal = 0;

	for (int i = 0; i < cardNumberLength; i++) {
		int isEven = (i == 0) || (i % 2 == 0);

		if (isEven) {
			evenTotal += i;
		}

		if (!isEven) {
			int oddNumber = calculateOddNumber(i);

			oddTotal += oddNumber;
		}
	}

	printf("eventotal: %i \n", evenTotal); //
	printf("oddTotal: %i \n", oddTotal); //
}


int calculateOddNumber(int n) {
		int z = (n * 2);
		int digitCount = countDigits(z);

		if (digitCount == 0) {
			return z;
		}

		// @TODO need to add these digits together.
		printf("large number, lets iterate %i\n", z);

		int sum = 0;
		int remainder;

		while (digitCount != 0) {
			remainder = digitCount % 10; // @TODO: Always returns 2 :S.
			sum += remainder;

			printf("adding %i\n", remainder);
			digitCount /= 10;
		}

		return sum;
}

int countDigits(long long n) {
	int count = 0;
	while (n != 0) {
		n /= 10;
		count++;
	}

	return count;
}
