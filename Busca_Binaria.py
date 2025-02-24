def Busca_Binaria(lista,num):
    alto=len(lista)-1
    baixo=0
    num_operações=0
    while baixo <= alto:
        num_operações+=1
        meio=(alto+baixo)//2
        if (num == lista[meio]):
            print("Número de operações: ",num_operações)
            return meio
        
        if(num > lista[meio]):
            baixo=meio+1
        
        if(num<lista[meio]):
            alto=meio-1
            
    return -1


lista = list(range(1, 1001))
num = int(input("Digite um número: "))

pos = int(Busca_Binaria(lista, num))

if(pos!=-1):
    print("O número está na posição ",pos)
else:
    print("O número não está na lista")
