#.n Renan Bueno Sanches
#.u 8962102

import random
import matplotlib.pyplot as plt
import numpy as np

def transformacaoEscala(U, V, n, a, b): #Funcao realizada exatamente de acordo com a especificacao do enunciado do EP3
    i=0
    while i<n:
        V[i]=a+U[i]*(b-a+1)
        i+=1
    plt.hist(V) #Tendo em vista que o professor permitiu que utilizassemos o plt.hist, e sabendo que ele propos a simplificacao do ep
    plt.title("Transformacao Escala")#Todos histogramas da primeira parte do ep foram realizados dentro das funcoes 
    plt.xlabel("Valor")
    plt.ylabel("Frequencia")
    plt.savefig('hist escala translacao.png')



def somaVetores(U1, U2, U, n): #Funcao realizada exatamente de acordo com a especificacao do enunciado do EP3
    i=0
    while i<n:
        U[i]=U1[i]+U2[i]
        i+=1
    plt.hist(U)
    plt.title("Soma Vetores")
    plt.xlabel("Valor")
    plt.ylabel("Frequencia")
    plt.savefig('hist soma.png')




def raizVetor(U,n): #Funcao realizada exatamente de acordo com a especificacao do enunciado do EP3
    i=0
    while i<n:
        U[i]=np.sqrt(U[i])
        i+=1
    plt.hist(U)
    plt.title("raiz Vetor")
    plt.xlabel("Valor")
    plt.ylabel("Frequencia")
    plt.savefig('hist raiz.png')



def normalTransform(U1, U2, Z1, Z2, n): #Funcao realizada exatamente de acordo com a especificacao do enunciado do EP3
    i=0
    while i<n:
        Z1[i]=np.cos(2*np.pi*U2[i])*np.sqrt(-2*np.log(U1[i]))
        Z2[i]=np.sin(2*np.pi*U2[i])*np.sqrt(-2*np.log(U1[i]))
        i+=1
    plt.hist(Z1)
    plt.title("Transform Z1")
    plt.xlabel("Valor")
    plt.ylabel("Frequencia")
    plt.savefig('hist normal Z1.png')
    plt.hist(Z2)
    plt.title("Transform Z2")
    plt.xlabel("Valor")
    plt.ylabel("Frequencia")
    plt.savefig('hist normal Z2.png')

    #Lembrando que o professor nos exonerou de fazer a funcao histograma



def listaCordasM1(r,n):
    i=0 #contador para o loop
    lista=[None]*n # lista vazia do tamanho nessario pra armazenar as cordas criadas
    while i<n: 
        A=random.uniform(0,2*np.pi) #cria o primeiro extremo da corda
        B=random.uniform(0,2*np.pi)#cria o segundo
        tupa=(r,A)# primeira tupla contem as coordenadas do extremo da corda criada
        tupb=(r,B)# segunda tupla contem as coordanadas do outro extremo da corda criada
        lista[i]=((tupa,tupb))# cria a lista contendo as coordenadas
        i+=1
    return lista
             


def listaCordasM2(r,n):
    i=0 #contador para o loop
    lista=[None]*n # lista vazia do tamanho nessario pra armazenar as cordas criadas
    while i<n:
        teta=random.uniform(0,2*np.pi) #Sorteia o angulo do ponto
        z=random.uniform(0,r) # Sorteia um ponto entre 0 e r
        a1=teta+np.arccos(z/r) # Ja cria a primeira coordenada do extremo dessa corda
        if a1>2*np.pi: # caso o arco criado seja maior que 2pi, normaliza ele para o quadrante correto
            a1=a1-2*np.pi
        a2=teta-np.arccos(z/r) #Cria a segunda coordenada do extremo da corda
        if a2<0: # caso o arco criado seja negativo, o valor e normalizado para o quadrante correto
            a2=a2+2*np.pi
        extremo1=(r,a1) #Cria a tupla que contem o primeiro par de coordenadas do extremo da corda
        extremo2=(r,a2) #Cria a segunda tupla
        lista[i]=((extremo1,extremo2))
        i+=1
    return lista

