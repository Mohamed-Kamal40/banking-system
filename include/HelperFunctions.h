#ifndef HELPERFUNCTIONS_H_INCLUDED
#define HELPERFUNCTIONS_H_INCLUDED

/***********************************************************************************
        Name: Swap

        Desc: Function to Swap Two Integers.

        Input: x,       Desc: Address of first Variable to be swapped,  Type: int*

        Input: y,       Desc: Address of second Variable to be swapped, Type: int*

        Output: Void.
*************************************************************************************/

void Swap(int* x , int*y)
{
    int temp ;
    temp = *x;
    *x = *y;
    *y = temp;
}


/***********************************************************************************
        Name: bubbleSort

        Desc: Function to Sort the Interruption Intervals.

        Input: Interruptions,       Desc: Array of Structure of Interrupts   type: struct myInterruptionIntervals[]

        Input: arr_Length,          Desc: Length,                            Type: int

        Output: Void.
*************************************************************************************/


void bubbleSort( struct myInterruptionIntervals Interruptions[], int arr_Length)
{
    int i, j;
    for (i = 0; i < arr_Length-1; i++)
    {
        for (j = 0; j < arr_Length-i-1; j++)
        {
             if (Interruptions[j].IntIntervals > Interruptions[j+1].IntIntervals)
             {
                Swap(&Interruptions[j].IntIntervals, &Interruptions[j+1].IntIntervals);
             }
        }
    }
}



/***********************************************************************************
        Name: Swap

        Desc: Function to Data the is Pointed to from the List.

        Input: x,       Desc: Address of first Pointer to Client to be swapped,  Type: Client**

        Input: y,       Desc: Address of second Pointer to Client to be swapped, Type: Client**

        Output: Void.
*************************************************************************************/
void Swap(Client** x, Client ** y)
{
    Client* temp = *x;
        *x = *y;
    *y = temp;
}






#endif // HELPERFUNCTIONS_H_INCLUDED
