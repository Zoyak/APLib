//
//  APRoundBy.h
//  Football
//
//  Created by JI LONG on 14-5-19.
//
//

#ifndef __Football__APRoundBy__
#define __Football__APRoundBy__

#include <iostream>
#include "cocos2d.h"
USING_NS_CC;

class APRoundBy : public ActionInterval
{
public:
    /** creates the action */
    static APRoundBy* create(float duration,float angle,const Point &center);
    virtual APRoundBy* clone() const override;
	virtual APRoundBy* reverse(void) const  override;
    virtual void startWithTarget(Node *target) override;
    virtual void update(float time) override;
protected:
    APRoundBy() {}
    virtual ~APRoundBy() {}
    /** initializes the action */
    bool initWithDuration(float duration,float angle,const Point &center);
    float m_startAngle;           // default
    float m_angle;                // angle
    float m_radius;               // Round circle radius
    float m_duration;
    Point m_center;               // Round circle center point
};

#endif /* defined(__Football__APRoundBy__) */
