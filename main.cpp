#include <iostream>
#include <climits>
using namespace std;

#include "Client.h"
#include "HelperFunctions.h"
#include "LinkedList.h"
#include "Cashier.h"
#include "Queue.h"


/***********************************************************************************
           Name:Algorithm  ->  CPU Scheduling Using RR Function

Desc: The Main Algorithm of The Project, It detects the entry and Interruption of Each Client.

    Input: C,            Desc: Cashier Container,               Type: Cashier Array

    Input: nOfCashiers,  Desc: Cashier Container,               Type: Int.

    Input: ClientQ,      Desc: Queue of Clients Waiting,        Type: Queue<Client>

    Input: quantum,      Desc: Cpu Scheduling Quantum iterator  Type: int

    Output: Void.

*************************************************************************************/

void Algorithm(Cashier C[], int nOfCashiers , Queue<Client> ClientQ  ,int quantum)
{
    Node<Client> ClientData[ClientQ.QueueCounter];
    int tempRemainingTime[3] = {0,0,0} ;
    bool notOver = false;


    while(1)
    {
        notOver = true;
        Cashier::BeginningWork++;

        for(int i = 0 ; i < nOfCashiers ; i++)
        {


            if(C[i].getFreeCashier() == true && ClientQ.QueueCounter >0 )
            {
                ClientData[i] = ClientQ.deQueue();

                C[i].setremaingingCashierTime(ClientData[i].Data->getDemandTime()) ;
                tempRemainingTime[i] =  C[i].getremaingingCashierTime();
                C[i].setFreeCashier(false);
                notOver = false;

                cout<<"Client Number: "<<ClientData[i].Data->getCId()<<" Is Processing with Cashier Number: ";
                cout<<C[i].getCashierID()<<endl;

                ClientData[i].Data->setClientData(" Started Processing at TU: " + to_string(Cashier::BeginningWork) +" CTU, On Cashier: "+ to_string(C[i].getCashierID()));
            }

            else
            {

                if( tempRemainingTime[i] > 0)
                {

                    notOver = false;
                    if(tempRemainingTime[i] > quantum)
                    {

                        ClientData[i].Data->WorkingTrace+= quantum;
                       // cout<<"here";
                       // cout<<ClientData[i].Data->InterruptTimeTrace<<endl;

                        if((ClientData[i].Data->InterruptTimeTrace < ClientData[i].Data->getnumberOfInterruptions() )
                           && ClientData[i].Data->WorkingTrace >= ClientData[i].Data->InterruptionIntervals[ClientData[i].Data->InterruptTimeTrace].IntIntervals
                           && !(ClientData[i].Data->InterruptionIntervals[ClientData[i].Data->InterruptTimeTrace].IntHappen))
                        {
                             //cout<<"here"<<endl;
                             cout<<"Client Number: "<<ClientData[i].Data->getCId()<<" Got Interrupted ";
                             cout<<"In Time Unit: "<<ClientData[i].Data->WorkingTrace<<" (Client TU)"<<endl;



                            ClientData[i].Data->setClientData(" Got Interrupted in TU:" + to_string(ClientData[i].Data->WorkingTrace)+"\t");



                            ClientData[i].Data->setDemandTime( ClientData[i].Data->getDemandTime() -  quantum);
                            ClientQ.enQueue(ClientData[i].Data);

                            tempRemainingTime[i] = 0;
                              notOver = false;
                              C[i].setFreeCashier(true);
                              ClientData[i].Data->InterruptionIntervals[ClientData[i].Data->InterruptTimeTrace].IntHappen = true;
                              ClientData[i].Data->InterruptTimeTrace++;
                              break;
                        }
                         tempRemainingTime[i] -= quantum;
                        C[i].setremaingingCashierTime(tempRemainingTime[i]);



                    }
                    else
                    {

                        cout<<"Client Number: " << ClientData[i].Data->getCId()<<" Finished Working On Cashier: "<<C[i].getCashierID()<<endl;
                        tempRemainingTime[i] = 0;
                         C[i].setFreeCashier(true);
                         notOver = false;
                        C[i].setremaingingCashierTime(tempRemainingTime[i]);
                    }
                }
            }
        }

        if(notOver == true )
            break;
    }
}


/***********************************************************************************
        Name: CUserInputValidation

        Desc: Validating User Input Entry.

        Input: void.

        Output: Void.
*************************************************************************************/


