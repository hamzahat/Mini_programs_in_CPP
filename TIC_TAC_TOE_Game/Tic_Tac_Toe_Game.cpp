//! TIC TAC TOE Game:

#include <iostream>
// #include <ctime> //? I need it?

//* get palyer's choice
void get_player_choice(char &player)
{
	do
	{
		std::cout << "Enter/choose 'X' or 'O'\n";
		std::cin >> player; 
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

//* get player's new choice, and draw it in the board
void player_Move(char *spaces, char player)
{
	int number = -1;

	while (true)
	{
		std::cout << "Enter a spot to palce a marker (1-9): ";
		std::cin >> number;
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
			std::cerr << "Invalid number!\n";
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
		spaces[6] == palyer ? std::cout << "You Win!\n" : std::cout << "You Lose!\n";
	else if (spaces[2] != ' ' && spaces[2] == spaces[5] && spaces[5] == spaces[8])
		spaces[6] == palyer ? std::cout << "You Win!\n" : std::cout << "You Lose!\n";
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

	draw_Board(spaces); //todo: should we draw a toturial about the spats and there numbers
	while (running)
	{
		player_Move(spaces, player);
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

/*
todo: should we draw a toturial about the spats and there numbers
* like this:
*  _____ _____ _____
* |     |     |     |
* |  1  |  2  |  3  |
* |_____|_____|_____|
* |     |     |     |
* |  4  |  5  |  6  |
* |_____|_____|_____|
* |     |     |     |
* |  7  |  8  |  9  |
* |_____|_____|_____|
*
*/

//todo fix error in input like when the user hit enter! or ctr+D
//todo add sentence that show that the computer play