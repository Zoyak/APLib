//
//  APBevTreeNodeParallel.h
//  Zombie3_4
//
//  Created by jl on 15/6/26.
//
//

#ifndef __Zombie3_4__APBevTreeNodeParallel__
#define __Zombie3_4__APBevTreeNodeParallel__

#include <stdio.h>
#include "APBevTreeNode.h"
#include "APBevTreePrecondition.h"
#include "APBevTreeEnum.h"

//并行节点
class APBevTreeNodeParallel : public APBevTreeNode
{
public:
    APBevTreeNodeParallel(APBevTreeNode* pNode, APBevTreePrecondition* nPrecondition = nullptr)
				: APBevTreeNode(pNode, nPrecondition)
				, me_FinishCondition(k_PFC_OR)
    {
        for(unsigned int i = 0; i < k_BLimited_MaxChildNodeCnt; ++i)
            mab_ChildNodeStatus[i] = k_BRS_Executing;
    }
    virtual bool doEvaluate(const BevNodeInputParam& input);
    virtual void doTransition(const BevNodeInputParam& input);
    virtual BevRunningStatus doTick(const BevNodeInputParam& input, BevNodeOutputParam& output);
    APBevTreeNodeParallel& setFinishCondition(E_ParallelFinishCondition eCondition);
private:
    E_ParallelFinishCondition me_FinishCondition;
    BevRunningStatus		  mab_ChildNodeStatus[k_BLimited_MaxChildNodeCnt];
};

#endif /* defined(__Zombie3_4__APBevTreeNodeParallel__) */
