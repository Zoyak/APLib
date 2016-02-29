//
//  APShader.cpp
//  Zombie3_4
//
//  Created by jl on 15/7/2.
//
//

#include "APShader.h"


void APShader::addShaderSprite(Sprite *addSprite,const char* shaderFile)
{
    auto fragmentFullPath = FileUtils::getInstance()->fullPathForFilename(shaderFile);
    auto fragSource = FileUtils::getInstance()->getStringFromFile(fragmentFullPath);
    auto glprogram = GLProgram::createWithByteArrays(ccPositionTextureColor_noMVP_vert, fragSource.c_str());
    addSprite->setGLProgram(glprogram);
}

void APShader::addShaderArmature(Armature *addArmature,const char* shaderFile)
{
    auto fragmentFullPath = FileUtils::getInstance()->fullPathForFilename(shaderFile);
    auto fragSource = FileUtils::getInstance()->getStringFromFile(fragmentFullPath);
    auto glprogram = GLProgram::createWithByteArrays(ccPositionTextureColor_noMVP_vert, fragSource.c_str());
    //获得所有骨骼，也就是编辑器中的layer
    auto& map = addArmature->getBoneDic();
    for (auto& entry : map){
        auto bone = entry.second;
        //p为一个shader，可以通过 GLProgram::createWithFilenames("gray.vsh","gray.fsh"); 获得，这里是预先创建好了放入了ShaderCache中，直接取出来就行了
        
        if (bone){
            //这里很关键，不能直接像2.x版本那样 对bone->getDisplayRenderNode()->setGLProgram(),要把每个骨骼身上得显示列表再次遍历
            auto list = bone->getDisplayManager()->getDecorativeDisplayList();
            for (auto dd:list){
                if (dd->getDisplay()){
                    //这个方法中已经调用了setGlprogramState(),无需在调用了，也无需在link()和updateUniform()了
                    dd->getDisplay()->setGLProgram(glprogram);
    
                }
            }
        }
    }
}


void APShader::addShaderArmature(Armature *addArmature,GLProgram* glpro)
{
   
    //获得所有骨骼，也就是编辑器中的layer
    auto& map = addArmature->getBoneDic();
    for (auto& entry : map){
        auto bone = entry.second;
        //p为一个shader，可以通过 GLProgram::createWithFilenames("gray.vsh","gray.fsh"); 获得，这里是预先创建好了放入了ShaderCache中，直接取出来就行了
        
        if (bone){
            //这里很关键，不能直接像2.x版本那样 对bone->getDisplayRenderNode()->setGLProgram(),要把每个骨骼身上得显示列表再次遍历
            auto list = bone->getDisplayManager()->getDecorativeDisplayList();
            for (auto dd:list){
                if (dd->getDisplay()){
                    //这个方法中已经调用了setGlprogramState(),无需在调用了，也无需在link()和updateUniform()了
                    dd->getDisplay()->setGLProgram(glpro);
                    
                }
            }
        }
    }
}