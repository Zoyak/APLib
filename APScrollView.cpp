//
//  APScrollView.cpp
//  DefendVillage3_4
//
//  Created by liuye on 15/6/10.
//
//

#include "APScrollView.h"

APScrollView* APScrollView::create(Size size, Node* container)
{
    APScrollView* pRet = new (std::nothrow) APScrollView();
    if (pRet && pRet->initWithViewSize(size, container))
    {
        pRet->autorelease();
    }
    else
    {
        CC_SAFE_DELETE(pRet);
    }
    return pRet;
}
APScrollView* APScrollView::create()
{
    APScrollView *pRet = new APScrollView();
    if (pRet && pRet->init())
    {
        pRet->autorelease();
    }
    else
    {
        CC_SAFE_DELETE(pRet);
    }
    return pRet;
}

bool APScrollView::onTouchBegan(Touch *pTouch, Event *pEvent)
{
    //log("APScrollView::onTouchBegan");
    return ScrollView::onTouchBegan(pTouch,pEvent);
}
void APScrollView::onTouchMoved(Touch *pTouch, Event *pEvent)
{
    auto pos=this->getContentOffset();
    auto minPos=this->minContainerOffset();
    startPos=pTouch->getStartLocationInView();
    endPos=pTouch->getLocationInView();
    if (pos.x>0) {
        if (startPos.x>endPos.x) {
            ScrollView::onTouchMoved(pTouch,pEvent);
        }
    }else{
        if (pos.x<minPos.x) {
            if (startPos.x<endPos.x) {
                ScrollView::onTouchMoved(pTouch,pEvent);
            }
        }else{
            ScrollView::onTouchMoved(pTouch,pEvent);
        }
    }
}
void APScrollView::onTouchEnded(Touch *pTouch, Event *pEvent)
{
    startPos=pTouch->getStartLocationInView();
    endPos=pTouch->getLocationInView();
    //log("startPos=%f,y=%f",startPos.x,startPos.y);
    //log("endPos=%f,y=%f",endPos.x,endPos.y);
    
    ScrollView::onTouchEnded(pTouch,pEvent);
}