def listaCordasM3(r,n):
    i=0 #contador para o loop
    lista=[None]*n # lista vazia do tamanho nessario pra armazenar as cordas criadas
    while i<n:
        X=random.uniform(-r,r) #Sorteia a primeira coordenada do ponto
        Y=random.uniform(-r,r) #Sorteia a segunda coordenada do ponto
        z=np.sqrt((X*X)+(Y*Y)) # Calcula o tamanho desse ponto
        if(z>r): #Caso o ponto extrapole o raio do circulo o sorteio eh anulado
            i=i-1
        else: #caso contrario
            teta=np.arctan2(Y,X) #Calcula o quadrante onde esta localizado o ponto
            if teta>2*np.pi: #Normaliza o valor caso o arco calculado extrapole 2pi
                teta=teta-2*np.pi
            if teta<0: #Normaliza o valor caso o arco calculado seja negativo
                teta=teta+2*np.pi
            a1=teta+np.arccos(z/r) # Cria a primeira coordenada do extremo dessa corda
            if a1>2*np.pi: #Normaliza o valor criado
                a1=a1-2*np.pi
            a2=teta-np.arccos(z/r) #Cria a segunda coordenada do extremo dessa corda
            if a2<0: #E normaliza o valor
                a2=a2+2*np.pi
            extremo1=(r,a1)
            extremo2=(r,a2)
            lista[i]=((extremo1,extremo2))
        i+=1
    return lista

  

def determinaPontosMedios(listaExtremos):
    lista=[None]*len(listaExtremos) #Cria uma lista vazia do tamanho adequado para armazenar os pontos medios da lista recebia
    for i in range(len(listaExtremos)):
        x1=listaExtremos[i][0][0]*np.cos(listaExtremos[i][0][1]) #x=r*cos(teta), de polar para cartesiana. R e teta estao localizados nesses index do array
        y1=listaExtremos[i][0][0]*np.sin(listaExtremos[i][0][1]) #y=r*sin(teta), de polar para cartesiana.R e teta estao localizados nesses index do array
        x2=listaExtremos[i][1][0]*np.cos(listaExtremos[i][1][1]) #A mesma coisa com o outro extremo. O index [i][1] contem a coordenada do outro extremo
        y2=listaExtremos[i][1][0]*np.sin(listaExtremos[i][1][1])
        x=(x1+x2)/2 #Calcula o ponto medio, abaixo ponto medio de y.
        y=(y1+y2)/2
        pmedio=(x,y) #Cria a tupla com o ponto medio em coordenadas cartesianas.
        lista[i]=pmedio
    return lista
                
        

def determinaPontosExtremos(r,listaPontosMedios): #Tendo em vista que construi o programa pela ordem das funcoes acabei nao utilizando essa funcao
    lista[None]*len(listaPontosMedios) #No entanto como especificado pelo enunciado a deixei criada
    for i in range(len(listaPontosMedios)):
        Z=np.sqrt((listaPontosMedios[i][0]**2)+(listaPontosMedios[i][1]**2)) #Converte para polar a dupla de coordenas cartesianas
        teta=np.arctan2(listaPontosMedios[i][0],listaPontosMedios[i][1]) #Calcula o quadrante onde esta localizado o ponto
        if teta>2*np.pi: #Normaliza o valor caso o arco calculado extrapole 2pi
            teta=teta-2*np.pi
        if teta<0: #Normaliza o valor caso o arco calculado seja negativo
            teta=teta+2*np.pi
        a1=teta+np.arccos(z/r) # Cria a primeira coordenada do extremo dessa corda
        if a1>2*np.pi: #Normaliza o valor criado
            a1=a1-2*np.pi
        a2=teta-np.arccos(z/r) #Cria a segunda coordenada do extremo dessa corda
        if a2<0: #E normaliza o valor
            a2=a2+2*np.pi
        A=(r,a1)
        B=(r,a2)
        lista[i]=((A,B))
    return lista

