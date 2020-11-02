#include <iostream>
#include "CmdManager.h"


using namespace std;
int main(){
	int cmd;
	CmdManager cmdManager;
	cmdManager.Init();
	
	cmdManager.PrintAllHelp();
	
	cout << "New Command ";
	
	while(cin>> cmd){
		if (cin.good()){
			bool exitCode = cmdManager.HandleCmd((CourseCmd)cmd);
			if(!exitCode){
				return 0;
			}
		}
	
		cout << "-------------------------------" <<endl;
		cout << "New Command: ";

		cin.clear();
		cin.ignore();
	}
}

