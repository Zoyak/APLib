//
//  APLoadingBarFromTo.cpp
//  Human3_4
//
//  Created by liuye on 15/3/16.
//
//

#include "APLoadingBarFromTo.h"

APLoadingBarFromTo* APLoadingBarFromTo::create(float duration, float from, float to)
{
    APLoadingBarFromTo *ap = new APLoadingBarFromTo();
    ap->initWithDuration(duration, from, to);
    ap->autorelease();
    
    return ap;
}

bool APLoadingBarFromTo::initWithDuration(float duration, float from, float to)
{
    if (ActionInterval::initWithDuration(duration))
    {
        _from = from;
        _to = to;
        
        return true;
    }
    
    return false;
}

APLoadingBarFromTo* APLoadingBarFromTo::clone() const
{
    // no copy constructor
    auto a = new APLoadingBarFromTo();
    a->initWithDuration(_duration, _from, _to);
    a->autorelease();
    return a;
}

APLoadingBarFromTo* APLoadingBarFromTo::reverse() const
{
    CCASSERT(false, "reverse() not supported in APLoadingBarFromTo");
    return nullptr;
}

void APLoadingBarFromTo::startWithTarget(Node *target)
{
    ((ui::LoadingBar*)(target))->setPercent(_from);
    
    ActionInterval::startWithTarget(target);
}

void APLoadingBarFromTo::update(float time)
{
    ((ui::LoadingBar*)(_target))->setPercent(_from + (_to - _from) * time);
}