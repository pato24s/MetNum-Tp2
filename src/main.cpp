
#include "lectura.cpp"
#include "metodos.cpp"

int main(int argc, char const *argv[])
{
	
	
	ifstream imagenesTrain;
	imagenesTrain.open("../data/train.dat");
	Imagenes train = lecturaTrain(imagenesTrain);
	imagenesTrain.close();

	
	ifstream imagenesTest;
	imagenesTest.open("../data/test.dat");
	Imagenes tests = lecturaTest(imagenesTest);	
	imagenesTest.close();


	Imagen img = tests.imags[51];
	mostrarImagen(img);

	cout<< "El digito es: "<< knn(img, train,  5)<<endl;






	return 0;
}
