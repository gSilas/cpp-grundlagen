#include <iostream>
#include <string>
#include <ctime>

using namespace std;

string name;
int health = 100;

int enemyhealth = 10;
int mattack = 10;
string monster;
int potions = 0;

int victories = 0;
int mStage = 8;

int RandomGen();
string chooseMonster();

int main()
{
	cout << "Choose your name!" << endl;
	getline(cin, name);

	cout << "You are entering the dungeon of certain doom!" << endl;

	monster = chooseMonster();

	while(mStage >= 0)
	{
		char action;
		cout << "####################################################################" << endl;
		cout << "Monster: " << monster << " Health: " << enemyhealth << endl;
		cout << "[A]ttack or [R]etreat or [U]se a potion" << endl;
		cout << "####################################################################" << endl;
		cin >> action;
		if (action == 'u' || action == 'U')
		{
			if (potions <= 0)
			{
				cout << "You dont have enough potions!" << endl;
			}

			if(potions > 0)
			{
				potions--;
				health += 20;
				cout << "You restored 20 health!" << endl;
			}
		}
		if (action == 'r' || action == 'R')
		{
			monster = chooseMonster();
			victories--;
		}

		if (action == 'a' || action == 'A')
		{
			cout << "The monster attacked with " << mattack << " damage." << endl;
			health = health - mattack;
			cout << "You still got " << health << " health left." << endl;
			if (health <= 0)
			{
				cout << name << " died in the dungeon."<< endl;
				break;
			}

			int pattack = rand() % 31;
			enemyhealth -= pattack;
			cout << name << " attacked with " << pattack << " damage!" << endl;
		}

		if(enemyhealth <= 0)
		{
			if(RandomGen() == 5 | RandomGen() == 0 | RandomGen() == 7)
			{
				cout << name << " found a potion!"<< endl;
				potions++;
			}
			monster = chooseMonster();
			enemyhealth = 10 + rand() % 21;
			victories++;
		}
		if(victories >= 20)
		{
			cout << name <<" reached the end of the dungeon!" << endl;
			cout << name <<" defeated 20 monsters!"<< endl;
			break;
		}
	}

    return 0;
}

string chooseMonster()
{
	string monster[8] = { "Bat","Orc","Thief", "Orc", "Warrior", "Mage", "Ghost", "Dragon" };
	int currIndex = RandomGen();
	mattack = (RandomGen() + mattack + currIndex)*0.5f;
	cout << "You are attacked by a Monster! It is a " << monster[currIndex] << " with " << mattack << " attackdamage!" << endl;
	return monster[currIndex];
}

int RandomGen()
{
	srand(time(NULL));
	return rand() % 8;
}


