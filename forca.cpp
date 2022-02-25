#include <iostream>
#include <string>
using namespace std;

int main(){
    //variable system
    string word,kword;
    char guess;
    int len,life=3,w=0;
    bool right=false;

    // word that player will guess
    cout<<"whire one word for to start the game: ";
    cin>>word;
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
    while(life>0){
        cout<<"lifes: "<<life<<'\n';
        cout<<kword<<"\n"<<"guess one char :";
        cin>>guess;
        while(w<=len){
            if (word[w]==guess){
                kword[w]=guess;
                right=true;
                cout << guess <<"\n";
                system("pause");
            }
            if (w==len && right==false){
                life-=1;
            }
            w++;
        }
        if (kword==word){
            cout <<"you won!! the word was "<<word<<"\n";
            break;
        }

        //reset system
        w=0;
        right=false;
        system("cls");

    }
    if(life==0){
        cout<<"you lose!!! the word was "<< word<<"\n";
    }
    system("pause");
}