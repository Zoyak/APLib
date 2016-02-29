//
//  APObjectMrg.h
//  对象管类类
//
//  Created by JI LONG on 14-6-10.
//
//

#ifndef __TowerWar3_0__APObjectMrg__
#define __TowerWar3_0__APObjectMrg__

#include <iostream>
#include <map>
#include <cassert>


#define kGameObjects APObjectMrg::Instance()

class APBaseObject;
typedef std::map<int, APBaseObject*> EntityMap;

class APObjectMrg
{
public:
    static APObjectMrg* Instance();
    //this method stores a pointer to the entity in the std::vector
    //m_Entities at the index position indicated by the entity's ID
    //(makes for faster access)
    void registerEntity(APBaseObject* NewEntity);
    
    void registerEntity(APBaseObject* NewEntity,int ObjectID);
    
    //returns a pointer to the entity with the ID given as a parameter
    APBaseObject* getEntityFromID(int id) const;
    
    //this method removes the entity from the list
    void removeEntity(APBaseObject* pEntity);
    
    //clears all entities from the entity map
    void reset();
    
    //获取所有实体类对象
    EntityMap* getAllEntity(){ return &m_EntityMap; };
private:
    
    
    
    
    //to facilitate quick lookup the entities are stored in a std::map, in which
    //pointers to entities are cross referenced by their identifying number
    EntityMap m_EntityMap;
    
    APObjectMrg(){}
    
    //copy ctor and assignment should be private
    APObjectMrg(const APObjectMrg&);
    APObjectMrg& operator=(const APObjectMrg&);
    

};
#endif /* defined(__TowerWar3_0__APObjectMrg__) */
