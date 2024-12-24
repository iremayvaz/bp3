program:
	gcc-14 Main.c Proje1.c	Proje1.h	-o	main
	./main birimler.txt	calisanlar.txt

clean:
	rm -f *.o program