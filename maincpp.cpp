#include <iostream>
#include<string>
#include<vector>
#include<cstdlib>
#include<ctime>

class Card
{
  public:
	  int randomCard;
	  
	  int randomGivenCards()
	  {
		  int randomCard1;
		  int randomCard2;
		  int c;
		  bool check = true;
		  srand(time(NULL));
		  while (check)
		  {
			  randomCard1 = (rand() % 13) + 1;
			  
			  randomCard2 = (rand() % 13) + 1;
			  
			  c = randomCard1 + randomCard2;
			  if (c <= 21)
			  {
				  std::cout << randomCard1 << std::endl;
				  std::cout << randomCard2 << std::endl;
				  check = false;
				  return c;
			  }

		  }
		  return c;
	  }
	

	  void drawCard(char choice)
	  {
		  

		  bool choiceCheck = true;
		  while (choiceCheck)
		  {
			  

			  if (choice == 'n' || choice == 'N')
			  {
				  choiceCheck = false;
				  break;
			  }
			  else if (choice == 'y' || choice == 'Y')
			  {
				  
                  randomCard = (rand() % 13) + 1;
				  std::cout << "Player Card: " << randomCard << std::endl;
				  return;
			  }

			  else
			  {
				  std::cout << "ERROR.Wrong input, choose beetwen y or n!" << std::endl;
				  return;
			  }
		  }//End of while loop
		  
	  }//end of drawCard

 private:
	std::string _type;
	int _value, _position;

};

int randomGivenCards1()
{
	
	int randomCard3;
	int randomCard4;
	int c;
	bool check = true;
	
	while (check)
	{
		randomCard3 = (rand() % 13) + 1;

		randomCard4 = (rand() % 13) + 1;

		c = randomCard3 + randomCard4;
		if (c <= 21)
		{
			std::cout << randomCard3 << std::endl;
			std::cout << randomCard4 << std::endl;
			check = false;
			return c;
		}
	}
	return c;
}


int main()
{
	bool inputCheck = true;
	bool mainCheck = true;
	bool playerInputCheck = true;
	bool dealerInputCheck = true;
	bool checkBet = true;
	char choice;
	int playerRandomCards = 0;
	int dealerRandomCards = 0;
	int playerMoney = 1000;
	int dealerMoney = 1000;
	int playerMoneyDraw = 0;
	int dealerMoneyDraw = 0;
	int playerBet = 0;
	int dealerBet = 0;
	int gameFlow = 0;
	Card card;
	
	
	while (inputCheck)
	{
		std::cout << "1. Start game\n\n"
			"2. Exit\n\n";
		std::cin >> gameFlow;

		switch (gameFlow)
		{
		case 1:
		{

			int& playerRandomCard = card.randomCard;
			
			while (mainCheck)
			{
				dealerInputCheck = true;
				playerInputCheck = true;

				checkBet = true;
				

				while (checkBet)
				{ 
					std::cout << "Enter your bet: ";
					std::cin >> playerBet;
					std::cin.clear();
					std::cin.ignore(10000, '\n');
					std::cout << std::endl;
					if (playerBet > playerMoney)
					{
						std::cout << "ERROR!!! You don t have that much money\n";
					}
					else
						checkBet = false;
					if (playerBet <= dealerMoney)
					{
						dealerBet = playerBet;
					}
					else
					dealerBet = dealerMoney;
					
					playerMoneyDraw = playerMoney;
					dealerMoneyDraw = dealerMoney;
					playerMoney -= playerBet;
					dealerMoney -= dealerBet;
				}

				playerRandomCards = card.randomGivenCards();
				dealerRandomCards = randomGivenCards1();




				std::cout << "Player cards: " << playerRandomCards;
				std::cout << "\nDealer cards: " << dealerRandomCards << "\n";

				while (playerInputCheck)
				{
					std::cout << "Hit card(y) or stand(n)" << std::endl;
					std::cin >> choice;
					std::cin.clear();
					std::cin.ignore(10000, '\n');
					if (choice == 'n' || choice == 'N')
					{
						playerInputCheck = false;
						break;
					}
					else if (choice == 'y' || choice == 'Y')
					{

						card.drawCard(choice);

						playerRandomCards += playerRandomCard;
						std::cout << "\nPlayer cards after draw " << playerRandomCards << std::endl;
						if (playerRandomCards == 21)
						{
							std::cout << "Congradilations. You earned max points!!!" << std::endl;
							playerInputCheck = false;
							break;
						}
						if (playerRandomCards > 21)
						{
							std::cout << "You lost!" << std::endl;
							//playerMoney -= playerBet;
							dealerMoney =dealerMoney + (playerBet * 2);
							playerInputCheck = false;
							dealerInputCheck = false;
							break;
						}

					}
					else
						std::cout << "ERROR.Wrong input!" << std::endl;


				}// end of playerInputCheck

				while (dealerInputCheck)
				{

					if (dealerRandomCards == playerRandomCards)
					{
						std::cout << "DRAW!" << std::endl;
						
						playerMoney = playerMoneyDraw;
						dealerMoney = dealerMoneyDraw ;

						break;
					}

					
					if (dealerRandomCards >= 18 && dealerRandomCards <= 21 && dealerRandomCards > playerRandomCards)
					{
						std::cout << "Dealer don t want to draw a card this round!" << std::endl;
						break;
					}
				  if (dealerRandomCards < playerRandomCards) 
					{
						
						while (dealerRandomCards < playerRandomCards)
						{
							int dealerRandomCard = (rand() % 13) + 1;
							std::cout << "Dealer pick card " << dealerRandomCard  << std::endl;
							dealerRandomCards += dealerRandomCard;
							std::cout << "\nDealer cards after draw " << dealerRandomCards << std::endl;
							if (dealerRandomCards > 21)
							{
								std::cout << "Dealer lost this round!!!" << std::endl;
								playerMoney = playerMoney + (dealerBet * 2);
								break;
							}
							else if (dealerRandomCards > playerRandomCards)
							{
								std::cout << "Dealer won this round!" << std::endl;
								dealerMoney = dealerMoney + (playerBet * 2);
								break;
							}
							
							
							
						}
						break;

					}
					if (dealerRandomCards > playerRandomCards && dealerRandomCards <= 21)
					{
						std::cout << "Dealer won this round!" << std::endl;
						dealerMoney = dealerMoney + (playerBet * 2);
						break;
					}
					if (playerRandomCards > dealerRandomCards )
					{
						std::cout << "Player won this round!\n";
						playerMoney = playerMoney + (dealerBet * 2);
						break;
						//dealerMoney -= dealerBet;

					}
				}//end of dealerInputCheck

				std::cout << "Player money: " << playerMoney;
				std::cout << "\n\nDealer money: " << dealerMoney << "\n\n\n";
				

				if (playerMoney <= 0)
				{
					std::cout << "Congradilations Mr. Dealer! You won\n" << std::endl;
					mainCheck = false;

				}
				if (dealerMoney <= 0)
				{
					std::cout << "Congradilations Mr. Player! You won\n" << std::endl;
					mainCheck = false;
				}

			}//end of main while loop

			break;

		}//case 1 end

		case 2:
			inputCheck = false;
			break;

		default:
			std::cout << "ERROR! Wrong input!!!\n\n";
			break;


		}//end of switch
	}//end of input check
	system("pause");
}