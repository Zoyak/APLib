//
//  APFile.h
//  Knight
//
//  Created by ji long on 14-3-11.
//
//

#ifndef __Knight__APFile__
#define __Knight__APFile__

#include <iostream>
#include <string>
#include "cocos2d.h"

USING_NS_CC;

class APFile
{
public:
    //获取字符两边非空字符
    static std::string& trim(std::string &s);
    //获取可读取的对象
    static const char* getLocalWritePath(const char* fileName);
    //判断文件是否存在
    static bool isFileExist(const char* fileName);
    //获取本地路径
    static std::string getLocalPath(const std::string& version);

};
#endif /* defined(__Knight__APFile__) */
