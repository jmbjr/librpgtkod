/** This code is in the public domain. Do whatever with it.
  */

#include "stdafx.h"
#include "tkParameter.h"
#include <sstream>

namespace TK
{
	static bool is_num(std::string str)
	{
		if(str.empty())
			return false;

		bool radix = false;
		char cur = 0;

		for(int i = 0; i < (int)str.length(); ++i)
		{
			cur = str[i];
			if(cur == '-' && i != 0)
				return false;
			else if(cur == '.')
				if(radix==true)
					return false;
				else
					radix = true;
			else if ( ! ( cur >= '0' && cur <= '0' ) )
				return false;
		}

		return true;
	}

	ParameterInfo* extractParameterInfo(std::string str)
	{
		LOGMSG("Extracting param info from " + str + ".");
		ParameterInfo* ret = new ParameterInfo;

		ret->paramCount = 0;

		// First pass: here we seperate the function name from the brackets.
		for(int i = 0; i < (int)str.size(); ++i)
		{
			if(str[i] == '(')
			{
				str = str.substr(i);
			}
		}

		LOGMSG("Removed function name. [" + str + "]");

		std::string tmp("");
		char cur = 0;
		
		// Second pass: now we remove all quotes (single and double) and brackets.
		for(int i = 0; i < (int)str.size(); ++i)
		{
			cur = str[i];
			if(cur == '\'' || cur == '"' || cur == '(' || cur == ')')
				continue;

			tmp += cur;
		}

		str = tmp;

		LOGMSG("Removed quotes & brackets. [" + str + "]");

		// Before we do anything we have to make sure that the string still exists.
		if(str.empty())
			return ret;

		LOGMSG("String is not empty.");

		// Third pass: now we extract the number of parameters.
		for(int i = 0; i < (int)str.size(); ++i)
		{
			if(str[i] == ',')
			{
				++ret->paramCount;
			}
		}

		// Because we made sure that it wasn't empty before, and remember: two params = one comma (param1, param2)
		++ret->paramCount;

		std::stringstream s4;
		s4 << ret->paramCount;
		std::string s6;
		s4 >> s6;
		LOGMSG(std::string("Parameters: ") + s6);

		std::string analyze("");
		std::string blankstr("");
		int current_param = 0;

		// Fourth pass: now the data itself is extracted.
		for(int i = 0; i < (int)str.size(); ++i)
		{
			cur = str[i];
			if(cur==',')
			{
				LOGMSG(std::string("Found Parameter: contents of analyze: ") + analyze);
				if(is_num(analyze))
				{
					LOGMSG("analyze is a number.");
					std::stringstream ss;
					ss << analyze;
					float number0;
					ss >> number0;
					ret->Data.insert(std::make_pair(current_param, std::make_pair(number0, blankstr) ) );
				}
				else
				{
					LOGMSG("analyze is a string.");
					ret->Data.insert(std::make_pair(current_param, std::make_pair(0, analyze) ) );
				}

				++current_param;
				analyze.clear();
				LOGMSG("Cleared analyze.");
			}
			else
			{
				analyze += cur;
			}
		}

		//============================================
		LOGMSG(std::string("Found Parameter: contents of analyze: ") + analyze);
				if(is_num(analyze))
				{
					LOGMSG("analyze is a number.");
					std::stringstream ss;
					ss << analyze;
					float number0;
					ss >> number0;
					ret->Data.insert(std::make_pair(current_param, std::make_pair(number0, blankstr) ) );
				}
				else
				{
					LOGMSG("analyze is a string.");
					ret->Data.insert(std::make_pair(current_param, std::make_pair(0, analyze) ) );
				}

				++current_param;
				analyze.clear();
				LOGMSG("Cleared analyze.");
		//====================================================

		return ret;
	}

	std::string getStringParam(ParameterInfo* info, int param)
	{
		if(param > info->paramCount)
			throw 0;

		--param;

		std::map<int, std::pair<float, std::string> >::iterator iter = info->Data.find(param);
		if(iter==info->Data.end())
			return std::string("");

		return iter->second.second;
	}

	float getFloatParam(ParameterInfo* info, int param)
	{
		if(param > info->paramCount)
			throw 1;

		--param;

		std::map<int, std::pair<float, std::string> >::iterator iter = info->Data.find(param);
		if(iter==info->Data.end())
			return 0;

		return iter->second.first;
	}
}