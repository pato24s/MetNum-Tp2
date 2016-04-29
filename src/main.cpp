
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
	prueba.Definir(1,1, 1);
	prueba.Definir(1,2, 0);
	prueba.Definir(1,3, 0);
	prueba.Definir(2,1, 0);
	prueba.Definir(2,2, 2);
	prueba.Definir(2,3, 0);
	prueba.Definir(3,1, 0);
	prueba.Definir(3,2, 0);
	prueba.Definir(3,3, 1);
	Matriz random = Matriz(3,1);
	random.Definir(1,1, 1);
	random.Definir(2,1, 1);
	random.Definir(3,1, 1);
	cout<<prueba<<endl;
	Matriz rt = random.copiarMatriz();
	//rt.mostrarMatriz(cout);
	rt.Traspuesta();
	//random.mostrarMatriz(cout);
	//rt.mostrarMatriz(cout);
	//cout<<random<<endl;
	//cout<<rt<<endl;
	//cout<< rt.multiMatricial(random);
	//cout<<prueba.multiMatricial(random);
	//cout<< rt.multiMatricial(prueba.multiMatricial(random));
	//cout<<rt.multiMatricial(prueba.multiMatricial(random))<<endl;
	cout<<"un autovalor es: "<<prueba.dameAutovalor(random , 10)<<endl;
	
	//cout<< pow(2, -1)<<endl;
	//double a = 1;
	//double b = 2;
	//cout<< double(1/2)<<endl;
	//cout << "El utovector correspondiente a ese autovalor es: ";
	//cout<<random;

	//cout<<random.norma2Vectorial()<<endl;
	//random.Traspuesta();
	//cout<<random.norma2Vectorial();

	//cout<< "El digito es: "<< knn(img, train,  5)<<endl;






	return 0;
}
