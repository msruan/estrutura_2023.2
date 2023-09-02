#include <iostream>
#include <string>
using namespace std;
int main(){
    int num_letras_palavra1;
    cin >> num_letras_palavra1;
    string palavra1;
    cin >> palavra1;
    int num_letras_palavra2;
    cin >> num_letras_palavra2;
    string palavra2;
    cin >> palavra2;
    int i;
    int menor = num_letras_palavra2 < num_letras_palavra1 ? num_letras_palavra1 : num_letras_palavra2;
    for (i = 0; i < menor; i++){
        if (not(palavra1[i] == palavra2[i]))
            break;
    }
    cout << i;
}