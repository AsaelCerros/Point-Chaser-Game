#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#define LARGOMARCO 24 
#define ANCHOMARCO 80
void marco();
void gotoxy(int x, int y);
void setcolor(int c);

int main(int argc, char const *argv[])
{
	int y, x, xl, yl;
	int xvieja, yvieja;
	char movcarita;
	marco();
	/*Generacion de carita*/
	srand(time(0));
	x=rand() % 77;
	y=rand() % 20;
	xl=rand() % 77;
	yl=rand() % 20;
	
	setcolor(2);
	gotoxy(x,y);
	printf("%c",2);
	/*generacion del lobo*/
	setcolor(4);
	gotoxy(xl, yl);
	printf("%c",190);
	do{
	/*movimiento de la carita*/
	xvieja = x;
	yvieja = y;

	movcarita=getch();
    switch(movcarita)
	{
			case 'w': 
			case 'W':
			 y--; break;
			case 'a':
			case 'A': x--; break;
			case 'S':
			case 's':
			y++; break;
			case 'D':
			case 'd': x++; break;
	}
/*Delimitacion del marco*/
	if(x<3){
		x = 3;
	}

	if(x>(ANCHOMARCO-3)){
		x = ANCHOMARCO-3;
	}

	if(y<2){
		y = 2;
	}

	if(y>LARGOMARCO-1){
		y = LARGOMARCO-1;
	}
	
	gotoxy(xvieja,yvieja);
	printf("%c",0);
	setcolor(2);
	gotoxy(x,y);
	printf("%c",2);
	}while(movcarita!='y');
	gotoxy(1,LARGOMARCO+5);
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
void marco()
{
	int i;
	setcolor(1);
	
	for(i=1;i<ANCHOMARCO;i++){
	gotoxy(i, 1);
	printf("#");}
	
	for(i=1;i<ANCHOMARCO;i++){
	gotoxy(i, 24);
	printf("#");}
	
	for(i=1;i<LARGOMARCO;i++){
	gotoxy(1, i);
	printf("#");}
	
	for(i=1;i<LARGOMARCO;i++){
	gotoxy(79, i);
	printf("#");}
}
