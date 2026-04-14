//! Luhn Algorithm:
/*
* 1. Double every seconde digit from right to left, If doubled number is 2 digits, split them
* 2. Add all single digits from step 1
* 3. Add all odd numbered digits from right to left
* 4. Sum results from steps 2 & 3
* 5. If step 4 is divisble by 10, => is valid
*/

#include <iostream>

int getDigit(const int number)
{
	return (number % 10 + (number / 10));
}

int sumOddDigits(const std::string cardNumber)
{
	int sum = 0;
	for (size_t i = 1; i < cardNumber.length(); i += 2)
		sum += getDigit(cardNumber[i] - 48);
	return sum;
}

int sumEvenDigits(const std::string cardNumber)
{
	int sum = 0;
	for (size_t i = 0; i < cardNumber.length(); i += 2)
		sum += getDigit((cardNumber[i] - 48) * 2);
	return sum;
}

int main()
{
	std::string cardNumber;
	int result = 0;

	std::cout << "Enter a credit Card Number: ";
	std::cin >> cardNumber;

	result = sumEvenDigits(cardNumber) + sumOddDigits(cardNumber);
	if (result % 10 == 0)
		std::cout << cardNumber << " is valid!\n";
	else
		std::cout << cardNumber << " is Not valid!\n";

	return 0;
}
