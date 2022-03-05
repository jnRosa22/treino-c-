/******************************************************
/ testes com a biblioteca windows.h
/ fora do winmain()
/
/
/
********************************************************/
#include<windows.h>
#include <iostream>
#include<sstream>
#define WIN32_LEAN_AND_MEAN

using namespace std;
using std:: stringstream;
//-----------------------------------------------------

void audio(){
    Beep(77700,45);
    Beep(7070,45);
    int cxscreen=GetSystemMetrics(SM_CXSCREEN);
    cout <<"\n\n\n\n"<< cxscreen<<"\n\n\n\n\n";
   int resp= MessageBoxA(NULL,"ola mundo","messagem",100);
    if(resp==IDYES){
        MessageBoxA(NULL,"oi","menssagem",0);
    }

}

int main(){
    MSG msg;
    cout << "começou";
    audio();
    cout << "terminou";
    return 0;
}