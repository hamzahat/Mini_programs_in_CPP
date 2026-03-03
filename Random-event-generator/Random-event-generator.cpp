#include <iostream>
#include <cstdlib>
#include <ctime>

int main()
{
	srand(time(NULL));
	int randNum = rand() % 5 + 1;

	switch (randNum)
	{
		case 1: std::cout << "you got the 1 rank!\n"; break;
		case 2: std::cout << "you got the 2 rank!\n"; break;
		case 3: std::cout << "you got the 3 rank!\n"; break;
		case 4: std::cout << "you got the 4 rank!\n"; break;
		case 5: std::cout << "you got the 5 rank!\n"; break;
	}

	return 0;
}

