/*#ifndef MATRIZ_H
#define MATRIZ_H*/
#include <vector>
#include <iostream>
#include <math.h> 
#include <cassert>
#include <stdlib.h> 
//#include "lectura.cpp"
#include "metodos.cpp"
using namespace std;



    class Matriz{

    public:

        Matriz();
        Matriz(int al, int an);

        Matriz(vector<vector<double> > v);


        void Definir ( int i,  int j, double s);
        double dameAutovalor(Matriz& x , int iter)const;
        void deflacion(double autovalor,  Matriz& autovector);
        Matriz baseAutovectores(int iter, Matriz& autovalores,int alfa)const;
        //const vector<double>& operator[](int i) const;
        double Obtener ( int i,  int j) const ;
        void insertarEnColumna(Matriz a, int c);
        Matriz Traspuesta();
        Matriz multiMatricial( const Matriz&  b) const; // Result = this*B  this tambien es por referencia sin poder modificar?
        Matriz multiEscalar(double a) const;
        void sumaMatricial(const Matriz& b );
        Matriz restaMatricial(const Matriz& b); 
        double multi(const Matriz& b, int i, int j )const;
        Matriz copiarMatriz() const;
        double norma2Vectorial() const;
        double norma2Cuadrado() const;
        ostream& mostrarMatriz(ostream&) const;
        void mostrar() const;
        void randomizar(int m, int n);

        Matriz& operator=( const Matriz& a);
        int DameAlto() const;
        int DameAncho() const;

        void Cholesky();

        double sumatoria(const Matriz& a, int i , int j);

        Matriz resolverTI(const Matriz& b) const ;
        Matriz  resolverTS(const Matriz& b) const ;
        Matriz superCholesky(const Matriz& b) ;
        Matriz superCholeskyMismaA(const Matriz& b, const Matriz& lt) const;
        Matriz gauss( Matriz b, int n) ;

        double media(int k) const;
        Matriz centrarConMedia();
        void restarFila(double media, int k);


        Matriz plsDa(Matriz, Matriz, int );

        void cambiarBaseX(int alfa);
        Matriz cambiarIesima(const Matriz& mb,int j);
        void insertarEnFila(Matriz& a, int f); //inserta en la fila f de a el this

        int pca(Matriz,Matriz, int, int alfa);

        void DefinirFila(int, vector<double>);
        vector<double> ObtenerFila(int f);
        void insertarEnFila2(Matriz& a, int f);
        void insertarEnFila1(Matriz& a, int f,int source);


		Matriz multiXtrans() const;


        
    private:

        
        int _alto;
        int _ancho;
        vector<vector<double> > _matriz;
           


    };

    // const vector<double>& Matriz::operator[](int i) const{
    //     return _matriz[i];
    // }
    Matriz::Matriz(){
    	_alto= 0;
    	_ancho=0;
    _matriz= (std::vector<std::vector<double> > ());
    }


    
    Matriz::Matriz(int al, int an): _alto(al), _ancho(an) {
        std::vector<double> v;
        for(int i=0;i<an;i++){
        v.push_back(0);}

       vector<vector<double> > prueba (al,v);
        //vector<int> prueba (5,0);
        _matriz = prueba;
    }
	    
    
    Matriz::Matriz( vector<vector<double> > v){
    	_matriz=v;
    	_alto= v.size();
    	_ancho= v[0].size();
    }

        
    Matriz& Matriz::operator=( const Matriz& a) {
        assert( _alto == a.DameAlto() && _ancho == a.DameAncho());
    	_alto=a._alto;
    	_ancho=a._ancho;
    	_matriz = a._matriz;
    	return *this;
    

    }
  
  
    int Matriz::DameAncho() const{
    	return _ancho;
    }


    int Matriz::DameAlto() const{
    	return _alto;
    }

  
    
    void Matriz::Definir( int i,  int j, double s) {
       assert(i<=_alto && j<=_ancho); 
        
        _matriz[i-1][j-1] = s;
      
    }


    void Matriz::DefinirFila(int f, vector<double> filaNueva){
        _matriz[f-1]=filaNueva;
    }

    vector<double> Matriz::ObtenerFila(int f){
        return _matriz[f-1];
    }
    
    
    
    // double Matriz::Obtener( int i,  int j) const  {
    //     return _matriz[i-1][j-1];
    // }

     double Matriz::Obtener( int i,  int j) const  {
        return _matriz[i-1][j-1];
        
    }



