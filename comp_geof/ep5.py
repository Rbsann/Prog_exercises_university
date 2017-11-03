import matplotlib.pyplot as plt
import numpy as np
results = []
with open("sismos_com_data.txt") as inputfile:
    for line in inputfile:
        results.append(list(map(float, line.split())))
Anos = [] 
for i in range (len(results)): #Algoritmo pra converter data para Julian Date
     Anos.append(results[i][2]+1900)         
plt.hist(Anos,bins=100)
plt.title("Anos-Terremotos")
plt.xlabel("Ano")
plt.ylabel("Quantidade")
fig = plt.gcf()
counts = np.bincount(Anos)#Conta os valores das bins
ano_max=np.argmax(counts) #Acho o dia com mais terremotos
a = Anos.count(ano_max) #Conta a quantidade de terremotos desse dia
print(ano_max)
print(a)

