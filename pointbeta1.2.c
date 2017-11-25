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
	int menu, avatar_opc, avatar;
	/*Menu del juego*/
	do{
	printf("1.-Iniciar juego\n2.-Cambiar skin\n3.-Puntuaciones\n4.-Salir\n");
	scanf("%i",&menu);
	switch(menu)
	{
		case 1:/*Inicia el juego con un caracter predefinido*/
		avatar=2;
		system("cls");	
	    goto start;
		break;
		case 2:/*Cambia el caracter del usuario en el juego*/
		{
		system("cls");
		printf("Seleccione su avatar:\n1)%c\n2)%c\n3)%c\n4)%c\n5)%c\n6)%c\n", 1, 2, 3, 4, 5, 6);
		scanf("%i",&avatar_opc);
		switch(avatar_opc)
		{
			case 1:
			avatar=1;
			system("cls");
			break;
			case 2:
			avatar=2;
			system("cls");
			break;
			case 3:
			avatar=3;
			system("cls");
			break;
			case 4:
			avatar=4;
			system("cls");
			break;
			case 5:
			avatar=5;
			system("cls");
			break;
			case 6:
			avatar=6;
			system("cls");
			break;
			default:
			printf("Opcion invalida\n");
			break;
		}

	    }
		break;
		case 3:
		system("cls");
		printf("Puntuaciones\nJugador1 1900\nJugador2 1231\n");/*Muestra las puntuaciones TEST*/
		system("pause");
		system("cls");	
		break;
		case 4:
		exit(EXIT_SUCCESS);/*Sale del juego*/
		break;
		default:
		printf("Seleccione una opcion valida");
		break;



	}
        }while(menu!=1);	
	start:
	marco();
	/*Generacion del jugador de forma aleatoria*/
	srand(time(0));
	x=rand() % 77;
	y=rand() % 20;
	xl=rand() % 77;
	yl=rand() % 20;
	
	setcolor(2);
	gotoxy(x,y);
	printf("%c",avatar);
	/*generacion del enemigo de forma aleatoria*/
	setcolor(4);
	gotoxy(xl, yl);
	printf("%c",190);
	do{
	/*movimiento del jugador*/
	xvieja = x;
	yvieja = y;

	movcarita=getch();
    switch(movcarita)/*Controles del jugador usando las letras: W A S D*/
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
/*Delimitacion del marco: genera un espacio fisico para que el jugador no pueda cruzar el marco*/
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
	printf("%c",avatar);
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
