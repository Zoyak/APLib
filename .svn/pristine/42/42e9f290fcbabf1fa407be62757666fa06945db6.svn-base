//
//  APShake.h
//  hero3_2
//  晃动
//  Created by liuye on 14-8-22.
//
//

#ifndef __hero3_2__APShake__
#define __hero3_2__APShake__

#include <iostream>
#include "cocos2d.h"

USING_NS_CC;

class APShake : public ActionInterval
{
public:
    APShake();
    // Create the action with a time and a strength (same in x and y)
    static APShake* create(float d, float strength);
    // Create the action with a time and strengths (different in x and y)
    static APShake* createWithStrength(float d, float strength_x, float strength_y);
    bool initWithDuration(float d, float strength_x, float strength_y);
    virtual APShake* reverse() const override{ return NULL; };
	virtual APShake* clone() const override{ return NULL; };
protected:
    void startWithTarget(Node *pTarget);
    void update(float time);
    void stop(void);
    // Initial position of the shaked node
    float m_initial_x, m_initial_y;
    // Strength of the action
    float m_strength_x, m_strength_y;
};

#endif /* defined(__hero3_2__APShake__) */
