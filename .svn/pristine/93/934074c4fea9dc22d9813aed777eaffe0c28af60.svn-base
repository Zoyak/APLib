//
//  APAPDateHelper.cpp
//  hero3_2
//
//  Created by liuye on 14-8-22.
//
//

#include "APDateHelper.h"
#include <time.h>

int APDateHelper::getNowTimer()
{
    struct timeval now;
    if (gettimeofday(&now, NULL) != 0)
    {
        CCLOG("error in gettimeofday");
    }
    return (int)now.tv_sec;
}

__String* APDateHelper::getStringNowTimer()
{
    int nowTimer= APDateHelper::getNowTimer();
    __String *sTimer=__String::createWithFormat("%d", nowTimer);
    return sTimer;
}

__String *APDateHelper::getConvertToTimer(int sec)
{
    int hour = sec / 3600;
    int min = (sec - hour * 3600) / 60;
    int secs = sec % 60;
    __String *sTimer=__String::createWithFormat("%02d:%02d:%02d", hour, min, secs);
    return sTimer;
}

time_t APDateHelper::getDatetime()
{
    time_t timet;
    time(&timet);
    return APDateHelper::getConvertToLocalTime(&timet);
}

time_t APDateHelper::getConvertToLocalTime(time_t* nowTime_t)
{
    time_t tm2=(*nowTime_t)+(3600*8);
    return tm2;
}

tm* APDateHelper::getLocalTime()
{
    time_t t;
    t = time(NULL);
    struct tm *tm;
    tm = localtime(&t);
    return tm;
}
__String* APDateHelper::getLastDate(int dayNumber)
{
    int year;
    int mon;
    int day;
    
    time_t t;
    struct tm *m;
    
    t = time(NULL) - (dayNumber * 24) * 3600;
    m = localtime(&t);
    
    year = m->tm_year + 1900;
    mon = m->tm_mon + 1;
    day = m->tm_mday;
    auto date=__String::createWithFormat("%d%d%d",year,mon,day);
    return date;
}
__String* APDateHelper::getDate()
{
    struct tm *tm=getLocalTime();
    int year = tm->tm_year + 1900;
    int month = tm->tm_mon + 1;
    int day = tm->tm_mday;
    auto date=__String::createWithFormat("%d%d%d",year,month,day);
    return date;
}
int APDateHelper::getYear()
{
    struct tm *tm=getLocalTime();
    int year = tm->tm_year + 1900;
    return year;
}
int APDateHelper::getMonth()
{
    struct tm *tm=getLocalTime();
    int month = tm->tm_mon + 1;
    return month;
}
int APDateHelper::getDay()
{
    struct tm *tm=getLocalTime();
    int day = tm->tm_mday;
    return day;
}
int APDateHelper::getRandom(int min,int max)
{
    srandom((unsigned int)time((time_t *)NULL));
    return rand()%max+min;
}
float APDateHelper::getTimeFloat()
{
    timeval timeVal;
	gettimeofday(&timeVal, 0);
    unsigned long curTime = timeVal.tv_sec * 1000 + timeVal.tv_usec / 1000;
	return (float)curTime;
}