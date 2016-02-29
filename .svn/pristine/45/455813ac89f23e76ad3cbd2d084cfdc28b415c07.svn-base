//
//  StateMachine.h
//  Agoura
//
//  Created by liuye on 15-2-3.
//
//

#ifndef Agoura_StateMachine_h
#define Agoura_StateMachine_h

#include "State.h"

template <class player>
class StateMachine
{
public:
    StateMachine(player *owner):m_owner(owner),m_currState(nullptr),m_previousState(nullptr),m_globalState(nullptr){};
    void setCurrState(State<player>* s){ m_currState=s; };
    void setPreviousState(State<player>* s){ m_previousState=s; };
    void setGlobalState(State<player>* s){ m_globalState=s; };
    
    void update() const
    {
        if (m_globalState) {
            m_globalState->execute(m_owner);
        }
        if (m_currState) {
            m_currState->execute(m_owner);
        }
    }
    //with time
    void updateTime(float dt) const
    {
        if (m_globalState) {
            m_globalState->executeTime(m_owner,dt);
        }
        if (m_currState) {
            m_currState->executeTime(m_owner,dt);
        }
    }
    //改变状态
    void changeState(State<player> *state)
    {
        m_previousState=m_currState;
        if(m_currState)
        {
            //是否可以改变状态
            if(!m_currState->canChangeState(state))
            {
                return;
            }
            m_currState->exit(m_owner);
        }
        
        m_currState=state;
        m_currState->enter(m_owner);
    }
    void backState()
    {
        m_currState->exit(m_owner);
        m_currState=m_previousState;
        m_currState->enter(m_owner);
    }
    //returns true if the current state's type is equal to the type of the
    //class passed as a parameter.
    bool isInState(const State<player>* st) const
    {
        if(!m_currState)
        {
            return false;
        }
        if (typeid(*m_currState) == typeid(*st)) return true;
        return false;
    }
    //only ever used during debugging to grab the name of the current state
    std::string getNameOfCurrentState() const
    {
        std::string s(typeid(*m_currState).name());
        //remove the 'class ' part from the front of the string
        if (s.size() > 20)
        {
            s.erase(0, 6);
        }
        return s;
    }
private:
    player *m_owner;
    State<player> *m_currState;
    State<player> *m_previousState;
    State<player> *m_globalState;
};

#endif
