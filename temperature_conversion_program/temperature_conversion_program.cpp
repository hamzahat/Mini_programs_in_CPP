#include <iostream>

int main()
{
	float temp;
	char unit;

	std::cout << "*** Temperature conversion program***" << '\n';
	std::cout << "F = Fahrenheit" << '\n';
	std::cout << "C = Celsius" << '\n';
	std::cout << "What unit would you like to convert to: ";
	std::cin >> unit;

	if (unit != 'F' && unit != 'f' && unit != 'C' && unit != 'c')
		std::cout << "Error!\nPlease enter in only C/c or F/f\n";
	else if (unit == 'F' || unit == 'f')
	{
		std::cout << "Enter the temperature in Celsius: ";
		std::cin >> temp;
		temp = (1.8 * temp) + 32.0;
		std::cout << "Temperature is: " << temp << " F\n";
	}
	else if (unit == 'C' || unit == 'c')
	{
		std::cout << "Enter the temperature in Fahrenheit: ";
		std::cin >> temp;
		temp = (temp - 32) / 1.8;
		std::cout << "Temperature is: " << temp << " C\n";
	}

	std::cout << "******************************" << '\n';
	return 0;
}
