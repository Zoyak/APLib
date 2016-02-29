//
//  APBevTreeNodeSelector.h
//  普通的选择节点
//
//  Created by jl on 15/6/26.
//
//

#ifndef __Zombie3_4__APBevTreeNodeSelector__
#define __Zombie3_4__APBevTreeNodeSelector__

#include <stdio.h>
#include "APBevTreeNode.h"
#include "APBevTreeNodePrioritySelector.h"
#include "APBevTreePrecondition.h"

//不带优先级的选择节点
class APBevTreeNodeSelector : public APBevTreeNodePrioritySelector
{
public:
    APBevTreeNodeSelector(APBevTreeNode* pNode, APBevTreePrecondition* nodePrecond=nullptr)
				: APBevTreeNodePrioritySelector(pNode, nodePrecond)
    {}
    virtual bool doEvaluate(const BevNodeInputParam& input);
    
};

#endif /* defined(__Zombie3_4__APBevTreeNodeSelector__) */
