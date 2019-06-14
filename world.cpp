
#include <string> 
#include <vector>
#include <iostream>

using namespace std;

#include "world.h"
#include "bot.h"

world::world(){
    worldID=currentID;
    population=0;
    currentID++;

}

int world::get_pop(){
	return population;
}

int world::get_max(){
	return maxplayer;
}

int world::get_ID(){
	return worldID;
}

void world::add_bot(bot *botName){
	for (int i=0; i<population; i++){
		if (botVector.at(i).get_id()==botName -> get_id()){
			cout << ">>> bot is already added too world "<< worldID <<endl;
			return;
		}
	}
	if (botName->get_worldid()>=0){
		cout << ">>> bot is already in world " << botName ->get_worldid() << endl;
		return;
	} 
	else if (population>=maxplayer){
		cout << ">>> world " << worldID <<" is already full." << endl;
	} 
	else {
		botName -> set_world(worldID);
		botVector.push_back(*botName);
		population++;
	}
}

void world::set_max(int maxi){
	maxplayer=maxi;
}

void world::print_bots(){
	if(botVector.size()==0){
		cout << ">>> N/A BOTS" << endl;
		return;
	}
	for (int i=0; i<botVector.size(); i++){
   	 	cout << botVector.at(i).get_botname() << endl;
   	}	
}


world::~world(){
    
}

int world::currentID=1;
int world::maxplayer=25;