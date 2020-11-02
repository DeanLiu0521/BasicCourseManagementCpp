#include "CourseManager.h"
#include "Cmd.h"
#include <map>
#include <istream>

using namespace std;


class CmdManager {
private:
	CourseManager manager;
	map<CourseCmd,string> cmdMap;
public:
	CmdManager()= default;
	void Init();
	void PrintAllHelp() const;
	void PrintCmdHelp(const CourseCmd cmd) const;
	bool HandleCmd(const CourseCmd cmd);
	CourseManager& GetCourseManager(){return manager;};
};
