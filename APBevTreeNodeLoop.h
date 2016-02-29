//
//  APBevTreeNodeLoop.h
//  Zombie3_4
//
//  Created by jl on 15/6/26.
//
//

#ifndef __Zombie3_4__APBevTreeNodeLoop__
#define __Zombie3_4__APBevTreeNodeLoop__

#include <stdio.h>
#include "APBevTreeNode.h"
#include "APBevTreePrecondition.h"

//循环节点
class APBevTreeNodeLoop : public APBevTreeNode
{
public:
    static const int kInfiniteLoop = -1;
    APBevTreeNodeLoop(APBevTreeNode* pNode, APBevTreePrecondition* nPrecondition = nullptr, int _i_LoopCnt = kInfiniteLoop)
				: APBevTreeNode(pNode, nPrecondition)
				, mi_LoopCount(_i_LoopCnt)
				, mi_CurrentCount(0)
    {}
    virtual bool doEvaluate(const BevNodeInputParam& input);
    virtual void doTransition(const BevNodeInputParam& input);
    virtual BevRunningStatus doTick(const BevNodeInputParam& input, BevNodeOutputParam& output);
private:
    int mi_LoopCount;
    int mi_CurrentCount;
};

#endif /* defined(__Zombie3_4__APBevTreeNodeLoop__) */
