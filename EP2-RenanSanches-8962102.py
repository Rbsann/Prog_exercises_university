#.n Renan Bueno Sanches
#.u 8962102


import random
import math


#Em relaçao ao metodo 1 , sortear pontos aleatorios na circunferencia eh o mesmo que sortear angulos dessa mesma circunferencia...
#...tendo em vista que a corda eh definidade matematica como 2*raio*sen(angulo em relacao ao centro/2)
def metodo1(r,n):
    i=0 #variavel pra controler o loop de while
    temp=0 #variavel pra inverter os numeros sorteados caso B seja maior que A
    counter=0 #variavel pra contar quantas vezes o arco sorteado eh maior que o lado do triangulo inscrito
    while i<n:
        A=random.uniform(0,2*math.pi) #A e B sao dois angulos sorteados, partindo do centro (0,0), sorteia dois floats entre 0 e 360 graus.
        B=random.uniform(0,2*math.pi)
        if (A<B): #como sin(-x)=-senx o algoritmo precisa de um valor positivo para o angulo
          temp=B
          B=A
          A=temp
        corda=A-B #Define a corda, poderia simplesmente sortear um angulo, fixando o outro em alguma extremidade, mas preferi sortear ambos e construir a corda
        if ((2*r*math.sin((corda/2)))>r*math.sqrt(3)): #caso a corda aleatoria seja maior que o lado do triangulo counter eh atualizado
             counter=counter+1
        i=i+1
    return float(counter/n) #retorna a proporcao entra counter e numero de vezes que o programa deve ser repetido
             



#para o metodo dois eh somente necessario sortear um segmento de reta dentro do comprimento do raio, e comparar o tamanho desse segmento com o raio
def metodo2(r,n):
    i=0 # variavel para controlar o loop
    counter=0 #variavel pra contar o numero de vezes que o segmento de reta foi menor que a metade do raio
    min=float(r/2) #nao ha necessidade para essa variavel, no entanto, eu prefiro criar o maximo numero de variaveis possiveis.Pra mim fica mais facil debug.
    while i<n:
        OP=random.uniform(0,r) #Sorteia um segmento de reta de comprimento maximo r
        if(OP<min): # Caso o segmento seja menor que r/2 counter eh atualizado
            counter=counter+1
        i=i+1
    return float(counter/n) # retorna a proporcao entre o numero de vezes que OP foi menor que r/2 e a quantidade de vezes que o metodo foi repetido



#No metodo 3 foi necessario sortear pontos aleatorios dentro do circulo, e comparar o comprimento desse ponto com o tamanho do raio
def metodo3(r,n):
    i=0 #controla o loop
    min=float(r/2) # mais uma vez variavel desnecessaria a variavel, no entanto prefiro trabalhar assim
    counter=0 # controla o numero de casos os quais o ponto sorteado teve comprimento menor que o raio
    while i<n:
        X=random.uniform(-r,r) # sorteia o primeiro ponto, de tamanho -r ateh r
        Y=random.uniform(-r,r)
        Z=math.sqrt((X*X)+(Y*Y)) #define o comprimento desse ponto, partindo do centro (0,0), pela formula de pitagoras
        if (Z>r):#caso a dupla de pontos sorteada seja maior que o comprimento do raio, os pontos estao fora do circulo, portanto essa vez do loop eh anulada
            i=i-1
        if (Z<min): #caso o comprimento do ponto seja menor que raio/2 incrementa counter
            counter=counter+1
        i=i+1
    return float(counter/n)






def main():
    r=float(input('Entre com o raio da circunferencia: ')) # usuario entra com tamanho do raio
    n=int(input("Entre com o numero de vezes os procedimentos serao repetidos: ")) # e a quantidade vezes que os procedimentos sao repetidos
    met1=metodo1(r,n) # chama o metodo 1 e aloca a uma variavel, o mesmo com metodo 2 e 3
    met2=metodo2(r,n)
    met3=metodo3(r,n)
    lado=r*math.sqrt(3) #ja calcula lado do triangulo equilatero inscrito e aloca em uma variavel
    print("Considerando um triangulo de lado %0.4f" %lado) 
    print("Pelo metodo 1 a probabilidade de um arco ser maior que o lado desse triangulo equilatero inscrito sera de %0.3f " %met1)
    print("Pelo metodo 2 a possibilidade de um arco aleatorio ser maior que o lado desse triangulo inscrito sera de  %0.1f" %met2)
    print("Pelo metodo 3 a possibilidade de um arco aleatorio ser maior que o lado desse triangulo inscrito sera de  %0.2f" %met3)

main() #chama o metodo main
             
    