#A funcao distribuicao borda divide o circulo em oito pedacos. De 0 a 2pi com incrementos de pi/4.
def distribuicaoBorda(r,listaCordas): 
    counter0=0 #Armazena os pontos que estao localizados entre 0 e pi/4. Grupo0
    counter1=0 #Armazena os pontos que estao localizados entre pi/4 e pi/2.Grupo1
    counter2=0 #Armazena os pontos que estao localizados entre pi/2 e 3pi/4.Grupo2
    counter3=0 #Armazena os pontos que estao localizados entre 3pi/4 e pi.Grupo3
    counter4=0 #Armazena os pontos que estao localizados entre pi e 5pi/4.Grupo4
    counter5=0 #Armazena os pontos que estao localizados entre 5pi/4 e 6pi/4.Grupo5
    counter6=0 #Armazena os pontos que estao localiados entre 6pi/4 e 7pi/4.Grupo6
    counter7=0 #Armazena os pontos que estao localizados entre 7pi/4 e 2pi.Grupo7
    plt.figure(figsize=(15,6),dpi=80) #Como especificado pelo enunciado cria a parte direita do grafico e lhe da o tamanho
    plt.subplot(121)
    thetas=np.arange(0,2*np.pi,0.01) #Cria condicoes pra plotar o circulo
    plt.plot(r*np.cos(thetas),r*np.sin(thetas),'w-') #Plota o circulo
    plt.plot((-r,r),(0,0),'b-') #Plota reta no eixo x
    plt.plot((0,0),(-r,r),'b-') #Plota reta no eixo y
    plt.plot((0,r*np.sin(np.pi/4)),(0,r*np.cos(np.pi/4)),'b-') #Plota reta de 0 ate pi/4
    plt.plot((0,r*np.sin(3*np.pi/4)),(0,r*np.cos(3*np.pi/4)),'b-') #Plota reta de 0 ate 3pi/4
    plt.plot((0,r*np.sin(5*np.pi/4)),(0,r*np.cos(5*np.pi/4)),'b-') #plota reta de 0 ate 5pi/4
    plt.plot((0,r*np.sin(7*np.pi/4)),(0,r*np.cos(7*np.pi/4)),'b-') #plota reta de 0 ate 7pi/4
    plt.axis([-r, r, -r, r])
    plt.title('Circulo dividido em bordas')
    n=0
    m=0
    while n<len(listaCordas): #o loop para plot cada dois pontos eh rodado duas vezes, uma para cada par de coordenadas dos extremos recebidos
        if 0<=listaCordas[n][0][1]<np.pi/4:
           plt.scatter(r*np.sin(listaCordas[n][0][1]),r*np.cos(listaCordas[n][0][1]),c='magenta',s=40)
           counter0+=1
        elif np.pi/4<=listaCordas[n][0][1]<np.pi/2:
           plt.scatter(r*np.sin(listaCordas[n][0][1]),r*np.cos(listaCordas[n][0][1]),c='green',s=40)
           counter1+=1
        elif np.pi/2<=listaCordas[n][0][1]<3*np.pi/4:
           plt.scatter(r*np.sin(listaCordas[n][0][1]),r*np.cos(listaCordas[n][0][1]),c='red',s=40)
           counter2+=1
        elif 3*np.pi/4<=listaCordas[n][0][1]<np.pi:
           plt.scatter(r*np.sin(listaCordas[n][0][1]),r*np.cos(listaCordas[n][0][1]),c='black',s=40)
           counter3+=1
        elif np.pi<=listaCordas[n][0][1]<5*np.pi/4:
           plt.scatter(r*np.sin(listaCordas[n][0][1]),r*np.cos(listaCordas[n][0][1]),c='orange',s=40)
           counter4+=1
        elif 5*np.pi/4<=listaCordas[n][0][1]<6*np.pi/4:
           plt.scatter(r*np.sin(listaCordas[n][0][1]),r*np.cos(listaCordas[n][0][1]),c='grey',s=40)
           counter5+=1
        elif 6*np.pi/4<=listaCordas[n][0][1]<7*np.pi/4:
           plt.scatter(r*np.sin(listaCordas[n][0][1]),r*np.cos(listaCordas[n][0][1]),c='yellow',s=40)
           counter6+=1
        elif 7*np.pi/4<=listaCordas[n][0][1]<2*np.pi:
           plt.scatter(r*np.sin(listaCordas[n][0][1]),r*np.cos(listaCordas[n][0][1]),c='brown',s=40)
           counter7+=1
        n+=1
    while m<len(listaCordas): #Segunda vez do loop, para o segundo par de coordenadas
        if 0<=listaCordas[m][1][1]<np.pi/4:
           plt.scatter(r*np.sin(listaCordas[m][1][1]),r*np.cos(listaCordas[m][1][1]),c='magenta',s=40)
           counter0+=1
        elif np.pi/4<=listaCordas[m][1][1]<np.pi/2:
           plt.scatter(r*np.sin(listaCordas[m][1][1]),r*np.cos(listaCordas[m][1][1]),c='green',s=40)
           counter1+=1
        elif np.pi/2<=listaCordas[m][1][1]<3*np.pi/4:
           plt.scatter(r*np.sin(listaCordas[m][1][1]),r*np.cos(listaCordas[m][1][1]),c='red',s=40)
           counter2+=1
        elif 3*np.pi/4<=listaCordas[m][1][1]<np.pi:
           plt.scatter(r*np.sin(listaCordas[m][1][1]),r*np.cos(listaCordas[m][1][1]),c='black',s=40)
           counter3+=1
        elif np.pi<=listaCordas[m][1][1]<5*np.pi/4:
           plt.scatter(r*np.sin(listaCordas[m][1][1]),r*np.cos(listaCordas[m][1][1]),c='orange',s=40)
           counter4+=1
        elif 5*np.pi/4<=listaCordas[m][1][1]<6*np.pi/4:
           plt.scatter(r*np.sin(listaCordas[m][1][1]),r*np.cos(listaCordas[m][1][1]),c='grey',s=40)
           counter5+=1
        elif 6*np.pi/4<=listaCordas[m][1][1]<7*np.pi/4:
           plt.scatter(r*np.sin(listaCordas[m][1][1]),r*np.cos(listaCordas[m][1][1]),c='yellow',s=40)
           counter6+=1
        elif 7*np.pi/4<=listaCordas[m][1][1]<2*np.pi:
           plt.scatter(r*np.sin(listaCordas[m][1][1]),r*np.cos(listaCordas[m][1][1]),c='brown',s=40)
           counter7+=1
        m+=1
    plt.subplot(122) #Segundo grafico
    grupos = ['grupo0', 'grupo1', 'grupo2', 'grupo3', 'grupo4', 'grupo5','grupo6','grupo7']
    frequencia = [counter0, counter1, counter2, counter3, counter4, counter5,counter6,counter7]
    pos = np.arange(len(grupos))
    width = 1.0     # Da ao grafico de barra aparencia de histograma
    plt.bar(pos, frequencia, width, color=['magenta','green','red','black','orange','grey','yellow','brown']) #Plota um histograma com barras de diferentes cores
    plt.ylabel('Frequencia') #Nomeia o eixo x e y e o grafico
    plt.xlabel('Grupos')
    plt.title('Distribuicao bordas por grupos')
    # descomente a linha abaixo caso queira ver o grafico
    #plt.show()
    #A imagem eh salva com nome Mx, sendo x o numero do metodo sendo utilizado, altere o nome do arquivo para nao o sobrepor
    plt.savefig('distribuicao_Borda_M1.png')
    
