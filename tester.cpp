/* 
This file is made becuase although we have a game and test by using the game
we were told that was not good enough. So here's a file that tests stuff.
even though it's already tested multiple time via using the game. 
*/


#include <stdio.h>
#include <time.h>
#include <iostream>
#include <string> 
#include <vector>
#include <climits>
#include <sstream>
#include <cstdlib>

#include "world.h"
#include "bot.h"
#include "items.h"
#include "tasks.h"

using namespace std;




bool start2(){
	cout << endl << endl;
	string startup;
    while(1){
        cout << "Would you like to test cases? (y/n):   ";
        getline(cin,startup);
        if (startup=="y"){
        	cout << endl << endl;
            cout << ">>> Loading test cases..." << endl;
            return true;
        } else if (startup=="n"){
        	cout << endl << endl;
            cout  << ">>> okay goodbye!" << endl;
            cout << endl << endl;
            return false;
        } else { cout << endl << ">>> sorry I don't understand, please try again." << endl << endl;
            }
    }
}



//fills each world - should fill world to worldmax and then say world is full twice
void case1(){
    cout << endl << endl;
	cout << ">>> start point of case 1 <<<" << endl;
	world * w1;
	int worldmax  = 5;
	w1 = new world();
	w1 -> set_max(worldmax);

	bot * bot_maxarray;
    int amountofbots = worldmax+2;
    bot_maxarray = new bot[amountofbots];

    //should fill world with 5 bots then say worlds full twice
    cout << "max population of world " << w1 -> get_ID() << " is set to " << w1 -> get_max() << endl;
    cout << "current population of world " << w1 -> get_ID() << " is " << w1 -> get_pop() << endl;
    for (int i=0; i<amountofbots; i++){
    	cout << "Attempting to add new bot..." << endl;
		w1 -> add_bot(&bot_maxarray[i]);
		cout << "current population of world " << w1 -> get_ID() << " is " << w1 -> get_pop() << endl;
	}	
    cout << ">>> Clearning memory..." << endl;

    delete w1, bot_maxarray;
    w1 = NULL;
    bot_maxarray = NULL;

    cout << ">>> END OF CASE 1 <<<" << endl;
}


//tries to add bot same bot into world it's already added too
//also tries to add bot that's already added in dif world
void case2(){
    cout << endl << endl;
    cout << ">>> start point of case 2 <<<" << endl;
    world * w2, *w3;
    w2 = new world();
    w3 = new world();
    int worldmax = 3;
    w2 -> set_max(worldmax);
    bot * b1, *b2, *b3;
    b1 = new bot("john");
    b2 = new bot("alex");
    b3 = new bot("fred");

    //both pops should be zero
    cout << "current population of world " << w2 -> get_ID() << " is " << w2 -> get_pop() << endl;
    cout << "current population of world " << w3 -> get_ID() << " is " << w3 -> get_pop() << endl;

    //should add john to first world
    cout << ">>> Attempting to add bot " << b1 -> get_botname()<<" to world "<< w2 -> get_ID() << endl;
    w2 -> add_bot(b1); 
    cout << "current population of world " << w2 -> get_ID() << " is " << w2 -> get_pop() << endl;
    cout << "current population of world " << w3 -> get_ID() << " is " << w3 -> get_pop() << endl;

    //should add alex to second world
    cout << ">>> Attempting to add bot " << b2 -> get_botname()<<" to world "<< w3 -> get_ID() << endl;
    w3 -> add_bot(b2); 
    cout << "current population of world " << w2 -> get_ID() << " is " << w2 -> get_pop() << endl;
    cout << "current population of world " << w3 -> get_ID() << " is " << w3 -> get_pop() << endl;

    //should say 'bot is already added too world'
    cout << ">>> Attempting to add bot " << b1 -> get_botname()<<" to world "<< w2 -> get_ID() << endl;
    w2 -> add_bot(b1); 
    cout << "current population of world " << w2 -> get_ID() << " is " << w2 -> get_pop() << endl;
    cout << "current population of world " << w3 -> get_ID() << " is " << w3 -> get_pop() << endl;

    //should say 'bot is already in other world'
    cout << ">>> Attempting to add bot " << b2 -> get_botname()<<" to world "<< w2 -> get_ID() << endl;
    w2 -> add_bot(b2); 
    cout << "current population of world " << w2 -> get_ID() << " is " << w2 -> get_pop() << endl;
    cout << "current population of world " << w3 -> get_ID() << " is " << w3 -> get_pop() << endl;

    //should add fred to first world
    cout << ">>> Attempting to add bot " << b3 -> get_botname()<<" to world "<< w2 -> get_ID() << endl;
    w2 -> add_bot(b3); 
    cout << "current population of world " << w2 -> get_ID() << " is " << w2 -> get_pop() << endl;
    cout << "current population of world " << w3 -> get_ID() << " is " << w3 -> get_pop() << endl;
    cout << ">>> Clearning memory..." << endl;
    delete w2, b1, b2, b3;
    w2 = NULL;
    b1 = NULL;
    b2 = NULL;
    b3 = NULL;
    cout << ">>> END OF CASE 2 <<<" << endl;
}

