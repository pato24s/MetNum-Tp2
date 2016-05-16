#include "lectura.cpp"
#include <algorithm>    // std::random_shuffle
#include <vector>
#include <iostream>
#include <fstream>
#include <cstring>
#include <stdlib.h> 
using namespace std;


int main(int argc, char const *argv[])
{

	//valor random  donde empieza
	//void insertarEnFila(Matriz& a, int f);
	
	ifstream imagenesTrain;
	imagenesTrain.open("../data/train.dat");
	Matriz etiquetasTrain = Matriz(42000, 1);
	Matriz imagenesTrainM = lecturaTrain(imagenesTrain, etiquetasTrain);
	Matriz imagenesTrainMCopia=imagenesTrainM;
	imagenesTrain.close();
	Matriz imagenTrainI=Matriz(1,imagenesTrainM.DameAncho());
	cout<<imagenesTrainM.DameAncho()<<" "<<imagenesTrainM.DameAlto()<<endl;
	/*
	Matriz muestra(1,784);
	for (int i = 1; i < 50; ++i){
		imagenesTrainM.insertarEnFila1(muestra,1,i);
		mostrarImagen(muestra);
	}
	*/

	Matriz pepe(1,784);
	for(int i = 1; i < 51 ;++i){
	
	imagenesTrainM.insertarEnFila1(pepe,1,1);	

	}
	//cout<<pepe;PARA TESTEAR CON LA IMAGEN PEPE
	mostrarImagen(pepe);
	
	cout << "TESTEANDO LOS PROMEDIOS PAPURRIIIIIIIIII"<<endl;
	
	int izquierda;
	int derecha;
	int abajo;
	int alto;
	promedioArribaYAbajo(imagenesTrainM,alto,abajo);
	promedioAnchoIzqYDer(imagenesTrainM,izquierda,derecha);
	cout << "Promedio Ancho izquierda Y derecha: "<<izquierda<<" "<<derecha<<endl;
	cout << "Promedio alto Y abajo: "			<<alto<<" "<<abajo<<endl;
	
	return 0;
}