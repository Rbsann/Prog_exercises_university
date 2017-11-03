import matplotlib.pyplot as plt
import numpy as np
results = []
with open("sismos_com_data.txt") as inputfile:
    for line in inputfile:
        results.append(list(map(float, line.split())))
Julian_date = [] 
for i in range (len(results)): #Algoritmo pra converter data para Julian Date
     if (results[i][0]<3): #Com um adendo, eu normalizo o valor da data juliana, sabendo
        y=(results[i][2]+1900)-1 #Que o primeiro dia juliano do txt eh 2415024
     else:
        y=results[i][2]+1900
     if (results[i][0]<3):
        m=results[i][0]+13
     else:
        m=results[i][0]+1
     Julian_date.append((int(365.25*y)+int(30.6001*m)+results[i][1]+1720982)-2415024)         
plt.hist(Julian_date,bins='fd',histtype='barstacked')
plt.title("Dias Julianos-Terremotos")
plt.xlabel("Dia")
plt.ylabel("Quantidade")
fig = plt.gcf()
fig.subplots_adjust(bottom=0.2)
ax = fig.add_subplot(111)
counts = np.bincount(Julian_date)#Conta os valores das bins
dia_max=np.argmax(counts) #Acho o dia com mais terremotos
a = Julian_date.count(dia_max) #Conta a quantidade de terremotos desse dia
print(dia_max)
print(a)

