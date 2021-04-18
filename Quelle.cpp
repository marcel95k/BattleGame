/* PROJECT BY MARCEL KIEHTREIBER
   _____________________________________________________________________________

   Short description:

   A set of maximum 4 players is going to fight each other with their
   characters to earn points. Each player is able to increase the character's
   attack/defend skills. The player with the hightest amount of points at the
   end wins the game.

   CHARACTERS:

   HEAVY:

   ATTACK: high (20 - 35) DEFEND: normal (15 - 30) PRECISION: low (1-5/3)

   DEFENDER:

   ATTACK: low (10 - 25) DEFEND: high (20 - 35) PRECISION: normal (1-3/2)

   PRECISE:

   ATTACK: low (10 - 25) DEFEND: normal (15 - 30) PRECISION: hig (1-2/1)

   INVADER:

   ATTACK: high (20 - 35) DEFEND: low (10 - 25) PRECISION: normal (1-3/2)

   Precision is calculated randomly. A smaller range between the numbers means
   a higher hitrate (e.g.: low PRECISION[1-5] number must be 3 to hit. The
   attack/defend values are a random number between the two numbers and are
   calculated randomly.

   INCREASING ATTACK/DEFEND SKILLS: (e.g.: HEAVY)

   Default: ATTACK (20 - 35) DEFEND (15 - 30)

   First increase: (either ATTACK OR DEFEND/NEVER BOTH IN ONE DRAW) ATTACK 
   (25 - 30) DEFEND (20 - 30)

   Second increase: (either ATTACK OR DEFEND/NEVER BOTH IN ONE DRAW) ATTACK
   (25 - 40) DEFEND (20 - 35)

   etc..
   _____________________________________________________________________________

   Started: 10-04-2021 Last edit: 13-04-2021

   TO DO LIST:

		1. Finish scenarios 3 - 4 for label ZEROattackONE. (DONE)
		2. Finish scenarios 1 - 4 for label ONEattackZERO. (DONE)

   FUTURE TO DO'S:

		1. Make colored signs/characters for each player. (NOT Done)
		2. Make COINS for players. (Coins are used for increasing attack/defend skills. For every SUCCESSFULL attack the attacking player robs coins from the defending player.

   _____________________________________________________________________________
 */
#include<iostream>
#include<time.h>
#include<conio.h>
#include<vector>
 // #include<stdlib.h>

using namespace std;


/*
Heavy
Defender
Precise 
Invader

			One main class (classWarriror)
									|
									|-> Heavy (
*/

class classWarrior
{
private:
	int lifepoints = 100;
	int coins = 0;
	
public:
	int setLifepoints(int value);
	int getLifepoints();
	int setCoins(int value);
	int getCoins();
	


};

int classWarrior::setLifepoints(int value)
{

	return lifepoints;
}
int classWarrior::getLifepoints()
{
	return lifepoints;
}
int classWarrior::setCoins(int value)
{

	return coins;
}
int classWarrior::getCoins()
{
	return coins;
}


class classHeavy
{
private:
	string name;
	int atkMin = 20;
	int atkMax = 35;

	int defMin = 15;
	int defMax = 30;

	int precMin = 1;
	int precMax = 5;
	int precHit = 3;
public:
	
	int getAtkMin() { return atkMin; };
	int getAtkMax() { return atkMax; };
	int getDefMin() { return defMin; };
	int getDefMax() { return defMax; };
	int getPrecMin() { return precMin; };
	int getPrecMax() { return precMax; };
	int getPrecHit() { return precHit; };
	string getName() { return name; };
	void setName(string value)
	{ 
		name = value;
	}

};
class classDefender : public classWarrior
{
private:
	string name;
	int atkMin = 10;
	int atkMax = 25;

	int defMin = 20;
	int defMax = 35;

	int precMin = 1;
	int precMax = 3;
	int precHit = 2;
public:
	int getAtkMin() { return atkMin; };
	int getAtkMax() { return atkMax; };
	int getDefMin() { return defMin; };
	int getDefMax() { return defMax; };
	int getPrecMin() { return precMin; };
	int getPrecMax() { return precMax; };
	int getPrecHit() { return precHit; };
	string getName() { return name; };
	void setName(string value) { name = value; };

};
class classScout : public classWarrior
{
private:
	string name;
	int atkMin = 10;
	int atkMax = 25;

	int defMin = 15;
	int defMax = 30;

	int precMin = 1;
	int precMax = 2;
	int precHit = 1;
public:
	int getAtkMin() { return atkMin; };
	int getAtkMax() { return atkMax; };
	int getDefMin() { return defMin; };
	int getDefMax() { return defMax; };
	int getPrecMin() { return precMin; };
	int getPrecMax() { return precMax; };
	int getPrecHit() { return precHit; };
	string getName() { return name; };
	void setName(string value) { name = value; };
};
class classInvader : public classWarrior
{
private:
	string name;
	int atkMin = 20;
	int atkMax = 35;

	int defMin = 10;
	int defMax = 25;

	int precMin = 1;
	int precMax = 3;
	int precHit = 2;
public:
	int getAtkMin() { return atkMin; };
	int getAtkMax() { return atkMax; };
	int getDefMin() { return defMin; };
	int getDefMax() { return defMax; };
	int getPrecMin() { return precMin; };
	int getPrecMax() { return precMax; };
	int getPrecHit() { return precHit; };
	string getName() { return name; };
	void setName(string value) { name = value; };
};


void createObjects(int valueAmount/*vector <classWarrior> *objectVector*/)
{
	classHeavy objectHeavy;
	classDefender objectDefender;
	classScout objectScout;
	classInvader objectInvader;
	/*
	string heavyTaken = ": " + objectHeavy().getName();
	string defenderTaken = ": " + objectHeavy().getName();
	string scoutTaken = ": " + objectHeavy().getName();
	string invaderTaken = ": " + objectHeavy().getName();
	*/
	vector <string> vectorNames;
	for (int x = 0; x < valueAmount; x++)
	{
		string inputName;
		cout << "\nPlease type in a name for your character: ";
		cin >> inputName;
		vectorNames.push_back(inputName);
	}
	int takenH = 0;
	int takenD = 0;
	int takenS = 0;
	int takenI = 0;
	for(int x=0; x<=valueAmount; x++)
	{

		int inputChar = 0;
		cout << "\nClass: Heavy (1): " << objectHeavy.getName();
		cout << "\nClass: Defender (2): " << objectDefender.getName();
		cout << "\nClass: Scout (3): " << objectScout.getName();
		cout << "\nClass: Invader (4): " << objectInvader.getName();
		cout << "\n\nChoose your character: ";
		cin >> inputChar;
		if (inputChar == 1 && takenH==0)
		{
			objectHeavy.setName(vectorNames.at(x));
			takenH = 1;
		}
		else
		{
			cout << "This character is already taken, please choose another one that's available.";
			x--;
		}
		if (inputChar == 2 && takenD ==0)
		{
			objectDefender.setName(vectorNames.at(x));
			takenD = 1;
		}
		else
		{
			cout << "This character is already taken, please choose another one that's available.";
			x--;
		}
		if (inputChar == 3 && takenD ==0)
		{
			objectScout.setName(vectorNames.at(x));
			takenS = 1;
		}
		else
		{
			cout << "This character is already taken, please choose another one that's available.";
			x--;
		}
		if (inputChar == 4 && takenI ==0)
		{
			objectInvader.setName(vectorNames.at(x));
			takenI = 1;
		}
		else
		{
			cout << "This character is already taken, please choose another one that's available.";
			x--;
		}
	

		/*
	
		
		
		for (y = 0; y < 4; y++)
		{
			cout << chosenCharacterString[y] << "\t" << characterString[y] << "\033[m\n"; // Displaying the list of playercharacters.
		}
		
		//classWarrior object(valueVector->at(x));
		//objectVector->push_back(object);




		vector <string> vectorNames;
		vector <classWarrior> vectorObjects;
		//vectorObjects.push_back(objectWarrior);
		//vectorObjects.push_back(objectHeavy);
		//vectorObjects.push_back(objectDefender);



		// FOR DEBUGGING
		//cout << "\tShowing name of object " << objectVector->at(x).getName();
		*/
	}


}



