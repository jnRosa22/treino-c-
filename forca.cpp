#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
string kword;
char guess,*word;
int len,life=3,w=0;



void analyze_word();
void analyze_char();

int main(){
    word=(char*)malloc(sizeof(word)+1);
    // word that player will guess
    cout<<"write a word to start the game: ";
    gets(word);
    analyze_word();
    while(life>0){
        cout<<"lifes: "<<life<<'\n';
        cout<<kword<<"\n"<<"guess one char :";
        cin>>guess;
        analyze_char();
        if (kword==word){
            cout <<"\nyou won!! the word was "<<word<<"\n";
            free(word);
            break;
        }

        //reset system
        w=0;
        system("cls");

    }
    if(life==0){
        cout<<"\nyou lose!!! the word was "<< word<<"\n";
    }
    system("pause");
}
void analyze_word(){
        for(int j,i=0;i<30;i++){
        if (word[i]!='\0'){
            continue;
        }else{
            len=i-1;
            while(j<i){
                kword+='-';
                j++;
            }
            break;   
        }
    }
}
void analyze_char(){
    bool right;
    while(w<=len){
        if (word[w]==guess){
            kword[w]=guess;
            right=true;
        }
        if (w==len && right==false){
            life-=1;
        }
            w++;
    }
    right=false;
}