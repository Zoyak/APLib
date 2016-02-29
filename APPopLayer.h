//
//  APPopLayer.h
//  Knight
//
//  Created by ji long on 14-2-25.
//
//

#ifndef __Knight__APPopLayer__
#define __Knight__APPopLayer__

#include <iostream>
#include "cocos2d.h"
#include "extensions/cocos-ext.h"

USING_NS_CC;
USING_NS_CC_EXT;

typedef std::function<void(Ref*)> APPopLayerCallback;

class APPopLayer : public Layer
{
public:
    CREATE_FUNC(APPopLayer);
    virtual bool init();
    virtual bool onTouchBegan(Touch *pTouch, Event *pEvent);
    APPopLayerCallback closeCallback;
    bool isToptouch;    //是否为最上层拦截touch
};

#endif /* defined(__Knight__APPopLayer__) */
