//
//  APBevTreeNode.h
//  Zombie3_4
//
//  Created by jl on 15/6/26.
//
//

#ifndef __Zombie3_4__APBevTreeNode__
#define __Zombie3_4__APBevTreeNode__

#include <stdio.h>
#include "GameHeader.h"
#include <string.h>
#include "APBevTreePrecondition.h"
#include "APBevTreeEnum.h"

using namespace std;

typedef APBevTreeAnyData BevNodeInputParam;
typedef APBevTreeAnyData BevNodeOutputParam;

#define k_BLimited_MaxChildNodeCnt              16
#define k_BLimited_InvalidChildNodeIndex        k_BLimited_MaxChildNodeCnt

class APBevTreeNode
{
public:
    ~APBevTreeNode();
    APBevTreeNode(APBevTreeNode* parentNode, APBevTreePrecondition* nodeScript = nullptr);
    bool evaluate(const BevNodeInputParam& input);                                          //评估对象
    void transition(const BevNodeInputParam& input);                                        //过度
    BevRunningStatus tick(const BevNodeInputParam& input, BevNodeOutputParam& output);      //循环
    APBevTreeNode& addChildNode(APBevTreeNode* _o_ChildNode);                               //增加子树叶
    APBevTreeNode& setNodePrecondition(APBevTreePrecondition* _o_NodePrecondition);         //设置节点外条件
    APBevTreeNode& setDebugName(const char* _debugName);            //设置调试名称
    const char* getDebugName() const;                               //获取调试名称
    const APBevTreeNode* oGetLastActiveNode() const;                //获取激活节点
    void setActiveNode(APBevTreeNode* _o_Node);                     //设置激活节点
    APBevTreeNode*                  mao_ChildNodeList[k_BLimited_MaxChildNodeCnt];   //子节点列表
    APBevTreeNode*                  mo_ParentNode;
    APBevTreeNode*                  mo_ActiveNode;
    APBevTreeNode*                  mo_LastActiveNode;
    APBevTreePrecondition*          mo_NodePrecondition;                             //条件节点
    int                             mul_ChildNodeCount;
    string                     abc;
    std::string                     mz_DebugName;
    
protected:
    virtual bool doEvaluate(const BevNodeInputParam& input);
    virtual void doTransition(const BevNodeInputParam& input);
    virtual BevRunningStatus doTick(const BevNodeInputParam& input, BevNodeOutputParam& output);
    void setParentNode(APBevTreeNode* parentNode);
    bool bCheckIndex(int _ui_Index) const;
};

#endif /* defined(__Zombie3_4__APBevTreeNode__) */
