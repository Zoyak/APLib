//
//  APScrollView.h
//  DefendVillage3_4
//
//  Created by liuye on 15/6/10.
//
//

#ifndef __DefendVillage3_4__APScrollView__
#define __DefendVillage3_4__APScrollView__

#include <stdio.h>
#include "cocos2d.h"
#include "extensions/cocos-ext.h"

USING_NS_CC_EXT;
USING_NS_CC;

class APScrollView : public extension::ScrollView
{
public:
    static APScrollView* create(Size size, Node* container = NULL);
    static APScrollView* create();
    virtual bool onTouchBegan(Touch *pTouch, Event *pEvent) override;
    virtual void onTouchMoved(Touch *pTouch, Event *pEvent) override;
    virtual void onTouchEnded(Touch *pTouch, Event *pEvent) override;
    //virtual void onTouchCancelled(Touch *pTouch, Event *pEvent) override;
    Point startPos;
    Point endPos;
};

#endif /* defined(__DefendVillage3_4__APScrollView__) */
