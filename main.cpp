#include <iostream>
#include <random>
#include <time.h>
#include "heap.h"
#include "arr_func.h"
#include "priority_queue.h"

using namespace std;

int randint(int min, int max);

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
    pqueue<int> pq;
    pq.insert(1, 0);
    pq.insert(2, 10);
    pq.insert(3,-5);
    pq.insert(4,15);
    pq.insert(5,5);
    pq.print();
    while(!pq.is_empty())
        cout << pq.pop() << endl;
    //--- RANDOM INSERTION ---
    cout << "Random insertion: \n";
    for(int i; i < 100; i++)
        pq.insert(randint(1,1000), randint(1,10));
    int count = 0;
    while(!pq.is_empty())
        cout << setw(4) <<left<< (count++)<< ": "\
             <<right<< pq.pop() << endl;
    cout << "Show get operations: \n";
    pq.insert(99, 10);
    cout << "Item: " << pq.top().get_item() \
         << " Priority: " << pq.top().get_priority() << endl;
    return 0;
}

int randint(int min, int max){
    assert(max > 0);
    static bool set_srand = false;
    if(!set_srand){
        srand(time(NULL));
        set_srand = true;
    }
    return rand() % (max- min + 1) + min;
}
