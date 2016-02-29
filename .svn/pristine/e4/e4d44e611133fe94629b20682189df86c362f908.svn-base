//
//  APBevTreeNodeSequence.cpp
//  Zombie3_4
//
//  Created by jl on 15/6/26.
//
//

#include "APBevTreeNodeSequence.h"

bool APBevTreeNodeSequence::doEvaluate(const BevNodeInputParam& input)
{
    unsigned int testNode;
    if(mui_CurrentNodeIndex == k_BLimited_InvalidChildNodeIndex)
        testNode = 0;
    else
        testNode = mui_CurrentNodeIndex;
    
    if(bCheckIndex(testNode))
    {
        APBevTreeNode* oBN = mao_ChildNodeList[testNode];
        if(oBN->evaluate(input))
            return true;
    }
    return false;
}
void APBevTreeNodeSequence::doTransition(const BevNodeInputParam& input)
{
    if(bCheckIndex(mui_CurrentNodeIndex))
    {
        APBevTreeNode* oBN = mao_ChildNodeList[mui_CurrentNodeIndex];
        oBN->transition(input);
    }
    mui_CurrentNodeIndex = k_BLimited_InvalidChildNodeIndex;
}

BevRunningStatus APBevTreeNodeSequence::doTick(const BevNodeInputParam& input, BevNodeOutputParam& output)
{
    BevRunningStatus bIsFinish = k_BRS_Finish;
    
    //First Time
    if(mui_CurrentNodeIndex == k_BLimited_InvalidChildNodeIndex)
        mui_CurrentNodeIndex = 0;
    
    APBevTreeNode* oBN = mao_ChildNodeList[mui_CurrentNodeIndex];
    bIsFinish = oBN->tick(input, output);
    if(bIsFinish == k_BRS_Finish)
    {
        ++mui_CurrentNodeIndex;
        //sequence is over
        if(mui_CurrentNodeIndex == mul_ChildNodeCount)
        {
            mui_CurrentNodeIndex = k_BLimited_InvalidChildNodeIndex;
        }
        else
        {
            bIsFinish = k_BRS_Executing;
        }
    }
    if(bIsFinish < 0)
    {
        mui_CurrentNodeIndex = k_BLimited_InvalidChildNodeIndex;
    }
    return bIsFinish;
}
