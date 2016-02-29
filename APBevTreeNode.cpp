//
//  APBevTreeNode.cpp
//  Zombie3_4
//
//  Created by jl on 15/6/26.
//
//

#include "APBevTreeNode.h"

APBevTreeNode::~APBevTreeNode()
{
    for(unsigned int i = 0; i < mul_ChildNodeCount; ++i)
    {
        CC_SAFE_DELETE(mao_ChildNodeList[i]);
    }
    CC_SAFE_DELETE(mo_NodePrecondition);
}

APBevTreeNode::APBevTreeNode(APBevTreeNode* parentNode, APBevTreePrecondition* nodeScript)
{
    mul_ChildNodeCount=0;
    mz_DebugName= "UNNAMED";
    mo_ActiveNode=nullptr;
    mo_LastActiveNode=nullptr;
    mo_NodePrecondition=nullptr;
    
    for(int i = 0; i < k_BLimited_MaxChildNodeCnt; ++i)
        mao_ChildNodeList[i] = nullptr;
    
    setParentNode(parentNode);
    setNodePrecondition(nodeScript);
}

bool APBevTreeNode::evaluate(const BevNodeInputParam& input)
{
    return (mo_NodePrecondition == NULL || mo_NodePrecondition->externalCondition(input)) && doEvaluate(input);
}

void APBevTreeNode::transition(const BevNodeInputParam& input)
{
    doTransition(input);
}

BevRunningStatus APBevTreeNode::tick(const BevNodeInputParam& input, BevNodeOutputParam& output)
{
    return doTick(input, output);
}
//---------------------------------------------------------------
APBevTreeNode& APBevTreeNode::addChildNode(APBevTreeNode* _o_ChildNode)
{
    if(mul_ChildNodeCount == k_BLimited_MaxChildNodeCnt)
    {
        //D_Output("The number of child nodes is up to 16");
        //D_CHECK(0);
        assert(false);
        return (*this);
    }
    mao_ChildNodeList[mul_ChildNodeCount] = _o_ChildNode;
    ++mul_ChildNodeCount;
    return (*this);
}

APBevTreeNode& APBevTreeNode::setNodePrecondition(APBevTreePrecondition* _o_NodePrecondition)
{
    if(mo_NodePrecondition != _o_NodePrecondition)
    {
        if(mo_NodePrecondition)
            delete mo_NodePrecondition;
        
        mo_NodePrecondition = _o_NodePrecondition;
    }
    return (*this);
}
APBevTreeNode& APBevTreeNode::setDebugName(const char* _debugName)
{
    mz_DebugName = _debugName;
    return (*this);
}
const APBevTreeNode* APBevTreeNode::oGetLastActiveNode() const
{
    return mo_LastActiveNode;
}
void APBevTreeNode::setActiveNode(APBevTreeNode* _o_Node)
{
    mo_LastActiveNode = mo_ActiveNode;
    mo_ActiveNode = _o_Node;
    if(mo_ParentNode != NULL)
        mo_ParentNode->setActiveNode(_o_Node);
}
const char* APBevTreeNode::getDebugName() const
{
    return mz_DebugName.c_str();
}

bool APBevTreeNode::doEvaluate(const BevNodeInputParam& input)
{
    return true;
}
void APBevTreeNode::doTransition(const BevNodeInputParam& input)
{
    
}

BevRunningStatus APBevTreeNode::doTick(const BevNodeInputParam& input, BevNodeOutputParam& output)
{
    return k_BRS_Finish;
}

void APBevTreeNode::setParentNode(APBevTreeNode* parentNode)
{
    mo_ParentNode = parentNode;
}

bool APBevTreeNode::bCheckIndex(int uiIndex) const
{
    return uiIndex >= 0 && uiIndex < mul_ChildNodeCount;
}