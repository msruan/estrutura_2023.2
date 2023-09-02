#include <iostream>
#include <string>
using namespace std;
string input(string label);
string f1;
string f2;
void print (string label){
    cout << label;
}
int main(){
    f1 = input("Digite a primeira string: ");
    f2 = input("Digite a segunda string: ");
    bool sao_iguais = f1.compare(f2) ? 0: 1;
    cout << sao_iguais;
}
string input(string label){
    print(label);
    string auxiliar;
    cin >> auxiliar;
    return auxiliar;
}