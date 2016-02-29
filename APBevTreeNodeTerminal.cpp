//
//  APBevTreeNodeTerminal.cpp
//  Zombie3_4
//
//  Created by jl on 15/6/26.
//
//

#include "APBevTreeNodeTerminal.h"


void APBevTreeNodeTerminal::doTransition(const BevNodeInputParam& input)
{
    if(mb_NeedExit)     //call Exit if we have called Enter
        doExit(input, k_BRS_ERROR_Transition);
    
    setActiveNode(nullptr);
    me_Status = k_TNS_Ready;
    mb_NeedExit = false;
}

BevRunningStatus APBevTreeNodeTerminal::doTick(const BevNodeInputParam& input, BevNodeOutputParam& output)
{
    BevRunningStatus bIsFinish = k_BRS_Finish;
    
    if(me_Status == k_TNS_Ready)
    {
        doEnter(input);
        mb_NeedExit = true;
        me_Status = k_TNS_Running;
        setActiveNode(this);
    }
    if(me_Status == k_TNS_Running)
    {
        bIsFinish = doExecute(input, output);
        setActiveNode(this);
        if(bIsFinish == k_BRS_Finish || bIsFinish < 0)
            me_Status = k_TNS_Finish;
    }
    if(me_Status == k_TNS_Finish)
    {
        if(mb_NeedExit)     //call Exit if we have called Enter
            doExit(input, bIsFinish);
        
        me_Status = k_TNS_Ready;
        mb_NeedExit = false;
        setActiveNode(NULL);
        
        return bIsFinish;
    }
    return bIsFinish;
}