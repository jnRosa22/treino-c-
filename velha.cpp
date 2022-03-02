#include <iostream>

using namespace std;

char matriz[3][3];
int player;

void draw();
void player1();
void player2();
void scan();

int main(){
    player=0;
    //game loop
    while(true){
        //draw game
        draw();

        //player1 command
        player1();
        draw();

        //scan
        scan();
        if(player>0){
            cout<<"player "<<player<<" venceu \n";
            system("pause");
            break;
        }

        //player2 command
        player2();
        draw();

        //scan
        scan();
        if(player>0){
            cout<<"player "<<player<<" venceu \n";
            system("pause");
            break;
        }
        system("cls");
    }
}
void draw(){
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if (matriz[i][j]=='\0'){
                matriz[i][j]=' ';
            }
        }
    }
    cout <<"\n"<<matriz[0][0]<<"|"<<matriz[0][1]<<"|"<< matriz[0][2]<<"\n";
    cout <<"-----"<<"\n";
    cout <<matriz[1][0]<<"|"<<matriz[1][1]<<"|"<< matriz[1][2]<<"\n";
    cout <<"-----"<<"\n";
    cout <<matriz[2][0]<<"|"<<matriz[2][1]<<"|"<< matriz[2][2]<<"\n\n";
}
void player1(){
    cout<<"player1 move\n";
    int x;
    int y;
    cout << "row";
    cin>> x;
    cout << "column";
    cin>> y;
    if(matriz[x-1][y-1]==' '){
        matriz[x-1][y-1]='x';
    }else{
        cout << "local ja usado\n";
        player1();
    }
}
void player2(){
    cout<<"player2 move\n";
    int x;
    int y;
    cout << "row";
    cin>> x;
    cout << "column";
    cin>> y;

    if(matriz[x-1][y-1]==' '){
        matriz[x-1][y-1]='o';
    }else{
        cout << "local ja usado\n";
        player2();
    }
}
void scan(){

    for(int i=0;i<3;i++){
        //scan playyer 1
        if(matriz[i][i]=='x'){
            if(matriz[0][i]==matriz[1][i]&&matriz[1][i]==matriz[2][i]){
                player=1;
            }
            if(matriz[i][0]==matriz[i][1]&&matriz[i][0]==matriz[i][2]){
                player=1;
            }
            if(matriz[i+1][i+1]==matriz[i][i]&&matriz[i-1][i-1]==matriz[i][i]){
                player=1;
            }
            if(matriz[i-1][i+1]==matriz[i][i]&&matriz[i+1][i-1]==matriz[i][i]){
                player=1;
            }
        }
        //scan playyer 2
        if(matriz[i][i]=='o'){
            if(matriz[0][i]==matriz[1][i]&&matriz[1][i]==matriz[2][i]){
                player=2;
            }
            if(matriz[i][0]==matriz[i][1]&&matriz[i][0]==matriz[i][2]){
                player=2;
            }
            if(matriz[i+1][i+1]==matriz[i][i]&&matriz[i-1][i-1]==matriz[i][i]){
                player=2;
            }
            if(matriz[i-1][i+1]==matriz[i][i]&&matriz[i+1][i-1]==matriz[i][i]){
                player=2;
            }
        }
    }
}