//
//  APBevTreeNodeTerminal.h
//  Zombie3_4
//
//  Created by jl on 15/6/26.
//
//

#ifndef __Zombie3_4__APBevTreeNodeTerminal__
#define __Zombie3_4__APBevTreeNodeTerminal__

#include <stdio.h>
#include "APBevTreeNode.h"
#include "APBevTreePrecondition.h"
#include "APBevTreeEnum.h"

class APBevTreeNodeTerminal : public APBevTreeNode
{
public:
    APBevTreeNodeTerminal(APBevTreeNode* pNode, APBevTreePrecondition* nodePrecond = nullptr)
				: APBevTreeNode(pNode, nodePrecond)
				, me_Status(k_TNS_Ready)
				, mb_NeedExit(false)
    {}
    virtual void doTransition(const BevNodeInputParam& input);
    virtual BevRunningStatus doTick(const BevNodeInputParam& input, BevNodeOutputParam& output);
protected:
    virtual void				doEnter(const BevNodeInputParam& input)								{}
    virtual BevRunningStatus	doExecute(const BevNodeInputParam& input, BevNodeOutputParam& output)	{ return k_BRS_Finish;}
    virtual void				doExit(const BevNodeInputParam& input, BevRunningStatus _ui_ExitID)	{}
private:
    E_TerminalNodeStaus me_Status;
    bool                mb_NeedExit;
};
#endif /* defined(__Zombie3_4__APBevTreeNodeTerminal__) */
