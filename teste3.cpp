#include <stdio.h>
#include <iostream>
#include <stdlib.h>

using namespace std;

int main(){
    char *letras;
    letras= (char *) malloc(sizeof(letras)+1);

    gets(letras);

    cout << letras <<"\n";
    free(letras);
    cout << letras <<"\n";
    system("pause");
    return 0;
}