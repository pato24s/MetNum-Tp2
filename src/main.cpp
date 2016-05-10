/*
	#include "lectura.cpp"
#include "metodos.cpp"
#include "Matriz.h"*/
//#include <math.h>       /* pow */
#include "Matriz.h"
#include "lectura.cpp"

int main(int argc, char const *argv[])
{
	
	
	ifstream imagenesTrain;
	imagenesTrain.open("../data/train.dat");
	Matriz etiquetasTrain = Matriz(42000, 1);
	Matriz imagenesTrainM = lecturaTrain(imagenesTrain, etiquetasTrain);
	imagenesTrain.close();

	Matriz imagenTrainI=Matriz(1,imagenesTrainM.DameAncho());
	for (int i = 1; i <= imagenesTrainM.DameAncho(); i++)
	{
		imagenTrainI.Definir(1,i,imagenesTrainM.Obtener(1,i));
	}


	//cout<<"pca da: "<<imagenesTrainM.pca(imagenTrainI,etiquetasTrain,20,400)<<endl;
	//Matriz etiquetas = Matriz(42000,1);
	//Matriz imagenesTraining = convertirAMatrizTrain(train, etiquetas);


	
	ifstream imagenesTest;
	imagenesTest.open("../data/test.dat");
	Matriz etiquetasTest = Matriz(28000,1);
	Matriz imagenesTests= Matriz(28000,784);
	imagenesTests = lecturaTest(imagenesTest, etiquetasTest);
	//imagenesTests.mostrarMatriz(cout);

	//IMPRIME LAS IMAGENES A PROBAR EN ESE FORMATO LINDO ASQUEROSO PETON
	Matriz imagen1 = Matriz(1,784);
	int it =1;
	while(it<11){
	imagenesTests.insertarEnFila1(imagen1,1,it);
	mostrarImagen(imagen1);
	it++;	
	}

	//Matriz etiquetas2 = Matriz(28000,1);
	//Matriz imagenesTesting = convertirAMatrizTest(tests, etiquetas2);
	imagenesTest.close();



/*

	Matriz x(3,3);
	x.Definir(1,1,1);
	x.Definir(1,2,2);
	x.Definir(1,3,3);
	x.Definir(2,1,4);
	x.Definir(2,2,5);
	x.Definir(2,3,6);
	
	x.mostrarMatriz(cout);

	///Matriz xt=x.Traspuesta();
	//cout<<xt;
	Matriz m=x.multiXtrans();
	cout<<m;
*/

/*

	Matriz random = Matriz(3,1);
	random.Definir(1,1, 1);
	random.Definir(2,1, 1);
	random.Definir(3,1, 1);
	cout<<prueba<<endl;
	Matriz rt = random.copiarMatriz();
	rt.Traspuesta();
	double autovalor =prueba.dameAutovalor(random , 30);


	cout<<"un autovalor es: "<<autovalor<<endl;
	//Matriz randi = Matriz(3, 3);
	cout<< "el autovector asociado es:";
	random.mostrarMatriz(cout);
	//randi.mostrarMatriz(cout);
	prueba = prueba.deflacion(autovalor, random);
	cout<<"deflaciado queda: ";
	prueba.mostrarMatriz(cout);
	random.Definir(1,1, 2);
	random.Definir(2,1, 3);
	random.Definir(3,1, 1);
	Matriz autovalores = Matriz(3,1);
	Matriz autovectores = Matriz(3,3);
	autovectores = prueba.baseAutovectores(40, autovalores);
	//cout << "el otro autovalor es: "<< prueba.dameAutovalor(random, 30);
	cout<< "Los autovalores son:";
	autovalores.mostrarMatriz(cout);
	cout<< "Y los autovectores...";
	autovectores.mostrarMatriz(cout);
	Matriz randi = Matriz(4, 4);
	randi.randomizar(3, 3);
	randi.mostrarMatriz(cout);

*/

	return 0;
}
