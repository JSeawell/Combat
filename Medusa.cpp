/******************************
 
 Name: Jake Seawell
 Date: 10/23/18
 Description:
 This is the class source/
 implementation file for a class
 called Medusa, which inherits
 from Character class, which
 represents characters is a
 fantasy combat game.
 
 ******************************/

#include "Medusa.hpp"
#include "intVal.hpp"

#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;

/******************************
 Constructor
 ******************************/
Medusa::Medusa(string name1) : Character("Medusa", 3, 8)
{
	name = name1;
}

/******************************
       Medusa::getName()
 ******************************/
string Medusa::getName()
{
    return name;
}

/******************************
 Medusa::isDead
 ******************************/
bool Medusa::isDead()
{
    if (strength <= 0)
        return true;
    else
        return false;
}

/******************************
 Medusa::attack()
 
 This function generates a random
 attack based on the character's
 abilities, then returns that num.
 
 ******************************/
int Medusa::attack()
{
    int ad1 = minMaxRand(1,6);
    int ad2 = minMaxRand(1,6);
    cout << "Medusa rolls: " << ad1 << ", " << ad2 << endl;
    int attackDamage = 0;
    if ((ad1 + ad2) == 12)
    {
        cout << "Medusa attacking with--> special ability: 'Glare'." << endl;
        attackDamage = 100;
	return attackDamage;
    }
    else
    {
        attackDamage = (ad1 + ad2);
        cout << "Medusa attacking with--> " << attackDamage << endl;
        return attackDamage;
    }
}

/******************************
 Medusa::defend()
 
 This function takes an attack
 as an argument, then generates
 a random defense based on the
 character's abilities.
 
 Neccessary armor is applied,
 damage is calculated, and
 strength points are updated
 and returned.
 
 ******************************/
int Medusa::defend(int attackDamage)
{
    if (strength <= 0)
    {
        cout << "Medusa is already dead." << endl;
    }
    else if (attackDamage == 100)
    {
	cout << "Medusa was instantly turned to stone. How ironic." << endl;
	attackDamage = 99;
	strength = 0;
    }
    else if (attackDamage < 100)
    {
        int defense = minMaxRand(1,6);
        cout << "Medusa rolls: " << defense << endl;
        cout << "Medusa defends with: " << defense << endl;
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
            cout << armor << "/3 armor applied to: " << attackDamage << endl;
        }
        else if (attackDamage > 0 && attackDamage < armor)
        {
            actualDamage = 0;
            cout << attackDamage << "/3 armor applied to: " << attackDamage << endl;
        }
        
	cout << "Medusa's strength before: " << strength << endl;
        cout << "Damage taken: " << actualDamage << endl;
        
        strength = (strength - actualDamage);
        if (strength < 0)
            strength = 0;
        
        cout << "Medusa's strength left: " << strength << endl;
        
        if (strength == 0)
            cout << "Medusa died." << endl;
    }
    return strength;
}
