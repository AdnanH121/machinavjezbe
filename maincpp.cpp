#include <iostream>
#include <string>

class Player
{
public:

	Player(int basicAttack, int specialAttack, int numOfSpAtt, int specialAttackCounter,int specialAbility, int hitPoints)
	{
		 x = basicAttack;
		 y = specialAttack;
		 c = numOfSpAtt;
		 a = specialAttackCounter;
		 b = specialAbility;
		 hp = hitPoints;
		
	}

	int x, y,a,b,c, hp;
	std::string userName;

	void basicDamage(int& hp,int&  x)
	{
		hp -= x;
	}

	void specialDamage(int& hp, int& y )
	{
		hp -= y;
			
	}
};

void playerName(std::string& plName)
{

	
	std::getline(std::cin, plName);

}

int attackFunc(std::string& userNameAttacker, std::string& userNameDamaged, int& basicAttack, int& specialAttack, int& numOfSpAtt,
	int& specialAttackCounter, int& specialAbility, int& hitPoints)
{
     
		int attack;
		std::cout << "Igrac " << userNameAttacker << " napada igraca " << userNameDamaged << std::endl;
		std::cout << std::endl;
		
		
		if (hitPoints <= 0)
		{
			std::cout << "Igrac " << userNameDamaged << " je mrtav!!!\n\n" << std::endl;

		}

		else if (hitPoints > 0 && numOfSpAtt != 0)
		{
			std::cout << userNameAttacker << " izaberite napad \n"
				"\n 1.Osnovni napad\n"
				"\n 2.Specijalni napad\n\n";
			std::cin >> attack;
			std::cin.ignore(1000, '\n');
			std::cin.clear();
			switch (attack)
			{
			case 1:
			{
				std::cout << "Igrac " << userNameAttacker << " napada osnovnim napadom\n\n" << std::endl;
				std::cout << userNameDamaged << " je izgubio " << basicAttack << " zivotnih poena!!! \n\n" << std::endl;
				
				std::cout << "Igrac " << userNameDamaged << " sada ima " << hitPoints - basicAttack << " zivotna poena!!!\n\n" << std::endl;
				specialAttackCounter += 20;
				return hitPoints -= basicAttack;
				
				break;
			}

			case 2:
			{
				std::cout << "Igrac " << userNameAttacker << " napada specijalnim napadom\n\n" << std::endl;
				std::cout << userNameDamaged << " je izgubio " << specialAttack << " zivotnih poena!!!\n\n " << std::endl;
				std::cout << "Igrac " << userNameDamaged << " sada ima " << hitPoints - specialAttack << " zivotna poena!!!\n\n" << std::endl;
				specialAttackCounter += 50;
				numOfSpAtt--;
				
				return hitPoints -= specialAttack;
				
				break;
			}

			default:
			{
				std::cout << "Izabrali ste nepostojeci napad!!!!\n\n" << std::endl;
				break;
			}
			}

		}
		else if (hitPoints > 0 && numOfSpAtt  == 0)
		{
			std::cout << "Igrac " << userNameAttacker << " napada osnovnim napadom\n\n" << std::endl;
			std::cout << userNameDamaged << " je izgubio " << basicAttack << " zivotnih poena!!! \n\n" << std::endl;
			std::cout << "Igrac " << userNameDamaged << " sada ima " << hitPoints - basicAttack << " zivotna poena!!!\n\n" << std::endl;
			specialAttackCounter += 20;
			hitPoints -= basicAttack;
			


		}
		if (specialAttackCounter >= 100)
		{
			numOfSpAtt++;
			std::cout << " Upravo ste zaradili novi specijalni napad\n\n" << std::endl;
			specialAttackCounter = 0;
		}
	
}//end of func


