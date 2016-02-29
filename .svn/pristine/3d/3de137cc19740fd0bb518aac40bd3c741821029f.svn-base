//
//  APPopLayer.cpp
//  Knight
//
//  Created by ji long on 14-2-25.
//
//

#include "APPopLayer.h"

bool APPopLayer::init()
{
    if (!Layer::init()) {
        return  false;
    }
    this->setTouchMode(Touch::DispatchMode::ONE_BY_ONE);
        
    auto touchListener = EventListenerTouchOneByOne::create();
    touchListener->setSwallowTouches(true);
    touchListener->onTouchBegan = CC_CALLBACK_2(APPopLayer::onTouchBegan, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(touchListener, this);
    
    isToptouch=true;
    
    return true;
}
bool APPopLayer::onTouchBegan(Touch *pTouch, Event *pEvent)
{
    return isToptouch;
}
