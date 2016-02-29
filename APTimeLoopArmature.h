//
//  APTimeLoopArmature.h
//  Football
//
//  Created by ji long on 14-5-17.
//
//

#ifndef __Football__APTimeLoopArmature__
#define __Football__APTimeLoopArmature__

#include <iostream>
#include "cocos2d.h"
#include "cocostudio/CocoStudio.h"

USING_NS_CC;
using namespace cocostudio;

class APTimeLoopArmature : public Ref
{
public:
    static APTimeLoopArmature* getInstance();
    Armature* play(const char* filePath,const char* armatureName,const char* actionName,float time);
private:
    Armature* _armature;
    const char* _actionName;
    void loop();
};
#endif /* defined(__Football__APTimeLoopArmature__) */