int main()
{
input:

	vector <string> vectorNames;
	vector <classWarrior> vectorObjects;
	//vectorObjects.push_back(objectWarrior);


	/*
	vectorObjects.push_back(objectHeavy);
	vectorObjects.push_back(objectDefender);
	vectorObjects.push_back(objectScout);
	vectorObjects.push_back(objectInvader);
	*/
	int inputAmount;
	cout << "How many players do you want? (max. 4)\n";
	cin >> inputAmount;
	if (inputAmount <= 4 && inputAmount > 1)
	{
		createObjects(inputAmount /*&vectorObjects*/);
	}
	else
	{
		goto input;
	}
	
	



















	// Random attack values
	int heavyAttack_v1 = 35;
	int heavyAttack_v2 = 20;

	int defenderAttack_v1 = 25;
	int defenderAttack_v2 = 10;

	int preciseAttack_v1 = 25;
	int preciseAttack_v2 = 10;

	int invaderAttack_v1 = 35;
	int invaderAttack_v2 = 20;

	// Random defend values
	int heavyDefend_v1 = 30;
	int heavyDefend_v2 = 15;

	int defenderDefend_v1 = 35;
	int defenderDefend_v2 = 20;

	int preciseDefend_v1 = 30;
	int preciseDefend_v2 = 15;

	int invaderDefend_v1 = 25;
	int invaderDefend_v2 = 10;

	// Character values
	int heavyAttack;
	int heavyDefend;
	int heavyPrecise;

	int defenderAttack;
	int defenderDefend;
	int defenderPrecise;

	int preciseAttack;
	int preciseDefend;
	int precisePrecise;

	int invaderAttack;
	int invaderDefend;
	int invaderPrecise;

	// Default declarations
	vector < int >roundCounterVector; // Declaring the vector "roundCounterVector" for round counter.
	vector < int >playerLifepointsVector; // Declaring the vector "playerLifepointsVector" for the player lifepoints.
	vector < int >playerNumberVector; // Declaring the vector "playerVector" for the players as numbers.
	vector < string > playerVector; // Declaring the vector "playerVector" for the players as strings.
	vector < string > playerChar = { "\033[31m-\033[m", "\033[32m-\033[m", "\033[33m-\033[m", "\033[34m-\033[m", "\033[35m-\033[m", "\033[36m-\033[m" };	// Vector "playerChar" for defining�the sign/characters of each player. 
	string characterString[4] = { "\033[32m1. HEAVY \t- (ATTACK: HIGH/ DEFEND: NORMAL/ PRECISION: LOW)\033[m", "\033[35m2. DEFENDER \t- (ATTACK: LOW/ DEFEND: HIGH/ PRECISION: NORMAL)\033[m", "\033[36m3. PRECISE \t- (ATTACK: LOW/ DEFEND: LOW/ PRECISION: HIGH)\033[m", "\033[33m4. INVADER \t- (ATTACK: HIGH/ DEFEND: LOW/ PRECISION: NORMAL)\033[m" }; // String array for the 4 character names.
	string chosenCharacterString[4] = { " ", " ", " ", " " }; // Stringarray for chosen characters.
	int damage;
	char decision; // Used for user decisions.
	int inputValue; // Used for user input.
	int x; // Used as variable for FOR-LOOPS.
	int y; // Same as for INT X.
	int playerAmount; // Number of total amount of players.
	int counter; // Used as round counter.
	// DEL1

	// INITIALISATION SECTION START

amountInput:

	// SECTION FOR CHOOSING THE AMOUNT OF PLAYERS AND TYPING IN PLAYERNAMES.

	printf("How many players are going to participate? (max. 4 players): ");
	cin >> playerAmount; // Enter the total amount of players.

	if (playerAmount > 4)
	{
		system("cls");
		printf("Enter a value lower than or equal to 4!\n");
		goto amountInput; // User will be sent back to "amountInput" if the typed in value is greater than 4.
	}

	if (playerAmount < 2)
	{
		system("cls");
		printf("At leat 2 players need to participate! Enter a value higher than 1!\n");
		goto amountInput; // User will be sent back to "amountInput" if the typed in value is lower than 2.
	}

	roundCounterVector.resize(playerAmount); // The vector "roundCounterVector" will apply the value of "playerAmount".
	playerLifepointsVector.resize(playerAmount); // The vector "LifepointsVector" will apply the value of "playerAmount".
	playerNumberVector.resize(playerAmount); // The vector "playerNumberVector" will apply the value of "playerAmount".
	playerVector.resize(playerAmount); // The vector "playerVector" will apply the value of "playerAmount".
	system("cls");

	for (x = 0; x < playerAmount; x++)
	{
		cout << "Player " << x << " enter your name: ";
		cin >> playerVector[x]; // Players entering their names during this FOR-LOOP. When the variable "x" has reached the value of "playerAmount", the FOR-LOOP will be left. 
	}

	system("cls");
	cout << playerVector.size() << " Participating players:\n"; // "playerVector.size()" shows the size of the vector "playerVector". In this case it is the value of "playerAmount".

	for (x = 0; x < playerAmount; x++)
	{
		cout << "Player " << x << ": " << playerVector[x] << "\n"; // This FOR-LOOP outputs a list of all participating players.
	}

continue1:

	printf("\nContinue? (y/n) ");
	decision = _getch();

	if (decision == 'y')
	{
		system("cls");
		goto gameStart;
	}
	if (decision == 'n')
	{
		system("cls");
		goto amountInput;
	}
	else
		goto continue1;

	// DEL2

gameStart:

	for (x = 0; x < playerAmount; x++)
	{
		playerLifepointsVector[x] = 100; // The lifepoints of each player is set to 100 during this FOR-LOOP.
	}

	int heavyTaken = 0;
	int defenderTaken = 0;
	int preciseTaken = 0;
	int invaderTaken = 0; // The 4 "...Taken" - variables check if a player has taken a character and another player can't take the same character.

	for (x = 0; x < playerAmount; x++)
	{
		system("cls");
		cout << "\n";
		for (y = 0; y < 4; y++)
		{
			cout << chosenCharacterString[y] << "\t" << characterString[y] << "\033[m\n"; // Displaying the list of playercharacters.
		}

	charChoice:

		// SECTION WHERE PLAYERS ARE CHOOSING THEIR CHARACTERS

		cout << "\n" << playerVector[x] << ", choose your character: ";
		cin >> inputValue; // User typing in a value to choose a character.

		if (heavyTaken == 1 && inputValue == 1)
		{
			goto charChoice; // User will be sent back to "charChoice" if a character is taken already ("...Taken" - value = 1).
		}
		if (defenderTaken == 1 && inputValue == 2)
		{
			goto charChoice;
		}
		if (preciseTaken == 1 && inputValue == 3)
		{
			goto charChoice;
		}
		if (invaderTaken == 1 && inputValue == 4)
		{
			goto charChoice;
		}

		if (inputValue == 1 && heavyTaken == 0)
		{
			heavyTaken = 1; // "...Taken" - value is set to 1.
			playerNumberVector[x] = 1; // Sets the current"playerNumberVector" to the value of the position of the character.
			chosenCharacterString[x] = "" + playerVector[x] + ": \033[32mHEAVY\033[m\n"; // Changes text from "chosenCharacterString" to make visible which character is taken by which player.
			characterString[0] = " "; // Remove text from "characterString" to remove the character from the list.
		}
		if (inputValue == 2 && defenderTaken == 0)
		{
			defenderTaken = 1;
			playerNumberVector[x] = 2;
			chosenCharacterString[x] = "" + playerVector[x] + ": \033[35mDEFENDER\033[m\n";
			characterString[1] = " ";
		}
		if (inputValue == 3 && preciseTaken == 0)
		{
			preciseTaken = 1;
			playerNumberVector[x] = 3;
			chosenCharacterString[x] = "" + playerVector[x] + ": \033[36mPRECISE\033[m\n";
			characterString[2] = " ";
		}
		if (inputValue == 4 && invaderTaken == 0)
		{
			invaderTaken = 1;
			playerNumberVector[x] = 4;
			chosenCharacterString[x] = "" + playerVector[x] + ": \033[33mINVADER\033[m\n";
			characterString[3] = " ";
		}
		if (inputValue > 4)
		{
			goto charChoice;
		}
	}
	system("cls");
	for (y = 0; y < 4; y++)
	{
		cout << chosenCharacterString[y] << characterString[y] << "\033[m\n";
	}

continue2:

	printf("Press SPACE to continue!");
	decision = _getch();

	if (decision == ' ')
	{
		counter = 1;
		// roundCounterVector[0] = 1; // HERE FOR 2 PLAYERS ONLY.
		// roundCounterVector[1] = 0;
		system("cls");
		goto playerDraws;
	}
	else
		goto continue2;

	// INITIALISATION SECTION END

playerDraws:

	if (counter > playerAmount)
	{
		counter = 1;
	}
	damage = 0;
	srand(time(NULL));
	heavyPrecise = rand() % 5 + 3; // The precision of each character is set to its random number each new round.
	defenderPrecise = rand() % 3 + 1;
	precisePrecise = rand() % 2 + 1;
	invaderPrecise = rand() % 3 + 1;
	for (x = 0; playerLifepointsVector[x] <= 0; x++)
	{
		goto gameover;
	}
	
	if (playerLifepointsVector[0] <= 0)
	{
		playerLifepointsVector[0] = 0;
		goto gameover;
	}
	if (playerLifepointsVector[1] <= 0)
	{
		playerLifepointsVector[1] = 0;
		goto gameover;
	}
	system("cls");

	for (y = 0; y < playerAmount; y++)
	{
		cout << chosenCharacterString[y] << playerLifepointsVector[y] << " \033[1;31mLIFEPOINTS\033[m" << "\n\n"; // Displaying the list of taken playercharacters and lifepoints.
	}

player0Draw:

	if (counter == 1)
	{
		cout << playerVector[0] <<
			", \033[1;34mwhat would you like to do?\033[m\n\n1. Attack another player\n2. Increase ATTACK\n3. Increase DEFEND\nChoice: ";
		cin >> inputValue;

		if (inputValue == 1)
		{
			cout << "\n\033[1;34mWho would you like to attack?\033[m\n\n";

			for (x = 0; x < playerAmount; x++)
			{
				cout << x << ". " << playerVector[x] << "\n";
			}
			cout << "Choice: ";
			cin >> inputValue;

			if (inputValue == 0)
			{
				cout << "\n\n\033[31mYOU CANT'T ATTACK YOURSELF!\n\033[m";
				goto player0Draw;
			}
			if (inputValue == 1)
			{
				goto ZEROattackONE;
			}
		}
	}
player1Draw:
	if (counter == 2)
	{
		cout << playerVector[1] <<
			", \033[1;34mwhat would you like to do?\033[m\n\n1. Attack another player\n2. Increase ATTACK\n3. Increase DEFEND\nChoice: ";
		cin >> inputValue;

		if (inputValue == 1)
		{
			cout << "\n\033[1;34mWho would you like to attack?\033[m\n\n";

			for (x = 0; x < playerAmount; x++)
			{
				cout << x << ". " << playerVector[x] << "\n";
			}
			cout << "Choice: ";
			cin >> inputValue;

			if (inputValue == 1)
			{
				cout << "\n\n\033[31mYOU CANT'T ATTACK YOURSELF!\n\033[m";
				goto player1Draw;
			}
			if (inputValue == 0)
			{
				goto ONEattackZERO;
			}
		}
	}
	/*
	   POSSIBLE SCENARIOS:

	   HEAVY -> DEFENDER (1:2) HEAVY -> PRECISE (1:3) HEAVY -> INVADER (1:4)

	   DEFENDER -> HEAVY (2:1) DEFENDER -> PRECISE (2:3) DEFENDER -> INVADER
	   (2:4)

	   PRECISE -> HEAVY (3:1) PRECISE -> DEFENDER (3:2) PRECISE -> INVADER
	   (3:4)

	   INVADER -> HEAVY (4:1) INVADER -> DEFENDER (4:2) INVADER -> PRECISE
	   (4:3) */



player2Draw:

	if (counter == 3)
	{
		cout << playerVector[2] <<
			", \033[1;34mwhat would you like to do?\033[m\n\n1. Attack another player\n2. Increase ATTACK\n3. Increase DEFEND\nChoice: ";
		cin >> inputValue;

		if (inputValue == 1)
		{
			cout << "\n\033[1;34mWho would you like to attack?\033[m\n\n";

			for (x = 0; x < playerAmount; x++)
			{
				cout << x << ". " << playerVector[x] << "\n";
			}
			cout << "Choice: ";
			cin >> inputValue;

			if (inputValue == 2)
			{
				cout << "\n\n\033[31mYOU CANT'T ATTACK YOURSELF!\n\033[m";
				goto player2Draw;
			}
			if (inputValue == 0)
			{
				goto ONEattackZERO;
			}
		}
	}

player3Draw:

	if (counter == 4)
	{
		cout << playerVector[3] <<
			", \033[1;34mwhat would you like to do?\033[m\n\n1. Attack another player\n2. Increase ATTACK\n3. Increase DEFEND\nChoice: ";
		cin >> inputValue;

		if (inputValue == 1)
		{
			cout << "\n\033[1;34mWho would you like to attack?\033[m\n\n";

			for (x = 0; x < playerAmount; x++)
			{
				cout << x << ". " << playerVector[x] << "\n";
			}
			cout << "Choice: ";
			cin >> inputValue;

			if (inputValue == 3)
			{
				cout << "\n\n\033[31mYOU CANT'T ATTACK YOURSELF!\n\033[m";
				goto player3Draw;
			}
			if (inputValue == 0)
			{
				goto ONEattackZERO;
			}
		}
	}

ZEROattackONE:

	system("cls");
	cout << chosenCharacterString[0] << " \033[31mATTACKS\033[m\n" << chosenCharacterString[1];

	// 1.

	if (playerNumberVector[0] == 1 && playerNumberVector[1] == 2) // HEAVY - DEFENDER
	{
		if (heavyPrecise == 3) // Precision is checked if it has the right value to even start a fight.
		{

			heavyAttack = rand() % heavyAttack_v1 + heavyAttack_v2;
			defenderDefend = rand() % defenderDefend_v1 + defenderDefend_v2; // "....Attack" and "....Defend" are calculated randomly by "....v1" and "....v2" - values.
			if (heavyAttack > defenderDefend) // Attack successfull:
			{
				damage = heavyAttack - defenderDefend;
				playerLifepointsVector[1] = playerLifepointsVector[1] - damage;
				cout << "\nAttack started and....";
				decision = _getch();
				cout << "\n\n\033[32mYOU MADE A HIT!\n\033[m" << playerVector[1] << " lost " <<
					damage << " lifepoints!\n";
				decision = _getch();
				counter++;
				goto playerDraws;
			}
			if (heavyAttack < defenderDefend) // Attack happened but defender was stronger.
			{
				damage = defenderDefend - heavyAttack;
				playerLifepointsVector[0] = playerLifepointsVector[0] - damage;
				cout << "\nAttack started and....";
				decision = _getch();
				cout << "\n\n\033[1;31mTHE ENEMY BLOCKED THE ATTACK!\n\033[m" << playerVector[0] <<
					" lost " << damage << " lifepoints!\n";
				decision = _getch();
				counter++; // The counter is increased by one. It's the next player's draw.
				goto playerDraws;
			}
		}
		else
		{
			cout << "\nAttack started and....";
			decision = _getch();
			cout << "\n\n\033[31mNO FIGHT OCCURED!\033[m\n";
			decision = _getch();
			counter++;
			goto playerDraws;
		}
	}

	if (playerNumberVector[0] == 1 && playerNumberVector[1] == 3) // HEAVY - PRECISE
	{
		if (heavyPrecise == 3)
		{

			heavyAttack = rand() % heavyAttack_v1 + heavyAttack_v2;
			preciseDefend = rand() % preciseDefend_v1 + preciseDefend_v2;
			if (heavyAttack > preciseDefend)
			{
				damage = heavyAttack - preciseDefend;
				playerLifepointsVector[1] = playerLifepointsVector[1] - damage;
				cout << "\nAttack started and....";
				decision = _getch();
				cout << "\n\n\033[32mYOU MADE A HIT!\n\033[m" << playerVector[1] << " lost " <<
					damage << " lifepoints!\n";
				decision = _getch();
				counter++;
				goto playerDraws;
			}
			if (heavyAttack < preciseDefend)
			{
				damage = preciseDefend - heavyAttack;
				playerLifepointsVector[0] = playerLifepointsVector[0] - damage;
				cout << "\nAttack started and....";
				decision = _getch();
				cout << "\n\n\033[1;31mTHE ENEMY BLOCKED THE ATTACK!\n\033[m" << playerVector[0] <<
					" lost " << damage << " lifepoints!\n";
				decision = _getch();
				counter++;
				goto playerDraws;
			}
		}
		else
		{
			cout << "\nAttack started and....";
			decision = _getch();
			cout << "\n\n\033[31mNO FIGHT OCCURED!\033[m\n";
			decision = _getch();
			counter++;
			goto playerDraws;
		}
	}

	if (playerNumberVector[0] == 1 && playerNumberVector[1] == 4) // HEAVY - INVADER
	{
		if (heavyPrecise == 3)
		{

			heavyAttack = rand() % heavyAttack_v1 + heavyAttack_v2;
			invaderDefend = rand() % invaderDefend_v1 + invaderDefend_v2;
			if (heavyAttack > invaderDefend)
			{
				damage = heavyAttack - invaderDefend;
				playerLifepointsVector[1] = playerLifepointsVector[1] - damage;
				cout << "\nAttack started and....";
				decision = _getch();
				cout << "\n\n\033[32mYOU MADE A HIT!\n\033[m" << playerVector[1] << " lost " <<
					damage << " lifepoints!\n";
				decision = _getch();
				counter++;
				goto playerDraws;
			}
			if (heavyAttack < invaderDefend)
			{
				damage = invaderDefend - heavyAttack;
				playerLifepointsVector[0] = playerLifepointsVector[0] - damage;
				cout << "\nAttack started and....";
				decision = _getch();
				cout << "\n\n\033[1;31mTHE ENEMY BLOCKED THE ATTACK!\n\033[m" << playerVector[0] <<
					" lost " << damage << " lifepoints!\n";
				decision = _getch();
				counter++;
				goto playerDraws;
			}
		}
		else
		{
			cout << "\nAttack started and....";
			decision = _getch();
			cout << "\n\n\033[31mNO FIGHT OCCURED!\033[m\n";
			decision = _getch();
			counter++;
			goto playerDraws;
		}
	}

	// 2.

	if (playerNumberVector[0] == 2 && playerNumberVector[1] == 1) // DEFENDER - HEAVY 
	{

		if (defenderPrecise == 3)
		{

			defenderAttack = rand() % heavyAttack_v1 + heavyAttack_v2;
			heavyDefend = rand() % heavyDefend_v1 + heavyDefend_v2;
			if (defenderAttack > heavyDefend)
			{
				damage = defenderAttack - heavyDefend;
				playerLifepointsVector[1] = playerLifepointsVector[1] - damage;
				cout << "\nAttack started and....";
				decision = _getch();
				cout << "\n\n\033[32mYOU MADE A HIT!\n\033[m" << playerVector[1] << " lost " <<
					damage << " lifepoints!\n";
				decision = _getch();
				counter++;
				goto playerDraws;
			}
			if (defenderAttack < heavyDefend)
			{
				damage = heavyDefend - defenderAttack;
				playerLifepointsVector[0] = playerLifepointsVector[0] - damage;
				cout << "\nAttack started and....";
				decision = _getch();
				cout << "\n\n\033[1;31mTHE ENEMY BLOCKED THE ATTACK!\n\033[m" << playerVector[0] <<
					" lost " << damage << " lifepoints!\n";
				decision = _getch();
				counter++;
				goto playerDraws;
			}
		}
		else
		{
			cout << "\nAttack started and....";
			decision = _getch();
			cout << "\n\n\033[31mNO FIGHT OCCURED!\033[m\n";
			decision = _getch();
			counter++;
			goto playerDraws;
		}
	}

	if (playerNumberVector[0] == 2 && playerNumberVector[1] == 3) // DEFENDER - PRECISE 
	{

		if (defenderPrecise == 3)
		{

			defenderAttack = rand() % defenderAttack_v1 + defenderAttack_v2;
			preciseDefend = rand() % preciseDefend_v1 + preciseDefend_v2;
			if (defenderAttack > preciseDefend)
			{
				damage = defenderAttack - preciseDefend;
				playerLifepointsVector[1] = playerLifepointsVector[1] - damage;
				cout << "\nAttack started and....";
				decision = _getch();
				cout << "\n\n\033[32mYOU MADE A HIT!\n\033[m" << playerVector[1] << " lost " <<
					damage << " lifepoints!\n";
				decision = _getch();
				counter++;
				goto playerDraws;
			}
			if (defenderAttack < preciseDefend)
			{
				damage = preciseDefend - defenderAttack;
				playerLifepointsVector[0] = playerLifepointsVector[0] - damage;
				cout << "\nAttack started and....";
				decision = _getch();
				cout << "\n\n\033[1;31mTHE ENEMY BLOCKED THE ATTACK!\n\033[m" << playerVector[0] <<
					" lost " << damage << " lifepoints!\n";
				decision = _getch();
				roundCounterVector[0] = 0;
				counter++;
				goto playerDraws;
			}
		}
		else
		{
			cout << "\nAttack started and....";
			decision = _getch();
			cout << "\n\n\033[31mNO FIGHT OCCURED!\033[m\n";
			decision = _getch();
			counter++;
			goto playerDraws;
		}
	}

	if (playerNumberVector[0] == 2 && playerNumberVector[1] == 4) // DEFENDER - INVADER 
	{

		if (defenderPrecise == 3)
		{

			defenderAttack = rand() % defenderAttack_v1 + defenderAttack_v2;
			invaderDefend = rand() % invaderDefend_v1 + invaderDefend_v2;
			if (defenderAttack > invaderDefend)
			{
				damage = defenderAttack - invaderDefend;
				playerLifepointsVector[1] = playerLifepointsVector[1] - damage;
				cout << "\nAttack started and....";
				decision = _getch();
				cout << "\n\n\033[32mYOU MADE A HIT!\n\033[m" << playerVector[1] << " lost " <<
					damage << " lifepoints!\n";
				decision = _getch();
				counter++;
				goto playerDraws;
			}
			if (defenderAttack < invaderDefend)
			{
				damage = invaderDefend - defenderAttack;
				playerLifepointsVector[0] = playerLifepointsVector[0] - damage;
				cout << "\nAttack started and....";
				decision = _getch();
				cout << "\n\n\033[1;31mTHE ENEMY BLOCKED THE ATTACK!\n\033[m" << playerVector[0] <<
					" lost " << damage << " lifepoints!\n";
				decision = _getch();
				counter++;
				goto playerDraws;
			}
		}
		else
		{
			cout << "\nAttack started and....";
			decision = _getch();
			cout << "\n\n\033[31mNO FIGHT OCCURED!\033[m\n";
			decision = _getch();
			counter++;
			goto playerDraws;
		}
	}


	// 3.

	if (playerNumberVector[0] == 3 && playerNumberVector[1] == 1) // PRECISE - HEAVY
	{
		if (precisePrecise == 1)
		{
			heavyAttack = rand() % heavyAttack_v1 + heavyAttack_v2;
			invaderDefend = rand() % invaderDefend_v1 + invaderDefend_v2;
			if (heavyAttack > invaderDefend)
			{
				damage = heavyAttack - invaderDefend;
				playerLifepointsVector[1] = playerLifepointsVector[1] - damage;
				cout << "\nAttack started and....";
				decision = _getch();
				cout << "\n\n\033[32mYOU MADE A HIT!\n\033[m" << playerVector[1] << " lost " <<
					damage << " lifepoints!\n";
				decision = _getch();
				counter++;
				goto playerDraws;
			}
			if (heavyAttack < invaderDefend)
			{
				damage = invaderDefend - heavyAttack;
				playerLifepointsVector[0] = playerLifepointsVector[0] - damage;
				cout << "\nAttack started and....";
				decision = _getch();
				cout << "\n\n\033[1;31mTHE ENEMY BLOCKED THE ATTACK!\n\033[m" << playerVector[0] <<
					" lost " << damage << " lifepoints!\n";
				decision = _getch();
				counter++;
				goto playerDraws;
			}
		}
		else
		{
			cout << "\nAttack started and....";
			decision = _getch();
			cout << "\n\n\033[31mNO FIGHT OCCURED!\033[m\n";
			decision = _getch();
			counter++;
			goto playerDraws;
		}
	}

	if (playerNumberVector[0] == 3 && playerNumberVector[1] == 2) // PRECISE - DEFENDER 
	{
		if (precisePrecise == 1)
		{
			preciseAttack = rand() % preciseAttack_v1 + preciseAttack_v2;
			defenderDefend = rand() % defenderDefend_v1 + defenderDefend_v2;
			if (preciseAttack > defenderDefend)
			{
				damage = preciseAttack - defenderDefend;
				playerLifepointsVector[1] = playerLifepointsVector[1] - damage;
				cout << "\nAttack started and....";
				decision = _getch();
				cout << "\n\n\033[32mYOU MADE A HIT!\n\033[m" << playerVector[1] << " lost " <<
					damage << " lifepoints!\n";
				decision = _getch();
				counter++;
				goto playerDraws;
			}
			if (preciseAttack < defenderDefend)
			{
				damage = defenderDefend - preciseAttack;
				playerLifepointsVector[0] = playerLifepointsVector[0] - damage;
				cout << "\nAttack started and....";
				decision = _getch();
				cout << "\n\n\033[1;31mTHE ENEMY BLOCKED THE ATTACK!\n\033[m" << playerVector[0] <<
					" lost " << damage << " lifepoints!\n";
				decision = _getch();
				counter++;
				goto playerDraws;
			}
		}
		else
		{
			cout << "\nAttack started and....";
			decision = _getch();
			cout << "\n\n\033[31mNO FIGHT OCCURED!\033[m\n";
			decision = _getch();
			counter++;
			goto playerDraws;
		}
	}

	if (playerNumberVector[0] == 3 && playerNumberVector[1] == 4) // PRECISE - INVADER
	{
		if (precisePrecise == 1)
		{
			preciseAttack = rand() % preciseAttack_v1 + preciseAttack_v2;
			invaderDefend = rand() % invaderDefend_v1 + invaderDefend_v2;
			if (preciseAttack > invaderDefend)
			{
				damage = preciseAttack - invaderDefend;
				playerLifepointsVector[1] = playerLifepointsVector[1] - damage;
				cout << "\nAttack started and....";
				decision = _getch();
				cout << "\n\n\033[32mYOU MADE A HIT!\n\033[m" << playerVector[1] << " lost " <<
					damage << " lifepoints!\n";
				decision = _getch();
				counter++;
				goto playerDraws;
			}
			if (preciseAttack < invaderDefend)
			{
				damage = invaderDefend - preciseAttack;
				playerLifepointsVector[0] = playerLifepointsVector[0] - damage;
				cout << "\nAttack started and....";
				decision = _getch();
				cout << "\n\n\033[1;31mTHE ENEMY BLOCKED THE ATTACK!\n\033[m" << playerVector[0] <<
					" lost " << damage << " lifepoints!\n";
				decision = _getch();
				counter++;
				goto playerDraws;
			}
		}
		else
		{
			cout << "\nAttack started and....";
			decision = _getch();
			cout << "\n\n\033[31mNO FIGHT OCCURED!\033[m\n";
			decision = _getch();
			counter++;
			goto playerDraws;
		}
	}

	// 4.

	if (playerNumberVector[0] == 4 && playerNumberVector[1] == 1)	// INVADER - HEAVY
	{
		if (invaderPrecise == 3)
		{
			invaderAttack = rand() % invaderAttack_v1 + invaderAttack_v2;
			heavyDefend = rand() % heavyDefend_v1 + heavyDefend_v2;
			if (invaderAttack > heavyDefend)
			{
				damage = invaderAttack - heavyDefend;
				playerLifepointsVector[1] = playerLifepointsVector[1] - damage;
				cout << "\nAttack started and....";
				decision = _getch();
				cout << "\n\n\033[32mYOU MADE A HIT!\n\033[m" << playerVector[1] << " lost " <<
					damage << " lifepoints!\n";
				decision = _getch();
				counter++;
				goto playerDraws;
			}
			if (invaderAttack < heavyDefend)
			{
				damage = heavyDefend - invaderAttack;
				playerLifepointsVector[0] = playerLifepointsVector[0] - damage;
				cout << "\nAttack started and....";
				decision = _getch();
				cout << "\n\n\033[1;31mTHE ENEMY BLOCKED THE ATTACK!\n\033[m" << playerVector[0] <<
					" lost " << damage << " lifepoints!\n";
				decision = _getch();
				counter++;
				goto playerDraws;
			}
		}
		else
		{
			cout << "\nAttack started and....";
			decision = _getch();
			cout << "\n\n\033[31mNO FIGHT OCCURED!\033[m\n";
			decision = _getch();
			counter++;
			goto playerDraws;
		}
	}

	if (playerNumberVector[0] == 4 && playerNumberVector[1] == 2) // INVADER - DEFENDER
	{
		if (invaderPrecise == 3)
		{
			invaderAttack = rand() % invaderAttack_v1 + invaderAttack_v2;
			defenderDefend = rand() % defenderDefend_v1 + defenderDefend_v2;
			if (invaderAttack > defenderDefend)
			{
				damage = invaderAttack - defenderDefend;
				playerLifepointsVector[1] = playerLifepointsVector[1] - damage;
				cout << "\nAttack started and....";
				decision = _getch();
				cout << "\n\n\033[32mYOU MADE A HIT!\n\033[m" << playerVector[1] << " lost " <<
					damage << " lifepoints!\n";
				decision = _getch();
				counter++;
				goto playerDraws;
			}
			if (invaderAttack < defenderDefend)
			{
				damage = heavyDefend - invaderAttack;
				playerLifepointsVector[0] = playerLifepointsVector[0] - damage;
				cout << "\nAttack started and....";
				decision = _getch();
				cout << "\n\n\033[1;31mTHE ENEMY BLOCKED THE ATTACK!\n\033[m" << playerVector[0] <<
					" lost " << damage << " lifepoints!\n";
				decision = _getch();
				counter++;
				goto playerDraws;
			}
		}
		else
		{
			cout << "\nAttack started and....";
			decision = _getch();
			cout << "\n\n\033[31mNO FIGHT OCCURED!\033[m\n";
			decision = _getch();
			counter++;
			goto playerDraws;
		}
	}

	if (playerNumberVector[0] == 4 && playerNumberVector[1] == 3) // INVADER - PRECISE
	{
		if (invaderPrecise == 3)
		{
			invaderAttack = rand() % invaderAttack_v1 + invaderAttack_v2;
			preciseDefend = rand() % preciseDefend_v1 + preciseDefend_v2;
			if (invaderAttack > preciseDefend)
			{
				damage = invaderAttack - preciseDefend;
				playerLifepointsVector[1] = playerLifepointsVector[1] - damage;
				cout << "\nAttack started and....";
				decision = _getch();
				cout << "\n\n\033[32mYOU MADE A HIT!\n\033[m" << playerVector[1] << " lost " <<
					damage << " lifepoints!\n";
				decision = _getch();
				counter++;
				goto playerDraws;
			}
			if (invaderAttack < preciseDefend)
			{
				damage = heavyDefend - invaderAttack;
				playerLifepointsVector[0] = playerLifepointsVector[0] - damage;
				cout << "\nAttack started and....";
				decision = _getch();
				cout << "\n\n\033[1;31mTHE ENEMY BLOCKED THE ATTACK!\n\033[m" << playerVector[0] <<
					" lost " << damage << " lifepoints!\n";
				decision = _getch();
				counter++;
				goto playerDraws;
			}
		}
		else
		{
			cout << "\nAttack started and....";
			decision = _getch();
			cout << "\n\n\033[31mNO FIGHT OCCURED!\033[m\n";
			decision = _getch();
			counter++;
			goto playerDraws;
		}
	}

ONEattackZERO:

	system("cls");
	cout << chosenCharacterString[1] << " \033[31mATTACKS\033[m\n" << chosenCharacterString[0];

	// 1.

	if (playerNumberVector[1] == 2 && playerNumberVector[0] == 1) // DEFENDER - HEAVY
	{

		if (defenderPrecise == 2)
		{
			defenderAttack = rand() % defenderAttack_v1 + defenderAttack_v2;
			heavyDefend = rand() % heavyDefend_v1 + heavyDefend_v2;
			if (defenderAttack > heavyDefend)
			{
				damage = defenderAttack - heavyDefend;
				playerLifepointsVector[0] = playerLifepointsVector[0] - damage;
				cout << "\nAttack started and....";
				decision = _getch();
				cout << "\n\n\033[32mYOU MADE A HIT!\n\033[m" << playerVector[0] << " lost " <<
					damage << " lifepoints!\n";
				decision = _getch();
				counter++;
				goto playerDraws;
			}
			if (defenderAttack < heavyDefend)
			{
				damage = heavyDefend - defenderAttack;
				playerLifepointsVector[1] = playerLifepointsVector[1] - damage;
				cout << "\nAttack started and....";
				decision = _getch();
				cout << "\n\n\033[1;31mTHE ENEMY BLOCKED THE ATTACK!\n\033[m" << playerVector[1] << " lost " << damage << " lifepoints!\n";
				decision = _getch();
				counter++;
				goto playerDraws;
			}
		}
		else
		{
			cout << "\nAttack started and....";
			decision = _getch();
			cout << "\n\n\033[31mNO FIGHT OCCURED!\033[m\n";
			decision = _getch();
			counter++;
			goto playerDraws;
		}
	}

	if (playerNumberVector[1] == 2 && playerNumberVector[0] == 3) // DEFENDER - PRECISE
	{
		if (defenderPrecise == 2)
		{
			defenderAttack = rand() % defenderAttack_v1 + defenderAttack_v2;
			preciseDefend = rand() % preciseDefend_v1 + preciseDefend_v2;
			if (defenderAttack > preciseDefend)
			{
				damage = defenderAttack - preciseDefend;
				playerLifepointsVector[0] = playerLifepointsVector[0] - damage;
				cout << "\nAttack started and....";
				decision = _getch();
				cout << "\n\n\033[32mYOU MADE A HIT!\n\033[m" << playerVector[0] << " lost " <<
					damage << " lifepoints!\n";
				decision = _getch();
				counter++;
				goto playerDraws;
			}
			if (defenderAttack < preciseDefend)
			{
				damage = preciseDefend - defenderAttack;
				playerLifepointsVector[1] = playerLifepointsVector[1] - damage;
				cout << "\nAttack started and....";
				decision = _getch();
				cout << "\n\n\033[1;31mTHE ENEMY BLOCKED THE ATTACK!\n\033[m" << playerVector[1] <<
					" lost " << damage << " lifepoints!\n";
				decision = _getch();
				counter++;
				goto playerDraws;
			}
		}
		else
		{
			cout << "\nAttack started and....";
			decision = _getch();
			cout << "\n\n\033[31mNO FIGHT OCCURED!\033[m\n";
			decision = _getch();
			counter++;
			goto playerDraws;
		}

	}

	if (playerNumberVector[1] == 2 && playerNumberVector[0] == 4) // DEFENDER - INVADER
	{
		if (defenderPrecise == 2)
		{
			defenderAttack = rand() % defenderAttack_v1 + defenderAttack_v2;
			invaderDefend = rand() % invaderDefend_v1 + invaderDefend_v2;
			if (defenderAttack > invaderDefend)
			{
				damage = defenderAttack - invaderDefend;
				playerLifepointsVector[0] = playerLifepointsVector[0] - damage;
				cout << "\nAttack started and....";
				decision = _getch();
				cout << "\n\n\033[32mYOU MADE A HIT!\n\033[m" << playerVector[0] << " lost " <<
					damage << " lifepoints!\n";
				decision = _getch();
				counter++;
				goto playerDraws;
			}
			if (defenderAttack < invaderDefend)
			{
				damage = invaderDefend - defenderAttack;
				playerLifepointsVector[1] = playerLifepointsVector[1] - damage;
				cout << "\nAttack started and....";
				decision = _getch();
				cout << "\n\n\033[1;31mTHE ENEMY BLOCKED THE ATTACK!\n\033[m" << playerVector[1] <<
					" lost " << damage << " lifepoints!\n";
				decision = _getch();
				counter++;
				goto playerDraws;
			}
		}
		else
		{
			cout << "\nAttack started and....";
			decision = _getch();
			cout << "\n\n\033[31mNO FIGHT OCCURED!\033[m\n";
			decision = _getch();
			counter++;
			goto playerDraws;
		}
	}

	//2.

	if (playerNumberVector[1] == 3 && playerNumberVector[0] == 1) // PRECISE - HEAVY
	{
		if (precisePrecise == 1)
		{
			preciseAttack = rand() % preciseAttack_v1 + preciseAttack_v2;
			heavyDefend = rand() % heavyDefend_v1 + heavyDefend_v2;
			if (preciseAttack > heavyDefend)
			{
				damage = preciseAttack - heavyDefend;
				playerLifepointsVector[0] = playerLifepointsVector[0] - damage;
				cout << "\nAttack started and....";
				decision = _getch();
				cout << "\n\n\033[32mYOU MADE A HIT!\n\033[m" << playerVector[0] << " lost " <<
					damage << " lifepoints!\n";
				decision = _getch();
				counter++;
				goto playerDraws;
			}
			if (preciseAttack < heavyDefend)
			{
				damage = heavyDefend - preciseAttack;
				playerLifepointsVector[1] = playerLifepointsVector[1] - damage;
				cout << "\nAttack started and....";
				decision = _getch();
				cout << "\n\n\033[1;31mTHE ENEMY BLOCKED THE ATTACK!\n\033[m" << playerVector[1] <<
					" lost " << damage << " lifepoints!\n";
				decision = _getch();
				counter++;
				goto playerDraws;
			}
		}
		else
		{
			cout << "\nAttack started and....";
			decision = _getch();
			cout << "\n\n\033[31mNO FIGHT OCCURED!\033[m\n";
			decision = _getch();
			counter++;
			goto playerDraws;
		}
	}

	if (playerNumberVector[1] == 3 && playerNumberVector[0] == 2) // PRECISE - DEFENDER
	{
		if (precisePrecise == 1)
		{
			preciseAttack = rand() % preciseAttack_v1 + preciseAttack_v2;
			defenderDefend = rand() % defenderDefend_v1 + defenderDefend_v2;
			if (preciseAttack > defenderDefend)
			{
				damage = preciseAttack - defenderDefend;
				playerLifepointsVector[0] = playerLifepointsVector[0] - damage;
				cout << "\nAttack started and....";
				decision = _getch();
				cout << "\n\n\033[32mYOU MADE A HIT!\n\033[m" << playerVector[0] << " lost " <<
					damage << " lifepoints!\n";
				decision = _getch();
				counter++;
				goto playerDraws;
			}
			if (preciseAttack < defenderDefend)
			{
				damage = defenderDefend - preciseAttack;
				playerLifepointsVector[1] = playerLifepointsVector[1] - damage;
				cout << "\nAttack started and....";
				decision = _getch();
				cout << "\n\n\033[1;31mTHE ENEMY BLOCKED THE ATTACK!\n\033[m" << playerVector[1] <<
					" lost " << damage << " lifepoints!\n";
				decision = _getch();
				counter++;
				goto playerDraws;
			}
		}
		else
		{
			cout << "\nAttack started and....";
			decision = _getch();
			cout << "\n\n\033[31mNO FIGHT OCCURED!\033[m\n";
			decision = _getch();
			counter++;
			goto playerDraws;
		}
	}

	if (playerNumberVector[1] == 3 && playerNumberVector[0] == 4) //PRECISE - INVADER 
	{
		if (precisePrecise == 1)
		{
			preciseAttack = rand() % preciseAttack_v1 + preciseAttack_v2;
			invaderDefend = rand() % invaderDefend_v1 + invaderDefend_v2;
			if (preciseAttack > invaderDefend)
			{
				damage = preciseAttack - invaderDefend;
				playerLifepointsVector[0] = playerLifepointsVector[0] - damage;
				cout << "\nAttack started and....";
				decision = _getch();
				cout << "\n\n\033[32mYOU MADE A HIT!\n\033[m" << playerVector[0] << " lost " <<
					damage << " lifepoints!\n";
				decision = _getch();
				counter++;
				goto playerDraws;
			}
			if (preciseAttack < invaderDefend)
			{
				damage = invaderDefend - preciseAttack;
				playerLifepointsVector[1] = playerLifepointsVector[1] - damage;
				cout << "\nAttack started and....";
				decision = _getch();
				cout << "\n\n\033[1;31mTHE ENEMY BLOCKED THE ATTACK!\n\033[m" << playerVector[1] <<
					" lost " << damage << " lifepoints!\n";
				decision = _getch();
				counter++;
				goto playerDraws;
			}
		}
		else
		{
			cout << "\nAttack started and....";
			decision = _getch();
			cout << "\n\n\033[31mNO FIGHT OCCURED!\033[m\n";
			decision = _getch();
			counter++;
			goto playerDraws;
		}
	}

	// 3.

	if (playerNumberVector[1] == 1 && playerNumberVector[0] == 3) // HEAVY - PRECISE 
	{
		if (heavyPrecise == 3)
		{
			heavyAttack = rand() % heavyAttack_v1 + heavyAttack_v2;
			preciseDefend = rand() % preciseDefend_v1 + preciseDefend_v2;
			if (heavyAttack > preciseDefend)
			{
				damage = heavyAttack - preciseDefend;
				playerLifepointsVector[0] = playerLifepointsVector[0] - damage;
				cout << "\nAttack started and....";
				decision = _getch();
				cout << "\n\n\033[32mYOU MADE A HIT!\n\033[m" << playerVector[0] << " lost " <<
					damage << " lifepoints!\n";
				decision = _getch();
				counter++;
				goto playerDraws;
			}
			if (heavyAttack < preciseDefend)
			{
				damage = preciseDefend - heavyAttack;
				playerLifepointsVector[1] = playerLifepointsVector[1] - damage;
				cout << "\nAttack started and....";
				decision = _getch();
				cout << "\n\n\033[1;31mTHE ENEMY BLOCKED THE ATTACK!\n\033[m" << playerVector[1] <<
					" lost " << damage << " lifepoints!\n";
				decision = _getch();
				counter++;
				goto playerDraws;
			}
		}
		else
		{
			cout << "\nAttack started and....";
			decision = _getch();
			cout << "\n\n\033[31mNO FIGHT OCCURED!\033[m\n";
			decision = _getch();
			counter++;
			goto playerDraws;
		}
	}

	if (playerNumberVector[1] == 1 && playerNumberVector[0] == 4) // HEAVY - INVADER 
	{
		if (heavyPrecise == 3)
		{
			heavyAttack = rand() % heavyAttack_v1 + heavyAttack_v2;
			invaderDefend = rand() % invaderDefend_v1 + invaderDefend_v2;
			if (heavyAttack > invaderDefend)
			{
				damage = heavyAttack - invaderDefend;
				playerLifepointsVector[0] = playerLifepointsVector[0] - damage;
				cout << "\nAttack started and....";
				decision = _getch();
				cout << "\n\n\033[32mYOU MADE A HIT!\n\033[m" << playerVector[0] << " lost " <<
					damage << " lifepoints!\n";
				decision = _getch();
				counter++;
				goto playerDraws;
			}
			if (heavyAttack < invaderDefend)
			{
				damage = invaderDefend - heavyAttack;
				playerLifepointsVector[1] = playerLifepointsVector[1] - damage;
				cout << "\nAttack started and....";
				decision = _getch();
				cout << "\n\n\033[1;31mTHE ENEMY BLOCKED THE ATTACK!\n\033[m" << playerVector[1] <<
					" lost " << damage << " lifepoints!\n";
				decision = _getch();
				counter++;
				goto playerDraws;
			}
		}
		else
		{
			cout << "\nAttack started and....";
			decision = _getch();
			cout << "\n\n\033[31mNO FIGHT OCCURED!\033[m\n";
			decision = _getch();
			counter++;
			goto playerDraws;
		}
	}

	//4.

	if (playerNumberVector[1] == 4 && playerNumberVector[0] == 1) // INVADER - HEAVY 
	{
		if (invaderPrecise == 2)
		{
			invaderAttack = rand() % invaderAttack_v1 + invaderAttack_v2;
			heavyDefend = rand() % heavyDefend_v1 + heavyDefend_v2;
			if (invaderAttack > heavyDefend)
			{
				damage = invaderAttack - heavyDefend;
				playerLifepointsVector[0] = playerLifepointsVector[0] - damage;
				cout << "\nAttack started and....";
				decision = _getch();
				cout << "\n\n\033[32mYOU MADE A HIT!\n\033[m" << playerVector[0] << " lost " <<
					damage << " lifepoints!\n";
				decision = _getch();
				counter++;
				goto playerDraws;
			}
			if (invaderAttack < heavyDefend)
			{
				damage = heavyDefend - invaderAttack;
				playerLifepointsVector[1] = playerLifepointsVector[1] - damage;
				cout << "\nAttack started and....";
				decision = _getch();
				cout << "\n\n\033[1;31mTHE ENEMY BLOCKED THE ATTACK!\n\033[m" << playerVector[1] <<
					" lost " << damage << " lifepoints!\n";
				decision = _getch();
				counter++;
				goto playerDraws;
			}
		}
		else
		{
			cout << "\nAttack started and....";
			decision = _getch();
			cout << "\n\n\033[31mNO FIGHT OCCURED!\033[m\n";
			decision = _getch();
			counter++;
			goto playerDraws;
		}
	}

	if (playerNumberVector[1] == 4 && playerNumberVector[0] == 2) // INVADER - DEFENDER 
	{
		if (invaderPrecise == 2)
		{
			invaderAttack = rand() % invaderAttack_v1 + invaderAttack_v2;
			defenderDefend = rand() % defenderDefend_v1 + defenderDefend_v2;
			if (invaderAttack > defenderDefend)
			{
				damage = invaderAttack - defenderDefend;
				playerLifepointsVector[0] = playerLifepointsVector[0] - damage;
				cout << "\nAttack started and....";
				decision = _getch();
				cout << "\n\n\033[32mYOU MADE A HIT!\n\033[m" << playerVector[0] << " lost " <<
					damage << " lifepoints!\n";
				decision = _getch();
				counter++;
				goto playerDraws;
			}
			if (invaderAttack < defenderDefend)
			{
				damage = defenderDefend - invaderAttack;
				playerLifepointsVector[1] = playerLifepointsVector[1] - damage;
				cout << "\nAttack started and....";
				decision = _getch();
				cout << "\n\n\033[1;31mTHE ENEMY BLOCKED THE ATTACK!\n\033[m" << playerVector[1] <<
					" lost " << damage << " lifepoints!\n";
				decision = _getch();
				counter++;
				goto playerDraws;
			}
		}
		else
		{
			cout << "\nAttack started and....";
			decision = _getch();
			cout << "\n\n\033[31mNO FIGHT OCCURED!\033[m\n";
			decision = _getch();
			counter++;
			goto playerDraws;
		}
	}

	if (playerNumberVector[1] == 4 && playerNumberVector[0] == 3) // INVADER - PRECISE 
	{
		if (invaderPrecise == 2)
		{
			invaderAttack = rand() % invaderAttack_v1 + invaderAttack_v2;
			preciseDefend = rand() % preciseDefend_v1 + preciseDefend_v2;
			if (invaderAttack > preciseDefend)
			{
				damage = invaderAttack - preciseDefend;
				playerLifepointsVector[0] = playerLifepointsVector[0] - damage;
				cout << "\nAttack started and....";
				decision = _getch();
				cout << "\n\n\033[32mYOU MADE A HIT!\n\033[m" << playerVector[0] << " lost " << damage << " lifepoints!\n";
				decision = _getch();
				counter++;
				goto playerDraws;
			}
			if (invaderAttack < preciseDefend)
			{
				damage = preciseDefend - invaderAttack;
				playerLifepointsVector[1] = playerLifepointsVector[1] - damage;
				cout << "\nAttack started and....";
				decision = _getch();
				cout << "\n\n\033[1;31mTHE ENEMY BLOCKED THE ATTACK!\n\033[m" << playerVector[1] << " lost " << damage << " lifepoints!\n";
				decision = _getch();
				counter++;
				goto playerDraws;
			}
		}
		else
		{
			cout << "\nAttack started and....";
			decision = _getch();
			cout << "\n\n\033[31mNO FIGHT OCCURED!\033[m\n";
			decision = _getch();
			counter++;
			goto playerDraws;
		}
	}

gameover:

	system("cls");

	for (y = 0; y < playerAmount; y++)
	{
		cout << chosenCharacterString[y] << playerLifepointsVector[y] << " \033[1;31mLIFEPOINTS\033[m" << "\n\n";
	}

	if (playerLifepointsVector[0] == 0)
	{
		cout << "\n\n\033[31mGAME OVER!\033[m\n\n" << playerVector[0] << " has lost all lifepoints!";
	}

	if (playerLifepointsVector[1] == 0)
	{
		cout << "\n\n\033[31mGAME OVER!\033[m\n\n" << playerVector[1] << " has lost all lifepoints!\n\n\n\033[m";
	}
}


