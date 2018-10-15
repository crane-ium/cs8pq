#ifndef INFO_H
#define INFO_H

#include <iostream>

using namespace std;

template<class T>
struct info{
    T item;
    int priority;
    //CTOR
    info(){}
    info(T i, int p):item(i),priority(p){}
    //MOD MEMBER FUNCTIONS
    T get_item() const;
    int get_priority() const;
    //OVERLOADED OPERANDS
    bool operator <(const info<T>& rhs);
    bool operator >(const info<T>& rhs);

    //FRIEND FUNCTIONS
    //cout item and priority
    template<class U>
    friend ostream& operator <<(ostream& outs, const info<U>& rhs);
};


//-------- INFO -----------
template<class T>
ostream& operator <<(ostream& outs, const info<T>& rhs){
    outs << "Item: " << setw(10) << rhs.item << "  Priority: " \
         << setw(10) << rhs.priority;
    return outs;
}
template<class T>
bool info<T>::operator <(const info<T>& rhs){
    return ((this->priority < rhs.priority)?(true):(false));
}
template<class T>
bool info<T>::operator >(const info<T>& rhs){
    return ((this->priority > rhs.priority)?(true):(false));
}
template<class T>
T info<T>::get_item() const{
    return item;
}
template<class T>
int info<T>::get_priority() const{
    return priority;
}
#endif // INFO_H
