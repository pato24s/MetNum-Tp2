#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
#include <stdlib.h> 
//#include <cassert>
#include "Matriz.h"
using namespace std;

//the following are UBUNTU/LINUX ONLY terminal color codes.
#define RESET   "\033[0m"
#define BLACK   "\033[30m"      /* Black */
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define YELLOW  "\033[33m"      /* Yellow */
#define BLUE    "\033[34m"      /* Blue */
#define MAGENTA "\033[35m"      /* Magenta */
#define CYAN    "\033[36m"      /* Cyan */
#define WHITE   "\033[37m"      /* White */
#define BOLDBLACK   "\033[1m\033[30m"      /* Bold Black */
#define BOLDRED     "\033[1m\033[31m"      /* Bold Red */
#define BOLDGREEN   "\033[1m\033[32m"      /* Bold Green */
#define BOLDYELLOW  "\033[1m\033[33m"      /* Bold Yellow */
#define BOLDBLUE    "\033[1m\033[34m"      /* Bold Blue */
#define BOLDMAGENTA "\033[1m\033[35m"      /* Bold Magenta */
#define BOLDCYAN    "\033[1m\033[36m"      /* Bold Cyan */
#define BOLDWHITE   "\033[1m\033[37m"      /* Bold White */
//std::cout << RED << "hello world" << RESET << std::endl;


/*struct Imagen
{
	int etiqueta;
	Matriz pixeles;
	Imagen(int e, Matriz p) : etiqueta(e), pixeles(p){}; //puede que no sea de ints
	Imagen(){};
	
};*/

/*
struct Imagenes
{
	vector<Imagen> imags;
	Imagenes(vector<Imagen> v) :	imags(v){}; //puede que no sea de ints
	Imagenes(){};
	
};
*/
struct tuplaDatos
{
	string path;
	int k;
	int alfa;
	int gamma;
	int cantFolds;
	Matriz kfold;
	tuplaDatos(string p, int kn, int a, int g, int cant, Matriz kf) : path(p), k(kn), alfa(a), gamma(g),cantFolds(cant), kfold(kf) {};

	tuplaDatos(){};
};


Matriz lecturaTrain(istream& is, Matriz& etiquetas){
	string etiq;
	double pixel;
	int etiqueta;
	string delim;


	Matriz result = Matriz(42000, 784);

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
	//cout <<j<<endl;
	}

	return result;
}


void mostrarImagen(const Matriz& i){
	
	double aux;
	int m = i.DameAncho();
	//cout << "Su etiqueta es: "<< i.etiqueta<< " y tiene " << i.pixeles.size()  << " pixeles" <<endl;
	for (int t = 0; t < 50; ++t){
		cout<<"-";
	}

	cout<<endl;
	
	for (int j = 1; j<m; ++j){
		aux = i.Obtener(1, j);
		if(aux != 0){
			cout  <<RED<<"0"<<RESET;
		}else{
			cout<<GREEN<<"0"<<RESET;	
		}
		
		if( j % 28 == 0 && j != 0){cout<<endl;}
	}
	cout<<endl;
	for (int f = 0; f < 50; ++f){
		cout<<"-";
	}
	cout<<endl;
	

}

//28000 imagenes
Matriz lecturaTest(istream& is, Matriz& etiquetas){
	Matriz resultante = Matriz(28000, 784);
	string etiq;
	double pixel;
	string delim;


	for (int j = 1; j <= 28000; ++j)	
	{		
		for (int i = 1; i <= 784; ++i)
		{
			getline(is, delim, ' ');
			pixel =atof(delim.c_str());
			resultante.Definir(j, i, pixel);
		}
	getline(is, delim , '/' );
	etiquetas.Definir(j, 1, 10);
	}
	return resultante;	
}
Matriz lecturaFold(istream& is, int k){
	Matriz resultante(42000,k);
	string aux;
	for (int i = 1; i <=k; ++i)
	{
		for (int j = 1; j <= 42000; ++j)
		{
			getline(is, aux, ' ');
			resultante.Definir(j, i, atoi(aux.c_str()));			
		}
	}
	return resultante;

}


Matriz lecturaImagen(istream& is){
	Matriz resultante(1,784);
	string aux;
		for (int j = 1; j <= 784; j++)
		{
			getline(is, aux, ' ');
			cout<<" "<<aux;
			resultante.Definir(1, j, atoi(aux.c_str()));			
		}
	cout<<"parsea bien"<<endl;
	mostrarImagen(resultante);
	return resultante;

}





tuplaDatos lecturaFoldTest(istream& is){

	
	int kvec;
	int alfa;
	int gamma;
	int cantFolds;
	string path;
	string aux;
	getline(is,path,' ');
	getline(is,aux,' ');
	kvec=atoi(aux.c_str());
	getline(is,aux,' ');
	alfa=atoi(aux.c_str());
	getline(is,aux,' ');
	gamma=atoi(aux.c_str());
	getline(is,aux,' ');
	cantFolds=atoi(aux.c_str());
	Matriz resultante(42000,cantFolds);

	for (int i = 1; i <=cantFolds; ++i)
	{
		for (int j = 1; j <= 42000; ++j)
		{
			getline(is, aux, ' ');
			resultante.Definir(j, i, atoi(aux.c_str()));			
		}
	}
	tuplaDatos res(path,kvec,alfa,gamma,cantFolds,resultante);
	return res;

}