void UserInputValidation(void)
{
    /***Client Row ***/
    Client DBClients[20];
    LinkedList<Client> ClientList ;

    /***Bank Cashiers ***/
    Cashier myCashiers[CASHIER_NUMBER];
    setCshierID(myCashiers);

    /***Client Queue ***/
    Queue<Client>ClientQ;

    char ClientEntery = 'y';
    int userInput;
    int idArr[20];


    int IdCounter = 0 ;
    int ClientCounter = 0 ;
    while(ClientEntery == 'y' || ClientEntery == 'Y' )
    {
        /*** Validating ID **/
        bool idFlag = false;
        do{
            idFlag = true;
            cout<<"Enter Client ID: ";
            cin>>userInput;
            cin.clear();
            cin.ignore(100, '\n');
            idArr[IdCounter] = userInput;
            for(int i = 0 ; i < IdCounter ; i++ )
            {
                if(idArr[i] == userInput)
                {
                    cout<<"Enter a Unique ID Please:"<<endl;
                    IdCounter--;
                    idFlag = false;
                }else
                {
                    idFlag = true;
                }
            }
            IdCounter++;

        }while(!idFlag);

        DBClients[ClientCounter].setCId(userInput);


         /*** Validating Arrival Time ***/
         do{
            cout<<"Enter Client Arrival Time: ";
            cin>>userInput;
            cin.clear();
            cin.ignore(100, '\n');
         }while(!userInput);

        DBClients[ClientCounter].setArrivalTime(userInput);

        /*** Validating Demanding Time ***/

        do{
            cout<<"Enter Client Demanding Time: ";
            cin>>userInput;
            cin.clear();
            cin.ignore(100, '\n');

        }while(!userInput);

        DBClients[ClientCounter].setDemandTime(userInput);

        /*** Validating Number of Interrupts ***/
            bool flag1 = false;
         do{

            cout<<"Enter Client Number of Client Interrupts: ";
            cin>>userInput;
            cin.clear();
            cin.ignore(100, '\n');
            if(userInput < 0)
            {
            }
            else{
                flag1 = true;
            }

        }while(!flag1);

        DBClients[ClientCounter].setnumberOfInterruptions(userInput);


        DBClients[ClientCounter].SetIntIntervals();
        bubbleSort(DBClients[ClientCounter].InterruptionIntervals,DBClients[ClientCounter].getnumberOfInterruptions());

        ClientList.Add(&DBClients[ClientCounter]);
        DBClients[ClientCounter].setClientTimeLine(DBClients[ClientCounter].getCId(),DBClients[ClientCounter].getDemandTime());
        ClientCounter++;
        cout<<"Click Y to Enter new Client or any key to Exit"<<endl;
        cin>> ClientEntery;
    }


    BubbleSort(ClientList);


    int listCount = ClientList.counter;
    for(int i = 0 ; i < listCount  ; i++)
    {
        ClientQ.enQueue(ClientList.Delete());
    }
    int len = ClientQ.QueueCounter;
    Algorithm(myCashiers, CASHIER_NUMBER , ClientQ ,1);

    cout<<endl<<endl<<endl;
    cout<<"---------------------------------------------------"<<endl;
    cout<<"CTU (Cashier Time Perspective)"<<endl;
    cout<<"TU  (Client  Time Perspective)"<<endl;

    cout<<endl<<endl;

    for(int i = 0 ; i < len ; i++)
    {
        DBClients[i].DisplayClientData();
        cout<<endl<<endl;
    }



}



/***********************************************************************************
        Name: TestingFunction

        Desc: Function to Check Each Progress we did in the Project.

        Input: void.

        Output: Void.
*************************************************************************************/


void TestingFunction(void)
{
    /*testing statically */

    /*
    Client* ClientPtr = NULL;

    LinkedList<Client> Client_LinkedList;

    Cashier myCashiers[CASHIER_NUMBER];
    setCshierID(myCashiers);

    Queue<Client>ClientQ;

    Client C1(1,8,20,3) ;
    Client C2(2,7,10,2) ;
    Client C3(3,10,5,1)  ;
    Client C4(4,1,6,1)  ;
    Client C5(5,15,3,0)  ;

    Client_LinkedList.Add(&C1);
    Client_LinkedList.Add(&C2);
    Client_LinkedList.Add(&C3);
    Client_LinkedList.Add(&C4);
    Client_LinkedList.Add(&C5);

    BubbleSort(Client_LinkedList);

    ClientPtr = Client_LinkedList.Delete();

    cout<<ClientPtr->getCId()<<"\t";
    cout<<ClientPtr->getDemandTime()<<"\t";
    cout<<ClientPtr->getArrivalTime()<<"\t";
    cout<<endl;
    ClientPtr = Client_LinkedList.Delete();

    cout<<ClientPtr->getCId()<<"\t";
    cout<<ClientPtr->getDemandTime()<<"\t";
    cout<<ClientPtr->getArrivalTime()<<"\t";
    cout<<endl;
    ClientPtr = Client_LinkedList.Delete();

    cout<<ClientPtr->getCId()<<"\t";
    cout<<ClientPtr->getDemandTime()<<"\t";
    cout<<ClientPtr->getArrivalTime()<<"\t";
    cout<<endl;
    ClientPtr = Client_LinkedList.Delete();

    cout<<ClientPtr->getCId()<<"\t";
    cout<<ClientPtr->getDemandTime()<<"\t";
    cout<<ClientPtr->getArrivalTime()<<"\t";
    ClientPtr = Client_LinkedList.Delete();
     cout<<endl;

    cout<<ClientPtr->getCId()<<"\t";
    cout<<ClientPtr->getDemandTime()<<"\t";
    cout<<ClientPtr->getArrivalTime()<<"\t";
    cout<<endl;




    C1.SetIntIntervals();
    C2.SetIntIntervals();
    C3.SetIntIntervals();
    C4.SetIntIntervals();

    ClientQ.enQueue(&C1);
    ClientQ.enQueue(&C2);
    ClientQ.enQueue(&C3);
    ClientQ.enQueue(&C4);
    ClientQ.enQueue(&C5);



    Algorithm(myCashiers, CASHIER_NUMBER , ClientQ ,1);
    cout<<endl<<endl<<endl;
    cout<<"---------------------------------------------------"<<endl;
    C1.DisplayClientData();
    cout<<endl;
    C2.DisplayClientData();
    cout<<endl;
    C3.DisplayClientData();
    cout<<endl;
    C4.DisplayClientData();
    cout<<endl;
    C5.DisplayClientData();
     */
}

int main(void)
{


    UserInputValidation();

  return 0;
}
