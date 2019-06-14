#include <stdio.h>
#include <time.h>
#include <iostream>
#include <string> 
#include <vector>
#include <climits>
#include <sstream>


#include "world.h"
#include "bot.h"
#include "tasks.h"

using namespace std;

extern void help2();
extern void botcommand(bot*,int*,time_t*,vector<bot>*);
extern void create(world*,vector<bot>*,int);
extern void list(vector<bot>*);
extern void worlds(world*,int);
extern void update(int*,time_t*,vector<bot>*);
extern void slaygoblin(int*);


bool start(){
    cout << endl << endl << endl;
    cout << "          			~~~~~~~~WELCOME~~~~~~~~" << endl;
    cout << "             			    FAKE RS BOT 07" << endl;
    cout << "          			~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << endl << endl;
    string startup;
    while(1){
        cout << "Would you like to start a new game? (y/n):   ";
        getline(cin,startup);

        if (startup=="y"){
            cout << endl << endl;
            cout << ">>> Loading game..." << endl;
            return true;
        } else if (startup=="n"){
            cout << endl << endl;
            cout  << ">>> okay..." << endl;
            return false;
        } else { cout << endl << ">>> sorry I don't understand, please try again." << endl << endl;
            }
    }
}

void intro(){
    cout << endl << endl;
    cout << "		~~~~~~~~~~~~~~~~~~~~~~ NEW GAME ~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << "          		AIM:    Collect as much rsgp as you can" << endl;
    cout << "          		HOW:    Create bots and farm gp\n                 		level up bots and buy new items\n      	             		to earn more gold faster!" << endl;
    cout << "          		WHY:    Why not?" << endl;
    cout << "          		SIDE NOTE:    Each world can hold upto\n                                      a maximum of 25 bots" << endl;
    cout << "		~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << "          			Type 'help' for list of commands" << endl << endl;
}	

void help(){
    cout << endl << endl;
    cout << "-------COMMAND LIST-------" << endl;
    cout << "'create' : Make a new bot" << endl;
    cout << "'gold' : Check how much gp you have" << endl;
    cout << "'slaygoblin' : gives player 10gp" << endl;
    cout << "'list' : list all current bots" << endl;
    cout << "'worlds' : print amount of players in each world"  <<endl;
    cout << "'worldbots' : prints all bots in selected world" << endl;
    cout << "'select' : select a bot" << endl;
    cout << "'help2' : list of bot commands" << endl;
    cout << "'r' : repeat previous command" << endl;    
    cout << "'exit' : end program" << endl;
    cout << "-------END O F LIST-------" << endl;
    cout << endl << endl;
}




void command(int *rsgold, world *worldlist, vector<bot> *botlist, int amountofworlds, time_t *timer){
    string task, botselect, input;
    string repeat="help";
    stringstream mv;
    int worldid=(-1);
    while(1){
    	update(rsgold,timer,botlist);
    	bool error=true;
    	cout << "Enter command: ";
        while (error){ //incase of the use of cin -> cin causes geetline to be skipped. 
        	getline(cin,task);
        	if(task!="\n" && task != ""){
        		error=false;
        	} 
    	}
        if (task=="r"){
            task=repeat;
        }
		if (task=="help"){
          help();
        } 
        else if (task=="help2"){
          help2();
        } 
        else if (task=="select"){
        	bool passed = false;
        	if ((botlist->size())>=1){
	        	cout << ">>> Name/s of all bots: "; 
	        	for (int i = 0; i < botlist->size(); ++i)
	        	{
	        		cout <<"'"<< (botlist->at(i)).get_botname() << "'	";
	        	}
	        	cout << endl;
	            for (int j=0; j<3; j++){
	            	if (passed==false){
	            		cout << "Enter bot name: ";
	            		getline(cin,botselect);
	            		for (int i=0; i<botlist->size(); i++){
	            			if (botselect==botlist->at(i).get_botname()){
	            				botcommand(&(botlist->at(i)),rsgold,timer,botlist);
	            				passed=true;
	            			}	
	        			}
	        			if (passed==false){
	        				cout << ">>> Bot not found please try again" << endl;
	        			}
	        		}
	        	}
	        	if (passed==false){
	        	cout << ">>> Three attempts failed, returning to commands" << endl;
	        	cout << ">>> Use 'list' to list all current bots" << endl;
	        	}
	        }
	        else 
	        {
	        	cout << ">>> You haven't made any bots yet, use the command 'create' to make a bot" << endl;
	        }
        } 
        else if (task=="create"){
        	create(worldlist,botlist,amountofworlds);
        } 
        else if (task=="worlds"){
        	worlds(worldlist,amountofworlds);
        }
        else if (task=="list"){
        	list(botlist);
        }
        else if (task=="gold"){
			update(rsgold,timer,botlist);
        	cout << ">>> You currently have: " << *rsgold << " gp" << endl;
        }
        else if (task=="slaygoblin"){
        	slaygoblin(rsgold);
        }
        else if (task=="worldbots"){
        	bool found = false;
            while(found==false){
            	cout << "Enter world id: ";
            	mv.clear();
        		mv.str("");
            	getline(cin,input);
            	mv.str(input);
            	mv>>worldid;
				if (worldid<=amountofworlds && worldid>0){
					found=true;
				} 
				else {
				cout << ">>> No world found. Please try again" << endl;
				}
			}
			(worldlist+worldid)->print_bots();
        }
        else if (task=="exit"){
            return;
        } 
        else {
            cout << endl << "sorry I don't understand, please try again." << endl;
            cout << "Type 'help' for list of commands" << endl << endl;
        }
        repeat=task;
    }
}






