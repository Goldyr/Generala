#include <iostream>
#include <cstdlib>
#include <ctime>
#include "includes.h"
#include "rlutil.h"
using namespace std;
int menuInicial() {
	int opcion;
	cout << "1---Jugador solo" << endl;
	cout << endl;
	cout << "2---Jugador vs Jugador" << endl;
	cout << endl;
	cout << "3---Mostrar maxima puntuacion (Al cerrar el programa se resetean)" << endl;
	cout << endl;
	cout << "4---Salir" << endl;
	cout << endl;
	cin >> opcion;
	return opcion;
}
void nombrarJ(char nombJ[]) {
	cout << "Ingresa el nombre: " << endl;
	cout << endl;
	cin >> nombJ;
	cout << endl;
	cout << "Bienvenido " << nombJ << endl;
	cout << endl;
	cout << "Jugador listado correctamente!." << endl;
}
void tirarDados(int dados[],bool PRUEBA) {
	srand(time(NULL));
	if (PRUEBA != TRUE) {
		for (int I = 0; I < 5; I++) {
			dados[I] = (rand() % 6) + 1;
		}
	}
	else {
		for (int I = 0; I < 5; I++) {
			cout << "Modo prueba, ingresar dado #" << I+1 << " " << endl;
			cin >> dados[I];
		}
	}
}
void mostrarDados(int dados[]) {
	for (int I = 0; I < 5; I++) {
		cout << "Dado #" << I+1 << " " << dados[I] << endl;
	}
	rlutil::getkey();
}
char Pcambiodados() {
	char chopcion;
	cout << "Queres cambiar algun dado individual? (S), Si no necesitas ningun cambio presiona (N)" << endl;
	cout << "Para tirar mas de un dado de vuelta escribir (R), si queres volver a tirar los 5 escribir (Y)" << endl;
	cin >> chopcion;
	return chopcion;
}
void cambiarDado(int dados[],int cambio, bool cambioPlural) {
	int cuantos,dadoC[5] ;
	srand(time(NULL));

	if(cambioPlural==false){
		if(cambio < 1 && cambio>6) {
		return;
		}
		else {
		dados[cambio-1] = (rand() % 6) + 1;//El +1 es porque los resto de 6 son 0,1,2,3,4,5 y no puedo tener un 0
		}
	}
	else {
		cout << "Cuantos dados vas a cambiar?" << endl;
		cin >> cuantos;
		cout << "Escribir el numero de los dados que vas a cambiar" << endl;
		switch (cuantos) {
		case 1:
			cin >> dadoC[0];
			break;
		case 2:
			cin >> dadoC[0];
			cin >> dadoC[1];
			break;
		case 3:
			cin >> dadoC[0];
			cin >> dadoC[1];
			cin >> dadoC[2];
			break;
		case 4:
			cin >> dadoC[0];
			cin >> dadoC[1];
			cin >> dadoC[2];
			cin >> dadoC[3];
			break;
		default:
			return cambiarDado(dados, cambio, cambioPlural);
			break;
		}
		for (int I = 0; I < cuantos; I++) {//Empieza en 0, va hasta la cantidad que queria cambiar-1(vectores)Y cambia el o los dados que querias cambiar-1(again vectores)
			dados[dadoC[I]-1]= (rand() % 6) + 1;
		}

	}
}
bool generala(int dados[]) {
	bool instawin = true;
	int dadoAnt = dados[0];
	for (int I = 1; I < 5; I++) {
		if (dados[I] != dadoAnt)instawin = false;
	}

	return instawin;
}
void contadorNumerosrep(int dados[], int dadosde[]) {
	for (int I = 0; I < 5; I++) {
		switch (dados[I]) {
		case 1:
			dadosde[0]++;
			break;
		case 2:
			dadosde[1]++;
			break;
		case 3:
			dadosde[2]++;
			break;
		case 4:
			dadosde[3]++;
			break;
		case 5:
			dadosde[4]++;
			break;
		case 6:
			dadosde[5]++;
			break;
		}
	}
}
void mostrarVectores(int vector[]) {
	for (int I = 0; I < 6; I++) {
		cout << vector[I] << endl;
	}
}
int calculadorPuntaje(int dadosde[],int dados[]) {
	//Generala
	int aux=1,dadosdemay = dadosde[0],AC=0;
	for (int I = 1; I < 6; I++) {
		if (dadosde[I] >= dadosdemay) {
			if (dadosdemay == dadosde[I] && I+1 > aux) {
				dadosdemay = dadosde[I];
				aux = I + 1;
			}
			dadosdemay = dadosde[I];
			aux = I+1;
		}
	}
	cout << endl;
	cout << endl;
	if (dadosdemay <= 3 && escalera(dados)==false && FULL(dadosde) == false) {
		AC+= dadosdemay * aux;
		cout << "Nada especial" << endl;
	}
	else if (generala(dados) == true) {
		AC+= 50;
		cout << "BIEN! GENERALA +50" << endl;
	}
	else if (dadosdemay == 4) {
		AC+= 40;
		cout << "POKER!" << endl;
	}
	else if (FULL(dadosde)) {
		AC+= 30;
		cout << "FULL!" << endl;
	}
	else if (escalera(dados) == true) {
		AC+= 25;
		cout << "ESCALERA!" << endl;
	}
	cout << endl;
	cout << "ESTO ES LO QUE VALEN TUS DADOS: " << AC << endl;
	return AC;
}
bool escalera(int dados[]) {
	bool escalera = true;
	int dadosAnt = dados[0];
	for (int I = 1; I < 5; I++) {
		if (dadosAnt > dados[I])escalera = false;
		dadosAnt = dados[I];
	}
	return escalera;
}
bool FULL(int dadosde[]) {
	bool FULL = false,firstFULL = false,secondFULL = false;
	for (int I = 0; I < 6; I++) {
		if (dadosde[I] == 3)firstFULL = true;
		else if (dadosde[I] == 2)secondFULL = true;
	}
	if (firstFULL&&secondFULL)FULL = true;

	return FULL;
}
void stats(char nombJ1[],char nombJ2[],int RES, int turno,bool MULTIPLAYER) {
	system("cls");
	if (MULTIPLAYER == true) {
		if (turno%2==0) {
			gotoxy(1, 1); cout << nombJ2 << endl;
		}
		else {
			gotoxy(1, 1); cout << nombJ1 << endl;
		}
		gotoxy(50, 1); cout << "PUNTUACION: " << RES << endl;
		gotoxy(110, 1); cout << "RONDA: " << turno << endl;
		cout << endl;
		cout << endl;
		cout << endl;
	}
	else {
		gotoxy(1, 1); cout << nombJ1 << endl;
		gotoxy(50, 1); cout << "PUNTUACION: " << RES << endl;
		gotoxy(110, 1); cout << "RONDA: " << turno << endl;
		cout << endl;
		cout << endl;
		cout << endl;
	}
}
void postPunt(char nombrJ1[], char nombrJ2[], int turno, bool MULTIPLAYER, int RES, int RES2) {
	system("cls");
	for (int I = 0; I <= 120; I++) {
		rlutil::locate(I, 1); 
		cout << char(178);
	}
	for (int I = 0; I <= 20; I++) {
		rlutil::locate(1, I); 
		cout << char(178);
	}
	for (int I = 0; I <= 119; I++) {
		rlutil::locate(I, 20); 
		cout << char(178);
	}
	for (int I = 0; I <= 20; I++) {
		rlutil::locate(120, I); 
		cout << char(178);
	}
	if (MULTIPLAYER == true) {
		rlutil::locate(50, 9);
		if (turno % 2 == 0) {
			cout << "Turno de: " << nombrJ1 << endl;
			rlutil::locate(50, 10);
			cout << "Puntuacion de: " << nombrJ2 << ": " << RES2 << endl;
			rlutil::locate(50, 11);
			cout << "Puntuacion de:" << nombrJ1 << ": " << RES << endl;
		}
		else {
			cout << "Turno de: "<< nombrJ2 << endl;
			rlutil::locate(50, 10);
			cout << "Puntuacion de "<< nombrJ1 << ": "<< RES << endl;
			rlutil::locate(50, 11);
			cout << "Puntuacion de "<< nombrJ2 << ": "<<RES2 << endl;
		}

	}
	else{
	rlutil::locate(50, 9); 
	cout << "Turno "<< turno+1 << endl;
	rlutil::locate(50, 10); 
	cout << "Jugador " << nombrJ1 << endl;
	rlutil::locate(50, 11);
	cout << "Puntuacion "<< RES << endl;
	}
	rlutil::hidecursor();
	rlutil::getkey();
}
void pantallaGanador(int RES, int RES2, char nombrJ1[], char nombrJ2[], int turno){
	system("cls");
	for (int I = 0; I <= 120; I++) {
		rlutil::locate(I, 1);
		cout << char(178);
	}
	for (int I = 0; I <= 20; I++) {
		rlutil::locate(1, I);
		cout << char(178);
	}
	for (int I = 0; I <= 119; I++) {
		rlutil::locate(I, 20);
		cout << char(178);
	}
	for (int I = 0; I <= 20; I++) {
		rlutil::locate(120, I);
		cout << char(178);
	}
	if (turno > 6 && RES > RES2) {
		rlutil::locate(35, 10);
		cout << "El ganador fue el jugador " << nombrJ1 << " con una puntuacion de: " << RES << endl;
	}
	else if (turno > 6 && RES2 > RES) {
		rlutil::locate(35, 10);
		cout << "El ganador fue el jugador " << nombrJ2 << " con una puntuacion de: " << RES2 << endl;
	}
}