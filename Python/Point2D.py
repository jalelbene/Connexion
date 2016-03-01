#!/usr/bin/python3

  # Point2D
  # Connexion

  # Created by Jalel Benerrami on 29/02/2016.
  # Copyright © 2016 Jalel Benerrami. All rights reserved.


import numpy as np
import matplotlib.pyplot as plt
import math

#
# A 2D point given by (x,y) coordinates

class Point2D :
    #
    # Create a new 2D point with given coordinates
    def __init__(self, x0, y0):
        self._x = x0
        self._y = y0
    #
    # Get coordinates
    def x(self):
        return self._x
    def y(self):
        return self._y
    #
    # Display a 2D point
    def __repr__(self):
        return "({},{})".format(self._x, self._y)
    def print(self):
        print(self)
    #
    # Calculate the Euclidian distance between two points
    def distance(self, pt):
        return math.sqrt((self.x()-pt.x())**2 + (self.y()-pt.y())**2)
    #
    # Draw a line between two points
    def connect(self, pt):
        abs = np.array([self.x(), pt.x()])
        ord = np.array([self.y(), pt.y()])
        plt.plot(abs, ord, "b-")
        # plt.plot(abs, ord, "bo-") to mark the points with symbol o
    #
    # Determine the nearest neighbourg of a point among the ones in a vector
    def nearestNeighbour(self, listPoints):
        nN = listPoints[0]
        for pt in listPoints:
            if(self.distance(pt) < self.distance(nN)):
                nN = pt
        return nN
    #
    # # Add a point to an existing list of points
    # def addPoint2D(self, listPoints):
    #     listPoints.append(self)
    


