#include <iostream>
#include <cstdlib>

int main()
{
	srand(time(NULL));

	int num = (rand() % 10) + 1;

	std::cout << num << '\n';

	return 0;
}
