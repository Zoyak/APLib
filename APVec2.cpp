//
//  APVec2.cpp
//  Zombie3_4
//
//  Created by jl on 15/7/16.
//
//

#include "APVec2.h"

void APVec2::truncate(Vec2& aVec2, double max)
{
    if (aVec2.length() > max)
    {
        aVec2.normalize();
        aVec2 *= max;
    }
}