//
//  APActionTimeLine.cpp
//  Adventure3_7
//
//  Created by jl on 15/9/15.
//
//

#include "APActionTimeLine.h"

#include "cocostudio/CSParseBinary_generated.h"

APActionTimeLine* APActionTimeLine::createForFile(const std::string & fileName)
{
    //for cocos2d3.7.1
    // if already exists an action with filename, then return this action
//    ActionTimeline* action = _animationActions.at(fileName);
//    if (action)
//        return action;
//    
    std::string path = fileName;
    
    std::string fullPath = FileUtils::getInstance()->fullPathForFilename(fileName.c_str());
    
    CC_ASSERT(FileUtils::getInstance()->isFileExist(fullPath));
    
    Data buf = FileUtils::getInstance()->getDataFromFile(fullPath);
    
    auto csparsebinary =  flatbuffers::GetCSParseBinary(buf.getBytes());
    
    auto nodeAction = csparsebinary->action();
    APActionTimeLine* action = new (std::nothrow) APActionTimeLine();
    action->autorelease();
    int duration = nodeAction->duration();
    action->setDuration(duration);
    float speed = nodeAction->speed();
    action->setTimeSpeed(speed);
    
    auto animationlist = csparsebinary->animationList();
    int animationcount = animationlist->size();
    for (int i = 0; i < animationcount; i++)
    {
        auto animationdata = animationlist->Get(i);
        AnimationInfo info;
        info.name = animationdata->name()->c_str();
        info.startIndex = animationdata->startIndex();
        info.endIndex = animationdata->endIndex();
        action->addAnimationInfo(info);
    }
    
    auto atl=CSLoader::createTimeline(fileName);
    auto timelines =atl->getTimelines();
    int timelineLength = timelines.size();
    for (int i = 0; i < timelineLength; i++)
    {
        //auto timelineFlatBuf = timelines->Get(i);
        Timeline* timeline = timelines.at(i);
        
        if (timeline)
        {
            auto frames=timeline->getFrames();
            auto f=frames.getRandomObject();
            action->addTimeline(timeline->clone());
        }
    }
    
    return action;
}

APActionTimeLine::~APActionTimeLine()
{
    
}

APActionTimeLine::APActionTimeLine()
{
    
}

void APActionTimeLine::setNodeVisiable(bool fVisiable)
{
    for(auto &s : getTarget()->getChildren())
    {
        s->setVisible(fVisiable);
    }
}
