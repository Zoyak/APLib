//
//  APDirectorSpeedAction.cpp
//  Zombie3_4
//
//  Created by jl on 15/7/9.
//
//

#include "APDirectorSpeedAction.h"

//设置动作持续时间及速度
APDirectorSpeedAction* APDirectorSpeedAction::create(float duration, float s){
    APDirectorSpeedAction* pRet = new APDirectorSpeedAction();
    if (pRet && pRet->initWithDuration(duration, s)) {
        pRet->autorelease();
    }
    else
    {
        CC_SAFE_DELETE(pRet);
    }
    return pRet;
}
//初始化速度参数
bool APDirectorSpeedAction::initWithDuration(float duration, float s){
    if (ActionInterval::initWithDuration(duration))
    {
        auto pScheduler = Director::getInstance()->getScheduler();
        m_startSpeed=pScheduler->getTimeScale();
        //获取要求达到的速度
        m_endSpeed=s;
        m_deltaSpeed=m_endSpeed-m_startSpeed;
        return true;
    }
    return false;
}
//每帧设置
void APDirectorSpeedAction::update(float time){
    ActionInterval::update(time);
    auto pScheduler = Director::getInstance()->getScheduler();
    pScheduler->setTimeScale(m_startSpeed+m_deltaSpeed*time);
}