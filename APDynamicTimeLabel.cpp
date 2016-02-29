//
//  APDynamicTimeLabel.cpp
//  Football
//
//  Created by ji long on 14-4-24.
//
//

#include "APDynamicTimeLabel.h"
#include "extensions/cocos-ext.h"
#include "ui/CocosGUI.h"

APDynamicTimeLabel* APDynamicTimeLabel::create(int second)
{
    APDynamicTimeLabel *ret = new APDynamicTimeLabel();
    ret->initWithDuration(second);
    ret->autorelease();
    
    return ret;
}
bool APDynamicTimeLabel::initWithDuration(int second)
{
    float duration=second;
    //log("duration:%f",duration);
    if (ActionInterval::initWithDuration(duration))
    {
        _timeSecond=second;
        return true;
    }
    return false;
}
APDynamicTimeLabel* APDynamicTimeLabel::clone(void) const
{
	// no copy constructor
	auto a = new APDynamicTimeLabel();
    a->initWithDuration(_timeSecond);
	a->autorelease();
	return a;
}
void APDynamicTimeLabel::startWithTarget(Node *target)
{
    ActionInterval::startWithTarget(target);
}
APDynamicTimeLabel* APDynamicTimeLabel::reverse() const
{
    return APDynamicTimeLabel::create(_duration);
}
void APDynamicTimeLabel::update(float t)
{
    if (_target)
    {
        int sumTime=_timeSecond*t;
        int currTime=_timeSecond-sumTime;
        if (currTime==lastNum) {
            return;
        }
        lastNum=currTime;
        
        auto str=getFormatTimeStr(currTime);
        auto lab=dynamic_cast<Label*>(_target);
        if (lab) {
            lab->setString(str->getCString());
        }
        auto guiTextBmf=dynamic_cast<ui::TextBMFont*>(_target);
        if (guiTextBmf) {
            guiTextBmf->setString(str->getCString());
        }
        auto guiTextAtl=dynamic_cast<ui::TextAtlas*>(_target);
        if (guiTextAtl) {
            guiTextAtl->setString(str->getCString());
        }
    }
}
__String* APDynamicTimeLabel::getFormatTimeStr(int second)
{
    auto time=__String::createWithFormat("");    
    int hour=second/3600;                           //小时
    int minute=(second-hour*3600)/60;               //分
    int tempSecond=(second-hour*3600)%60;           //秒
    if (hour>0) {
        time=__String::createWithFormat("%d:%02d:%02d",hour,minute,tempSecond);
    }else{
        time=__String::createWithFormat("%02d:%02d",minute,tempSecond);
    }
    return time;
}