void mostrarImagenRecortada(const Matriz& i){
	
	double aux;
	int m = i.DameAncho();
	//cout << "Su etiqueta es: "<< i.etiqueta<< " y tiene " << i.pixeles.size()  << " pixeles" <<endl;
	for (int t = 0; t < 19; ++t){
		cout<<"-";
	}

	cout<<endl;
	
	for (int j = 1; j<m; ++j){
		aux = i.Obtener(1, j);
		if(aux != 0){
			cout  <<RED<<"0"<<RESET;
		}else{
			cout<<GREEN<<"0"<<RESET;	
		}
		
		if( j % 17 == 0 && j != 0){cout<<endl;}
	}
	cout<<endl;
	for (int f = 0; f < 19; ++f){
		cout<<"-";
	}
	cout<<endl;
}



bool filaVacia(const Matriz& src,int filaMatriz ,int filaImagen){
	bool filaEsVacia=true;
	int i=0;
	while(i<28){
		filaEsVacia= (src.Obtener(filaMatriz,filaImagen)==0) && filaEsVacia;
		i++;
		filaImagen++;
	}
	return filaEsVacia;
}

void promedioArribaYAbajo(const Matriz& source,int& arriba,int& abajo){
	int sumaPromedioAlto=0;
	int sumaPromedioAbajo=0;
	int fila=source.DameAlto();
	int sumaFilaArriba;
	int sumaFilaAbajo;

	for (int i = 1; i <= fila; ++i){
		bool esAbajo=false;
		sumaFilaArriba=0;
		sumaFilaAbajo=0;
		int t=1;
		while(t<784){
			if(esAbajo){
				if(filaVacia(source,i,t)){
					sumaFilaAbajo++;
				}
			}else{
				if(filaVacia(source,i,t)){
					sumaFilaArriba++;
				}else{
					esAbajo=true;
				}
			}

			t=t+28;
		}
		sumaPromedioAlto=sumaPromedioAlto+sumaFilaArriba;
		sumaPromedioAbajo=sumaPromedioAbajo+sumaFilaAbajo;

	}
	sumaPromedioAlto=sumaPromedioAlto/fila;
	sumaPromedioAbajo=sumaPromedioAbajo/fila;
	arriba=sumaPromedioAlto;
	abajo=sumaPromedioAbajo;
}

bool columnaVacia(const Matriz& src,int t,int f){
	int alto=src.DameAlto();
	int ancho=src.DameAncho();
	bool columnaesVacia=true;
	int i=0;
	while(i<28){
		
		columnaesVacia = (src.Obtener(t,f)==0) && columnaesVacia;
		//cout<<"Itaracion Numero: "<<f<<" EL VALOR  "<<src.Obtener(t,f)<<endl;
		f=f+28;
		i++;
	}
	return columnaesVacia;
}

void promedioAnchoIzqYDer(const Matriz& source,int& izq,int& der){

	int sumaPromedioIzquierda=0;
	int sumaPromedioDerecha=0;
	int fila = source.DameAlto();
	int columnaDondeEmpiezaIzquierda;
	int columnaDondeEmpiezaDerecha;


	for (int i = 1; i <= fila; ++i){ //calculo todas mis imagenes 
		columnaDondeEmpiezaIzquierda=0;
		columnaDondeEmpiezaDerecha=0;
		bool esDerecha=false;
		for (int t = 1; t <= 28; ++t){
			if(esDerecha){
				if(columnaVacia(source,i,t)){
					columnaDondeEmpiezaDerecha=columnaDondeEmpiezaDerecha+1;
				}
			}else{
				if(columnaVacia(source,i,t)){
					columnaDondeEmpiezaIzquierda=columnaDondeEmpiezaIzquierda+1;
					//cout<<"pepeeee :"<<columnaVacia(source,i,t)<<endl;
					}else{
					esDerecha=true;
					}
				}	
		}
		//mostrarImagen(source);
		sumaPromedioIzquierda = sumaPromedioIzquierda + columnaDondeEmpiezaIzquierda;
		sumaPromedioDerecha   = sumaPromedioDerecha+columnaDondeEmpiezaDerecha;
	}

	sumaPromedioIzquierda = sumaPromedioIzquierda/fila;
	sumaPromedioDerecha= sumaPromedioDerecha/fila;
	izq =sumaPromedioIzquierda;
	der =sumaPromedioDerecha;
}

