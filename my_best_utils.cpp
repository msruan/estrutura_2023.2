#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

bool in(string colecao, char digito)
{
    for (int i = 0; i < colecao.length(); i++){
        if (digito == colecao[i])
            return true;
    }
    return false;
}

bool eh_digito(char digito)
{
    string numeros = "1234567890";
    return (in(numeros,digito));

}

bool eh_numero(string numero)
{
    int ha_ponto = 0;
    bool ha_numeros = false;
    for (int i = 0; i<(numero.length()) ; i++){
        if (numero[i] == '.'){
            ha_ponto++;
        }
        else if (eh_digito(numero[i])){
            ha_numeros = true;
        }
        else
            return 0;
        if (ha_ponto > 1){
            return 0;
        }
    }
    return ha_numeros;
}

bool eh_inteiro(string numero)
{
    if (eh_numero(numero))
        return (not(in(numero,'.')));
    return false;
}

bool eh_float(string numero)
{
    if ((eh_numero(numero)) and (!(eh_inteiro(numero))))
        return true;
    return false;
}

int char2int(char digito)
{   
    if (digito =='1')
        return 1;
    else if (digito =='2')
        return 2;
    else if (digito =='3')
        return 3;
    else if (digito =='4')
        return 4;
    else if (digito =='5')
        return 5;
    else if (digito =='6')
        return 6;
    else if (digito =='7')
        return 7;
    else if (digito =='8')
        return 8;
    else if (digito =='9')
        return 9;
    else if (digito =='0')
        return 0;
    return -1;
}
int full(string inteiro)
{
    if (eh_inteiro(inteiro)){
        int dezena = 0;
        int numero = 0;
        for (int i = inteiro.length() - 1; i > -1; i--){
            numero += (char2int(inteiro[i])*(pow(10,dezena)));
            dezena++;
        }
        return numero;
    }else if(eh_float(inteiro)){
        for (int i = 0; i < inteiro.size(); i++){//.0
            if ((inteiro[i] == '.') and (i==0))
                return 0;
            else if (inteiro[i] == '.')//0.
                return (full(inteiro.substr(0,i)));
        }
    }return 0;//pro compilador n ficar bravo
 // o mais adequado seria levantar uma exceção
}

bool eh_ponto(char digito){
    return (digito == '.');
}
bool eh_nulo(char digito){
    return (digito == '\0');
}

float real(string number)
{
    if (eh_inteiro(number))
        return (full(number) + 0.f);
    string parte_inteira = "0";
    string parte_float = ""; 
    float flutuante = 0.f;

    bool encontrou_ponto = false;
    for (int i = 0; i < number.length(); i++) {
        if (eh_ponto(number[i])) {
            encontrou_ponto = true;
            continue;
        }
        if (encontrou_ponto)
            parte_float += number[i]; 
        else 
            parte_inteira += number[i]; 
    }
    for (int j = 1; j < parte_float.length() + 1; j++)
        flutuante += (char2int(parte_float[j-1])*(pow(10,-j)));
    return (flutuante + full(parte_inteira));
      // o mais adequado seria levantar uma exceção
}

int inputi(string label="")
{
    string numero;
    if ((label) == "")
        cout << "\nDigite um inteiro: ";
    else
        cout << label;
    cin >> numero;
    if (eh_numero(numero))
        return full(numero);
    return inputi(label);
}

float inputf(string label="")
{
    string numero;
    if ((label) == "")
        cout << "\nDigite um float: ";
    else
        cout << label;
    cin >> numero;
    if (eh_numero(numero))
        return real(numero);
    return inputf(label);
}

void printi(int numero){
    cout << numero;
}

void print(string label){
    cout << label;
}
void printf(float label){
    cout << label;
}
vector<string> split(string label, char separador){
    string palavra = "";
    vector <string> palavras(0);
    for (int i = 0; label[i] != '\0'; i++){
        if (label[i] != separador)
            palavra += label[i];
        else if(palavra!="")
            palavras.push_back(palavra);
        }
    return palavras;
}
int len(string str)
{
    int i;
    for (i=0;str[i] != '\0';++i){}
    return i;
}

/*
float expo(int base, int expoente)
{
    if (expoente<0)
        return (1.0/expo(base,-expoente));
    else if ((base < 0) or (expoente == 0))
        return 1;
    else if (expoente==1)
        return base;
    int expo;
    for (expo = base; --expoente; expo *= base){}
    return expo;
}
*/
int main(){
    int i = 10;
    while(--i){
        int a = inputi("Digite um inteiro e irei mostrá-lo...\n>>> ");
        print("\nO número é ");
        cout << a;
        float b = inputf("\nDigite um float e irei mostrá-lo...\n>>> ");
        print("\nO número é ");
        cout << b;
    }
    
}
