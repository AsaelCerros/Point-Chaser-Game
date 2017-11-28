/*
Equipo 4
Brayan Ricardo Carrete Martínez 307746
Asael David Cerros Domínguez 324603
Daniel Martínez Quinones 313409
Sergio Armando Rodríguez Nava 281854
*/
#include <stdio.h> 
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#define LARGOMARCO 24 
#define ANCHOMARCO 80
//#pragma comment(lib, "winmm.lib")

/*Estructura para la puntuacion de los jugadores*/
typedef struct{
	char nombre[10];
	int puntos;
}pnt; 

/*Declaracion de funciones*/
void portales(int *x,int *y,int *x_enemigo,int *y1,int x_portal1, int y_portal1,int x_portal2, int y_portal2); 
int tocarx(int x, int y, int x_pared, int y_pared[6],char input);
int tocary(int x, int y, int x_pared, int y_pared[6],char input);
void pared_tangible(int *x_pared, int y_pared[6]);
void borrar(int x, int x_enemigo, int y, int y1);
void gotoxy(int x, int y);
double RAND(double min, double max);
int EnemigoX(int x, int x_enemigo);
int EnemigoY(int y, int y_enemigo);
void scoreCrea(int scrm);
void scoreMuestra(void);
void setcolor(int c);
void marco();

