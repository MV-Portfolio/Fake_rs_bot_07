
#include <stdio.h>
#include <time.h>
#include <iostream>
#include <string> 
#include <vector>
#include <fstream>
#include <sstream>
//#include <ctime>

#include "world.h"
#include "bot.h"

using namespace std;

extern bool start();
extern bool start2();
extern int intro();
extern void help();
extern void command(int*,world*,vector<bot>*,int,time_t*);
extern void botcommand();
extern void tester(); 

int main()
{


    bot *A;  //import required xp to level up, then deletes itself as xpgoals array is static
    A = new bot("?"); 
    A -> mining -> import_xpgoals(); //loads from xplevels file
    delete A; // bot A is no longer needed so is removed
    A = NULL;


    time_t time1; //keep track of time
    time (&time1); //sets starting time so it can be called later
    world *world_array; //An pointer array of worlds a person can put bots in
    int amountofworlds = 10; //chosen ammount of worlds
    world_array = new world[amountofworlds]; //creates amount of worlds with chosen ammount
    vector<bot> *bot_vector = new vector<bot>(); //vector of all bots made by plater
    int rsgp; //amount of money the player has
    rsgp = 0;

    
    bool a1 = start(); //sees if test would like to play or test or exit
    if (a1==true){
        intro(); 
        command(&rsgp,world_array,bot_vector,amountofworlds,&time1); //passes all pointers over to command function
    } else {
        bool a2 = start2(); 
        if (a2==true){
        	cout << ">>> lanching tester" << endl;
        	tester();
        } else {return 0;}
    }
    


    
    return 0;
}