#A funcao distribuicaoRadial divide o circulo em 8 coroas. Cada uma com largura de r/8
def distribuicaoRadial(r,listaCordas):
    counter0=0 #Armazena os pontos que estao localizados entre 0 e r/8. Grupo0
    counter1=0 #Armazena os pontos que estao localizados entre r/8 e r/4. Grupo1
    counter2=0 #Armazena os pontos que estao localizados entre r/4 e 3r/8. Grupo2
    counter3=0 #Armazena os pontos que estao localizados entre 3r/8 e r/2. Grupo3
    counter4=0 #Armazena os pontos que estao localizados entre r/2 e 5r/8. Grupo4
    counter5=0 #Armazena os pontos que estao localizados entre 5r/8 e 6r/8. Grupo5
    counter6=0 #Armazena os pontos que estao localizados entre 6r/8 e 7r/8. Grupo6
    counter7=0 #Armazena os pontos que estao localizados entre 7r/8 e r. Grupo7
    listaMedios=determinaPontosMedios(listaCordas) #envia as cordas recebidas e recebe de volta lista com pontos medios das cordas
    plt.figure(figsize=(15,6),dpi=80) #especifica o grafico da mesma maneira que a anterior
    plt.subplot(121)
    thetas=np.arange(0,2*np.pi,0.01)
    plt.plot(r*np.cos(thetas),r*np.sin(thetas),'b-')
    plt.plot((r/8)*np.cos(thetas),(r/8)*np.sin(thetas),'b-') #plota os subcirculos
    plt.plot((r/4)*np.cos(thetas),(r/4)*np.sin(thetas),'b-')
    plt.plot((3*r/8)*np.cos(thetas),(3*r/8)*np.sin(thetas),'b-')
    plt.plot((r/2)*np.cos(thetas),(r/2)*np.sin(thetas),'b-')
    plt.plot((5*r/8)*np.cos(thetas),(5*r/8)*np.sin(thetas),'b-')
    plt.plot((6*r/8)*np.cos(thetas),(6*r/8)*np.sin(thetas),'b-')
    plt.plot((7*r/8)*np.cos(thetas),(7*r/8)*np.sin(thetas),'b-')
    plt.axis([-r, r, -r, r])
    plt.title('Circulo dividido em coroas')
    n=0
    while n<len(listaMedios): #loop para plotar os pontos de acordo com os grupos pre-definidos
        if 0<=np.sqrt((listaMedios[n][0]**2)+(listaMedios[n][1]**2))<r/8:
           plt.scatter(listaMedios[n][0],listaMedios[n][1],c='magenta')
           counter0+=1
        elif r/8<=np.sqrt((listaMedios[n][0]**2)+(listaMedios[n][1]**2))<r/4:
           plt.scatter(listaMedios[n][0],listaMedios[n][1],c='green')
           counter1+=1 
        elif r/4<=np.sqrt((listaMedios[n][0]**2)+(listaMedios[n][1]**2))<3*r/8:
           plt.scatter(listaMedios[n][0],listaMedios[n][1],c='red')
           counter2+=1 
        elif 3*r/8<=np.sqrt((listaMedios[n][0]**2)+(listaMedios[n][1]**2))<r/2:
           plt.scatter(listaMedios[n][0],listaMedios[n][1],c='black')
           counter3+=1 
        elif r/2<=np.sqrt((listaMedios[n][0]**2)+(listaMedios[n][1]**2))<5*r/8:
           plt.scatter(listaMedios[n][0],listaMedios[n][1],c='orange')
           counter4+=1 
        elif 5*r/8<=np.sqrt((listaMedios[n][0]**2)+(listaMedios[n][1]**2))<6*r/8:
           plt.scatter(listaMedios[n][0],listaMedios[n][1],c='grey')
           counter5+=1 
        elif 6*r/8<=np.sqrt((listaMedios[n][0]**2)+(listaMedios[n][1]**2))<7*r/8:
           plt.scatter(listaMedios[n][0],listaMedios[n][1],c='yellow')
           counter6+=1
        elif 7*r/8<=np.sqrt((listaMedios[n][0]**2)+(listaMedios[n][1]**2))<=r:
           plt.scatter(listaMedios[n][0],listaMedios[n][1],c='brown')
           counter7+=1
        n+=1
    plt.subplot(122)#plota histograma exatamente da mesma maneira que a anterior
    grupos = ['grupo0', 'grupo1', 'grupo2', 'grupo3', 'grupo4', 'grupo5','grupo6','grupo7']
    frequencia = [counter0, counter1, counter2, counter3, counter4, counter5,counter6,counter7]
    pos = np.arange(len(grupos))
    width = 1.0     
    plt.bar(pos, frequencia, width, color=['magenta','green','red','black','orange','grey','yellow','brown'])
    plt.ylabel('Frequencia')
    plt.xlabel('Grupos')
    plt.title('Distribuicao radial por grupos')
     #descomente a linha abaixo caso queira ver o grafico
    #plt.show()
    #A imagem eh salva com nome Mx, sendo x o numero do metodo sendo utilizado, altere o nome do arquivo para nao o sobrepor
    plt.savefig('distribuicao_Radial_M1.png')

