//
//  heap.hpp
//  Connexion
//
//  Created by Jalel Benerrami on 24/04/2016.
//
//


#ifndef heap_h
#define heap_h

#include <stdio.h>
#include <vector>
#include <string>
using namespace std;


/*
 Heap using an array
 Enables us to represent binary trees without pointers:
 - Left child sits at 2n
 - Right child sits at 2n + 1
 - Parent sits at floor(n/2)
 */

class Heap {
    std::vector<int> _queue;
    unsigned int _size;
    
    // Called by insert()
    // If the parent's value is greater than current
    //  the current item bubbles up till we reach root
    void bubbleUp (int idx);
    // Called by delete()
    // If the current is greater than children
    //  the current item bubbles down till no more children
    void bubbleDown(int idx);
    // Used by bubbleDown()
    //  Get the index of the min value
    //  between 3 given indices to the heap array.
    int getMinIdx(int aIdx, int bIdx, int cIdx);
    
public:
    Heap();
    ~Heap() {};
    bool empty() const;
    int size() const;
    void clear();
    int getItem(unsigned int idx) const;
    int parent(unsigned int idx) const;
    int son(unsigned int idx) const;
    int find(unsigned int idx, const int &val) const;
    void insert(const int &val);
    void remove(int val);
    void makeHeap(int array[], int size);
    void makeHeap(std::vector<int> &input);
    int extractMin(); //Removes and returns min value
    vector<int>  heapSort  (); //O(n log n)
    string toString() const;
};


#endif /* heap_h */
