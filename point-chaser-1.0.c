#include <stdio.h> 
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <conio.h> 

void borrar(int x, int x1, int y, int y1);
void portal();
void marcox();
int borrar_x(int x);
int lobox(int x, int x1);
int loboy(int y, int y1);
void gotoxy(int x, int y);
void setcolor(int c);
int main(int argc, char const *argv[])
{
	int y, x, x1, y1, r;
	int obj[3];
	int *b;
	
	srand(time(0));
	x=rand() % 79;
	y=rand() % 24;
	x1=rand() % 79;
	y1=rand() % 24;
	
	system("cls");
	setcolor(4);
	gotoxy(x1, y1);
	printf("X");
	
	portal();
	gotoxy(x, y);
	setcolor(2);
	printf("%c", 2);
	
	borrar(x, x1, y, y1);
	marcox();
	do
	{
	    r=getche();
	    setcolor(4);
	    gotoxy(x1, y1);
 	    printf("X");
	    
	    gotoxy(x, y);
	    setcolor(2);
	    printf("%c", 2);
	    
	    borrar(x, x1, y, y1);
	    switch(r)
		{
			case 'w': 
			case 'W': y--; break;
			case 'a':
			case 'A': x--; break;
			case 'S':
			case 's': y++; break;
			case 'D':
			case 'd': x++; break;
		}
	    setcolor(4);
	    x1=lobox(x, x1);
	    y1=loboy(y, y1);
	    gotoxy(x1, y1);
	    printf("X");
	    
	    setcolor(2);
	    gotoxy(x, y);
	    printf("%c", 2);
	
	}while(x!=x1 || y!=y1);

	return 0;
}
void gotoxy(int x, int y)
{
    HANDLE hConsola;
    COORD dwPos;
    dwPos.X = x;
    dwPos.Y = y;
    hConsola = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hConsola,dwPos);
    
    
}
void setcolor(int c)
{
	HANDLE hConsola;
    hConsola = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsola,c);
	
}
void marcox(){
	int i;
	setcolor(1);
	
	for(i=1;i<80;i++){
	gotoxy(i, 1);
	printf("#");}
	
	for(i=1;i<80;i++){
	gotoxy(i, 24);
	printf("#");}
	
	for(i=1;i<24;i++){
	gotoxy(1, i);
	printf("#");}
	
	for(i=1;i<24;i++){
	gotoxy(79, i);
	printf("#");}
}
void borrar(int x, int x1, int y, int y1){
	gotoxy(x, y);
	printf("%c", 0);
	
	gotoxy(x+1, y);
	printf("%c", 0);
	
	gotoxy(x1, y1);
	printf("%c", 0);
	
	gotoxy(x1-1, y1);
	printf("%c", 0);
	
	gotoxy(x1, y1-1);
	printf("%c", 0);
	
	gotoxy(x1, y1+1);
	printf("%c", 0);
}
int lobox(int x, int x1){
	if(x1 < x)
	{
		x1++;
	}
	
	if(x1 > x)
	{
		x1--;
	}
	return x1;
}
int loboy(int y, int y1){
	if(y1 < y)
	{
		y1++;
	}
	
	if(y1 > y)
	{
		y1--;
	}
	return y1;
}
void portal()
{
  int x,y;
  setcolor(5);
  x=rand() % 79;
  y=rand() % 24;
  gotoxy(x,y);
  printf("%c",176);
  
  setcolor(5);
  x=rand() % 79;
  y=rand() % 24;
  gotoxy(x,y);
  printf("%c",176);		
}
