//
//  heap.cpp
//  Connexion
//
//  Created by Jalel Benerrami on 24/04/2016.
//
//

#include "heap.h"
#include <iostream>
#include <iterator>
#include <algorithm>
#include <sstream> //stringstream

typedef vector<int>::iterator vecIter;
typedef vector<int>::const_iterator vecCiter;


//
void Heap::bubbleUp(int idx) { //O(log n)
    int parentIdx = parent(idx);
    if (parentIdx == -1) return; //base case: root of heap
    
    if (_queue[parentIdx] > _queue[idx]) {
        swap(_queue[parentIdx], _queue[idx]);
        bubbleUp(parentIdx);
    }
}


void Heap::bubbleDown(int idx) { //O(log n)
    int sonIdx = son(idx);
    if (sonIdx == -1) return; //base case: no children left
    int minIdx = getMinIdx(idx, sonIdx, sonIdx + 1);
    
    if (minIdx != idx) {
        swap(_queue[minIdx], _queue[idx]);
        bubbleDown(minIdx);
    }
}

// @Precondition: index aIdx and bIdx exist in the array
int Heap::getMinIdx(int aIdx, int bIdx, int cIdx) {
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
Heap::Heap() : _queue(1,0), _size(0) {}

// Determine if the heap is empty or not
bool Heap::empty() const {
    return (_size == 0);
}

int Heap::size() const {
    return _size;
}

void Heap::clear() {
    _queue.clear();
    _queue.push_back(0); //first item is a dud
}

int Heap::getItem(unsigned int idx) const {
    return _queue[idx];
}

int Heap::parent(unsigned int idx) const {
    if (_size <= 1) return -1; //empty or root has no parent
    return ((int) idx / 2); //floor (idx/2)
}

int Heap::son(unsigned int idx) const {
    if (_size <= 1 || 2 * idx > _size ) return -1; //empty or only root or a vertex idx has no son
    return (2 * idx);
}

int Heap::find(unsigned int idx, const int &val) const { //O(log n)
    if (idx > _size) return -1; //base case: idx out of bounds
    if (val < _queue[idx]) return -1;   //base case: val not in min-heap
    if (_queue[idx] == val) return idx; //Found the val, return its index
    
    int sonIdx = son(idx), i = -1;
    
    if (sonIdx != -1) { //find in left and right children
        i = max(find(sonIdx, val), find(sonIdx + 1, val));
    }
    return i;
}


void Heap::insert(const int &val) {
    _queue.push_back(val);
    _size++;
    bubbleUp(_size);
}



void Heap::remove(int val) { //O(2 * log n)
    int idx = find(1, val);
    if (idx == -1) return;
    
    _queue[idx] = _queue[_size--]; // swap current with last item
    _queue.resize(_size + 1); //idx 0 is a dud item
    bubbleDown(idx);
    bubbleUp(idx);
}

int Heap::extractMin() { //Special case of remove: O(2 * log n)
    if (empty()) throw "Empty Heap!";
    
    int min = _queue[1];
    remove(min);
    return min;
}


vector<int> Heap::heapSort() { //O(n log n)
    vector<int> sortedItems;
    sortedItems.reserve(_size);
    while(!empty()) {
        sortedItems.push_back(extractMin());
    }
    
    return sortedItems;
}

// Create the heap given an unsorted array
void Heap::makeHeap(int array[], int n) { //O(n log n)?
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
void Heap::makeHeap(vector<int> &input) { //O(n log n)?
    _size = input.size();
    vecCiter citer = input.begin();
    
    for (; citer != input.end(); citer++) { // O(n)
        _queue.push_back(*citer);
    }
    for (int i = _size; i > 0; i--) {
        bubbleDown(i); //O(log n)
    }
}

string Heap::toString() const {
    if (empty()) return "";
    
    ostringstream sstream;
    copy(_queue.begin() + 1, _queue.end() - 1, ostream_iterator<int>(sstream, " "));
    sstream << *(_queue.end() - 1);
    
    return sstream.str();
}