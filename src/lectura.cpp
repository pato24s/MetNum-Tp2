#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
#include <stdlib.h> 
#include "Matriz.h"
//#include <cassert>
using namespace std;



struct Imagen
{
	int etiqueta;
	Matriz pixeles;
	Imagen(int e, Matriz p) : etiqueta(e), pixeles(p){}; //puede que no sea de ints
	Imagen(){};
	
};

/*
struct Imagenes
{
	vector<Imagen> imags;
	Imagenes(vector<Imagen> v) :	imags(v){}; //puede que no sea de ints
	Imagenes(){};
	
};
*/

Matriz lecturaTrain(istream& is, Matriz& etiquetas){
	string etiq;
	double pixel;
	int etiqueta;
	string delim;
	Matriz result;

	for (int j = 1; j <= 42000; ++j)	
	{
		getline (is, etiq, '_');
		etiqueta= atof(etiq.c_str());
		for (int i = 1; i <= 783; ++i)
		{
			getline(is, delim, ' ');
			pixel =atof(delim.c_str());
			//vectorAux.push_back(pixel);
			result.Definir(j,i,pixel);
		}

	getline(is, delim, '/' );
	pixel = atof(delim.c_str());
	//vectorAux.push_back(pixel);
	result.Definir(j, 784, pixel);
	etiquetas.Definir(j,1,etiqueta);
	//Imagen imgAux = Imagen(etiqueta, vectorAux);
	//result.push_back(imgAux);		
		
	}

	return result;
}

//28000 imagenes
Imagenes lecturaTest(istream& is){
	string etiq;
	double pixel;
	string delim;

	vector<Imagen> result;

	for (int j = 1; j <= 28000; ++j)	
	{		
		vector<int> vectorAux;
		for (int i = 1; i <= 784; ++i)
		{
			getline(is, delim, ' ');
			pixel =atof(delim.c_str());
			vectorAux.push_back(pixel);
		}
	getline(is, delim , '/' );

	Imagen imgAux = Imagen(10, vectorAux); //le pongo la etiqueta 10 para indicar que todavia no tienen etiquetas
	result.push_back(imgAux);		
		
	}

	return Imagenes(result);
}

void mostrarImagen(Imagen i){
	
	int aux;
	cout << "Su etiqueta es: "<< i.etiqueta<< " y tiene " << i.pixeles.size()  << " pixeles" <<endl;
	for (int j = 0; j<i.pixeles.size(); ++j)
	{
		aux = i.pixeles[j];
		cout<< aux << " "; 		
		if( j % 28 == 0 && j != 0){cout<<endl;}
	}
	cout<<endl;


}

 Matriz convertirAMatrizTrain(Imagenes img, Matriz& etiquetas ){
 	// etiquetas = 784x1
 	assert(etiquetas.DameAlto() == 42000);
 	assert (img.imags.size() == 42000 && img.imags[0].pixeles.size() == 784);
 	Matriz resultante = Matriz(42000, 784);
 	for (int i = 0; i < 42000; ++i)
 	{
 		for (int j = 0; j < 784; ++j)
 		{
 			resultante.Definir(i+1, j+1, img.imags[i].pixeles[j] );
 		}
 		etiquetas.Definir(i+1, 1, img.imags[i].etiqueta);
 	}

 	return resultante;
 } 

Matriz convertirAMatrizTest(Imagenes img, Matriz& etiquetas ){
 	// etiquetas = 784x1

 	assert(etiquetas.DameAlto() == 28000);
 	Matriz resultante = Matriz(28000, 784);
 	for (int i = 0; i < 28000; ++i)
 	{
 		for (int j = 0; j < 784; ++j)
 		{
 			resultante.Definir(i+1, j+1, img.imags[i].pixeles[j]);
 		}
 		etiquetas.Definir(i+1, 1, img.imags[i].etiqueta);
 	}

 	return resultante;
 }