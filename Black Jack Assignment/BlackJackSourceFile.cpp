#include <iostream>
#include <Windows.h>
#include <cstdlib>
#include <time.h>
#include <algorithm>
#define Suit 2
#define Cards 52

int cardDeck [Cards][Suit];
int mainMenuOption, Wager = 0, Money = 1000;
char Username[20];
int ShuffledDeck [Cards][Suit];
bool GameStarted = false;

void DeckInitialisation(void); //Function DeckInitialisation Prototype
void BlackJackGame(void); //Function BlackJackGame Prototype
void BlackJackText(void); //Function BlackJackText Prototype
void ShufflingDeck(void); //Function ShufflingDeck Prototype

int main()
{
	srand(time(NULL));
	SetConsoleTitle( TEXT( "BLACK JACK" ));

	DeckInitialisation(); // Function used to set card No. and suit to cardDeck array
	ShufflingDeck();
	//system("CLS");


		if (GameStarted == false)
		{
		BlackJackText();
		std::cout << "Please enter your username: ";
		std::cin >> Username;
		GameStarted = true;
		}

		system("CLS");

		BlackJackText();

		std::cout << "Please choose an option to perform:" << std::endl;
		std::cout << "(1) Play Black Jack" << std::endl;
		std::cout << "(2) Shuffle Deck" << std::endl;
		std::cout << "(3) Exit Game" << std::endl;
		std::cin >> mainMenuOption;

		switch(mainMenuOption)

		{

			case 1:
				BlackJackGame();
				break;

			case 2:
				ShufflingDeck();
				main();
				break;
		
			case 3:

				break;

			default:
				std::cout << "You must input a valid option!";
				std::cin.get();
				std::cin.get();
				main();
				break;

		}
}

void BlackJackGame(void)
{
	system("CLS");

	BlackJackText();
	std::cout << "You have started the game!\n";
	std::cout << "Enter your wager amount for this round: ";
	std::cin >> Wager;

	system("CLS");

	BlackJackText();



}

void BlackJackText(void)
{
		std::cout << "-----------------------" << std::endl;
		std::cout << "------BLACK  JACK------" << std::endl;
		std::cout << "-----------------------" << std::endl;
		std::cout << "\n";
		std::cout << "Money: " << Money << "	" << "Wager: " << Wager << "	" << "Username: " << Username;
		std::cout << "\n\n";
}

void DeckInitialisation(void)
{

	int counter = 1;

	for(int S = 0; S < 2; S++)
	{ 
//		std::cout << S;
		if(S == 0)
		{
			for(int rotation = 0; rotation < 4; rotation ++)
			{
				for (int C = 1; C < 14; C++)
				{
					cardDeck [counter][S] = C;	
					counter++;
		//	std::cout << counter;
				}
			}
		}
		else if (S == 1)
		{
			counter = 1;
			for (int X = 3; X < 7; X++)
			{
				for (int Y = 1; Y < 14; Y++) //3 Hearts, 4 Diamonds, 5 Clubs, 6 Spades
				{
					cardDeck [counter][S] = X;		
					counter++;
				}
			}
		}
	}
	
//	for (int s = 0; s < 1; s++)
//	{
//		for (int c = 1; c <= 52; c++)
//		{	
//			std::cout << cardDeck [c][s] << " ";
//			s++;
//			std::cout << char(cardDeck [c][s]) << std::endl;
//			s--;
//		}
//	}

}

void ShufflingDeck(void)
{
	int Card [52];
	

	for (int i = 0; i < 52; i ++)
	{		
		Card[i] = (i+1);
	}
	
	std::random_shuffle (std::begin(Card), std::end(Card));

	for (int i=0; i<52; i++) {
	}

	for (int count = 1; count <= 52; count++)
	{
		ShuffledDeck[count][0] = cardDeck[Card[count-1]][0];
		ShuffledDeck[count][1] = cardDeck[Card[count-1]][1];
	}

//	for (int s = 0; s < 1; s++)
//	{
//		for (int c = 1; c <= 52; c++)
//		{	
//			std::cout << ShuffledDeck [c][s] << " ";
//			s++;
//			std::cout << char(ShuffledDeck [c][s]) << std::endl;
//			s--;
//		}
//	}

	//shuffle Card array
	//assign CardDeck values to ShuffledDack Values dependant on the random numbers generated from the shuffled counter array
}