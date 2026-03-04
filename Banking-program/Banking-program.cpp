#include <iostream>
#include <iomanip>

void showBalance(float balance)
{
	std::cout << "Your balance is: $" << std::setprecision(2) << std::fixed << balance << '\n';
}

void deposit(float& balance)
{
	float amount = 0;
	std::cout << "Enter amount to be deposited: ";
	std::cin >> amount;
	if (amount > 0)
		balance += amount;
	else
		std::cout << "Invalid amount!\n";
}

void withdraw(float& balance)
{
	float amount = 0;
	std::cout << "Enter amount to be withdrawn: ";
	std::cin >> amount;
	if (amount > balance)
		std::cout << "Insufficient funds\n";
	else if (amount < 1)
		std::cout << "Invalid amount!\n";
	else
		balance -= amount;
}

int main()
{
	float balance = 0;
	int choice = 0;

	do
	{
		std::cout << "******************\n";
		std::cout << "Enter your choice:\n";
		std::cout << "******************\n";
		std::cout << "1. Show Balance\n";
		std::cout << "2. Deposit Money\n";
		std::cout << "3. Withdraw Money\n";
		std::cout << "4. Exit\n";
		std::cin >> choice;

		std::cin.clear();
		fflush(stdin);

		switch (choice)
		{
		case 1: showBalance(balance); break;
		case 2: deposit(balance); break;
		case 3: withdraw(balance); break;
		case 4: std::cout << "EXIT!\n"; break;
		default: std::cout << "Invalid input!\n"; break;
		}

		std::cout << std::endl;

	} while (choice != 4);

	return 0;
}

