#include <iostream>

int main()
{
	char user_answer;
	int score = 0;

	std::string questions[] = { "1. What year was C++ created?",
								"2. Who invented C++?",
								"3. What is the predecessor of C++?",
								"4. is the Earth flat?"};

	std::string options[][4] = {{"A. 1969",             "B. 1975",              "C. 1985",         "D.1989",},
								{"A. Guido van Rossum", "B. Bjarne Stroustrup", "C. John Carmack", "D. Mark Zuckerburg"},
								{"A. C",                "B. C+",                "C. C--",          "D. B++"},
								{"A. yes",              "B. no",                "C. sometimes",    "D. What's Earth?"}};

	char answerKey[] = {'C', 'B', 'A', 'B'};

	int questions_nbr = sizeof(questions)/sizeof(questions[0]);
	int options_nbr = sizeof(options[0])/sizeof(options[0][0]);

	for (int i = 0; i < questions_nbr; i++)
	{
		std::cout << "**************************************\n";
		std::cout << questions[i] << '\n';
		std::cout << "**************************************\n";

		for (int j = 0; j < options_nbr; j++)
			std::cout << options[i][j] << '\n';
		
		std::cout << "Enter the correct answer: ";
		std::cin >> user_answer;
		user_answer = toupper(user_answer);

		if (user_answer == answerKey[i])
		{
			std::cout << "CORRECT!\n";
			score++;
		}
		else
		{
			std::cout << "WRONG!\n";
			std::cout << "Correct Answer is: " << answerKey[i] << '\n';
		}

	}

	std::cout << "*************************************\n";
	std::cout << "*              RESULTS              *\n";
	std::cout << "*************************************\n";
	std::cout << "Correct Guesses: " << score << '\n';
	std::cout << "Number of questions: " << questions_nbr << '\n';
	std::cout << "Your total correct answers is: " << (score / (float)questions_nbr) * 100 << "%\n";

	return 0;
}
