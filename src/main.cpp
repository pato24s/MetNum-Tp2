
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
	prueba.Definir(2,1, 1);
	prueba.Definir(2,2, 2);
	prueba.Definir(2,3, 1);
	prueba.Definir(3,1, 1);
	prueba.Definir(3,2, 0);
	prueba.Definir(3,3, 1);
	Matriz random = Matriz(3,1);
	random.Definir(1,1, 1);
	random.Definir(2,1, 1);
	random.Definir(3,1, 1);
	cout<<prueba<<endl;
	Matriz rt = random.copiarMatriz();
	rt.Traspuesta();
	cout<<"un autovalor es: "<<prueba.dameAutovalor(random , 30)<<endl;






	return 0;
}
