import matplotlib.pyplot as plt
import matplotlib.cm 
from mpl_toolkits.basemap import Basemap
from matplotlib.patches import Polygon
from matplotlib.collections import PatchCollection
from matplotlib.colors import Normalize
import numpy as np
import csv
from operator import itemgetter
import io
def frange(start, stop, step):
    x = start
    while x < stop:
            yield x
            x += step
m = Basemap(width=12000000,height=8000000,
            resolution='l',projection='stere',\
            lat_ts=-10,lat_0=-10,lon_0=-70)
m.drawcoastlines()
m.fillcontinents(color='coral',lake_color='aqua')
m.drawmapboundary(fill_color='aqua')
delta=0.5
x=[]
y=[]
for i in frange(-80,-29.5,delta):
    x.append(float(i))
for j in frange(-40,10.5,delta):
    y.append(float(j))
a,b= np.meshgrid(x, y)
with open("Declinacao_certo.txt", "r") as ins:
    z = []
    for line in ins:
        z.append(float(line))
print(len(a))
CS = m.contour(a,b,z)
plt.save("mapa_decl")
plt.show()
