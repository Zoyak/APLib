//
//  APBevTreePreconditionIsTrue.h
//  Zombie3_4
//
//  Created by jl on 15/7/6.
//
//

#ifndef __Zombie3_4__APBevTreePreconditionIsTrue__
#define __Zombie3_4__APBevTreePreconditionIsTrue__

#include <stdio.h>
#include "APBevTreePrecondition.h"

class APBevTreePreconditionIsTrue : public APBevTreePrecondition
{
public:
    APBevTreePreconditionIsTrue(APBevTreePrecondition* lhs)
    : m_Precondition(lhs)
    {
        
    }
    
    ~APBevTreePreconditionIsTrue(){
        do {
            delete m_Precondition;
            m_Precondition = nullptr;
        } while(0);
    }
    
    virtual bool externalCondition(const BevNodeInputParam& input) const{
        return m_Precondition->externalCondition(input);
    }
private:
    APBevTreePrecondition* m_Precondition;
};


#endif /* defined(__Zombie3_4__APBevTreePreconditionIsTrue__) */
