from matplotlib import pyplot
from mpl_toolkits.mplot3d import Axes3D
import random
import sys

fig = pyplot.figure()
ax = Axes3D(fig)

x = []
y = []
z = []

with open(sys.argv[1]) as f:
    lines = f.readlines()
    for line in lines:
        a, b, c, _ = line.split(' ')
        x.append(float(a))
        y.append(float(b))
        z.append(float(c))


ax.scatter(x, y, z)
pyplot.show()