//prints xp needed to go from a level to the next one
//then levels up a bot
void case3(){
    cout << endl << endl;
    cout << ">>> start point of case 3 <<<" << endl;
    bot * b4;
    b4 = new bot("mat");
    cout << "printing list from 'xplevels.csv'" << endl;
    b4 -> mining -> print();
    cout << "Mining level: "<<b4->mining->get_level() << endl;
    cout << "Minging xp: "<<b4->mining->get_xp()<< endl;
    cout << "Woodcutting level: "<<b4->woodcutting->get_level() << endl;
    cout << "Woodcutting xp: "<<b4->woodcutting->get_xp() << endl;
    cout << "Fishing level: "<<b4->fishing->get_level() << endl;
    cout << "Fishing xp: "<<b4->fishing->get_xp() << endl;

    //xp goes up by 1
    cout << ">>> Giving bot "<< b4 -> get_botname()<< " 1 xp in mining"<< endl;
    b4 -> mining -> updatexp(1);
    cout << "Mining level: "<<b4->mining->get_level() << endl;
    cout << "Minging xp: "<<b4->mining->get_xp()<< endl;
    cout << "Mining xp needed for level up: "<<b4->mining->get_xp_till_level()<<endl;

    //xp goes up by 1
    cout << ">>> Giving bot "<< b4 -> get_botname()<< " 1 xp in mining"<< endl;
    b4 -> mining -> updatexp(1);
    cout << "Mining level: "<<b4->mining->get_level() << endl;
    cout << "Minging xp: "<<b4->mining->get_xp()<< endl;
    cout << "Mining xp needed for level up: "<<b4->mining->get_xp_till_level()<<endl;

    // go to level 98 and need 1 xp to go to 99
    cout << ">>> Giving bot "<< b4 -> get_botname()<< " 138206874 xp in woodcutting"<< endl;
    b4 -> woodcutting -> updatexp(138206874);
    cout << "Woodcutting level: "<<b4->woodcutting->get_level() << endl;
    cout << "Woodcutting xp: "<<b4->woodcutting->get_xp() << endl;
    cout << "Woodcutting xp needed for level up: "<<b4->woodcutting->get_xp_till_level()<<endl;

    //should go to level 99 and xp set to zero
    cout << ">>> Giving bot "<< b4 -> get_botname()<< " 10 xp in woodcutting"<< endl;
    b4 -> woodcutting -> updatexp(10);
    cout << "Woodcutting level: "<<b4->woodcutting->get_level() << endl;
    cout << "Woodcutting xp: "<<b4->woodcutting->get_xp() << endl;
    cout << "Woodcutting xp needed for level up: "<<b4->woodcutting->get_xp_till_level()<<endl;

    //should go to level 99
    cout << ">>> Giving bot "<< b4 -> get_botname()<< " 999999999 xp in fishing"<< endl;
    b4 -> fishing -> updatexp(999999999);
    cout << "Fishing level: "<<b4->fishing->get_level() << endl;
    cout << "Fishing xp: "<<b4->fishing->get_xp() << endl;
    cout << "Fishing xp needed for level up: "<<b4->fishing->get_xp_till_level()<<endl;

    //should level up to level 23 with 940 xp
    cout << ">>> Giving bot "<< b4 -> get_botname()<< " 50000 xp in attack"<< endl;
    b4 -> attack -> updatexp(50000);
    cout << "Attack level: "<<b4->attack->get_level() << endl;
    cout << "Attack xp: "<<b4->attack->get_xp()<< endl;
    cout << "Attack xp needed for level up: "<<b4->attack->get_xp_till_level()<<endl;

    //no change should be made to lvl or xp
    cout << ">>> Giving bot "<< b4 -> get_botname()<< " -50000 xp in attack"<< endl;
    b4 -> attack -> updatexp(-50000);
    cout << "Attack level: "<<b4->attack->get_level() << endl;
    cout << "Attack xp: "<<b4->attack->get_xp()<< endl;
    cout << "Attack xp needed for level up: "<<b4->attack->get_xp_till_level()<<endl;

    cout << ">>> Clearning memory..." << endl;
    delete b4;
    b4=NULL;
    cout << ">>> END OF CASE 3 <<<"<< endl;
}


