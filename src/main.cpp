/*
	#include "lectura.cpp"
#include "metodos.cpp"
#include "Matriz.h"*/
//#include <math.h>       /* pow */
//#include "Matriz.h"
#include "lectura.cpp"
#include <algorithm>    // std::random_shuffle
#include <vector>
int main(int argc, char const *argv[])
{

	
	ifstream imagenesTrain;
	imagenesTrain.open("../data/train.dat");
	Matriz etiquetasTrain = Matriz(42000, 1);
	Matriz imagenesTrainM = lecturaTrain(imagenesTrain, etiquetasTrain);
	Matriz imagenesTrainMCopia=imagenesTrainM;
	imagenesTrain.close();
	Matriz imagenTrainI=Matriz(1,imagenesTrainM.DameAncho());
	
	ifstream pepe;
	pepe.open("../data/numero.dat");
	Matriz imagen = lecturaImagen(pepe);
	pepe.close();
	int etiqueta= imagenesTrainM.plsNuevo(imagen,etiquetasTrain, 7 ,50);
	cout<<"El numero es: "<<etiqueta<<endl;

	return 0;
}
