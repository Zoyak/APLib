//
//  APMessageDispatcher.h
//  TowerWar3_0
//
//  Created by JI LONG on 14-6-10.
//
//

#ifndef __TowerWar3_0__APMessageDispatcher__
#define __TowerWar3_0__APMessageDispatcher__

#include <iostream>

#include <set>
#include <string>


class APMessage;
class APBaseObject;


//to make life easier...
#define kMessageManager APMessageDispatcher::Instance()

//to make code easier to read
const double SEND_MSG_IMMEDIATELY = 0.0;
const int    NO_ADDITIONAL_INFO   = 0;
const int    SENDER_ID_IRRELEVANT = -1;


class APMessageDispatcher
{
private:
    
    //a std::set is used as the container for the delayed messages
    //because of the benefit of automatic sorting and avoidance
    //of duplicates. Messages are sorted by their dispatch time.
    std::set<APMessage> PriorityQ;
    
    //this method is utilized by DispatchMsg or DispatchDelayedMessages.
    //This method calls the message handling member function of the receiving
    //entity, pReceiver, with the newly created telegram
    void Discharge(APBaseObject* pReceiver, const APMessage& msg);
    
    APMessageDispatcher(){}
    
    //copy ctor and assignment should be private
    APMessageDispatcher(const APMessageDispatcher&);
    APMessageDispatcher& operator=(const APMessageDispatcher&);
    
public:
    
    static APMessageDispatcher* Instance();
    
    //send a message to another agent. Receiving agent is referenced by ID.
    void DispatchMsg(double      delay,
                     int         sender,
                     int         receiver,
                     int         msg,
                     void*       ExtraInfo);
    
    //send out any delayed messages. This method is called each time through
    //the main game loop.
    void DispatchDelayedMessages();
};

#endif /* defined(__TowerWar3_0__APMessageDispatcher__) */
