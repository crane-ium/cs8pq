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

    void insert(const T& value, int p);
    info<T> pop();
    info<T> top() const;

    bool is_empty() const;
    int size() const;
    void print() const;

private:
    heap<info<T> > my_heap;
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


#endif // PRIORITY_QUEUE_H
