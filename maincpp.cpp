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

int checkHits(int& hp, int& strength, std::string& userName)
{
	hp -= strength;
	if (hp > 0)
	{
		//hp -= strength;
		std::cout << "Player " << userName << " lost " << strength << " hitpoints" << std::endl;
		std::cout << "Player " << userName << " now has " << hp << " hitpoints" << std::endl;

	}
	if (hp <= 0)
	{
		hp = 0;
		std::cout << "Player " << userName << " je mrtav!!!" << std::endl;
	}
	return hp - strength;
}

void chooseName(std::string& plOne, std::string& plTwo, std::string& plThree)
{
	
	std::cout << "Izaberite ime za prvog igraca: ";
	std::getline(std::cin, plOne);

	std::cout << "Izaberite ime za drugog igraca: ";
	std::getline(std::cin, plTwo);

	std::cout << "Izaberite ime za treceg igraca: ";
	std::getline(std::cin, plThree);
}

void move(int& x, int& y, int& velocity)
{
	x += velocity;
	y += velocity;
}

int main()
{

	
	

	Player playerOne = Player(0, 0, 10, 30);
	playerOne.strength = 12;


	Player playerTwo = Player(10, 15, 10, 30);
	playerTwo.strength = 11;

	Player playerThree = Player(20, 25, 10, 25);
	playerThree.strength = 15;

	chooseName(playerOne.userName, playerTwo.userName, playerThree.userName);


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
				checkHitChevk = false;

			else
				std::cout << "Error! Izabrali ste nepostojeceg playera!" << std::endl;
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
			checkHits(playerTwo.hp, playerOne.strength, playerTwo.userName); //checkHits(int& hp, int& strength, std::string& userName)
		}
		else if (hitCheck == 1 && toHitCheck == 3)
		{
			checkHits(playerThree.hp, playerOne.strength,  playerThree.userName);
		}
		else if (hitCheck == 2 && toHitCheck == 1)
		{
			checkHits(playerOne.hp, playerTwo.strength, playerOne.userName);
		}
		else if (hitCheck == 2 && toHitCheck == 3)
		{
			checkHits(playerThree.hp, playerTwo.strength, playerThree.userName);
		}

		else if (hitCheck == 3 && toHitCheck == 1)
		{
			checkHits(playerOne.hp, playerThree.strength, playerOne.userName);
		}
		else if (hitCheck == 3 && toHitCheck == 2)
		{
			checkHits(playerTwo.hp, playerThree.strength, playerTwo.userName);
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
	std::cout << losingPlayer1 << " and " << losingPlayer2 << " lost! Better luck next time!" << std::endl;

	// Napraviti treceg playera, te postaviti mogucnost za biranje usernamea (korisnik sam unosi 
	// username).
	// Prosiriti mogucnost damageanja playera tako da se bira koji ce kojeg udariti.

	std::cin.get();
}