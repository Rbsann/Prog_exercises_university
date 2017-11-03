import matplotlib.pyplot as plt
import numpy as np
results = []
with open("sismos_com_data.txt") as inputfile:
    for line in inputfile:
        results.append(list(map(float, line.split())))
Anos = [] 
Anos_certos=list(xrange(1900,1999))
Energia_temp=0
Energia=[]
for i in range (len(results)): #Algoritmo pra converter data para Julian Date
     Anos.append(results[i][2]+1900)
for i in range(len(results)):
    results[i][3]=10**((1.5*results[i][3])+4.8) 
for i in range(len(Anos)-1):
    if(Anos[i]==Anos[i+1]):
        Energia_temp+=results[i][3]
    else:
        Energia.append(Energia_temp)
        Energia_temp=0
plt.plot(Anos_certos,Energia)
plt.title("Ano-Energia")
plt.xlabel("Ano")
plt.ylabel("Energia")
counts = np.bincount(Anos)#Conta os valores das bins
ano_max=np.argmax(counts) #Acho o dia com mais terremotos
a = Anos.count(ano_max) #Conta a quantidade de terremotos desse dia
print(ano_max)
print(a)

