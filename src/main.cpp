/*
	#include "lectura.cpp"
#include "metodos.cpp"
#include "Matriz.h"*/
//#include <math.h>       /* pow */
//#include "Matriz.h"
#include "lectura.cpp"
#include <algorithm>    // std::random_shuffle
#include <vector>
int main(int argc, char const *argv[])
{
	






// COSAS PARA AMBOS MAINS VIEJOS


	
	ifstream imagenesTrain;
	imagenesTrain.open("../data/train.dat");
	Matriz etiquetasTrain = Matriz(5000, 1);
	 Matriz imagenesTrainM = lecturaTrain(imagenesTrain, etiquetasTrain);
	Matriz imagenesTrainMCopia=imagenesTrainM;
	imagenesTrain.close();
	Matriz imagenTrainI=Matriz(1,imagenesTrainM.DameAncho());
	





// // 1. MAIN PARA LEVANTAR 1 SOLA IMAGEN Y PROBARLA
// 	 //Matriz imagenTrainI=Matriz(1,imagenesTrainM.DameAncho());
// 	for (int i = 1; i <= imagenesTrainM.DameAncho(); i++)
// 	{
// 		imagenTrainI.Definir(1,i,imagenesTrainM.Obtener(7000,i));
// 	}

// // Matriz prueba(4,4);
// // prueba.Definir(1,1,1);
// // prueba.Definir(1,2,0);
// // prueba.Definir(1,3,0);
// // prueba.Definir(1,4,0);

// // prueba.Definir(2,1,0);
// // prueba.Definir(2,2,2);
// // prueba.Definir(2,3,0);
// // prueba.Definir(2,4,0);

// // prueba.Definir(3,1,0);
// // prueba.Definir(3,2,0);
// // prueba.Definir(3,3,3);
// // prueba.Definir(3,4,0);

// // prueba.Definir(4,1,0);
// // prueba.Definir(4,2,0);
// // prueba.Definir(4,3,0);
// // prueba.Definir(4,4,4);

// // Matriz autovector(4, 1);
// // autovector.randomizar(4,1);
// // double autovalor = prueba.dameAutovalor(autovector, 30);
// // cout<<autovector;
// // cout<<autovalor<<endl;
// // Matriz autovalores(10,1);
// // Matriz mb1=prueba.baseAutovectores(30,autovalores, 4);
// // cout<<mb1;


// 	cout<<"la imagen era"<<endl;
// 	mostrarImagen(imagenTrainI);
// 	cout<<"pls da: "<<imagenesTrainM.plsNuevo(imagenTrainI,etiquetasTrain,20,5)<<endl;






// 2. MAIN PARA PROBAR N IMAGENES

	/*int n=imagenesTrainM.DameAlto();
	vector<double> medias=imagenesTrainM.dameVectorMedias();
    imagenesTrainMCopia.centrarConMediaNuevo(medias,n);

	cout<<"voy a transponer"<<endl;
	Matriz thisT=imagenesTrainMCopia.Traspuesta();
	cout<<"voy a hacer xt x"<<endl;
	Matriz xtx=thisT.multiXtrans();
	Matriz autovalores(30,1);
	cout<<"armo baseAutovectores"<<endl;
	Matriz mb1=xtx.baseAutovectores(30, autovalores,30);
	Matriz imagenCambiada(1,30);
	int res;
	cout<<"arranco ciclo"<<endl;
	imagenesTrainMCopia.cambiarBaseNuevo(mb1);

	for(int i=1;i<=999;++i){
		for(int j=1;j<=imagenesTrainM.DameAncho();++j){
			imagenTrainI.Definir(1,j,imagenesTrainM.Obtener(i,j));
		}
		//mostrarImagen(imagenTrainI);
		imagenTrainI.centrarConMediaNuevo(medias,n);
		imagenCambiada=imagenTrainI.multiMatricial(mb1);
		res= knn(imagenCambiada,etiquetasTrain,imagenesTrainMCopia,1);
		//cout<<"imagen "<<i<<"nos dio: "<<res<<" y su etiqueta era "<<etiquetasTrain.Obtener(i,1)<<endl;
		//int res=imagenesTrainM.pcaRapido(mb1,imagenTrainI,etiquetasTrain,20,30);
		if(res==etiquetasTrain.Obtener(i,1)){
			cout<<"BIEN"<<endl;
		}else{
			cout<<"NOOOOOOO NOOOO"<<endl;
		}
	}






/*

Matriz prueba(4,4);
prueba.Definir(1,1,61);
prueba.Definir(1,2,18);
prueba.Definir(1,3,32);
prueba.Definir(1,4,21);

prueba.Definir(2,1,10);
prueba.Definir(2,2,11);
prueba.Definir(2,3,17);
prueba.Definir(2,4,22);

prueba.Definir(3,1,24);
prueba.Definir(3,2,42);
prueba.Definir(3,3,90);
prueba.Definir(3,4,31);

prueba.Definir(4,1,10);
prueba.Definir(4,2,22);
prueba.Definir(4,3,39);
prueba.Definir(4,4,43);

cout<<prueba;

prueba.mezclarMatriz();
cout<<" "<<endl;
cout<<prueba;

*/



	ifstream imagenesTest;
	imagenesTest.open("../data/test.dat");
	Matriz etiquetasTest(28000,1);
	Matriz imagenesTestM = lecturaTest(imagenesTest, etiquetasTest);
	Matriz imagenesTestMcopia=imagenesTestM;
	imagenesTest.close();
	Matriz imagenTestM=Matriz(1,imagenesTestM.DameAncho());
	Matriz imagenTestM2=Matriz(1,imagenesTestM.DameAncho());

	Matriz imagenTestI=Matriz(1,imagenesTestM.DameAncho());
	for (int i = 1; i <= imagenesTestM.DameAncho(); i++)
	{
		imagenTestM.Definir(1,i,imagenesTestM.Obtener(900,i));
		imagenTestM2.Definir(1,i,imagenesTestM.Obtener(900,i));

	}
	mostrarImagen(imagenTestM);
	cout<<"pls da: "<<imagenesTrainMCopia.plsNuevo(imagenTestM,etiquetasTrain,20,4)<<endl;
	cout<<"pca da: "<<imagenesTrainM.pcaNuevo(imagenTestM2,etiquetasTrain,20,30)<<endl;




/*
	ifstream imagenesTrain;
	imagenesTrain.open("../data/train.dat");
	Matriz etiquetasTrain = Matriz(42000, 1);
	 Matriz imagenesTrainM = lecturaTrain(imagenesTrain, etiquetasTrain);
	Matriz imagenesTrainMCopia=imagenesTrainM;
	imagenesTrain.close();
	Matriz imagenTrainI=Matriz(1,imagenesTrainM.DameAncho());
	
(5 1.88845) (5 1.95719) (5 2.07936) (7 2.1573) (6 2.17056) (7 2.19249) (5 2.20239) (1 2.22161) (7 2.22623) (5 2.23478) (1 2.24152) (2 2.24818) (5 2.25068) (6 2.27009) (2 2.28003) (5 2.30285) (2 2.32959) (6 2.33277) (4 2.35022) (5 2.38246)

(5 1.88845) (5 1.95719) (5 2.07936) (7 2.1573) (6 2.17056) (7 2.19249) (5 2.20239) (1 2.22161) (7 2.22623) (5 2.23478) (1 2.24152) (2 2.24818) (5 2.25068) (6 2.27009) (2 2.28003) (5 2.30285) (2 2.32959) (6 2.33277) (4 2.35022) (5 2.38246)  




*/







	return 0;
}
