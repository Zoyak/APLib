//
//  APAnalysisTools.h
//  Zombie3_4
//  分析工具
//  Created by jl on 15/8/14.
//
//

#ifndef __Zombie3_4__APAnalysisTools__
#define __Zombie3_4__APAnalysisTools__

#include <stdio.h>

#include "cocos2d.h"
#include "extensions/cocos-ext.h"
#include "ui/CocosGUI.h"
#include "cocostudio/CocoStudio.h"

using namespace cocos2d;
using namespace cocostudio;
using namespace ui;

//分析活跃用户,登录模型,登录,留存,开启次数,激活次数
class APAnalysisLoginModel
{
public:
    std::string sApiVer;         //接口版本
    std::string sAppID;          //应用ID
    std::string sAppVer;         //应用版本
    std::string sUserID;         //玩家ID
    std::string sChannelID;      //渠道ID
    std::string sCocos2dxVer;    //引擎版本
    std::string sPlatform;       //运行平台
    time_t  date;                //操作时间
};

//分析场景模型时间
class APAnalysisEventModel
{
public:
    std::string sApiVer;         //接口版本
    std::string sAppID;          //应用ID
    std::string sAppVer;         //应用版本
    std::string sUserID;         //玩家ID
    std::string sCocos2dxVer;    //引擎版本
    std::string sPlatform;       //运行平台
    std::string sChannelID;      //渠道ID
    std::string sSceneName;      //场景名称
    std::string sSceneNameCn;    //场景中文名称
    time_t enterTime;            //进入时间
    time_t levaeTime;            //离开时间

};

//分析充值模型
class APAnalysisBuyModel
{
public:
    std::string sApiVer;         //接口版本
    std::string sAppID;          //应用ID
    std::string sAppVer;         //应用版本
    std::string sUserID;         //玩家ID
    std::string sChannelID;      //渠道ID
    std::string sCocos2dxVer;    //引擎版本
    std::string sPlatform;       //运行平台
    std::string sShopItemName;   //商品名称
    time_t accessTime;           //购买时间
    float buyPrice;              //购买价格
};

//分析充值模型
class APAnalysisTools
{
public:
    static APAnalysisTools* getInstance();
    static void destory();
    ~APAnalysisTools();
    APAnalysisTools();
    void AppStart();                        //应用启动
    const char* APAnalysisToolsVersion();   //获取API版本
};


#endif /* defined(__Zombie3_4__APAnalysisTools__) */
