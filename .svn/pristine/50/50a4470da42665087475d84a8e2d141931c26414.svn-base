//
//  BTRenderableNode.cpp
//  HeroTower3_4
//
//  Created by jl on 15/5/11.
//
//

#include "BTRenderableNode.h"

bool BTRenderableNode::init()
{
    if (!Node::init()) {
        return false;
    }
    
    return true;
}

void BTRenderableNode::loadBehaviourTreeNode(APBevTreeNode *bn)
{
    m_BevNode=bn;
    this->removeAllChildren();
    m_Lines.clear();
    
    m_Size = Director::getInstance()->getWinSize();
    rootPos=Vec2(m_Size.width*0.5,m_Size.height-100);
    
    auto btn=Button::create();
    btn->setAnchorPoint(Vec2(0.5,0));
    btn->loadTextureNormal("Default/Button_Normal.png");
    std::string name=m_BevNode->getDebugName();
    btn->setTitleColor(Color3B::RED);
    btn->setTitleText(name);
    btn->setPosition(rootPos);
    this->addChild(btn);
    
    drawChildrenInfo(m_BevNode,btn);
}

void BTRenderableNode::drawChildrenInfo(APBevTreeNode* parent, Button* parentButton)
{
    if (!parent){
        log("---root is null");
        return;
    }
    std::vector<Button*> btnList;
    auto parentPos=parentButton->getPosition();
    
    int count=parent->mul_ChildNodeCount;
    if (count>0) {
        rootPos+=Vec2(-rootPos.x,-50);
    }
    auto newPos=Vec2(0,parentPos.y-50);
    for (int i=0; i<count; i++) {
        auto child=parent->mao_ChildNodeList[i];
        if (!child) {
            continue;
        }
        rootPos.x=i*100+100;
        newPos.x=i*100+100;
        auto btn=Button::create();
        btn->setUserData(child);
        btn->setAnchorPoint(Vec2(0.5,0.5));
        btn->loadTextureNormal("Default/Button_Normal.png");
        std::string name=child->getDebugName();
        btn->setTitleText(name);
        if (child==parent->mo_ActiveNode) {
            btn->setTitleColor(Color3B::RED);
        }else{
            btn->setTitleColor(Color3B::BLACK);
        }
        
        btn->setPosition(rootPos);
        this->addChild(btn);
        
        m_Lines.push_back(Rect(parentPos.x,parentPos.y,rootPos.x,rootPos.y+btn->getContentSize().height*0.5));
        //m_Lines.push_back(Rect(parentPos.x,parentPos.y,newPos.x,newPos.y+btn->getContentSize().height*0.5));
        btnList.push_back(btn);
    }
    for (int i=0; i<count; i++) {
        auto child=parent->mao_ChildNodeList[i];
        if (!child) {
            continue;
        }
        drawChildrenInfo(child,btnList.at(i));
    }
}

void BTRenderableNode::draw(Renderer *renderer, const Mat4 &transform, uint32_t flags)
{
    Node::draw(renderer, transform, flags);
    //return;
    //loadBehaviourTreeNode(m_BevNode);
    _customCmd.init(_globalZOrder, transform, flags);
    _customCmd.func = CC_CALLBACK_0(BTRenderableNode::onDraw, this, transform, flags);
    renderer->addCommand(&_customCmd);
}

void BTRenderableNode::onDraw(const Mat4 &transform, uint32_t flags)
{
    //初始化
    Director* director = Director::getInstance();
    director->pushMatrix(MATRIX_STACK_TYPE::MATRIX_STACK_MODELVIEW);
    director->loadMatrix(MATRIX_STACK_TYPE::MATRIX_STACK_MODELVIEW, transform);
    
    //int count=m_BevNode->mul_ChildNodeCount;
    
    for (auto& obj : m_Lines) {
        //画线
        CHECK_GL_ERROR_DEBUG();
        glLineWidth(3.0f);//设置线条宽度
        DrawPrimitives::setDrawColor4B(255, 0, 0, 255);//设置颜色
        DrawPrimitives::drawLine(Vec2(obj.origin.x,obj.origin.y), Vec2(obj.size.width,obj.size.height));
    }
    /*
    //画线
    CHECK_GL_ERROR_DEBUG();
    glLineWidth(5.0f);//设置线条宽度
    DrawPrimitives::setDrawColor4B(255, 0, 0, 255);//设置颜色
    DrawPrimitives::drawLine(Vec2(10,10), Vec2(370,370));
    */
    CHECK_GL_ERROR_DEBUG();
    director->popMatrix(MATRIX_STACK_TYPE::MATRIX_STACK_MODELVIEW);
}
