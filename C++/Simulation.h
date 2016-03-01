//
//  Simulation.hpp
//  Connexion
//
//  Created by Jalel Benerrami on 26/02/2016.
//  Copyright © 2016 Jalel Benerrami. All rights reserved.
//

#ifndef Simulation_hpp
#define Simulation_hpp

#include "Point2D.h"



/*
 * A simulation given by random points
 */
class Simulation{
    // Number of points generated
    int numberPoints;
    // Abscissas between 0 and xLimit
    int xLimit;
    // Ordinates between 0 and yLimit
    int yLimit;
    // Vector to store the random generated points
    vector <Point2D> points;
    // Strategy used in {0,1}
    int strat;
    // Time of execution
    float timeExecution;
    // total length of drawn lines
    float costLength;
public:
    // Create a simulation with a given number of points to generate
    Simulation(const int &n, const int &w, const int &h);
    // Get the number of points generated
    int number() const;
    // Get the abcissas limit
    int xLim() const;
    // Get the ordinates limit
    int yLim() const;
    // Save the used strategy
    void saveStrategy(const int &str);
    // Get the used strategy
    int strategy() const;
    // Save the execution time
    void saveTime(const float &time);
    // Get the execution time
    float runtime() const;
    // Save the cost
    void saveCost(const float &c);
    // Get the cost
    float cost() const;
    // Execute a simulation
    void execute(const int &strategy);
};


//
// Display simulation information
//
ostream &operator<<(ostream &os, Simulation const &sim);
ostream &operator<<(ostream &os, Simulation* const &sim);


#endif /* Simulation_hpp */
