//Autor: Jenniffer Granados jrgranados.jg@gmail.com
//Juego de cartas 31 
#include<stdio.h>
#include <stdlib.h>
#include<time.h>
#include <string.h>
#include<stdbool.h>
#ifdef __linux__   //Validacion del sistema operativo... Sirve para poder limpiar la pantalla
#define so "Linux" // dependiendo del sistema en el que se encuetre el usuario
#elif _WIN32
#define so "Windows"
#include <Windows.h>
#endif


// ***** Definicion de Variables *********

char totalCartas[]={'A','2','3','4','5','6','7','8','9','J','Q','K',
'A','2','3','4','5','6','7','8','9','J','Q','K',
'A','2','3','4','5','6','7','8','9','J','Q','K',
'A','2','3','4','5','6','7','8','9','J','Q','K'};  
char baraja[47];
char palo[15];
int carta=0,sumaJugador=0,sumaBanquero=0,seguirJuego=1;
char manoJugador1[1000]="",manoJugador2[1000]="",manoJugador3[1000]="",manoJugador4[1000]="";
char manoBanca1[1000]="",manoBanca2[1000]="",manoBanca3[1000]="",manoBanca4[1000]="";
char nombreJugador[25];
// ***********************************************

//Generador de numeros aleatorios para sacar las cartas
int numeroAleatorio(){
    int numero=0;
    do{
        numero=(rand()%47);      
    }while(baraja[numero]=='0');
    return numero;
}
//Inicializacion de variables a utilizar y llena el vector que contiene la baraja
void llenarBaraja(){
    strcpy(manoJugador1,"");
    strcpy(manoJugador2,"");
    strcpy(manoJugador3,"");
    strcpy(manoJugador4,"");
    
    strcpy(manoBanca1,"");
    strcpy(manoBanca2,"");
    strcpy(manoBanca3,"");
    strcpy(manoBanca4,"");
    carta=0,sumaJugador=0,sumaBanquero=0;

    for(int i=0;i<48;i++)baraja[i]=totalCartas[i];
}
//Escoge palo(pica, trebol, Corazon y diamante) y se lo asigna a la carta 
void escogerPalo(int a){   
    char parte1[20]="";
    char parte2[20]="";
    char parte3[20]="";
    char parte4[20]="";    
    char variable[2]="";
     
	strcpy(parte1," _____   ");
    strcpy(parte3,"|  ");		
    variable[0]=baraja[carta];
    strcat(parte3,variable);
    strcat(parte3,"  |  ");
   
    if(carta<=12){
        strcpy(palo,"Diamante");
        strcpy(parte2,"|♦    |  ");
        strcat(parte4,"|____♦|  ");
    }else{
        if(carta<=24) {
             strcpy(palo,"Pica");
             strcpy(parte2,"|♠    |  ");
             strcat(parte4,"|____♠|  ");
        }
    
        else{
            if(carta<=36){
                 strcpy(palo,"Corazón");
                 strcpy(parte2,"|♥    |  ");
                 strcat(parte4,"|____♥|  ");
            }
            else {
                strcpy(palo,"Trebol");
                strcpy(parte2,"|♣    |  ");
                strcat(parte4,"|____♣|  ");
            }
        }
    }
    if(a==1){
        strcat(manoJugador1,parte1);
        strcat(manoJugador2,parte2);
        strcat(manoJugador3,parte3);
        strcat(manoJugador4,parte4);
       
    }else{
        strcat(manoBanca1,parte1);
        strcat(manoBanca2,parte2);
        strcat(manoBanca3,parte3);
        strcat(manoBanca4,parte4);
    }
}

//Metodo que imprime las cartas 
void imprimirMano(int player){ 
    char manosT1[1000]="",manosT2[1000]="",manosT3[1000]="",manosT4[1000]="";
    if(player==1){
        strcat(manosT1,manoJugador1);
        strcat(manosT2,manoJugador2);
        strcat(manosT3,manoJugador3);
        strcat(manosT4,manoJugador4);
    }
    else{
        strcat(manosT1,manoBanca1);
        strcat(manosT2,manoBanca2);
        strcat(manosT3,manoBanca3);
        strcat(manosT4,manoBanca4);        
    }

    int g=0;    
    while(manosT1[g]!='\0'){
    printf("%c",manosT1[g]);
    g++;
    }printf("\n"); 

    g=0;    
    while(manosT2[g]!='\0'){
    printf("%c",manosT2[g]);
    g++;
    }printf("\n"); 

   g=0;    
    while(manosT3[g]!='\0'){
    printf("%c",manosT3[g]);
    g++;
    }printf("\n"); 

    g=0;    
    while(manosT4[g]!='\0'){
    printf("%c",manosT4[g]);
    g++;
    }printf("\n"); 
}
//Suma las cartas del jugador y de la banca
void sumaCartas(int player){
    int as=0;
    if(player==1){
        if(baraja[carta]=='J'||baraja[carta]=='Q'||baraja[carta]=='K')sumaJugador+=10;			
        else {
            if(baraja[carta]=='A'){
                if(sumaJugador<21){
                    printf("Suma Jugador: %i \n",sumaJugador);
                    do{
                        printf("Carta: A\n ¿Como desea tomar el As? 1-->1, 2-->11\n");
                        scanf("%d",&as);
                     }while(as!=1&&as!=2);
                    
                    switch(as){
                        case 1: sumaJugador+=1;
                        break;
                        case 2: sumaJugador+=11;
                        break;
                    }					
                }
                else sumaJugador+=1;
            }
            else sumaJugador+=(baraja[carta] -'0');
        }
    }
    else{
        if(baraja[carta]=='J'||baraja[carta]=='Q'||baraja[carta]=='K')sumaBanquero+=10;			
        else {
            if(baraja[carta]=='A') sumaBanquero+=11;  				
            else sumaBanquero+=(baraja[carta] -'0');
        } 
    }
}

