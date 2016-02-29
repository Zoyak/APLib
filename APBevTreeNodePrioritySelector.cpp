//
//  APBevTreeNodePrioritySelector.cpp
//  Zombie3_4
//
//  Created by jl on 15/6/26.
//
//

#include "APBevTreeNodePrioritySelector.h"

APBevTreeNodePrioritySelector::APBevTreeNodePrioritySelector(APBevTreeNode* pNode, APBevTreePrecondition* nPrecond) : APBevTreeNode(pNode, nPrecond)
{
    mui_LastSelectIndex=k_BLimited_InvalidChildNodeIndex;
    mui_CurrentSelectIndex=k_BLimited_InvalidChildNodeIndex;
}

bool APBevTreeNodePrioritySelector::doEvaluate(const BevNodeInputParam& input)
{
    mui_CurrentSelectIndex = k_BLimited_InvalidChildNodeIndex;
    for(unsigned int i = 0; i < mul_ChildNodeCount; ++i)
    {
        //log("level=%d",i);
        APBevTreeNode* oBN = mao_ChildNodeList[i];
        if(oBN->evaluate(input))
        {
            mui_CurrentSelectIndex = i;
            if (i==2) {
                //log("test");
            }
            return true;
        }
    }
    return false;
}

void APBevTreeNodePrioritySelector::doTransition(const BevNodeInputParam& input)
{
    if(bCheckIndex(mui_LastSelectIndex))
    {
        APBevTreeNode* oBN = mao_ChildNodeList[mui_LastSelectIndex];
        oBN->transition(input);
    }
    mui_LastSelectIndex = k_BLimited_InvalidChildNodeIndex;
}

BevRunningStatus APBevTreeNodePrioritySelector::doTick(const BevNodeInputParam& input, BevNodeOutputParam& output)
{
    BevRunningStatus bIsFinish = k_BRS_Finish;
    if(bCheckIndex(mui_CurrentSelectIndex))
    {
        if(mui_LastSelectIndex != mui_CurrentSelectIndex)  //new select result
        {
            if(bCheckIndex(mui_LastSelectIndex))
            {
                APBevTreeNode* oBN = mao_ChildNodeList[mui_LastSelectIndex];
                oBN->transition(input);   //we need transition
            }
            mui_LastSelectIndex = mui_CurrentSelectIndex;
        }
    }
    if(bCheckIndex(mui_LastSelectIndex))
    {
        //Running node
        APBevTreeNode* oBN = mao_ChildNodeList[mui_LastSelectIndex];
        bIsFinish = oBN->tick(input, output);
        //clear variable if finish
        if(bIsFinish)
            mui_LastSelectIndex = k_BLimited_InvalidChildNodeIndex;
    }
    return bIsFinish;
}