Matriz Matriz::Traspuesta(){
	Matriz result(_ancho,_alto);
	double aux;
	for(int i=0; i<_alto; i++){
		for(int j=0; j<_ancho;j++){
			//cout<<"par i j: "<<i<<" , "<<j<<endl;
			aux=_matriz[i][j];
			result.Definir(j+1,i+1,aux);


		}
	}

    /*int aux2 = _alto;
    _alto = _ancho;
    _ancho = aux2;

    *this=result;*/
    return result;
}


    
ostream& operator<<(ostream& out, const Matriz a){
    return a.mostrarMatriz(out);
}



    
ostream& Matriz::mostrarMatriz(ostream& os) const{
cout<<"------------------"<<endl;

    for(int i=0;i<_alto;i++){
        os<<"[";
        for(int j=0;j<_ancho;j++){
        if(j!=_ancho-1){
        os<<_matriz[i][j]<<",";
        }else{
        os<<_matriz[i][j]<<"]"<<endl;
        }
        }
    }
    cout<<"------------------";

}
    
    
void Matriz::mostrar() const{

cout<<"------------------"<<endl;
    for(int i=0;i<_alto;i++){
        cout<<"[";
        for(int j=0;j<_ancho;j++){
         if(j!=_ancho-1){
        cout<<_matriz[i][j]<<",";
        }else{
        cout<<_matriz[i][j]<<"]"<<endl;
        	}
		}


}
cout<<"------------------";
}

 double Matriz::sumatoria(const Matriz& a, int i, int j){
    double sum=0;
    for(int k=1; k<=j-1;k++){
        sum= sum+Obtener(i,k) * Obtener(j,k);
    }
    return sum;

}


// double MatrixS::sumar_filas_cholesky(const MatrixS& l, unsigned int i, unsigned int j, int h) const{
//     double sum = 0;
//     for (int k = 0; k < h; k++){
//         double a1 = l[i][k];
//         double a2 = l[j][k];
//         sum += a1*a2;
//     }
//     return sum;
// }


void Matriz::Cholesky(){ //modifica la a de modo tal que te queda la L
    int n=this->DameAlto();
    double a11= sqrt(this->Obtener(1,1));
    this->Definir(1,1,a11);

    for(int i=2; i<=n; i++){
        this->Definir(i,1,(this->Obtener(i,1)/a11));

    }


    for(int j=2; j<=n-1; j++){
        this->Definir(j,j,sqrt(this->Obtener(j,j)-this->sumatoria(*this,j,j)));
        double ljj=this->Obtener(j,j); 
        for(int r=j+1; r<=n; r++){
            double defino =(this->Obtener(r,j)-this->sumatoria(*this,r,j))/ljj;
            this->Definir(r,j,defino);
        }
        
    
    }
    double auxiliar= this->Obtener(n,n)- this->sumatoria(*this,n,n);
this->Definir(n,n,sqrt(auxiliar));

}

Matriz Matriz::resolverTS( const Matriz& b) const {
    int n = this->DameAlto();
    Matriz result(n, 1); //matriz columna de resultados
    double  q = b.Obtener(n, 1) / this->Obtener(n, n);
    result.Definir(n, 1, q);
    //result.mostrar();
    double  acum;
    for (int i = n-1; i >=1; --i)
    {
        acum = 0;
        for (int j = i+1; j <= n ; ++j)
        {
        
            acum = acum + this->Obtener(i, j)*result.Obtener(j, 1);
            
        }
        

        q = (b.Obtener(i, 1) - acum )/this->Obtener(i, i);
        
        result.Definir(i, 1, q);
    }

    return result;
}

