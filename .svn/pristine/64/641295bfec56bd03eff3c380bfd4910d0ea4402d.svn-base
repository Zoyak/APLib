//
//  APDynamicLoadingBar.h
//  Football
//
//  Created by ji long on 14-4-25.
//
//

#ifndef __Football__APDynamicLoadingBar__
#define __Football__APDynamicLoadingBar__

#include <iostream>
#include "cocos2d.h"

USING_NS_CC;

class APDynamicLoadingBar : public ActionInterval
{
public:
    /** creates the action */
    static APDynamicLoadingBar* create(float duration, int startPercent,int tarPercent);
    virtual APDynamicLoadingBar* clone() const override;
	virtual APDynamicLoadingBar* reverse(void) const  override;
    virtual void startWithTarget(Node *target) override;
    virtual void update(float time) override;
protected:
    APDynamicLoadingBar() {}
    virtual ~APDynamicLoadingBar() {}
    /** initializes the action */
    bool initWithDuration(float duration, int startPercent,int tarPercent);
    int iStartPercent;     //开始进度
    int iTarPercent;       //目标进度
};
#endif /* defined(__Football__APDynamicLoadingBar__) */
