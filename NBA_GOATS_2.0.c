#include <stdio.h>
#include <stdlib.h>


//Estas son las distintas funciones que usamos a lo largo del programa
void menu();
void allstar();
void infojugadoreseste();
void infojugadoresoeste();
void playoffs();


// En primer lugar estan definidas tres estructuras, una la usamos para almacenar los equipos, otra para los datos de cada jugador y la ultima sirve para el registro de usuarios
typedef struct{
	char nombre[50];
}equipos;

typedef struct{
	char nombre[500];
	char posicion[500];
	char equipo[500];
	float puntos;
	float asistencias;
	float rebotes;
}jugador;

struct registro{
	char usuario[50],contrasena[100];
};


//Desarollo principal del programa
int main(){
	
	//USAMOS ESTA FUNCION PARA APLICAR A LA INTERFAZ DEL PROGRAMA LOS COLORES DESEADOS
    system("color 3f"); 
    
    
    //Declaracion de las variables utilizadas a lo largo del programa
	int  i,w,equipo,conf,xx,cc; 
	int  opcion, ok=0, error=0, y=0, exit ,j;
	char contrasena[20], usu[100];
	
	
	//Definicion de los de los punteros
	FILE *pf;
	FILE *pe;
	FILE *po;
	FILE *pj;
	FILE *pn;
	
	
   //Aqui definimos el vector que almacena el nombre de los equipos
	equipos cole[50];

	
    // Aqui definimos la estructura de registro de usuarios
	struct registro usuario[100];

	
	
	printf("                                    ********************************************\n");
	printf("                                    *                                          *\n");
	printf("                                    *        NNN    NN   BBBB     AAAAAA       *\n");
	printf("                                    *        NN N   NN   BB  BB   AA  AA       *\n");
	printf("                                    *        NN  N  NN   BBBB     AAAAAA       *\n");
	printf("                                    *        NN   N NN   BB  BB   AA  AA       *\n");
	printf("                                    *        NN    NNN   BBBB     AA  AA       *\n");
	printf("                                    *                                          *\n");
	printf("                                    *  GGGGGG   OOOOO   AAAAAA  TTTTTT  SSSSS  *\n");
	printf("                                    *  GG       OO OO   AA  AA    TT    S      *\n");
	printf("                                    *  GG GGG   OO OO   AAAAAA    TT    SSSSS  *\n");
	printf("                                    *  GG  GG   OO OO   AA  AA    TT        S  *\n");
	printf("                                    *  GGGGGG   OOOOO   AA  AA    TT    SSSSS  *\n");
	printf("                                    *                                          *\n");
	printf("                                    ********************************************\n");
	printf("\n\n                                      -Bienvenidos al mejor programa de la NBA-\n\n");
	
   
		pn = fopen("usuarios.txt","r");
	if (pn == NULL){ 
		printf("No se encuentra fichero");
		return 0;
		}
y=0;
	
	
	
	
 //Inicio programa es un printf que muestra en la pantalla las distintas opciones para continuar	
	do {
 		printf ("SELECCIONE UNA DE LAS SIGUIENTES OPCIONES \n\n");
		printf ("1-REGISTRARSE \n\n");
		printf ("2-INICIAR SESION \n\n");
		scanf("%d", &opcion);
		system ("cls");
		}
	while (opcion > 2 || opcion <=0);
	
	
	
	//SWITCH CASE para elegir una de las dos opciones
	switch (opcion){
		case 1: 
		
			system ("cls"); // Borra todo lo anterior
				printf("Listo para registrarse? \n");
				printf("Introduzca su nombre de usuario: \n");
			fflush (stdin);
				gets(usuario[y].usuario);
			fflush (stdin);
				printf("Introduzca la contrasena deseada: \n");
				gets(usuario[y].contrasena);
				printf("Se ha registrado correctamente ;D\n");
			
			
			//Arimos un fichero para guardar los usuarios y sus respectivas conntraseñas
			pn = fopen("usuarios.txt","w");
				if (pn == NULL)
					{ 
						printf("No se encuentra fichero");
						return 0;
					}
				for(i=0;i<=y;i++)
					{
						fprintf(pn, "%s %s\n", usuario[i].usuario,usuario[i].contrasena);
					}
			fclose(pn);
			system("CLS()");
			
				error=0;
			do{
				if(error!=0){
					system ("cls");
					printf("ERROR AL INICIAR SESION\n");
					printf("EL CORREO Y LA CONTRASENA NO COINCIDEN, INTENTELO DE NUEVO:\n");
					printf("PARA REINTENTAR PULSE R\n");
					printf("PARA ABANDONAR EL PROGRAMA PULSE 1\n");
					
					
					scanf("%d",&exit);
					if(exit==1){
						return 0;
						break;
					}
				}
				else{printf("INICIA TU SESION \n");
				}
			fflush (stdin);
			printf("Introduzca su nombre de usuario:\n");
			gets(usu);
			fflush (stdin);
			printf("Introduzca la contrasena:\n");
			gets(contrasena);
			
			////Con este bucle se comprueba que el usuario y la contraseña son correctos:
			for(j=0;j<=y;j++){
				ok=0;
				if(strcmp(usu,usuario[j].usuario)==0)
				ok++;
				if(strcmp(contrasena,usuario[j].contrasena)==0)
				ok++;
				if(ok==2)
				break;
			}
			error++;
			}
			while(ok!=2);
			
			
			system ("cls");
			printf ("Cargando...., ha iniciado sesion correctamente '%s':\n\n\n", usuario[j].usuario);
			menu();
			
		
			
		break;

	case 2: 
				//Arimos un fichero para buscar los usuarios y sus respectivas contraseñas
			pn = fopen("usuarios.txt","r");
				if (pn == NULL)
					{ 
						printf("No se encuentra fichero");
						return 0;
					}
				for(i=0;i<=y;i++)
					{
						fscanf(pn, "%s %s\n", usuario[i].usuario,usuario[i].contrasena);
					}
			fclose(pn);
			
			system("CLS()");
			
				error=0;
			do{
				if(error!=0){
					system ("cls");
					printf("ERROR AL INICIAR SESION\n");
					printf("EL CORREO Y LA CONTRASENA NO COINCIDEN, INTENTELO DE NUEVO:\n");
					printf("PARA REINTENTAR PULSE R\n");
					printf("PARA ABANDONAR EL PROGRAMA PULSE 1\n");
					
					
					scanf("%d",&exit);
					if(exit==1){
						return 0;
						break;
					}
				}
				else{printf("INICIA TU SESION \n");
				}
			fflush (stdin);
			printf("Introduzca su nombre de usuario:\n");
			gets(usu);
			fflush (stdin);
			printf("Introduzca la contrasena:\n");
			gets(contrasena);
			
			
			//Con este bucle se comprueba que el usuario y la contraseña son correctos:
			for(j=0;j<=y;j++){
				ok=0;
				if(strcmp(usu,usuario[j].usuario)==0)
				ok++;
				if(strcmp(contrasena,usuario[j].contrasena)==0)
				ok++;
				if(ok==2)
				break;
			}
			error++;
			}
			while(ok!=2);
			
			system ("cls");
			printf ("Cargando...., ha iniciado sesion correctamente '%s':\n\n\n", usuario[j].usuario);
			menu();
	
	
	return 0;
	}
			
			system("PAUSE()");}


	
