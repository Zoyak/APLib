//
//  APShakeUpDown.h
//  hero3_2
//  晃动－上下晃动
//  Created by liuye on 14-8-22.
//
//

#ifndef __hero3_2__APShakeUpDown__
#define __hero3_2__APShakeUpDown__

#include <iostream>
#include "cocos2d.h"

USING_NS_CC;

class APShakeUpDown : public ActionInterval
{
public:
    APShakeUpDown();
    // Create the action with a time and a strength (same in y)
    static APShakeUpDown* create(float d, float strength);
    // Create the action with a time and strengths (different in y)
    static APShakeUpDown* createWithStrength(float d, float strength_y);
    bool initWithDuration(float d, float strength_y);
    virtual APShakeUpDown* reverse() const override{ return NULL; };
	virtual APShakeUpDown* clone() const override{ return NULL; };
protected:
    void startWithTarget(Node *pTarget);
    void update(float time);
    void stop(void);
    // Initial position of the shaked node
    float m_initial_y;
    // Strength of the action
    float m_strength_y;
};
#endif /* defined(__hero3_2__APShakeUpDown__) */