#A funcao distribuicao area divide o circulo em 8 partes de area igual. 4 partes internas de 0 ate r/sqrt(2) e de divisao angular igual de pi/2
#E uma parte externa de r/sqrt(2) ate r e de divisao angular igual de pi/2  
def distribuicaoArea(r,listaCordas):
    counter0=0 #Os primeiros quatro grupos armazenam a parte interna da divisao. Grupo 0 fica com a parte interna de 0 ate pi/2
    counter1=0 #Os primeiros quatro grupos armazenam a parte interna da divisao. Grupo 1 fica com a parte interna de pi/2 ate pi
    counter2=0 #Os primeiros quatro grupos armazenam a parte interna da divisao. Grupo 2 fica com a parte interna de pi ate 3pi/2
    counter3=0 #Os primeiros quatro grupos armazenam a parte interna da divisao. Grupo 3 fica com a parte interna de 3pi/2 ate 2pi
    counter4=0 #Os ultimos quatro grupos armazenam a parte externa da divisao. Grupo 4 fica com a parte externa de 0 ate pi/2
    counter5=0 #Os ultimos quatro grupos armazenam a parte externa da divisao. Grupo 5 fica com a parte externa de pi/2 ate pi
    counter6=0 #Os ultimos quatro grupos armazenam a parte externa da divisao. Grupo 6 fica com a parte externa de pi ate 3pi/2
    counter7=0 #Os ultimos quatro grupos armazenam a parte externa da divisao. Grupo 7 fica com a parte externa de 3pi/2 ate 2pi
    listaMedios=determinaPontosMedios(listaCordas)
    plt.figure(figsize=(15,6),dpi=80)
    plt.subplot(121)
    thetas=np.arange(0,2*np.pi,0.01)
    plt.plot(r*np.cos(thetas),r*np.sin(thetas),'b-')
    plt.plot((-r,r),(0,0),'b-') #Divide o circulo horizontalmente
    plt.plot((0,0),(-r,r),'b-') #Divide o circulo verticalmente
    plt.plot((r/np.sqrt(2))*np.cos(thetas),(r/np.sqrt(2))*np.sin(thetas),'b-') #cria outro circulo de r/sqrt(2), criando assim 8 regioes de mesma area
    plt.axis([-r, r, -r, r])
    plt.title('Circulo dividido em area')
    n=0# o loop de plotagem dos pontos envolve o calculo de sua distancia da origem e de seu angulo, e comparando esses valores com os valores definidos acima..
    while n<len(listaMedios):# para os grupos
        teta=np.arctan2((listaMedios[n][1]),(listaMedios[n][0])) #cria o angulo dos pontos para sua classificacao
        if teta>2*np.pi: #normaliza o angulo
            teta=teta-2*np.pi
        if teta<0: #normaliza o angulo
            teta=teta+2*np.pi
        if 0<=np.sqrt((listaMedios[n][0]**2)+(listaMedios[n][1]**2))<(r/np.sqrt(2)) and 0<=teta<np.pi/2: 
           plt.scatter(listaMedios[n][0],listaMedios[n][1],c='magenta')
           counter0+=1
        if 0<=np.sqrt((listaMedios[n][0]**2)+(listaMedios[n][1]**2))<(r/np.sqrt(2)) and np.pi/2<=teta<np.pi:
           plt.scatter(listaMedios[n][0],listaMedios[n][1],c='green')
           counter1+=1
        if 0<=np.sqrt((listaMedios[n][0]**2)+(listaMedios[n][1]**2))<(r/np.sqrt(2)) and np.pi<=teta<3*np.pi/2:
           plt.scatter(listaMedios[n][0],listaMedios[n][1],c='red')
           counter2+=1
        if 0<=np.sqrt((listaMedios[n][0]**2)+(listaMedios[n][1]**2))<(r/np.sqrt(2)) and 3*np.pi/2<=teta<2*np.pi:
           plt.scatter(listaMedios[n][0],listaMedios[n][1],c='black')
           counter3+=1
        if (r/np.sqrt(2))<=np.sqrt((listaMedios[n][0]**2)+(listaMedios[n][1]**2))<r and 0<=teta<np.pi/2:
           plt.scatter(listaMedios[n][0],listaMedios[n][1],c='orange')
           counter4+=1
        if (r/np.sqrt(2))<=np.sqrt((listaMedios[n][0]**2)+(listaMedios[n][1]**2))<r and np.pi/2<=teta<np.pi:
           plt.scatter(listaMedios[n][0],listaMedios[n][1],c='grey')
           counter5+=1
        if (r/np.sqrt(2))<=np.sqrt((listaMedios[n][0]**2)+(listaMedios[n][1]**2))<r and np.pi<=teta<3*np.pi/2:
           plt.scatter(listaMedios[n][0],listaMedios[n][1],c='yellow')
           counter6+=1
        if (r/np.sqrt(2))<=np.sqrt((listaMedios[n][0]**2)+(listaMedios[n][1]**2))<r and 3*np.pi/2<=teta<2*np.pi:
           plt.scatter(listaMedios[n][0],listaMedios[n][1],c='brown')
           counter7+=1
        n+=1
    plt.subplot(122)
    grupos = ['grupo0', 'grupo1', 'grupo2', 'grupo3', 'grupo4', 'grupo5','grupo6','grupo7']
    frequencia = [counter0, counter1, counter2, counter3, counter4, counter5,counter6,counter7]
    pos = np.arange(len(grupos))
    width = 1.0     
    plt.bar(pos, frequencia, width, color=['magenta','green','red','black','orange','grey','yellow','brown'])
    plt.ylabel('Frequencia')
    plt.xlabel('Grupos')
    plt.title('Distribuicao area por grupos')
     #descomente a linha abaixo caso queira ver o grafico
    #plt.show()
    #A imagem eh salva com nome Mx, sendo x o numero do metodo sendo utilizado, altere o nome do arquivo para nao o sobrepor
    plt.savefig('distribuicao_Area_M1.png')
    