// la funcion menu nos permite poder reiniciar el programa desde e menu cada vez que tenemos la opcion	
void menu(){
  //Declaracion de las variables utilizadas a lo largo del programa
	int  eleccion,i,w,equipo,conf,xx,cc; 
	int  opcion, ok=0, error=0, y=0, exit ,j;
	char contrasena[20], usu[100];
	
	
	//Definicion de los de los punteros
	FILE *pf;
	FILE *pe;
	FILE *po;
	FILE *pj;
	FILE *pn;
	
	
   //Aqui definimos el vector que almacena el nombre de los equipos
	equipos cole[50];
	
	
			
			do {
	printf("Elige una opcion para continuar:\n");
	printf("1. Jugadores por equipo\n");
	printf("2. Rellena tu bracket de los playoffs\n");
	printf("3. Elige tus premios all star\n");
	printf("4. Salir del programa\n\n");
	scanf("%d", &eleccion);//Con este scanf se recoge la variable que expresa que eleccion hace el usuario
	}while (eleccion > 4 || eleccion <=0);
	
	//Este switch case es el que redirige al usuario a su opcion deseada dependendo del numero que haya introducido

	switch (eleccion){
		case 1:// el case 1 es la primera opcion del menu despues de elegirla se le vuelve a pedir al usuario que elija opcion
			system ("cls"); // Borra todo lo anterior
			printf("Vamos a buscar a tu jugador favorito!\n");
			
			//En este do while el usuario intoduce una de las dos opciones este u oeste, o si no se las vuelve a pedir
			do{ system ("cls");
				printf("Te vamos a mostar las dos conferencias que hay en la NBA, cada una con 15 equipos\n");
				printf("Elige una de las dos:\n(1)Oeste\n(2)Este\n(3)Regresar al menu\n");
				scanf("%d", &conf);
			}while (conf < 1 || conf>3);
			
			system ("cls"); // Borra todo lo anterior
			printf("Bien! Ahora te vamos a mostar los equipos de la conferencia escogida\n");
	
			// En este switch case en fucion de la variable introducida ejecuta el caso del este o del oeste
			switch (conf){
				case 1: 
					po = fopen("oeste.txt","r");//Aqui se dirige al programa al fichero oeste 
					while(fscanf(po,"%[^\n]\n",cole[i].nombre) != EOF)// con fscanf lee el fichero
    				i++;
    
					for (i=0;i<15;i++){
						printf("%i. %s\n",i+1,cole[i].nombre);//Y aqui con printf lo imprime en pantalla
					}
					
					infojugadoresoeste();// Abre la funcion indicada
					
				break;
		
				case 2:
					pe = fopen("este.txt","r");//Aqui se dirige al programa al fichero este 
					while(fscanf(pe,"%[^\n]\n",cole[i].nombre) != EOF)// con fscanf lee el fichero
    				i++;
   
					for (i=0;i<15;i++){
						printf("%i. %s\n",i+1,cole[i].nombre);//Y aqui con printf lo imprime en pantalla
					}
					
					infojugadoreseste(xx=0);// Abre la funcion indicada
					
					break;	
				
				case 3:
					system ("cls");
					menu();
					break;
					
			}
		break;
			
		case 2: 
			system ("cls"); // Borra todo lo anterior
			do{
			printf("Elige la conferencia para escoger tus brackets\n");
			printf("1.Oeste\n");
			printf("2.Este\n"); 
			scanf ("%d", &cc);
			} while (cc<1 || cc>2);
			// Escribe equipos de cada conferencia
			switch (cc){
				case 1: 
					po = fopen("oeste.txt","r");//Aqui se dirige al programa al fichero oeste 
					while(fscanf(po,"%[^\n]\n",cole[i].nombre) != EOF)// con fscanf lee el fichero
    				i++;
    				
    				system("cls");// Borra todo lo anterior
    
					for (i=0;i<15;i++){
						printf("%i. %s\n",i+1,cole[i].nombre);//Y aqui con printf lo imprime en pantalla
					}
					
					playoffs();// Abre la funcion indicada
					
				break;
		
				case 2:
					pe = fopen("este.txt","r");//Aqui se dirige al programa al fichero este 
					while(fscanf(pe,"%[^\n]\n",cole[i].nombre) != EOF)// con fscanf lee el fichero
    				i++;
   					
   					system("cls");// Borra todo lo anterior
   					
					for (i=0;i<15;i++){
						printf("%i. %s\n",i+1,cole[i].nombre);//Y aqui con printf lo imprime en pantalla
					}
					
					playoffs();// Abre la funcion indicada
					
					break;	
					
			}
			break;
		
		case 3: 
			system ("cls"); // Borra todo lo anterior
			allstar(w=0); // Abre la funcion indicada
			break;
		
		case 4: 
			system ("cls"); // Borra todo lo anterior
			printf("Adios,vuelve pronto!\n");
			break;
		
	}
}


