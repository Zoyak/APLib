//
//  APDynamicTimeLabel.h
//  Football
//
//  Created by ji long on 14-4-24.
//
//

#ifndef __Football__APDynamicTimeLabel__
#define __Football__APDynamicTimeLabel__

#include <iostream>
#include "cocos2d.h"

USING_NS_CC;

class APDynamicTimeLabel : public ActionInterval
{
public:
    /** creates the action */
    static APDynamicTimeLabel* create(int second);
    virtual APDynamicTimeLabel* reverse(void) const  override;
    virtual APDynamicTimeLabel* clone() const override;
    virtual void startWithTarget(Node *target) override;
    virtual void update(float time) override;
protected:
    APDynamicTimeLabel() {}
    virtual ~APDynamicTimeLabel() {}
    /** initializes the action */
    bool initWithDuration(int second);
    int _timeSecond;
    __String* getFormatTimeStr(int second);
    int lastNum;
};

#endif /* defined(__Football__APDynamicTimeLabel__) */
