shareout : main.o 
	cd libmakefile; make lib; cd ..
	gcc -I./libmakefile -L./libmakefile -o sharedout main.c -Wl,--rpath=./libmakefile -lshared

main.o : main.c
	gcc -c main.c
clean : 
	rm -f libmakefile/libshared.so.1.0.1 libmakefile/libsharedso.1 libmakefile/libshared.so sharedout 
	cd libmakefile; make clean

