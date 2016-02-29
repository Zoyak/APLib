//
//  APArmSpeedAction.cpp
//  Zombie3_4
//
//  Created by jl on 15/7/9.
//
//

#include "APArmSpeedAction.h"

APArmSpeedAction* APArmSpeedAction::create(float duration, float s){
    APArmSpeedAction* pRet = new APArmSpeedAction();
    if (pRet && pRet->initWithDuration(duration, s)) {
        pRet->autorelease();
    }
    else
    {
        CC_SAFE_DELETE(pRet);
    }
    return pRet;
}

bool APArmSpeedAction::initWithDuration(float duration, float s){
    if (ActionInterval::initWithDuration(duration))
    {
        //获取要求达到的速度
        m_endSpeed=s;
        return true;
    }
    return false;
}
//计算差值变量
void APArmSpeedAction::startWithTarget(Node *target){
    ActionInterval::startWithTarget(target);
    //获取默认速度
    auto p_target=dynamic_cast<Armature*>(target);
    m_startSpeed=p_target->getAnimation()->getSpeedScale();
    //计算速度变量
    m_deltaSpeed=m_endSpeed-m_startSpeed;
}
//帧改变动画速率
void APArmSpeedAction::update(float time){
    ActionInterval::update(time);
    auto target=dynamic_cast<Armature*>(getTarget());
    if (getTarget()) {
        //改变动画速率
        target->getAnimation()->setSpeedScale(m_startSpeed+m_deltaSpeed*time);
    }
}
