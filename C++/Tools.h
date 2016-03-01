//
//  Tools.hpp
//  Connexion
//
//  Created by Jalel Benerrami on 26/02/2016.
//  Copyright © 2016 Jalel Benerrami. All rights reserved.
//

#ifndef Tools_h
#define Tools_h

#include <iostream>
using namespace std;
#include <vector>
#include <set>
#include "Point2D.h"


//// Return uniformly a random floating value  between 0 and 1
//float randomUniform();
//
//// Return uniformly a random floating value  between a and b
//float random(const float &a, const float &b);
//
//// Return uniformly a random floating value  between 0 and a
//float random(const float &a);


// Return uniformly a random integer between 0 and a
int random(const int &a);

// Return uniformly a random integer between a and b
int random(const int &a, const int &b);

//// Display a vector of templates
//template<typename T>
//ostream &operator<<(ostream &os, vector<Point2D> const &v);
//template<typename T>
//ostream &operator<<(ostream &os, vector<Point2D*> const &v);
//
//// Display a set of templates
//template<typename T>
//ostream &operator<<(ostream &os, set<T> const &s);
//template<typename T>
//ostream &operator<<(ostream &os, set<T*> const &s);


// Display a vector of Point2D with its size
void display(const vector<Point2D> &v);
void display(const vector<Point2D*> &v);

// Display a set of Point2D with its size
void display(const set<Point2D> &s);
void display(const set<Point2D*> &s);


#endif /* Tools_h */
