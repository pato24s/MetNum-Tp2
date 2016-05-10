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
	Matriz imagenesCopia(2000,784);
	for (int i = 1; i <=2000 ; ++i)
	{
		for (int j = 1; j<=784 ; ++j)
		{
			imagenesCopia.Definir(i,j, imagenesTrainM.Obtener(i,j));
		}
	}
	cout<<"listo, ya lo copie"<<endl;
	Matriz imagenTrainI(1,imagenesTrainM.DameAncho());
	for (int i = 1; i <= imagenesTrainM.DameAncho(); i++)
	{
		imagenTrainI.Definir(1,i,imagenesTrainM.Obtener(1,i));
	}


	//cout<<"pca da: "<<imagenesTrainM.pca(imagenTrainI,etiquetasTrain,20,400)<<endl;
	//Matriz etiquetas = Matriz(42000,1);
	//Matriz imagenesTraining = convertirAMatrizTrain(train, etiquetas);
	//int digito = imagenesTrainM.pca(imagenesCopia,etiquetasTrain, 10, 30);
	//cout<< "La primera imagen corresponde al digito..."<< digito<<endl;

	Matriz prueba(3,3);
	prueba.Definir(1,1,1);
	prueba.Definir(1,2,0);
	prueba.Definir(1,3,0);
	prueba.Definir(2,1,1);
	prueba.Definir(2,2,2);
	prueba.Definir(2,3,0);
	prueba.Definir(3,1,0);
	prueba.Definir(3,2,0);
	prueba.Definir(3,3,3);
	Matriz autovalores(3,1);
	Matriz base = prueba.baseAutovectores(1000,autovalores, 3);
	base.mostrarMatriz(cout);
	cout<<autovalores;
/*	Matriz autovalores(3,1);
	Matriz autovalor1(3,1);
	autovalor1.Definir(1,1,1);
	autovalor1.Definir(2,1,1);
	double av1 = prueba.dameAutovalor(autovalor1, 50);
	cout<<"un autovalor es.."<< av1;
	cout<<"el autovector asociado es..";
	cout<<autovalor1;


	prueba.deflacion(av1, autovalor1);
	av1 = prueba.dameAutovalor(autovalor1, 50);
	cout<<"el otro autovalor es.."<< av1;
	cout<<"el autovector asociado es..";
	 cout<<autovalor1;	
	prueba.deflacion(av1, autovalor1);
	cout<<"el ultimo autovalor es.."<< prueba.dameAutovalor(autovalor1, 50)<<endl;
	cout<<"el autovector asociado es..";
	 cout<<autovalor1;*/
	
	/*Matriz base = prueba.baseAutovectores(50, autovalores, 3);
	cout<<"los autovalores son..";
	autovalores.mostrarMatriz(cout);
	cout<<"los autovectores son..";
	base.mostrarMatriz(cout);*/
	ifstream imagenesTest;
	imagenesTest.open("../data/test.dat");
	Matriz etiquetasTest = Matriz(28000,1);
	Matriz imagenesTests= Matriz(28000,784);
	imagenesTests = lecturaTest(imagenesTest, etiquetasTest);
	//imagenesTests.mostrarMatriz(cout);

	//IMPRIME LAS IMAGENES A PROBAR EN ESE FORMATO LINDO ASQUEROSO PETON
/*	Matriz imagen1 = Matriz(1,784);
	int it =1;
	while(it<11){
	imagenesTests.insertarEnFila1(imagen1,1,it);
	mostrarImagen(imagen1);
	it++;	
	}*/

	//Matriz etiquetas2 = Matriz(28000,1);
	//Matriz imagenesTesting = convertirAMatrizTest(tests, etiquetas2);
	imagenesTest.close();



/*

	Matriz x(3,3);7
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
