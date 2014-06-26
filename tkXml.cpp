#include "stdafx.h"
#include "tkXml.h"

#include "stdio.h"

#include <map>

namespace x
{
	std::map<std::string, RPGCodeHandler> commands;
	std::map<std::string, RPGCodeHandler>::iterator citer;

	void add_function(std::string s, RPGCodeHandler h)
	{
		commands.insert(std::make_pair(s, h));
	}

	bool function_exists(std::string command)
	{
		if(command == "clean")
		{
			return true;
		}

		citer = commands.find(command);
		if(citer==commands.end())
		{
			return false;
		}

		return true;
	}

	int execute_function(std::string command)
	{
		LOGAMSG("execute_function was called to execute '");
		LOGAMSG(command);
		LOGAMSG("'\n");
		LOGAMSG("The TCN is ");
		LOGAMSG(getTrueName(command));
		LOGAMSG("\n");

		if(getTrueName(command)=="clean")
			return 1;

		citer = commands.find(getTrueName(command));
		if(citer == commands.end())
			return 1;

		return citer->second(command);
	}

	//=======
}