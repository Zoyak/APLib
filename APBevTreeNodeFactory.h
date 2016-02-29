//
//  APBevTreeNodeFactory.h
//  Zombie3_4
//
//  Created by jl on 15/6/26.
//
//

#ifndef __Zombie3_4__APBevTreeNodeFactory__
#define __Zombie3_4__APBevTreeNodeFactory__

#include <stdio.h>
#include "APBevTreeNode.h"
#include "APBevTreeNodePrioritySelector.h"
#include "APBevTreePrecondition.h"
#include "APBevTreeNodeParallel.h"
#include "APBevTreeNodePrioritySelector.h"
#include "APBevTreeNodeSelector.h"
#include "APBevTreeNodeSequence.h"
#include "APBevTreeNodeTerminal.h"
#include "APBevTreeNodeLoop.h"

class APBevTreeNodeFactory
{
public:
    static APBevTreeNode& oCreateParallelNode(APBevTreeNode* parent, E_ParallelFinishCondition ec, const char* debugName)
    {
        APBevTreeNodeParallel* pReturn = new APBevTreeNodeParallel(parent);
        pReturn->setFinishCondition(ec);
        pReturn->setDebugName(debugName);
        if(parent) parent->addChildNode(pReturn);
        return (*pReturn);
    }
    
    //创建优先选择节点
    static APBevTreeNode* createPrioritySelectorNode(APBevTreeNode* parent, const char* debugName)
    {
        APBevTreeNodePrioritySelector* pReturn = new APBevTreeNodePrioritySelector(parent);
        pReturn->setDebugName(debugName);
        parent->addChildNode(pReturn);
        return pReturn;
    }
    
    static APBevTreeNode& oCreateNonePrioritySelectorNode(APBevTreeNode* parent, const char* debugName)
    {
        APBevTreeNodeSelector* pReturn = new APBevTreeNodeSelector(parent);
        pReturn->setDebugName(debugName);
        if(parent) parent->addChildNode(pReturn);
        return (*pReturn);
    }
    
    //创建队列节点
    static APBevTreeNode* createSequenceNode(APBevTreeNode* parent, const char* debugName)
    {
        APBevTreeNodeSequence* pReturn = new APBevTreeNodeSequence(parent);
        pReturn->setDebugName(debugName);
        parent->addChildNode(pReturn);
        return pReturn;
    }
    
    static APBevTreeNode& oCreateLoopNode(APBevTreeNode* parent, const char* name, int loop)
    {
        APBevTreeNodeLoop* pReturn = new APBevTreeNodeLoop(parent, NULL, loop);
        pReturn->setDebugName(name);
        if(parent) parent->addChildNode(pReturn);
        return (*pReturn);
    }
    template<typename T>
    static APBevTreeNode* createTeminalNode(APBevTreeNode* parent, const char* debugName)
    {
        APBevTreeNodeTerminal* pReturn = new T(parent);
        pReturn->setDebugName(debugName);
         parent->addChildNode(pReturn);
        return pReturn;
    }
};


#endif /* defined(__Zombie3_4__APBevTreeNodeFactory__) */
