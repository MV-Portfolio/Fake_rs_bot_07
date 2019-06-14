#include "world.h"
#include "bot.h"
#include "skills.h"
#include <string> 
#include <vector>
#include <iostream>

using namespace std; 

//bot::bot(){
	//botid=idCount;
	//name = "?"
	//world = 0;
	//idCount++;
//}

bot::bot(string botname){
	botid=idCount;
	name = botname;
	gpsec=1;
	idCount++;
	X = new skills("mining");
	Y = new skills("woodcutting");
	Z = new skills("fishing");
}

string bot::get_botname(){
	return name;
}

int bot::get_gpsec(){
	return gpsec;
}

int bot::get_lvl(string skill_name){
	if (skill_name=="mining"){
		return X -> get_level();
	} else if (skill_name=="woodcutting"){
		return Y -> get_level();
	} else if (skill_name=="fishing"){
		return Z -> get_level();
	} else {cout << ">>> ERROR! No skill found" << endl;};
}

int bot::get_xp(string skill_name){
	if (skill_name=="mining"){
		return X -> get_xp();
	} else if (skill_name=="woodcutting"){
		return Y -> get_xp();
	} else if (skill_name=="fishing"){
		return Z -> get_xp();
	} else {cout << ">>> ERROR! No skill found" << endl;};
}

int bot::get_xp_till_lvl(string skill_name){
	if (skill_name=="mining"){
		return X -> get_xp_till_level();
	} else if (skill_name=="woodcutting"){
		return Y -> get_xp_till_level();
	} else if (skill_name=="fishing"){
		return Z -> get_xp_till_level();
	} else {cout << ">>> ERROR! No skill found" << endl;};
}

bot::~bot(){

}

int bot::idCount=0;