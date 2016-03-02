#!/usr/bin/python3

  # Simulation
  # Connexion

  # Created by Jalel Benerrami on 29/02/2016.
  # Copyright © 2016 Jalel Benerrami. All rights reserved.

import numpy as np
import matplotlib.pyplot as plt
import math
import time
import random
from Point2D import *

#
# A simulation given by random points
#
class Simulation:
    #
    # Create a simulation with a given number of points to generate
    def __init__(self,n):  
        self.numberPoints = n
        self.listPoints = []
        self.strategy = 0
        self.runtime = 0
        self.cost = 0
    # Fill the list of points with random Point2D
        for i in range(n):
            x = np.random.uniform(0,1)
            y = np.random.uniform(0,1)
            (self.listPoints).append(Point2D(x,y))
    #
    # Get the number of generated points
    def number(self):
        return self.numberPoints
    #
    # Get the list of generated points 
    def list(self):
        return self.listPoints
    #
    # Set the strategy
    def setStrat(self,strat):
        self.strategy = strat
    #
    # Get the used strategy
    def getStrat(self):
        return self.strategy
    #
    # Set the execution time
    def setTime(self,t):
        self.runtime = t
    #
    # Get the execution time
    def getTime(self):
        return self.runtime
    #
    # Set the cost
    def setCost(self,c):
        self.cost = c
    #
    # Get the cost
    def getCost(self):
        return self.cost
    #
    # Display a simulation informations
    def __repr__(self):
        return """Simulation results :
            Generated points = {} 
            Strategy = {} 
            Cost : {} 
            Executed in : {} """.format(self.numberPoints, self.strategy, self.cost, self.runtime)           
    #
    def print(self):
        print(self)
    #
    # Execute a simulation
    def execute(self, str):
        # Beginning of the simulation
        time1 = time.clock()
        length = 0
        #
        # Start a figure with window limits (0,1)
        plt.figure()
        plt.xlim(0, 1)
        plt.ylim(0, 1)
        #
        # Waiting message
        print("  processing ... \n")
        #
        if(str == 1):
            # For every point in the list ...
            for pt in range(1,self.number()):
                # find its nearest neighbour among the previous ones...
                nN = (self.list()[pt]).nearestNeighbour(self.list()[:pt])
                # ... and connect it
                self.list()[pt].connect(nN)
                # Add the just made connexion 's length to the total length
                length += self.list()[pt].distance(nN)
        #
        else:
            # Define covered and uncovered points sets
            coveredPoints = []
            uncoveredPoints = self.list()[:]
            # Choose a random point in the list ...
            first = np.random.randint(self.number())
            # ... add it as the first covered one ...
            coveredPoints.append(uncoveredPoints[first])
            # ... and erase it from the uncovered points set
            del uncoveredPoints[first]
        #
            # While there are uncovered points
            while(len(uncoveredPoints) != 0):
                # Choose the first point in coveredPoints
                id = 0
                origin = coveredPoints[id]
                destination = origin.nearestNeighbour(uncoveredPoints)
                d = origin.distance(destination)
                #
                # For all other points after the first one ...
                for pt in range(1,len(coveredPoints)):
                    P = coveredPoints[pt]
                    nN = P.nearestNeighbour(uncoveredPoints)
                    # ... compare the distance bewteen points and their nearest neighbour
                    if(d > P.distance(nN)):
                        id = pt
                        origin = P
                        destination = nN
                        d = origin.distance(destination)
            #                
                # Connect to nearest uncovered point to its nearest covered neighbour
                origin.connect(destination)
                # Add the just made connexion's length to the total length
                length += origin.distance(destination)
                # Put the nearest uncovered point in the covered points set ...
                coveredPoints.append(destination)
                # ... and delete it from the uncovered points set
                uncoveredPoints.remove(destination)
        #
        # Save the used strategy
        self.setStrat(str)
        #
        # Save the total length
        self.setCost(length)
        #
        #Display the graphics
        plt.show()
        #
        # End of the simulation
        time2 = time.clock()
        #
        #Save execution time
        self.setTime(time2-time1)
        #print(time2-time1)

