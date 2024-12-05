#include <iostream>
using namespace std;

/*
// program goal:

simulate battle between two pokemon:

this includes simulating two pokemon exchanging attacks until one dies

so what are "pokemon", what kind of data do they have

for our purpose, we'll simplify it and say pokemon just have:
HP, DEF, ATK, SPD

So we want two pokemon fighting

this means they trade attacking eachother until one's HP falls to 0 (or below)

*/

struct Pokemon
{
    int hp;
    int atk;
    int def;
    int spd;
   
    // constructor is a special function that is called ONCE
    // exactly when an instance of a class/struct is declared
    Pokemon(int startingHp, int startingAtk, int startingDef, int startingSpd)
    {
        this->hp = startingHp;
        this->atk = startingAtk;
        this->def = startingDef;
        this->spd = startingSpd;
    }
   
    // member function
    void attack(Pokemon* target)
    {
        target->hp -= this->atk - this->def;
    }
   
};

int MenuSystem()
{
    int choice;

    cout << "______     _                               ______ _       _     _   _               _____ _                 _       _             " << endl;
    cout << "| ___ \\   | |                              |  ___(_)     | |   | | (_)             /  ___(_)               | |     | |            " << endl;
    cout << "| |_/ /__ | | _____ _ __ ___   ___  _ __   | |_   _  __ _| |__ | |_ _ _ __   __ _ \\ `--. _ _ __ ___  _   _| | __ _| |_ ___  _ __ " << endl;
    cout << "|  __/ _ \\| |/ / _ \\ '_ ` _ \\ / _ \\| '_ \\  |  _| | |/ _` | '_ \\| __| | '_ \\ / _` |  `--. \\ | '_ ` _ \\| | | | |/ _` | __/ _ \\| '__|" << endl;
    cout << "| | | (_) |   <  __/ | | | | | (_) | | | | | |   | | (_| | | | | |_| | | | | (_| | /\\__/ / | | | | | | |_| | | (_| | || (_) | |   " << endl;
    cout <<"\\_| \\___/|_|\\_\\___|_| |_| |_|\\___/|_| |_|\\_|   |_|\\__, |_| |_|\\__|_|_| |_|\\__, |\\____/|_|_| |_| |_|\\__,_|_|\\__,_|\\__\\___/|_|   " << endl;
    cout << "                                                     __/ |                   __/ |                                                " << endl;
    cout << "                                                    |___/                   |___/                                                 " << endl;
    
    cout << endl << endl;

    cout << "1. Create a Pokemon" << endl;
    cout << "2. Choose a Pokemon" << endl;
    cout << "3. Quit" << endl;
    cout << "Your Choice: ";
    cin >> choice;

    return choice;
}

// creating a pokemon by passing the Pokemon struct and possibly using a constructor
void createPokemon()
{

}

int main()
{
    int menuChoice = MenuSystem();

//    cout << " |_| |_| |_| " << endl;

    // creating instance of pokemon struct
    Pokemon p1(20, 2, 0, 1);    // (hp, atk, def, spd)
    Pokemon p2(20, 3, 0, 3);
   
    // p1 attacks p2
   // p1.attack(&p2);
   

   if (p1.spd > p2.spd)
   {
    cout << "P1 is faster than P2, P1 attacks first" << endl << endl;
   }
   else
   {
    cout << "P2 is faster than P1, P2 attacks first" << endl << endl;
   }
   
    while (p1.hp >= 0 && p2.hp >= 0)
    {
        bool is1Faster{ p1.spd > p2.spd };
       
        if (is1Faster)
        {
            // first pokemon attacks
            // p1 attacks p2
            cout << "P1 attacks first, Attack: " << p1.atk << endl;
            p1.attack(&p2);
            std::cout << "P2's HP: " << p2.hp << endl << endl;
           
            if (p2.hp > 0)
            {
                // second pokemon attcks 1
                cout << "P2 attacks second, Attack: " << p2.atk << endl;
                p2.attack(&p1);
                std::cout << "P1's HP: " << p1.hp << endl << endl;
            }
            else
            {
                std::cout << "P1 won\n";
                break;
            }

            cout << endl;
        }
        else
        {
            // second pokemon attacks
                cout << "P2 attacks first, Attack: " << p2.atk << endl;
            p2.attack(&p1);
            std::cout << "P1's HP: " << p1.hp << endl << endl;
           
            if (p1.hp > 0)
            {
                // first pokemon attcks 2
                cout << "P1 attacks second, Attack: " << p1.atk << endl;
                p2.attack(&p1);
                std::cout << "P2's HP: " << p2.hp << endl << endl;
            }
            else
            {
                std::cout << "P2 won\n";
                break;
            }

            cout << endl;
        }
    }

    return 0;
}