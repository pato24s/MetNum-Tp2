//#include <cassert>
//#include <math.h>
#include "Matriz.h"
//#include <vector>

struct tuplaDistanciaEtiq
{	int etiqueta;
	double distancia;
	tuplaDistanciaEtiq(int e, double d) : etiqueta(e), distancia(d){}; //puede que no sea de ints
	tuplaDistanciaEtiq(){};
	
};

void selectionSortVoid(std::vector<tuplaDistanciaEtiq>& v) {
	int actual=0;
	while(actual<v.size()){
	int minimo=actual;
	int j=actual+1;
		while(j<v.size()){
			if(v[j].distancia<v[minimo].distancia){
				minimo=j;
			}
			j++;
		}
	tuplaDistanciaEtiq aux = v[actual];
	v[actual]=v[minimo];
	v[minimo]=aux;
	actual++;

	}
	 
}

int lugarMaximo(std::vector<int> v){
	int max = 0;
	for (int i = 0; i <= 9; ++i)
	{
		if(v[i]> v[max]){
			max = i;
		}
	}

	return max;

}



double normaResta(Matriz a, Matriz b, int f){
	//assert(a.size() == b.size());
	double aux;
	double res = 0;
	for (int i = 1; i <= a.DameAncho(); ++i)
	{
		aux = a.Obtener(1,i) - b.Obtener(f, i);
		res = res + aux*aux;
	}
	res = sqrt(res);
	return res;
}

int moda(std::vector <tuplaDistanciaEtiq> v, int k ){ //k me dice cuantos ver para sacar la moda
	
	vector<int> contadores;
	for (int i = 0; i <= 9; ++i)
	{
		contadores.push_back(0);
	}

	for (int i = 0; i < k ; ++i)
	{
		int aux = v[i].etiqueta;
		contadores[aux]++; //le sumo 1 al lugar que le corresponde a la etiqueta i
	}

	return lugarMaximo(contadores);
	
}




int knn(Matriz e, Matriz etiquetasT, Matriz t, int k){ //devuelve la etiqueta de la imagen e, comparando con las imagenes de t
	//e imagen para etiquetar
	// etiquetasT tiene las etiquetas de las imagenes de t como un vector columna
	int n = t.DameAlto(); //n es la cantidad de imagenes qe tengo en mi campo train
	vector<tuplaDistanciaEtiq> distancias;
	double aux;
	for (int i = 1; i <= n; ++i)
	{
		 aux = normaResta(e, t, i); //la distancia entre la imagen e y la i-esima imagen de t
		 distancias.push_back(tuplaDistanciaEtiq(etiquetasT.Obtener(i, 1),aux));
	}

	selectionSortVoid(distancias); //los ordeno de acuerdo a las distancias de menor a mayor
	
	return moda(distancias, k); //la etiqueta del minimos
}






