// Funcion de los jugadores de la conferencia este
void infojugadoreseste(int xx){
	
	// Fichero
	FILE *pj;
	
	// Variables utilizadas
	int i,equipo,g;

	// Vector de los jugadores
	jugador cr[500];
	g=0;
	
	
	//Abre fichero
	pj = fopen("eeste.txt","r");
	
	
	// Lee el fichero
	while(fscanf(pj,"%[^;];%[^;];%f;%f;%f;%[^\n]\n",cr[i].nombre, cr[i].posicion,&cr[i].puntos,&cr[i].asistencias,&cr[i].rebotes,cr[i].equipo) != EOF)
    i++;
    
	// Pregunta el equipo que quieres ver
    do
	{
   		printf("\nEscribe el equipo que quieres que se vea: ");
    	scanf("%d", &equipo);
	} 
	while (equipo<1 || equipo>15);
   
    system("cls");  // Borra todo lo anterior
    
	
	printf("Estos son los jugadores\n");
	// Muestra los jugadores del equipo que has escogido
    for (i=equipo*5-5;i<equipo*5;i++)
	{
		printf("\n%d. %s\n",g+=1,cr[i].nombre);
	}
	
	// Escoge a un jugador
	do
	 {
		printf("\nElige a tu jugador preferido:");
		scanf("%d", &xx);
	} while (xx>5 || xx<1);
	
	system("cls");  // Borra todo lo anterior
	// Estadisticas del jugador deseado
	printf("Estas son las estadisticas buscadas:\n");
	printf("\nNombre: %s\nPosicion: %s\nPuntos: %.2f\nAsistencias: %.2f\nRebotes: %.2f\n",cr[equipo*5-6+xx].nombre, cr[equipo*5-6+xx].posicion,cr[equipo*5-6+xx].puntos,cr[equipo*5-6+xx].asistencias,cr[equipo*5-6+xx].rebotes);
}

