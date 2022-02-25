#include <iostream>
using namespace std;

int main(){
    bool loop=true;
    int var = 0;
    int resposta;
    string cont;
    system("color 0a");
    while(loop){
        cout << "----------------\n"<< "SOMA DE NUMEROS\n"<< "----------------\n";
        cout << "digite um numero: ";
        cin>>resposta;
        var= var + resposta;

        while(true){
            cout << "\nainda quer continuar?[s/n] ";
            cin >> cont;
            cout << "\n";
            if (cont=="s"){
                system("cls");
                break;
            }else if (cont=="n"){
                loop=false;
                break;
            }else{
                cout << "Valor de Resposta incorreto, por favor digite novamente\n";
            }
        }
        
    }
    cout<< "a soma de todos os numeros foi "<< var <<"\n";
    system("pause");
    return 0;
};
