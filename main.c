/*
* @file             Main.c
* @description      Proje.h kütüphanesinin fonksiyonlarının uygulaması
* @assignment       1
* @date             11.12.2024
* @author           İrem AYVAZ  irem.ayvaz@stu.fsm.edu.tr
*/

#include <stdio.h>
#include <float.h>
#include <string.h>
#include <stdlib.h>
#include "Proje1.h" // kendi yazdığım kütüphane

extern int calisanlarSize; // "calisanlarListesi" uzunluğu
extern int birimlerSize; // "birimlerListesi" uzunluğu

int main(int argc, char *argv[])
{ // command line parameter
    // önce birimler.txt ve calisanlar.txt dosyalarındaki verileri aktarmak için
    // iki tane yeni dizi oluşturuyorum.
    birim **birimler = (birim **)malloc(sizeof(birim *));
    calisan **calisanlar = (calisan **)malloc(sizeof(calisan *));

    // sonra dosyalardaki verileri dizilere aktarıyorum.
    diziyeAktar(argc, argv, &birimler, &calisanlar);

    // diziye aktarılmış mı kontrol edelim
    dinamikBirimYazdir(birimler);

    /*calisan *c1 = calisanOlustur("Muhammet Mustafa", "Sağlam", 26754, 35000, 2001);
    calisan *c1 = calisanOlustur("Mehmet Aral", "Özaltın", 26754, 30000, 2022);
    calisan *c1 = calisanOlustur("Elif Nur", "Gül", 26754, 30000, 2022);*/

    return 0;
}