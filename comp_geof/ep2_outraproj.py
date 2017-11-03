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
results = []
with open("sismos_com_data.txt") as inputfile:
    for line in inputfile:
        results.append(list(map(float, line.split())))
results2=sorted(results, key=itemgetter(3),reverse=True)
#for i in range(10):
 #   print(results2[i])
m = Basemap(projection='robin', resolution = 'l', area_thresh = 1000.0,
              lat_0=0, lon_0=-130)
m.drawcoastlines()
m.drawcountries()
#map.fillcontinents(color = 'gray')
m.bluemarble()
m.drawmapboundary()
m.drawmeridians(np.arange(0, 360, 30))
m.drawparallels(np.arange(-90, 90, 30))
#def column(matrix, i):
 #   return [row[i] for row in matrix]
#lons=column(results2,5)
#lons1=lons[0:51]
#lats=column(results2,6)
#lats1=lats[0:51]
for i in range (51):
    lons=results2[i][5]
    lats=results2[i][6]
    x,y=m(lons,lats)
    m.plot(x,y,'go',markersize=6)
plt.title("Maiores_terremotos")
plt.show()