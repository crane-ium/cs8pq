#ifndef HEAP_H
#define HEAP_H
/*heap.h
 * This data structure organizes an array of items based on their priority
 *
 * */

#include <stdlib.h>
#include <iostream>
#include <cassert>
#include <math.h>
#include <algorithm>
#include "arr_func.h"

using namespace std;

template<class T>
struct heap{
    heap():it_arr(NULL), size_cap(0),how_many(0),height(0){}

    //BIG3
    ~heap();
    heap(const heap<T>& h);
    heap<T>& operator =(const heap<T>& h);

    //MOD MEMBER FUNCTIONS
    void insert(const T& item);
    T pop(); //return top item and shuffle the node out of range
    T top() const; //return top item

    //CONST MEMBER FUNCTIONS
    bool is_empty() const;
    size_t size() const; //returns how_many
    size_t capacity() const; //returns the size of the dynamic array
    void print() const; //print the array in order

    //FRIEND FUNCTIONS
    template<class U>
    friend ostream& operator <<(ostream& outs, heap<U>& rhs);

private:
    //PRIVATE FUNCTIONS
    bool swap_parent(const size_t &i); //Swaps with parents until sorted. Returns true if swap
    bool swap_child(const size_t &i); //swaps parent downward
    size_t parent_index(const size_t& i) const; //returns parent id. returns i if no parent
    size_t right_i(const size_t& i) const; //returns the index of the right child index
    size_t left_i(const size_t& i) const;
    size_t bigger_child(const size_t& i) const; //returns bigger child
    bool is_leaf(const size_t& i) const; //returns if i node has no children

    //PRIVATE VARIABLES
    T* it_arr; //Dynamic array that holds all the items
    size_t how_many;
    size_t size_cap; //capacity of the array
    size_t height; //used to help allocate space appropriately by simulating the array as a tree
};

template<class T>
heap<T>::~heap(){
    delete[] it_arr;
}
template<class T>
heap<T>::heap(const heap<T>& h){
    this->how_many = h.size();
    this->size_cap = h.capacity();
    this->height = h.height;
    this->it_arr = get_new_arr(h.it_arr, h.capacity(), h.capacity());
}
template<class T>
heap<T>& heap<T>::operator =(const heap<T>& h){
    if(this != &h){
        this->how_many = h.size();
        this->size_cap = h.capacity();
        this->height = h.height;
        this->it_arr = get_new_arr(h.it_arr, h.capacity(), h.capacity());
    }
    return (*this);
}

template<class T>
void heap<T>::insert(const T& item){
    assert(how_many <= size_cap);
    if(how_many == size_cap){ //create a newly sized array!
        height++;
        size_t new_size = pow(2,height) - 1;
        T* temp       = new T[new_size];
        copy_arr(temp, it_arr, size_cap);
        delete[] it_arr;
        it_arr          = temp;
        size_cap        = new_size;
    }

    //Insert at the end of the "tree"
    it_arr[how_many] = item;
    how_many++;
    //Now swap it where necessary
    size_t my_i = (how_many - 1 >= 0)?(how_many - 1):(0);
    swap_parent(my_i);
}

template<class T>
T heap<T>::pop(){
    assert(!this->is_empty());
    T item = it_arr[0];

    size_t current_i = 0;
    //place it at the very end then deincrement the size to "delete" the popped item
    swap(it_arr[current_i], it_arr[this->size()-1]);
    how_many--;
    swap_child(current_i);

    return item;
}

template<class T>
void heap<T>::print() const{
    cout << "--Data--\n";
    cout << "how_many/capacity: " << how_many << "/" << size_cap << endl;
    cout << "- Array -\n";
    heap<T> popper(*this);
    while(popper.size())
        cout << popper.pop() << endl;
}

template<class T>
bool heap<T>::swap_parent(const size_t &i){
    int parent_i = parent_index(i); //parent_i == i if no parent
    if(parent_i == i)
        return false;
    else if(it_arr[i] > it_arr[parent_i]){
        swap(it_arr[i], it_arr[parent_i]);
        swap_parent(parent_i);
        return true;
    }else
        return false;
}

//
template<class T>
bool heap<T>::swap_child(const size_t& i){
    if(is_leaf(i))
        return false;
    int child = bigger_child(i);
    if(it_arr[i] < it_arr[child]){
        swap(it_arr[i], it_arr[child]);
        swap_child(child);
        return true;
    }else
        return false;
}

template<class T>
size_t heap<T>::parent_index(const size_t &i) const{
    return ((((int)i-1)/2 >= 0) ? ((size_t)((i-1)/2)) : (i));
}

template<class T>
size_t heap<T>::right_i(const size_t& i) const{
    return (2*i + 2);
}
template<class T>
size_t heap<T>::left_i(const size_t& i) const{
    return (2*i + 1);
}

template<class T>
bool heap<T>::is_empty() const{
    if(how_many == 0)
        return true;
    else
        return false;
}

template<class T>
bool heap<T>::is_leaf(const size_t &i) const{
    //check if node i left would be less than size
    if(left_i(i) < this->size()){
        return false;
    }else
        return true;
}

template<class T>
size_t heap<T>::bigger_child(const size_t& i) const{
    if(!is_leaf(i)){
        size_t left, right;
        left = left_i(i);
        right = right_i(i);
        if(right < size()){
            if(it_arr[right] > it_arr[left])
                return right;
            else
                return left;
        }else
            return left;
    }else
        return i;
}

template<class T>
size_t heap<T>::size() const{
    return how_many;
}

template<class T>
size_t heap<T>::capacity() const{
    return size_cap;
}

template<class T>
T heap<T>::top() const{
    return it_arr[0];
}

#endif // HEAP_H
