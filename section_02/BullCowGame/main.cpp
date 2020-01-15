
#include<iostream>
#include<string>
#include "FBullCOwGame.h"



using FText = std::string;
using int32 = int;


void Print32int32ro();
void PlayGame();
FText GetValidGuess();
bool AskToPlayAgain();
void PrintGameSummary();


FBullCowGame BCGame;

int main()
{
	std::cout << BCGame.GetCurrentTry();

	bool bPlayAgain = false;
	do {
		Print32int32ro();
		PlayGame();
		bPlayAgain = AskToPlayAgain();
	} while (bPlayAgain);

	std::cout << std::endl;

	return	0; 
}

void PlayGame()
{

	BCGame.Reset();
	int32 MaxTryies = BCGame.GetMaxTries(); 
	std::cout << MaxTryies << std::endl;

	while (!BCGame.IsGameWon() && BCGame.GetCurrentTry() <= MaxTryies) {
		FText Guess = GetValidGuess(); 

		FBullCowCount BullCowCount = BCGame.SubmitValidGuess(Guess);

		std::cout << " Bulls = " << BullCowCount.Bulls;
		std::cout << " Cows = " << BullCowCount.Cows << "\n\n";
	}

	PrintGameSummary();
	return;
}

void Print32int32ro()
{


	std::cout << "\n\nWelcome to bulls and Cows, the wirdest game i've ever seen xD\n";
	std::cout << "So you realy try play of this? Ok, Then Lets start\n";
	std::cout << std::endl;
	std::cout << "                }   {       ___" << std::endl;
	std::cout << "                (o o)      (o o)" << std::endl;
	std::cout << "     /-----------\\ /        \\ /---------\\" << std::endl;
	std::cout << "    / |  BULL   | 0          0|  COW   | \\" << std::endl;
	std::cout << "   *  |-,-------|             |--------|  *" << std::endl;
	std::cout << "      ^         ^             ^        ^ \n" << std::endl;
	std::cout << "Can you guess the " << BCGame.GetHiddenWordLength();
	std::cout << " letter isogram I'm thinking of?\n";
	std::cout << std::endl;
	return;
}

FText GetValidGuess()
{
	FText Guess = "";
	EGuessStatus Status = EGuessStatus::Invalid_status;
	do {
		int32 CurrentTry = BCGame.GetCurrentTry();
		std::cout << "Try " << CurrentTry << " of " << BCGame.GetMaxTries();
		std::cout << " Enter your Guess: ";
		std::getline(std::cin, Guess);

		Status = BCGame.CheckGuessValidiaty(Guess);
		switch (Status)
		{
		case EGuessStatus::Wrong_Length:
			std::cout << "please enter a " << BCGame.GetHiddenWordLength() << "Letter word.\n\n";
			break;
		case EGuessStatus::Not_Isogram:
			std::cout << "Please enter a word witout repeating letters.\n\n";
			break;
		case EGuessStatus::Not_Lowercase:
			std::cout << "Pleas enter all lowercase letters.\n\n";
			break;
		default:
			break;
		}
	} while (Status != EGuessStatus::OK); 
	return Guess;
}

bool AskToPlayAgain()
{
	std::cout << "Do you wont play again? (y/n) ";
	FText Response = "";
	std::getline(std::cin, Response);
	system("CLS");

	return (Response[0] == 'y') || (Response[0] == 'Y');
}

void PrintGameSummary() 
{
	if (BCGame.IsGameWon()) 
	{
		std::cout << "WELL DONE - YOU WIN\n";
	}
	else 
	{
		std::cout << "Better luck next time\n";
	}
}
