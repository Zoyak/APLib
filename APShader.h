//
//  APShader.h
//  Zombie3_4
//
//  Created by jl on 15/7/2.
//
//

#ifndef __Zombie3_4__APShader__
#define __Zombie3_4__APShader__

#include <stdio.h>
#include "GameHeader.h"


class APShader
{
public:
    static void addShaderSprite(Sprite *addSprite,const char* shaderFile);
    static void addShaderArmature(Armature *addSprite,const char* shaderFile);
    static void addShaderArmature(Armature *addSprite,GLProgram* glpro);
};
#endif /* defined(__Zombie3_4__APShader__) */
