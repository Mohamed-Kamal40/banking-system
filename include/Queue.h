#ifndef QUEUE_H
#define QUEUE_H

#include "LinkedList.h"
/*** Queue Object ***/
template <class T>
class Queue
{
    LinkedList<T> L ;

    public:

        int QueueCounter ;

        Queue(){ QueueCounter = 0 ;}
        virtual ~Queue(){}



    void enQueue (T* data)
    {
        L.Add(data);
        ++QueueCounter;
    }



    void display()
    {

        L.Display();
    }


    Node<T> deQueue()
    {

        QueueCounter--;
        Node<T> data ;
        Node<T> * current = L.head;


        data.Data = current->Data;
        data.Next = current->Next;
        data.Prev = current->Prev;


        L.head = L.head->Next;



        delete current;

        return data;
    }


};


#endif // QUEUE_H
