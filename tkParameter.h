/** This code is in the public domain. Do whatever with it.
  */

#include "stdafx.h"
#include <string>
#include <stdlib.h>
#include <sstream>
#include <fstream>
#include <map>

inline void LOGAMSG(std::string msg)
{
	std::ofstream os;
	os.open("C:/users/gubbaloo/tk.log", std::ios::out | std::ios::app);
	os << msg;
	os.close();
}

#define LOGMSG(msg) LOGAMSG(std::string(msg) + "\n")

namespace TK
{
	struct ParameterInfo
	{
		std::map<int, std::pair<float, std::string> > Data;
		int paramCount;
	};

	// Pass in the string the TKPlugExecute gives you to this function.
	ParameterInfo* extractParameterInfo(std::string str);

	// In the event that the param cannot be accessed (out of range)
	// these functions will throw an int -- 0 for getStringParam, 1 for getFloatParam.
	// To protect against termination of trans3, wrap your whole function's code in a try/catch block.
	std::string getStringParam(ParameterInfo* info, int param);
	float		getFloatParam(ParameterInfo* info, int param);
}