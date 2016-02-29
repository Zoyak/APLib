//
//  APShake.cpp
//  hero3_2
//  晃动
//  Created by liuye on 14-8-22.
//
//

#include "APShake.h"

// not really useful, but I like clean default constructors
APShake::APShake() : m_strength_x(0), m_strength_y(0), m_initial_x(0), m_initial_y(0)
{
}

APShake* APShake::create(float d, float strength)
{
    // call other construction method with twice the same strength
    return createWithStrength(d, strength, strength);
}

APShake* APShake::createWithStrength(float duration, float strength_x, float strength_y)
{
    APShake *pRet = new APShake();
    
    if (pRet && pRet->initWithDuration(duration, strength_x, strength_y))
    {
        pRet->autorelease();
    }
    else
    {
        CC_SAFE_DELETE(pRet);
    }
    
    return pRet;
}

bool APShake::initWithDuration(float duration, float strength_x, float strength_y)
{
    if (ActionInterval::initWithDuration(duration))
    {
        m_strength_x = strength_x;
        m_strength_y = strength_y;
        return true;
    }
    
    return false;
}

// Helper function. I included it here so that you can compile the whole file
// it returns a random value between min and max included
static float fgRangeRand(float min, float max)
{
    float rnd=((float)rand()/(float)RAND_MAX);
    return rnd*(max-min)+min;
}

void APShake::update(float dt)
{
    float randx = fgRangeRand(-m_strength_x, m_strength_x)*dt;
    float randy = fgRangeRand(-m_strength_y, m_strength_y)*dt;
    
    // move the target to a shaked position
    getTarget()->setPosition(Point(m_initial_x, m_initial_y) + Point(randx, randy));
}

void APShake::startWithTarget(Node *pTarget)
{
    ActionInterval::startWithTarget(pTarget);
    
    // save the initial position
    m_initial_x = pTarget->getPosition().x;
    m_initial_y = pTarget->getPosition().y;
}

void APShake::stop(void)
{
    // Action is done, reset clip position
    this->getTarget()->setPosition(Point(m_initial_x, m_initial_y));
    
    ActionInterval::stop();
}