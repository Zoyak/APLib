//
//  APShakeUpDown.cpp
//  hero3_2
//  晃动－上下晃动
//  Created by liuye on 14-8-22.
//
//

#include "APShakeUpDown.h"

// not really useful, but I like clean default constructors
APShakeUpDown::APShakeUpDown() : m_strength_y(0), m_initial_y(0)
{
}

APShakeUpDown* APShakeUpDown::create(float d, float strength)
{
    // call other construction method with twice the same strength
    return createWithStrength(d, strength);
}

APShakeUpDown* APShakeUpDown::createWithStrength(float duration, float strength_y)
{
    APShakeUpDown *pRet = new APShakeUpDown();
    if (pRet && pRet->initWithDuration(duration, strength_y))
    {
        pRet->autorelease();
    }
    else
    {
        CC_SAFE_DELETE(pRet);
    }
    
    return pRet;
}

bool APShakeUpDown::initWithDuration(float duration, float strength_y)
{
    if (ActionInterval::initWithDuration(duration))
    {
        m_strength_y = strength_y;
        return true;
    }
    
    return false;
}

// Helper function. I included it here so that you can compile the whole file
// it returns a random value between min and max included
static float fgRangeRand(float min, float max)
{
    /*
    float rnd=((float)rand()/(float)RAND_MAX);
    return rnd*(max-min)+min;
     */
    float rnd=min+(max-min)*CCRANDOM_0_1();
    return rnd;
}

void APShakeUpDown::update(float dt)
{
    float randy = fgRangeRand(-m_strength_y, 0)*dt;
    getTarget()->setPositionY(randy+m_initial_y);
}

void APShakeUpDown::startWithTarget(Node *pTarget)
{
    ActionInterval::startWithTarget(pTarget);
    // save the initial position
    m_initial_y = pTarget->getPosition().y;
}

void APShakeUpDown::stop(void)
{
    this->getTarget()->setPositionY(m_initial_y);
    
    ActionInterval::stop();
}
