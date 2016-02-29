//
//  State.h
//  Agoura
//
//  Created by liuye on 15-2-3.
//
//

#ifndef Agoura_State_h
#define Agoura_State_h

template <class entity_type>
class State
{
public:
    
    virtual ~State(){}
    
    //是否可以跳转当前状态
    virtual bool canChangeState(State<entity_type>* aState){ return true; }
    
    //this will execute when the state is entered
    virtual void enter(entity_type*)=0;
    
    //this is the states normal update function
    virtual void execute(entity_type*)=0;
    
    //this will execute when the state is exited. (My word, isn't
    //life full of surprises... ;o))
    virtual void exit(entity_type*)=0;
    
    //this is the states normal update function
    virtual void executeTime(entity_type*,float dt)=0;
    
};

#endif
