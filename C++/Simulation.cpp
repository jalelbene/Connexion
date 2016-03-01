//
//  Simulation.cpp
//  Connexion
//
//  Created by Jalel Benerrami on 26/02/2016.
//  Copyright © 2016 Jalel Benerrami. All rights reserved.
//

#include "Simulation.h"
#include "Tools.h"
#include <ctime>     /* time(0), clock() */


// Create a simulation with a given number of points to generate, and the limit values w and h
Simulation::Simulation(const int &n, const int &x, const int &y){
    numberPoints = n;
    xLimit = x;
    yLimit = y;
    for(int i=0; i<numberPoints; i++){
        points.push_back(Point2D(random(xLimit),random(yLimit)));
    }
}

// Get the number of points generated
int Simulation::number()const{
    return numberPoints;
}


// Get the limit of X axis
int Simulation::xLim()const{
    return xLimit;
}

// Get the limit Y axis
int Simulation::yLim()const{
    return yLimit;
}


// Save the used strategy
void Simulation::saveStrategy(const int &str){
    strat = str;
}


// Get the used strategy
int Simulation::strategy()const{
    return strat;
}


// Save the execution time
void Simulation::saveTime(const float &t){
    timeExecution = t;
}

// Get the execution time
float Simulation::runtime()const{
    return timeExecution;
}


// Save the cost
void Simulation::saveCost(const float &c){
    costLength = c;
}

// Get the cost
float Simulation::cost()const{
    return costLength;
}


// Execute the simulation in a window of size w*h
void Simulation::execute(const int &strategy){
    
    // Beginning of the simulation
    clock_t time1 = clock();
    
    // Choose of a unique random color
    Color c = Color(random(256),random(256),random(256));
    // or a unique set color with c in {BLACK, WHITE, RED, GREEN, BLUE, CYAN, MAGENTA, YELLOW}
    
//    srand(time(0));
    
    // Opening the window and graphic instructions
    openWindow(this->xLim(), this->yLim());
    
    if(strategy == 1){
        
        for(vector<Point2D>::iterator it=points.begin()+1; it != points.end()+1; ++it){
            // Find the nearest neighbour of the nth point among the (n-1)th firts ones
            vector<Point2D> previous(points.begin(), it);
            int nN = it->nearestNeighbour(previous);
            /* c = Color(random(256),random(256),random(256)); // To change color for each line */
            // Connect the random point to his nearest neighbour
            it->connect(points[nN],c);
            }
    }
    
    else{
        // Create the set of uncovered points
        set<Point2D> coveredPoints;
        
        // Create the set of covered points
        set<Point2D> uncoveredPoints(points.begin(),points.end());
        
//        //Verification in debbug mode
//        display(coveredPoints);
//        display(uncoveredPoints);
        
        // Choose at random a first point in the list
        Point2D first = points[random(this->number())];
        
        // Put the first point in the covered points set and delete it from the uncovered points set
        coveredPoints.insert(first);
        uncoveredPoints.erase(first);
        
//        //Verification in debbug mode
//        cout << first;
//        cout << first.nearestNeighbour(uncoveredPoints);
//        cout << " d = " << first.distance(first.nearestNeighbour(uncoveredPoints)) << endl;
//        cout << endl;
        
        // Find the uncovered point nearest to the covered points set
        // as long as there are uncovered points
        while(!uncoveredPoints.empty()){
            
//            // Verification in debbug mode
//            display(coveredPoints);
//            cout << *(coveredPoints.begin()); cout << endl;
//            display(uncoveredPoints); cout << endl;
            
            // Choose the first covered point to begin the comparisons
            set<Point2D>::iterator origin = coveredPoints.begin();
            Point2D destination = origin->nearestNeighbour(uncoveredPoints);
            float d = origin->distance(destination);
            
//            // Verification in debbug mode
//            cout << "origin = " << *origin
//                 << " destination = " << destination
//                 << " d = " << d << endl;
            
            // Determine the nearest uncovered point and its nearest covered neighbour
            for(set<Point2D>::iterator it = ++coveredPoints.begin(); it != coveredPoints.end(); ++it){
                
//                // Verification in debbug mode
//                cout << *it;
//                cout <<" d = "<< d <<" <> "<< it->distance(it->nearestNeighbour(uncoveredPoints)) << endl;
                
                if(d > it->distance(it->nearestNeighbour(uncoveredPoints))){
                    origin = it;
                    destination = origin->nearestNeighbour(uncoveredPoints);
                    d = origin->distance(destination);
                }
            }
            
//            // Verification in debbug mode
//            cout << " origin = " << *origin
//                 << " destination = " << destination
//                 << "d = " << d << endl;
//            cout << endl;
            
            // Connect to nearest uncovered point to its nearest covered neighbour
            /* c = Color(random(256),random(256),random(256)); // To change color for each line */
            origin->connect(destination,c);
            // Put the nearest uncovered point in the covered points set ...
            coveredPoints.insert(destination);
            // ... and delete it from the uncovered points set
            uncoveredPoints.erase(destination);
            
        }
    }

    
    // Save the strategy
    this->saveStrategy(strategy);
    
    // End of the simulation
    clock_t time2 = clock();
    
    // Save execution time
    this->saveTime((float)(time2-time1)/CLOCKS_PER_SEC);
}


//
// Display simulation informations
//
ostream &operator<<(ostream &os, Simulation const &sim) {
    return os << "Simulation informations : \n"
              << "  Generated points : " << sim.number() << "\n"
              << "  Window's width : " << sim.xLim() << "\n"
              << "  Window's height : " << sim.yLim() << "\n"
              << "  Strategy : " << sim.strategy() << "\n"
              << "  Executed in : " << sim.runtime() << " seconds"
              << endl;
}
ostream &operator<<(ostream &os, Simulation* const &sim) {
    return os << *sim;
}