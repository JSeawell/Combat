/******************************
 
 Name: Jake Seawell
 Date: 10/23/18
 Description:
 This is the class source/
 implementation file for a class
 called Vampire, which inherits
 from Character class, which
 represents characters is a
 fantasy combat game.
 
 ******************************/

#include "Vampire.hpp"
#include "intVal.hpp"

#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;

/******************************
 Constructor
 ******************************/
Vampire::Vampire(string name1) : Character("Vampire", 1, 18)
{
	name = name1; 
}

/******************************
       Vampire::getName()
 ******************************/
string Vampire::getName()
{
    return name;
}

/******************************
 Vampire::isDead
 ******************************/
bool Vampire::isDead()
{
    if (strength <= 0)
        return true;
    else
        return false;
}

/******************************
 Vampire::attack()
 
 This function generates a random
 attack based on the character's
 abilities, then returns that num.
 
 ******************************/
int Vampire::attack()
{
    int attackDamage = minMaxRand(1,12);
    cout << "Vampire rolls: " << attackDamage << endl;
    cout << "Vampire attacking with--> " << attackDamage << endl;
    return attackDamage;
}

/******************************
 Vampire::defend()
 
 This function takes an attack
 as an argument, then generates
 a random defense based on the
 character's abilities.
 
 Neccessary armor is applied,
 damage is calculated, and
 strength points are updated
 and returned.
 
 ******************************/
int Vampire::defend(int attackDamage)
{
    if (strength <= 0)
    {
        cout << "Vampire is already dead." << endl;
    }
    else
    {
        cout << "Vampire tries to use special ability: 'Charm'." << endl;
        int charm = minMaxRand(1,2);
        if (charm == 1)
        {
            cout << "It worked this time!" << endl;
            if (attackDamage == 100)
                cout << "Medusa's 'Glare' was blocked!" << endl;
            else
                cout << "The enemy decided not to attack." << endl;
            
            attackDamage = 0;
        }
        else if (charm == 2)
        {
            cout << "Charm didn't work this time." << endl;
            
            if (attackDamage == 100)
            {
                cout << "Vampire was instantly turned to stone." << endl;
                strength = 0;
            }
            else
            {
                int d1 = minMaxRand(1,6);
                int d2 = minMaxRand(1,6);
                cout << "Vampire rolls: " << d1 << ", " << d2 << endl;
                int defense = (d1 + d2);
                cout << "Vampire defends with: " << defense << endl;
                attackDamage = (attackDamage - defense);
            }
        }
        
        if (attackDamage !=100)
        {
            int actualDamage = 0;
        	if (attackDamage <= 0)
        	{
            		actualDamage = 0;
            		cout << "No armor needed. None applied." << endl;
        	}
        	else if (attackDamage > 0 && attackDamage >= armor)
        	{
            		actualDamage = (attackDamage - armor);
            		cout << armor << "/1 armor applied to: " << attackDamage << endl;
        	}
        	else if (attackDamage > 0 && attackDamage < armor)
        	{
            		actualDamage = 0;
            		cout << attackDamage << "/1 armor applied to: " << attackDamage << endl;
        	}
        
        	cout << "Vampire strength before: " << strength << endl;
        	cout << "Damage taken: " << actualDamage << endl;
        
        	strength = (strength - actualDamage);
        	if (strength < 0)
            		strength = 0;
        
        	cout << "Vampire strength left: " << strength << endl;
        }
        if (strength == 0)
            cout << "Vampire died." << endl;
    }
    return strength;
}
