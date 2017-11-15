#include <stdio.h> 
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <conio.h> 

void borrar(int x, int x1, int y, int y1);
int objetos(int x, int y, int xp1, int yp1, int xp2, int yp2);
void marcox();
int borrar_x(int x);
int lobox(int x, int x1);
int loboy(int y, int y1);
void gotoxy(int x, int y);
void setcolor(int c);
int main(int argc, char const *argv[])
{
	int y, x, x1, y1, xp1, yp1, yp2, xp2, r;
	int obj[3];
	int b;
	int l;
	do{
	srand(time(0));
	x=rand() % 79;
	y=rand() % 24;
	x1=rand() % 79;
	y1=rand() % 24;
	xp1=rand() % 75;
	yp1=rand() % 22;
	xp2=rand() % 75;
	yp2=rand() % 22;	
	system("cls");
	setcolor(4);
	gotoxy(x1, y1);
	printf("X");
	gotoxy(x, y);
	setcolor(2);
	printf("%c", 2);
	gotoxy(xp1, yp1);
	printf("°");
	gotoxy(xp2, yp2);
	printf("°");
	borrar(x, x1, y, y1);
	marcox();
	do{
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
	    /*x1=lobox(x, x1);
	    y1=loboy(y, y1);
	    b=portal(x,y, xp1, yp1, xp2, yp2);*/
	    if(x1==xp1 && y1==yp1){
	    	switch(b){
	    		case 'a':
	    			x1=xp2+1;
	    			y1=yp2; break;
	    		case 'b':
	    			x1=xp2;
	    			y1=yp2+1; break;
	    		case 'c':
	    			x1==xp2-1;
	    			y1=yp2; break;
	    		case 'd':
	    			x1=xp2;
	    			y1=yp2-1; break;
	    		default:
	    			x1=xp2;
	    			y1=yp2; break;
			}
		}
	    gotoxy(x1, y1);
	    printf("X");
	    b=objetos(x, y, xp1, yp1, xp2, yp2);
	    setcolor(2);
	    if(x==xp1 && y==yp1){
	    	switch(b){
	    		case 'a':
	    			x=xp2+1;
	    			y=yp2; break;
	    		case 'b':
	    			x=xp2;
	    			y=yp2+1; break;
	    		case 'c':
	    			x==xp2-1;
	    			y=yp2; break;
	    		case 'd':
	    			x=xp2;
	    			y=yp2-1; break;
	    		default:
	    			x=xp2;
	    			y=yp2; break;
			}
		}
		gotoxy(x, y);
	    printf("%c", 2);
		if(x==xp2 && y==yp2){
	    	switch(b){
	    		case 'a':
	    			x=xp1+1;
	    			y=yp1; break;
	    		case 'b':
	    			x=xp1;
	    			y=yp1+1; break;
	    		case 'c':
	    			x==xp1-1;
	    			y=yp1; break;
	    		case 'd':
	    			x=xp1;
	    			y=yp1-1; break;
	    		default:
	    			x=xp1;
	    			y=yp1; break;
			}
		}
		if(x<2){
			x++;
		}
		if(x>79){
			x--;
		}
		if(y<2){
			y++;
		}
		if(y>23){
			y--;
		}
		gotoxy(x, y);
		setcolor(4);
	    printf("%c", 2);
	    gotoxy(xp1, yp1);
	    printf("°");
	    setcolor(2);
	    gotoxy(xp2, yp2);
	    printf("°");
	    printf("%c", 0);
	}while(x!=x1 || y!=y1);
	printf("Desea reiniciar el juego(Y/n)");
	r=getche();
   }while(r!='n');
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
	
	gotoxy(x1+1, y1);
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
int objetos(int x, int y, int xp1, int yp1, int xp2, int yp2){
	char b;
	if(x==xp1-1 && y==yp1){
		b='a';
	}
	if(x==xp1+1 && y==yp1){
		b='c';
	}
	if(x==xp1 && y==yp1-1){
		b='b';
	}
	if(x==xp1 && y==yp1+1){
		b='d';
	}
	if(x==xp2-1 && y==yp2){
		b='a';
	}
	if(x==xp2+1 && y==yp2){
		b='c';
	}
	if(x==xp2 && y==yp2-1){
		b='b';
	}
	if(x==xp2 && y==yp2+1){
		b='d';
	}
	return b;
}
