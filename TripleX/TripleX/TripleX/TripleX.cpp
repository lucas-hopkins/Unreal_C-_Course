#include <iostream>
#include <ctime>

void PlayGameatDiffulty(int difficulty)
{
	std::cout << "You're a secret agent breaking in to LEVEL " << difficulty << " server room\n";
	std::cout << "Your SUPERHACKER power tells you the following info...\n" << std::endl;

	srand(time(NULL)); // Create random seed using time
	
	// Generate 3 ints with our random seed
	const int a = rand() % difficulty + difficulty;
	const int b = rand() % difficulty + difficulty;
	const int c = rand() % difficulty + difficulty;

	std::cout << a << b << c;
	const int product = a * b * c;
	const int sum     = a + b + c;

	std::cout << std::endl;
	std::cout << "+ There are three numbers in the code\n";
	std::cout << "+ The codes multiply to give " << product << std::endl;
	std::cout << "+ The codes add up to " << sum << std::endl;

	int answer{};
	int guessA{};
	int guessB{};
	int guessC{};
	int userSum{};
	int userProduct{};

	std::cout << "Enter the code - Example 10 31 21" << std::endl;
	std::cin >> guessA >> guessB >> guessC;
	{
		userSum = guessA + guessB + guessC;
		userProduct = guessA * guessB * guessC;
	}

	if (userSum == sum && userProduct == product)
	{
		std::cout << "CONGRATULATIONS, YOU'RE IN. Now hurry before anyone finds you\n";
		std::cout << "=============================================================\n";
	}
	else
	{
		std::cout << "You have failed....and died\n";
		std::cout << std::endl;
	}
	
}


int main(int argc, char** argv)
{
	int difficulty;
	int maxDifficulty = 10;
	int minDifficulty = 1;
	std::cout << "Enter 1-10 to determine difficulty" << std::endl;
	std::cin >> difficulty;
	while (difficulty <= maxDifficulty && difficulty >= minDifficulty)
	{	
		PlayGameatDiffulty(difficulty);
		std::cin.clear();
		std::cin.ignore();
		++difficulty;
	}

	std::cout << "WOW - You're a master hacker\n";
	return 0;
}