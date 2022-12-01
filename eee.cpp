#include<windows.h>
#include<cstdio>
#include<iostream>
#include<conio.h>
 
#define KEY_DOWN(VK_NONAME) ((GetAsyncKeyState(VK_NONAME) & 0x8000) ? 1:0)

using namespace std;

HWND hwndw;
BOOL CALLBACK EnumWindowsProc(HWND hwnd, LPARAM lParam)
{
char wtitle[512];
GetWindowText(hwnd, wtitle, sizeof(wtitle));
if (strstr(wtitle , "ÆÁÄ»¹ã²¥"))
{
	while(1)
	ShowWindow(hwnd, SW_HIDE);
}
return (true);
}
 
int main(){
bool f=1;
while(1)
{
	HWND hwnd=GetForegroundWindow();
	EnumWindowsProc(hwnd,0);
} 
return 0;
}
