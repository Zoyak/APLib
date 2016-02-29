//
//  APBaseObject.h
//  TowerWar3_0
//
//  Created by JI LONG on 14-6-10.
//
//

#ifndef __TowerWar3_0__APBaseObject__
#define __TowerWar3_0__APBaseObject__

#include <iostream>


struct APMessage;

class APBaseObject
{
public:
    enum {default_entity_type = -1};
    
    int   ID() const {return m_ID;}
    
    void setID(int val) { m_ID=val; };
    
    int ObjectType() const { return m_iType; };
    
    void setObjectType(int val) { m_iType=val; };

    virtual bool handleMessage(const APMessage& msg){return false;}
    int  EntityType()const{return m_iType;}
    
protected:
    int         m_ID;
    int         m_iType;
};


#endif /* defined(__TowerWar3_0__APBaseObject__) */
