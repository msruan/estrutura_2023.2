#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool ta_em (string label ,vector<string> labels){
    for(int i = 0; i < labels.size(); i++){
        if(label.compare(labels[i]) == 0)
            return true;
    }return false;
}

vector<string> tirar_repetidos(vector<string> lista){
    vector<string> saida(0);
    for(string i: lista){
        if(not ta_em(i,saida))
            saida.push_back(i);
    }return saida;
}

vector<string> filtrar (bool (*funcao_criterio)(string s), vector<string> colecao){
    vector<string> saida(0);
    for (int i= 0; i < colecao.size(); i++){
        if (funcao_criterio(colecao[i]))
            saida.push_back(colecao[i]);
    }return saida;
}

bool in(char caractere, string label)
{
    for (int i = 0; i < label.size(); i++){
        if (caractere == label[i])
            return true;
    }return false;
}
bool not_ha_repetidos(string s){
    string verificados = "";
    for (int i = 0; i < s.length(); i++){
        if (in(s[i],verificados)){
            return false;
        }verificados += s[i];
    }return true;
}
void mostrar_vetor(vector<string> lista){
    cout << endl <<"INICIO DO VETOR[ |"<< endl;
    for (string i: lista){
        cout << "| "<< i << " |"<<endl;
    }cout << " ]FIM DO VETOR"<<endl;
}
void mostrar_vetor_v2(vector<string> lista){
    cout << endl <<"INICIO DO VETOR[ |"<< endl;
    for (char i: lista[0]){
        cout << "| "<< i << " |"<<endl;
    }cout << " ]FIM DO VETOR"<<endl;
}

void mostrar_vetor(char *lista,int sizee){
    cout << "\n[ |";
    for (int i = 0; i < sizee; i++){
        cout << lista[i] << " |";
    }cout << " ]\n";
}

int main()
{
    int numero_de_entradas;
    cin >> numero_de_entradas; 
    cin.ignore();
    char numeros[numero_de_entradas];
    for (int i = 0; i < numero_de_entradas; i++){
        char j;
        cin >> j;
        numeros[i] = j;
        cin.ignore();
    }
   /*cout << "\nA entrada foi < ";
    mostrar_vetor(numeros,numero_de_entradas);
    cout << " > \n";*/
    //mostrar_vetor(numeros,numero_de_entradas);//TO PRINTANDO
    vector<string> intervalos_de_distintos(0);
    /*int numero_de_substrings = fatorial_dominoh(numero_de_entradas);
    string numerosv2[numero_de_substrings];*/
    
    string substring = "";
    //int numero_de_substrings = fatorial_dominoh(numero_de_entradas);

    for (int i = 0; i < numero_de_entradas ; i++){
        for (int j = i; j < numero_de_entradas; j++){
            substring += numeros[j];
            intervalos_de_distintos.push_back(substring);
        }substring = "";
    }
    //cout << "***********************************************";
    intervalos_de_distintos = tirar_repetidos(filtrar(not_ha_repetidos,intervalos_de_distintos));
    //mostrar_vetor(intervalos_de_distintos);

    //mostrar_vetor(intervalos_de_distintos);
    int maior = -1;
    for (string atual: intervalos_de_distintos){
        int sizee = atual.length(); 
        if (sizee > maior){
            maior = sizee;
        }
    }cout << maior;
}