/* DELETED CODE:

*DEL1: (Signs/characters for players done seperately)

   string player0char = "\033[31m-\033[m"; string player1char =
   "\033[32m-\033[m"; string player2char = "\033[33m-\033[m"; string
   player3char = "\033[34m-\033[m"; string player4char = "\033[35m-\033[m";
   string player5char = "\033[36m-\033[m";


*DEL2: (Choosing the starting player)

   startingPlayerInput:

   // SECTION FOR CHOOSING WHICH PLAYER IS GOING TO START.

   printf("\nWhich player is going to start? Enter the playernumber: "); cin
   >> inputValue;

   if (inputValue >= playerAmount) { printf("\nThere are not that much
   players!"); goto startingPlayerInput; // User will be sent back
   to"startingPlayerInput" if the typed in value is greater than the value of
   "playerAmout". }

   if (inputValue == 0) { cout << "\n" << playerVector[0] << " is going to
   start!"; } else if (inputValue == 1) { cout << "\n" << playerVector[1] << "
   is going to start!"; } else if (inputValue == 2) { cout << "\n" <<
   playerVector[2] << " is going to start!"; } else if (inputValue == 3) //
   Checking the typed in value of "inputValue". { cout << "\n" <<
   playerVector[3] << " is going to start!"; } else if (inputValue == 4) {
   cout << "\n" << playerVector[4] << " is going to start!"; } else if
   (inputValue == 5) { cout << "\n\n" << playerVector[5] << " is going to
   start!"; } */
