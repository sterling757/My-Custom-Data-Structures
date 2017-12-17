#ifndef DSLIST_H
#define DSLIST_H
#include "dsstring.h"
#include "DsNode.h"
#include <ostream>

template <class T>
class DsList{

        private:
           //size of list
             int sizeOfList = 0;

           //beginning of list
           DsNode<T>* head;

           //end of list
           DsNode<T>* tail;

           //class nodeIndex
           DsNode<T>* nodeIndex(int position) const;

           //Copies list
           void copyList(const DsList& origin, DsList& location);

           //private function to insert elements at a certain pointer
           void insert(DsNode<T>* ptr, T element);

       public:

           //constructors
           DsList();
           DsList(const DsList& LL);

           //returns false if empty
           bool isEmpty();

           //returns the value of sizeOfList
           int getLength() const;

           //functions relating to elements in the list
           T& first();
           T get(int position) const;
           T& last();
           int find(T value);
           T* getvaluePointer(int position);

           //functions that modify the list
           void push_back(T value);
           void push_first(T value);

           void assign(int position, T value);
           void insert(int position, T value);

           //functions that remove elements from the list
           T removeElement(int position);
           T popBack();
           T popFirst();
           void clearList();

           //resizes the list
           void resizeList(int size, T val);

           //overloads << operator
           template<class U>
           friend std::ostream& operator<<(std::ostream& o, const DsList<U>& list);

           //overloaders [] and =
           T& operator[](int position);
           DsList& operator=(const DsList& list);

           //getters and setters
           void setHead(DsNode<T>* value);
           DsNode<T>* getHead() const;
           void setTail(DsNode<T>* value);
           DsNode<T>* getTail() const;

           //destructor
           ~DsList();


};


//constructor for DsList class
template <class T>
DsList<T>::DsList(){


    head = nullptr;
    tail = nullptr;

}

//copy constructor
template <class T>
DsList<T>::DsList(const DsList &LL){

    sizeOfList = LL.sizeOfList;
    head = nullptr;
    tail = nullptr;

    copyList(LL, *this);

}

//this function returns the position of a node
template<class T>
DsNode<T>*DsList<T>::nodeIndex(int position) const{

    //checks if index is in bounds
    if(position >= sizeOfList || position < 0){

        cerr << "INDEX ENTERED NOT VALID!";

    }
    DsNode<T>* theNode;

    //sees which way the node is coming due to position
    if(position < sizeOfList / 2){

        theNode = head;

    }
    else
        theNode = tail;

    //starts from front of linked list
    if(theNode == head){

        for(int i = 0; i < position; i++){

            theNode = theNode->nextNode;

        }
    }
    //starts from back of linked list
    else{

        for(int i = sizeOfList-1; i > position; i--){

            theNode = theNode->lastNode;

        }
    }

    return theNode;

}




//this function copies a list into "origin"
template<class T>
void DsList<T>::copyList(const DsList &origin, DsList &location){

    //if empty
    if(origin.getHead() == nullptr){

        return;

    }
    //sets head
    location.setHead(new DsNode<T>(origin.getHead()->content));
    
    //if size is one, tail is equal to head
    if(origin.sizeOfList == 1){

        location.setTail(head);

    }
    //if size is not empty or one
    else if(origin.sizeOfList > 1){

        //temp head variable
        DsNode<T>* temp = location.getHead();
        //variable to get next node
        DsNode<T>* source = origin.getHead()->nextNode;

        while(source != nullptr){
            //adds new node
            DsNode<T>* inserted = new DsNode<T>(source->content);

            temp->nextNode = inserted;
            source = source->nextNode;
            inserted->lastNode = temp;
            temp = temp->nextNode;

        }
        //sets tail
        location.setTail(temp);

    }
}

//this function inserts an element into the Linked list
template <class T>
void DsList<T>::insert(DsNode<T> *ptr, T element){

    //node to put into LL
    DsNode<T>* insertedNode = new DsNode<T>(element);

    DsNode<T>* last = ptr->lastNode;

    if(ptr == head){

        head = insertedNode;

    }

    insertedNode->nextNode = ptr;
    ptr->lastNode = insertedNode;

    //if last element is node, put element in last
    if(last != nullptr){

        last->nextNode = insertedNode;
        insertedNode->lastNode = last;

    }

    sizeOfList++;

}

//class that inserts a value at a position
template <class T>
void DsList<T>::insert(int position, T value){

    //if position is the same size just put in back
    if(position == sizeOfList){

        push_back(value);

    }
    else
        insert(nodeIndex(position), value);
}

