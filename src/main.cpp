
#include "lectura.cpp"
//#include "metodos.cpp"
#include "Matriz.h"
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
	prueba.Definir(1,2, 1);
	prueba.Definir(1,3, 1);
	prueba.Definir(2,1, 1);
	prueba.Definir(2,2, 1);
	prueba.Definir(2,3, 1);
	prueba.Definir(3,1, 1);
	prueba.Definir(3,2, 1);
	prueba.Definir(3,3, 1);
	Matriz random = Matriz(3,1);
	random.Definir(1,1, 2);
	random.Definir(2,1, 0);
	random.Definir(3,1, 4);
	cout<<"un autovalor es: "<<prueba.dameAutovalor(random , 2);
	//cout<<random.norma2Vectorial()<<endl;
	//random.Traspuesta();
	//cout<<random.norma2Vectorial();

	//cout<< "El digito es: "<< knn(img, train,  5)<<endl;






	return 0;
}
