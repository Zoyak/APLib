//
//  APBevTreePreconditionOR.h
//  Zombie3_4
//
//  Created by jl on 15/6/26.
//
//

#ifndef __Zombie3_4__APBevTreePreconditionOR__
#define __Zombie3_4__APBevTreePreconditionOR__

#include <stdio.h>
#include "APBevTreePrecondition.h"
#include <vector>

class APBevTreePreconditionOR : public APBevTreePrecondition
{
public:
    APBevTreePreconditionOR()
    {
    }
    ~APBevTreePreconditionOR(){
        for (auto & c : conditions) {
            delete c;
        }
        conditions.clear();
    }
    void addCondition(APBevTreePrecondition* condition){
        conditions.push_back(condition);
    }
    virtual bool externalCondition(const BevNodeInputParam& input) const{
        for (auto & c : conditions) {
            if (c->externalCondition(input)) {
                return true;
            }
        }
        return false;
    }
private:
    std::vector<APBevTreePrecondition*> conditions;
};

#endif /* defined(__Zombie3_4__APBevTreePreconditionOR__) */
