//
//  APDynamicLabel.h
//  Knight
//
//  Created by JI LONG on 14-4-2.
//
//

#ifndef __Knight__APDynamicLabel__
#define __Knight__APDynamicLabel__

#include <iostream>
#include "cocos2d.h"

USING_NS_CC;

class APDynamicLabel : public ActionInterval
{
public:
    /** creates the action */
    static APDynamicLabel* create(float duration, int startNum,int tarNum);
    virtual APDynamicLabel* clone() const override;
	virtual APDynamicLabel* reverse(void) const  override;
    virtual void startWithTarget(Node *target) override;
    virtual void update(float time) override;
    std::string sChar;                          //设置是否显示符号
protected:
    APDynamicLabel() {}
    virtual ~APDynamicLabel() {}
    /** initializes the action */
    bool initWithDuration(float duration, int startNum,int tarNum);
    int iStartNum;    //开始数据
    int iTarNum;      //目标数据
    
};
#endif /* defined(__Knight__APDynamicLabel__) */
