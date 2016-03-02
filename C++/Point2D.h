//
//  Point2D.hpp
//  Connexion
//
//  Created by Jalel Benerrami on 26/02/2016.
//  Copyright © 2016 Jalel Benerrami. All rights reserved.
//

#ifndef Point2D_hpp
#define Point2D_hpp

#include <stdio.h>
#include <iostream>
using std::ostream;
using namespace std;
#include <vector>   /* vector */
#include <set>      /* set */

# include <Imagine/Graphics.h>   /* module Graphics */
using namespace Imagine ;



/*
 * A 2D point given by (x,y) coordinates
 */
class Point2D
{
    // Coordinates
    float _x, _y;
public:
    // Create a new 2D point with given coordinates
    Point2D(float x, float y) : _x(x), _y(y) {}
    // Get coordinates
    inline float x() const { return _x; }
    inline float y() const { return _y; }
    // Define a order between two Point2D
    bool operator<(const Point2D &pt) const;
    // Calculate the Euclidian distance between two points
    float distance(const Point2D &pt) const;
    // Draw a line between two points
    void connect(const Point2D &pt, const Color &c) const;
    // Determine the nearest neighbourg of a point among the ones in a vector
    int nearestNeighbour(const vector <Point2D> &v) const;
    // Determine the nearest neighbourg of a point among the ones in a set
    Point2D nearestNeighbour(const set <Point2D> &s) const;
    // Add a point to an existing list of points
    void addPoint2D(vector<Point2D> &v) const;
    // Multiply a point coordonnates by floating values
    Point2D homothety(const float &k, const float &l)const;
};

//
// Display 2D point
//
ostream &operator<<(ostream &os, Point2D const &pt);
ostream &operator<<(ostream &os, Point2D* const &p);


#endif /* Point2D_hpp */
