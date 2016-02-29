//
//  APStringHelper.h
//  Knight
//
//  Created by ji long on 14-3-10.
//
//

#ifndef __Knight__APStringHelper__
#define __Knight__APStringHelper__

#include <iostream>
#include "cocos2d.h"

USING_NS_CC;

class  APStringHelper
{
public:
    static void split(std::string& s, const std::string& delim,std::vector< std::string >* ret);

    static const char* indexValue(int index,std::vector< std::string >& ret);
    
    static float indexFloatValue(int index,std::vector< std::string >& ret);
    
    //静态字符串替换
    static void stringReplace(std::string &string,std::string &key, std::string &replaceValue);
    
    static std::string &Ltrim(std::string &str);
    static std::string &Rtrim(std::string &str);
    static std::string &Trim(std::string &str);
};
#endif /* defined(__Knight__APStringHelper__) */
