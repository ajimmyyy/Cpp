#include <iostream>
#include <conio.h>
#include <windows.h>

using namespace std;
int main()
{
    int ch,x=720;
    HDC hdc = ::GetDC(NULL);
    int pixel;
    cout<<"enter to start"<<endl;
    while(1){
        if(_kbhit()){
            ch=_getch();
            if(ch==13){
                break;
            }
        }
    }
    //按下enter開始
    for(int i=0;i<4;i++){
        SetCursorPos (x,700);
        pixel = GetPixel(hdc, x, 700);
        mouse_event(MOUSEEVENTF_LEFTDOWN|MOUSEEVENTF_LEFTUP,0,0,0,0);
        x=x+140;
        Sleep(100);
    }
    //點擊初始的方塊
    while(1){
        x=720;
        for(int i=0;i<4;i++){
            SetCursorPos (x,700);
            pixel = GetPixel(hdc, x, 700);
            if(_kbhit()){
            	ch=_getch();
            	if(ch==13){
                	break;
            	}
        	}
            else if(pixel<=131328){
                mouse_event(MOUSEEVENTF_LEFTDOWN|MOUSEEVENTF_LEFTUP,0,0,0,0);
        	}

        	x+=140;
        }
    }
    //判定方塊是否為黑色
    return 0;
}
