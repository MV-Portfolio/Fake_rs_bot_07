#include <stdio.h>
#include <time.h>
#include <iostream>
#include <string> 
#include <vector>
//#include <ctime>
#include <climits>
#include <sstream>
#include <cstdlib>
//#include <conio.h>

#include "world.h"
#include "bot.h"
using namespace std;

void create(world *worldlist,vector<bot> *botlist,int amountofworlds){
	string name,idloc;
	bool space=false;
	int worldnum= (-1);
	int steps=0;
	stringstream a1;
	//add max letters of 8
	//add letter min of 2
	for (int i=0; i<amountofworlds; i++){
		if ((worldlist+i)->get_pop()<((worldlist+i)->get_max())){
			space=true;
		}
	}
	if (space==false){
		cout << endl << endl;
		cout << ">>> All worlds are currently full." << endl;
		cout << endl << endl;
		return;
	}
	while(steps==0){
		steps++;
		cout << "USERNAME: ";
		getline(cin,name);
		if (name.size()<=1 || name.size()>=10){
			steps=0;
			cout << ">>> Username must be between 2 to 9 characters" << endl;
		}
		for (int i=0; i<botlist->size(); i++){
        	if (name==botlist->at(i).get_botname()){
        		cout << ">>> Username already taken, please try again." << endl;
        		steps=0;
        	}	
    	}
    }
    while(steps==1){
    	steps++;
		cout << "WORLD ID: ";
        a1.clear();
        a1.str("");
        //input.clear;
        getline(cin,idloc);
        a1.str(idloc);
        a1>>worldnum;
		if (worldnum>amountofworlds || worldnum<=0){
			cout << ">>> No world found. Please enter ID number between 1 and " << amountofworlds<<  endl;
			steps=1;
		}
		else if (((worldlist+worldnum)->get_pop())>=((worldlist+worldnum)->get_max())){
			cout << ">>> World full, please select differnt world." << endl;
			steps=1;
		} 
	}
	bot *A;
	A = new bot(name);
	//A->set_world(worldnum);
	(worldlist+worldnum-1)->add_bot(A);
	botlist->push_back(*A);
	cout << ">>> BOT CREATED!" << endl;
	//need to add world location to bot class
}

void worlds(world *worldlist,int amountofworlds){
    for (int i=0; i<amountofworlds; i++){
        cout << "world ID: " << i+1 << " , amount of players: " << (worldlist+i)->get_pop() <<endl;
    }
}

void list(vector<bot> *botlist){
	cout << "---- Bot ID ------- Username -------- Current task -------- Gold Per Second -------- World ID ----" << endl;
	for (int i=0; i<botlist->size(); i++){
        cout << "	"<<botlist->at(i).get_id()<<"	      " <<botlist->at(i).get_botname() << "		"<< botlist->at(i).get_task() << " 		 " << botlist->at(i).get_gpsec()<<"			"<<botlist->at(i).get_worldid() <<endl;
    }
    //cout << name << id << level << task << gpsec << world
}


void update(int *rsgp,time_t *lastupdate,vector<bot> *botlist){
	time_t current;
	time (&current);

	//gold
	int earnt=0;
	if (botlist->size()==0){
		time (lastupdate);
		return;
	}
	for (int i=0; i<botlist->size(); i++){
		earnt=earnt+botlist->at(i).get_gpsec();
	}
	int dif = difftime(current,*lastupdate);
	*rsgp=*(rsgp)+(earnt*dif);

	//xpupdate
	string tasker="?";
	int c_xpsec=0;
	int xpammount=0;
	if (botlist->size()==0){
		time (lastupdate);
		return;
	}
	for (int i=0; i<botlist->size(); i++){
		c_xpsec=botlist->at(i).get_xpsec();
		if (c_xpsec>0){
			tasker=botlist->at(i).get_task();
			xpammount=c_xpsec*dif;
			if (tasker=="mining"){
				(botlist->at(i)).mining -> updatexp(xpammount);
			}
			else if (tasker=="woodcutting"){
				(botlist->at(i)).woodcutting -> updatexp(xpammount);
			}
			else if (tasker=="fishing"){
				(botlist->at(i)).fishing -> updatexp(xpammount);
			}
		}
	}

	time (lastupdate);
	return;
}



void slaygoblin(int *rsgp){
	//http://runescape.wikia.com/wiki/Coins
	int drop = rand() % 24 + 1;
	cout << ">>>The goblin dropped " << drop << " gp" << endl;
	*rsgp=*(rsgp)+drop;
}

