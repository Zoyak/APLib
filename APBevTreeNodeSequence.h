//
//  APBevTreeNodeSequence.h
//  顺序执行节点
//
//  Created by jl on 15/6/26.
//
//

#ifndef __Zombie3_4__APBevTreeNodeSequence__
#define __Zombie3_4__APBevTreeNodeSequence__

#include <stdio.h>
#include "APBevTreeNode.h"
#include "APBevTreePrecondition.h"

//序列节点
class APBevTreeNodeSequence : public APBevTreeNode
{
public:
    APBevTreeNodeSequence(APBevTreeNode* _o_ParentNode, APBevTreePrecondition* _o_NodePrecondition = nullptr)
				: APBevTreeNode(_o_ParentNode, _o_NodePrecondition)
				, mui_CurrentNodeIndex(k_BLimited_InvalidChildNodeIndex)
    {}
    virtual bool doEvaluate(const BevNodeInputParam& input);
    virtual void doTransition(const BevNodeInputParam& input);
    virtual BevRunningStatus doTick(const BevNodeInputParam& input, BevNodeOutputParam& output);
    
private:
    int mui_CurrentNodeIndex;
};

#endif /* defined(__Zombie3_4__APBevTreeNodeSequence__) */
