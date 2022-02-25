#include <iostream>
using namespace std;
#define pi cout << 3.1415;

int main(){
    int num=3;
    char letra='g';
    string nome="juan";
    float decimal=3.5;
    double decais=3.3;
    bool binario=true;
    cout <<"digite um nome: ";
    cin >> num;
    cout << "nome: "<< &num <<"\n";
    cout << &++num <<"\n";



    system("pause");
    return 0;
}
