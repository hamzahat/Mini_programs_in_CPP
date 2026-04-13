//! Luhn Algorithm:
/*
* 1. Double every seconde digit from right to left, If doubled number is 2 digits, split them
* 2. Add all single digits from step 1
* 3. Add all odd numbered digits from right to left
* 4. Sum results from steps 2 & 3
* 5. If step 4 is divisble by 10, => is valid
*/
//? I have a question, how we know that a credit card number is valid? is there a reference? or what?

#include <iostream>
#include <cstring>
#include <cstdlib>

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cerr << "Invalide number of arguments!\n";
		return 1;
	}

	for (int i = 0; i < (int)strlen(argv[1]); i+=2)
	{
		int tmp_digit = argv[1][i] - 48;
		tmp_digit *= 2;
	}
	

	return 0;
}
