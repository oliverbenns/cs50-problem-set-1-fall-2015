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
		return printf("INVALID length: %i \n", cardNumberLength);
	}

	int evenTotal = 0;
	int oddTotal = 0;

	long long tempNumber = cardNumber;

	for (int i = 0; i < cardNumberLength; i++) {
		int isEven = (i == 0) || (i % 2 == 0);
		int value = tempNumber % 10;

		printf("value: %i\n", value);

		if (isEven) {
			evenTotal += value;
		}

		if (!isEven) {
			int oddNumber = calculateOddNumber(value);

			oddTotal += oddNumber;
		}

		tempNumber /= 10;
		printf("------------------------------------\n");
	}

	printf("eventotal: %i \n", evenTotal); //
	printf("oddTotal: %i \n", oddTotal); //

	if ((oddTotal + evenTotal) % 10 != 0) {
		return printf("INVALID card number\n");
	}

	// if number starts with 34 or 37. AND is 15 digits
	// 	return printf("AMEX\n");

	// if number starts with 51, 52, 53, 54, or 55 AND is 16 digits
	// 	return printf("MASTERCARD\n");

	// if number starts with 4 AND is 13 OR 16 digits
	// 	return printf("VISA\n");

}


int calculateOddNumber(int n) {
		int z = (n * 2);
		int digitCount = countDigits(z);
		printf("digitCount: %i\n", digitCount);

		if (digitCount == 0 || digitCount == 1) { // This isn't quite right. Using the 0 digit returns, though it's 1 digit.
			printf("addingSmall: %i\n", z);
			return z;
		}

		int sum = 0;
		int remainder;

		while (z != 0) {
			remainder = z % 10;
			printf("remainder: %i\n", remainder);
			sum += remainder;

			z /= 10;
		}

		printf("addingBig: %i\n", sum);
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
