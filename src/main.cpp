
#include "lectura.cpp"
#include "metodos.cpp"

int main(int argc, char const *argv[])
{
	
	
	ifstream imagenesTrain;
	imagenesTrain.open("../data/train.dat");
	Imagenes train = lecturaTrain(imagenesTrain);

	/*int size = v.imags[41999].pixeles.size();
	for (int i = 0; i < size; ++i)
	{	
		int a = v.imags[41999].pixeles[i];
		cout<<a<<' ';
	}
	cout<<endl;
	cout<< "y la etiqueta es: "<< v.imags[41999].etiqueta;*/
	imagenesTrain.close();
	
	ifstream imagenesTest;
	imagenesTest.open("../data/test.dat");
	Imagenes tests = lecturaTest(imagenesTest);
	/*int size = v.imags[27999].pixeles.size();
	for (int i = 0; i < size; ++i)
	{	
		int a = v.imags[27999].pixeles[i];
		cout<<a<<' ';
	}
	cout<<endl;
	cout<< "y la etiqueta es: "<< v.imags[27999].etiqueta;*/
	




	imagenesTest.close();
	return 0;
}