//bot buying items tests for levels and gold
void case4(){
    cout << endl << endl;
    cout << ">>> start point of case 4 <<<" << endl;
    int fakegold = 0 ;
    bot * b5; 
    b5 = new bot("bob");
    item * i1,*i2,*i3;
    i1 = new pickaxe();
    i2 = new hatchet();
    i3 = new fishingtool();
    i1->set_metalclass(5);
    i2->set_metalclass(8);
    i3->set_metalclass(1);

    //try to buy item with no enough money & lvl
    cout << "requirements to buy " << i1->get_name() << " , gold: " << i1->get_cost() << " , lvl: " << i1->get_lvlrec() << endl;
    cout << "Current bot mining level: "<<b5->mining->get_level() << endl;
    cout << "Current amount of gold: " << fakegold << endl;
    cout << ">>> Attempting to buy item... "<< endl;
    if (fakegold<(i1->get_cost())){
        cout << ">>> insufficient funds" << endl;
    } else {
        b5->add_item(i1);
    }
    cout << "printing items in bot inventory: "<< endl;
    b5->print_items();

    //try to buy item with not enough lvl
    cout << ">>> Giving 1,000,000 gold to player" << endl;
    fakegold=1000000;
    cout << "Current bot mining level: "<<b5->mining->get_level() << endl;
    cout << "Current amount of gold: " << fakegold << endl;
    if (fakegold<(i1->get_cost())){
        cout << ">>> insufficient funds" << endl;
    } else {
        b5->add_item(i1);
    }
    cout << "printing items in bot inventory: "<< endl;
    b5->print_items();

    //try to buy item with not enough money
    cout << ">>> Giving 1000000 mining xp to player" << endl;
    b5 -> mining -> updatexp(1000000);
    cout << ">>> setting gold back to zero" << endl;
    fakegold=0;
    cout << "Current bot mining level: "<<b5->mining->get_level() << endl;
    cout << "Current amount of gold: " << fakegold << endl;
    if (fakegold<(i1->get_cost())){
        cout << ">>> insufficient funds" << endl;
    } else { 
        b5->add_item(i1);
    }
    cout << "printing items in bot inventory: "<< endl;
    b5->print_items();

    //buy lowest tier item
    cout << ">>> Giving 1,000,000,000 gold to player" << endl;
    fakegold=1000000000;
    cout << "requirements to buy " << i3->get_name() << " , gold: " << i3->get_cost() << " , lvl: " << i3->get_lvlrec() << endl;
    cout << "Current bot fishing level: "<<b5->fishing->get_level() << endl;
    cout << "Current amount of gold: " << fakegold << endl;
    if (fakegold<(i3->get_cost())){
        cout << ">>> insufficient funds" << endl;
    } else {
        b5->add_item(i3);
        fakegold-=i3->get_cost();
    }
    cout << "printing items in bot inventory: "<< endl;
    b5->print_items();

    //buy top tier item
    cout << ">>> Giving 138206876 woodcutting xp to player" << endl;
    b5 -> woodcutting -> updatexp(138206876);
    cout << "requirements to buy " << i2->get_name() << " , gold: " << i2->get_cost() << " , lvl: " << i2->get_lvlrec() << endl;
    cout << "Current bot woodcutting level: "<<b5->woodcutting->get_level() << endl;
    cout << "Current amount of gold: " << fakegold << endl;
    if (fakegold<(i2->get_cost())){
        cout << ">>> insufficient funds" << endl;
    } else {
        b5->add_item(i2);
        fakegold-=i2->get_cost();
    }
    cout << "printing items in bot inventory: "<< endl;
    b5->print_items();
    cout << "Current amount of gold: " << fakegold << endl;
    cout << ">>> Clearning memory..." << endl;
    delete b5, i1, i2, i3;
    b5=NULL;
    i1=NULL;
    i2=NULL;
    i3=NULL;
    cout << ">>> END OF CASE 4 <<<"<< endl;
}

