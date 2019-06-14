#ifndef SKILLS_H
#define SKILLS_H
using namespace std;

#include <string> 
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>

class skills{
public:
    skills(string skillname);
    string filexpgoal;
    string skill;
    int xp; 
    int level; 
    int xpgoal;
    int xpgoalset;


    bool newgoal;
    stringstream exp;


    void updatexp(int amount);
    void import_xpgoals();
    void print();

    string get_skill();    
    int get_level();
    int get_xp();
    int get_xp_till_level();


    ~skills();

    static int xp_array[99];

    //http://runescape.wikia.com/wiki/Experience/Table
};




#endif //SKILLS_H


/*
    skills *A;
    A = new skills("wood");
    A -> import_xpgoals();
    A -> print();

    */

/*
class mining:  public skills{
public: 
    string skillname = "mining";
    int skill_ID=1;
};

class woodcutting:  public skills{
public: 
    string skillname = "woodcutting";
    int skill_ID=2;
};

class fishing: public skills{
public: 
    string skillname = "fishing";
    int skill_ID=3;
};

*/