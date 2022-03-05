/************************************************
// window
// 
// criado:      05/03/2022
// atualização: 05/03/2022
// compilador:  ...
//
// descrição:   Criação de janelas com suas
//              variações e complementos.
*************************************************/
//adicionando cabeçalho necessario
#define WIN32_LEAN_AND_MEAN
#include <windows.h>

//************************************************

LRESULT CALLBACK WinProc(HWND ,UINT ,WPARAM ,LPARAM );

//************************************************
//Programa principal

int WINAPI WinMain(_In_ HINSTANCE hInstance,_In_opt_ HINSTANCE hPrevIntance,_In_ LPSTR ipCMDLine,_In_ int nCMDShow ) {

//declaração de variaveis
    HWND hwnd;
    MSG msg;
    WNDCLASSA surface;

// definindo parametros de classe da janela
    surface.style         = CS_HREDRAW|CS_VREDRAW;
    surface.lpfnWndProc   = WinProc;    
    surface.cbClsExtra    = 0;
    surface.cbClsExtra    = 0;
    surface.hInstance     = hInstance; 
    surface.hbrBackground = (HBRUSH) GetSysColorBrush(WHITE_BRUSH);
    surface.hIcon         = LoadIcon(NULL,IDI_APPLICATION);  
    surface.hCursor       = LoadIcon(NULL,IDC_ARROW);
    surface.lpszMenuName  = NULL;
    surface.lpszClassName = "basicwindow";

//criação da janela 
    hwnd=CreateWindowA("basicwindow",         //classe da janela
                       "interface",            //titulo da janela
                       WS_OVERLAPPEDWINDOW,    //estilo da janela
                       CW_USEDEFAULT,
                       CW_USEDEFAULT,
                       CW_USEDEFAULT,
                       CW_USEDEFAULT,
                       NULL,
                       NULL,
                       hInstance,
                       NULL);

    ShowWindow(hwnd,nCMDShow);
    UpdateWindow(hwnd);

    while(GetMessage(&msg,NULL,0,0)){
        TranslateMessage(&msg);
        DispatchMessage(&msg);

    }



    return int(msg.wParam);
}

LRESULT CALLBACK WinProc(HWND hwnd ,UINT message,WPARAM wParam,LPARAM lParam){
    HDC hdc;
    PAINTSTRUCT ps;
    RECT rect;

    switch(message){
        case WM_PAINT:
            hdc = BeginPaint(hwnd,&ps);
            GetClientRect(hwnd,&rect);
            DrawTextA(hdc,"ola mundo",-1,&rect,DT_SINGLELINE|DT_CENTER|DT_VCENTER);
            EndPaint(hwnd,&ps);
            return 0;
    }


    return DefWindowProc(hwnd,message,wParam,lParam);
}