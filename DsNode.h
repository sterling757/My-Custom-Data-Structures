#ifndef DsNode_H
#define DsNode_H
#include "DsList.h"
#include<ostream>
using namespace std;
template <class T>
class DsNode
{
private:
    template <class U> friend class DsList;
    //Pointers to other DsNodes within list
    DsNode<T>* nextNode;

    //pointer to last node
    DsNode<T>* lastNode;

    //templated content varibale
    T content;

public:

    //Constructors
    DsNode();

    //templated constuctor takes in content
    DsNode(T content);

    //copy constructor
    DsNode(const DsNode<T>& node);

    //overloaded '=' operator
    DsNode<T>& operator=(const DsNode<T>& node);

    //Getters and setters
    void setContent(const T& value);
    T getContent() const;
    void setnextNode(DsNode<T>* value);
    DsNode<T>* getnextNode() const;
    DsNode<T>* getlastNode() const;

    //the last node
    void last(DsNode<T>* value);

    //overload << operator
    template<class V>
    friend std::ostream& operator<<(std::ostream& o, const DsNode<V>& DsNode);

};

//default constructor
template<class T>
DsNode<T>::DsNode(){

    nextNode = nullptr;
    lastNode = nullptr;
    content = 0;

}

//constructor that passes in data
template<class T>
DsNode<T>::DsNode(T data) {

    content = data;
    nextNode = nullptr;
    lastNode = nullptr;

}

//copy constructor
template<class T>
DsNode<T>::DsNode(const DsNode<T>& n){

    content = n.content;
    nextNode = n.nextNode;
    lastNode = nullptr;

}

//overlaods = operator
template<class T>
DsNode<T>& DsNode<T>::operator=(const DsNode<T>& n){

    content = n.content;
    nextNode = n.nextNode;
    lastNode = n.lastNode;

}

//sets the passed in value to content variable
template<class T>
void DsNode<T>::setContent(const T& value){

    content = value;

}

//returns the set content
template<class T>
T DsNode<T>::getContent() const{

    return content;

}

//sets the passed in value to the next node
template<class T>
void DsNode<T>::setnextNode(DsNode<T>* value){

    nextNode = value;

}

//returns the value of the next node
template<class T>
DsNode<T>* DsNode<T>::getnextNode() const{

    return nextNode;

}

//sets the passed in value to the last node
template<class T>
void DsNode<T>::last(DsNode<T>* value){

    lastNode = value;

}

//returns content in the last node
template<class T>
DsNode<T>* DsNode<T>::getlastNode() const{

    return lastNode;

}

#endif // DsNode_H
