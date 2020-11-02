#include "CmdManager.h"
#include <iostream>
#include <stdexcept>
using namespace std;

void CmdManager::Init(){
	manager.AddCourse("Linux");
	cmdMap.insert(pair<CourseCmd,string>(Cmd_PrintHelp, "Help Info"));
	cmdMap.insert(pair<CourseCmd,string>(Cmd_PrintCourse,"Course List"));
	cmdMap.insert(pair<CourseCmd,string>(Cmd_PrintCourseNum,"Course Number"));
	cmdMap.insert(pair<CourseCmd,string>(Cmd_PrintLongName,"Longest Course Name"));
	cmdMap.insert(pair<CourseCmd,string>(Cmd_RemoveLastCourse,"Remove Last Course"));
	
	cmdMap.insert(pair<CourseCmd,string>(Cmd_Exit, "Exit"));

}


void CmdManager::PrintAllHelp() const{
	for(auto iter=cmdMap.begin();iter!=cmdMap.end();iter++){
		cout << iter->first << ": " << iter->second << endl;
	}
}

void CmdManager::PrintCmdHelp(const CourseCmd cmd) const{
	auto iter = cmdMap.find(cmd);

	cout << iter->first << ": " << iter->second << endl;
}

bool CmdManager::HandleCmd(const CourseCmd cmd){
	auto iter = cmdMap.find(cmd);
	if(iter ==cmdMap.end()){
		cout << "NOT FOUND" << endl;
		return true;
	}

	switch(cmd){
        case Cmd_PrintHelp: PrintAllHelp(); break;
        case Cmd_PrintCourse: manager.PrintAllCourse(); break;
        case Cmd_PrintCourseNum: cout << manager.GetCourseNum() << endl; break;
        case Cmd_PrintLongName: manager.PrintLongNameCourse(); break;
        case Cmd_RemoveLastCourse: manager.RemoveLast(); break;
        // return false用来帮助外层的循环退出
        case Cmd_Exit: return false;
        default: break;
	}

	return true;
}
