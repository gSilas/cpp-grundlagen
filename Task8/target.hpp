#ifndef _TARGET
#define _TARGET
#include <string>

#include <random>
#include <iostream>

class Target {
public:
	Target(std::string name,int health, int x, int y)
	{
		mName = name;
		xPos = x;
		yPos = y;
		mHealth = health;
	}

	virtual void loseHealth(const Target& t) = 0;

	friend std::ostream &operator<<(std::ostream &lhs, const Target &t) {
		lhs << t.mName << " mit " << " Leben an Position " << t.xPos << ":" << t.yPos;
		return lhs;
	}

	int getHealth() const {
		return mHealth;
	}

	bool isDestroyed() const {
		return isBoom;
	}

	const std::string& getName() const {
		return mName;
	}

protected:
	int xPos;
	int yPos;
	std::string mName;
	bool isBoom = false;
	int mHealth;

	virtual void explode()
	{
		isBoom = true;
	}
};

class Spaceship: public Target
{
public:
	Spaceship(std::string name, int health,int x ,int y, int shields) : Target(name,health, x, y)
	{
		mShields = shields;
	}

	void attack(Target& t){
		t.loseHealth(*this);
	}

	void loseHealth(const Target& s) override {
		if (nullptr == dynamic_cast<const Spaceship*>(&s))
			return;

			mShields -= 12;
			if (mShields <= 0)
				mHealth -= 32;
			if (mHealth <= 0 && mShields <= 0)
				explode();
		
	}

	size_t getShield()
	{
		return mShields;
	}

protected:
	size_t mLasers;
	double mShields = 100;
};

class Deathstar :public Spaceship
{
public:
	Deathstar(std::string name, int health, int x, int y,int shields = 10000) : Spaceship(name, health, x, y,shields)
	{
		mShields = shields;
	}

	void loseHealth(const Target& s) override {
		if (nullptr != dynamic_cast<const Spaceship*>(&s)) {
			mShields -= 12;
			if (mShields <= 0)
				mHealth -= 32;
			bool mightExplode = (rand() % 4) == 1;
			if (mightExplode)
				explode();
			if (mHealth <= 0 && mShields <= 0)
				explode();
		}
	}
};

class Planet : public Target
{
	public:
	Planet(std::string name, int health, int x, int y): Target(name, health,x,y)
	{
	}

	void loseHealth(const Target& s) override {
		if (nullptr == dynamic_cast<const Deathstar*>(&s))
			return;
		explode();
	}
};
#endif