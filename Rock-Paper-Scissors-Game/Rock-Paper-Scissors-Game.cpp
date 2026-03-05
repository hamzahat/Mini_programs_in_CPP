#include <iostream>
#include <cstdlib>
#include <ctime>

void getUserChoice(char& player)
{
	do {
		std::cout << "choose your character:\n";
		std::cout << "'r' for rock\n";
		std::cout << "'p' for paper\n";
		std::cout << "'s' for scissors\n";
		std::cin >> player;
		std::cin.clear();
		fflush(stdin);
	} while (player != 'r' && player != 'p' && player != 's');
}

void getComputerChoice(char& computer)
{
	srand(time(NULL));
	int num = rand() % 3 + 1;

	switch (num)
	{
	case 1: 
		computer = 'r';
		break;
	case 2:
		computer = 'p';
		break;
	case 3:
		computer = 's';
		break;
	}
}

void showChoice(char choice)
{
	switch (choice)
	{
	case 'r':
		std::cout << "Rock\n";		
		break;
	case 'p':
		std::cout << "Paper\n";		
		break;
	case 's':
		std::cout << "Scissors\n";		
		break;
	}
}

void chooseWinner(char player, char computer)
{
	if (player == 'r')
	{
		if (computer == 'r')
			std::cout << "It's a tie!\n";
		else if (computer == 'p')
			std::cout << "You lose!\n";
		else
			std::cout << "You win!\n";
	}
	else if (player == 'p')
	{
		if (computer == 'r')
			std::cout << "You win!\n";
		else if (computer == 'p')
			std::cout << "It's a tie!\n";
		else
			std::cout << "You lose!\n";
	}
	else
	{
		if (computer == 'r')
			std::cout << "You lose!\n";
		else if (computer == 'p')
			std::cout << "You win!\n";
		else
			std::cout << "It's a tie!\n";
	}
}

int main()
{
	char player;
	char computer;

	std::cout << "***************************************\n";
	std::cout << "* Wecome to Rock-Paper-Scissors Game! *\n";
	std::cout << "***************************************\n";

	do
	{
		getUserChoice(player);
		std::cout << '\n';
		std::cout << "Your choice is: ";
		showChoice(player);
		getComputerChoice(computer);
		std::cout << "Computer's choice is: ";
		showChoice(computer);
		chooseWinner(player, computer);
		std::cout << "\nReplay? (y/n)\n";
		std::cin >> player;
	} while (player == 'y');

	return 0;
}

