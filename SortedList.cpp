
#include "SortedList.h"


template<class T>
SortedList<T>::SortedList() {
    length = 0;
    head = nullptr;
    curr = nullptr;
}

template<class T>
void SortedList<T>::MakeEmpty() {
    while(head!= nullptr){
        NodeT temp = head;
        head=head->next;
        delete temp;
    }
}

template<class T>
bool SortedList<T>::IsFull() const {
    try{
        NodeT temp = new NodeT;
        delete temp;
    }
    catch(std::bad_alloc error){
        return true;}
    return false;
}

template<class T>
int SortedList<T>::GetLength() const {
    return length;
}

template<class T>
bool SortedList<T>::Contains(T someItem) {
    NodeT temp = head;
    while(temp != nullptr){
        if(temp->info == someItem)
            return true;
        temp=temp->next;
    }
    return false;
}

template<class T>
void SortedList<T>::PutItem(T item) {
    if(IsFull())
        return;
    NodeT* newNode = new NodeT;
    newNode->info = item;
    ++length;
    if(head == nullptr){
        head == newNode;
        return;}
    NodeT* temp = head;
    NodeT* prev = nullptr;
    while(temp != nullptr){
        if(temp->info > item){
            if(temp != head)
                prev->next = newNode;
            else
                head=newNode;
            return;
        }
        prev = temp;
        temp= temp->next;
    }
    prev->next=newNode;
}

template<class T>
void SortedList<T>::DeleteItem(T item) {
    NodeT* temp = head;
    NodeT* prev = nullptr;
    while(temp != nullptr){
        if(temp->info == item){
           if(temp == head)
               head = head->next;
           else
               prev->next = temp->next;
           delete temp;
           length--;
        }
        prev = temp;
        temp= temp->next;
    }
}

template<class T>
void SortedList<T>::ResetIterator() {
    curr = head;
}

template<class T>
int SortedList<T>::GetNextItem() {
    T temp = curr->info;
    curr = curr->next;
    return temp;
}

