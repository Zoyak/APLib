//
//  APDirectorSpeedAction.h
//  Zombie3_4
//  整体游戏速度控制
//  Created by jl on 15/7/9.
//
//

#ifndef __Zombie3_4__APDirectorSpeedAction__
#define __Zombie3_4__APDirectorSpeedAction__

#include "cocos2d.h"
#include "extensions/cocos-ext.h"
#include "ui/CocosGUI.h"
#include "cocostudio/CocoStudio.h"

using namespace cocos2d;
using namespace cocostudio;
using namespace ui;

class APDirectorSpeedAction : public ActionInterval
{
public:
    static APDirectorSpeedAction* create(float duration, float s);    //设置动作持续时间及速度
    APDirectorSpeedAction(){};
    virtual ~APDirectorSpeedAction(){};
    bool initWithDuration(float duration, float s);
    void update(float time);                                          //每帧设置
protected:
    float m_duration;               //持续时间
    float m_startSpeed;             //动画默认速度
    float m_endSpeed;               //要求动画达到的结束速度
    float m_deltaSpeed;             //结束与开始时动画的速度变量
};
#endif /* defined(__Zombie3_4__APDirectorSpeedAction__) */