Matriz Matriz::resolverTI(const Matriz& b) const{

    int n = this->DameAlto();
    Matriz result(n, 1); //matriz columna de resultados
    double  q = b.Obtener(1, 1) / this->Obtener(1, 1);
    result.Definir(1, 1, q);
    double  acum;
    for (int i = 2; i <= n; ++i)
    {
        acum = 0;
        for (int j = 1; j <= i-1 ; ++j)
        {
            acum = acum + this->Obtener(i, j)*result.Obtener(j, 1);
        }

        q = (b.Obtener(i, 1) - acum )/this->Obtener(i, i);
        result.Definir(i, 1, q);
    }

    return result;
}




Matriz Matriz::superCholesky(const Matriz& b){
/*
    Matriz l = *this;
     l.Cholesky();
    Matriz y = l.resolverTI(b);
    l.Traspuesta();
    return l.resolverTS(y);*/
}

Matriz Matriz::superCholeskyMismaA(const Matriz& b, const Matriz& lt) const{
    Matriz y = this->resolverTI(b);
    return lt.resolverTS(y);
}






Matriz Matriz::gauss( Matriz b, int n) {
    for(int i=1; i<n;i++){
        for(int j=i+1;j<=n;j++){
            double Mji=this->Obtener(j,i)/this->Obtener(i,i);
            
            if(Mji != 0){
            for(int k=i;k<=n;k++){
                double  p = this->Obtener(j, k) - Mji*(this->Obtener(i, k)); 
                        this->Definir(j, k, p);
            }

            double  a = b.Obtener(j, 1) - Mji*(b.Obtener(i, 1));
                    b.Definir(j, 1, a);
        }
    }
}
    return this->resolverTS(b);
}


Matriz Matriz::multiXtrans() const{
	Matriz result(DameAlto(),DameAlto());
	int fila1=1;
	while(fila1<=DameAlto()){
        if(fila1 % 100==0){
		  cout<<"iteracion "<<fila1<<endl;
        }
		int fila2=1;
		while(fila2<=DameAlto()){
			int i=1;
			int r=0;
			while(i<=DameAncho()){
				double aux=(_matriz[fila1-1][i-1]);
				if(fila1==fila2){
					r=r+(aux*aux);
				}else{
				r=r+(aux)*(_matriz[fila2-1][i-1]);
				}
				i++;

			}
			result.Definir(fila1,fila2,r);
			r = 0;
			fila2++;
		}
		fila1++;
	}
	return result;


}


Matriz Matriz::multiMatricial( const Matriz&  b) const{
    int m = this->DameAlto();
    int n = this->DameAncho();
    int k = b.DameAncho();
    assert(n == b.DameAlto());

 	Matriz resultante(m,k);
    double aij;
    for (int i = 1; i <= m; ++i)
    {  
    	//cout<<"multiplicacion numero "<<i<<endl;
        for (int j = 1; j <= k; ++j)
        {
            //cout<<" "<<i<<"    "<<j<<"   "<<endl;
            resultante.Definir(i, j, this->multi(b, i, j));
        }
    }
    return resultante;
}

Matriz Matriz::multiEscalar(double a) const{
    int m = _alto; //m filas
    int n = _ancho; //n columnas
    double aux;
    Matriz resultante = Matriz(m, n);
    for (int i = 1; i <= m; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            aux = a*this->Obtener(i, j);
            resultante.Definir(i, j, aux);
        }
                
    }
    return resultante;

}

void Matriz::sumaMatricial(const Matriz& b ){
    int m = this->DameAlto();
    int n = this->DameAncho();
    assert(b.DameAlto() == m && b.DameAncho() == n);
    Matriz resultante = Matriz(m, n);
    double resta;
    for (int i = 1; i <= m; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            resta = this->Obtener(i, j) + b.Obtener(i, j);
            this->Definir(i, j, resta);
        }
    }
}

Matriz Matriz::restaMatricial(const Matriz& b ){
	Matriz c= b.multiEscalar(-1);
	this->sumaMatricial(c);
}

double Matriz::norma2Vectorial() const{
    int m = _alto;
    int n = _ancho;
    assert(n*m == n || n*m == m); //son vectores
    double norma = 0;
    double aux;
    if(n*m == n){ //vector fila
        for (int i = 1; i <= n; ++i)
        {
            aux = this->Obtener(1, i);
            norma = norma + (aux*aux);
        }
            norma = sqrt(norma);
    }
    else{ //vector columna
        for (int i = 1; i <= m; ++i)
        {
            aux = this->Obtener(i, 1);
            norma = norma + (aux*aux);
        }
            norma = sqrt(norma);

    }
    return norma;

}


