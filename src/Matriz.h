//#ifndef MATRIZ_H
//#define MATRIZ_H
#include <vector>
#include <iostream>
#include <math.h> 
#include <cassert>
#include <stdlib.h> 
#include <algorithm>    // std::random_shuffle
//#include "lectura.cpp"
//#include "metodos.cpp"
using namespace std;
struct tuplaMetricas
{
            vector<double> falsosN;
            vector<double> falsosP;
            vector<double> verdaderosP;
            double hitr;
            tuplaMetricas(vector<double> fn, vector<double> fp, vector<double> vp, double hr) : falsosN(fn) , falsosP(fp) , verdaderosP (vp) , hitr(hr) {}
            tuplaMetricas(){}

            tuplaMetricas& operator =(const tuplaMetricas& copia){
                falsosN=copia.falsosN;
                falsosP=copia.falsosP;
                verdaderosP=copia.verdaderosP;
                hitr=copia.hitr;
                return *this;
            }


};
    // class Matriz;
    // Matriz plsDa(Matriz& x, Matriz& y, int gamma);

    class Matriz{

    public:

        Matriz();
        Matriz(int al, int an);

        Matriz(vector<vector<double> > v);


        void Definir ( int i,  int j, double s);
        double dameAutovalor(Matriz& x , int iter)const;
        void deflacion(double autovalor,  Matriz& autovector);
        Matriz baseAutovectores(int iter, Matriz& autovalores,int alfa);
        Matriz baseAutovectoresConEscritura(ostream&,int , Matriz& , int );



                Matriz baseAutovectoresConVector(vector<double>&,int , Matriz& , int );


        //const vector<double>& operator[](int i) const;
        double Obtener ( int i,  int j) const ;
        void insertarEnColumna(Matriz a, int c);
        Matriz Traspuesta();
        Matriz multiMatricial( const Matriz&  b) const; // Result = this*B  this tambien es por referencia sin poder modificar?
        void multiEscalar(double a);
        void sumaMatricial(const Matriz& b );
        void restaMatricial(Matriz& b); 
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
        void centrarConMedia();
        void restarFila(double media, int k);


        Matriz plsDa(Matriz&, int );
        Matriz plsDaConEscritura(ostream&,Matriz&, int);


                Matriz plsDaConVector(vector<double>&,Matriz&, int);


        void cambiarBaseX(int alfa);
        Matriz cambiarIesima(const Matriz& mb,int j);
        void insertarEnFila(Matriz& a, int f); //inserta en la fila f de a el this

        int pca(Matriz,Matriz, int, int alfa);

        void DefinirFila(int, vector<double>);
        vector<double> ObtenerFila(int f);
        void insertarEnFila2(Matriz& a, int f);
        void insertarEnFila1(Matriz& a, int f,int source);
        void cambiarBaseX2(int alfa, Matriz cambioBase);
        Matriz pcaRapido(Matriz etiquetasTrain, Matriz imagenes, int alfa, int k);
        double productoEscalar(Matriz& a, Matriz& b);

		Matriz multiXtrans() const;


        vector<double> dameVectorMedias();

        void centrarConMediaNuevo(vector<double>, int);

        void cambiarBaseNuevo( Matriz&);
        

        int pcaNuevo(Matriz&,Matriz&, int, int);

        int pcaRapido(Matriz&,Matriz&,Matriz& , int , int);

        void mezclarMatriz();




        int plsNuevo(Matriz& imagen,Matriz& etiquetasT, int k, int gamma);

















        
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
        //assert( _alto == a.DameAlto() && _ancho == a.DameAncho());
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
 

/*
Matriz foldRandom(int n,int k){
Matriz folds(42000,k);
for (int i = 1; i <= k; ++i)
        {
                //srand(time(NULL));
                        for (int x = 1; x <= n/k ; ++x)
                        {
                               cout<<"entra alguna vez aca?"<<endl;
				 int indice = (rand() % 42000) + 1;
                               cout<<"defino en el "<<indice<<" "<<i;
				folds.Definir(indice,i , 1);
                        }
        }
return folds;
}
		        Matriz randomFold(int k ){
        Matriz fold(42000,k);
        for(int i =1 ; i<= k; ++i){
                srand(time(NULL));
                for(int j = 1; j<= 42000/k; ++j){
                int indice = (rand() % 42000)+1;
                fold.Definir(indice, i, 1);
                }
        }
        return fold;
}

   
*/

    
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


	Matriz randomFold(int k ){
	Matriz fold(42000,k);
	for(int i =1 ; i<= k; ++i){
		//srand(time(NULL));
		for(int j = 1; j<= 42000/k; ++j){
		int indice = (rand() % 42000)+1;
		fold.Definir(indice, i, 1);
		}
	}
	return fold;
}

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
        //if(fila1 % 100==0){
		  cout<<"iteracion "<<fila1<<endl;
       // }
		int fila2=1;
		while(fila2<=DameAlto()){
			int i=1;
			double r=0;
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

void Matriz::multiEscalar(double a){
    int m = _alto; //m filas
    int n = _ancho; //n columnas
    double aux;
    //Matriz resultante = Matriz(m, n);
    for (int i = 1; i <= m; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            aux = a*this->Obtener(i, j);
            this->Definir(i, j, aux);
        }
                
    }

}

void Matriz::sumaMatricial(const Matriz& b ){
    int m = this->DameAlto();
    int n = this->DameAncho();
    assert(b.DameAlto() == m && b.DameAncho() == n);
    //Matriz resultante = Matriz(m, n);
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

void Matriz::restaMatricial(Matriz& b ){
	b.multiEscalar(-1);
    //Matriz copia = this*;

	this->sumaMatricial(b);
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


double Matriz::dameAutovalor(Matriz& v , int iter)const{
    Matriz autovalor = Matriz(1, 1);
    double normaCuadrado;
    //Matriz v = x.copiarMatriz();
    for (int i = 1; i <= iter; ++i)
    {   
        v = this->multiMatricial(v);
        double norma = v.norma2Vectorial(); //tiene que darme 1/norma
        norma = pow(norma, -1);
        v.multiEscalar(norma);

    }
    Matriz vt = v.Traspuesta();
    Matriz vTv=vt.multiMatricial(v);
    double denominador=pow(vTv.Obtener(1,1),-1);

    //normaCuadrado = v.norma2Cuadrado();
    Matriz aux = vt.multiMatricial(this->multiMatricial(v));
    aux.multiEscalar(denominador);
    //x = v; //esto debería dejar en x el autovector
    return aux.Obtener(1,1);
}

/*void Matriz::deflacion(double a,  Matriz& v ){
	cout<<"DEFLACIOOOOOOOOOOOOOOOOOON"<<endl;
    Matriz vt = v.Traspuesta();
    Matriz vvt = v.multiMatricial(vt);
    //Matriz vvt = v.multiXtrans();
    vvt.multiEscalar(-a);
    //vvt.mostrarMatriz(cout);
    this->sumaMatricial(vvt);
}
*/
void Matriz::deflacion(double a, Matriz& v ){
    Matriz vt = v.Traspuesta();
    Matriz vvt = v.multiMatricial(vt);
    vvt.multiEscalar(-a);
    //vvt.mostrarMatriz(cout);
    this->sumaMatricial(vvt);
}


Matriz Matriz::baseAutovectores(int iter, Matriz& autovalores, int alfa){
    int m = this->DameAlto();
    int n = this->DameAncho();
    assert(m==n);
    //Matriz copia = *this;
    Matriz resultante(m, alfa);
    //Matriz resultante = Matriz(m,alfa);
    Matriz autovector(m, 1);
    for (int i = 1; i <= alfa; ++i)
    {
        //cout<<"iteracion base numero "<<i<<endl;
        autovector.randomizar(m, 1);
        double autovalor = this->dameAutovalor(autovector, iter); //esto me deja en autovector el autovector y devuelve el autovalor
        autovalores.Definir(i, 1, autovalor);
        resultante.insertarEnColumna(autovector, i);
        this->deflacion(autovalor, autovector);
    }
    return resultante;
}

Matriz Matriz::baseAutovectoresConEscritura(ostream& os,int iter, Matriz& autovalores, int alfa){
    int m = this->DameAlto();
    int n = this->DameAncho();
    assert(m==n);
    //Matriz copia = *this;
    Matriz resultante(m, alfa);
    //Matriz resultante = Matriz(m,alfa);
    Matriz autovector(m, 1);
    for (int i = 1; i <= alfa; ++i)
    {
        //cout<<"iteracion base numero "<<i<<endl;
        autovector.randomizar(m, 1);
        double autovalor = this->dameAutovalor(autovector, iter); //esto me deja en autovector el autovector y devuelve el autovalor
        os<<autovalor<<endl;
        autovalores.Definir(i, 1, autovalor);
        resultante.insertarEnColumna(autovector, i);
        this->deflacion(autovalor, autovector);
    }
    return resultante;
}


Matriz Matriz::baseAutovectoresConVector(vector<double>& autovaloresVec,int iter, Matriz& autovalores, int alfa){
    int m = this->DameAlto();
    int n = this->DameAncho();
    assert(m==n);
    //Matriz copia = *this;
    Matriz resultante(m, alfa);
    //Matriz resultante = Matriz(m,alfa);
    Matriz autovector(m, 1);
    for (int i = 1; i <= alfa; ++i)
    {
        //cout<<"iteracion base numero "<<i<<endl;
        autovector.randomizar(m, 1);
        double autovalor = this->dameAutovalor(autovector, iter); //esto me deja en autovector el autovector y devuelve el autovalor

        //autovaloresVec[i-1]=autovalor;
        autovaloresVec.push_back(autovalor);

        autovalores.Definir(i, 1, autovalor);
        resultante.insertarEnColumna(autovector, i);
        this->deflacion(autovalor, autovector);
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
                double randi = rand() ;
                this->Definir(i, j, randi);
            }
        }   
}


double Matriz::media(int k) const{ //media de la fila k de la matriz
    double media = 0;
    int n = this->DameAncho();

    for (int i = 1; i <= n; ++i)
    {
        media = media + this->Obtener(k, i);
    }
    media = media/n;
    return media;
}



void Matriz::centrarConMedia(){ //ojo que tambien me modifica this
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
        this->multiEscalar(raiz);
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
  //  cout<<"vamo a centrarno "<<endl;
	this->centrarConMedia(); //x[i] = (x[i]- media)*(raiz n-1)
    //cout<<"vamo a copiarno "<<endl;

	Matriz xt=this->Traspuesta();
    //cout<<"la traspuesta que te pario "<<endl;
    //cout<<"vamo a multiplicarno "<<endl;
	//Matriz m=xt.multiMatricial(xCentrada);
	Matriz m=xt.multiXtrans();
    Matriz autovalores(alfa,1);
    //cout<<"vamo a basearno "<<endl;
	Matriz mb=m.baseAutovectores(30, autovalores,alfa); //30 parece un buen numero de iteraciones
	//matriz mb es la matriz que voy a usar para cambiar de base. tiene los autovectores de la matriz de covarianza
    // mb esta en R m x alfa
    for (int i = 1; i <= n; ++i)
	{  
        //if(i%1000==0){
          //  cout<<"vamo la putas: "<<i<<endl;
        //}
        this->cambiarIesima(mb,i).insertarEnFila(*this, i); //inserto la i-esima fila cambiada de base en this
	//}
    this->_ancho = alfa;
    //this->_alto no cambia, sigue siendo n
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

void selectionSortVoid(std::vector<tuplaDistanciaEtiq>& v, int k ) {
    int actual=0;
    while(actual<k){
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


    // normaresta(imagencambiada,cambiada,i)
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
    int n = t.DameAlto(); //n es la cantidad de imagenes qe tengo en mi campo train
    vector<tuplaDistanciaEtiq> distancias;
    double aux;
    for (int i = 1; i <= n; ++i)
    {
         aux = normaResta(e, t, i); //la distancia entre la imagen e y la i-esima imagen de t
         distancias.push_back(tuplaDistanciaEtiq(etiquetasT.Obtener(i, 1),aux));
    }
    selectionSortVoid(distancias,k); //los ordeno de acuerdo a las distancias de menor a mayor
    if(distancias[0].distancia==0){
    	return distancias[0].etiqueta;
    }else{
    	return moda(distancias, k); //la etiqueta del minimos
    }	
}


int Matriz::pca(Matriz imagen,Matriz etiquetasT, int k, int alfa){
    cout<<"PCA CAMBIAR BASE los datos"<<endl;
    this->cambiarBaseX(alfa);
    cout<<"PCA CAMBIAR DE BASE la IMAGEN"<<endl;
    imagen.cambiarBaseX(alfa);
    cout<<"se larga knn"<<endl; 
    return knn(imagen,etiquetasT,*this,k);
}



int knniesimo(Matriz& imagenes, Matriz& etiquetasT, Matriz& t, int k, int l){ //devuelve la etiqueta de la imagen e, comparando con las imagenes de t
    int n = t.DameAlto(); //n es la cantidad de imagenes qe tengo en mi campo train
    vector<tuplaDistanciaEtiq> distancias;
    double aux;
    for (int i = 1; i <= n; ++i)
    {
        for (int k = 1; k <= imagenes.DameAncho(); ++k)
        {
            aux = imagenes.Obtener(l, k) - t.Obtener(i, k);
            aux = aux*aux;
        }
        distancias.push_back(tuplaDistanciaEtiq(etiquetasT.Obtener(i, 1),aux));

    }
    selectionSortVoid(distancias,k); //los ordeno de acuerdo a las distancias de menor a mayor
    
    return moda(distancias, k); //la etiqueta del minimos
}


Matriz Matriz::pcaRapido(Matriz etiquetasTrain, Matriz imagenes, int alfa, int k){ //esta matriz tiene que calcular solo 1 vez la matriz de cambio de base y clasificar muchas imagenes
    Matriz resultado(imagenes.DameAlto(), 1);
    int n=this->DameAlto();
    this->centrarConMedia(); //x[i] = (x[i]- media)*(raiz n-1)
    Matriz xt = this->Traspuesta();
    Matriz covarianza = xt.multiXtrans();
    Matriz autovalores(alfa,1);
    Matriz cambioBase = covarianza.baseAutovectores(30, autovalores, alfa); //30 parece un buen numero de iteraciones
    this->cambiarBaseX2(alfa, cambioBase);
    imagenes.cambiarBaseX2(alfa, cambioBase);
    for (int i = 1; i <= imagenes.DameAlto(); ++i)
    {
        int etiquetaI =  knniesimo(imagenes, etiquetasTrain, *this, k, i);
        resultado.Definir(i, 1, etiquetaI);
    }
    return resultado;
 }

double promedio(vector<double> v){ //media de la fila k de la matriz
    double media = 0;
    int n= v.size();

    for (int i = 0; i < n; ++i)
    {
        media = media + v[i];
    }
    media = media/n;
    return media;
}




void Matriz::cambiarBaseX2(int alfa, Matriz cambioBase){ //en this le paso los x(i) que son las imagenes
    int n=this->DameAlto();
    for (int i = 1; i <= n; ++i)
    {  
         this->cambiarIesima(cambioBase,i).insertarEnFila2(*this, i);
        //&this->_matriz[i-1] =  this->cambiarIesima(cambioBase,i)._matriz[0]; //deberia cambiar en o de 1
    }
        this->_ancho = alfa;
        //alto no cambia
}



Matriz lecturaPLSDA(){
    ifstream is;
    is.open("../data/train.dat");

    string etiq;
    string delim;
    Matriz result(42000,1);
    int etiqueta;

    for (int j = 1; j <= 42000; ++j)    
    {
        getline (is, etiq, '_');
        etiqueta= atoi(etiq.c_str());
        result.Definir(j,1,etiqueta);
        getline(is, delim, '/' );
    }

    is.close();
    return result;
}



double productoEscalar(Matriz& a, Matriz& b){ //alto de a == ancho b ancho de a y b == 1 
    double res = 0;
    double aux;
    int  f = a.DameAlto();
    //assert(a.DameAlto() == b.DameAncho() || b.DameAlto == 1 || a.DameAncho==1)
    for (int i = 0; i < f; ++i){
        aux = a.Obtener(i,1) * b.Obtener(1,i);
        res = res+aux; 
    }
    return res;
}



Matriz crearY(int n){

Matriz etiquetas= lecturaPLSDA();
int m= 10;
Matriz res(n,10);


for(int i=1; i<=n; i++){
    for(int j=1; j<=m; j++){
        if(j== etiquetas.Obtener(i,1)){
            res.Definir(i,j,1);
        }else{
            res.Definir(i,j,(-1));
        }
    }
}



vector<double> v = res.dameVectorMedias(); //RAVIOL


for(int i=0;i<10;i++){
//cout<< "vector" << v[i]<<endl;
}
double temp;
for(int i=1; i<=n; i++){
    for(int j=1; j<=m; j++){
        temp= v[j-1];
        if(j== etiquetas.Obtener(i,1)){
            res.Definir(i,j,(1-temp)/sqrt(n-1));
        }else{
            res.Definir(i,j,((-1)-temp)/sqrt(n-1));
        }
    }
}


return res;

}


Matriz crearYAUX(int n, Matriz etiquetas){

int m= 10;
Matriz res(n,10);


for(int i=1; i<=n; i++){
    for(int j=1; j<=m; j++){
        if(j-1== etiquetas.Obtener(i,1)){
            res.Definir(i,j,1);
        }else{
            res.Definir(i,j,(-1));
        }
    }
}

vector<double> v = res.dameVectorMedias(); //RAVIOL
res.centrarConMediaNuevo(v,n);

return res;

}

Matriz Matriz::plsDa(Matriz& y, int gamma){//ESTA VERGA ME DEVUELVE LA MATRIZ EN DE GAMMA FILAS X WI COLUMNAS
    Matriz result = Matriz(DameAncho(), gamma);
    double normaWi;
    double unoSobreNorma;
    int n=DameAlto();
 
    for (int i = 1; i <= gamma; ++i){ //PAPAUEPA
            Matriz xt=Traspuesta();
            Matriz xty=xt.multiMatricial(y);
            Matriz xtyTrans=xty.Traspuesta();
            Matriz mi=xty.multiMatricial(xtyTrans);
            int fila = mi.DameAlto();
            Matriz autovector(fila, 1);
            autovector.randomizar(fila,1);
            Matriz copiaMI = mi;
            double autovalor = mi.dameAutovalor(autovector, 300); //esto me deja en randi el autovector y devuelve el autovalor RAVIOLI RAVIOLI DAME LA FORMUOLI
            result.insertarEnColumna(autovector,i); //en la i-esima columna tengo el wi (wi esta normalizado)
            Matriz ti = multiMatricial(autovector);
            normaWi=ti.norma2Vectorial();
            normaWi= pow(normaWi, -1);
            ti.multiEscalar(normaWi);
            Matriz tiT=ti.Traspuesta();
            Matriz tiTX = tiT.multiMatricial(*this);
            Matriz titiTx= ti.multiMatricial(tiTX);
            restaMatricial(titiTx);
            Matriz tiTY = tiT.multiMatricial(y);
            Matriz titiTY= ti.multiMatricial(tiTY);
            y.restaMatricial(titiTY); 
        }      
    return result;    
 
 }

Matriz Matriz::plsDaConEscritura(ostream& os,Matriz& y, int gamma){//ESTA VERGA ME DEVUELVE LA MATRIZ EN DE GAMMA FILAS X WI COLUMNAS
    Matriz result = Matriz(DameAncho(), gamma);
    double normaWi;
    double unoSobreNorma;
    int n=DameAlto();
    for (int i = 1; i <= gamma; ++i){ //PAPAUEPA
            Matriz xt=Traspuesta();
            Matriz xty=xt.multiMatricial(y);
           Matriz mi = xty.multiXtrans();
            int fila = mi.DameAlto();
            Matriz autovector(fila, 1);
            autovector.randomizar(fila,1);
            Matriz copiaMI = mi;
            double autovalor = mi.dameAutovalor(autovector, 30000); //esto me deja en randi el autovector y devuelve el autovalor RAVIOLI RAVIOLI DAME LA FORMUOLI
            os<<autovalor<<endl;
            result.insertarEnColumna(autovector,i); //en la i-esima columna tengo el wi (wi esta normalizado)
            Matriz ti = multiMatricial(autovector);
            normaWi=ti.norma2Vectorial();
            normaWi= pow(normaWi, -1);
            ti.multiEscalar(normaWi);
            Matriz tiT=ti.Traspuesta();
            Matriz tiTX = tiT.multiMatricial(*this);
            Matriz titiTx= ti.multiMatricial(tiTX);
            restaMatricial(titiTx);
            Matriz tiTY = tiT.multiMatricial(y);
            Matriz titiTY= ti.multiMatricial(tiTY);
            y.restaMatricial(titiTY); 
        }      
    return result;    
 
 }






Matriz Matriz::plsDaConVector(vector<double>& autovalores,Matriz& y, int gamma){//ESTA VERGA ME DEVUELVE LA MATRIZ EN DE GAMMA FILAS X WI COLUMNAS
    Matriz result = Matriz(DameAncho(), gamma);
    double normaWi;
    double unoSobreNorma;
    int n=DameAlto();

    for (int i = 1; i <= gamma; ++i){ //PAPAUEPA
            Matriz xt=Traspuesta();

           
            Matriz xty=xt.multiMatricial(y);


           Matriz mi = xty.multiXtrans();


            int fila = mi.DameAlto();

            Matriz autovector(fila, 1);

            autovector.randomizar(fila,1);
            Matriz copiaMI = mi;
 	
            double autovalor = mi.dameAutovalor(autovector, 30000); //esto me deja en randi el autovector y devuelve el autovalor RAVIOLI RAVIOLI DAME LA FORMUOLI
            //autovalores[i-1]=autovalor;
            autovalores.push_back(autovalor);
            result.insertarEnColumna(autovector,i); //en la i-esima columna tengo el wi (wi esta normalizado)


            Matriz ti = multiMatricial(autovector);
            //Actualizo mi x
            normaWi=ti.norma2Vectorial();
            normaWi= pow(normaWi, -1);
            //cout<< "normaWi"<< normaWi<<endl;
            ti.multiEscalar(normaWi);
            Matriz tiT=ti.Traspuesta();


           

            Matriz tiTX = tiT.multiMatricial(*this);
            Matriz titiTx= ti.multiMatricial(tiTX);

            restaMatricial(titiTx);


            Matriz tiTY = tiT.multiMatricial(y);
            Matriz titiTY= ti.multiMatricial(tiTY);


            y.restaMatricial(titiTY); 
            
            
        }      
    return result;    
 
 }







vector<double> Matriz::dameVectorMedias(){
    int topeColumnas=DameAncho();
    int topeFilas=DameAlto();
    vector<double> result(topeColumnas);
    int iterCols=1;
    int iterFilas;
    while(iterCols<=topeColumnas){
        iterFilas=1;
        double media=0;
        while(iterFilas<=topeFilas){
            media=media+Obtener(iterFilas,iterCols);
            iterFilas++;
        }
        media=media/topeFilas;
        result[iterCols-1]=media;
        iterCols++;
    }
    return result;
}

void Matriz::centrarConMediaNuevo(vector<double> medias, int n){
    assert(DameAncho()==medias.size());
    int alto=DameAlto();
    int ancho=DameAncho();
    double raiz=sqrt(n-1);
    raiz =pow(raiz,-1);
    for (int i = 1; i <= ancho; ++i)
    {
        for (int j = 1; j <=alto; ++j)
        {
            double aux=Obtener(j,i) - medias[i-1];
            aux=aux*raiz;
            Definir(j,i,aux);
        }
    }

}

void Matriz::cambiarBaseNuevo(Matriz& mBase){
    /*cout<<"centro con media"<<endl;
    this->centrarConMediaNuevo(medias,n);
    cout<<"transp"<<endl;
    Matriz xt=this->Traspuesta();
    cout<<"xtx"<<endl;
    Matriz xtx=xt.multiXtrans();*/
    int n=DameAlto();
    //cout<<"cambio filas"<<endl;
    for (int i = 1; i <= n; ++i)
    {  
        Matriz filaCambiada=cambiarIesima(mBase,i);
        filaCambiada.insertarEnFila2(*this,i);
    }

}

int Matriz::pcaNuevo(Matriz& imagen,Matriz& etiquetasT, int k, int alfa){
    
    //centrar con media
    vector<double> medias=dameVectorMedias();
    int n=DameAlto();
    cout<<"entro a pca"<<endl;


    centrarConMediaNuevo(medias,n);



   // cout<<"primera fila post"<<endl;


    //obtengo base
  //  cout<<"voy a transponer"<<endl;
    Matriz thisT=Traspuesta();
    cout<<"armo baseAutovectores"<<endl;
  //  cout<<"voy a hacer xt x"<<endl;
    Matriz xtx=thisT.multiXtrans();
    Matriz autovalores(alfa,1);
    Matriz mb1=xtx.baseAutovectores(30, autovalores,alfa);
   // cout<<"se vienen las mierdas"<<endl;
    this->cambiarBaseNuevo(mb1);

   // cout<<"a cambiar imagen"<<endl;
    
    imagen.centrarConMediaNuevo(medias,n);
  


    Matriz imagenCambiada=imagen.multiMatricial(mb1);

    cout<<"arranca knn"<<endl;
    return knn(imagenCambiada,etiquetasT,*this,k);

//  return 1;
}

int Matriz::plsNuevo(Matriz& imagen,Matriz& etiquetasT, int k, int gamma){
    vector<double> medias=dameVectorMedias();
    int n=DameAlto();
    centrarConMediaNuevo(medias,n);
    Matriz otroX=*this;
    Matriz y=crearY(n);
    Matriz mb1=plsDa(y,gamma);	
    Matriz cambiada=otroX.multiMatricial(mb1);
    imagen.centrarConMediaNuevo(medias,n);
	Matriz imagenCambiada=imagen.multiMatricial(mb1);

    return knn(imagenCambiada,etiquetasT,cambiada,k);

}

void Matriz::mezclarMatriz(){
    
    random_shuffle ( _matriz.begin(), _matriz.end() );

}





Matriz filtrarTrain(Matriz& viejoTrain, Matriz& etiquetasTodas, Matriz& etiquetasNuevoTrain, Matriz& foldM, Matriz& nuevoTest, Matriz& etiquetasNuevoTest, int indiceFold){ //me devuelve el train
	int tamanio= 0;
	for (int i = 1; i <= 42000; ++i)
	{
		tamanio+= foldM.Obtener(i,indiceFold);
	}
	
	Matriz nuevoTrain(tamanio,784);
	Matriz nuevoTest2(42000-tamanio, 784);
	Matriz etiquetasNuevoTrainNuevo(tamanio,1);
	Matriz etiquetasNuevoTestNuevo(42000-tamanio,1);

//separa en train y test segun me lo indica foldM (foldM es una matriz y en indiceFold me dice cual de las columnas, cual de los folds es el que uso)
	int j=1;
	int l = 1;
		for (int i = 1; i<=42000; ++i)
		{
			if (foldM.Obtener(i,indiceFold) == 1 )//si es 1, va al train
			{
						for (int x = 1; x <= 784; ++x)
						{
							//cout<<"definir de filtrar train iteracion: "<<x<<endl;
							nuevoTrain.Definir(j, x, viejoTrain.Obtener(i, x));
							
						}
						//cout<<"defino las etiquetas nuevas"<<endl;
						etiquetasNuevoTrainNuevo.Definir(j, 1, etiquetasTodas.Obtener(i,1));
						j++;
			}else{
							for (int x = 1; x <= 784; ++x)
							{
								//cout<<"definir else filtrar train"<<endl;
								nuevoTest2.Definir(l, x, viejoTrain.Obtener(i, x));
								
							}
							etiquetasNuevoTestNuevo.Definir(l,1,etiquetasTodas.Obtener(i,1));
							l++;
			}



		}
etiquetasNuevoTrain=etiquetasNuevoTrainNuevo;
etiquetasNuevoTest=etiquetasNuevoTestNuevo;
nuevoTest = nuevoTest2;
return nuevoTrain;

}

tuplaMetricas kFoldCrossVal(Matriz& todas, int k, int alfa, int gamma, Matriz& etiquetasTodas, int metodo, Matriz& foldM){
   int n=todas.DameAlto();
    
    double promedioTotal = 0;
    double kesimoPromedio = 0;
    int tamanio = n / k;
    vector<double> verdaderosPositivos(10,0);
    vector<double> falsosPositivos(10,0);
    vector<double> falsosNegativos(10,0);

    

    for (int i = 1; i <= k; i++){ //CAMBIAR ESTO CUANDO ANDE RAVIOL RAVIOL 
    	Matriz nuevoTest;
    	Matriz etiquetasNuevoTrain;
    	Matriz etiquetasNuevoTest;
    	Matriz nuevoTrain = filtrarTrain(todas, etiquetasTodas, etiquetasNuevoTrain, foldM, nuevoTest, etiquetasNuevoTest, i);
    	n = nuevoTrain.DameAlto();
    	vector<double> medias = nuevoTrain.dameVectorMedias();
    	nuevoTrain.centrarConMediaNuevo(medias, n);
if(metodo == 1) //1 = pca
{
		kesimoPromedio=0;
    	Matriz thisT=nuevoTrain.Traspuesta();
    	Matriz xtx=thisT.multiXtrans();
    	Matriz autovalores(alfa,1);
    	Matriz mb1=xtx.baseAutovectores(30, autovalores,alfa);
    	nuevoTrain.cambiarBaseNuevo(mb1);

    Matriz imagenIesima(1,784);
   	for (int z = 1; z <= nuevoTest.DameAlto(); ++z)
   	{
   		
        for (int x = 1; x <= nuevoTest.DameAncho(); ++x)
        {
        	imagenIesima.Definir(1, x, nuevoTest.Obtener(z,x));
        }
        imagenIesima.centrarConMediaNuevo(medias, n);
        Matriz imagenCambiada = imagenIesima.multiMatricial(mb1);
    	int etiquetaIesima = knn(imagenCambiada, etiquetasNuevoTrain, nuevoTrain,5);
    	if(etiquetaIesima == etiquetasNuevoTest.Obtener(z,1)){
            kesimoPromedio+=1;
            verdaderosPositivos[etiquetaIesima]+=1;
        }else{
            falsosPositivos[etiquetaIesima]+=1;
            falsosNegativos[etiquetasNuevoTest.Obtener(z,1)]+=1;
        }

   	}
   	kesimoPromedio=kesimoPromedio/nuevoTest.DameAlto();
   	promedioTotal+=kesimoPromedio;

}

else{ //2= pls
    Matriz otroX=nuevoTrain;
    Matriz y=crearY(n);
    Matriz mb1=nuevoTrain.plsDa(y,gamma);//RAVIOL
    Matriz cambiada=otroX.multiMatricial(mb1);
   Matriz imagenIesima(1,784);
	for(int j=1;j<=nuevoTest.DameAlto();++j){
		for (int x = 1; x <= nuevoTest.DameAncho(); x++)
		{
			        	
		imagenIesima.Definir(1,x,nuevoTest.Obtener(j,x));
		}
		imagenIesima.centrarConMediaNuevo(medias,n);

		Matriz imagenCambiada=imagenIesima.multiMatricial(mb1);
		int etiquetaIesima = knn(imagenCambiada,etiquetasNuevoTrain,cambiada,5);
		if(etiquetaIesima == etiquetasNuevoTest.Obtener(j,1)){
            kesimoPromedio+=1;
            verdaderosPositivos[etiquetaIesima]+=1;
        }else{
            falsosPositivos[etiquetaIesima]+=1;
            falsosNegativos[etiquetasNuevoTest.Obtener(j,1)]+=1;
        }
	}
	kesimoPromedio=kesimoPromedio/nuevoTest.DameAlto();
		promedioTotal+=kesimoPromedio;

}



}
    promedioTotal= promedioTotal /k;
    tuplaMetricas result(falsosNegativos,falsosPositivos,verdaderosPositivos,promedioTotal);
    return result;


}




tuplaMetricas kFoldCrossValConEscritura(ostream& os, Matriz& todas, int k, int alfa, int gamma, Matriz& etiquetasTodas, int metodo, Matriz& foldM){
    int n=todas.DameAlto();
    
    double promedioTotal = 0;
    double kesimoPromedio = 0;
    int tamanio = n / k;
    vector<double> verdaderosPositivos(10,0);
    vector<double> falsosPositivos(10,0);
    vector<double> falsosNegativos(10,0);




    for (int i = 1; i <= k; i++){ //CAMBIAR ESTO CUANDO ANDE RAVIOL RAVIOL 
        Matriz nuevoTest;
        Matriz etiquetasNuevoTrain;
        Matriz etiquetasNuevoTest;
        Matriz nuevoTrain = filtrarTrain(todas, etiquetasTodas, etiquetasNuevoTrain, foldM, nuevoTest, etiquetasNuevoTest, i);
        //cout<<"ALTOOOOOOOOOO "<<etiquetasNuevoTrain.DameAlto()<<endl;
        n = nuevoTrain.DameAlto();
        vector<double> medias = nuevoTrain.dameVectorMedias();
        nuevoTrain.centrarConMediaNuevo(medias, n);
    Matriz etiquetasMatriz(10,10);
if(metodo == 1) //1 = pca
{
        kesimoPromedio=0;
        Matriz thisT=nuevoTrain.Traspuesta();
        Matriz xtx=thisT.multiXtrans();
        Matriz autovalores(alfa,1);
        Matriz mb1=xtx.baseAutovectoresConEscritura(os,30, autovalores,alfa);
        nuevoTrain.cambiarBaseNuevo(mb1);
    Matriz imagenIesima(1,784);
    for (int z = 1; z <= nuevoTest.DameAlto(); ++z)
    {
        
        for (int x = 1; x <= nuevoTest.DameAncho(); ++x)
        {
            //cout<<"copio imagen en kfold: "<<x<<endl;
            imagenIesima.Definir(1, x, nuevoTest.Obtener(z,x));
        }
        //cout<<"sali del for "<<endl;
        imagenIesima.centrarConMediaNuevo(medias, n);
        //cout<<"ya centre"<<endl;
        Matriz imagenCambiada = imagenIesima.multiMatricial(mb1);
        //cout<<"ya cambie"<<endl;
        int etiquetaIesima = knn(imagenCambiada, etiquetasNuevoTrain, nuevoTrain,30);
        //cout<<"ya hice knn"<<endl;
        if(etiquetaIesima == etiquetasNuevoTest.Obtener(z,1)){
            kesimoPromedio+=1;
            verdaderosPositivos[etiquetaIesima]++;
        }else{
            falsosPositivos[etiquetaIesima]++;
            falsosNegativos[etiquetasNuevoTest.Obtener(z,1)]++;
        }
    int aux = etiquetasMatriz.Obtener(etiquetaIesima+1, etiquetasNuevoTest.Obtener(z,1)+1);
    etiquetasMatriz.Definir(etiquetaIesima+1, etiquetasNuevoTest.Obtener(z,1)+1, aux+1);
        

    }
    kesimoPromedio=kesimoPromedio/nuevoTest.DameAlto();
    cout<<"promedio particion "<<i<<"con pca: "<<kesimoPromedio;
    promedioTotal+=kesimoPromedio;

}

else{ //2= pls
    cout<<"entre metodo 2 con i:"<<i<<endl;
    Matriz otroX=nuevoTrain;
    Matriz y=crearYAUX(otroX.DameAlto(),etiquetasNuevoTrain);

    Matriz mb1=nuevoTrain.plsDaConEscritura(os,y,gamma);//RAVIOL
    cout<<"listo plsda "<<endl;
    Matriz cambiada=otroX.multiMatricial(mb1);

   Matriz imagenIesima(1,784);
    for(int j=1;j<=nuevoTest.DameAlto();++j){
        //cout<<"copio imagen en kfold ELSE "<<j<<endl;

        for (int x = 1; x <= nuevoTest.DameAncho(); x++)
        {
                        
        imagenIesima.Definir(1,x,nuevoTest.Obtener(j,x));
        }
        imagenIesima.centrarConMediaNuevo(medias,n);

        Matriz imagenCambiada=imagenIesima.multiMatricial(mb1);
        int etiquetaIesima = knn(imagenCambiada,etiquetasNuevoTrain,cambiada,15);
        if(etiquetaIesima == etiquetasNuevoTest.Obtener(j,1)){
            kesimoPromedio+=1;
            verdaderosPositivos[etiquetaIesima]++;
        }else{
            falsosPositivos[etiquetaIesima]++;
            falsosNegativos[etiquetasNuevoTest.Obtener(j,1)]++;
        }
        int aux = etiquetasMatriz.Obtener(etiquetaIesima+1, etiquetasNuevoTest.Obtener(j,1)+1);
        etiquetasMatriz.Definir(etiquetaIesima+1, etiquetasNuevoTest.Obtener(j,1)+1, aux+1);
        //cout<<"era un:"<<etiquetasNuevoTest.Obtener(j,1)<<" diste un: "<<etiquetaIesima<<endl;
    }
    cout<<"asi etiqueto PLS"<<endl;
    cout<<etiquetasMatriz;
    kesimoPromedio=kesimoPromedio/nuevoTest.DameAlto();
    cout<<"promedio iter "<<i<<" :"<<kesimoPromedio<<endl;
        promedioTotal+=kesimoPromedio;

}



}
    promedioTotal= promedioTotal /k;
    tuplaMetricas result(falsosNegativos,falsosPositivos,verdaderosPositivos,promedioTotal);
    return result;

}



vector<vector<double> > kFoldCrossValConVector(Matriz& todas, int k, int alfa, int gamma, Matriz& etiquetasTodas, int metodo, Matriz& foldM){
    int n=todas.DameAlto();
    
    double promedioTotal = 0;
    double kesimoPromedio = 0;
    int tamanio = n / k;
    vector<double> verdaderosPositivos(10,0);
    vector<double> falsosPositivos(10,0);
    vector<double> falsosNegativos(10,0);

    vector<vector<double> > todosAutovalores;


    for (int i = 1; i <= k; i++){ //CAMBIAR ESTO CUANDO ANDE RAVIOL RAVIOL 
        Matriz nuevoTest;
        Matriz etiquetasNuevoTrain;
        Matriz etiquetasNuevoTest;
        Matriz nuevoTrain = filtrarTrain(todas, etiquetasTodas, etiquetasNuevoTrain, foldM, nuevoTest, etiquetasNuevoTest, i);
        n = nuevoTrain.DameAlto();
        vector<double> medias = nuevoTrain.dameVectorMedias();
        nuevoTrain.centrarConMediaNuevo(medias, n);
    	Matriz etiquetasMatriz(10,10);

if(metodo == 1) //1 = pca
{
        cout<<"pca iter "<<i<<" de "<<k<<endl;
		vector<double> autovaloresPca;
        kesimoPromedio=0;
        Matriz thisT=nuevoTrain.Traspuesta();
        Matriz xtx=thisT.multiXtrans();
        Matriz autovalores(alfa,1);
        Matriz mb1=xtx.baseAutovectoresConVector(autovaloresPca,30, autovalores,alfa);
        nuevoTrain.cambiarBaseNuevo(mb1);
        Matriz imagenIesima(1,784);
       cout<<"comparando imagenes..."<<endl;

    for (int z = 1; z <= nuevoTest.DameAlto(); ++z)
    {
        if(z==3000){
            cout<<"Aja! pensaste que habia pasado algo interesante! lamento informarte que seguimos comparando imagenes"<<endl;
        }
        if(z==4000){
            cout<<"Nope, not yet"<<endl;
        }
        if(z==6000){
            cout<<"Si, para el proximo fold vas a leer lo mismo y esto no va a tener gracia -.-"<<endl;
        }
        if(z==8300){
            cout<<"Igual tampoco era muy gracioso..."<<endl;
        }
        for (int x = 1; x <= nuevoTest.DameAncho(); ++x)
        {
            //cout<<"copio imagen en kfold: "<<x<<endl;
            imagenIesima.Definir(1, x, nuevoTest.Obtener(z,x));
        }
        //cout<<"sali del for "<<endl;
        imagenIesima.centrarConMediaNuevo(medias, n);
        //cout<<"ya centre"<<endl;
        Matriz imagenCambiada = imagenIesima.multiMatricial(mb1);
        //cout<<"ya cambie"<<endl;
        int etiquetaIesima = knn(imagenCambiada, etiquetasNuevoTrain, nuevoTrain,30);
        //cout<<"ya hice knn"<<endl;
        if(etiquetaIesima == etiquetasNuevoTest.Obtener(z,1)){
            kesimoPromedio+=1;
            verdaderosPositivos[etiquetaIesima]++;
        }else{
            falsosPositivos[etiquetaIesima]++;
            falsosNegativos[etiquetasNuevoTest.Obtener(z,1)]++;
        }
        

    }

    kesimoPromedio=kesimoPromedio/nuevoTest.DameAlto();
    cout<<"promedio particion "<<i<<" con Pca: "<<kesimoPromedio<<endl;

    promedioTotal+=kesimoPromedio;
    todosAutovalores.push_back(autovaloresPca);


}

else{ //2= pls
        cout<<"pls iter "<<i<<" de "<<k<<endl;

	vector<double> autovaloresPls;
    Matriz otroX=nuevoTrain;
    Matriz y=crearYAUX(otroX.DameAlto(),etiquetasNuevoTrain);

    Matriz mb1=nuevoTrain.plsDaConVector(autovaloresPls,y,gamma);//RAVIOL
    Matriz cambiada=otroX.multiMatricial(mb1);

   Matriz imagenIesima(1,784);
   cout<<"comparando imagenes..."<<endl;
    for(int j=1;j<=nuevoTest.DameAlto();++j){
        if(j==3000){
            cout<<"Gracias por esperar, aguarde otro momentito por favor, ya sera atentido (suena musica de ascensor, una bossa berreta que te quiere hacer creer que estas en aruba cuando en realidad estas en una ciudad de mierda)"<<endl;
        }
        if(j==4000){
            cout<<"Que clima loco no? Se vino el otoño ya"<<endl;
        }
        if(j==6000){
            cout<<"Tu mujer todo bien? Me alegro..."<<endl;
        }
        if(j==7000){
            cout<<"..."<<endl;
        }
        if(j==8200){
            cout<<"PLIN (ruido que hacen los ascensores en las peliculas cuando llegan a destino)"<<endl;
        }
        for (int x = 1; x <= nuevoTest.DameAncho(); x++)
        {
                        
        imagenIesima.Definir(1,x,nuevoTest.Obtener(j,x));
        }
        imagenIesima.centrarConMediaNuevo(medias,n);

        Matriz imagenCambiada=imagenIesima.multiMatricial(mb1);
        int etiquetaIesima = knn(imagenCambiada,etiquetasNuevoTrain,cambiada,15);
        if(etiquetaIesima == etiquetasNuevoTest.Obtener(j,1)){
            kesimoPromedio+=1;
            verdaderosPositivos[etiquetaIesima]++;
        }else{
            falsosPositivos[etiquetaIesima]++;
            falsosNegativos[etiquetasNuevoTest.Obtener(j,1)]++;
        }
    }
        kesimoPromedio=kesimoPromedio/nuevoTest.DameAlto();
        cout<<"promedio particion "<<i<<"con Pls: "<<kesimoPromedio<<endl;

        promedioTotal+=kesimoPromedio;

        todosAutovalores.push_back(autovaloresPls);

}



}
    promedioTotal= promedioTotal /k;
    tuplaMetricas result(falsosNegativos,falsosPositivos,verdaderosPositivos,promedioTotal);
    return todosAutovalores;

}
