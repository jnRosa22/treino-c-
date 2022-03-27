/*************************************************************
// text_input
//
//  criado     : 09/03/2022
//  atualizado : 09/03/2022
//  compilador : Visual Studio Code C/C++ Compile Run extension
//
//  descrição  : usando entrada de teclado e mause
//               usando a biblioteca windows.h
***************************************************************/
//cabeçalho
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <iostream>
using namespace std;

//-------------------------------------------------------------
//prototipos de funções 

LRESULT CALLBACK winEvents(HWND,UINT,WPARAM,LPARAM);
char text[64];
unsigned textindex=0;
bool vk_keys[256];
//--------------------------------------------------------------
//programa principal 

int WINAPI WinMain(_In_ HINSTANCE hInstance,_In_opt_ HINSTANCE hPrevInstance,_In_ LPSTR ipCMDLine, int nCMDShow){
    
    HWND hwnd;
    MSG msg;
    WNDCLASSA window={};
    const char *name_class="window";

//definindo classe da janela
    window.lpszClassName=name_class;
    window.hInstance=hInstance;
    window.lpfnWndProc=winEvents;
    window.style=CS_HREDRAW|CS_VREDRAW;
    window.cbClsExtra=0;
    window.cbWndExtra=0;
    window.hIcon=LoadIcon(NULL,IDI_APPLICATION);
    window.hCursor=LoadCursor(NULL,IDC_ARROW);
    window.hbrBackground=GetSysColorBrush(4);
    window.lpszMenuName=NULL;

    RegisterClassA(&window);

    hwnd =CreateWindowA(name_class,
                        "game",
                        WS_OVERLAPPEDWINDOW,
                        GetSystemMetrics(SM_CXSCREEN)/2-GetSystemMetrics(SM_CXSCREEN)/4,
                        GetSystemMetrics(SM_CYSCREEN)/2-GetSystemMetrics(SM_CYSCREEN)/4,
                        GetSystemMetrics(SM_CXSCREEN)/2,
                        GetSystemMetrics(SM_CYSCREEN)/2,
                        NULL,
                        NULL,
                        hInstance,
                        NULL
                        );
    ShowWindow(hwnd,nCMDShow);
    UpdateWindow(hwnd);

    while(GetMessage(&msg,NULL,0,0)){
        TranslateMessage(&msg);
        DispatchMessage(&msg);

    }

    return int(msg.wParam);
}
//-----------------------------------------------------------------
//funções de messagens
LRESULT CALLBACK winEvents (HWND hwnd,UINT message, WPARAM wParam,LPARAM lParam){

    HDC hdc;
    RECT rect;
    PAINTSTRUCT ps;

    switch (message){
    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;

    case WM_PAINT:
        hdc=BeginPaint(hwnd,&ps);
        GetClientRect(hwnd,&rect);
        DrawTextA(hdc,text,-1,&rect,5|7);
        EndPaint(hwnd,&ps);

    case WM_KEYDOWN:
        vk_keys[wParam]=true;
        //InvalidateRect(hwnd,NULL,true);  
        return 0;
    
    case WM_KEYUP:
        vk_keys[wParam]=false;
        //InvalidateRect(hwnd,NULL,true);   
        return 0;
    case WM_CHAR:
        switch (wParam){
            case 8 :
                textindex--;
                text[textindex]='\0';
                InvalidateRect(hwnd,NULL,true); 
                return 0;
            
            default:
                if(textindex<63){
                    text[textindex]=char(wParam);
                    textindex++;
                    InvalidateRect(hwnd,NULL,true); 
                }
            return 0;
        }
    }
    return DefWindowProc(hwnd,message,wParam,lParam);
}
//-------------------------------------------------------------------