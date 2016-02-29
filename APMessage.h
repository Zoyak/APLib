//
//  APMessage.h
//  TowerWar3_0
//
//  Created by JI LONG on 14-6-10.
//
//

#ifndef __TowerWar3_0__APMessage__
#define __TowerWar3_0__APMessage__

#include <iostream>
#include <math.h>

struct APMessage
{
    //the entity that sent this telegram
    int          Sender;
    
    //the entity that is to receive this telegram
    int          Receiver;
    
    //the message itself. These are all enumerated in the file
    //"MessageTypes.h"
    int          Msg;
    
    //messages can be dispatched immediately or delayed for a specified amount
    //of time. If a delay is necessary this field is stamped with the time
    //the message should be dispatched.
    double       DispatchTime;
    
    //any additional information that may accompany the message
    void*        ExtraInfo;
    
    
    APMessage():DispatchTime(-1),
    Sender(-1),
    Receiver(-1),
    Msg(-1)
    {}
    
    
    APMessage(double time,
             int    sender,
             int    receiver,
             int    msg,
             void*  info = NULL): DispatchTime(time),
    Sender(sender),
    Receiver(receiver),
    Msg(msg),
    ExtraInfo(info)
    {}
    
};

const double SmallestDelay = 0.25;


inline bool operator==(const APMessage& t1, const APMessage& t2)
{
    return ( fabs(t1.DispatchTime-t2.DispatchTime) < SmallestDelay) &&
    (t1.Sender == t2.Sender)        &&
    (t1.Receiver == t2.Receiver)    &&
    (t1.Msg == t2.Msg);
}

inline bool operator<(const APMessage& t1, const APMessage& t2)
{

    if (t1 == t2)
    {
        return false;
    }
    
    else
    {
        return  (t1.DispatchTime <= t2.DispatchTime);
    }
}


#endif /* defined(__TowerWar3_0__APMessage__) */
