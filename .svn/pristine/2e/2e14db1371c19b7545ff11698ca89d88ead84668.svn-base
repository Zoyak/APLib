//
//  APGeometry.cpp
//  pandajump2
//
//  Created by li shiyong on 12-11-13.
//
//

#include "APGeometry.h"

Vec2 APVec2Make(float rateX, float rateY)
{
    Size vs = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    return origin+Vec2(vs.width * rateX, vs.height * rateY);
}

Size APCCSizeMake(float rateW, float rateH)
{
    Size vs = Director::getInstance()->getVisibleSize();
    return Size(vs.width * rateW, vs.height * rateH);
}

Vec2 APVec2RateMake(Node* node, float rateX, float rateY){
    Size size = node->getContentSize();
    Vec2 position = Vec2(size.width * rateX, size.height * rateY);
    return position;
}

void APAddChildForRate(Node* parent, Node* child, float rateX, float rateY, int zOrder)
{
    Size parentSize = parent->getContentSize();
    Vec2 childPosition = Vec2(parentSize.width * rateX, parentSize.height * rateY);
    child->setPosition(childPosition);
    /*
    if (-1 == zOrder) {
        parent->addChild(child);
    }else{
        parent->addChild(child, zOrder);
    }
     */
    
    parent->addChild(child, zOrder);
}

void fitToVisibleSize(Node *pNode)
{
    auto winSize = Director::getInstance()->getWinSize();
    auto vs = Director::getInstance()->getVisibleSize();
    float scaleX = vs.width/winSize.width;
    float scaleY = vs.height/winSize.height;
    pNode->setScaleX(scaleX);
    pNode->setScaleY(scaleY);
}

Vec2 APScaleRate(){
    Size winSize = Director::getInstance()->getWinSize();
    Size vs = Director::getInstance()->getVisibleSize();
    float scaleX = vs.width/winSize.width;
    float scaleY = vs.height/winSize.height;
    
    return Vec2(scaleX, scaleY);
}

Vec2 APGetVec2AtTime(float time, __Array* pPaths, float duration)
{
    Vec2 rVec2 = Vec2::ZERO;
    
    //处理各种边缘情况
    if (pPaths==NULL || pPaths->count() == 0) {
        return rVec2;
    }
    if (pPaths->count() < 2 || time >= duration) {
        Vec2 *lastVec2 = (Vec2*)pPaths->getLastObject();
        rVec2 = Vec2(lastVec2->x,lastVec2->y);
        return rVec2;
    }
    if (time == 0.0) {
        Vec2 *firstVec2 = (Vec2*)pPaths->getObjectAtIndex(0);
        rVec2 = Vec2(firstVec2->x,firstVec2->y);
        return rVec2;
    }
    
    
    //求总距离、各段距离、速度   
    float* distances = new float[pPaths->count()-1];
    float totalDistance = 0.0f;
    
    for (int i = 0; i < pPaths->count(); i++) {
        
        Vec2 *p0=(Vec2*)pPaths->getObjectAtIndex(i);
        if (p0 != (Vec2*)pPaths->getLastObject()) {
            Vec2 *p1=(Vec2*)pPaths->getObjectAtIndex(i+1);
            Vec2 sub = *p1-*p0;
            float distance = sqrt(pow(sub.x,2) + pow(sub.y,2));
            distances[i] = distance;
            totalDistance += distance;
        }
    }
    //速度
    float speed = totalDistance / duration;
    
    //第time的移动的距离
    float distanceAtTime = speed * time;
    
    
    //求在time时候，在哪个段上、在该段上移动的距离
    int curLine = 0;             //在哪个段上
    float distance = 0.0f;       //段距离
    float moveDistance = 0.0f;   //在该段上移动的距离
    
    float tempDistance = 0.0;
    for (int i = 0; i < pPaths->count() - 1; i++) {
        tempDistance += distances[i];
        if (tempDistance >= distanceAtTime) {
            curLine = i;
            moveDistance = distanceAtTime - (tempDistance - distances[i]);
            distance = distances[i];
            break;
        }
    }
    
    //按三角形等比原理，求出当前移动到的点。（先平行移动到原点，在移回来）
    Vec2 *p0=(Vec2*)pPaths->getObjectAtIndex(curLine);
    Vec2 *p1=(Vec2*)pPaths->getObjectAtIndex(curLine+1);
    Vec2 sub = *p1-*p0;
    
    Vec2 rVec2Origin = sub*(moveDistance/distance);
    rVec2 = rVec2Origin+*p0;
    
    
    delete distances;
    return rVec2;
    
}

