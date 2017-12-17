#ifndef DsStack_H
#define DsStack_H
#include "DsList.h"

template<class T>
class DsStack
{
public:

    //takes element off stack
    T pop();

    //looks at whats at a certain index
    T& peek();

    //checks if empty
    bool isEmpty();

    //list of stacks contents
    DsList<T> stackContents() const;

    //int for size of stack
    int size() const;

    //templated variable for first
    T first();

    //pushes element onto stack
    void push(T);

    //destructor
    ~DsStack();

private:

    DsList<T> value;

};

//removes last entry in the stack and returns the last value
template<class T>
T DsStack<T>::pop(){

    return value.popBack();

}

//returns the value in the last element of the stack
template<class T>
T& DsStack<T>::peek(){

    return value.last();

}

//pushes the value onto the stack
template<class T>
void DsStack<T>::push(T d){

    value.push_back(d);

}

//boolean function that chacks if the stack is empty
template<class T>
bool DsStack<T>::isEmpty(){

    return value.isEmpty();

}


//prints out the linked list so user can read the contents of the stack
template<class T>
DsList<T> DsStack<T>::stackContents() const{

    return value;

}

//returns the size of the stack
template<class T>
int DsStack<T>::size() const{

    return value.getLength();

}

//the first element of the stack
template<class T>
T DsStack<T>::first(){

    return value.first();

}

//destructor
template <class T>
DsStack<T>::~DsStack() {

}

#endif
