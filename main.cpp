#include <iostream>
#include "heap.h"
#include "arr_func.h"

using namespace std;

int main()
{
    int* arr = new int[3];
    arr[0] = 1;
    arr[1] = 2;
    arr[2] = 3;
    for(int i=0; i < 3; i++)
        cout << arr[i] << endl;
    cout << "NEXT!\n";

    int* new_arr = get_new_arr(arr, 3, 10);
    new_arr[3] = 4;
    new_arr[4] = 5;
    for(int i = 0; i < 5; i++)
        cout << new_arr[i] << endl;

    int size = 20;
    int capacity = 0;
    int* newer_arr = new int[size];
    for(int i = 0; i < size; i++){
        if(i <= capacity){
            newer_arr[i] = i;
            capacity++;
        }
    }

    int* newest_arr = new int[size];
    copy_arr(newest_arr, newer_arr, size);
    cout << "Newest arr: " << endl;
    for(int i = 0; i < size; i++)
        cout << newest_arr[i] << endl;

    heap<int> heap_int;
    heap_int.insert(1);
    heap_int.insert(2);
    heap_int.insert(3);
    heap_int.insert(4);
    heap_int.insert(5);
    heap_int.insert(10);
    heap_int.insert(25);
    heap_int.insert(15);
    heap_int.insert(10);
    heap_int.insert(15);
    heap_int.insert(30);
    heap_int.print();
    cout << "Popping\n";
    while(heap_int.size() > 4)
        cout << heap_int.pop() << endl;
    heap_int.insert(3);
    heap_int.insert(20);
    heap_int.insert(10);
    cout << "Pop2\n";
    while(!heap_int.is_empty())
        cout << heap_int.pop() << endl;
    heap_int.insert(10);
    heap_int.insert(20);
    heap_int.insert(15);
    heap_int.insert(3);
    cout << "Round 3\n";
    heap_int.print();
    cout << "GO!\n";
    while(!heap_int.is_empty())
        cout << heap_int.pop() << endl;
    return 0;
}
