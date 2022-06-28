lib : add.o sub.o divi.o multi.o   
	gcc -shared -Wl,-soname,libshared.so.1 -o libshared.so.1.0.1 add.o sub.o divi.o multi.o   
	ln -s libshared.so.1.0.1 libshared.so.1
	ln -s libshared.so.1.0.1 libshared.so

add.o : add.c 
	gcc -c add.c

sub.o : sub.c
	gcc -c sub.c

multi.o : multi.c
	gcc -c multi.c

divi.o : divi.c
	gcc -c divi.c

clean : 
	rm -f add.o sub.o divi.o multi.o libshared.so.1.0.1 libshared.so.1 libshared.so

