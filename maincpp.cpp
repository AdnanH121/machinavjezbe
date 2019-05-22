#include <iostream>
#include<string>
#include<vector>
#include<cstdlib>
#include<ctime>

class Card
{
public:

	int randCardOne;
	int randCardTwo;
	int randCardThree;
	int randCardFour;
	int playerRandomCards;
	int dealerRandomCards;

	


	


	void randomCards()
	{
		srand(time(NULL));
		 randCardOne = (rand() % 10) + 1;
		 randCardTwo = (rand() % 10) + 1;
		 if ((randCardOne == 10 && randCardTwo == 1) || (randCardOne == 1 && randCardTwo == 10))
			 playerRandomCards = 21;
		 else
			  playerRandomCards = randCardOne + randCardTwo;

		  randCardThree = (rand() % 10) + 1;
	      randCardFour = (rand() % 10) + 1;
		 if ((randCardThree == 10 && randCardFour == 1) || (randCardThree == 1 && randCardFour == 10))
			  dealerRandomCards = 21;
		 else
			  dealerRandomCards = randCardThree + randCardFour;
    }
	

private:
	int _firstValue, _secondValue, _drawValue;
};

class Player : public Card
{
public:
	void playerCards()
	{
		std::cout << "Your cards: " << randCardOne << " and " << randCardTwo << " , which is " << playerRandomCards << " points!"<<std::endl;
	}
	
	void drawCard()
	{
		

				
					int pickCard = (rand() % 10) + 1;
					playerRandomCards += pickCard;
					
					std::cout << "You picked card " << pickCard << "\n"
						"\nand now you have " << playerRandomCards << std::endl;
					if (playerRandomCards > 21)
					{
						std::cout << playerRandomCards << " points!!!You loose " << std::endl;
						

					}

	}

};
class Dealer : public Player
{
public:

	
void dealerCards()
{
	std::cout << "Dealer cards: " << randCardThree << " and " << randCardFour << " , which is " << dealerRandomCards << " points!" << std::endl;
}
void dealerDrawCard()
{
	 bool check = true;
	
	while (check)
	{
		
		

		if ((dealerRandomCards < playerRandomCards) || (dealerRandomCards >= 10 && dealerRandomCards < 14))
		{
			int dealerPickCard = (rand() % 10) + 1;
			dealerRandomCards += dealerPickCard;
			std::cout << "Dealer picked card " << dealerPickCard << "\n"
				"\nand now has " << dealerRandomCards << std::endl;
			if (dealerRandomCards >= 21)
			{
				
				check = false;
				break;
			}


		}
		else
		{
			check = false;
			break;
		}
	}
}
};

void placeBet(bool& checkBet, int& playerMoney, int& playerTempMoney, 
	          int& dealerMoney, int& dealerTempMoney, int& playerBet, int& dealerBet )
{
	checkBet = true;
	
	
		
			std::cout << "Enter your bet: ";
			std::cin >> playerBet;
			std::cin.clear();
			std::cin.ignore(10000, '\n');
			std::cout << std::endl;

			
		
		if (playerBet > playerMoney)
		{
			std::cout << "ERROR!!! You don t have that much money\n";
			
		}
		else if (playerBet > dealerMoney)
		{
			std::cout << "Warning! Bet can't be higher then dealer's money\n";
			
		}
		else
		{
			checkBet = false;
			dealerBet = playerBet;
			playerTempMoney = playerMoney;
			dealerTempMoney = dealerMoney;
			playerMoney -= playerBet;
			dealerMoney -= dealerBet;
		}
}

 void checkResult(int& _playerMoney, int& _playerTempMoney , int& _dealerMoney, int& _dealerTempMoney,
	int& _playerBet, int& _dealerBet, int& playerCards, int& dealerCards)
{
	
	
	
	if (playerCards == dealerCards && playerCards <= 21)
	{
		if (dealerCards < 21)
		{
			int dealerPickCard = (rand() % 10) + 1;
			dealerCards += dealerPickCard;
			std::cout << "Dealer picked card " << dealerPickCard << "\n"
				"\nand now has " << dealerCards << std::endl;
		}
		else
		{

			std::cout << "DRAW!" << std::endl;
			_playerMoney = _playerTempMoney;
			_dealerMoney = _dealerTempMoney;

		}
	}
		

 
	
	if (dealerCards > 21)
	{
		std::cout << "Dealer has too many points. You WIN !!!";
		_playerMoney = _playerMoney + (_dealerBet * 2);
		
	}
	if (playerCards > dealerCards && playerCards <= 21)
	{
		std::cout << "You WIN !!!";
		 _playerMoney = _playerMoney + (_dealerBet * 2);
		
	}
	if (playerCards < dealerCards && dealerCards <= 21)
	{
		std::cout << "You loose !!!";
		
		 _dealerMoney = _dealerMoney + (_playerBet * 2);
		
	}
	
}



