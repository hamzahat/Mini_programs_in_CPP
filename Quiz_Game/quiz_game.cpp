#include <iostream>

int main()
{
	char answer;
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

	//! algo:
	//* loop over the questions
	//* print the questions
	//* print the options
	//* check if the user's anser correct or not
	//* calculate the total score (correct questions)

	for (int i = 0; i < questions_nbr; i++)
	{
		std::cout << "**************************************\n";
		std::cout << questions[i] << '\n';
		std::cout << "**************************************\n";

		for (int j = 0; j < options_nbr; j++)
			std::cout << options[i][j] << '\n';
		
		std::cout << "Enter the correct answer: ";
		std::cin >> answer;
		answer = toupper(answer);

		if (answer == answerKey[i])
		{
			std::cout << "Correct!\n";
			score++;
		}
		else
			std::cout << "Wrong!\n";

	}

	std::cout << "*************************************\n";
	std::cout << " Your total correct answers is: " << (score/(float)questions_nbr)*100 << "%\n";
	std::cout << "*************************************\n";

	return 0;
}

//! I think that I finish this code, just need to check it with 'Bro Code' to see if we miss something!