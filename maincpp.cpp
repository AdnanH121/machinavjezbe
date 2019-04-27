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

	std::string getPrivateString()
	{
		return _privateString;
	}

	void setPrivateString(std::string stringParm)
	{
		_privateString = stringParm;
	}

private:

	std::string _privateString;

protected:

	std::string _protectedString;


};


void move(int& x, int& y, int& velocity)
{
	x += velocity;
	y += velocity;
}

int main()
{
	int number = 5;
	int& tracker = number;
	int* ptr = &number;
	std::string* stringptr;
	std::string someWord = "Nesto";
	stringptr = &someWord;
	int** doubleptr = &ptr;

	number = 9;
	std::cout << "Hello world" << std::endl;
	std::cout << "number: " << number << std::endl;
	std::cout << "number: " << tracker << std::endl;
	std::cout << "ptr: " << ptr << std::endl;
	std::cout << "stringptr: " << stringptr << std::endl;

	std::cout << "derefference stringptr: " << *stringptr << std::endl;
	*stringptr = "nesto drugo";
	Player playerOne = Player(0, 0, 10, 30);
	playerOne.userName = "Chaos";
	playerOne.strength = 12;


	Player playerTwo = Player(10, 15, 10, 30);
	playerTwo.userName = "robi256";
	playerTwo.strength = 11;

	playerOne.move();
	playerTwo.move();

	playerOne.setPrivateString("Ja sam privatan!");

	std::cout << playerOne.getPrivateString() << std::endl;

	std::string losingPlayer;
	std::string winningPlayer;

	std::cout << "derefference stringptr take 2: " << *stringptr << std::endl;
	std::cout << "doubleptr ptr address: " << *doubleptr << std::endl;
	std::cout << "doubleptr ptr address: " << **doubleptr << std::endl;
	while (playerOne.hp > 0 && playerTwo.hp > 0)
	{
		int check;
		std::cout << "Choose which player you want to hit: ";
		std::cin >> check;
		std::cout << std::endl;

		std::cin.ignore(1000, '\n');
		std::cin.clear();
		switch (check)
		{
		case 1:
			playerOne.damage(playerTwo.strength);
			std::cout << "Player one lost 5 hitpoints" << std::endl;
			break;
		case 2:
			playerTwo.damage(playerOne.strength);
			std::cout << "Player two lost 5 hitpoints" << std::endl;
			break;
		default:
			break;
		}

		std::cout << "Player one hitpoints: " << playerOne.hp << std::endl;
		
			

			
			std::cout << "Player two hitpoints: " << playerTwo.hp << std::endl;
		std::cout << std::endl;

		if (playerOne.hp <= 0)
		{
			losingPlayer = playerOne.userName;
			winningPlayer = playerTwo.userName;
		}
		else if (playerTwo.hp <= 0)
		{
			losingPlayer = playerTwo.userName;
			winningPlayer = playerOne.userName;
		}
	}

	std::cout << winningPlayer << " wins! Congratulations!" << std::endl;
	std::cout << losingPlayer << " lost! Better luck next time!" << std::endl;

	// Napraviti treceg playera, te postaviti mogucnost za biranje usernamea (korisnik sam unosi 
	// username).
	// Prosiriti mogucnost damageanja playera tako da se bira koji ce kojeg udariti.

	std::cin.get();
}