#ifndef CLIENT_H
#define CLIENT_H

#include <iostream>
#include <climits>

using namespace std;

/***** Client Object *****/

struct myInterruptionIntervals{

   int IntIntervals;
   bool IntHappen  ;
};

class Client{

    int clientID    ;
    int ArrivalTime ;
    int DemandTime  ; //BurstTime
    int StartingTime;

    int numberOfInterruptions;


    string ClientTimeLine;


public:

    int WorkingTrace;
    int InterruptTimeTrace;
    struct myInterruptionIntervals * InterruptionIntervals;

    Client()
    {

        clientID = ArrivalTime = DemandTime =StartingTime = 0;
        InterruptionIntervals = NULL;
        ClientTimeLine = "";
        StartingTime       =  0               ;
        WorkingTrace       =  0               ;
        InterruptTimeTrace =  0               ;
        ClientTimeLine     = "Client Number: " + to_string(clientID) + " Should Take: " + to_string(DemandTime) +" TU,";
    }

    Client(int _clientID, int _arrivalTime, int _demandTime, int _numberOfInterruptions)
    {

        clientID           = _clientID        ;
        ArrivalTime        = _arrivalTime     ;
        DemandTime         = _demandTime      ;
        StartingTime       =  0               ;
        WorkingTrace       =  0               ;
        InterruptTimeTrace =  0               ;
        ClientTimeLine     = "Client Number: " + to_string(clientID) + " Should Take: " + to_string(DemandTime) +" TU,";


        numberOfInterruptions   = _numberOfInterruptions          ;

        InterruptionIntervals   =  new myInterruptionIntervals[numberOfInterruptions];

    }

    ~Client()
    {

        delete [] InterruptionIntervals;

    }


    Client(const Client& oldClient)
    {
        clientID               = oldClient.clientID              ;
        ArrivalTime            = oldClient.ArrivalTime           ;
        DemandTime             = oldClient.DemandTime            ;
        StartingTime           = oldClient.StartingTime          ;
        numberOfInterruptions  = oldClient.numberOfInterruptions ;


        InterruptionIntervals = new myInterruptionIntervals [numberOfInterruptions]  ;

            for(int i = 0 ; i < numberOfInterruptions ; i++)
                InterruptionIntervals[i] = oldClient.InterruptionIntervals[i];

        cout<<"Copy Constructor"<<endl;

    }

    /**************** Setters and Getters **********/

    int getCId(void)                    {return clientID              ;}
    int getArrivalTime(void)            {return ArrivalTime           ;}
    int getDemandTime(void)             {return DemandTime            ;}
    int getStartingTime(void)           {return StartingTime          ;}
    int getnumberOfInterruptions(void)  {return numberOfInterruptions ;}



    void setCId(int ID)                       {clientID    = ID                 ;}
    void setArrivalTime(int ATime)            {ArrivalTime = ATime              ;}
    void setDemandTime(int DTime)             {DemandTime  = DTime              ;}
    void setStartingTime(int STime)           {StartingTime= STime              ;}
    void setClientTimeLine(int _clientID, int _demandTime){ClientTimeLine     = "Client Number: " + to_string(_clientID) + " Should Take: " + to_string(_demandTime) +" TU,";}


    void setClientData(string _ClinetTimeLine)
    {
        ClientTimeLine  += _ClinetTimeLine;

    }


    void setnumberOfInterruptions(int nOInts )
    {

        numberOfInterruptions   = nOInts;
        if (numberOfInterruptions == 0)
        {
            return;
        }

        if( InterruptionIntervals != NULL)
            delete[]InterruptionIntervals;
        InterruptionIntervals   =  new myInterruptionIntervals [numberOfInterruptions];

    }




     /**************** Comments.. **********/


    void SetIntIntervals()
    {
        if(numberOfInterruptions == 0)
        {
            return;
        }

        cout<<"Enter Client Interrupt Intervals"<<endl;

        for(int i = 0 ; i < numberOfInterruptions ; i++)
        {
            cout<<"Interval Number "<<i+1<<endl;


            cin>> InterruptionIntervals[i].IntIntervals;

            InterruptionIntervals[i].IntHappen = false;
        }


    }

    void DisplayClientData()
    {
        cout<<ClientTimeLine<<endl;
    }

     /**************** Operator Overloading.. **********/

    const Client& operator = (const Client & Right)
    {


        clientID             = Right.clientID    ;
        ArrivalTime          = Right.ArrivalTime ;
        DemandTime           = Right.DemandTime  ;
        StartingTime         = Right.StartingTime;
        numberOfInterruptions= Right.numberOfInterruptions;

        delete []InterruptionIntervals;


        InterruptionIntervals =   new myInterruptionIntervals [numberOfInterruptions];

        for(int i = 0 ; i <numberOfInterruptions ; i++)
            InterruptionIntervals[i] = Right.InterruptionIntervals[i];


        return *this;

    }

};

#endif // CLIENT_H
