
#include "lectura.cpp"
#include <algorithm>    // std::random_shuffle
#include <vector>

int main(int argc, char const *argv[])
{

	ifstream imagenesTrain;
        imagenesTrain.open("../data/train.dat");
        Matriz etiquetasTrain = Matriz(42000, 1);
        Matriz imagenesTrainM = lecturaTrain(imagenesTrain, etiquetasTrain);
        Matriz imagenesTrainMCopia=imagenesTrainM;
        imagenesTrain.close();
        Matriz imagenTrainI=Matriz(1,imagenesTrainM.DameAncho());

        ifstream pepe;
        pepe.open("./tests/test1.dat");
        Matriz foldsM=lecturaFold(pepe,5);
        pepe.close();

        int metodo=1;
        int alfa=30;
        int gamma=15;

	//cout<<randomFold(2);
	for(alfa = 1; alfa<=784; alfa++){
	cout<<"el promedio en la iteracion "<<alfa<<" de los folds es : "<<kFoldCrossVal(imagenesTrainM,5,alfa,gamma,etiquetasTrain,metodo,foldsM)<<endl;
}

/*
	ifstream imagenesTrain;
	imagenesTrain.open("../data/train.dat");
	Matriz etiquetasTrain = Matriz(42000, 1);
	Matriz imagenesTrainM = lecturaTrain(imagenesTrain, etiquetasTrain);
	imagenesTrain.close();



	ifstream pepe;
	pepe.open("./tests/test1.dat");
	Matriz foldsM = lecturaFold(pepe, 10);
	pepe.close();
	cout<<"foldsm esta en " << foldsM.DameAlto()<< " X "<<foldsM.DameAncho()<<endl;
	int contador=0;
	for (int i = 1; i <= 42000; ++i)
	{
		//cout<<i<<endl;
		if (foldsM.Obtener(i,1) == 1){

		contador+= foldsM.Obtener(i,1);
		
		}
	//cout<<foldsM.Obtener(i,1)<<" ";
	}
	cout<<"sal";
	cout<<foldsM;
	cout<<"putooo";
	Matriz nuevoTrain(contador,784);
	int j =1;
	for (int i = 1; i <= 42000; ++i)
	{
		if (foldsM.Obtener(i,1) == 1)
		{
			for (int k = 1; k<= 784; ++k)
			{
				nuevoTrain.Definir(j, k, imagenesTrainM.Obtener(i, k));
			}
		j=j+1;
		}
	}


for (int k = 1; k <= 10; ++k)
{
	Matriz img1(1,784);
	Matriz img2(1,784);
	for (int i = 1; i <=784; ++i)
	{
		img1.Definir(1,i, imagenesTrainM.Obtener(k,i));
		img2.Definir(1,i, nuevoTrain.Obtener(k,i));
	}
	//mostrarImagen(img1);
	//mostrarImagen(img2);

}



	//en nuevo train tengo el nuevo campo de training
	vector<double> medias = nuevoTrain.dameVectorMedias();
	nuevoTrain.centrarConMediaNuevo(medias, contador);
	Matriz trasp = nuevoTrain.Traspuesta();
	cout<<"la nuema matriz tiene tamaño"<<nuevoTrain.DameAlto()<<" X "<<nuevoTrain.DameAncho()<<endl;
	//Matriz xtx = trasp.multiMatricial(nuevoTrain);
	Matriz xtx = trasp.multiXtrans();
	
	Matriz autovalores(50,1);
	Matriz mb1 = xtx.baseAutovectores(30, autovalores, 50);
	Matriz autovector(784,1);
	autovector.Definir(50,1, 23);
	autovector.Definir(53,1, 2);
	autovector.Definir(58,1, 3);
	autovector.Definir(10,1, 2);

	cout<<"holaa"<<endl;
	//autovalores.Definir(1,1, xtx.dameAutovalor(autovector, 30));
	cout<<autovalores;
	Matriz prueba(3,3);
	Matriz autovalores(3,1);
	prueba.Definir(1,1,7);                               
	prueba.Definir(1,2,2);
	prueba.Definir(1,3,3);
	prueba.Definir(2,1,0);
	prueba.Definir(2,2,2);
	prueba.Definir(3,1,-6);
	prueba.Definir(3,2,-2);
	prueba.Definir(3,3,-2);
	prueba.baseAutovectores(30, autovalores, 3);
	cout<<autovalores;






*/

	return 0;
}
