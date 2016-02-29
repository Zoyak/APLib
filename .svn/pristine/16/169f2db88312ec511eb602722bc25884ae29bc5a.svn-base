//
//  APBevTreePreconditionAnd.h
//  Zombie3_4
//
//  Created by jl on 15/6/26.
//
//

#ifndef __Zombie3_4__APBevTreePreconditionAnd__
#define __Zombie3_4__APBevTreePreconditionAnd__

#include <stdio.h>

#include "APBevTreePrecondition.h"

class APBevTreePreconditionAnd : public APBevTreePrecondition
{
public:
    virtual bool externalCondition(const BevNodeInputParam& input) const{
        /*
         class BevNodePreconditionAND : public BevNodePrecondition
         {
         public:
         BevNodePreconditionAND(BevNodePrecondition* lhs, BevNodePrecondition* rhs)
         : m_lhs(lhs)
         , m_rhs(rhs)
         {
         D_CHECK(m_lhs && m_rhs);
         }
         ~BevNodePreconditionAND(){
         D_SafeDelete(m_lhs);
         D_SafeDelete(m_rhs);
         }
         virtual bool ExternalCondition(const BevNodeInputParam& input) const{
         return m_lhs->ExternalCondition(input) && m_rhs->ExternalCondition(input);
         }
         private:
         BevNodePrecondition* m_lhs;
         BevNodePrecondition* m_rhs;
         };
         */
        return true;
    }
};


#endif /* defined(__Zombie3_4__APBevTreePreconditionAnd__) */