//Metodo para limpiar la pantalla de la consola
void limpiarPantalla(){
     //Validar el sistema operativo para limpiar la pantalla
     if(so=="Linux") system("clear "); 
     else  system("cls");
     //**************************************
}

int main(){
    srand(time(NULL));
    //Nombre del jugador
	SetConsoleOutputCP(CP_UTF8); //Para imprimir los caracteres  ♦♠♥♣
    printf(" -♦♠- Juego de cartas 31. Por favor digita tu nombre -♥♣-\n");
    scanf("%24[0-9a-zA-Z ]",nombreJugador);
  
    do{ 
        limpiarPantalla();     
        printf("-♦♠- Juego de cartas 31. Bienvenid@ %s -♥♣-\n",nombreJugador);
        llenarBaraja(); 
        sumaJugador=0;
        sumaBanquero=0;
        int seguir=0,pedir=0;;
       
        printf("Cartas en la mano \n");
        for(int i=0;i<3;i++){
            //Cartas iniciales del jugador
            carta=numeroAleatorio();
            escogerPalo(1);
            sumaCartas(1);  
            baraja[carta]='0';
    
            //Cartas iniciales de la Banca
            carta=numeroAleatorio();
            escogerPalo(3);        
            sumaCartas(2);  
            baraja[carta]='0';
        }
        imprimirMano(1);
        printf("\n");       
        printf("Total Jugador: %i \n",sumaJugador);
        if(sumaJugador<31){
            do{
                printf("%s, ¿Desea pedir otra carta?\n 1-->si, 2-->No\n",nombreJugador);
                scanf("%d",&pedir);
            }while(pedir!=1&&pedir!=2);        
        }        
        while(pedir==1){  
            limpiarPantalla();
            printf("-♦♠- Juego de cartas 31. Jugador %s -♥♣-\n \n",nombreJugador);
            carta=numeroAleatorio();   
            escogerPalo(1);
            printf("Carta: %c %s \n",baraja[carta],palo);  
            sumaCartas(1);   
            imprimirMano(1);
            printf("\n");
            printf("Total Jugador: %i \n",sumaJugador);   
            baraja[carta]='0';
         
            if(sumaJugador>=31)pedir=0;
            else{
                do{
                    printf("%s ¿Desea pedir otra carta?\n 1-->si, 2-->No\n",nombreJugador);
                    scanf("%d",&pedir);
                }while(pedir!=1&&pedir!=2);
            }  
        }    
       limpiarPantalla();
       printf("-♦♠- Juego de cartas 31. Jugador %s -♥♣-\n \n",nombreJugador);

        if(sumaJugador==31) printf("Tienes 31!! %s has ganado la partida!!\n",nombreJugador);
        else{
            if(sumaJugador>31){
                printf("%s has perdido la partida\n",nombreJugador);
                printf("Tu total es: %i \n",sumaJugador);  
            }
            else{
                while(sumaBanquero<=sumaJugador){
                    carta=numeroAleatorio();   
                    escogerPalo(2);
                    sumaCartas(2);
                    baraja[carta]='0';                 
                }
                if(sumaBanquero>=32) printf("%s has ganado la partida!!\n",nombreJugador);               
                
                else printf("%s has Perdido la partida\n",nombreJugador);
                
            }
        }
        //Impresion de las cartas finales en las manos
        printf("Mano final del jugador %s\n",nombreJugador);
        imprimirMano(1);
        printf("\n");
        printf("Total Jugador: %i \n",sumaJugador);
        printf("\n");
        printf("Mano final de la Banca\n");
        imprimirMano(2);
        printf("\n");
        printf("Total Banca: %i \n",sumaBanquero);		
        do{
            printf("%s, ¿Deseas volver a jugar? \n1-->si, 2-->No\n",nombreJugador);
            scanf("%d",&seguirJuego);
        }while(seguirJuego!=1&&seguirJuego!=2);		

    }while(seguirJuego==1);
    return 0;
}