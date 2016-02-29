//
//  APProgressTo.cpp
//  Zombie3_4
//
//  Created by liuye on 15/8/28.
//
//

#include "APProgressTo.h"

APProgressTo* APProgressTo::create(float duration, float to, Label* lb)
{
    APProgressTo *ap = new (std::nothrow) APProgressTo();
    ap->initWithDuration(duration, to, lb);
    ap->autorelease();
    
    return ap;
}

bool APProgressTo::initWithDuration(float duration, float to, Label* lb)
{
    if (ActionInterval::initWithDuration(duration))
    {
        m_TimeLabel = lb;
        m_to = to;
        
        return true;
    }
    
    return false;
}

APProgressTo* APProgressTo::clone() const
{
    // no copy constructor
    auto a = new (std::nothrow) APProgressTo();
    a->initWithDuration(_duration, m_to, m_TimeLabel);
    a->autorelease();
    return a;
}

APProgressTo* APProgressTo::reverse() const
{
    CCASSERT(false, "reverse() not supported in APProgressTo");
    return nullptr;
}

void APProgressTo::startWithTarget(Node *target)
{
    ActionInterval::startWithTarget(target);
    
    m_from = ((ProgressTimer*)(target))->getPercentage();
}

void APProgressTo::update(float time)
{
    ((ProgressTimer*)(_target))->setPercentage(m_from + (m_to - m_from) * time);
    
    if (m_TimeLabel) {
        auto timeString=__String::createWithFormat("%0.1f",_duration - _duration * time);
        m_TimeLabel->setString(timeString->getCString());
    }
}