////
////  Draft.cpp
////  Connexion
////
////  Created by Jalel Benerrami on 27/02/2016.
////
////
//
#include <stdio.h>
#include <iostream>
using namespace std;
#include <ctime>

#include "Tools.h"
#include "Point2D.h"
#include "Simulation.h"



# include <Imagine/Graphics.h>
using namespace Imagine ;
//
//
//
//void aff(const vector<int> &v){
//    cout << "%%  ";
//    for(vector<int>::const_iterator it=v.begin(); it != v.end(); ++it){
//        cout << *it << "  ";
//    }
//    cout << endl;
//}
//
//int main(int argc, const char * argv[]) {
//
//vector<int> v(10);
//aff(v);
//for(int i=0;i<v.size();i++) v[i]=i+1;
//aff(v);
//vector<int> v2(v.begin(),v.end());
//aff(v2);
//vector<int> v3(v.begin()+2,v.end()-1);
//aff(v3);
//
//for(vector<int>::iterator it=v.begin(); it != v.end()+1; ++it){
//    vector<int> w(v.begin(),it);
//    aff(w);
//}
//
//
////// Beginning of the programm
////clock_t time1 = clock();
////
////srand(time(0));
////
////// Number of random points to place
////int numPoints = 1000;
////// Width and height of the display window
////int w=700 ,h=700;
////
////// Vector to store the random points
////vector <Point2D> points;
////// Initializing the random points list
////points.push_back(Point2D(random(w),random(h)));
////
////// Choose of a unique random color
////Color c = Color(random(256),random(256),random(256));
////
////// Opening the window and graphic instructions
////openWindow(w, h);
////
////for(int i=0; i<numPoints-1; i++){
////    // Create a random point
////    float x = random(w);
////    float y = random(h);
////    Point2D P = Point2D(x,y);
////    // Find his nearest neighbour in the list
////    int nN = P.nearestNeighbour(points);
////    /* c = Color(random(256),random(256),random(256)); // To change color for each line */
////    // Connect the random point to his nearest neighbour
////    P.connect(points[nN],c);
////    // Add the random point the list
////    P.addPoint2D(points);
////}
////
////
////
/////*
//// Printing list of points in order of apparition
//// 
//// for(vector<Point2D>::iterator it = points.begin(); it != points.end(); ++it){
//// cout << *it << endl;
//// }
//// */
////
////
////// End of the programm
////clock_t time2 = clock();
////
////cout << "Number of random points : " << numPoints << endl;
////cout << "Programm executed in : "
////<< ((float)(time2-time1)/CLOCKS_PER_SEC) << " seconds." << endl;
////
////openWindow(w,h);
////
////for(int i=0; i<numPoints-1; i++){
////    
////}
////
////
////// Click on the window to close it
////endGraphics();
//
//
//    return 0;
//}


//else{
//    // Create the set of uncovered points
//    vector<Point2D> coveredPoints;
//    // Create the set of covered points
//    vector<Point2D> uncoveredPoints(points.begin(),points.end());
//    
//    // Choose at random a first point in the list
//    float f = random(this->number());
//    Point2D first = points[f];
//    // Put the first point in the covered points set and delete it from the uncovered points set
//    coveredPoints.push_back(first);
//    uncoveredPoints.erase(uncoveredPoints.begin()+f);
//    
//    // Find the uncovered point nearest to the covered points set
//    // as long as there are uncovered points
//    while(!uncoveredPoints.empty()){
//        
//        // Choose the first covered point to begin the comparisons
//        vector<Point2D>::iterator origin = coveredPoints.begin();
//        int nN = origin->nearestNeighbour(uncoveredPoints);
//        Point2D destination = uncoveredPoints[nN];
//        float d = origin->distance(destination);
//        
//        // Determine the nearest uncovered point and its nearest covered neighbour
//        for(vector<Point2D>::iterator it = coveredPoints.begin(); it != coveredPoints.end(); ++it){
//            if(d > it->distance(uncoveredPoints[it->nearestNeighbour(uncoveredPoints)])){
//                origin = it;
//                nN = origin->nearestNeighbour(uncoveredPoints);
//                destination = uncoveredPoints[nN];
//                d = it->distance(destination);
//            }
//            
//            // Connect to nearest uncovered point to its nearest covered neighbour
//            /* c = Color(random(256),random(256),random(256)); // To change color for each line */
//            origin->connect(destination,c);
//            // Put the nearest uncovered point in the covered points set ...
//            coveredPoints.push_back(destination);
//            // ... and delete it from the uncovered points set
//            uncoveredPoints.erase(uncoveredPoints.begin()+nN);
//        }
//    }
//}


//int main(){
//    
//    vector<Point2D> v;
//    set<Point2D> s;
//    display(v);
//    display(s);
//    cout << endl;
//    
//    int n = 2;
//    for(int i=0; i<n; i++){
//        Point2D P = Point2D(i, i);
//        v.push_back(P);
//        s.insert(P);
//    }
//    display(v);
//    display(s);
//    cout << endl;
//    
//    v.push_back(Point2D(n-1,n-1));
//    s.insert(Point2D(n-1,n-1));
//    display(v);
//    display(s);
//    cout << endl;
//    
//    v.push_back(Point2D(n+10,0));
//    s.insert(Point2D(n+10,0));
//    display(v);
//    display(s);
//    cout << endl;
//    
//    v.push_back(Point2D(n+3,-n));
//    s.insert(Point2D(n+3,-n));
//    display(v);
//    display(s);
//    cout << endl;
//    
//    v.push_back(Point2D(-n,n));
//    s.insert(Point2D(-n,n));
//    display(v);
//    display(s);
//    cout << endl;
//    
//    v.push_back(Point2D(0,0));
//    s.insert(Point2D(0,0));
//    display(v);
//    display(s);
//    cout << endl;
//    
//    return 0;
//}





























