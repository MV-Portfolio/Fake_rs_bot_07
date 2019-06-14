
#include "items.h"

#include <string> 
#include <vector>
#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

// START OF ITEMS

int item::get_cost(){
	return cost;
}

int item::get_lvlrec(){
	return lvlrec;
}

int item::get_lvlrec2(){
	return lvlrec2;
}

int item::get_metalclass(){
	return metalclass1;
}

item::~item(){

}



//  START OF PICKAXE


pickaxe::pickaxe(){
	metalclass1=0;
	cost = 0;
	lvlrec = 0;
	lvlrec2 = 0;
}

pickaxe::pickaxe(int metalclass){
	metalclass1=metalclass;
	cost = pow(metalclass,5)*100+600;
	lvlrec = metalclass*7;
	lvlrec2 = 0;
}

string pickaxe::task_type(){
	return "mining";
}

string pickaxe::shop_name(int numb){
	return metalnames[numb];
}

int pickaxe::shop_lvlrec(int numb){
	return numb*7;
}

int pickaxe::shop_cost(int numb){
	return pow(numb,5)*100+600;
}

int pickaxe::item_arraysize(){
	return 9; //fix this so that the number can be dinamic
}

int pickaxe::name_to_numb(string metaltype){
 	for (int i=0; i<9; i++){
 		if (metaltype==metalnames[i]){
 			return i;
 		}
 	}
 	return -1; 
}

void pickaxe::set_metalclass(int metalnumber){
	metalclass1=metalnumber;
	cost = pow(metalnumber,5)*100+600;
	lvlrec = metalnumber*7;
	lvlrec2 = 0;
}

string pickaxe::get_name(){
	return metalnames[metalclass1]+" pickaxe";
}

pickaxe::~pickaxe(){

}



// START OF HATCHET

hatchet::hatchet(){
	metalclass1=0;
	cost = 0;
	lvlrec = 0;
	lvlrec2 = 0;
}

hatchet::hatchet(int metalclass){
	metalclass1=metalclass;
	cost = pow(metalclass,4)*300+400;
	lvlrec = metalclass*10+1;
	lvlrec2 = 0;
}

string hatchet::task_type(){
	return "woodcutting";
}

string hatchet::shop_name(int numb){
	return metalnames[numb];
}

int hatchet::shop_lvlrec(int numb){
	return numb*10+1;
}

int hatchet::shop_cost(int numb){
	return pow(numb,4)*300+400;
}

int hatchet::item_arraysize(){
	return 9;
}

int hatchet::name_to_numb(string metaltype){
 	for (int i=0; i<9; i++){
 		if (metaltype==metalnames[i]){
 			return i;
 		}
 	}
 	return -1; 
}

void hatchet::set_metalclass(int metalnumber){
	metalclass1=metalnumber;
	cost = pow(metalnumber,4)*300;
	lvlrec = metalnumber*10+1;
	lvlrec2 = 0;
}

string hatchet::get_name(){
	return metalnames[metalclass1]+" hatchet";
}


hatchet::~hatchet(){

}


// START OF FISHINGTOOL

fishingtool::fishingtool(){
	metalclass1=0;
	cost = 0;
	lvlrec = 0;
	lvlrec2 = 0;
}

fishingtool::fishingtool(int metalclass){
	metalclass1=metalclass;
	cost = 100;
	lvlrec = 1;
	lvlrec2 = 0;
}

string fishingtool::task_type(){
	return "fishing";
}

string fishingtool::shop_name(int numb){
	return "fishing rod";
}

int fishingtool::shop_lvlrec(int numb){
	return 1;
}

int fishingtool::shop_cost(int numb){
	return 100;
}

int fishingtool::item_arraysize(){
	return 1;
}

int fishingtool::name_to_numb(string metaltype){
 	if (metaltype=="fishing rod"){
 		return 0;
 	}
 	return -1; 
}

void fishingtool::set_metalclass(int metalnumber){
	metalclass1=metalnumber;
	cost = 100;
	lvlrec = 1;
	lvlrec2 = 0;
}

string fishingtool::get_name(){
	return "fishing rod";
}

fishingtool::~fishingtool(){

}










string item::metalnames[9] = {"Bronze","Iron","Steel","Black","Mithril","Adamant","Rune","Dragon","Crystal"};