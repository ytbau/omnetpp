/*
 * Node.cc
 *
 *  Created on: Jun 19, 2016
 *      Author: OMNeT++
 */

#include <omnetpp.h>

class Node : public cSimpleModule
{
private:
    int num_packet_sent;
    int num_packet_received;
    double time_interval;
protected:
    virtual void initialize();
    virtual void handleMessage(cMessage *msg);
    virtual void finish();
};

Define_Module(Node);

void Node::initialize()
{
    num_packet_sent = 0;
    num_packet_received = 0;
    time_interval = 0.1;

    cMessage *msg = new cMessage;
    scheduleAt(0.01, msg);
}

void Node::handleMessage(cMessage* msg)
{
    if(msg->isSelfMessage())
    {
        cMessage *out_msg = new cMessage();
        send(out_msg, "out");
        num_packet_sent++;
        scheduleAt(simTime()+time_interval, msg);
    }
    else
    {
        num_packet_received++;
        delete(msg);
    }
}

void Node::finish()
{
    recordScalar("Number of sent message ", num_packet_sent);
    recordScalar("Number of received message ", num_packet_received);
}

