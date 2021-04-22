#ifndef CASHIER_H
#define CASHIER_H

#define CASHIER_NUMBER 3


/******* Cashier Object ***/

class Cashier{


    bool FreeCashier            ;
    int remaingingCashierTime   ;
    int CashierID               ;

public:
    static int BeginningWork    ;

    Cashier()
    {
        FreeCashier = true;
        remaingingCashierTime = 0 ;
    }


    /****************Setters and Getters ***************/


   bool getFreeCashier(void)          {return FreeCashier   ;}
   int  getremaingingCashierTime(void){return remaingingCashierTime;}
   int  getCashierID    (void)        {return CashierID            ;}

   void setFreeCashier(bool FC)          {FreeCashier =    FC        ;}
   void setremaingingCashierTime(int RCT){remaingingCashierTime = RCT;}
   void setCashierID(int CashID)         {CashierID = CashID         ;}

};

int Cashier::BeginningWork    = 0;



/***********************************************************************************
           Name:setCshierID

Desc: Sets Each Cashier ID.

    Input: _myCashiers,            Desc: Cashier Container,               Type: Cashier Array

    Output: Void.

*************************************************************************************/
void setCshierID(Cashier _myCashiers[])
{
    for(int i = 0 ; i < CASHIER_NUMBER ; i++)
    {
        _myCashiers[i].setCashierID(i+1);
    }

}

#endif // CASHIER_H