Vec2 APGetVec2AtTime(float time, PointArray* pPaths, float duration)
{
    Vec2 rVec2 = Vec2::ZERO;
    
    //处理各种边缘情况
    if (pPaths==NULL || pPaths->count() == 0) {
        return rVec2;
    }
    if (pPaths->count() < 2 || time >= duration) {
        Vec2 lastVec2 = pPaths->getControlPointAtIndex(pPaths->count()-1);
        rVec2 = Vec2(lastVec2.x,lastVec2.y);
        return rVec2;
    }
    if (time == 0.0) {
        Vec2 firstVec2 = pPaths->getControlPointAtIndex(0);
        rVec2 = Vec2(firstVec2.x,firstVec2.y);
        return rVec2;
    }
    
    //求总距离、各段距离、速度
    float* distances = new float[pPaths->count()-1];
    float totalDistance = 0.0f;
    
    for (int i = 0; i < pPaths->count(); i++) {
        
        Vec2 p0=pPaths->getControlPointAtIndex(i);
        if (i != pPaths->count()-1) {
            Vec2 p1=pPaths->getControlPointAtIndex(i+1);
            Vec2 sub = p1+p0;
            float distance = sqrt(pow(sub.x,2) + pow(sub.y,2));
            distances[i] = distance;
            totalDistance += distance;
        }
    }
    //速度
    float speed = totalDistance / duration;
    
    //第time的移动的距离
    float distanceAtTime = speed * time;
    
    //求在time时候，在哪个段上、在该段上移动的距离
    int curLine = 0;             //在哪个段上
    float distance = 0.0f;       //段距离
    float moveDistance = 0.0f;   //在该段上移动的距离
    
    float tempDistance = 0.0;
    for (int i = 0; i < pPaths->count() - 1; i++) {
        tempDistance += distances[i];
        if (tempDistance >= distanceAtTime) {
            curLine = i;
            moveDistance = distanceAtTime - (tempDistance - distances[i]);
            distance = distances[i];
            break;
        }
    }
    
    //按三角形等比原理，求出当前移动到的点。（先平行移动到原点，在移回来）
    Vec2 p0=pPaths->getControlPointAtIndex(curLine);
    Vec2 p1=pPaths->getControlPointAtIndex(curLine+1);
    Vec2 sub = p1+p0;
    
    Vec2 rVec2Origin = sub*(moveDistance/distance);
    rVec2 = rVec2Origin+p0;
    
    delete distances;
    return rVec2;
}

float APccpAngle(Vec2 &p1, Vec2 &p2)
{
    Vec2 sub = p1-p2;
    float radian = 0.0; //
    
    if (sub.y == 0.0 && p1.x > p2.x){          // 0度
        radian = 0.0f;
    }else if (sub.x == 0.0 && p1.y > p2.y){    // 90度
        radian = M_PI / 2.0;
    }else if (sub.y == 0.0 && p1.x < p2.x){    // 180度
        radian = M_PI;
    }else if (sub.x == 0.0 && p1.y < p2.y){    // 270度
        radian = M_PI * 1.5;
    }else{
        radian = atanf(sub.y/sub.x);
        if (sub.x < 0 && sub.y > 0) {                 // 第二象限
            radian = radian + M_PI;
        }else if (sub.x < 0 && sub.y < 0) {           // 第三象限
            radian =  radian + M_PI;
        }else if (sub.x > 0 && sub.y < 0) {           // 第四象限
            radian = radian + M_PI * 2;
        }
    }
    return radian;
}

float APccpAngleDegree(Vec2 &p1, Vec2 &p2)
{
    float angle = APccpAngle(p1,p2);
    return CC_RADIANS_TO_DEGREES(angle);
}

float APMoveDurationWithSpeed(Vec2 &p1, Vec2 &p2, float speed)
{
    if (p1.equals(p2))
        return 0.0;
    if (speed <= 0) 
        return 1000000.0;
    
    Vec2 sub = p1-p2;
    float distance = sqrt(pow(sub.x,2) + pow(sub.y,2));
    
    return distance/speed;    
}

float APMoveDuration(Vec2 &p1, Vec2 &p2, float uDistance, float uDuration){
    if (uDuration <= 0 )
        return 0.0;
    
    return APMoveDurationWithSpeed(p1,p2, uDistance/uDuration);
}

float APDistanceRate(Vec2 &p1, Vec2 &p2, float unitDistance){    
    Vec2 sub = p1-p2;
    float distance = sqrt(pow(sub.x,2) + pow(sub.y,2));
    return distance/unitDistance;
}

float APDistance(Vec2 &p1, Vec2 &p2)
{
    Vec2 sub = p1-p2;
    float distance = sqrt(pow(sub.x,2) + pow(sub.y,2));
    return distance;
}

//判断矩形与直线相通的交点
Vec2 APRectIsSegmentIntersect(const Rect& cRect,const Vec2& p1,const Vec2& p2)
{
    Vec2 r[4];
    r[0]=cRect.origin;
    r[1]=Vec2(cRect.getMinX(),cRect.getMaxY());
    r[2]=Vec2(cRect.getMaxX(),cRect.getMaxY());
    r[3]=Vec2(cRect.getMaxX(),cRect.getMinY());
    for (int i=0; i< 4; i++) {
        int j=i;
        int k=j+1;
        if (k==4) {
            k=0;
        }
        if(Vec2::isSegmentIntersect(r[j],r[k],p1,p2))
        {
            Vec2 cPos=Vec2::getIntersectPoint(r[j],r[k],p1,p2);
            return cPos;
        }
    }
    return Vec2(-1,-1);
}