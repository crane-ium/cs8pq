#ifndef ARR_FUNC_H
#define ARR_FUNC_H
/* arr_func : ARRAY FUNCTIONS
 * Manipulate arrays to simulate a dynamic array
 * */

#include <stdlib.h>

//SIGNATURES/*
template<typename T>
T* get_new_arr(const T* arr, const size_t &arr_size, const size_t &new_size); //returns a copy of size new_size
template<typename T>
void copy_arr(T* &new_arr, const T* arr, const size_t &arr_size); //*/

//DECLARATIONS
template<typename T>
T* get_new_arr(const T* arr, const size_t &arr_size, const size_t &new_size){
    T* new_arr = new T[new_size];
    for(int i = 0; i < arr_size; i++)
        new_arr[i] = arr[i];
    return new_arr;
}

template<typename T>
void copy_arr(T* &new_arr, const T* arr, const size_t &arr_size){
    for(int i = 0; i < arr_size; i++)
        new_arr[i] = arr[i];
}

#endif // ARR_FUNC_H
