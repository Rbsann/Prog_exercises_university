import matplotlib.pyplot as plt
import numpy as np
results = []
with open("sismos_com_data.txt") as inputfile:
    for line in inputfile:
        results.append(list(map(float, line.split())))
Magnitude=[]
E04=[]
E64=[]
Diferenca=[]
for i in range(len(results)):
    E04.append((1.5*results[i][3])+4.8)
    E64.append((1.44*results[i][3])+5.24)
    Diferenca.append(abs(E04[i]-E64[i]))
    Magnitude.append(results[i][3])
#plt.gca().set_position((.1,.3,.8,.6))    
#plt.scatter(Magnitude,E04,c='y',s=2,norm=True)
plt.scatter(Magnitude,Diferenca,c='b',s=2)
#plt.figtext(.02,.02,"Amarelo dado de 2004, Azul dado de 1974")
#plt.vlines(x=Magnitude,ymin=E04,ymax=E64,linestyles='dashdot')
#plt.plot(Diferenca)
plt.title("Magnitude-Diferenca_Energia")
plt.xlabel("Magnitude")
plt.ylabel("Diferenca_energia (Joules)")
