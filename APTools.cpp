//
//  APTools.cpp
//  Knight
//
//  Created by ji long on 14-2-17.
//
//

#include "APTools.h"

int APTools::getRand(int minNum, int maxNum)
{
    /*
    srand((unsigned)time(0));
    maxNum++;
    int rangeDuration = maxNum-minNum;
    return (rand()%rangeDuration)+minNum;
     */
    maxNum++;
    int iRand = CCRANDOM_0_1()*(maxNum-minNum)+minNum;
    return iRand;
}
//获取随机数
float APTools::getRandFloat(float minNum, float maxNum)
{
    /*
    time_t tt;
    time(&tt);
    struct tm * now;
    //获得本地时间//
    now = localtime(&tt);
    timeval tv;
    gettimeofday(&tv,NULL);
    //都转化为毫秒//
    //unsigned long reed = tv.tv_sec*1000+tv.tv_usec/1000;
    unsigned long reed = tv.tv_usec;
    //srand()中传入一个随机数种子//
    srand(reed);*/
    //maxNum+=1.0;
    float fRand = CCRANDOM_0_1()*(maxNum-minNum)+minNum;
    return fRand;
}
//获取随机数
float APTools::getRandFloat(float minNum, float maxNum,float absMin)
{
    while (1) {
        float fRand = CCRANDOM_0_1()*(maxNum-minNum)+minNum;
        if (fabsf(fRand)>absMin) {
            return fRand;
            break;
        }
    }
    
}
//获取微秒随机数
int APTools::getRandMicrosecond()
{
    timeval tv;
    gettimeofday(&tv, nullptr);
    srand((unsigned)tv.tv_usec);
    return rand();
}
//得到两坐标的顺时针角度值
float APTools::getAngle(const Vec2& vCenter, const Vec2& v2)
{
    Vec2 sp = (vCenter - v2);
    sp.normalize();
    float angle = sp.getAngle();
    angle *= -57.29577951f;
    angle = (angle < 0) ? 360 + angle : angle;
    return angle;
}
//得到两坐标的逆时针角度值
float APTools::getAntiAngle(const Vec2& vCenter, const Vec2& v2)
{
    float angle=APTools::getAngle(v2, vCenter);
    angle=360-angle;
    return angle;
}
/**
 *  获取圆上的坐标点
 *
 *  @param vCenter  中心点
 *  @param fAngle   角度(相对于中心点的逆时针角度)
 *  @param fRadius  半径
 *
 *  @return 圆上的点
 */
Vec2 APTools::getRoundPoint(const Vec2& vCenter, float fAngle, float fRadius)
{
    float radian=CC_DEGREES_TO_RADIANS(fAngle);
    float x=fRadius * cosf(radian);
    float y=fRadius * sinf(radian);
    auto targetPos=Vec2(x + vCenter.x, y + vCenter.y);
    return targetPos;
}
//打印所有子节点信息
void APTools::PrintUIWidgetChildrenInfo(Widget* root)
{
    if (!root){
        log("---root is null");
        return;
    }
    auto parentObj=root->getParent();
    if (parentObj) {
        auto widObj=dynamic_cast<Widget*>(parentObj);
        if (widObj) {
            log("---ParentName:%s,ChildsType:%s,name:%s",widObj->getName().c_str(),root->getDescription().c_str(), root->getName().c_str());
        }else{
            log("---ParentName:null,ChildsType:%s,name:%s",root->getDescription().c_str(), root->getName().c_str());
        }
    }else{
        log("---ChildsType:%s,name:%s",root->getDescription().c_str(), root->getName().c_str());
    }
    const auto& arrayRootChildren = root->getChildren();
    for (auto& subWidget : arrayRootChildren){
        Widget* child = static_cast<Widget*>(subWidget);
        PrintUIWidgetChildrenInfo(child);
    }
}
//打印骨骼动画所有动作名
void APTools::PrintMovementNames(Armature *arm)
{
    if (!arm){
        log("---Armature is null");
        return;
    }
    AnimationData *animData=arm->getAnimation()->getAnimationData();
    auto movementNames=animData->movementNames;
    for (auto name : movementNames) {
        log("---name:%s",name.c_str());
    }
}
//获取矩形里随机一个点
Vec2 APTools::getRandPoint(const Rect& rect)
{
    float random=CCRANDOM_0_1();
    auto pos=Vec2(rect.getMidX(),rect.getMidY());
    pos.x=rect.getMinX() + rect.getMaxX() * random;
    pos.y=rect.getMinY() + rect.getMaxY() * random;
    return pos;
}
//获取一个点与矩形最近的相交点
Vec2 APTools::getRectPoint(const Rect& rect, const Vec2& pos)
{
    std::vector<Vec2> points;
    auto pos1=Vec2(rect.getMinX(),rect.getMinY());
    points.push_back(pos1);
    auto pos2=Vec2(rect.getMinX(),rect.getMaxY());
    points.push_back(pos2);
    auto pos3=Vec2(rect.getMaxX(),rect.getMaxY());
    points.push_back(pos3);
    auto pos4=Vec2(rect.getMaxX(),rect.getMinY());
    points.push_back(pos4);
    
    auto resultPos=Vec2::ZERO;
    float distance=0.0f;
    int count=points.size();
    for (int i=0; i<count ; i++) {
        auto tempPos=points.at(i);
        float tempDistance=pos.getDistance(tempPos);
        if (distance>tempDistance) {
            continue;
        }
        distance=tempDistance;
        resultPos=pos;
    }
    if (resultPos.x>rect.getMaxX()) {
        resultPos.x=rect.getMaxX();
    }
    if (resultPos.x<rect.getMinX()) {
        resultPos.x=rect.getMinX();
    }
    if (resultPos.y>rect.getMaxY()) {
        resultPos.y=rect.getMaxY();
    }
    if (resultPos.y<rect.getMinY()) {
        resultPos.y=rect.getMinY();
    }
    return resultPos;
}
//获取等级增长率累加数值
int APTools::getLevelRateNumber(int baseNumber, int lv, float rate)
{
    for (int i=1; i<lv; i++) {
        baseNumber+=baseNumber*rate;
    }
    return baseNumber;
}