//
//  APProgressTo.h
//  Zombie3_4
//
//  Created by liuye on 15/8/28.
//
//

#ifndef __Zombie3_4__APProgressTo__
#define __Zombie3_4__APProgressTo__

#include <stdio.h>
#include "cocos2d.h"

using namespace cocos2d;

class APProgressTo : public ActionInterval
{
public:
    static APProgressTo* create(float duration, float to, Label* lb=nullptr);
    virtual APProgressTo* clone() const override;
    virtual APProgressTo* reverse(void) const override;
    virtual void startWithTarget(Node *target) override;
    virtual void update(float time) override;
    bool initWithDuration(float duration, float to, Label* lb);
protected:
    Label* m_TimeLabel=nullptr;
    float m_to=0.0f;
    float m_from=0.0f;
};

#endif /* defined(__Zombie3_4__APProgressTo__) */
