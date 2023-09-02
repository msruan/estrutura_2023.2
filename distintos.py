def main():
    numero_de_entradas = int(input())
    numeros = ""
    for i in range(numero_de_entradas):
        aux = input()
        numeros += aux

    intervalos_de_distintos = []
    substring = ""

    for i in range(numero_de_entradas):
        for j in range(numero_de_entradas):
            if numeros[j] in substring:
                intervalos_de_distintos.append(substring)
                substring = numeros[j]
            else:
                substring += numeros[j]
        intervalos_de_distintos.append(substring)
        substring = ""
    maior = 1
    
    for i in range(len(intervalos_de_distintos)):
        if (len(intervalos_de_distintos[i]) > maior):

            maior = len(intervalos_de_distintos[i])
    print(maior)

main()