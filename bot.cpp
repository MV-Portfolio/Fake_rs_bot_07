#include "bot.h"
#include "items.h"


#include <string> 
#include <vector>
#include <iostream>
#include <fstream>


using namespace std; 


bot::bot(){
	botid=idCount;
	idCount++;
	name = "bot"+botid;
	gpsec=1;
	xpsec=0;
	currenttask="walking";
	mining = new skills("mining");
	woodcutting = new skills("woodcutting");
	fishing = new skills("fishing");
	attack = new skills("attack");
	worldloc=(-1);
}

bot::bot(string botname){
	botid=idCount;
	idCount++;
	name = botname;
	gpsec=1;
	xpsec=0;
	currenttask="walking";
	mining = new skills("mining");
	woodcutting = new skills("woodcutting");
	fishing = new skills("fishing");
	attack = new skills("attack");
	worldloc=(-1);
}

void bot::set_task(string taskname, task * jobtask){
	currenttask=taskname;
	job=jobtask;
}

void bot::set_gpsec(int gold){
	gpsec=gold;
}

void bot::set_xpsec(int xp){
	xpsec=xp;
}

string bot::get_botname(){
	return name;
}

string bot::get_task(){
	return currenttask;
}

int bot::get_id(){
	return botid;
}

int bot::get_gpsec(){
	return gpsec;
}

int bot::get_xpsec(){
	return xpsec;
}

int bot::get_worldid(){
	return worldloc;
}

void bot::set_world(int idnum){
	worldloc=idnum;
}

vector<item*> bot::get_vector(){
	return inventory;
}


int bot::get_mining_classlvl(){
	int best=(-1);
	for(int i=0;i<inventory.size();i++){
		if(inventory[i]->task_type()=="mining"){
			if(inventory[i]->get_metalclass()>best){
				best=inventory[i]->get_metalclass();
			}
		}
	}
	return best;
}

int bot::get_woodcutting_classlvl(){
	int best=(-1);
	for(int i=0;i<inventory.size();i++){
		if(inventory[i]->task_type()=="woodcutting"){
			if(inventory[i]->get_metalclass()>best){
				best=inventory[i]->get_metalclass();
			}
		}
	}
	return best;
}

int bot::get_fishing_classlvl(){
	int best=(-1);
	for(int i=0;i<inventory.size();i++){
		if(inventory[i]->task_type()=="fishing"){
			if(inventory[i]->get_metalclass()>best){
				best=inventory[i]->get_metalclass();
			}
		}
	}
	return best;
}


void bot::add_item(item *itemid){
	string check;
	check=itemid->task_type();
	if (check=="mining"){
		if (itemid->get_lvlrec()<=mining->get_level()){
			inventory.push_back(itemid);
		} 
		else {
			cout << ">>> bot "<<name<<" is too low level for that item" << endl;
		}
	}
	else if (check=="woodcutting"){
		if (itemid->get_lvlrec()<=woodcutting->get_level()){
			inventory.push_back(itemid);
		} 
		else {
			cout << ">>> bot "<<name<<" is too low level for that item" << endl;
		}
	}
	else if (check=="fishing")
	{
		if (itemid->get_lvlrec()<=fishing->get_level()){
			inventory.push_back(itemid);
		} 
		else {
			cout << ">>> bot "<<name<<" is too low level for that item" << endl;
		}
	}
	
}


void bot::print_items(){
	if(inventory.size()==0){
		cout << ">>> N/A ITEMS" << endl;
		return;
	}
	for (int i=0; i<inventory.size(); i++){
   	 	cout << inventory.at(i)->get_name() << endl;
   	}	
}


bot::~bot(){

}

int bot::idCount=0;

bot::skills::skills(string skillname){
	skill=skillname;
	xp=0;
	level=1;
	xpgoal=83;
}


void bot::skills::updatexp(int amount){
	bool newgoal = false;
	bool looper = true;
	//while(looper)
	if (amount<=0){
		return;
	}
	xp = xp+amount;
	while(looper){
		if (level==99){
			xpgoal=0;
			xp = 0;
			return;
		}
		else if (xp==xpgoal){
			xp=0;			
			level++;
			newgoal=true;
			looper=false;
		}
		else if (xp>xpgoal){
			xp = xp-xpgoal;
			level++;
			newgoal=true;
			looper=true;
		}
		else {looper=false;}

		if(newgoal){
			xpgoal=xp_array[level];
		}
	}
}

void bot::skills::print(){
	for (int i=0; i<99; i++){
		cout<<xp_array[i]<<endl;
	}
}


void bot::skills::import_xpgoals(){
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



string bot::skills::get_skill(){
	return skill;
}

int bot::skills::get_level(){
	return level;
}

int bot::skills::get_xp(){
	return xp;
}		

int bot::skills::get_xp_till_level(){
	return xpgoal-xp;
}



bot::skills::~skills(){

}

int bot::skills::xp_array[99]={};

















