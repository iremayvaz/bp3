all: maked run

maked: main.o proje1.o
	gcc-14	main.o proje1.o	-o	maked

main.o: Main.c
	gcc-14	-c Main.c

proje1.o: Proje1.c Proje1.h
	gcc-14	-c Proje1.c

clean:
	rm -rf *o maked

run:	
	./maked birimler.txt calisanlar.txt