//
//  APActionTimeLine.h
//  Adventure3_7
//  运行时间线动作
//  Created by jl on 15/9/15.
//
// doing anything

#ifndef __APLib__APActionTimeLine__
#define __APLib__APActionTimeLine__

#include <stdio.h>
#include "cocos2d.h"
#include "ui/CocosGUI.h"
#include "cocostudio/CocoStudio.h"

using namespace cocostudio::timeline;//动画相关的类位于cocostuio::timeline当中

class APActionTimeLine :public cocostudio::timeline::ActionTimeline
{
public:
    static APActionTimeLine* createForFile(const std::string & fileName);
    ~APActionTimeLine();
    APActionTimeLine();
    void setNodeVisiable(bool fVisiable);
};
#endif /* defined(__Adventure3_7__APActionTimeLine__) */
