
#ifndef ITEMS_H
#define ITEMS_H
using namespace std;

#include <string> 
#include <vector>
#include <iostream>
#include <fstream>




class item{
protected:
	int cost,lvlrec,lvlrec2;
	int metalclass1;
	static string metalnames[9];//= {"Bronze","Iron","Steel","Black","Mithril","Adamant","Rune","Dragon","Crystal"};
public:
	// set functions
	
	// print and get functions
	int get_cost();
	int get_lvlrec();
	int get_lvlrec2();
	int get_metalclass();
	virtual string get_name()=0;
	virtual int name_to_numb(string metaltype)=0;
	virtual string task_type()=0;
	virtual string shop_name(int numb)=0;
	virtual int item_arraysize()=0;
	virtual int shop_lvlrec(int numb)=0;
	virtual int shop_cost(int numb)=0;
	virtual void set_metalclass(int metalnumber){cout<<"HA"<<endl;};
	~item();
};



class pickaxe:public item{
public:
	//http://runescape.wikia.com/wiki/Pickaxe
	//int lvlrec(); // metalclass*10+1
	//int lvlrec2(); // metalclass*10
	pickaxe();
	pickaxe(int metalclass);
	string get_name();
	int name_to_numb(string metaltype);
	string task_type();
	string shop_name(int numb);
	int shop_lvlrec(int numb);
	int shop_cost(int numb);
	int item_arraysize();
	void set_metalclass(int metalnumber);
	~pickaxe(); 
};

class hatchet:public item{
public:
	//http://runescape.wikia.com/wiki/Hatchet
	//int lvlrec(); // metalclass*7
	//int lvlrec2(); // metalclass*10
	hatchet();
	hatchet(int metalclass);
	string get_name();
	int name_to_numb(string metaltype);
	string task_type();
	string shop_name(int numb);
	int shop_lvlrec(int numb);
	int shop_cost(int numb);
	int item_arraysize();
	void set_metalclass(int metalnumber);
	~hatchet();	
};

class fishingtool:public item{
public:
	//http://runescape.wikia.com/wiki/Fishing
	//int lvlrec(); // =1.
	fishingtool();
	fishingtool(int metalclass);
    string get_name();
	int name_to_numb(string metaltype);
	string task_type();
	string shop_name(int numb);
	int shop_lvlrec(int numb);
	int shop_cost(int numb);
	int item_arraysize();
	void set_metalclass(int metalnumber);
	~fishingtool();
};



#endif //ITEMS_H

