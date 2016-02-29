//
//  APFile.cpp
//  Knight
//
//  Created by ji long on 14-3-11.
//
//

#include "APFile.h"
#include <sstream>
#include <fstream>
#define MAX_LINE 1024

//获取字符两边非空字符
std::string& APFile::trim(std::string &s)
{
    if (s.empty())
    {
        return s;
    }
    
    s.erase(0,s.find_first_not_of(" "));
    s.erase(s.find_last_not_of(" ") + 1);
    return s;
}
//获取可读取的对象
const char* APFile::getLocalWritePath(const char* fileName)
{
    std::string writablePath = FileUtils::getInstance()->getWritablePath();
    __String *str=__String::createWithFormat("%s%s",writablePath.c_str(),fileName);
    return str->getCString();
}
//判断文件是否存在
bool APFile::isFileExist(const char* fileName)
{
    return FileUtils::getInstance()->isFileExist(fileName);
}

//获取路径
std::string APFile::getLocalPath(const std::string& version)
{
    std::string sCurrVersionPath=FileUtils::getInstance()->getWritablePath()+version;
    if(!FileUtils::getInstance()->isDirectoryExist(sCurrVersionPath))
    {
        FileUtils::getInstance()->createDirectory(sCurrVersionPath);
    }
    return sCurrVersionPath+"/"+"data.apm";
}