def distribuicaoCordas(r,listaCordas):
    plt.figure(figsize=(15,6),dpi=80) #Cria o grafico da mesma maneira que os graficos acima
    plt.subplot(121) # Mantenho aqui o mesmo tamanho, tirando a especificacao subplot o circulo fica com uma aparencia elipsoidal
    thetas=np.arange(0,2*np.pi,0.01)
    plt.plot(r*np.cos(thetas),r*np.sin(thetas),'b-')
    plt.axis([-r, r, -r, r])
    plt.title('Circulo dividido em cordas')
    for i in range(len(listaCordas)):
        x1=listaCordas[i][0][0]*np.cos(listaCordas[i][0][1]) #transforma em cartesiana os pontos polares recebidos
        y1=listaCordas[i][0][0]*np.sin(listaCordas[i][0][1])
        x2=listaCordas[i][1][0]*np.cos(listaCordas[i][1][1])
        y2=listaCordas[i][1][0]*np.sin(listaCordas[i][1][1])
        plt.plot((x1,x2),(y1,y2),'c-') #plota a corda
    #A imagem eh salva com nome Mx, sendo x o numero do metodo sendo utilizado, altere o nome do arquivo para nao o sobrepor
    plt.savefig('distribuicao_cordas_M1.png')

        

def main():
    print("O seguinte programa consiste em duas partes\n")
    print("A primeira parte consiste em plotar 4 diferentes histogramas com valores calculados em funçoes de manipulacao de vetor\n")
    t=int(input("Para comecar entre com o tamanho dos vetores que serao utilizados: "))
    a=float(input("Agora entre com um valor real que sera utilizado na primeira funcao de manipulacao de vetor, no formato x.x: "))
    b=float(input("Entre com o segundo valor para a mesma funcao, no formato x.x: "))
    U=[None]*t #Todas as funcoes abaixo, incluindo essa, foram criadas de acordo com a especificacao dada pelo enunciado do EP
    V=[None]*t
    U2=[None]*t
    U3=[None]*t
    Z1=[0]*t
    Z2=[0]*t
    for i in range(t):
        U[i]=random.uniform(0,1)
    for i in range(t):
        U2[i]=random.uniform(0,1)
    transformacaoEscala(U,V,t,a,b)
    somaVetores(U,U2,U3,t)
    raizVetor(U,t)
    normalTransform(U,U2,Z1,Z2,t)
    print("Agora prosseguiremos para a segunda parte do programa, onde serão gerados n cordas em um circulo de raio r")
    r=float(input("Entre com o tamanho do raio do circulo, no formato x.x: "))
    n=int(input("Entre com o numero de cordas que serao geradas: "))
    print("A principio utilizaremos o metodo 1 de geracao de cordas")
    print("Para gerar as cordas pelos outros metodos descomente as chamadas das funcoes abaixo correspondente ao metodo de geracao a ser utilizado")
    listaM1=listaCordasM1(r,n) #Como ja comentado, para criar os outros circulos eh soh descomentar as funcoes correspondentes e mudar o nome do .png salvo
    distribuicaoBorda(r,listaM1)
    distribuicaoRadial(r,listaM1)
    distribuicaoArea(r,listaM1)
    distribuicaoCordas(r,listaM1)
    #listaM2=listaCordasM2(r,n)
    #distribuicaoBorda(r,listaM2)
    #distribuicaoRadial(r,listaM2)
    #distribuicaoArea(r,listaM2)
    #distribuicaoCordas(r,listaM2)
    #listaM3=listaCordasM3(r,n)
    #distribuicaoBorda(r,listaM3)
    #distribuicaoRadial(r,listaM3)
    #distribuicaoArea(r,listaM3)
    #distribuicaoCordas(r,listaM3)
    
    
main() #chama o main
