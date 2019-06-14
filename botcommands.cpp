#include <stdio.h>
#include <time.h>
#include <iostream>
#include <string> 
#include <sstream>
#include <cstdlib>
//#include <conio.h>

#include "world.h"
#include "bot.h"
#include "items.h"
#include "tasks.h"

using namespace std;

extern void help();
extern void command();
extern void update(int*,time_t*,vector<bot>*);
extern void shop(int*,bot*);
extern void info(bot*);
extern void inventory(bot*);
extern void set_task(bot*);




void help2(){
    cout << endl << endl;
    cout << "-----BOT COMMAND LIST-----" << endl;
    cout << "'info' : view all info about bot" << endl;
    cout << "'inventory' : see all items in bot inventory" << endl;
    cout << "'shop' : buy a item for selected bot" << endl;
    cout << "'task' : set task of bot" << endl;
    cout << "'return' : deselect current bot" << endl;
    cout << "-------END O F LIST-------" << endl;
    cout << endl << endl;
}




void botcommand(bot *account,int *rsgp, time_t *lastupdate,vector<bot> *botlist){
    string bottask = "?";
    while(1){
        bool error=true;
        update(rsgp,lastupdate,botlist);
        cout << "Enter command for " << account->get_botname() << ": ";
        while (error){ //incase of the use of cin -> cin causes geetline to be skipped. 
            getline(cin, bottask);
            if (bottask!="\n"&&bottask != ""){
                error=false;
            } 
        }
        if (bottask=="help"){
            help();
        } 
        else if (bottask=="help2"){
            help2();
        } 
        else if (bottask=="shop"){
            update(rsgp,lastupdate,botlist);
            shop(rsgp,account);
        }
        else if (bottask=="info"){
            info(account);
        }
        else if (bottask=="inventory"){
            inventory(account);
        }
        else if (bottask=="task"){
            set_task(account);
        }
        else if (bottask=="return"){
            return;
        } 
        else {
            cout << endl << ">>> Sorry, please try again." << endl;
            cout << ">>> Master commands do not execute in bot commands" << endl;
            cout << ">>> Type 'return' to go back to Master commands" << endl;
            cout << ">>> Type 'help2' for list of bot commands" << endl << endl;
        }
    }
}


//need to pass over amount of gold and bot details 

//,
void shop(int *rsgp, bot *account){
    bool notpass = true;
    string type = "?";
    string metalclass = "?"; 
    int lvl,metalnumb;
    item * A1;

    cout << endl << endl;
    cout << "-------Grand Exchange-------" << endl;
    cout << ">>> How can i help you?" << endl;
    cout << "'pickaxe' - mining tool" << endl;
    cout << "'hatchet' - woodcutting tool" << endl;
    cout << "'fishing' - fishing tools" << endl;
    cout << "'goodbye' - leave store" << endl;
    cout << "--------END O F LIST--------" << endl;
    cout << endl << endl;

    while(notpass){
        cout << "what whould you like to buy: ";
        getline(cin,type);
        notpass=false;
        if (type=="pickaxe"){
            A1 = new pickaxe();
            lvl = account -> mining -> get_level();
        }
        else if (type=="hatchet"){
            A1 = new hatchet();
            lvl = account -> woodcutting -> get_level();
        }
        else if (type=="fishing"){
            A1 = new fishingtool();
            lvl = account -> fishing -> get_level();
        }
        else if (type=="goodbye"){
            return;
        }
        else {
            cout << ">>> Sorry i don't understand.." << endl; 
            notpass=true;
        }
    }

    cout << endl << endl;
    cout << "-------Grand Exchange-------" << endl;
    cout << ">>> What type would you like?" << endl;
    //cout << A1->item_arraysize() << endl;
    for (int i=0; i<A1->item_arraysize(); i++){
        cout <<"'"<< A1->shop_name(i) <<"'"<< " -> level requirment: " << A1->shop_lvlrec(i) <<" "<<A1->task_type()<< " , cost: " << A1->shop_cost(i) << " gp" <<endl;
    }
    cout << "'goodbye' - leave store" << endl;
    cout << "--------END O F LIST--------" << endl;
    cout << ">>> You currently have : " << *rsgp << " gp"<< endl;
    cout << ">>> bot "<< account->get_botname() << " has level " << lvl << " " << A1->task_type() << endl;
    cout << endl << endl;

    cout << "What type would you like: ";
    getline(cin,metalclass);
    metalnumb=A1->name_to_numb(metalclass);
    A1->set_metalclass(metalnumb);
    if (metalclass=="goodbye"){
        cout << ">>> cya! " << endl;
        return;
    }
    else if (metalnumb==-1){
        cout << ">>> " << metalclass << " " << type << " not found..." << endl;
        return; 
    } else if (lvl<(A1->get_lvlrec())){
        cout << ">>> bot does not have high enough level for this item" << endl;
        return;
    } else if (*rsgp<(A1->get_cost())){
        cout << ">>> insufficient funds" << endl;
        return;
    }
    *rsgp=*rsgp-(A1->get_cost());
    account->add_item(A1);
    cout << ">>> "<< metalclass << " " << type << " was added to " << account->get_botname()<<"'s inventory"<< endl ;
    cout << ">>> note: to use new item, you must set task of bot again" << endl<< endl << endl;
    return;
}




