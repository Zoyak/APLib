//
//  APLoadingBarTo.h
//  TowerWar3_0
//
//  Created by JI LONG on 14-6-19.
//
//

#ifndef __TowerWar3_0__APLoadingBarTo__
#define __TowerWar3_0__APLoadingBarTo__

#include <iostream>
#include "cocos2d.h"
#include "extensions/cocos-ext.h"
#include "ui/CocosGUI.h"
#include "cocostudio/CocoStudio.h"

using namespace cocos2d;
using namespace cocostudio;
using namespace ui;

class APLoadingBarTo : public ActionInterval
{
public:
    static APLoadingBarTo* create(float duration, float percent);
    
    //
    // Overrides
    //
	virtual APLoadingBarTo* clone() const override;
	virtual APLoadingBarTo* reverse(void) const override;
    virtual void startWithTarget(Node *target) override;
    virtual void update(float time) override;
    
    /** Initializes with a duration and a percent */
    bool initWithDuration(float duration, float percent);
    
protected:
    float _to;
    float _from;
    
};
#endif /* defined(__TowerWar3_0__APLoadingBarTo__) */
