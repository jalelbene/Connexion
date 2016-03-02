#!/usr/bin/python3

  # Main
  # Connexion

  # Created by Jalel Benerrami on 29/02/2016.
  # Copyright © 2016 Jalel Benerrami. All rights reserved.
 
# from /Users/jalelbenerrami/Desktop/project_Python/Point2D import*
# from /Users/jalelbenerrami/Desktop/project_Python/Simulation import*

from Point2D import *
from Simulation import *

  #
  # Run programm by choosing parameters into the terminal
  #

# Number of random points
n = input("\nEnter the number of points you want to generate : ")
n = int(n)
print(n, "\n")    
    
# Choose a strategy
s = input("Choose a strategy : " )
s = int(s)
print(s, "\n")

# Create a simulation with given number of points
Sim = Simulation(n)
    
# Execute the created simulation
Sim.execute(s)
    
# Display the information about executed simulation
print(Sim, "\n")
    