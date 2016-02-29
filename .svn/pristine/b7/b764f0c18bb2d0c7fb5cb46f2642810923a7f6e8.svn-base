//
//  APDateHelper.h
//  hero3_2
//
//  Created by liuye on 14-8-22.
//
//

#ifndef __hero3_2__APDateHelper__
#define __hero3_2__APDateHelper__

#include <iostream>
#include "cocos2d.h"

USING_NS_CC;

//SqlServer2008返回Datatime 类型时间判断  UTC to local time
#define isPNullDate(expr) expr == NULL ? -1 : DateHelper::getLocalTime(expr)

class APDateHelper
{
public:
    static int getNowTimer();
    static __String* getStringNowTimer();
    static __String *getConvertToTimer(int sec);
    static time_t getDatetime();
    static time_t getConvertToLocalTime(time_t* nowTime_t);     //UTC时间转换为本地时间
    static tm* getLocalTime();
    static __String* getLastDate(int dayNumber);
    static __String* getDate();
    static int getYear();
    static int getMonth();
    static int getDay();
    static int getRandom(int min,int max);                      //获取最小min ,最大随机值
    static float getTimeFloat();
};

#endif /* defined(__hero3_2__APDateHelper__) */
