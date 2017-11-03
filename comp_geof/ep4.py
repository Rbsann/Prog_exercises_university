import matplotlib.pyplot as plt
import numpy as np
results = []
with open("sismos_com_data.txt") as inputfile:
    for line in inputfile:
        results.append(list(map(float, line.split())))
Mes= [] 
for i in range (len(results)): #Algoritmo pra converter mes para mes corrido
    if (results[i][2]==0):
        Mes.append(results[i][0])
    else:           
        Mes.append(12+(results[i][0]*results[i][2]))         
plt.hist(Mes,bins=100)
plt.title("Meses-Terremotos")
plt.xlabel("Meses")
plt.ylabel("Quantidade")
fig = plt.gcf()
counts = np.bincount(Mes)#Conta os valores das bins
mes_max=np.argmax(counts) #Acho o dia com mais terremotos
a = Mes.count(mes_max) #Conta a quantidade de terremotos desse mes
print(mes_max)
print(a)


