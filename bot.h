#ifndef BOT_H
#define BOT_H
using namespace std;
#include <string> 
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>

#include "items.h"
#include "tasks.h"



class bot{
protected:
	int totgoldmade; //total gold made by bot
    int botid; //id of bot
    string name; //name given to bot
    int gpsec; //current gold earnt per second
    vector<item*> inventory; //all items the the bot holds
    int worldloc; //world that the bot is in
    int inventory_size; //amount of items in inventory
    int xpsec; //amount of xp earnt by bot per second
    string currenttask; //name of task of bot
    task* job; //task of bot
    static int idCount; //counts id of bot
public:
    //set functions
    bot();
    bot(string botname);
    void set_world(int idnum);
    void set_task(string taskname, task* jobtask);
    void set_gpsec(int gold);
    void set_xpsec(int xp);
    void add_item(item *itemid);
    //print and get functions
    void print_items();
    string get_botname();
    int get_id();
    int get_gpsec();
    int get_worldid();
    string get_task();
    vector<item*> get_vector();
    int get_xpsec();
    int get_mining_classlvl();
    int get_woodcutting_classlvl();
    int get_fishing_classlvl();

    class skills{
    protected:
    	string filexpgoal; //string of goal before converted to int
        string skill; // name of skill
        int xp; // amount of xp eart
        int level; // level of skill earnt
        int xpgoal; // amount till next level
        int xpgoalset; //used for tansfer goals into xp_array
        stringstream exp; //import from file
        static int xp_array[99]; //amount xp to go from one level to another
    public:
        //http://runescape.wikia.com/wiki/Experience/Table
        //set functions
        skills(string skillname);
        void updatexp(int amount);
        void import_xpgoals();
        void print();
        //print and get functions
        string get_skill();    
        int get_level();
        int get_xp();
        int get_xp_till_level();
        ~skills();
    };


    skills *mining, *woodcutting, *fishing, *attack;  // skills of bot
    ~bot();

};

#endif //BOT_H




