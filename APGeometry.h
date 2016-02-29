//
//  APGeometry.h
//  pandajump2
//
//  Created by li shiyong on 12-11-13.
//
//

#ifndef __pandajump2__APGeometry__
#define __pandajump2__APGeometry__

#include "cocos2d.h"

USING_NS_CC;

//公共私有变量属性
#define AP_SYNTHESIZE_PUBLIC(varType, varName, funName)\
public: varType varName;\
public: virtual const varType& get##funName(void) const { return varName; }\
public: virtual void set##funName(varType var){ varName = var; }


/** 获取对象的RTTI 名称
 @return const char*
 @
 */
#define apcn(aClass) typeid(aClass).name()

/** 获取字符串比较
 @return int  0 相同 ，非0不同
 @
 */
#define apstrcmp(achar,bchar) strcmp(achar, bchar)

Vec2 APVec2Make(float rateX, float rateY);

/** 调整屏幕点，使之适应不同屏幕分辨率
 @return Vec2 
 @
 */
#define apccp(__X__,__Y__) APVec2Make((float)(__X__), (float)(__Y__))

Vec2 APVec2Make(float rateX, float rateY);


/** 按比例从屏幕可视size中，取得size
 @return Size
 @
 */
Size APSizeMake(float rateW, float rateH);


/** 节点比例的点
 @return Vec2
 @
 */
#define aprateccp(__node__,__X__,__Y__) APVec2RateMake((Node*)(__node__), (float)(__X__), (float)(__Y__))

Vec2 APVec2RateMake(Node* node, float rateX, float rateY);


/** 按照比例加到父节点
 @return Vec2 子节点的位置
 @
 */
void APAddChildForRate(Node* parent, Node* child, float rateX, float rateY, int zOrder = 0);


/** 修正Scale来适应VisibleSize
 @return 
 @
 */
#define apftv(__pNode__) fitToVisibleSize(__pNode__)
void fitToVisibleSize(Node *pNode);

/** 屏幕可视化比率
 @return
 @
 */
Vec2 APScaleRate();

/** 设对象在paths组成的线段中匀速移动，共用时duration。
 @return 在 time 时刻对象的位置
 @ time:     某时刻 
 @ duration: 移动完成总共用时
 */
Vec2 APGetVec2AtTime(float time, __Array* pPaths, float duration);

Vec2 APGetVec2AtTime(float time, PointArray* pPaths, float duration);

/** 设对象在paths组成的线段中匀速移动，共用时duration。
 @return 在 time 时刻对象的位置
 @ time:     某时刻
 @ duration: 移动完成总共用时
 */
Vec2 APGetVec2AtTime(float time, __Array* pPaths, float duration);

/** 取两点间的夹角
 @return 弧度，在(0 ~ 2PI)之间
 @ 
 */
float APccpAngle(Vec2 &p1, Vec2 &p2);
float APccpAngleDegree(Vec2 &p1, Vec2 &p2);

/** 两点间移动需要的时间
 @return 移动需要的时间
 @
 */
float APMoveDurationWithSpeed(Vec2 &p1, Vec2 &p2, float speed);
float APMoveDuration(Vec2 &p1, Vec2 &p2, float uDistance, float uDuration);

/** 两点间距离与单位长度的比率
 @return 
 @
 */
float APDistanceRate(Vec2 &p1, Vec2 &p2, float unitDistance);

/** 两点间距离
 @return
 @
 */
float APDistance(Vec2 &p1, Vec2 &p2);


/** 判断矩形与直线相通的交点
 @return 相交点坐标
 @
 */
Vec2 APRectIsSegmentIntersect(const Rect& cRect,const Vec2& p1,const Vec2& p2);

#endif /* defined(__pandajump2__APGeometry__) */
