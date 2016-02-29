//
//  APDynamicLoadingBar.cpp
//  Football
//
//  Created by ji long on 14-4-25.
//
//

#include "APDynamicLoadingBar.h"
#include "extensions/cocos-ext.h"
#include "ui/CocosGUI.h"

APDynamicLoadingBar* APDynamicLoadingBar::create(float duration, int startPercent,int tarPercent)
{
    CCAssert(duration>=0, "APDynamicLoadingBar:duration err");
    CCAssert(startPercent>=0 && startPercent<=100, "APDynamicLoadingBar:startPercent err");
    CCAssert(tarPercent>=0 && tarPercent<=100, "APDynamicLoadingBar:tarPercent err");
    CCAssert(startPercent<=tarPercent, "APDynamicLoadingBar:startPercent err");    
    APDynamicLoadingBar *ret = new APDynamicLoadingBar();
    ret->initWithDuration(duration, startPercent,tarPercent);
    ret->autorelease();
    
    return ret;
}
bool APDynamicLoadingBar::initWithDuration(float duration,  int startPercent,int tarPercent)
{
    if (ActionInterval::initWithDuration(duration))
    {
        iStartPercent=startPercent;
        iTarPercent=tarPercent;
        return true;
    }
    return false;
}
APDynamicLoadingBar* APDynamicLoadingBar::clone(void) const
{
	// no copy constructor
	auto a = new APDynamicLoadingBar();
    a->initWithDuration(_duration, iStartPercent,iTarPercent);
	a->autorelease();
	return a;
}
void APDynamicLoadingBar::startWithTarget(Node *target)
{
    ActionInterval::startWithTarget(target);
}
APDynamicLoadingBar* APDynamicLoadingBar::reverse() const
{
    return APDynamicLoadingBar::create(_duration,iStartPercent, iTarPercent);
}
void APDynamicLoadingBar::update(float t)
{
    if (_target)
    {
        int iNum=(iTarPercent-iStartPercent)*t;
        int percent=iStartPercent+iNum;
        auto loadingBar=dynamic_cast<ui::LoadingBar*>(_target);
        if (loadingBar) {
            loadingBar->setPercent(percent);
        }
    }
}