//this class returns the length of the list
template <class T>
int DsList<T>::getLength() const{

    //returns because of private member variable
    return sizeOfList;

}

//setter for Head
template <class T>
void DsList<T>::setHead(DsNode<T> *value){

    head = value;

}

//getter for head
template <class T>
DsNode<T>* DsList<T>::getHead()const{

    return head;

}

//setter for tail
template <class T>
void DsList<T>::setTail(DsNode<T> *value){

    tail = value;

}
//getter for tail
template <class T>
DsNode<T>* DsList<T>::getTail()const{

    return tail;

}

//this function overloads the "=" operator
template <class T>
DsList<T>& DsList<T>::operator=(const DsList& list){

    clearList();
    copyList(list, *this);
    sizeOfList = list.sizeOfList;
    return *this;

}

//overloaded [] operator to return the position
template <class T>
T& DsList<T>::operator [](int position){

    return nodeIndex(position)->content;
}

//this function overloads the "<<" operator
template <class U>
std::ostream& operator <<(std::ostream& o, const DsList<U>& list){

    DsNode<U>* temp = list.head;

    if(list.head == nullptr){
        o << "The List Is Empty!";

    }

    else{
        //puts getContent into stream
        o << temp->getContent();

        while(temp->getnextNode() != nullptr){

            temp = temp->getnextNode();
            o << ", " << temp->getContent();

        }
    }

    return o;

}


//inserts element in first element of list
template <class T>
void DsList<T>::push_first(T value){

    insert(0, value);

}

//inserts an element to the back of the list
template <class T>
void DsList<T>::push_back(T value){

    DsNode<T>* temp = new DsNode<T>(value);

    //if tail isnt empty
    if(tail != nullptr){
        tail->nextNode = temp;
        temp->lastNode = tail;
    }
    //if it is empty
    else{
        head = temp;

    }
    tail = temp;


    sizeOfList++;

}



//this function removes an element at a given position
template <class T>
T DsList<T>::removeElement(int position){

    DsNode<T>* currentNode = nodeIndex(position);
    DsNode<T>* last = currentNode->lastNode;
    DsNode<T>* next = currentNode->nextNode;

    if(last != nullptr){

        last->nextNode = next;
        currentNode->lastNode = nullptr;

    }

    if(next != nullptr){

        next->lastNode = last;
        currentNode->nextNode = nullptr;

    }

    if(head == currentNode){

        head = next;

    }

    if((tail == currentNode)){

        tail = last;

    }
    //the value of the current node
    T data = currentNode->content;

    delete currentNode;
    sizeOfList--;
    return data;
}

//this function removes the first element of the list
template <class T>
T DsList<T>::popFirst(){

    return removeElement(0);

}

//this function removes the last element of the list
template <class T>
T DsList<T>::popBack(){

    return removeElement(sizeOfList-1);

}

//this function clears out all the contents of the list
template <class T>
void DsList<T>::clearList(){

    while(sizeOfList != 0){

        popFirst();

    }
}

//this function checks if the list is empty and returns a boolean
template <class T>
bool DsList<T>::isEmpty(){
    if(sizeOfList == 0){
        return true;
    }
    else
        return false;
}

//gets the value at a specific node
template <class T>
T DsList<T>::get(int position) const{

    return (nodeIndex(position)->content);

}

//function that returns the value in the first node
template <class T>
T& DsList<T>::first(){

    //prints error if nothing is in first index
    if(head == nullptr)
        cerr << "THERE IS NOTHING IN YOUR LIST!" << endl;

    return head->content;

}

//function that returns the value in the last node
template <class T>
T& DsList<T>::last(){

     //prints error if nothing is in last index
    if(tail == nullptr)
        cerr << "THERE IS NOTHING IN YOUR LIST!" << endl;

    return tail->content;

}

//function that finds the node where the passed in value resides
template<class T>
int DsList<T>::find(T value)
{

    DsNode<T>* temp = head;

    //for loop to find the position of the value in list
    for(int i = 0; i < sizeOfList; i++)
    {

        if(value == temp->content)
            return i;

        temp = temp->nextNode;

    }

    return -1;

}

//function that changes the value at a given postition
template<class T>
void DsList<T>::assign(int position, T value)
{

    DsNode<T>* temp = nodeIndex(position);
    temp->content = value;

}

//destructor
template <class T>
DsList<T>::~DsList(){

    clearList();
    head = nullptr;
    tail = nullptr;

}

#endif // DSLIST_H
