#include <cs50.h>
#include <stdio.h>

int calculateOddNumber(int n);
int countDigits(long long n);

int main(void) {
	printf("Number: ");
	long long cardNumber = GetLongLong();
	int cardNumberLength = countDigits(cardNumber);

	if (cardNumberLength < 13 || cardNumberLength > 16) {
		printf("INVALID\n");
		return 0;
	}

	int evenTotal = 0;
	int oddTotal = 0;

	long long tempNumber = cardNumber;

	for (int i = 0; i < cardNumberLength; i++) {
		int isEven = (i == 0) || (i % 2 == 0);
		int value = tempNumber % 10;

		if (isEven) {
			evenTotal += value;
		}

		if (!isEven) {
			int oddNumber = calculateOddNumber(value);

			oddTotal += oddNumber;
		}

		tempNumber /= 10;
	}

	if ((oddTotal + evenTotal) % 10) {
		printf("INVALID\n");
		return 0;
	}

	if (cardNumberLength == 15) {
		printf("AMEX\n");
		return 0;
	}

	if (cardNumber >= 5100000000000000 && cardNumber <= 5599999999999999) {
		printf("MASTERCARD\n");
		return 0;
	}

	if (cardNumber >= 4000000000000000 && cardNumber <= 4999999999999999) {
		printf("VISA\n");
		return 0;
	}
}

int calculateOddNumber(int n) {
		int z = (n * 2);
		int digitCount = countDigits(z);

		if (digitCount == 0 || digitCount == 1) {
			return z;
		}

		int sum = 0;
		int remainder;

		while (z != 0) {
			remainder = z % 10;
			sum += remainder;

			z /= 10;
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