// TOMA UNA MATRIZ DE 1,784 Y ME DEVUELVE UNA DE 1,357
Matriz recortarImagen(Matriz& src,int arriba,int abajo,int izq,int der){
	//HACER UN CROPFLIP PAPA
	Matriz res(1,357);
	int tamx=17;//lo hardcodeo a mano
	int tamy=21;
	int y=0;
	int x=0;
	int primerFila;
	int columna;
	int pos=1;
	//cicloFilas
	while(y<tamy){
		//Arrlgo mi fila
		x=0;
		primerFila = arriba*28;
		while(x<tamx){
			columna = primerFila;
			double aux= src.Obtener(1,columna);
			res.Definir(1,pos,aux);
			x++;
			columna++;
			pos++;
		}
		primerFila+28;
		y++;
	}
	return res;
}
//NUESTRO CASO ES 4,3,6,5 Y NOS DEVUELVE UNA MATRIZ DE 42000 IMAGENES DE TAMANIO 357 matriz(42000,357) es decir el 45% de la imagen original
Matriz recortarTodas(Matriz& src,int arriba,int abajo,int izq,int der){
	Matriz res(42000,357);
	Matriz aux(1,784);
	int fila = src.DameAlto();
	for (int i = 1; i <= fila; ++i){
		//Estoy en la iesima imagen a recortar;
		src.insertarEnFila1(aux,1,i);
		Matriz resParcial = recortarImagen(aux,arriba,abajo,izq,der);
		resParcial.insertarEnFila1(res,i,1);	
	}
	return res;
}
/*
int promedioAltoArriba(const Matriz& source){

	int sumaPromedio=0;
	int fila = source.DameAlto();
	cout<<"AASDJASHCAJSCHAS "<<fila<<endl;
	int filaDondeEmpieza;
	bool Empece;

	for (int i = 1; i < fila; ++i){ //calculo todas mis imagenes 
		Empece = false;
		filaDondeEmpieza = 0;
		for (int t = 0; t < 784; ++t){
			if(!Empece){
				if(t%28 ==0){
					filaDondeEmpieza=filaDondeEmpieza+1;
				}else{
					Empece= source.Obtener(i,t) != 0;
					//cout<<"EL NUMERO QUE ESTA EN "<<i<<", "<<t<<" : "<<source.Obtener(i,t)<<endl;
					//mostrarImagen(source);
				}
			}
		}
		//cout<<" FILA DONDE EMPIEZA IMAGEN "<<i<<" "<<filaDondeEmpieza<<endl;
		sumaPromedio = sumaPromedio + filaDondeEmpieza-1;
	}
	
	sumaPromedio = (sumaPromedio/fila); //ver que onda esto
	return sumaPromedio;
}

int promedioAltoAbajo(const Matriz& source){

	int sumaPromedio=0;
	int fila = source.DameAlto();
	int filaDondeEmpieza;
	bool Empece;

	for (int i = 1; i < fila; ++i){ //calculo todas mis imagenes 
		Empece = false;
		filaDondeEmpieza = 0;

		Empece = false;
		filaDondeEmpieza = 0;
		for (int t = 783; t >=0 ; --t){
			if(!Empece){
				if(t%28 ==0){
					filaDondeEmpieza=filaDondeEmpieza+1;
				}else{
					Empece= source.Obtener(i,t) != 0;
					//cout<<"EL NUMERO QUE ESTA EN "<<i<<", "<<t<<" : "<<source.Obtener(i,t)<<endl;
					//mostrarImagen(source);
				}
			}
		}
		
		sumaPromedio = sumaPromedio + filaDondeEmpieza;
	}
	sumaPromedio = sumaPromedio/fila -1; //ver que onda esto
	return sumaPromedio;
}
*/

/*
int promedioAnchoDerecha(const Matriz& source){// revisar esta verga que 
	
	int sumaPromedio=0;
	int fila = source.DameAlto();
	bool noEmpece;
	int filaImagen;
	int filaImagen1;
	int columnaDondeEmpieza;
	int contador;

	for (int i = 0; i < fila; ++i){ //calculo todas mis imagenes 
		noEmpece = true;
		filaImagen = 0;
		columnaDondeEmpieza = 0;
		contador = 0;
		
		filaImagen1 = 28;
		while(noEmpece){
			 filaImagen = filaImagen1;
			while(contador < 28){
				
				noEmpece = (source.Obtener(i,filaImagen) == 0) && noEmpece;
				filaImagen = filaImagen+28;
				
			}
			if(noEmpece){
				columnaDondeEmpieza++;
			}
			filaImagen1--;
									
		}

		sumaPromedio = sumaPromedio + columnaDondeEmpieza;

	}

	sumaPromedio = sumaPromedio/fila -1; //ver que onda esto
	return sumaPromedio;
}
*/
/* Matriz convertirAMatrizTrain(Imagenes img, Matriz& etiquetas ){
 	// etiquetas = 784x1
 	assert(etiquetas.DameAlto() == 37000);
 	assert (img.imags.size() == 5000 && img.imags[0].pixeles.size() == 784);
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
*/
/*Matriz convertirAMatrizTest(Imagenes img, Matriz& etiquetas ){
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
 }*/