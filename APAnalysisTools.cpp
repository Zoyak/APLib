//
//  APAnalysisTools.cpp
//  Zombie3_4
//
//  Created by jl on 15/8/14.
//
//

#include "APAnalysisTools.h"

static APAnalysisTools *_sharedAPAnalysisTools=nullptr;

APAnalysisTools* APAnalysisTools::getInstance()
{
    if (nullptr == _sharedAPAnalysisTools)
    {
        _sharedAPAnalysisTools = new APAnalysisTools();
    }
    return _sharedAPAnalysisTools;
}

void APAnalysisTools::destory()
{
    if (_sharedAPAnalysisTools) {
        CC_SAFE_DELETE(_sharedAPAnalysisTools);
    }
}

APAnalysisTools::~APAnalysisTools()
{
    
}
APAnalysisTools::APAnalysisTools()
{
    //开启线程
    //auto t = std::thread(std::bind(&APNATServer::networkThread, this));
    //t.detach();
    
}


//应用启动
void APAnalysisTools::AppStart()
{
    
}

//获取API版本
const char* APAnalysisTools::APAnalysisToolsVersion()
{
    return "1.0";
}
