//
//  APBevTreeNodeSelector.cpp
//  Zombie3_4
//
//  Created by jl on 15/6/26.
//
//

#include "APBevTreeNodeSelector.h"


bool APBevTreeNodeSelector::doEvaluate(const BevNodeInputParam& input)
{
    if(bCheckIndex(mui_CurrentSelectIndex))
    {
        APBevTreeNode* oBN = mao_ChildNodeList[mui_CurrentSelectIndex];
        if(oBN->evaluate(input))
        {
            return true;
        }
    }
    return APBevTreeNodePrioritySelector::doEvaluate(input);
}
