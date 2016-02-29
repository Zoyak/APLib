//
//  APRoundBy.cpp
//  Football
//  根据中心点进行旋转
//  Created by JI LONG on 14-5-19.
//
//

#include "APRoundBy.h"

APRoundBy* APRoundBy::create(float duration,float angle,const Point &center)
{
    APRoundBy *ret = new APRoundBy();
    ret->initWithDuration(duration, angle,center);
    ret->autorelease();
    
    return ret;
}
bool APRoundBy::initWithDuration(float duration,float angle,const Point &center)
{
    if (ActionInterval::initWithDuration(duration))
    {
        //m_radius=radius;
        m_duration=duration;
        //m_startAngle=startAngle;
        m_angle=angle;
        
        m_center=center;
        return true;
    }
    return false;
}
APRoundBy* APRoundBy::clone(void) const
{
	// no copy constructor
	//auto a = new APRoundBy();
    //a->initWithDuration(_duration, iStartNum,iTarNum);
	//a->autorelease();
	return nullptr;
}
void APRoundBy::startWithTarget(Node *target)
{
    //LabelTTF *labTtf=dynamic_cast<LabelTTF*>(target);
    //(labTtf, "label ttf not APRoundBy!");
    //float currRotation=target->getRotation();
    m_startAngle=target->getRotation()+180;
    Point currTarPos=target->getPosition();
    m_radius=m_center.getDistance(currTarPos);
    ActionInterval::startWithTarget(target);
}
APRoundBy* APRoundBy::reverse() const
{
    return APRoundBy::create(m_duration,-1*m_angle,m_center);
    return nullptr;
}
void APRoundBy::update(float t)
{
    float rotate =  (m_startAngle + m_angle * t );
    
    _target->setRotation(rotate-180);
    //[target_ setRotation:rotate];
    
    float fradian = rotate * M_PI / 180.0f;
    Point pos = Point(m_center.x + m_radius * sinf(fradian),
                      m_center.y + m_radius * cosf(fradian));
    _target->setPosition(pos);
}
