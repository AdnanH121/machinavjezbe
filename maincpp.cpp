#include <iostream>
#include <string>

class Player
{

public:
	Player(int positionX, int positionY, int currentVelocity, int hitPoints)
	{
		x = positionX;
		y = positionY;
		velocity = currentVelocity;
		hp = hitPoints;
	}

	int x, y, velocity, hp, strength;
	std::string userName;

	void move()
	{
		x += velocity;
		y += velocity;
	}

	void damage(int ammount)
	{
		hp -= ammount;
	}
};


void move(int& x, int& y, int& velocity)
{
	x += velocity;
	y += velocity;
}

int main()
{

	std::string plOne =" " , plTwo = " " , plThree = " ";
	std::cout << "Izaberite ime za prvog igraca: ";
	std::getline(std::cin, plOne);

	std::cout << "Izaberite ime za drugog igraca: ";
	std::getline(std::cin, plTwo);

	std::cout << "Izaberite ime za treceg igraca: ";
	std::getline(std::cin, plThree);
	
	
	Player playerOne = Player(0, 0, 10, 30);
	playerOne.userName = plOne;
	playerOne.strength = 12;


	Player playerTwo = Player(10, 15, 10, 30);
	playerTwo.userName = plTwo;
	playerTwo.strength = 11;

	Player playerThree = Player(20, 25, 10, 25);
	playerThree.userName = plThree;
	playerThree.strength = 15;



	playerOne.move();
	playerTwo.move();
	playerThree.move();

	std::string losingPlayer1;
	std::string losingPlayer2;
	std::string winningPlayer;
	bool bigCheck = true;
	
	while (bigCheck == true)
	{
		bool checkHitChevk2 = true;
		bool checkHitChevk1 = true;
		bool checkHitChevk = true;
		int hitCheck = 0, toHitCheck = 4;
		
			while (checkHitChevk == true)
			{
				std::cout << "Choose which player is hitting(player 1, 2 or 3): ";
				std::cin >> hitCheck;
				
				std::cout << std::endl;
                std::cin.ignore(1000, '\n');
				std::cin.clear();
				if (hitCheck >= 1 && hitCheck <= 3)
					checkHitChevk = false ;

				else
					std::cout << "Error! Izabrali ste nepostojeceg playera!" <<std::endl;
			}
			
			while (checkHitChevk2 == true)
			{
				std::cout << "Choose  player to  hit: ";
				std::cin >> toHitCheck;
				std::cout << std::endl;

				std::cin.ignore(1000, '\n');
				std::cin.clear();
				if ((toHitCheck >= 1 && toHitCheck <= 3) && hitCheck != toHitCheck)
				{
					checkHitChevk2 = false;
					
				}
				else if (hitCheck == toHitCheck)

					std::cout << "Error! Player ne moze udariti sam sebe!" << std::endl;

				else

					std::cout << "Error! Pokusavate udariti nepostojeceg playera!" << std::endl;

			}

		

		if (hitCheck == 1 && toHitCheck == 2)
		{
			playerTwo.damage(playerOne.strength);
			std::cout << "Player two lost "<< playerOne.strength<<" hitpoints" << std::endl;
			std::cout << "Player two now has " << playerTwo.hp << " hitpoints" << std::endl;
		}
		else if (hitCheck == 1 && toHitCheck == 3)
		{
			playerThree.damage(playerOne.strength);
			std::cout << "Player three lost " << playerOne.strength << " hitpoints" << std::endl;
			std::cout << "Player three now has " << playerThree.hp << " hitpoints" << std::endl;
		}
		else if (hitCheck == 2 && toHitCheck == 1)
		{
			playerOne.damage(playerTwo.strength);
			std::cout << "Player one lost " << playerTwo.strength << " hitpoints" << std::endl;
			std::cout << "Player one now has " << playerOne.hp << " hitpoints" << std::endl;
		}
		else if (hitCheck == 2 && toHitCheck == 3)
		{
			playerThree.damage(playerTwo.strength);
			std::cout << "Player three lost " << playerTwo.strength << " hitpoints" << std::endl;
			std::cout << "Player three now has " << playerThree.hp << " hitpoints" << std::endl;
		}
		else if (hitCheck == 3 && toHitCheck == 1)
		{
			playerOne.damage(playerThree.strength);
			std::cout << "Player one lost " << playerThree.strength << " hitpoints" << std::endl;
			std::cout << "Player one now has " << playerOne.hp << " hitpoints" << std::endl;
		}
		else if (hitCheck == 3 && toHitCheck == 2)
		{
			playerTwo.damage(playerThree.strength);
			std::cout << "Player two lost " << playerThree.strength << " hitpoints" << std::endl;
			std::cout << "Player two now has " << playerTwo.hp << " hitpoints" << std::endl;
		}
		if (playerOne.hp <= 0 && playerTwo.hp <= 0)
			bigCheck = false;
		if (playerTwo.hp <= 0 && playerThree.hp <= 0)
			bigCheck = false;
		if (playerThree.hp <= 0 && playerOne.hp <= 0)
			bigCheck = false;
	}
		std::cout << "Player one hitpoints: " << playerOne.hp << std::endl;
		std::cout << "Player two hitpoints: " << playerTwo.hp << std::endl;
		std::cout << "Player three hitpoints: " << playerThree.hp << std::endl;
		std::cout << std::endl;

		if (playerOne.hp <= 0 && playerTwo.hp <= 0)
		{
			losingPlayer1 = playerOne.userName;
			losingPlayer2 = playerTwo.userName;
			winningPlayer = playerThree.userName;
		}
		else if (playerTwo.hp <= 0 && playerThree.hp <= 0)
		{
			losingPlayer1 = playerThree.userName;
			losingPlayer2 = playerTwo.userName;
			winningPlayer = playerOne.userName;
		}
		else if (playerOne.hp <= 0 && playerThree.hp <= 0)
		{
		
			losingPlayer1 = playerThree.userName;
			losingPlayer2 = playerOne.userName;
			winningPlayer = playerTwo.userName;
		}
	

	std::cout << winningPlayer << " wins! Congratulations!" << std::endl;
	std::cout << losingPlayer1 << " "<< losingPlayer2<<" lost! Better luck next time bois!" << std::endl;

	// Napraviti treceg playera, te postaviti mogucnost za biranje usernamea (korisnik sam unosi 
	// username).
	// Prosiriti mogucnost damageanja playera tako da se bira koji ce kojeg udariti.

	std::cin.get();
}