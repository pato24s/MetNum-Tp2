/*
	#include "lectura.cpp"
#include "metodos.cpp"
#include "Matriz.h"*/
//#include <math.h>       /* pow */
//#include "Matriz.h"
#include "lectura.cpp"

int main(int argc, char const *argv[])
{
	
	
	ifstream imagenesTrain;
	imagenesTrain.open("../data/train.dat");
	Matriz etiquetasTrain = Matriz(42000,1); 
	//cout<< lecturaPLSDA(); //Matriz(42000, 1);
	Matriz imagenesTrainM = lecturaTrain(imagenesTrain, etiquetasTrain);
	imagenesTrain.close();



	Matriz imagenesCopia(2000,784);
	for (int i = 1; i <=2000 ; ++i)
	{
		for (int j = 1; j<=784 ; ++j)
		{
			imagenesCopia.Definir(i,j, imagenesTrainM.Obtener(i,j));
		}
	}
	cout<<"listo, ya lo copie"<<endl;
	Matriz imagenTrainI(1,imagenesTrainM.DameAncho());
	for (int i = 1; i <= imagenesTrainM.DameAncho(); i++)
	{
		Matriz etiquetasT;
		imagenTrainI.Definir(1,i,imagenesTrainM.Obtener(1,i));
	}



	cout<<"pls da: "<<plsDApiola(imagenesTrainM,etiquetasTrain,20,20, imagenTrainI,imagenesTrainM.DameAlto())<<endl;
	Matriz etiquetas = Matriz(42000,1);

	 mostrarImagen(imagenTrainI);





// COSAS PARA AMBOS MAINS VIEJOS


	
	/*ifstream imagenesTrain;
	imagenesTrain.open("../data/train.dat");
	Matriz etiquetasTrain = Matriz(42000, 1);
	Matriz imagenesTrainM = lecturaTrain(imagenesTrain, etiquetasTrain);
	Matriz imagenesTrainMCopia=imagenesTrainM;
	imagenesTrain.close();
	Matriz imagenTrainI=Matriz(1,imagenesTrainM.DameAncho());
	
*/




// 1. MAIN PARA LEVANTAR 1 SOLA IMAGEN Y PROBARLA
	 /*//Matriz imagenTrainI=Matriz(1,imagenesTrainM.DameAncho());
	for (int i = 1; i <= imagenesTrainM.DameAncho(); i++)
	{
		imagenTrainI.Definir(1,i,imagenesTrainM.Obtener(41,i));
	}


	cout<<"pca da: "<<imagenesTrainM.pcaNuevo(imagenTrainI,etiquetasTrain,20,30)<<endl;
	cout<<"la imagen era"<<endl;
	mostrarImagen(imagenTrainI);



*/


// 2. MAIN PARA PROBAR N IMAGENES


/*	cout<<"voy a transponer"<<endl;
	Matriz thisT=imagenesTrainM.Traspuesta();
	cout<<"voy a hacer xt x"<<endl;
	Matriz xtx=thisT.multiXtrans();
	Matriz autovalores(30,1);
	cout<<"armo baseAutovectores"<<endl;
	Matriz mb1=xtx.baseAutovectores(30, autovalores,30);
	Matriz imagenCambiada(1,30);
	int res;
	cout<<"arranco ciclo"<<endl;
	imagenesTrainMCopia.cambiarBaseNuevo(mb1);

	for(int i=1;i<=100;++i){
		for(int j=1;j<=imagenesTrainM.DameAncho();++j){
			imagenTrainI.Definir(1,j,imagenesTrainM.Obtener(i,j));
		}
		//mostrarImagen(imagenTrainI);
		imagenCambiada=imagenTrainI.multiMatricial(mb1);
		res= knn(imagenCambiada,etiquetasTrain,imagenesTrainMCopia,1);
		//cout<<"imagen "<<i<<"nos dio: "<<res<<" y su etiqueta era "<<etiquetasTrain.Obtener(i,1)<<endl;
		//int res=imagenesTrainM.pcaRapido(mb1,imagenTrainI,etiquetasTrain,20,30);
		if(res==etiquetasTrain.Obtener(i,1)){
			cout<<"BIEN"<<endl;
		}else{
			cout<<"NOOOOOOO NOOOO"<<endl;
		}
	}*/




	return 0;
}
