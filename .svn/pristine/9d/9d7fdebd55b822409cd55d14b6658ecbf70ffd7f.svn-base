//
//  APBevTreePreconditionNot.h
//  Zombie3_4
//
//  Created by jl on 15/6/26.
//
//

#ifndef __Zombie3_4__APBevTreePreconditionNot__
#define __Zombie3_4__APBevTreePreconditionNot__

#include <stdio.h>
#include "GameHeader.h"
#include "APBevTreePrecondition.h"

class APBevTreePreconditionNot : public APBevTreePrecondition
{
public:
    APBevTreePreconditionNot(APBevTreePrecondition* lhs)
         : m_Precondition(lhs)
    {
        
    }
    ~APBevTreePreconditionNot(){
         do { delete m_Precondition; m_Precondition = nullptr; } while(0);
    }
    virtual bool externalCondition(const BevNodeInputParam& input) const{
         return !m_Precondition->externalCondition(input);
    }
private:
    APBevTreePrecondition* m_Precondition;

};

#endif /* defined(__Zombie3_4__APBevTreePreconditionNot__) */
