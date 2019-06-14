#include <string> 
#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

#include "world.h"
#include "bot.h"
#include "skills.h"


skills::skills(string skillname){
	skill=skillname;
	xp=0;
	level=1;
	xpgoal=83;
}


void skills::updatexp(int amount){
	newgoal = false;
	if (level=99){
		return;
	}
	else if (xp+amount==xpgoal){
		xp=0;
		level++;
		newgoal=true;
	}
	else if (xp+amount>xpgoal){
		xp = xp+amount-xpgoal;
		level++;
		newgoal=true;
	}
	else{
		xp=xp+amount;
	}
	if(newgoal){
		xpgoal=xp_array[level];
	}
}

void skills::print(){
	for (int i=0; i<99; i++){
		cout<<xp_array[i]<<endl;
	}
}


void skills::import_xpgoals(){
	ifstream lvl("xplevels.csv");
	exp.clear();
    exp.str("");
	for (int i=0; i<99; i++){
    	getline(lvl,filexpgoal, '\n');
    	exp.str(filexpgoal);
    	exp>>xpgoalset;
		xp_array[i]=xpgoalset;
	}
   lvl.close();
}

string skills::get_skill(){
	return skill;
}

int skills::get_level(){
	return level;
}

int skills::get_xp(){
	return xp;
}		

int skills::get_xp_till_level(){
	return xpgoal-xp;
}


skills::~skills(){

}

int skills::xp_array[99]={};
