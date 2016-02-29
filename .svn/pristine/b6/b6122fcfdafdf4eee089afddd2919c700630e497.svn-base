//
//  APBevTreePrecondition.h
//  前提条件类
//  Created by jl on 15/6/26.
//
//

#ifndef __Zombie3_4__APBevTreePrecondition__
#define __Zombie3_4__APBevTreePrecondition__

#include <stdio.h>
#include "APBevTreeAnyData.h"

typedef APBevTreeAnyData BevNodeInputParam;

/*前提条件类
 */
class APBevTreePrecondition
{
public:
    virtual ~APBevTreePrecondition(){};
    APBevTreePrecondition(){};
    virtual bool externalCondition(const BevNodeInputParam& input) const = 0;  //外部条件
};
#endif /* defined(__Zombie3_4__APBevTreePrecondition__) */
