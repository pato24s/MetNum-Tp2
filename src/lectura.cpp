#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
#include <stdlib.h> 
using namespace std;



struct Imagen
{
	int etiqueta;
	vector<int> pixeles;
	Imagen(int e, vector<int> v) : etiqueta(e), pixeles(v){}; //puede que no sea de ints
	Imagen(){};
	
};

struct Imagenes
{
	vector<Imagen> imags;
	Imagenes(vector<Imagen> v) :	imags(v){}; //puede que no sea de ints
	Imagenes(){};
	
};


Imagenes lecturaTrain(istream& is){
	string etiq;
	int pixel;
	int etiqueta;
	string delim;

	vector<Imagen> result;

	for (int j = 1; j <= 42000; ++j)	
	{
		getline (is, etiq, '_');
		etiqueta= atoi(etiq.c_str());
		vector<int> vectorAux;
		for (int i = 1; i <= 783; ++i)
		{
			getline(is, delim, ' ');
			pixel =atoi(delim.c_str());
			vectorAux.push_back(pixel);
		}

	getline(is, delim, '/' );
	Imagen imgAux = Imagen(etiqueta, vectorAux);
	result.push_back(imgAux);		
		
	}

	return Imagenes(result);
}

//28000 imagenes
Imagenes lecturaTest(istream& is){
	string etiq;
	int pixel;
	int etiqueta;
	string delim;

	vector<Imagen> result;

	for (int j = 1; j <= 28000; ++j)	
	{
		getline (is, etiq, '_');
		etiqueta= atoi(etiq.c_str());
		vector<int> vectorAux;
		vectorAux.push_back(etiqueta); //en este caso no tiene etiqueta 
		for (int i = 1; i <= 783; ++i)
		{
			getline(is, delim, ' ');
			pixel =atoi(delim.c_str());
			vectorAux.push_back(pixel);
		}

	getline(is, delim, '/' );
	Imagen imgAux = Imagen(10, vectorAux); //le pongo la etiqueta 10 para indicar que todavia no tienen etiquetas
	result.push_back(imgAux);		
		
	}

	return Imagenes(result);
}


