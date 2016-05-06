#include <cassert>
#include <math.h>

struct tuplaDistanciaEtiq
{	int etiqueta;
	float distancia;
	tuplaDistanciaEtiq(int e, float d) : etiqueta(e), distancia(d){}; //puede que no sea de ints
	tuplaDistanciaEtiq(){};
	
};

void selectionSortVoid(vector<tuplaDistanciaEtiq>& v) {
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

int lugarMaximo(vector<int> v){
	int max = 0;
	for (int i = 0; i <= 9; ++i)
	{
		if(v[i]> v[max]){
			max = i;
		}
	}

	return max;

}



float normaResta(vector<int> &a, vector<int> &b){
	assert(a.size() == b.size());
	float res = 0;
	for (int i = 0; i < a.size(); ++i)
	{
		res = res + (a[i] - b[i])*(a[i] - b[i]);
	}
	res = sqrt(res);
	return res;
}

int moda(vector <tuplaDistanciaEtiq> v, int k ){ //k me dice cuantos ver para sacar la moda
	
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




int knn(Imagen e, Imagenes t, int k){ //devuelve la etiqueta
	//e imagen para etiquetar
	int n = t.imags.size(); //n es la cantidad de imagenes qe tengo en mi campo train
	vector<tuplaDistanciaEtiq> distancias;
	float aux;
	for (int i = 0; i < n; ++i)
	{
		 aux = normaResta(e.pixeles, t.imags[i].pixeles );
		 distancias.push_back( tuplaDistanciaEtiq(t.imags[i].etiqueta, aux) );
	}

	selectionSortVoid(distancias); //los ordeno de acuerdo a las distancias de menor a mayor
	
	return moda(distancias, k); //la etiqueta del minimos
}





























