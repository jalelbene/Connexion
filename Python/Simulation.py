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
    # Display a simulation informations
    def __repr__(self):
        return "Simulation informations : Generated points = {} // Strategy = {} // Executed in : {}".format(self.numberPoints, self.strategy, self.runtime)
    #
    def print(self):
        print(self)
    #
    # Execute a simulation
    def execute(self, str):
        # Beginning of the simulation
        time1 = time.clock()
        #
        plt.figure()
        plt.xlim(0, 1)
        plt.ylim(0, 1)
        #
        if(str == 1):
            for pt in range(1,self.number()):
                nN = (self.list()[pt]).nearestNeighbour(self.list()[:pt])
                self.list()[pt].connect(nN)
        #
        else:
            coveredPoints = []
            uncoveredPoints = self.list()[:]
            first = np.random.randint(self.number())
            coveredPoints.append(uncoveredPoints[first])
            del uncoveredPoints[first]
        #
            while(len(uncoveredPoints) != 0):
                id = 0
                origin = coveredPoints[id]
                destination = origin.nearestNeighbour(uncoveredPoints)
                d = origin.distance(destination)
                #
                for pt in range(1,len(coveredPoints)):
                    P = coveredPoints[pt]
                    nN = P.nearestNeighbour(uncoveredPoints)
                    if(d > P.distance(nN)):
                        id = pt
                        origin = P
                        destination = nN
                        d = origin.distance(destination)
            #                
                # Connect to nearest uncovered point to its nearest covered neighbour
                origin.connect(destination)
                # Put the nearest uncovered point in the covered points set ...
                coveredPoints.append(destination)
                # ... and delete it from the uncovered points set
                uncoveredPoints.remove(destination)
        #
        self.setStrat(str)
        #
        plt.show()
        #
        # End of the simulation
        time2 = time.clock()
        #
        #Save execution time
        self.setTime(time2-time1)
        #print(time2-time1)

