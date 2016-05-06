/*#ifndef MATRIZ_H
#define MATRIZ_H*/
#include <vector>
#include <iostream>
#include <math.h> 
#include <cassert>
using namespace std;



    class Matriz{

    public:

        Matriz();
        Matriz(int al, int an);

        Matriz(vector<vector<double> > v);


        void Definir ( int i,  int j, double s);
        double dameAutovalor(Matriz& x , int iter)const;
        Matriz deflacion(double autovalor, const Matriz& autovector);
        Matriz baseAutovectores(int iter, Matriz& autovalores)const;
        //const vector<double>& operator[](int i) const;
        double Obtener ( int i,  int j) const ;
        void insertarEnColumna(Matriz a, int c);
        void Traspuesta();
        Matriz multiMatricial( const Matriz&  b) const; // Result = this*B  this tambien es por referencia sin poder modificar?
        Matriz multiEscalar(double a) const;
        Matriz sumaMatricial(const Matriz& b ) const;
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

    
    
    
    // double Matriz::Obtener( int i,  int j) const  {
    //     return _matriz[i-1][j-1];
    // }

     double Matriz::Obtener( int i,  int j) const  {
        return _matriz[i-1][j-1];
        
    }



void Matriz::Traspuesta(){
	for(int i=0; i<_alto; i++){
		for(int j=0; j<_ancho;j++){
			if(i!=j){
				double aux=_matriz[i][j];
				_matriz[i][j]=_matriz[j][i];
				_matriz[j][i]=aux;
				}
		}
	}
 
    int aux2 = _alto;
    _alto = _ancho;
    _ancho = aux2;

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

    Matriz l = *this;
     l.Cholesky();
    Matriz y = l.resolverTI(b);
    l.Traspuesta();
    return l.resolverTS(y);
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


Matriz Matriz::multiMatricial( const Matriz&  b) const{
    int m = this->DameAlto();
    int n = this->DameAncho();
    int k = b.DameAncho();
    assert(n == b.DameAlto());

    Matriz resultante = Matriz(m,k);
    double aij;
    for (int i = 1; i <= m; ++i)
    {
        for (int j = 1; j <= k; ++j)
        {
            aij = this->multi(b, i, j);
            resultante.Definir(i, j, aij);
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

Matriz Matriz::sumaMatricial(const Matriz& b ) const{
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
            resultante.Definir(i, j, resta);
        }
    }
    return resultante;
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
        v = this->multiMatricial(v);
        double norma = v.norma2Vectorial(); //tiene que darme 1/norma
        norma = pow(norma, -1);
        v = v.multiEscalar(norma);
    }
    Matriz vt = v.copiarMatriz();
    vt.Traspuesta();
    normaCuadrado = v.norma2Cuadrado();
    autovalor = vt.multiMatricial(this->multiMatricial(v)).multiEscalar(normaCuadrado);
    x = v; //esto debería dejar en x el autovector
    return autovalor.Obtener(1,1);
}

Matriz Matriz::deflacion(double a, const Matriz& v ){
    Matriz vt = v.copiarMatriz();
    vt.Traspuesta();
    Matriz vvt = v.multiMatricial(vt);
    vvt = vvt.multiEscalar(-a);
    vvt.mostrarMatriz(cout);
    Matriz resta = this->sumaMatricial(vvt);
   return resta;
}

Matriz Matriz::baseAutovectores(int iter, Matriz& autovalores)const {
    int m = this->DameAlto();
    int n = this->DameAncho();
    assert(m==n);
    Matriz copia = this->copiarMatriz();
    Matriz resultante = Matriz(m,n);
    for (int i = 1; i <= n; ++i)
    {
        Matriz autovector = Matriz(m, 1);
         autovector.randomizar(m, 1);
        double autovalor = copia.dameAutovalor(autovector, iter); //esto me deja en randi el autovector y devuelve el autovalor
        autovalores.Definir(i, 1, autovalor);
        resultante.insertarEnColumna(autovector, i);
        copia = copia.deflacion(autovalor, autovector);
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

/*Matriz Matriz::matrizCovarianza(){
    int n = this->DameAlto(); //n = cantidad de muestras
    int m = this->DameAncho(); //m es el tamaño de cada muestra
    double media;
    double aux;
    for (int i = 1; i <= n; ++i)
       {
           media = this->media(i);
           for (int j = 1; j <=m; ++j)
            {
                aux = this->Obtener()
            } 

       }   
}*/

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












