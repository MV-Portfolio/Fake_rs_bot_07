#ifndef WORLD_H
#define WORLD_H
using namespace std;

#include <string> 
#include <vector>
#include <iostream>

#include "bot.h"


class world{
private:
    int worldID; //Id of a world
    int population; // amount of bots within a world
    vector<bot> botVector; // bots within a world
    static int maxplayer; // Maximum players that can fit in a world
    static int currentID; // Id tracker of worlds made
public: 
    // set functions
    world();
    void set_max(int maxi);
    void add_bot(bot *botName);
    //print and get functions
    int get_pop();
    int get_ID();
    int get_max();
    void print_bots();
   	~world();
};

#endif //WORLD_H
