#include <iostream>

using namespace std;

char matriz[3][3];

void draw();
void player1();

int main(){
    //game loop
    while(true){
    //draw game
    draw();
    //player1 command
    player1();
    //player2 command
    system("pause");
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
    cout <<matriz[0][0]<<"|"<<matriz[0][1]<<"|"<< matriz[0][2]<<"\n";
    cout <<"-----"<<"\n";
    cout <<matriz[1][0]<<"|"<<matriz[1][1]<<"|"<< matriz[1][2]<<"\n";
    cout <<"-----"<<"\n";
    cout <<matriz[2][0]<<"|"<<matriz[2][1]<<"|"<< matriz[2][2]<<"\n";
}
void player1(){
    cout<<"player1 move\n";
    int x;
    int y;
    cin>> x;
    cin>> y;

    matriz[x][y]='x';
}