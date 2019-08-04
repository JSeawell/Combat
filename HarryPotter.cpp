/******************************
 
 Name: Jake Seawell
 Date: 10/23/18
 Description:
 This is the class source/
 implementation file for a class
 called HarryPotter, which inherits
 from Character class, which
 represents characters is a
 fantasy combat game.
 
 ******************************/

#include "HarryPotter.hpp"
#include "intVal.hpp"

#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;

/******************************
 Constructor
 ******************************/
HarryPotter::HarryPotter(string name1) : Character("Harry Potter", 0, 10)
{
    	name = name1;
	extraLives = 1;
}

/******************************
       HarryPotter::getName()
 ******************************/
string HarryPotter::getName()
{
    return name;
}

/******************************
 HarryPotter::isDead
 ******************************/
bool HarryPotter::isDead()
{
    if (extraLives == 0 && strength <= 0)
        return true;
    else
        return false;
}

/******************************
 HarryPotter::attack()
 
 This function generates a random
 attack based on the character's
 abilities, then returns that num.
 
 ******************************/
int HarryPotter::attack()
{
    int ad1 = minMaxRand(1,6);
    int ad2 = minMaxRand(1,6);
    cout << "Harry Potter rolls: " << ad1 << ", " << ad2 << endl;
    int attackDamage = (ad1 + ad2);
    cout << "Harry Potter attacking with--> " << attackDamage << endl;
    return attackDamage;
}

/******************************
 HarryPotter::defend()
 
 This function takes an attack
 as an argument, then generates
 a random defense based on the
 character's abilities.
 
 Neccessary armor is applied,
 damage is calculated, and
 strength points are updated
 and returned.
 
 ******************************/
int HarryPotter::defend(int attackDamage)
{
    if (strength <= 0)
    {
        cout << "Harry Potter is already dead." << endl;
    }
    else if (attackDamage == 100)
    {
        cout << "Harry Potter was instantly turned to stone." << endl;
        strength = 0;
        if (extraLives > 0)
        {
        	cout << "Luckily, he uses his special ability 'Hogwarts' to come back to life with double the strength!" << endl;
        	extraLives = extraLives - 1;
        	strength = 20;
        }
    }
    else
    {
        int d1 = minMaxRand(1,6);
        int d2 = minMaxRand(1,6);
        cout << "Harry Potter rolls: " << d1 << ", " << d2 << endl;
	int defense = (d1 + d2);
        cout << "Harry Potter defends with: " << defense << endl;
	attackDamage = (attackDamage - defense);
        
        int actualDamage = 0;
        if (attackDamage <= 0)
        {
            actualDamage = 0;
            cout << "No armor needed. None applied." << endl;
        }
        else if (attackDamage > 0 && attackDamage >= armor)
        {
            actualDamage = (attackDamage - armor);
            cout << armor << "/0 armor applied to: " << attackDamage << endl;
        }
        else if (attackDamage > 0 && attackDamage < armor)
        {
            actualDamage = 0;
            cout << attackDamage << "/" << armor << " armor applied to: " << attackDamage << endl;
        }
        
	cout << "Harry Potter strength before: " << strength << endl;
        cout << "Damage taken: " << actualDamage << endl;
        
        strength = (strength - actualDamage);
        if (strength < 0)
            strength = 0;
        
        cout << "Harry Potter's strength left: " << strength << endl;
        
        if (strength == 0)
        {    
		cout << "Harry Potter died." << endl;
            	if (extraLives > 0)
            	{
                	cout << "Luckily, he uses his special ability 'Hogwarts' to come back to life with double the strength!" << endl;
                	extraLives = extraLives - 1;
                	strength = 20;
            	}
    	}
    }
    return strength;
}
