#.n Renan Bueno Sanches
#.u 8962102
import numpy as np
import matplotlib.pyplot as plt


def leEntrada(nome):
    lista=[] #cria uma lista vazia
    with open(nome) as f:
        lines = [line.rstrip('\n') for line in open(nome)] #tira /n do conteudo o arquivo lio
    for i in lines:
        lista.append(i.split(',')) #separa a dupla de coordenadas do arquivo lido
    for i in range(1,len(lista)):
        lista[i][0]=int(lista[i][0]) #transforma em uma dupla de coordenadas de int os numeros que estavam em string do arquivo
        lista[i][1]=int(lista[i][1])
    return lista

def transformatabquad(T,b,s):
    Som=np.zeros(T.shape) # Cria uma matriz preenchida com zeros do tamanho da matriz recebida
    Som = (T[0:-2,0:-2] + T[0:-2,1:-1] + T[0:-2,2:] +
         T[1:-1,0:-2]+ T[1:-1,2:] + T[2:  ,0:-2] + T[2:  ,1:-1] + T[2:  ,2:]) # Soma todos as celulas da matriz do tabuleiro recebido
    nasce = (Som==b) & (T[1:-1,1:-1]==0) # cria uma array com  se as condicoes de vida estejam preenchidas
    vivo = (Som==s) & (T[1:-1,1:-1]==1) # cria um array se as condicoes de sobrevivencia estejam preenchidas
    T[...] = 0 #reseta o tabuleiro preenchendo com zero
    T[1:-1,1:-1][nasce | vivo] = 1 #preenche o tabuleiro com os valores corretos
    return T
def simulaQuadGenerica(n,m,lista,t,b,s):
    tabuleiro=np.zeros((n,m)) # cria um tabuleiro preenchido com zeros de tamanho n por m
    for x in lista:
        tabuleiro[x[0]][x[1]]=1 # preenche esse tabuleiro com os valores vivos
    for i in range(t): # manda o tabuleiro pra ele ser transformado
        transformatabquad(tabuleiro,b,s)
    return tabuleiro

#def simulaHexGenerica(n,m,lista,t,b,s):

def main():
    lista=[] # cria uma lista vazia
    lista=leEntrada('exemplo2.txt') #preenche ela com os valores do arquivo lido
    n=int(input("Entre com numero de linhas: ")) 
    m=int(input("Entre com numero de colunas: "))
    t=int(input("Entre com numero de iteraçoes: "))
    b=int(input("Entre com as condiçoes para uma celula nascer: "))
    s=int(input("Entre com as condicoes para uma celular continuar viva: "))
    quadrado='H' 
    if quadrado in lista[0]: # se a string 'H' esta na primeira linha do arquivo inicia  os metodos do quadrado
        del lista[0] # deleta a primeira linha do arquivo, ela nao eh mais necessaria
        lista=np.array(lista) #transformar a lista em um formato numpy
        lista2=simulaQuadGenerica(n,m,lista,t,b,s)
    print(lista2)

main()
