//
//  APVec2.h
//  Zombie3_4
//  vec2帮助类
//  Created by jl on 15/7/16.
//
//

#ifndef __Zombie3_4__APVec2__
#define __Zombie3_4__APVec2__

#include <stdio.h>
#include "cocos2d.h"

using namespace cocos2d;

class APVec2{
public:
    static void truncate(Vec2& aVec2, double max);
};
#endif /* defined(__Zombie3_4__APVec2__) */
