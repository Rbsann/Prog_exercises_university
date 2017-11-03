import matplotlib.pyplot as plt
import numpy as np
from pylab import *
Magnitude=[]
E04=[]
E64=[]
#Diferenca=[]
Magnitude=np.arange(0,10.1,0.1)
for i in range(len(Magnitude)):
    E04.append(((1.5*Magnitude[i])+4.8))
    E64.append(((1.44*Magnitude[i])+5.24))
    #Diferenca.append(abs(E04[i]-E64[i]))
plt.gca().set_position((.1,.3,.8,.6))    
plt.scatter(Magnitude,E04,c='y',s=2,norm=True)
plt.scatter(Magnitude,E64,c='b',s=2,norm=True)
plt.figtext(.02,.02,"Amarelo dado de 2004, Azul dado de 1974")
#plt.vlines(x=Magnitude,ymin=E04,ymax=E64,linestyles='dashdot')
#plt.plot(Diferenca)
plt.title("Magnitude-Diferenca_Energia")
plt.xlabel("Magnitude")
plt.ylabel("Diferenca_energia (Joules)")