int main()
{
	int playerMoney ;
	int dealerMoney ;
	int playerBet = 0;
	int dealerBet = 0;
	bool check = true;
	bool checkBet = true;
	bool moneyCheck = true;
	int playerTempMoney = 0;
	int dealerTempMoney = 0;
	int gameFlow = 0;
	char choice = 'a';
	
	
	
	Dealer card;

	while (moneyCheck)

	{
		playerMoney = 1000;
		dealerMoney = 1000;

	std::cout << "1. Start game\n\n"
		"2. Exit\n\n";
	std::cin >> gameFlow;

	switch (gameFlow)
	{

	case 1:
	{
		check = true;
		while (check)
		{
			checkBet = true;

			while (checkBet)
			{

				placeBet(checkBet, playerMoney, playerTempMoney,
					dealerMoney, dealerTempMoney, playerBet, dealerBet);
				
			}
			card.randomCards();

			card.playerCards();
			
				if (card.playerRandomCards == 21)
				{
					std::cout << "Congradilation! You earned max points" << std::endl;
					
				}
				else
				{ 
					while ((choice != 'n' || choice != 'N') && card.playerRandomCards <=21)
					{
						std::cout << "Hit or hold (y / n)" << std::endl;
						std::cin >> choice;
						std::cin.clear();
						std::cin.ignore(10000, '\n');
						if (choice == 'n' || choice == 'N')
							break;
						else if (choice == 'y' || choice == 'Y')
						
							
							card.drawCard();
						
						else
							std::cout << "ERROR! Wrong input!\n";
					}
					
				}
				
				if (card.playerRandomCards > 21)
				{
					dealerMoney = dealerMoney + (playerBet * 2);
					
				}
				else
				{

					card.dealerCards();
					if (card.dealerRandomCards > card.playerRandomCards)
					{
						std::cout << "Dealer don t want to pick a card this round!" << std::endl;

					}
					else
					{
						card.dealerDrawCard();
					}
					

					checkResult( playerMoney, playerTempMoney, dealerMoney, dealerTempMoney,
						playerBet, dealerBet, card.playerRandomCards, card.dealerRandomCards);
				}
			std::cout << "\n\nPlayer money: " << playerMoney;
			std::cout << "\n\nDealer money: " << dealerMoney << "\n\n\n";

			if (playerMoney <= 0)
			{
				std::cout << "Congradilations Mr. Dealer! You won\n" << std::endl;
				check = false;
				

			}
			if (dealerMoney <= 0)
			{
				std::cout << "Congradilations Mr. Player! You won\n" << std::endl;
				check = false;
				
			}
			
		}//end of while check

		break;

	}//end of case 1

	case 2:
	{
		moneyCheck = false;
		break;
	}
	default:
		std::cout << "ERROR!Wrong input!!!\n\n";
		break;


	}//end of switch
	}//end of moneyCheck while
	system("pause");


}