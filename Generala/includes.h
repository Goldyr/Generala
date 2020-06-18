#pragma once
// te manda al menu inicial/ 1-Jugador solo 2-JvsJ 3-Salir
int menuInicial();

//Muestra estadisticas.
void stats(char nombJ1[], char nombJ2[], int RES, int turno, bool MULTIPLAYER);

//Nombra al jugador
void nombrarJ(char nombJ[]);

//Tirar dados *//REMINDER: srand funciona con tiempo, si haces todo muy rapido puede que vuelvan a tocarte los mismos nums.
void tirarDados(int dados[],bool PRUEBA);

//mostrar dados
void mostrarDados(int dados[]);

//Pregunta cambio de dado
char Pcambiodados();

//cambiar dado *//REMINDER: srand funciona con tiempo
void cambiarDado(int dados[],int cambio, bool cambioPlural);

//generala? instawin
bool generala(int dados[]);

//Ver cuantos numeros hay de c/u //Cargo dadosde[] con los repetidos
void contadorNumerosrep(int dados[], int dadosde[]);

//Calcular el puntaje
int calculadorPuntaje(int dadosde[],int dados[]);

//Ver el vector
void mostrarVectores(int vector[]);

//Escalera?
bool escalera(int dados[]);

//FULL?
bool FULL(int dadosde[]);

//Menu postpuntuacion
void postPunt(char nombrJ1[], char nombrJ2[],int turno, bool MULTIPLAYER, int RES,int RES2);

//pantalla ganador por si se alarga y no llega a un final con generala servida
void pantallaGanador(int RES,int RES2,char nombrJ1[],char nombrJ2[],int turno);