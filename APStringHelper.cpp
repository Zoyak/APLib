//
//  APStringHelper.cpp
//  Knight
//
//  Created by ji long on 14-3-10.
//
//

#include "APStringHelper.h"

void APStringHelper::split(std::string& s, const std::string& delim,std::vector< std::string >* ret)
{
    size_t last = 0;
    size_t index=s.find_first_of(delim,last);
    while (index!=std::string::npos)
    {
        ret->push_back(s.substr(last,index-last));
        last=index+1;
        index=s.find_first_of(delim,last);
    }
    if (index-last>0)
    {
        ret->push_back(s.substr(last,index-last));
    }
}
const char* APStringHelper::indexValue(int index,std::vector< std::string >& ret)
{
    int iCapacity=(int)ret.capacity();
    if (index >= iCapacity) {
        return NULL;
    }
    return ret[index].c_str();
}
float APStringHelper::indexFloatValue(int index,std::vector< std::string >& ret)
{
    int iCapacity=(int)ret.capacity();
    if (index >= iCapacity) {
        return NULL;
    }
    return atof(ret[index].c_str());
}
//字符串替换
void APStringHelper::stringReplace(std::string &str,std::string &key, std::string &replaceValue)
{
    std::string::size_type pos=0;
	std::string::size_type keySize=key.size();
	std::string::size_type rValueSize=replaceValue.size();
	while((pos=str.find(key,pos))!=std::string::npos)
	{
		str.replace(pos,rValueSize,replaceValue);
		pos+=keySize;
	}
}


std::string &APStringHelper::Ltrim(std::string &str)
{
    str.erase(str.begin(), std::find_if(str.begin(), str.end(),
                                        std::not1(std::ptr_fun(::isspace))));
    return str;
    
}

/**********************************************************
 *
 *功能：去后空格
 *
 *str：源字符串
 *
 *反回值：去除后空格后的字符串
 *
 ***********************************************************/
std::string &APStringHelper::Rtrim(std::string &str)
{
    str.erase(std::find_if(str.rbegin(), str.rend(),
                           std::not1(std::ptr_fun(::isspace))).base(),
              str.end());
    return str;
    
}

/**********************************************************
 *
 *功能：去前后空格
 *
 *str：源字符串
 *
 *反回值：去除前后空格后的字符串
 *
 ***********************************************************/
std::string &APStringHelper::Trim(std::string &str)
{
    return APStringHelper::Rtrim(APStringHelper::Ltrim(str));
}
