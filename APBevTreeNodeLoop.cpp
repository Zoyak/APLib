//
//  APBevTreeNodeLoop.cpp
//  Zombie3_4
//
//  Created by jl on 15/6/26.
//
//

#include "APBevTreeNodeLoop.h"

bool APBevTreeNodeLoop::doEvaluate(const BevNodeInputParam& input)
{
    bool checkLoopCount = (mi_LoopCount == kInfiniteLoop) ||
    mi_CurrentCount < mi_LoopCount;
    
    if(!checkLoopCount)
        return false;
    
    if(bCheckIndex(0))
    {
        APBevTreeNode* oBN = mao_ChildNodeList[0];
        if(oBN->evaluate(input))
            return true;
    }
    return false;
}
void APBevTreeNodeLoop::doTransition(const BevNodeInputParam& input)
{
    if(bCheckIndex(0))
    {
        APBevTreeNode* oBN = mao_ChildNodeList[0];
        oBN->transition(input);
    }
    mi_CurrentCount = 0;
}

BevRunningStatus APBevTreeNodeLoop::doTick(const BevNodeInputParam& input, BevNodeOutputParam& output)
{
    BevRunningStatus bIsFinish = k_BRS_Finish;
    if(bCheckIndex(0))
    {
        APBevTreeNode* oBN = mao_ChildNodeList[0];
        bIsFinish = oBN->tick(input, output);
        
        if(bIsFinish == k_BRS_Finish)
        {
            if(mi_LoopCount != kInfiniteLoop)
            {
                mi_CurrentCount++;
                if(mi_CurrentCount < mi_LoopCount)
                {
                    bIsFinish = k_BRS_Executing;
                }
            }
            else
            {
                bIsFinish = k_BRS_Executing;
            }
        }
    }
    if(bIsFinish)
    {
        mi_CurrentCount = 0;
    }
    return bIsFinish;
}
