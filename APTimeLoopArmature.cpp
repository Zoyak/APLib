//
//  APTimeLoopArmature.cpp
//  Football
//
//  Created by ji long on 14-5-17.
//
//

#include "APTimeLoopArmature.h"

using namespace cocostudio;

static APTimeLoopArmature *_shared;
APTimeLoopArmature* APTimeLoopArmature::getInstance()
{
    if (nullptr == _shared)
    {
        _shared = new APTimeLoopArmature();
    }
    return _shared;
}
Armature* APTimeLoopArmature::play(const char* filePath,const char* armatureName,const char* actionName,float time)
{
    CCAssert(filePath, "APTimeLoopArmature:filePath is not null");
    CCAssert(armatureName, "APTimeLoopArmature:armatureName is not null");
    CCAssert(actionName, "APTimeLoopArmature:actionName is not null");
    CCAssert(time>0, "APTimeLoopArmature:time error");

    _actionName=actionName;
    CCArmatureDataManager::getInstance()->addArmatureFileInfo(filePath);
    _armature=Armature::create(armatureName);
    _armature->getAnimation()->play(_actionName,-1,0);
    auto call=CallFunc::create(CC_CALLBACK_0(APTimeLoopArmature::loop, this));
    auto action=Sequence::create(DelayTime::create(time),call, NULL);
    _armature->runAction(RepeatForever::create(action));
    
    return _armature;
}
void APTimeLoopArmature::loop()
{
    _armature->getAnimation()->play(_actionName,-1,0);
}