int chooseFirstPlayer(int choose)
{
	switch (choose)
	{
	case 1:
	{
		std::cout << "Vitez je u napadu!\n\n" << std::endl;
		break;
	}
	case 2:
	{
		std::cout << "Strijelac je u napadu\n\n" << std::endl;
		break;
	}
	case 3:
	{
		std::cout << "Carobnjak je u napadu!\n\n" << std::endl;
		break;
	}

	default:
	{
		std::cout << "Error. Izabrali ste nepostojeceg playera!!!\n\n" << std::endl;
		break;
	}
	}//end of switch
	return choose;
}

int chooseWhoToAttack(int choosen)
{
	switch (choosen)
	{
	case 1:
	{
		std::cout << "Napada Viteza!\n\n" << std::endl;

		break;
	}
	case 2:
	{
		std::cout << "Napada strijelca!\n\n" << std::endl;
		break;
	}
	case 3:
	{
		std::cout << "Napada carobnjaka!\n\n" << std::endl;
		break;
	}

	default:
	{
		std::cout << "Error. Izabrali ste nepostojeceg playera!!!\n\n" << std::endl;
		break;
	}
	
	}//end of switch
	return choosen;
}

int main()
{
	std::string losingPlayer1;
	std::string losingPlayer2;
	std::string winningPlayer;

	std::cout << "Izaberite vaseg karaktera: \n"
		" 1. Vitez - unistava neprijatelje svojim ostrim macem i hrabrim srcem\n"
		" \nZivotna energija 300 poena\n "
		" \nOsnovni napad macem - damage 30 HP\n"
		" \nSpecijalni napad macem [ GNJEV ZMAJA ] - damage 120 HP\n "
		" \nSpecijalna sposobnost [ SNAGA VITEZA ] - blokira neprijateljski napad \n\n"

		" \n2. Strijelac - svojom strijelom neprijatelje pogadja u srce\n"
		" \nZivotna energija 320 poena\n "
		" \nOsnovni napad strijelom- damage 25 HP\n"
		" \nSpecijalni napad [ VATRENA STRIJELA ] - damage 100 HP\n "
		" \nSpecijalna sposobnost [ DVOJNA STRIJELA ] - uveca damage jednog osnovnog napada za 100% \n\n"

		" \n2. Carobnjak - majstor magicnih vjestina \n"
		" \nZivotna energija 360 poena\n "
		" \nOsnovni napad Carobna kugla- damage 20 HP\n"
		" \nSpecijalni napad  [ Kugla unistenja ] - damage 80 HP\n "
		" \nSpecijalna sposobnost [ Regeneracija ] - regenerira zivotnu energiju za 60 poena \n\n";

	Player playerOne = Player(30, 120, 1, 0, 1, 300);//(int basicAttack, int specialAttack,int numOfSpAtt,int specialAttackCounter,int specialAbility, int hitPoints)


	Player playerTwo = Player(25, 100, 1, 0, 1, 320);


	Player playerThree = Player(20, 80, 1, 0, 1, 260);


	std::cout << "Izaberite ime za Vitez karaktera: ";
	playerName(playerOne.userName);
	std::cout << std::endl;
	std::cout << playerOne.userName << " je izabrao/la Viteza!!!\n\n" << std::endl;
	std::cout << std::endl;

	std::cout << "Izaberite ime za Strijelac karaktera: ";
	playerName(playerTwo.userName);
	std::cout << std::endl;
	std::cout << playerTwo.userName << " je izabrao/la Strijelca!!!\n\n" << std::endl;
	std::cout << std::endl;

	std::cout << "Izaberite ime za Carobnjak karaktera: ";
	playerName(playerThree.userName);
	std::cout << std::endl;
	std::cout << playerThree.userName << " je izabrao/la Carobnjaka!!!\n\n" << std::endl;
	std::cout << std::endl;


	int startPlayer = 1;
	int attackedPlayer = 2;
	bool endLoop = true;
	bool bigCheck = true;
	while(bigCheck)
{
	do
	{

		std::cout << "Izaberite igraca koji napada\n"
			"1.Vitez\n"
			"2.Strijelac\n"
			"3.Carobnjak\n";
		std::cout << std::endl;
		std::cin >> startPlayer;
		std::cin.ignore(1000, '\n');
		std::cin.clear();
		std::cout << std::endl;
		if (startPlayer > 0 && startPlayer < 4)
		{
			chooseFirstPlayer(startPlayer);
			endLoop = false;
		}
	} while (endLoop == true);

	endLoop = true;
	do
	{

		std::cout << "Izaberite igraca kojeg napada\n"
			"1.Vitez\n"
			"2.Strijelac\n"
			"3.Carobnjak\n";
		std::cout << std::endl;
		std::cin >> attackedPlayer;
		std::cin.ignore(1000, '\n');
		std::cin.clear();
		std::cout << std::endl;
		if (startPlayer == attackedPlayer)
		{
			std::cout << "Karakter ne moze napasti sam sebe!!!\n" << std::endl;

		}
		else
		{
			if (attackedPlayer > 0 && attackedPlayer < 4)
			{
				chooseWhoToAttack(attackedPlayer);
				endLoop = false;
			}
		}
	} while (endLoop == true);

	//int attackFunc(std::string& userNameAttacker, std::string& userNameDamaged, int& basicAttack, int& specialAttack,int& numOfSpAtt,
			//int& specialAttackCounter, int& specialAbility, int& hitPoints)
		//Player playerOne = Player(30, 120, 1, 1, 0, 300);
		//Player playerTwo = Player(25, 100, 1, 2, 0, 320);
		//Player playerThree = Player(20, 80 ,1, 1, 0, 1, 260);
		/*x = basicAttack;
		y = specialAttack;
		c = numOfSpAtt;
		a = specialAttackCounter;
		b = specialAbility;
		hp = hitPoints;*/
	if (startPlayer == 1 && attackedPlayer == 2)
	{

		attackFunc(playerOne.userName, playerTwo.userName, playerOne.x, playerOne.y,
		playerOne.c, playerOne.a, playerTwo.b, playerTwo.hp);
	}
	else if (startPlayer == 1 && attackedPlayer == 3)
	{
		attackFunc(playerOne.userName, playerThree.userName, playerOne.x, playerOne.y,
			playerOne.c, playerOne.a, playerThree.b, playerThree.hp);
	}

	else if (startPlayer == 2 && attackedPlayer == 1)
	{
		attackFunc(playerTwo.userName, playerOne.userName, playerTwo.x, playerTwo.y,
			playerTwo.c, playerTwo.a, playerOne.b, playerOne.hp);
	}

	else if (startPlayer == 2 && attackedPlayer == 3)
	{
		attackFunc(playerTwo.userName, playerThree.userName, playerTwo.x, playerTwo.y,
			playerTwo.c, playerTwo.a, playerThree.b, playerThree.hp);
	}
	else if (startPlayer == 3 && attackedPlayer == 1)
	{
		attackFunc(playerThree.userName, playerOne.userName, playerThree.x, playerThree.y,
			playerThree.c, playerThree.a, playerOne.b, playerOne.hp);
	}
	else if (startPlayer == 3 && attackedPlayer == 2)
	{
		attackFunc(playerThree.userName, playerTwo.userName, playerThree.x, playerThree.y,
			playerThree.c, playerThree.a, playerTwo.b, playerTwo.hp);
	}

	
	if (playerOne.hp <= 0 && playerTwo.hp <= 0)
		bigCheck = false;
	if (playerTwo.hp <= 0 && playerThree.hp <= 0)
		bigCheck = false;
	if (playerThree.hp <= 0 && playerOne.hp <= 0)
		bigCheck = false;

}//end of bigCheck

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


std::cout << winningPlayer << " je pobjednik! Cestitamo\n\n" << std::endl;
std::cout << losingPlayer1 << " " << losingPlayer2 << " su gubitnici! Vise srece drugi put\n" << std::endl;


	system("pause");
}