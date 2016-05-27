//
//  heap.hpp
//  Connexion
//
//  Created by Jalel Benerrami on 24/04/2016.
//
//


#ifndef heap_T_h
#define heap_T_h

#include <stdio.h>
#include <vector>
#include <string>
#include <iostream>
#include <iterator>
#include <algorithm>
#include <sstream> //stringstream
using namespace std;
#include "Point2D.h"


/*
 Heap using an array
 Enables us to represent binary trees without pointers:
 - Left child sits at 2n
 - Right child sits at 2n + 1
 - Parent sits at floor(n/2)
 */

template <typename T>
class Heap {
    std::vector<T> _queue;
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
    T getItem(unsigned int idx) const;
    int parent(unsigned int idx) const;
    int son(unsigned int idx) const;
    int find(unsigned int idx, const T &val) const;
    void insert(const T &val);
    void remove(T val);
    void makeHeap(T array[], int size);
    void makeHeap(vector<T> &input);
    T extractMin(); //Removes and returns min value
    vector<T>  heapSort(); //O(n log n)
    string toString() const;
};


template <typename T>
typedef vector<T>::iterator vecIter;
typedef vector<T>::const_iterator vecCiter;


//
void Heap<T>::bubbleUp(int idx) { //O(log n)
    int parentIdx = parent(idx);
    if (parentIdx == -1) return; //base case: root of heap
    
    if (_queue[parentIdx] > _queue[idx]) {
        swap(_queue[parentIdx], _queue[idx]);
        bubbleUp(parentIdx);
    }
}


void Heap<T>::bubbleDown(int idx) { //O(log n)
    int sonIdx = son(idx);
    if (sonIdx == -1) return; //base case: no children left
    int minIdx = getMinIdx(idx, sonIdx, sonIdx + 1);
    
    if (minIdx != idx) {
        swap(_queue[minIdx], _queue[idx]);
        bubbleDown(minIdx);
    }
}

// @Precondition: index aIdx and bIdx exist in the array
int Heap<T>::getMinIdx(int aIdx, int bIdx, int cIdx) {
    bool LeftSmaller = (_queue[aIdx] < _queue[bIdx]);
    
    if (cIdx > (int) _size) { //the last right child doesnt exist
        return LeftSmaller ? aIdx : bIdx;
    } else if (LeftSmaller) {
        return (_queue[aIdx] < _queue[cIdx]) ? aIdx : cIdx;
    } else {
        return (_queue[bIdx] < _queue[cIdx]) ? bIdx : cIdx;
    }
}


// Add a dud first elem
Heap<T>::Heap() : _queue(Point2D(0,0)), _size(0) {}

// Determine if the heap is empty or not
bool Heap<T>::empty() const {
    return (_size == 0);
}

int Heap<T>::size() const {
    return _size;
}

void Heap<T>::clear() {
    _queue.clear();
    _queue.push_back(Point2D(0,0)); //first item is a dud
}

template <typename T>
T Heap<T>::getItem(unsigned int idx) const {
    return _queue[idx];
}


int Heap<T>::parent(unsigned int idx) const {
    if (_size <= 1) return -1; //empty or root has no parent
    return ((int) idx / 2); //floor (idx/2)
}

int Heap<T>::son(unsigned int idx) const {
    if (_size <= 1 || 2 * idx > _size ) return -1; //empty or only root or a vertex idx has no son
    return (2 * idx);
}

template <typename T>
int Heap<T>::find(unsigned int idx, const T &val) const { //O(log n)
    if (idx > _size) return -1; //base case: idx out of bounds
    if (val < _queue[idx]) return -1;   //base case: val not in min-heap
    if (_queue[idx] == val) return idx; //Found the val, return its index
    
    int sonIdx = son(idx), i = -1;
    
    if (sonIdx != -1) { //find in left and right children
        i = max(find(sonIdx, val), find(sonIdx + 1, val));
    }
    return i;
}


template <typename T>
void Heap<T>::insert(const T &val) {
    _queue.push_back(val);
    _size++;
    bubbleUp(_size);
}


template <typename T>
void Heap<T>::remove(T val) { //O(2 * log n)
    int idx = find(1, val);
    if (idx == -1) return;
    
    _queue[idx] = _queue[_size--]; // swap current with last item
    _queue.resize(_size + 1); //idx 0 is a dud item
    bubbleDown(idx);
    bubbleUp(idx);
}


template <typename T>
T Heap<T>::extractMin() { //Special case of remove: O(2 * log n)
    if (empty()) throw "Empty Heap!";
    
    T min = _queue[1];
    remove(min);
    return min;
}


template <typename T>
vector<T> Heap<T>::heapSort() { //O(n log n)
    vector<int> sortedItems;
    sortedItems.reserve(_size);
    while(!empty()) {
        sortedItems.push_back(extractMin());
    }
    
    return sortedItems;
}



// Create the heap given an unsorted array
template <typename T>
void Heap<T>::makeHeap(T array[], int n) { //O(n log n)?
    _size = n;
    int i = 0;
    
    for (; i < n; i++) { // O(n)
        _queue.push_back(array[i]);
    }
    for (int i = n; i > 0; i--) {
        bubbleDown(i); //O(log n)
    }
}

// Create the heap given an unsorted vector
template <typename T>
void Heap<T>::makeHeap(vector<T> &input) { //O(n log n)?
    _size = input.size();
    vecCiter citer = input.begin();
    
    for (; citer != input.end(); citer++) { // O(n)
        _queue.push_back(*citer);
    }
    for (int i = _size; i > 0; i--) {
        bubbleDown(i); //O(log n)
    }
}


template <typename T>
string Heap<T>::toString() const {
    if (empty()) return "";
    
    ostringstream sstream;
    copy(_queue.begin() + 1, _queue.end() - 1, ostream_iterator<T>(sstream, " "));
    sstream << *(_queue.end() - 1);
    
    return sstream.str();
}

#endif /* heap_T_h */
