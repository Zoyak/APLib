//
//  APDynamicLabel.cpp
//  Knight
//
//  Created by JI LONG on 14-4-2.
//
//

#include "APDynamicLabel.h"
#include "extensions/cocos-ext.h"
#include "ui/CocosGUI.h"

APDynamicLabel* APDynamicLabel::create(float duration, int startNum,int tarNum)
{
    APDynamicLabel *ret = new APDynamicLabel();
    ret->initWithDuration(duration, startNum,tarNum);
    ret->autorelease();
    
    return ret;
}
bool APDynamicLabel::initWithDuration(float duration,  int startNum,int tarNum)
{
    if (ActionInterval::initWithDuration(duration))
    {
        iStartNum=startNum;
        iTarNum=tarNum;
        return true;
    }    
    return false;
}
APDynamicLabel* APDynamicLabel::clone(void) const
{
	// no copy constructor
	auto a = new APDynamicLabel();
    a->initWithDuration(_duration, iStartNum,iTarNum);
	a->autorelease();
	return a;
}
void APDynamicLabel::startWithTarget(Node *target)
{
    ActionInterval::startWithTarget(target);
}
APDynamicLabel* APDynamicLabel::reverse() const
{
    return APDynamicLabel::create(_duration,iTarNum, iStartNum);
}
void APDynamicLabel::update(float t)
{
    if (_target)
    {
        int iNum=(iTarNum-iStartNum)*t;
        std::string str;
        if (sChar.length()>0) {
            str= StringUtils::format("%s%d",sChar.c_str(),iStartNum+iNum);
        }else{
            str= StringUtils::format("%d",iStartNum+iNum);
        }
        auto lab=dynamic_cast<Label*>(_target);
        if (lab) {
            lab->setString(str.c_str());
        }
        auto guiTextBmf=dynamic_cast<ui::TextBMFont*>(_target);
        if (guiTextBmf) {
            guiTextBmf->setString(str.c_str());
        }
        auto guiTextAtl=dynamic_cast<ui::TextAtlas*>(_target);
        if (guiTextAtl) {
            guiTextAtl->setString(str.c_str());
        }        
    }
}