// Funcion de los jugadores de la conferencia oeste
void infojugadoresoeste(int xx){
	// Definimos el fichero
	FILE *pj;
	// Variables utilizadas
	int i,equipo,g;
	// Estructura jugador
	jugador cr[500];
	g=0;
	// Abrimos fichero
	pj = fopen("eoeste.txt","r");
	// Lee fichero
	while(fscanf(pj,"%[^;];%[^;];%f;%f;%f;%[^\n]\n",cr[i].nombre,cr[i].posicion,&cr[i].puntos,&cr[i].asistencias,&cr[i].rebotes,cr[i].equipo) != EOF)
    i++;
    // Pregunta el equipo que quieres ver
    do{
    printf("\nEscribe el equipo que quieres que se vea: ");
    scanf("%d", &equipo);
	} while (equipo<1 || equipo>15);
	    
    system("cls");  // Borra todo lo anterior
    printf("Estos son los jugadores\n");
	// Muestra los jugadores del equipo que has escogido
    for (i=equipo*5-5;i<equipo*5;i++){
		printf("\n%d. %s\n",g+=1,cr[i].nombre);
	}
	// Escoge a un jugador
	do {
	printf("\nElige a tu jugador preferido:");
	scanf("%d", &xx);
	} while (xx>5 || xx<1);
	
	system("cls");  // Borra todo lo anterior
	// Estadisticas del jugador deseado
	printf("Estas son las estadisticas buscadas:\n");
	printf("\nNombre: %s\nPosicion: %s\nPuntos: %.2f\nAsistencias: %.2f\nRebotes: %.2f\n",cr[equipo*5-6+xx].nombre, cr[equipo*5-6+xx].posicion,cr[equipo*5-6+xx].puntos,cr[equipo*5-6+xx].asistencias,cr[equipo*5-6+xx].rebotes);
}
void allstar(int w){
	// Define fichero
	FILE*ptFichero;
	// Variables a utilizar
	char nombre0[100];
	char nombre1[100];
	char nombre2[100];
	char nombre3[100];
	char nombre4[100];
	char nombre5[100];
	char nombre6[100];
	// Abre fichero
	ptFichero=fopen("allstar.txt", "w");

	puts("\nCrea tus premios all star\n"); // Escribe en el programa
	gets(nombre0); 
	puts("\nMVP: \n");// Escribe en el programa
	gets(nombre1); // Guarda en el programa
	puts("\nJugador que mas ha mejorado: \n");// Escribe en el programa
	gets(nombre2);// Guarda en el programa
	puts("\nMejor defensa: \n");// Escribe en el programa
	gets(nombre3);// Guarda en el programa
	puts("\nMejor entrenador: \n");// Escribe en el programa
	gets(nombre4);// Guarda en el programa
	puts("\nMejor quinteto: \n");// Escribe en el programa
	gets(nombre5);// Guarda en el programa
	puts("\nMejor novato: \n");// Escribe en el programa
	gets(nombre6); // Guarda en el programa
	
	fprintf(ptFichero, "MVP :%s\n",nombre1); // Escribe en el fichero
	fprintf(ptFichero, "Jugador que mas ha mejorado :%s\n",nombre2); // Escribe en el fichero
	fprintf(ptFichero, "Mejor defensa: %s\n",nombre3); // Escribe en el fichero
	fprintf(ptFichero, "Mejor entrenador: %s\n",nombre4); // Escribe en el fichero
	fprintf(ptFichero, "Mejor quinteto: %s\n",nombre5); // Escribe en el fichero
	fprintf(ptFichero, "Mejor novato: %s\n",nombre6); // Escribe en el fichero

	fclose(ptFichero); // Cierra fichero
	system ("cls");  // Borra todo lo anterior
	// Escoge si quieres ver que has esogido
	do {
		printf("Quieres ver tus elecciones??\n1. Si\n2. No\n3. Regresar al menu\n");
		scanf("%d", &w);
	} while (w<1 || w>3);

	switch (w){
		case 1:
			printf("Visita el fichero -allstar- en la carpeta del programa");
		break;
		
		case 2:
			printf("Hasta pronto.");
		break;
		case 3:
			
			menu();
			break;
							
	}
}
// Funcion para 
void playoffs(){
	
	FILE*ptFichero;
	// Variables a utilizar
	char clas0[50];
	char clas1[50];
	char clas2[50];
	char clas3[50];
	char clas4[50];
	char clas5[50];
	char clas6[50];
	char clas7[50];
	char clas8[50];
	char clas9[50];
	char clas10[50];
	char clas11[50];
	char clas12[50];
	char clas13[50];
	char clas14[50];
	char clas15[50];

	ptFichero=fopen("bracket.txt", "w");

	gets(clas0);
	printf("\nprimer clasificado primera ronda: \n");
	gets(clas1);// Guarda en el programa
	printf("\nSegundo clasificado primera ronda\n");
	gets(clas2);// Guarda en el programa
	printf("\nTercer clasificado primera ronda: \n");
	gets(clas3);// Guarda en el programa
	printf("\nCuarto clasificado primera ronda: \n");
	gets(clas4);// Guarda en el programa
	printf("\nQuinto clasificado primera ronda: \n");
	gets(clas5);// Guarda en el programa
	printf("\nSexto clasificado primera ronda: \n");
	gets(clas6); // Guarda en el programa
	printf("\nSeptimo clasificado primera ronda: \n");
	gets(clas7);// Guarda en el programa
	printf("\nOctavo clasificado primera ronda: \n");
	gets(clas8);// Guarda en el programa
	printf("\nGanador entre %s y %s: \n", clas1,clas8);
	gets(clas9);// Guarda en el programa
	printf("\nGanador entre %s y %s: \n", clas4,clas5);
	gets(clas10);// Guarda en el programa
	printf("\nGanador entre %s y %s: \n", clas3,clas6);
	gets(clas11);// Guarda en el programa
	printf("\nGanador entre %s y %s: \n", clas2,clas7);
	gets(clas12);// Guarda en el programa
	printf("\nGanador entre %s y %s: \n", clas9,clas10);
	gets(clas13);// Guarda en el programa
	printf("\nGanador entre %s y %s: \n", clas11,clas12);
	gets(clas14);// Guarda en el programa
	printf("\nGanador entre %s y %s: \n", clas13,clas14);
	gets(clas15);// Guarda en el programa
	printf("Tu campeon es %s!!!!!!\n\n", clas15);
	

	fprintf(ptFichero, "Primer clasificado primera ronda: :%s\n",clas1); // Escribe en el fichero
	fprintf(ptFichero, "Segundo clasificado primera ronda::%s\n",clas2); // Escribe en el fichero
	fprintf(ptFichero, "Tercer clasificado primera ronda:: %s\n",clas3); // Escribe en el fichero
	fprintf(ptFichero, "Cuarto clasificado primera ronda:: %s\n",clas4); // Escribe en el fichero
	fprintf(ptFichero, "Quinto clasificado primera ronda:: %s\n",clas5); // Escribe en el fichero
	fprintf(ptFichero, "Sexto clasificado primera ronda:: %s\n",clas6); // Escribe en el fichero
	fprintf(ptFichero, "Septimo clasificado primera ronda:: %s\n",clas7); // Escribe en el fichero
	fprintf(ptFichero, "Octavo clasificado primera ronda:: %s\n",clas8); // Escribe en el fichero
	fprintf(ptFichero, "Primer clasificado semifinales de conferencia:: %s\n",clas9); // Escribe en el fichero
	fprintf(ptFichero, "Segundo clasificado semifinales de conferencia:: %s\n",clas10); // Escribe en el fichero
	fprintf(ptFichero, "Tercero clasificado semifinales de conferencia:: %s\n",clas11); // Escribe en el fichero
	fprintf(ptFichero, "Cuarto clasificado semifinales de conferencia:: %s\n",clas12); // Escribe en el fichero
	fprintf(ptFichero, "Primer clasificado finales de conferencia:: %s\n",clas13); // Escribe en el fichero
	fprintf(ptFichero, "Octavo clasificado finales de conferencia:: %s\n",clas14); // Escribe en el fichero
	fprintf(ptFichero, "Campeon de conferencia:: %s\n",clas15); // Escribe en el fichero

	fclose(ptFichero);
	
	int g;
	do {
		printf("Que quieres hacer?\n1. Salir\n2. Regresar al menu\n");
		scanf("%d", &g);
	} while (g<1 || g>2);

	switch (g){
		
		case 1:
			printf("Hasta pronto.");
		break;
		case 2:
			system ("cls");
			menu();
			break;
							
	}
}
