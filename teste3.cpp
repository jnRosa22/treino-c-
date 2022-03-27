#include <stdio.h>
#include <iostream>
#include <stdlib.h>

using namespace std;

void ll();

int main(){
    ll();
    ll();
    return 0;
}
void ll(){
    char *letras;
    letras= (char *) malloc(sizeof(letras)+1);

    gets(letras);
    cout << letras <<"\n";
    free(letras);
    letras=NULL;
    system("pause");
    
}