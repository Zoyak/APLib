//
//  APObjectMrg.cpp
//  TowerWar3_0
//
//  Created by JI LONG on 14-6-10.
//
//

#include "APObjectMrg.h"
#include "APBaseObject.h"
#include "cocos2d.h"
USING_NS_CC;

//--------------------------- Instance ----------------------------------------
//
//   this class is a singleton
//-----------------------------------------------------------------------------
APObjectMrg* APObjectMrg::Instance()
{
    static APObjectMrg instance;
    
    return &instance;
}

//------------------------- GetEntityFromID -----------------------------------
//-----------------------------------------------------------------------------
APBaseObject* APObjectMrg::getEntityFromID(int id)const
{
    //find the entity
    EntityMap::const_iterator ent = m_EntityMap.find(id);
    
    //assert that the entity is a member of the map
    assert ( (ent !=  m_EntityMap.end()) && "<APObjectMrg::GetEntityFromID>: invalid ID");
    
    return ent->second;
}

//--------------------------- RemoveEntity ------------------------------------
//-----------------------------------------------------------------------------
void APObjectMrg::removeEntity(APBaseObject* pEntity)
{
    m_EntityMap.erase(m_EntityMap.find(pEntity->ID()));
    
    //如果是Ref对象则加释放对象
    Ref *ref=dynamic_cast<Ref*>(pEntity);
    if (ref) {
        ref->release();
    }
}

//---------------------------- RegisterEntity ---------------------------------
//-----------------------------------------------------------------------------
void APObjectMrg::registerEntity(APBaseObject* NewEntity)
{
    //如果是Ref对象，则加计数引用
    Ref *ref=dynamic_cast<Ref*>(NewEntity);
    if (ref) {
        ref->retain();
    }
    m_EntityMap.insert(std::make_pair(NewEntity->ID(), NewEntity));
}

void APObjectMrg::registerEntity(APBaseObject* NewEntity,int ObjectID)
{
    NewEntity->setID(ObjectID);
    this->registerEntity(NewEntity);
}


//删除重置对象管理
void APObjectMrg::reset()
{
    for (auto& it : m_EntityMap ) {
        Ref *ref=dynamic_cast<Ref*>(it.second);
        ref->release();
    }
    m_EntityMap.clear();
    
}
