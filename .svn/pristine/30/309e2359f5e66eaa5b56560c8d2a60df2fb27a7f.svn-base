//
//  APLoadingBarFromTo.h
//  Human3_4
//
//  Created by liuye on 15/3/16.
//
//

#ifndef __Human3_4__APLoadingBarFromTo__
#define __Human3_4__APLoadingBarFromTo__

#include <stdio.h>
#include "cocos2d.h"
#include "ui/CocosGUI.h"

using namespace cocos2d;
using namespace ui;

class APLoadingBarFromTo : public ActionInterval
{
public:
    static APLoadingBarFromTo* create(float duration, float from, float to);
    virtual APLoadingBarFromTo* clone() const override;
    virtual APLoadingBarFromTo* reverse(void) const override;
    virtual void startWithTarget(Node *target) override;
    virtual void update(float time) override;
    bool initWithDuration(float duration, float from, float to);
protected:
    float _to;
    float _from;
};

#endif /* defined(__Human3_4__APLoadingBarFromTo__) */
