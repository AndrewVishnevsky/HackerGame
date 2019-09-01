#include <iostream>
#include <ctime>

using namespace std;


void Menu(int Difficulty)
{
	cout << "You a secret agent breaking into a level "<< Difficulty<<" server room" << endl;
	cout << "Enter the correct code to continue..." << endl;

}

bool PlayGame(int Difficulty)
{
	Menu(Difficulty);
	const int FirstCode = rand()%Difficulty+1;
	const int SecondCode = rand()%Difficulty + 1;
	const int ThirdCode = rand()%Difficulty + 1;

	const int CodeSum = FirstCode + SecondCode + ThirdCode;
	const int CodeProduct = FirstCode * SecondCode * ThirdCode;

	cout << "There are 3 numbers of the code\n";
	cout << "The codes add-up to: " << CodeSum << endl;
	cout << "The codes multiplay to give: " << CodeProduct << endl;

	int FirstGuess;
	int SecondGuess;
	int ThirdGuess;


	cout << "Enter a password a three times: ";
	cin >> FirstGuess >> SecondGuess >> ThirdGuess;
	cout << "Yot entered: " << FirstGuess << SecondGuess << ThirdGuess << endl;
	int GuessSum = FirstGuess + SecondGuess + ThirdGuess;
	int GuessProduct = FirstGuess * SecondGuess * ThirdGuess;

	if (GuessSum == CodeSum && GuessProduct == CodeProduct)
	{
		cout << "Well done! Now u can hack next level\n";
		return true;
	}
	else
	{
		cout << "U a losser! Try again!\n";
		return false;
	}
	
}

int main()
{
	srand(time(NULL));
	int LevelDiff = 1;
	const int MaxDiff = 5;

	while (LevelDiff<=MaxDiff)
	{
		bool bLevelComplete=PlayGame(LevelDiff);
		cin.clear();
		cin.ignore();

		if (bLevelComplete)	
		{
			// Increase difficulty
			++LevelDiff;
		}
	}
	cout << "U finally got it! U a cool hacker!\n";

	return 0;
}
