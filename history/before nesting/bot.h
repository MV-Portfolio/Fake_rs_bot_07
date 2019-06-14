#ifndef BOT_H
#define BOT_H
using namespace std;
#include <string> 
#include <vector>

#include "skills.h"


class bot{
public:
    //bot();
    bot(string botname);
    int totgoldmade; //total gold made by bot
    int botid; //id of bot
    string name; //name given to bot
    int gpsec; //current gold earnt per second
    //task - current task
    //items - items bot has
    //total level
    //time created

    skills *X, *Y, *Z;


    string get_botname();
    int get_gpsec();

    int get_lvl(string skill_name);
    int get_xp(string skill_name);
    int get_xp_till_lvl(string skill_name);

    ~bot();
    static int idCount; 
};

#endif //BOT_H

/*
3 * xps
3 * levels
*/



