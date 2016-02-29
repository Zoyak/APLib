//
//  BTRenderableNode.h
//  HeroTower3_4
//  渲染节点
//  Created by jl on 15/5/11.
//
//

#ifndef __HeroTower3_4__BTRenderableNode__
#define __HeroTower3_4__BTRenderableNode__

#include <stdio.h>
#include "GameHeader.h"
#include "APBevTreeHeader.h"


class BTRenderableNode : public Node
{
public:
    CREATE_FUNC(BTRenderableNode);
    virtual bool init();
    virtual void draw(cocos2d::Renderer *renderer, const cocos2d::Mat4 &transform, uint32_t flags) override;
    void loadBehaviourTreeNode(APBevTreeNode *bn);
private:
    APBevTreeNode *m_BevNode;
    void onDraw(const cocos2d::Mat4 &transform, uint32_t flags);
    cocos2d::CustomCommand _customCmd;
    void drawChildrenInfo(APBevTreeNode* parent, Button* parentButton);
    Size m_Size;
    Vec2 rootPos;
    std::vector<Rect> m_Lines;
};

#endif /* defined(__HeroTower3_4__BTRenderableNode__) */
