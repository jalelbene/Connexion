P=Point2D(1,6)
Q=Point2D(1,9)
P.distance(Q)


P=Point2D(0,0)
Q=Point2D(1,1)
R=Point2D(2,1/2)


n=3
list = []
for i in range(n):
    x = np.random.uniform(0,1)
    y = np.random.uniform(0,1)
    list.append(Point2D(x,y))


x = np.random.uniform(0,1)
y = np.random.uniform(0,1)
W=Point2D(x,y)


Sim = Simulation(5)
Sim.number()
Sim.list()
Sim.setStrat(1)
Sim.getStrat()
Sim


plt.figure()
for pt in range(1,Sim.number()):
    nN = Sim.list()[pt].nearestNeighbour(Sim.list()[:pt])
    abs = np.array([Sim.list()[pt].x(), nN.x()])
    ord = np.array([Sim.list()[pt].y(), nN.y()])
    plt.plot(abs, ord)
    plt.show()

Sim = Simulation(30)

plt.figure()
for pt in range(1,Sim.number()):
    nN = Sim.list()[pt].nearestNeighbour(Sim.list()[:pt])
    Sim.list()[pt].connect(nN)

plt.show()




Sim = Simulation(30)

plt.figure()
coveredPoints = []
uncoveredPoints = Sim.list()[:]
first = np.random.randint(Sim.number())
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

plt.show()
