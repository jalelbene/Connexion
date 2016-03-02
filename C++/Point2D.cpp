//
//  Point.cpp
//  Connexion
//
//  Created by Jalel Benerrami on 26/02/2016.
//  Copyright © 2016 Jalel Benerrami. All rights reserved.
//

#include "Point2D.h"
using std::ostream;
#include <math.h>    /* sqrt */




//
//Define a order between two Point2D
//
bool Point2D::operator<(const Point2D &pt) const {
    return _x < pt.x() || (_x == pt.x() && _y < pt.y());
}

//
// Calculate the Euclidian distance between two points
//
float Point2D::distance(const Point2D &pt) const {
    return sqrt(powf(_x-pt.x(),2) + powf(_y-pt.y(),2));
}

//
// Draw a line between two points
//
void Point2D::connect(const Point2D &pt, const Color &c) const {
    drawLine(_x,_y,pt.x(),pt.y(),c);
}

//
// Add a point to an existing list of points
//
void Point2D::addPoint2D(vector<Point2D> &v) const {
    v.push_back(*this);
}

//
// Determine the nearest neighbourg of a point among the ones in a vector
//
int Point2D::nearestNeighbour(const vector <Point2D> &v) const {
    int nN=0;
    for(vector<Point2D>::const_iterator it = v.begin(); it != v.end(); ++it){
        if(this->distance(v[nN]) > this->distance(*it)){
            nN = it - v.begin();
        }
    }
    return nN;
}

//
// Determine the nearest neighbourg of a point among the ones in a set
//
Point2D Point2D::nearestNeighbour(const set <Point2D> &s) const{
    Point2D nN = *(s.begin());
    for(set<Point2D>::const_iterator it = s.begin(); it != s.end(); ++it){
        if(this->distance(nN) > this->distance(*it)){
            nN = *it;
        }
    }
    return nN;
}

//
// Multiply or divide a point coordonnates by the same floating value
//
Point2D Point2D::homothety(const float &k, const float &l)const{
    return Point2D(_x/k,_y/l);
}

//
// Set the color
//
void Point2D::colorIn(const Color &c){
    _c = c;
}


//
// Display 2D point
//
ostream &operator<<(ostream &os, Point2D const &pt) {
    return os << "(" << pt.x() << "," << pt.y() << ")";
}
ostream &operator<<(ostream &os, Point2D* const &p) {
    return os << *p;
}