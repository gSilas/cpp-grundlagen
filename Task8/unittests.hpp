#include "target.hpp"
#include <iostream>
#include <fstream>

void say(std::string msg){
    std::cout << msg << std::endl;
}

void testPlanet(){
	say("PLANET TESTING");
	Planet p("testplanet", 50,10,10 );
	Spaceship s("ship that destroys",50,0,0,0);
	Deathstar d("darkstar",100,6,6);
	int oldhealth = p.getHealth();
	s.attack(p);
	if (p.getHealth() == oldhealth)
	{
		say("1. planet takes no damage from spaceships");
	}

	d.attack(p);
	if(p.isDestroyed() == true)
	{
		say("2. planet destroyed by deathstar");
	}

	//p.attack not possbile
}

void testSpaceship()
{
	say("SPACESHIP TESTING");
	Spaceship s1("ship", 50, 0, 0,50);
	Spaceship s2("ship", 50, 0, 0,0);
	Spaceship s3("ship", 50, 0, 0,50);

	// the spaceship must generate damage
	int oldHealth = s2.getHealth();
	int oldShield = s3.getShield();
	s1.attack(s2);
	if (s2.getHealth() < oldHealth) {
		say("3. spaceship could damage other spaceship");
	}
	s1.attack(s3);
	if(s3.getShield() < oldShield){
		say("4. spaceship could damage other spaceships shield");
	}

	while (s2.getHealth() > 0)
		s1.attack(s2);

	if (s2.isDestroyed()) {
		say("5. spaceship can destroy spaceship");
	}

}

void testDeathstar()
{
	say("DEATHSTAR TESTING");
	Spaceship s1("ship", 50, 0, 0, 50);
	Deathstar d("star", 1000, 0, 0);
	int times = 0;
	int destroyedtimes = 0;

	while (times < 1000000) {
		s1.attack(d);
		times++;
		// random chance kicked in, restart
		if (d.isDestroyed()) {
			d = Deathstar("star", 1000, 0, 0);
			destroyedtimes++;
			}
	}

	std::cout << ((float)destroyedtimes / (float)times)*100 << " % of times in " << times << " tries destroyed" << std::endl;
}