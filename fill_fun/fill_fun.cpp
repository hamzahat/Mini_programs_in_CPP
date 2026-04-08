#include <iostream>
#include <algorithm> //* for std::fill() fun

int main()
{
	int size = 9;
	std::string foods[size];

	std::fill(foods, foods + (size/3), "pizza");
	std::fill(foods + (size/3), foods + (size/3) * 2, "hamburger");
	std::fill(foods + (size/3) * 2, foods + size, "tajin");

	for (int i = 0; i < size; i++)
		std::cout << foods[i] << '\n';

	return 0;
}
