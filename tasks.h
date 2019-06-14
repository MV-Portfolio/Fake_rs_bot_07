#ifndef TASKS_H
#define TASKS_H
using namespace std;
#include <string> 
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>

#include "items.h"

//TASK PARENT CLASS

class task {   
protected:
	string taskname;
	string reqtooltype;
	int tasklevel,gpsec,lvlreq,xp;
public:
	task();
	int get_gpsec();
	int get_xp();
	int get_req_level();
	string get_taskname();
	string get_req_tool_type();
	virtual void set_tool_level(int tlevel) = 0;
	~task();
};


//CHILD WALK AROUND

class walk_around: public task{
public:
	walk_around();
	void set_tool_level(int tlevel);
	~walk_around();
};



//CHILD MINING

class mining: public task{
public:
	mining();
	void set_tool_level(int tlevel);
	~mining();
};



//CHILD WOODCUTTING

class woodcutting: public task{
public:
	woodcutting();
	void set_tool_level(int tlevel);
	~woodcutting();
};



//CHILD FISHING

class fishing: public task{
public:
	fishing();
	void set_tool_level(int tlevel);
	~fishing();
	
};

#endif //TASKS_H










