//
//  APLoadingBarTo.cpp
//  TowerWar3_0
//
//  Created by JI LONG on 14-6-19.
//
//

#include "APLoadingBarTo.h"

APLoadingBarTo* APLoadingBarTo::create(float duration, float percent)
{
    APLoadingBarTo *ap = new APLoadingBarTo();
    ap->initWithDuration(duration, percent);
    ap->autorelease();
    
    return ap;
}

bool APLoadingBarTo::initWithDuration(float duration, float percent)
{
    if (ActionInterval::initWithDuration(duration))
    {
        _to = percent;
        
        return true;
    }
    
    return false;
}

APLoadingBarTo* APLoadingBarTo::clone() const
{
	// no copy constructor
	auto a = new APLoadingBarTo();
    a->initWithDuration(_duration, _to);
	a->autorelease();
	return a;
}

APLoadingBarTo* APLoadingBarTo::reverse() const
{
	CCASSERT(false, "reverse() not supported in APLoadingBarTo");
	return nullptr;
}

void APLoadingBarTo::startWithTarget(Node *target)
{
    ActionInterval::startWithTarget(target);
    _from = ((LoadingBar*)(target))->getPercent();
    
    // XXX: Is this correct ?
    // Adding it to support Repeat
    if (_from == 100)
    {
        _from = 0;
    }
}

void APLoadingBarTo::update(float time)
{
    ((LoadingBar*)_target)->setPercent(_from + (_to - _from) * time);
}
