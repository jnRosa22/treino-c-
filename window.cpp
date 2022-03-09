/************************************************
// window
// 
// criado:      05/03/2022
// atualização: 08/03/2022
// compilador:  Visual Studio Code C/C++ Compile Run extension 
//
// descrição:   Criação de janelas com suas
//              variações e complementos.
*************************************************/
//adicionando cabeçalho necessario
#define WIN32_LEAN_AND_MEAN
#include <windows.h>

//************************************************

LRESULT CALLBACK WinProc(HWND ,UINT ,WPARAM ,LPARAM );

//------------------------------------------------
//Programa principal

int WINAPI WinMain(_In_ HINSTANCE hInstance,_In_opt_ HINSTANCE hPrevIntance,_In_ LPSTR ipCMDLine,_In_ int nCMDShow ) {

//declaração de variaveis
    HWND hwnd;
    MSG msg;
    WNDCLASSA surface = {};
    const char CLASS_NAME =TEXT('window_cass');
// definindo parametros de classe da janela
    surface.style         = CS_HREDRAW|CS_VREDRAW;
    surface.lpfnWndProc   = WinProc;    
    surface.cbClsExtra    = 0;
    surface.cbClsExtra    = 0;
    surface.hInstance     = hInstance; 
    surface.hbrBackground = GetSysColorBrush(4) ;
    surface.hIcon         = LoadIcon(NULL,IDI_APPLICATION);  
    surface.hCursor       = LoadCursor(NULL,IDC_ARROW);
    surface.lpszMenuName  = NULL;
    surface.lpszClassName = &CLASS_NAME;

    RegisterClassA(&surface);

//criação da janela 
    hwnd = CreateWindowA(&CLASS_NAME,                                                       //classe da janela
                        "system",                                                           //titulo da janela
                        WS_OVERLAPPED|WS_SYSMENU|WS_MAXIMIZEBOX|WS_MINIMIZEBOX,             //estilo da janela
                        GetSystemMetrics(SM_CXSCREEN)/2-GetSystemMetrics(SM_CXSCREEN)/4,    //valor da coordenada X inicial
                        GetSystemMetrics(SM_CYSCREEN)/2-GetSystemMetrics(SM_CYSCREEN)/4,    //valor da coordenada Y inicial
                        GetSystemMetrics(SM_CXSCREEN)/2,                                    //tamanho horizintal da janela
                        GetSystemMetrics(SM_CYSCREEN)/2,                                    //tamanho vertical da janela
                        NULL,                                                               // parentes da janela
                        NULL,
                        hInstance,                                                          //instancia
                        NULL);

    ShowWindow(hwnd,nCMDShow);
    UpdateWindow(hwnd);

    while(GetMessage(&msg,NULL,0,0)){
        TranslateMessage(&msg);
        DispatchMessage(&msg);

    }



    return int(msg.wParam);
}
//--------------------------------------------------
//PROCEDIMENTO DA JANELA
LRESULT CALLBACK WinProc(HWND hwnd ,UINT message,WPARAM wParam,LPARAM lParam){
    HDC hdc;
    PAINTSTRUCT ps;
    RECT rect;
     CONST char *text;

    switch(message){

        case WM_DESTROY:
            PostQuitMessage(0);
            return 0;

        case WM_PAINT:
            hdc = BeginPaint(hwnd,&ps);
            GetClientRect(hwnd,&rect);
            DrawTextA(hdc,text,-1,&rect,DT_SINGLELINE|DT_CENTER|DT_VCENTER);
            EndPaint(hwnd,&ps);
            return 0;
    }
    return DefWindowProc(hwnd,message,wParam,lParam);
}
//--------------------------------------------------