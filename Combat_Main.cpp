/******************************
 
 Name: Jake Seawell
 Date: 10/23/18
 Description:
 This is the main function
 for running/testing a
 fantasy combat game.
 
 ******************************/

// Header files needed
#include "Character.hpp"
#include "Barbarian.hpp"
#include "Vampire.hpp"
#include "BlueMen.hpp"
#include "Medusa.hpp"
#include "HarryPotter.hpp"
#include "choiceFunction.hpp"
#include "Menu.hpp"
#include "intVal.hpp"

// Rand libraries needed
#include <cstdlib>
#include <time.h>

//stream libraries needed
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

main()
{
    // User prompted to play or quit
    int playOrNaw = choiceFunction("::Fantasy Combat:", "Play game", "Quit game");

    // If play is chosen
    if (playOrNaw == 1)
    {
	
	// 2 pointers to characters created
    Character* char1 = 0;
	Character* char2 = 0;

	// Seed all rand functions (done only once)
    srand(time(0));
        
    //create character selection menu
    Menu menu1(5, "::Character Selection::");
    menu1.setOption(1, "Barbarian");
    menu1.setOption(2, "Vampire");
    menu1.setOption(3, "BlueMen");
    menu1.setOption(4, "Medusa");
    menu1.setOption(5, "Harry Potter");
        
	int playAgain = 0;
	
  // Do-while loops until game is quit/exited
  do
  {
            // Character 1 chooses player
            cout << "Select Player 1's character:" << endl;
		    int choice1 = minMaxValidation(menu1.displayMenu(),0,5);
 
        	if (choice1 == 1)
            		char1 = new Barbarian("Barbarian");
        	else if (choice1 == 2)
            		char1 = new Vampire("Vampire");
        	else if (choice1 == 3)
            		char1 = new BlueMen("BlueMen");
        	else if (choice1 == 4)
            		char1 = new Medusa("Medusa");
        	else if (choice1 == 5)
            		char1 = new HarryPotter("Harry Potter");
            else if (choice1 == 0)
			break;

        	
            // Character 2 chooses player
            cout << endl << "Select Player 2's character:" << endl;
		    int choice2 = minMaxValidation(menu1.displayMenu(),0,5);

        	if (choice2 == 1)
            		char2 = new Barbarian("Barbarian");
        	else if (choice2 == 2)
            		char2 = new Vampire("Vampire");
        	else if (choice2 == 3)
            		char2 = new BlueMen("BlueMen");
        	else if (choice2 == 4)
            		char2 = new Medusa("Medusa");
        	else if (choice2 == 5)
            		char2 = new HarryPotter("Harry Potter");
            else if (choice2 == 0)
			break;
	
            cout << "__________________________" << endl;
            cout << "Press enter to begin." << endl;
		
            // Pause before starting game
            cin.ignore();
 
        
            // Round begins
            int round = 0;
    		
            //While loop until a character dies
            while (!char1->isDead() && !char2->isDead())
    		{	
			round = round + 1;
			cin.ignore();
			cout << "__________________________" << endl;
            cout << "Round: " << round << endl;
            cout << endl;
            
            // Player 1 attacks
            cout << "Player 1's ";
			int attack1 = char1->attack();
        		
            // Player 2 defends
            cout << "Player 2's ";
			char2->defend(attack1);

                //If character 2 is still alive
                if (!char2->isDead())
                {
                    cout << endl;
                    
                    // Player 2 attacks
                    cout << "Player 2's ";
                    int attack2 = char2->attack();
                    
                    // Player 2 defends
                    cout << "Player 1's ";
                    char1->defend(attack2);
                    cout << "__________________________" << endl;
                    cout << "Press enter to continue." << endl;
                }
            }

            // If character 1 died and ended round
    		if (char1->isDead())
            {
                cout << endl << "Player 1's " << char1->getName() << " died in round ";
                cout << round << "." << endl;
            }
        
            // If character 2 died and ended round
            else if (char2->isDead())
            {
			cout << endl << "Player 2's " << char2->getName() << " died in round ";
			cout << round << "." << endl;
    		}		
            cout << "__________________________" << endl;
        
            // Game over, prompt user to play again or quit
            playAgain = choiceFunction("Would you like to play again?", "Yes, play again", "No thanks, quit the game");

		// Delete dynamically allocated character objects
        delete char1;
		delete char2;

	} while (playAgain == 1);
        
  }
  
  // Game over. End program
  cout << "Game over." << endl;
  return 0;
}
