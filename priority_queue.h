#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

#include <iomanip>
#include "heap.h"
#include "info.h"

using namespace std;

template<class T>
class pqueue{
public:
    //CTOR
    pqueue();

    //MOD MEMBER FUNCTIONS
    void insert(const T& value, int p);
    info<T> pop();

    //CONST MEMBER FUNCTIONS
    info<T> top() const;

    bool is_empty() const;
    int size() const;
    void print() const;

    //FRIEND FUNC
    //assigns a new heap to the pqueue! :)
    pqueue<T>& operator =(heap<info<T> >& rhs);

private:
    heap<info<T> > my_heap; //holds a heap data structure of type info<T>
    //and in this case info<int>
};


//----------- priority queue ------------
template<class T>
pqueue<T>::pqueue(){

}

template<class T>
void pqueue<T>::insert(const T &value, int p){
    info<int> inf(value, p);
    my_heap.insert(inf);
}

template<class T>
info<T> pqueue<T>::pop(){
    return my_heap.pop();
}

template<class T>
void pqueue<T>::print() const{
    my_heap.print();
}

template<class T>
bool pqueue<T>::is_empty() const{
    return my_heap.is_empty();
}

template<class T>
info<T> pqueue<T>::top() const{
    return my_heap.top();
}

template<class T>
pqueue<T>& pqueue<T>::operator =(heap<info<T> >& rhs){
    my_heap = rhs;
}


#endif // PRIORITY_QUEUE_H