void info(bot *account){
    cout << endl << endl;
	cout << "------- Account info -------" << endl;
    cout << "bot ID number: " << account->get_id() << endl;
    cout << "Username: " << account->get_botname() << endl;
    cout << "World ID: " << account->get_worldid() << endl;
    cout << "Current Task: " << account->get_task() << endl;
    cout << "Gold earnt per second: " << account->get_gpsec() << endl;
    cout << "Xp earn per second: " << account->get_xpsec() << endl;
    cout << "------- Levels and XP -------" << endl;
    cout << "Mining level: "<<account->mining->get_level() << endl;
    cout << "Minging xp: "<<account->mining->get_xp()<< endl;
    cout << "Woodcutting level: "<<account->woodcutting->get_level() << endl;
    cout << "Woodcutting xp: "<<account->woodcutting->get_xp() << endl;
    cout << "Fishing level: "<<account->fishing->get_level() << endl;
    cout << "Fishing xp: "<<account->fishing->get_xp() << endl;
    cout << "------- Inventory -------" << endl;
    account->print_items();
    cout << "-------- THE END --------" << endl << endl << endl;
}


void inventory(bot *account){
    cout << endl << endl;
    cout << "------- Inventory -------" << endl;
    account->print_items();
    cout << "-------- THE END --------" << endl << endl << endl;
}

void set_task(bot *account){
    string taskA;
    bool notpass2 = true;
    int itemlvl;
    task * setter;

    task * A1;

    cout << endl << endl;
    cout << "-------TASK SELECTION-------" << endl;
    cout << ">>> What task would you like start?" << endl;
    cout << "'mining' - high gold per second but lower xp" << endl;
    cout << "'woodcutting' - high xp per second but lower gold" << endl;
    cout << "'fishing' - better flat rate gold and xp then walking" << endl;
    cout << "'goodbye' - leave selection" << endl;
    cout << "--------END O F LIST--------" << endl;
    cout << endl << endl;

    while(notpass2){
        cout << "What task would you like to set: ";
        getline(cin,taskA);
        notpass2=false;
        if (taskA=="mining"){
            itemlvl=account->get_mining_classlvl();
            if (itemlvl==-1){
                cout << ">>> You do not have the required item to start that task" << endl << endl;
                return;
            }
            else if (itemlvl>=0){
                setter=new mining();
                account->set_task(taskA,setter);
                setter->set_tool_level(itemlvl);
                account->set_gpsec(setter->get_gpsec());
                account->set_xpsec(setter->get_xp());
            }
        }
        else if (taskA=="woodcutting"){
            itemlvl=account->get_woodcutting_classlvl();
            if (itemlvl==-1){
                cout << ">>> You do not have the required item to start that task" << endl << endl;
                return;
            }
            else if (itemlvl>=0){
                setter=new woodcutting();
                account->set_task(taskA,setter);
                setter->set_tool_level(itemlvl);
                account->set_gpsec(setter->get_gpsec());
                account->set_xpsec(setter->get_xp());
            }
        }
        else if (taskA=="fishing"){
            itemlvl=account->get_fishing_classlvl();
            if (itemlvl==-1){
                cout << ">>> You do not have the required item to start that task" << endl << endl;
                return;
            }
            else if (itemlvl>=0){
                setter=new fishing();
                account->set_task(taskA,setter);
                setter->set_tool_level(itemlvl);
                account->set_gpsec(setter->get_gpsec());
                account->set_xpsec(setter->get_xp());
            }
        }
        else if (taskA=="goodbye"){
            return;
        }
        else {
            cout << ">>> Sorry i don't understand.." << endl; 
            notpass2=true;
        }
    }

    cout << ">>> new task set, bot " << account->get_botname() << " is now earning " << account->get_gpsec() << " gold and " << account->get_xpsec() << "xp a second" << endl;
}