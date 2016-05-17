g++ -O2 mainTiempo.cpp -o mainTiempo


for(( i = 1; i < 16; i=i+1 )); do
     	echo "gamma $i"
	  printf '%i   ' $(($i)) >> tiempoPLS
	  ./mainTiempo 1 2 30 $i  >>tiempoPLS
	 done


