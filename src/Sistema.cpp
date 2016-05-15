#include "lectura.cpp"
#include <iostream>
#include <fstream>
//#include <iomanip>	// fruta1
//#include <string>     // fruta2
#include <stdlib.h>
#include <vector>

using namespace std;


/*
ejecutable tomara tres parametros por lınea de comando, que seran el nombre del archivo de
entrada, el nombre del archivo de salida, y el metodo a ejecutar (0: kN N , 1: PCA + kN N ,
2: PLS-DA + kN N ).
*/
int main(int argc, char const *argv[])
{

	// ifstream imagenesTrain;
	// imagenesTrain.open("../data/train.dat");
	// Matriz etiquetasTrain = Matriz(42000, 1);
	// Matriz imagenesTrainM = lecturaTrain(imagenesTrain, etiquetasTrain);
	// imagenesTrain.close();
	// Matriz imagenTrainI=Matriz(1,imagenesTrainM.DameAncho());
	
	ifstream pepe;
	pepe.open(argv[1]);//la matriz de ceros y unos
	tuplaDatos data=lecturaFoldTest(pepe);
	pepe.close();
	cout<<data.path;
	ifstream imagenesTrain;
	string ruta=data.path + "train.dat";
	imagenesTrain.open(ruta.c_str());
	Matriz etiquetasTrain = Matriz(42000,1);
	Matriz imagenesTrainM = lecturaTrain(imagenesTrain,etiquetasTrain);
	imagenesTrain.close();


	ofstream fileOut;
	fileOut.open(argv[2]); //donde imprimir la mierda
	int metodo=atoi(argv[3]);
	if(metodo==0){
		cout<<"pediste knn"<<endl;
	}else{
		if(metodo==1){
				kFoldCrossValConEscritura(fileOut, imagenesTrainM, data.cantFolds, data.alfa, data.gamma, etiquetasTrain, metodo, data.kfold);

		}else{
			kFoldCrossValConEscritura(fileOut, imagenesTrainM, data.cantFolds, data.alfa, data.gamma, etiquetasTrain, metodo, data.kfold);
		}
	}
	fileOut.close();

	return 0;
}