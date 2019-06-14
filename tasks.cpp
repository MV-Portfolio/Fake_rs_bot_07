#include "tasks.h"
#include "items.h"



#include <string> 
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <cmath>

using namespace std;



task::task(){

	gpsec = 0;
	xp = 0;
	lvlreq = 0;
	taskname = "default";
}

int task::get_gpsec(){
	return gpsec;
}

int task::get_xp(){
	return xp;
}

int task::get_req_level(){
	return lvlreq;
}

string task::get_taskname(){
	return taskname;
}

string task::get_req_tool_type(){
	return reqtooltype;
}



task::~task(){

}


//WALK AROUND

walk_around::walk_around(){
	gpsec = 1;
	xp = 0;
	lvlreq = 0;
	taskname = "walking";
	reqtooltype = "?";
}


void walk_around::set_tool_level(int tlevel){
	gpsec = 1;
	xp = 0;
}


walk_around::~walk_around(){

}



//MINING

mining::mining() {
	gpsec = 1;
	xp = 1;
	lvlreq = 1;
	taskname = "mining";
	reqtooltype = "mining";
}


void mining::set_tool_level(int tlevel){
	if (tlevel == -1){
		cout << "You do not have the required tool to mine that" << endl;
	}	
	else if(tlevel != -1){
		gpsec = 10*pow((tlevel),3)+30;
		xp = 10*(pow(tlevel,2))+10;
	}
}

mining::~mining(){

}



//WOODCUTTING

woodcutting::woodcutting(){
	gpsec = 1;
	xp = 1;
	lvlreq = 1;
	taskname = "woodcutting";
	reqtooltype = "woodcutting";
}


void woodcutting::set_tool_level(int tlevel){
	if (tlevel == -1){
		cout << "You do not have the required tool to chop that" << endl;
	}	
	else if(tlevel != -1){
		gpsec = 10*pow((tlevel),2)+10;
		xp = 10*(pow(tlevel,3))+30;
	}
}

woodcutting::~woodcutting(){

}





//FISHING

fishing::fishing() {
	gpsec = 15;
	xp = 20;
	lvlreq = 1;
	taskname = "fishing";
	reqtooltype = "fishing";

}


void fishing::set_tool_level(int tlevel){
	if (tlevel == -1){
		cout << "You do not have the required tool to fish that" << endl;
	}	
	else if(tlevel != -1){
		gpsec = 15;
		xp = 20;
	}

}

fishing::~fishing(){

}














