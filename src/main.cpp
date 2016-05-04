
#include "lectura.cpp"
//#include "metodos.cpp"
#include "Matriz.h"
#include <math.h>       /* pow */
int main(int argc, char const *argv[])
{
	
	
	/*ifstream imagenesTrain;
	imagenesTrain.open("../data/train.dat");
	Imagenes train = lecturaTrain(imagenesTrain);
	imagenesTrain.close();

	
	ifstream imagenesTest;
	imagenesTest.open("../data/test.dat");
	Imagenes tests = lecturaTest(imagenesTest);	
	imagenesTest.close();


	Imagen img = tests.imags[51];
	mostrarImagen(img);
*/
	Matriz prueba = Matriz(3,3);
	prueba.Definir(1,1, 3);
	prueba.Definir(1,2, 0);
	prueba.Definir(1,3, 0);
	prueba.Definir(2,1, 0);
	prueba.Definir(2,2, 2);
	prueba.Definir(2,3, 0);
	prueba.Definir(3,1, 0);
	prueba.Definir(3,2, 0);
	prueba.Definir(3,3, 1);
	/*
	Matriz random = Matriz(3,1);
	random.Definir(1,1, 1);
	random.Definir(2,1, 1);
	random.Definir(3,1, 1);
	cout<<prueba<<endl;
	Matriz rt = random.copiarMatriz();
	rt.Traspuesta();
	double autovalor =prueba.dameAutovalor(random , 30);*/
	/*cout<<"un autovalor es: "<<autovalor<<endl;
	//Matriz randi = Matriz(3, 3);
	cout<< "el autovector asociado es:";
	random.mostrarMatriz(cout);
	//randi.mostrarMatriz(cout);
	prueba = prueba.deflacion(autovalor, random);
	cout<<"deflaciado queda: ";
	prueba.mostrarMatriz(cout);
	random.Definir(1,1, 2);
	random.Definir(2,1, 3);*/
//	random.Definir(3,1, 1);
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



	return 0;
}