double Matriz::norma2Cuadrado() const{
    int m = _alto;
    int n = _ancho;
    assert(n*m == n || n*m == m); //son vectores
    double norma = 0;
    double aux;
    if(n*m == n){ //vector fila
        for (int i = 1; i <= n; ++i)
        {
            aux = this->Obtener(1, i);
            norma = norma + (aux*aux);
        }
    }
    else{ //vector columna
        for (int i = 1; i <= m; ++i)
        {
            aux = this->Obtener(i, 1);
            norma = norma + (aux*aux);
        }

    }
    return norma;

}



Matriz Matriz::copiarMatriz()const{
    int m = _alto;
    int n = _ancho;
    Matriz copia = Matriz(m, n);
    double aux;
    for (int i = 1; i <= m; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            aux = this->Obtener(i, j);
            copia.Definir(i, j, aux);                       
        }
    }
    return copia;
}




double Matriz::multi(const Matriz& b, int i, int j )const{ //fila i (this) * col j(b);
    double res = 0;
    int n = _ancho;
    double aik;
    double bkj;
    for (int k = 1; k <= n; ++k)
    {

        aik = this->Obtener(i, k);
        bkj = b.Obtener(k,j);
        res = res + (aik*bkj);
    }
    return res;
}





double Matriz::dameAutovalor(Matriz& x , int iter)const{
    Matriz autovalor = Matriz(1, 1);
    double normaCuadrado;
    Matriz v = x.copiarMatriz();
    for (int i = 1; i <= iter; ++i)
    {   
    	//cout<<"dame autovalor "<<i<<endl;
        v = this->multiMatricial(v);
        double norma = v.norma2Vectorial(); //tiene que darme 1/norma
        norma = pow(norma, -1);
        v = v.multiEscalar(norma);
    }
    Matriz vt = v.Traspuesta();
    normaCuadrado = v.norma2Cuadrado();
    autovalor = vt.multiMatricial(this->multiMatricial(v)).multiEscalar(normaCuadrado);
    x = v; //esto debería dejar en x el autovector
    return autovalor.Obtener(1,1);
}

void Matriz::deflacion(double a,  Matriz& v ){
	cout<<"DEFLACIOOOOOOOOOOOOOOOOOON"<<endl;
    //Matriz vt = v.Traspuesta();
    //Matriz vvt = v.multiMatricial(vt);
    Matriz vvt = v.multiXtrans();
    vvt = vvt.multiEscalar(-a);
    //vvt.mostrarMatriz(cout);
    this->sumaMatricial(vvt);
}

Matriz Matriz::baseAutovectores(int iter, Matriz& autovalores, int alfa)const {
    int m = this->DameAlto();
    int n = this->DameAncho();
    assert(m==n);
    Matriz copia = *this;
    Matriz resultante = Matriz(m,n);
    for (int i = 1; i <= alfa; ++i)
    {
    	//cout<<"iteracion base numero "<<i<<endl;
        Matriz autovector = Matriz(m, 1);
        autovector.randomizar(m, 1);
        double autovalor = copia.dameAutovalor(autovector, iter); //esto me deja en randi el autovector y devuelve el autovalor
        autovalores.Definir(i, 1, autovalor);
        resultante.insertarEnColumna(autovector, i);
		copia.deflacion(autovalor, autovector);
    }
    return resultante;
}

void Matriz::insertarEnColumna(Matriz a, int c){
    int m = this->DameAlto();
    assert(a.DameAlto() == m);
    for (int i = 1; i <= m; ++i)
    {
        double aux = a.Obtener(i, 1);
        this->Definir(i, c, aux);
    }

}


void Matriz::randomizar(int m, int n){
     srand (time(NULL));
     for (int i = 1; i <= m; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                double randi = rand();
                this->Definir(i, j, randi);
            }
        }   
}


