make clean 
make
for(( i = 128; i < 1700; i=i+128 )); do
     	echo "corriendo filtro para una matriz de $i x $i"
	  printf '%i   ' $(($i*$i)) >> SEPIAFATFAST
	  ./build/tp2 sepia -i asm ./img/lena.${i}x${i}.bmp -t 100 >>SEPIAFATFAST
	 done