//Inicio del juego
int main(int argc, char const *argv[])
{
	//PlaySound(TEXT("Guiles_theme_download.wav"), 0,SND_ASYNC);//cancion en la misma carpeta del programa 
	int y, x, x_enemigo, y_enemigo, x_portal1, y_portal1, y_portal2, x_portal2, input, i, scr=0,scrm=0, color, ranv=65;
	int victoria_1,victoria_2,x_pared, y_pared[6];
	char rank;
	pnt Djugador;
	int xvieja, yvieja;
	int menu, avatar_opc, avatar=2;

	/*Menu del juego*/
	MENU:
	setcolor(10);
	printf("POINT CHASER %c\n", 2);
	setcolor(7);
	avatar=2;
	do{
	printf("1.-Iniciar juego\n2.-Cambiar skin\n3.-Puntuaciones\n4.-Salir\n");
	scanf("%i",&menu);
	switch(menu)
	{
		case 1:/*Inicia el juego con un caracter predefinido*/
		system("cls");	
	    goto inicio;
		break;
		case 2:/*Cambia el caracter del usuario en el juego*/
		{
		system("cls");
		setcolor(10);
		printf("Seleccione su avatar: ");
		setcolor(7);
		printf("\n1)%c\n2)%c\n3)%c\n4)%c\n5)%c\n6)%c\n", 1, 2, 3, 4, 5, 6);
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
		case 3:/*Muestra las puntuaciones*/
		system("cls");
		setcolor(10);
		printf("***TABLA DE PUNTUACIONES***\n");
	    scoreMuestra();
		system("pause");
		system("cls");
		goto MENU;
		break;
		case 4:/*Sale del juego*/
		exit(EXIT_SUCCESS);
		break;
		default:
		printf("Seleccione una opcion valida\n");
		break;

	}
        }while(menu!=1);
	do{
		inicio:
	srand(time(0));//Genera los portales y el punto de victoria en una posicion aleatoria	
	x_portal1=RAND(3,76);
	y_portal1=RAND(3,20);
	x_portal2=RAND(3,76);
	y_portal2=RAND(3,20);
	victoria_1=rand() % 75+3;
	victoria_2=rand() % 19+3;
	ranv=RAND(130,246);
	/*Generacion del jugador y del enemigo de forma aleatoria*/
	srand(time(0));
	x=rand() % 76+2;
	y=rand() % 20+2;
	x_enemigo=rand() % 76+2;
	y_enemigo=rand() % 20+2;
	//Impresion de marco, enemigo y punto de victoria
	system("cls");
	marco();
	setcolor(4);
	gotoxy(x_enemigo, y_enemigo);
	printf("x");
	gotoxy(x, y);
	setcolor(2);
	printf("%c", avatar);
	//Funcion para borrar el trazado
	borrar(x, x_enemigo, y, y_enemigo);
	setcolor(11);
	//Impresion de punto de victoria
	gotoxy(victoria_1,victoria_2);
	printf("%c", ranv);
	setcolor(42);
	pared_tangible(&x_pared, y_pared);
	do{
	    input=getch();
	    setcolor(4);//Impresion del caracter enemigo
	    gotoxy(x_enemigo, y_enemigo);
 	    printf("X");
 	    //Impresion del caracter del jugador
	    setcolor(2);
	    gotoxy(x, y);
	    printf("%c", avatar);
	    borrar(x, x_enemigo, y, y_enemigo);
	    switch(input)
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
			if(x<3)/*Delimitacion del marco: genera un espacio fisico para que el jugador no pueda cruzar el marco*/
			{		
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
		//inicializa la funcion para perseguir al jugador
	    setcolor(4);
	    x_enemigo=EnemigoX(x, x_enemigo);
	    y_enemigo=EnemigoY(y, y_enemigo);
	    gotoxy(x_enemigo, y_enemigo);
	    printf("X");
	    setcolor(2);
	    //Inicializa la funcion de los portales.
	    portales(&x,&y,&x_enemigo,&y_enemigo,x_portal1,y_portal1,x_portal2,y_portal2);
		gotoxy(x, y);
	    printf("%c", avatar);
	    //Funciones para tocar la pared.
		x=tocarx(x, y, x_pared, y_pared,input);
		y=tocary(x, y, x_pared, y_pared,input);
		gotoxy(x, y);
		setcolor(2);
	    printf("%c", avatar);
	    //Impresion de portales.
	    setcolor(9);
	    gotoxy(x_portal1, y_portal1);
	    printf("%c", 21);
	    setcolor(7);
	    gotoxy(x_portal2, y_portal2);
	    printf("%c", 21);
	    printf("%c", 0);
	    if(x==victoria_1&&y==victoria_2)//Condiciones de victoria
	    {
	    system("cls");
		scr++;//Suma un punto cada vez que se pasa de nivel
		printf("+1 punto iniciar siguiente LVL %d\n",scr+1);
		system("pause");
		goto inicio;	
		}
		for(i=1;i<6;i++)
		{
		y_pared[i]=y_pared[0]+i;
		gotoxy(x_pared, y_pared[i]);
		printf("%c", 16);
	    }
	}while(x!=x_enemigo||y!=y_enemigo);//Condiciones de derrota
	system("pause");
	system("cls");
	printf("Desea Guardar Su Puntuacion(Y/n): ");//Guardar y mostrar puntuacion
	rank=getch();
	if(rank=='y'||rank=='y')
	{
	scrm=scr;
	scoreCrea(scrm);
	scoreMuestra();
	 rank=NULL;
    }
	printf("\nUsted perdio puntuacion mas alta: %d\nDesea reiniciar el juego(Y/n): ",scr);
	Djugador.puntos=scr;
	scr=0;
	input=getche();
	
   }while(input!='n');
	return 0;
}
//Funciones del juego
void gotoxy(int x, int y)//Funcion para posicionar el cursor en coordenadas especificas
{
    HANDLE hConsola;
    COORD dwPos;
    dwPos.X = x;
    dwPos.Y = y;
    hConsola = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hConsola,dwPos);
    
    
}
void setcolor(int c)//Funcion para cambiar el color del texto
{
	HANDLE hConsola;
    hConsola = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsola,c);
	
}
void marco()//Funcion para generar el marco del juego
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
void borrar(int x, int x_enemigo, int y, int y_enemigo)//Funcion para borrar el trazado del jugador y el enemigo
{
	gotoxy(x, y);
	printf("%c", 0);
	
	gotoxy(x_enemigo, y_enemigo);
	printf("%c", 0);
	
}
int EnemigoX(int x, int x_enemigo)//Funcion que hace que el enemigo persiga al jugador en x
{
	if(x_enemigo < x)
	{
		x_enemigo++;
	}
	
	if(x_enemigo > x)
	{
		x_enemigo--;
	}
	return x_enemigo;
}
int EnemigoY(int y, int y_enemigo)//Funcion que hace que el enemigo persiga al jugador en y
{
	if(y_enemigo < y)
	{
		y_enemigo++;
	}
	
	if(y_enemigo > y)
	{
		y_enemigo--;
	}
	return y_enemigo;
}
//Funcion que transporta al jugador y al enemigo entre portales.
void portales(int *x,int *y,int *x_enemigo,int *y_enemigo,int x_portal1, int y_portal1,int x_portal2, int y_portal2)
{
	if(*x==x_portal1&&*y==y_portal1)
	{
		*x=x_portal2;
		*y=y_portal2;
	}
	else if(*x==x_portal2&&*y==y_portal2)
	{
		*x=x_portal1;
		*y=y_portal1;
	}
	else if(*x_enemigo==x_portal2&&*y_enemigo==y_portal2)
	{
		*x_enemigo=x_portal1;
		*y_enemigo=y_portal1;
	}
	else if(*x_enemigo==x_portal1&&*y_enemigo==y_portal1)
	{
		*x_enemigo=x_portal2;
		*y_enemigo=y_portal2;
	}
	
	
}
void pared_tangible(int *x_pared, int y_pared[6])//Funcion que genera un muro para frenar a el jugador
{
	int i;
	*x_pared=rand()%70;
	y_pared[0]=rand()%14;
	gotoxy(*x_pared, y_pared[0]);
	printf("%c", 16);
	for(i=1;i<6;i++)
	{
		y_pared[i]=y_pared[0]+i;
		gotoxy(*x_pared, y_pared[i]);
		printf("%c", 16);
	}
}
int tocarx(int x, int y, int x_pared, int y_pared[6],char input)//Funcion para tocar el muro en x
{
	int i;
	for(i=0;i<7;i++)
	{
		if(x==x_pared && y==y_pared[i])
		switch(input)
	    {
		
		  case 'd':
		  	    x--;
		  	    break;
		  case 'a':
		  	    x++;
				break;
	    }
	}
		return x;
}
int tocary(int x, int y, int x_pared, int y_pared[6],char input)//Funcion para tocar el muro en y
{
	int i;
	for(i=0;i<7;i++)
	{
		if(x==x_pared && y==y_pared[i])
		switch(input)
	    {
		  case 's':
		  	    y--;
		  	    break;
		  case 'w':
		        y++;
			    break;	
     	}
	}
		return y;
}
void scoreCrea(int scrm)//Crea un archivo que contiene las puntuaciones de los jugadores
{
	FILE *arch;
	pnt jugador;
	    arch= fopen("Score.dat","ab");
	    if(arch!=NULL)
	    {	 	
	 	printf("\nNombre del jugador: ");
	 	fflush(stdin);
	 	gets(jugador.nombre);
	 	jugador.puntos=scrm;
	 	fwrite(&jugador,sizeof(pnt),1,arch);
		fclose(arch);
	    }
}
void scoreMuestra(void)//Muestra el archivo con las puntuaciones de los jugadores
{
    FILE *arch;
    pnt jugador;
	arch=fopen("Score.dat","rb");
	if(arch!=NULL)
	{
		while(!feof(arch))
		{
		fread(&jugador,sizeof(pnt),1,arch);	
		if(!feof(arch))
		setcolor(7);
		printf("%s puntos:%d\n",jugador.nombre,jugador.puntos);
	}
	fclose(arch);	
	}
}
double RAND(double min, double max)//Funcion para generar numeros aleatorios dentro de un rango
{
    return (double)rand()/(double)RAND_MAX * (max - min) + min;
}
