//
//  APAPAPMessageDispatcher.cpp
//  TowerWar3_0
//
//  Created by JI LONG on 14-6-10.
//
//

#include "APMessageDispatcher.h"
#include "APBaseObject.h"
#include "APObjectMrg.h"
#include "APMessage.h"
//#include "DateHelper.h"

using std::set;

//uncomment below to send message info to the debug window
//#define SHOW_MESSAGING_INFO

//--------------------------- Instance ----------------------------------------
//
//   this class is a singleton
//-----------------------------------------------------------------------------
APMessageDispatcher* APMessageDispatcher::Instance()
{
    static APMessageDispatcher instance;
    
    return &instance;
}

//----------------------------- Dispatch ---------------------------------
//
//  see description in header
//------------------------------------------------------------------------
void APMessageDispatcher::Discharge(APBaseObject* pReceiver, const APMessage& telegram)
{
    if (!pReceiver->handleMessage(telegram))
    {
        //telegram could not be handled
#ifdef SHOW_MESSAGING_INFO
        debug_con << "Message not handled" << "";
#endif
    }
}

//---------------------------- DispatchMsg ---------------------------
//
//  given a message, a receiver, a sender and any time delay, this function
//  routes the message to the correct agent (if no delay) or stores
//  in the message queue to be dispatched at the correct time
//------------------------------------------------------------------------
void APMessageDispatcher::DispatchMsg(double       delay,
                                    int          sender,
                                    int          receiver,
                                    int          msg,
                                    void*        AdditionalInfo = NULL)
{
    
    //get a pointer to the receiver
    APBaseObject* pReceiver = APObjectMrg::Instance()->getEntityFromID(receiver);
    
    //make sure the receiver is valid
    if (pReceiver == NULL)
    {
        std::cout << "\nWarning! No Receiver with ID of " << receiver << " found" << "";
        return;
    }
    
    //create the telegram
    //APMessage telegram(0, sender, receiver, msg, AdditionalInfo);
    APMessage telegram;
    telegram.Sender=sender;
    telegram.Receiver=receiver;
    telegram.Msg=msg;
    telegram.ExtraInfo=AdditionalInfo;
    telegram.DispatchTime=0;
    
    //if there is no delay, route telegram immediately
    if (delay <= 0.0)
    {
#ifdef SHOW_MESSAGING_INFO
        debug_con << "\nTelegram dispatched at time: " << TickCounter->GetCurrentFrame()
        << " by " << sender << " for " << receiver
        << ". Msg is " << msg << "";
#endif
        
        //send the telegram to the recipient
        Discharge(pReceiver, telegram);
    }
    
    //else calculate the time when the telegram should be dispatched
    else
    {
        //double CurrentTime = TickCounter->GetCurrentFrame();
        //get curr time
        time_t timet;
        time(&timet);
        double CurrentTime=timet;
        telegram.DispatchTime = CurrentTime + delay;
        
        //and put it in the queue
        std::cout << "priorityQ insert:[%d]" << PriorityQ.size() <<std::endl;
        PriorityQ.insert(telegram);
        std::cout << "priorityQ after insert:[%d]" << PriorityQ.size() <<std::endl;
#ifdef SHOW_MESSAGING_INFO
        debug_con << "\nDelayed telegram from " << sender << " recorded at time "
        << TickCounter->GetCurrentFrame() << " for " << receiver
        << ". Msg is " << msg << "";
#endif
    }
}

//---------------------- DispatchDelayedMessages -------------------------
//
//  This function dispatches any telegrams with a timestamp that has
//  expired. Any dispatched telegrams are removed from the queue
//------------------------------------------------------------------------
void APMessageDispatcher::DispatchDelayedMessages()
{
    //first get current time
    //double CurrentTime = TickCounter->GetCurrentFrame();
    time_t timet;
    time(&timet);
    double CurrentTime=timet;
    //now peek at the queue to see if any telegrams need dispatching.
    //remove all telegrams from the front of the queue that have gone
    //past their sell by date
    while( !PriorityQ.empty() &&
          (PriorityQ.begin()->DispatchTime < CurrentTime) &&
          (PriorityQ.begin()->DispatchTime > 0) )
    {
        //read the telegram from the front of the queue
        const APMessage& telegram = *PriorityQ.begin();
        
        //find the recipient
        APBaseObject* pReceiver = APObjectMrg::Instance()->getEntityFromID(telegram.Receiver);
        
#ifdef SHOW_MESSAGING_INFO
        debug_con << "\nQueued telegram ready for dispatch: Sent to "
        << pReceiver->ID() << ". Msg is "<< telegram.Msg << "";
#endif
        
        //send the telegram to the recipient
        Discharge(pReceiver, telegram);
        
        //remove it from the queue
        PriorityQ.erase(PriorityQ.begin());
    }
}



