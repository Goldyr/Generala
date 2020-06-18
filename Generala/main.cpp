#include <iostream>
#include <cstdlib>
#include <ctime>
#include "includes.h"
#include "rlutil.h"
using namespace std;

int main(){// ESTAS USANDO 5 DADOS QUE PUEDEN TENER 6 VALORES DISTINTOS.
	system("cls");
	rlutil::setColor(rlutil::YELLOW);
	rlutil::setBackgroundColor(rlutil::BLACK);
	rlutil::cls();
	int A, dados[5], turno = 1, cambio, MAXRES = 0;
	char nombrJ1[15];
	char nombrJ2[15];
	char chopcion;
	const bool PRUEBA = false;//TRUE=MODO PRUEBA
	bool MULTIPLAYER=false;//Se hace true solo si menuInicial=2;
	bool generalaMulti = false, cambioPlural = false;

	do {
		if (turno != 1) {
			cout << "Puntuacion maxima alcanzada hasta ahora: "<< MAXRES << endl;
			rlutil::getkey();
			system("cls");
			turno = 1;
		}
		int RES = 0;
		int RES2 = 0;//Aunque no haya player 2 deberia tener esto para las funciones en el futuro
		do {
			int RES = 0;
			int RES2 = 0;
			A = menuInicial();
			system("cls");
		} while (A<0 && A>5);//Antiforradas
		cambio = 0;
		switch (A) {
		case 1:
			MULTIPLAYER = false;
			//Nombro jugador 1
			nombrarJ(nombrJ1);
			//Agrego al j2 para poder reusar alguna func en el futuro
			char nombrJ2[15];
			rlutil::getkey();
			system("cls");
			cout << "Comienza la partida!" << endl;
			do {
				cout << "Presione cualquier boton para tirar dados" << endl;
				rlutil::getkey();
				stats(nombrJ1,nombrJ2,RES,turno,MULTIPLAYER);
				int dadosde[6]{ 0 };
				//Tiras dados
				tirarDados(dados, PRUEBA);////////////////////////////////////
				//Mostras los dados
				mostrarDados(dados);
				if (generala(dados) == true) {
					system("cls");
					cout << "Felicidades sacaste Generala sin cambio de dados ganaste!" << endl;
					cout << "Presiona cualquier boton para volver al menu" << endl;
					rlutil::getkey();
					system("cls");
					RES += 50;
					
					break;
				}
				//Preguntas si quieren cambiar algun dado
				chopcion=Pcambiodados();
				if (chopcion == 'S' || chopcion == 's') {
					cout << "Escribi el num del dado que queres cambiar" << endl;
					cin >> cambio;
					cambiarDado(dados, cambio, cambioPlural);
					mostrarDados(dados);
					chopcion = Pcambiodados();
					if (chopcion == 'S' || chopcion == 's') {
						cout << "Escribi el num del dado que queres cambiar" << endl;
						cin >> cambio;
						cambiarDado(dados, cambio, cambioPlural);
					}
					else if (chopcion == 'Y' || chopcion == 'y') {
						tirarDados(dados, PRUEBA);
						cout << endl;
					}
					else if (chopcion == 'R' || chopcion == 'r') {
						cambioPlural = true;
						cambiarDado(dados, cambio, cambioPlural);
						cambioPlural = false;
						mostrarDados(dados);
						cout << endl;
						cout << endl;
					}
				}
				else if (chopcion == 'Y' || chopcion == 'y') {
					tirarDados(dados, PRUEBA);
					mostrarDados(dados);
					cout << endl;
					cout << endl;
					chopcion = Pcambiodados();
					if (chopcion == 'S' || chopcion == 's') {
						cout << "Escribi el num del dado que queres cambiar" << endl;
						cin >> cambio;
						cambiarDado(dados, cambio, cambioPlural);
					}
					else if (chopcion == 'Y' || chopcion == 's') {
						tirarDados(dados, PRUEBA);
						cout << endl;
						mostrarDados(dados);
						cout << endl;
						cout << endl;
					}
					else if (chopcion == 'R' || chopcion == 'r') {
						cambioPlural = true;
						cambiarDado(dados, cambio, cambioPlural);
						cambioPlural = false;
						mostrarDados(dados);
						cout << endl;
						cout << endl;
					}
				}
				else if (chopcion == 'R'|| chopcion == 'r') {
					cambioPlural = true;
					cambiarDado(dados, cambio, cambioPlural);
					cambioPlural = false;
					mostrarDados(dados);
					cout << endl;
					cout << endl;
					chopcion = Pcambiodados();
					if (chopcion == 'S' || chopcion == 's') {
						cout << "Escribi el num del dado que queres cambiar" << endl;
						cin >> cambio;
						cambiarDado(dados, cambio, cambioPlural);
					}
					else if (chopcion == 'Y' || chopcion == 's') {
						tirarDados(dados, PRUEBA);
						cout << endl;
						mostrarDados(dados);
						cout << endl;
						cout << endl;
					}
					else if (chopcion == 'R' || chopcion == 'r') {
						cambioPlural = true;
						cambiarDado(dados, cambio, cambioPlural);
						cambioPlural = false;
						mostrarDados(dados);
						cout << endl;
						cout << endl;
					}

				}
				cout << "Tus dados quedaron asi: " << endl;
				//Volver a mostrar los dados con cambios hechos o no.
				mostrarDados(dados);
				//Cuento repetidos
				contadorNumerosrep(dados, dadosde);
				//Calculo dependiendo los repetidos.
				int AC = 0;
				AC = calculadorPuntaje(dadosde,dados);
				RES+= AC;
				rlutil::getkey();
				if (turno < 10)postPunt(nombrJ1, nombrJ2, turno, MULTIPLAYER, RES, RES2);
				system("cls");
				turno++;
			} while (turno <= 10);//Turnos que va a durar la partida en caso de que no saquen generala de una.
			if (turno > 10) {
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
				rlutil::locate(35, 10);
				cout << "Alcanzaste el maximo de rondas llegando a un puntaje de: " << RES << endl;

				rlutil::getkey();
				system("cls");
			}
			break;
		case 2://Voy a usar los turnos para diferenciar jugadores (Jugador 1 siempre va a tener turnos impares, mientras que el jugador 2 siempre tendra pares)
			MULTIPLAYER = true;
			//Nombro jugador 1
			nombrarJ(nombrJ1);
			//Nombro jugador 2
			nombrarJ(nombrJ2);

			rlutil::getkey();
			system("cls");//Limpio pantalla

			do {//Empieza el juego 1 v 1
				//De quien es el turno para mostrar stats?
				if (turno % 2 == 0) {
					stats(nombrJ1, nombrJ2, RES2, turno, MULTIPLAYER);
				}
				else {
					stats(nombrJ1, nombrJ2, RES, turno, MULTIPLAYER);
				}
				int dadosde[6]{ 0 };//////////////////////////////////
				tirarDados(dados, PRUEBA);//Tiras dados
				cout << endl;
				cout << endl;
				mostrarDados(dados);
				if (generala(dados) == true) {//Generala?
					cout << endl;
					cout << "Sacaste Generala sin cambio de dados!" << endl;
					cout << "Tu contrincante tiene una ultima oportunidad de empatar la partida, necesita sacar una generala de un tiro!" << endl;
					cout << endl;
					cout << "Presione cualquier boton para tirar por la oportunidad de empate!" << endl;
					cout << endl;
					cout << endl;
					rlutil::getkey();
					tirarDados(dados, PRUEBA);
					cout << endl;
					cout << endl;
					mostrarDados(dados);
					cout << endl;
					if (generala(dados) == true) {//NICE
						system("cls");
						cout << "EMPATE!!!!!!!" << endl;
						cout << "Regresar a menu presionando cualquier boton" << endl;
						rlutil::getkey();
						RES += 50;
						RES2 += 50;
						system("cls");
					}
					else {
						generalaMulti = true;//Voy a usarla para felicitar al jugador que saco generala sino no podria diferenciarlo de ganar normalmente
						system("cls");
					}
						break;
				}
				
				//Preguntas si quieren cambiar algun dado
				chopcion = Pcambiodados();
				if (chopcion == 'S' || chopcion == 's') {
					cout << "Escribi el num del dado que queres cambiar" << endl;
					cin >> cambio;
					cambiarDado(dados, cambio, cambioPlural);
					mostrarDados(dados);
					chopcion = Pcambiodados();
					if (chopcion == 'S' || chopcion == 's') {
						cout << "Escribi el num del dado que queres cambiar" << endl;
						cin >> cambio;
						cambiarDado(dados, cambio, cambioPlural);
					}
					else if (chopcion == 'Y' || chopcion == 'y') {
						tirarDados(dados, PRUEBA);
						cout << endl;
					}
					else if (chopcion == 'R' || chopcion == 'r') {
						cambioPlural = true;
						cambiarDado(dados, cambio, cambioPlural);
						cambioPlural = false;
						mostrarDados(dados);
						cout << endl;
						cout << endl;
					}
				}
				else if (chopcion == 'Y' || chopcion == 'y') {
					tirarDados(dados, PRUEBA);
					mostrarDados(dados);
					cout << endl;
					cout << endl;
					chopcion = Pcambiodados();
					if (chopcion == 'S' || chopcion == 's') {
						cout << "Escribi el num del dado que queres cambiar" << endl;
						cin >> cambio;
						cambiarDado(dados, cambio, cambioPlural);
					}
					else if (chopcion == 'Y' || chopcion == 's') {
						tirarDados(dados, PRUEBA);
						cout << endl;
						mostrarDados(dados);
						cout << endl;
						cout << endl;
					}
					else if (chopcion == 'R' || chopcion == 'r') {
						cambioPlural = true;
						cambiarDado(dados, cambio, cambioPlural);
						cambioPlural = false;
						mostrarDados(dados);
						cout << endl;
						cout << endl;
					}
				}
				else if (chopcion == 'R' || chopcion == 'r') {
					cambioPlural = true;
					cambiarDado(dados, cambio, cambioPlural);
					cambioPlural = false;
					mostrarDados(dados);
					cout << endl;
					cout << endl;
					chopcion = Pcambiodados();
					if (chopcion == 'S' || chopcion == 's') {
						cout << "Escribi el num del dado que queres cambiar" << endl;
						cin >> cambio;
						cambiarDado(dados, cambio, cambioPlural);
					}
					else if (chopcion == 'Y' || chopcion == 's') {
						tirarDados(dados, PRUEBA);
						cout << endl;
						mostrarDados(dados);
						cout << endl;
						cout << endl;
					}
					else if (chopcion == 'R' || chopcion == 'r') {
						cambioPlural = true;
						cambiarDado(dados, cambio, cambioPlural);
						cambioPlural = false;
						mostrarDados(dados);
						cout << endl;
						cout << endl;
					}

				}
				cout << "Tus dados quedaron asi: " << endl;
				//Volver a mostrar los dados con cambios hechos o no.
				mostrarDados(dados);
				
				//Cuento repetidos
				contadorNumerosrep(dados, dadosde);

				//Calculo dependiendo los repetidos.
				int AC = 0;/////////////
				AC = calculadorPuntaje(dadosde, dados);
				if (turno % 2 == 0) {
					RES2 += AC;
				}
				else {
					RES += AC;
				}
				rlutil::getkey();
				//Menu post puntuacion, muestra los cambios de turnos y la puntuacion que lleva cada jugador//el if esta para que no lo muestre la ultima ronda
				if (turno<10)postPunt(nombrJ1, nombrJ2, turno, MULTIPLAYER, RES, RES2);
				system("cls");
				turno++;
				if (turno > 10 && RES == RES2) {//Turnos hasta que pare
					cout << "Empate entre los 2 jugadores se volvera al menu" << endl;
					system("cls");
				}
			} while (turno <= 10);
			pantallaGanador(RES,RES2,nombrJ1,nombrJ2,turno);
			rlutil::getkey();
			system("cls");
			break;
		case 3://Maxima puntuacion guardada
			cout << "La puntuacion maxima guardada es: " << MAXRES << endl;
			rlutil::getkey();
			system("cls");
			break;
		case 4://Salir
			break;
		default:
			cout << "Te estas mandando cagadas" << endl;
			break;
		}
		if (generalaMulti && turno%2==0) {//Felicitar jugador por victoria por generala
			cout << "Felicidades " << nombrJ2 << " ganaste!" << endl;
			RES2 += 50;
		}
		else if(generalaMulti && turno%2!=0) {
			cout << "Felicidades " << nombrJ1 << " ganaste!" << endl;
			RES += 50;
		}

		if (MAXRES == 0 && MULTIPLAYER == false) {//Recibir la maxima puntuacion.
			MAXRES = RES;
		}
		else if (MULTIPLAYER == false && RES > MAXRES)MAXRES = RES;
		else if(MAXRES == 0 && MULTIPLAYER == true) {
			if (RES > RES2)MAXRES = RES;
			else if (RES2 > RES)MAXRES = RES2;
			else MAXRES = RES;
		}

	} while (A != 4);

	system("cls");
	cout << "Gracias por jugar! Esto fue Generala por Enzo Bogado." << endl;
	rlutil::getkey();
	
	return 0;
}