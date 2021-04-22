#ifndef NODE_H
#define NODE_H

#include<iostream>

/**** Node Object ****/
template<class T>
class Node
{
    public:
        T *Data;
        Node *Next, *Prev;
        Node()
        {

        }
        Node(T *data)
        {
            Data = data;
            Next = Prev = NULL;
        }

    const Node& operator = (const Node & Right)
    {

        Next = Right.Next;
        Prev = Right.Prev;
        Data = Right.Data;

        return *this;

    }



};
#endif // NODE_H