double Matriz::media(int k) const{ //media de la fila k de la matriz
    double media = 0;
    int n = this->DameAncho();
    int m = this->DameAlto();

    for (int i = 1; i <= n; ++i)
    {
        media = media + this->Obtener(k, i);
    }
    media = media/n;
    return media;
}



Matriz Matriz::centrarConMedia(){ //ojo que tambien me modifica this
        int n = this->DameAlto();
        int m = this->DameAncho();
        double media;
        double raiz = sqrt(n-1);
        raiz = pow(raiz, -1);

        for (int i = 1; i <= n; ++i)
        {
            media = this->media(i);     //media de la fila i
            this->restarFila(media, i);
        }
        return this->multiEscalar(raiz);
}

void Matriz::restarFila(double media, int k){
    int m = this->DameAncho();
    double aux;
    for (int i = 1; i <=m; ++i)
    {
        aux = this->Obtener(k,i);
        aux = aux - media;
        this->Definir(k, i, aux);
    }
}


void Matriz::cambiarBaseX(int alfa){ //en this le paso los x(i) que son las imagenes
	int n=this->DameAlto();
    cout<<"vamo a centrarno "<<endl;
	Matriz xCentrada=this->centrarConMedia();
    cout<<"vamo a copiarno "<<endl;
	Matriz xt=xCentrada.Traspuesta();
    cout<<"la traspuesta que te pario "<<endl;
    cout<<"vamo a multiplicarno "<<endl;
	//Matriz m=xt.multiMatricial(xCentrada);
	Matriz m=xt.multiXtrans();
    Matriz autovalores(784,1);
    cout<<"vamo a basearno "<<endl;
	Matriz mb=m.baseAutovectores(30, autovalores,alfa);
	for (int i = 1; i <= n; ++i)
	{  
        if(i%1000==0){
            cout<<"vamo la putas: "<<i<<endl;
        }
		this->cambiarIesima(mb,i).insertarEnFila2(*this, i); //inserto la i-esima fila cambiada de base en this
		
	}
}

void Matriz::insertarEnFila2(Matriz& a, int f){
    a.DefinirFila(f,ObtenerFila(1));
}


void Matriz::insertarEnFila1(Matriz& a, int f, int source){
    int n = this->DameAncho();
    for (int i = 1; i <= n; ++i)
    {
       a.Definir(f, i, this->Obtener(source,i));
    }

}

void Matriz::insertarEnFila(Matriz& a, int f){
    int n = this->DameAncho();
    for (int i = 1; i <= n; ++i)
    {
       a.Definir(f, i, this->Obtener(1, i));
    }

}


