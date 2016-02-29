//
//  APBevTreeNodeParallel.cpp
//  Zombie3_4
//
//  Created by jl on 15/6/26.
//
//

#include "APBevTreeNodeParallel.h"


bool APBevTreeNodeParallel::doEvaluate(const BevNodeInputParam& input)
{
    for(unsigned int i = 0; i < mul_ChildNodeCount; ++i)
    {
        APBevTreeNode* oBN = mao_ChildNodeList[i];
        if(mab_ChildNodeStatus[i] == 0)
        {
            if(!oBN->evaluate(input))
            {
                return false;
            }
        }
    }
    return true;
}
void APBevTreeNodeParallel::doTransition(const BevNodeInputParam& input)
{
    for(unsigned int i = 0; i < k_BLimited_MaxChildNodeCnt; ++i)
        mab_ChildNodeStatus[i] = k_BRS_Executing;
    
    for(unsigned int i = 0; i < mul_ChildNodeCount; ++i)
    {
        APBevTreeNode* oBN = mao_ChildNodeList[i];
        oBN->transition(input);
    }
}

APBevTreeNodeParallel& APBevTreeNodeParallel::setFinishCondition(E_ParallelFinishCondition _e_Condition)
{
    me_FinishCondition = _e_Condition;
    return (*this);
}

BevRunningStatus APBevTreeNodeParallel::doTick(const BevNodeInputParam& input, BevNodeOutputParam& output)
{
    unsigned int finishedChildCount = 0;
    for(unsigned int i = 0; i < mul_ChildNodeCount; ++i)
    {
        APBevTreeNode* oBN = mao_ChildNodeList[i];
        if(me_FinishCondition == k_PFC_OR)
        {
            if(mab_ChildNodeStatus[i] == k_BRS_Executing)
            {
                mab_ChildNodeStatus[i] = oBN->tick(input, output);
            }
            if(mab_ChildNodeStatus[i] != k_BRS_Executing)
            {
                for(unsigned int i = 0; i < k_BLimited_MaxChildNodeCnt; ++i)
                    mab_ChildNodeStatus[i] = k_BRS_Executing;
                return k_BRS_Finish;
            }
        }
        else if(me_FinishCondition == k_PFC_AND)
        {
            if(mab_ChildNodeStatus[i] == k_BRS_Executing)
            {
                mab_ChildNodeStatus[i] = oBN->tick(input, output);
            }
            if(mab_ChildNodeStatus[i] != k_BRS_Executing)
            {
                finishedChildCount++;
            }
        }
        else
        {
            //D_CHECK(0);
        }
    }
    if(finishedChildCount == mul_ChildNodeCount)
    {
        for(unsigned int i = 0; i < k_BLimited_MaxChildNodeCnt; ++i)
            mab_ChildNodeStatus[i] = k_BRS_Executing;
        return k_BRS_Finish;
    }
    return k_BRS_Executing;
}
