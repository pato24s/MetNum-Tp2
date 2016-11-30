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
	
	ifstream pepe;
	pepe.open(argv[1]);//la matriz de ceros y unos
	tuplaDatos data=lecturaFoldTest(pepe);
	pepe.close();
		ifstream imagenesTrain;
	string ruta=data.path + "train.dat";
	imagenesTrain.open(ruta.c_str());
	Matriz etiquetasTrain = Matriz(42000,1);
	Matriz imagenesTrainM = lecturaTrain(imagenesTrain,etiquetasTrain);
	imagenesTrain.close();



	ofstream obligatorio;
	obligatorio.open(argv[2]); //donde imprimir la mierda
	int metodo=atoi(argv[3]);

	vector<vector<double> > pca=kFoldCrossValConVector(imagenesTrainM, data.cantFolds, data.alfa, data.gamma, etiquetasTrain, 1, data.kfold);
	vector<vector<double> > pls=kFoldCrossValConVector(imagenesTrainM, data.cantFolds, data.alfa, data.gamma, etiquetasTrain, 2, data.kfold);
	cout<<"Escribiendo autovalores..."<<endl;
	int i=0;
	while(i<data.cantFolds){
		for (int j = 0; j < data.alfa; ++j){
			obligatorio<<scientific<<pca[i][j]<<endl;
		}
		for (int l = 0; l < data.gamma; ++l){
			obligatorio<<scientific<<pls[i][l]<<endl;
		}
		i++;
	}



	obligatorio.close();

	return 0;
}