//
//  APBevNodePrioritySelector.h
//  Zombie3_4
//  带优先级选择的节点
//  Created by jl on 15/6/26.
//
//

#ifndef __Zombie3_4__APBevTreeNodePrioritySelector__
#define __Zombie3_4__APBevTreeNodePrioritySelector__

#include <stdio.h>
#include "APBevTreeNode.h"
#include "APBevTreePrecondition.h"

//带优先级的选择节点
class APBevTreeNodePrioritySelector : public APBevTreeNode
{
public:
    APBevTreeNodePrioritySelector(APBevTreeNode* pNode, APBevTreePrecondition* nPrecond=nullptr);
    virtual bool doEvaluate(const BevNodeInputParam& input);
    virtual void doTransition(const BevNodeInputParam& input);
    virtual BevRunningStatus doTick(const BevNodeInputParam& input, BevNodeOutputParam& output);
protected:
    int mui_CurrentSelectIndex;
    int mui_LastSelectIndex;
};

#endif /* defined(__Zombie3_4__APBevNodePrioritySelector__) */