Matriz Matriz::cambiarIesima(const Matriz& mb,int j){ //tengo que multiplicar la fila j-esima de this por la matriz mb
    //mas vale que mb tenga m filas
    Matriz resultante (1, this->DameAncho());

    int m = mb.DameAncho();
    for (int i = 1; i <= m; ++i)
    {
    	//cout<<"iteracion cambiar "<<i<<endl;
        double rji= this->multi(mb, j, i);
        resultante.Definir(1, i, rji);
    }
    return resultante; //la j-esima columna de this cambiada de base
}
struct tuplaDistanciaEtiq
{   int etiqueta;
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



double normaResta(Matriz& a, Matriz& b, int f){
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




int knn(Matriz& e, Matriz& etiquetasT, Matriz& t, int k){ //devuelve la etiqueta de la imagen e, comparando con las imagenes de t
    //e imagen para etiquetar
    // etiquetasT tiene las etiquetas de las imagenes de t como un vector columna
    int n = t.DameAlto(); //n es la cantidad de imagenes qe tengo en mi campo train
    vector<tuplaDistanciaEtiq> distancias;
    double aux;
    //cout<<"ciclo distancias"<<endl;
    for (int i = 1; i <= n; ++i)
    {
        //cout<<"norma resta "<<i<<endl;
         aux = normaResta(e, t, i); //la distancia entre la imagen e y la i-esima imagen de t
         distancias.push_back(tuplaDistanciaEtiq(etiquetasT.Obtener(i, 1),aux));
    }
    //cout<<"sorting time "<<endl;
    selectionSortVoid(distancias); //los ordeno de acuerdo a las distancias de menor a mayor
    
    return moda(distancias, k); //la etiqueta del minimos
}


int Matriz::pca(Matriz imagen,Matriz etiquetasT, int k, int alfa){
	cout<<"PCA CAMBIAR BASE 1"<<endl;
	this->cambiarBaseX(alfa);
	cout<<"PCA CAMBIAR DE BASE 2"<<endl;
	imagen.cambiarBaseX(alfa);
    cout<<"se larga knn"<<endl; 
	return knn(imagen,etiquetasT,*this,k);
}









/*

Matriz Matriz::plsCompleto(Matriz x, int gamma){









	return pls(x.centrarConMedia(), y,gamma);
}





Matriz Matriz::pls(Matriz x, Matriz y, int gamma){
	Matriz result=Matriz(x.DameAncho(),x.DameAncho());
	for (int i = 1; i <= gamma; i++){
		Matriz xt=x.copiarMatriz();
		xt.Traspuesta();
		Matriz yt=y.copiarMatriz();
		yt.Traspuesta();
		
		//3 definir Mi como cuenta magica
		Matriz Mi=(xt.multiMatricial(y)).multiMatricial(yt.multiMatricial(x));
		Matriz wi=Matriz(Mi.DameAlto(),1);
		wi.randomizar(Mi.DameAlto(),1);
		
		//4 calcular wi como el autovector
		double autoValorGdeMi=Mi.dameAutovalor(wi,30);
		
		//5 normalizar
		double normaWi=wi.norma2Vectorial();
		double unoSobreNorma=1/normaWi;
		wi.multiEscalar(unoSobreNorma);

		//6 definir ti como Xwi
		Matriz ti=x.multiMatricial(wi);

		//7. normalizo ti
		double normaTi=ti.norma2Vectorial();
		double unoSobreNormaTi=1/normaTi;
		ti.multiEscalar(unoSobreNormaTi);

		//8 actualizar X
		Matriz Tt=x.copiarMatriz();
		Tt.Traspuesta();
		Matriz TiTit=ti.multiMatricial(Tt);
		Matriz TiTitX=TiTit.multiMatricial(x);
		x = x.restaMatricial(TiTitX);

		//9 actualizar Y
		y= y.restaMatricial(TiTit.multiMatricial(y));


		//meto wi en el resultado
		result.insertarEnColumna(wi,i);

	}
	return result;

}

Matriz Matriz::plsDa(Matriz x, Matriz y, int gamma){
	Matriz result=Matriz(x.DameAncho(),x.DameAncho());
	for (int i = 1; i <= gamma; i++){
		Matriz xt=x.copiarMatriz();
		xt.Traspuesta();
		Matriz yt=y.copiarMatriz();
		yt.Traspuesta();
		
		//3 definir Mi como cuenta magica
		Matriz Mi=(xt.multiMatricial(y)).multiMatricial(yt.multiMatricial(x));
		Matriz wi=Matriz(Mi.DameAlto(),1);
		wi.randomizar(Mi.DameAlto(),1);
		
		//4 calcular wi como el autovector
		double autoValorGdeMi=Mi.dameAutovalor(wi,30);
		
		//5 normalizar
		double normaWi=wi.norma2Vectorial();
		double unoSobreNorma=1/normaWi;
		wi.multiEscalar(unoSobreNorma);

		//6 definir ti como Xwi
		Matriz ti=x.multiMatricial(wi);

		//7. normalizo ti
		double normaTi=ti.norma2Vectorial();
		double unoSobreNormaTi=1/normaTi;
		ti.multiEscalar(unoSobreNormaTi);

		//8 actualizar X
		Matriz Tt=x.copiarMatriz();
		Tt.Traspuesta();
		Matriz TiTit=ti.multiMatricial(Tt);
		Matriz TiTitX=TiTit.multiMatricial(x);
		x = x.restaMatricial(TiTitX);

		//9 actualizar Y
		y= y.restaMatricial(TiTit.multiMatricial(y));


		//meto wi en el resultado
		result.insertarEnColumna(wi,i);

	}
	return result;

}
*/
