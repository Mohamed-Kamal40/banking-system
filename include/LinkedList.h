#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include "Node.h"

/** Linked List Ob***/

template<class T>
class LinkedList
{

public:
    Node<T> *head, *tail;
    int counter ;
    LinkedList()
    {
        head = tail = NULL;
        counter = 0 ;
    }

   // void Add(Node<T> *newNode);

    void Add(T *data)
    {
        Node<T> *newNode = new Node<T>(data);


        if(head == NULL)
        {

            head = tail = newNode;
        }
        else
        {

            tail->Next = newNode;
            newNode->Prev = tail;
            tail = newNode;
        }
        counter++;
    }



    void Display()
    {
        Node<T> *current = head;

        while(current != NULL)
        {

            (current->Data)->DisplayClientData();

            current = current->Next;


        }
    }

    T* Delete()
    {
        T *data ;
        Node<T> *pDelete = Search(tail->Data);

        data = tail->Data;

        if(pDelete == NULL)
            return NULL;

        if(pDelete == head)
        {
            if(pDelete == tail) // if(head->Next == NULL)
            {
                head = tail = NULL;
            }
            else
            {
                head = head->Next;
                head->Prev = NULL;
            }
        }
        else if(pDelete == tail)
        {
            tail = tail->Prev;
            tail->Next = NULL;
        }
        else
        {
            pDelete->Prev->Next = pDelete->Next; // A->Next = B
            pDelete->Next->Prev = pDelete->Prev; // B->Prev = A
        }

        delete pDelete;
        counter--;
        return data;
    }

    void InsertAfter(T *afterData, T *newData)
    {
         Node<T> *pDelete = Search(afterData);

         if(pDelete->Next == NULL){

                Add(newData);
         }
         else{

            Node<T> *newNode = new Node<T>(newData);

            newNode->Next = pDelete->Next;
            pDelete->Next->Prev = newNode;

            pDelete->Next = newNode;
            newNode->Prev = pDelete;
         }


    }

private:
    Node<T>* Search(T *data)
    {
        Node<T> *current = head;

        while(current != NULL)
        {
            if(current->Data == data)
                return current;

            current = current->Next;
        }

        return NULL;
    }
};


/***********************************************************************************
        Name: bubbleSort

        Desc: Function to Sort the Clients Based On Thier Arrival Time.

        Input: L,       Desc: List of Clients   type: LinkedList<T>

        Output: Void.
*************************************************************************************/


template<class T>
void BubbleSort(LinkedList<T> L)
{
    int sorted = 0;
    Node<T>* current  = L.head;

    Node<T>* lastCurrent  = NULL;
    do
    {
        sorted = 0;
        current  = L.head;

        while(current->Next != lastCurrent)
        {

            if(current->Data->getArrivalTime() < current->Next->Data->getArrivalTime())
            {

                Swap(&(current->Data),&(current->Next->Data));
                sorted = 1;
            }

            current = current->Next;
        }
        lastCurrent = current;
    }while(sorted);
}

#endif // LINKEDLIST_H
