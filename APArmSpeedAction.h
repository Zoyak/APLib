//
//  APArmSpeedAction.h
//  Zombie3_4
//  控制骨骼速度动画行为
//  Created by jl on 15/7/9.
//
//

#ifndef __Zombie3_4__APArmSpeedAction__
#define __Zombie3_4__APArmSpeedAction__

#include "cocos2d.h"
#include "extensions/cocos-ext.h"
#include "ui/CocosGUI.h"
#include "cocostudio/CocoStudio.h"

using namespace cocos2d;
using namespace cocostudio;
using namespace ui;

class APArmSpeedAction : public ActionInterval
{
public:
    static APArmSpeedAction* create(float duration, float s);       //设置动作持续(时间,速度)
    APArmSpeedAction(){};
    virtual ~APArmSpeedAction(){};
    bool initWithDuration(float duration, float s);
    virtual void startWithTarget(Node *target);                     //获取目标信息
    void update(float time);                                        //每帧设置
protected:
    float m_duration;               //持续时间
    float m_startSpeed;             //动画默认速度
    float m_endSpeed;               //要求动画达到的结束速度
    float m_deltaSpeed;             //结束与开始时动画的速度变量
};
#endif /* defined(__Zombie3_4__APArmSpeedAction__) */
