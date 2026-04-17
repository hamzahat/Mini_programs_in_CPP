//! TIC TAC TOE Game:

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

//* get palyer's choice
void get_player_choice(char &player)
{
	std::string input;

	do
	{
		std::cout << "Enter/choose 'X' or 'O'\n";
		std::getline(std::cin, input);
		if (std::cin.eof())
		{
			std::cout << "\nEOF detected. Exiting game.\n";
			exit(0);
		}
		else if (input.length() == 1)
			player = input[0];
		else
			player = ' ';
	} while (player != 'X' && player != 'x' && player != 'O' && player != 'o');
}

//* get computer's choice based on player's choice
void get_computer_choice(char &computer, char palyer)
{
	if (palyer == 'X' || palyer == 'x')
		computer = 'O';
	else
		computer = 'X';
}

//* draw the TIC TAC TOE board;
void draw_Board(char *spaces)
{
	std::cout << '\n';
	std::cout << "     |     |     " << '\n';
	std::cout << "  " << spaces[0] << "  |  " << spaces[1] << "  |  " << spaces[2] << "  " << '\n';
	std::cout << "_____|_____|_____" << '\n';
	std::cout << "     |     |     " << '\n';
	std::cout << "  " << spaces[3] << "  |  " << spaces[4] << "  |  " << spaces[5] << "  " << '\n';
	std::cout << "_____|_____|_____" << '\n';
	std::cout << "     |     |     " << '\n';
	std::cout << "  " << spaces[6] << "  |  " << spaces[7] << "  |  " << spaces[8] << "  " << '\n';
	std::cout << "     |     |     " << '\n';
	std::cout << '\n';
}

//* draw the first board tutorial:
void draw_Board_tutorial(char *spaces)
{
	std::cout << '\n';
	std::cout << "     |     |     " << '\n';
	std::cout << "  1  |  2  |  3  " << '\n';
	std::cout << "_____|_____|_____" << '\n';
	std::cout << "     |     |     " << '\n';
	std::cout << "  4  |  5  |  6  " << '\n';
	std::cout << "_____|_____|_____" << '\n';
	std::cout << "     |     |     " << '\n';
	std::cout << "  7  |  8  |  9  " << '\n';
	std::cout << "     |     |     " << '\n';
	std::cout << '\n';
}

//* get player's new choice, and draw it in the board
void player_Move(char *spaces, char player)
{
	std::string input;
	int number = -1;

	while (true)
	{
		std::cout << "Enter a spot to palce a marker (1-9): ";
		std::getline(std::cin, input);
		if (std::cin.eof())
		{
			std::cout << "\nEOF detected. Exiting game.\n";
            exit(0);
		}
		else if (input.length() == 1 && isdigit(input[0]))
		{
			number = input[0] - '0';
			number--;
			if (number >= 0 && number <= 8)
			{
				if (spaces[number] == ' ')
				{
					spaces[number] = player;
					break;
				}
				else
					std::cerr << "this spot is Not valid!\n";
			}
			else
				std::cerr << "Invalid number! (1-9)\n";
		}
		else
			std::cerr << "Invalid input! Please enter a number.\n";
	}
}

//* get computer's new choice, and draw it in the board
void computer_Move(char *spaces, char computer)
{
	int number;

	srand(time(NULL));
	while (true)
	{
		number = rand() % 9;
		if (spaces[number] == ' ')
		{
			spaces[number] = computer;
			break;
		}
	}
}

//* check if someone winne!
bool check_Winner(char *spaces, char palyer, char computer)
{
	if (spaces[0] != ' ' && spaces[0] == spaces[1] && spaces[1] == spaces[2])
		spaces[0] == palyer ? std::cout << "You Win!\n" : std::cout << "You Lose!\n";
	else if (spaces[3] != ' ' && spaces[3] == spaces[4] && spaces[4] == spaces[5])
		spaces[3] == palyer ? std::cout << "You Win!\n" : std::cout << "You Lose!\n";
	else if (spaces[6] != ' ' && spaces[6] == spaces[7] && spaces[7] == spaces[8])
		spaces[6] == palyer ? std::cout << "You Win!\n" : std::cout << "You Lose!\n";
	else if (spaces[0] != ' ' && spaces[0] == spaces[4] && spaces[4] == spaces[8])
		spaces[0] == palyer ? std::cout << "You Win!\n" : std::cout << "You Lose!\n";
	else if (spaces[2] != ' ' && spaces[2] == spaces[4] && spaces[4] == spaces[6])
		spaces[2] == palyer ? std::cout << "You Win!\n" : std::cout << "You Lose!\n";
	else if (spaces[0] != ' ' && spaces[0] == spaces[3] && spaces[3] == spaces[6])
		spaces[0] == palyer ? std::cout << "You Win!\n" : std::cout << "You Lose!\n";
	else if (spaces[1] != ' ' && spaces[1] == spaces[4] && spaces[4] == spaces[7])
		spaces[1] == palyer ? std::cout << "You Win!\n" : std::cout << "You Lose!\n";
	else if (spaces[2] != ' ' && spaces[2] == spaces[5] && spaces[5] == spaces[8])
		spaces[2] == palyer ? std::cout << "You Win!\n" : std::cout << "You Lose!\n";
	else
		return false;
	return true;
}

//* check if it's a Tie!
bool check_Tie(char *spaces)
{
	for (int i = 0; i < 9; i++)
	{
		if (spaces[i] == ' ')
			return false;
	}
	std::cout << "It's a Tie!\n";
	return true;
}

int main()
{
	char spaces[] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
	char player;
	char computer;
	bool running = true;

	get_player_choice(player);
	get_computer_choice(computer, player);

	draw_Board_tutorial(spaces);
	while (running)
	{
		player_Move(spaces, player);
		std::cout << "You:\n";
		draw_Board(spaces);
		if (check_Winner(spaces, player, computer))
		{
			running = false;
			break;
		}
		else if (check_Tie(spaces))
		{
			running = false;
			break;
		}
		computer_Move(spaces, computer);
		std::cout << "Computer:\n";
		draw_Board(spaces);
		if (check_Winner(spaces, player, computer))
		{
			running = false;
			break;
		}
		else if (check_Tie(spaces))
		{
			running = false;
			break;
		}
	}

	std::cout << "Thanks for playing!\n";

	return 0;
}