//test itemes held and how they can be passed 
void case5(){

    cout << endl << endl;
    cout << ">>> start point of case 5 <<<" << endl;
    int sizec;
    bot * b6; 
    b6 = new bot("bob");
    item * i4,*i5,*i6;
    i4 = new pickaxe();
    i5 = new hatchet();
    i6 = new fishingtool();
    i4->set_metalclass(0);
    i5->set_metalclass(0);
    i6->set_metalclass(1);
    b6->add_item(i4);
    b6->add_item(i5);
    b6->add_item(i6);

    cout << "printing items from bot:" << endl;
    b6->print_items();
    cout << "---" << endl;

    cout << "printing items from vector call:" << endl;
    vector<item*> v1=(b6->get_vector());
    sizec=v1.size();
    for (int i=0; i<sizec; i++){
        cout << v1[i]->get_name() << endl;
    }

    cout << ">>> Clearning memory..." << endl;
    delete b6, i4, i5, i6;
    b6=NULL;
    i4=NULL;
    i5=NULL;
    i6=NULL;
    cout << ">>> END OF CASE 5 <<<"<< endl;

}

void case6(){
    cout << endl << endl;
    cout << ">>> start point of case 6 <<<" << endl;
    int gp;
    int exp;
    bot * b7; 
    b7 = new bot("dan");
    item * i4;
    b7->mining->updatexp(999999999);
    i4 = new pickaxe();
    i4->set_metalclass(0);
    b7->add_item(i4);
    task * t1;
    t1 = new mining();
    t1->set_tool_level(b7->get_mining_classlvl());
    cout << "GP gained per second: " << t1->get_gpsec() << endl;
    cout << "XP gained per second: " << t1->get_xp() << endl;
    cout << "Taskname: " << t1->get_taskname() << endl;
    delete b7, i4, t1;
    b7=NULL;
    i4=NULL;
    t1=NULL;
    cout << ">>> END OF CASE 6 <<<" << endl;

}


void tester(){
    cout << ">>> stat point of cases" << endl;
    case1();
    cout << endl << endl << "Press Any Key to Continue tests...";
    cin.get();
    case2();
    cout << endl << endl << "Press Any Key to Continue tests...";
    cin.get();
    case3();
    cout << endl << endl << "Press Any Key to Continue tests...";    
    cin.get();
    case4();    
    cout << endl << endl << "Press Any Key to Continue tests...";
    cin.get();
    case5();
    cout << endl << endl << "Press Any Key to Continue tests...";
    cin.get();
    case6();
    return;
}