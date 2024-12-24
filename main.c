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

    // birimlerin en yüksek maaşlı çalışanlarını görelim
    enYuksekMaaslar(birimler);

    // birimlerin ortalama maaşlarını hesaplayalım.
    birim *bm = birimler[0];
    float bm_avg = birimMaasOrtHesapla(bm);
    printf("Bilgisayar Muhendisligi maas ortalamasi: %.2f\n", bm_avg);

    birim *im = birimler[1];
    float im_avg = birimMaasOrtHesapla(im);
    printf("İnsaat Muhendisligi maas ortalamasi: %.2f\n", im_avg);

    // Birimde 10+ yıldır çalışan ama maaşı ortalamadan düşük olanların maaşlarını güncelleyelim
    maasiGuncelle(bm, 99999, 2024);
    birimBilgileriniYazdir(bm);

    maasiGuncelle(im, 111111, 2024);
    birimBilgileriniYazdir(im);

    // yeni çalışanlar oluşturalım
    calisan *newEmp1 = calisanOlustur("Muhammet Mustafa", "Sağlam", 26754, 35000, 2001);
    calisan *newEmp2 = calisanOlustur("Mehmet Aral", "Özaltın", 26754, 30000, 2022);
    calisan *newEmp3 = calisanOlustur("Elif Nur", "Gül", 26754, 30000, 2022);

    // çalışan bilgilerini görelim
    calisanBilgileriniYazdir(newEmp1);
    calisanBilgileriniYazdir(newEmp2);
    calisanBilgileriniYazdir(newEmp3);

    // yeni birim oluşturalım
    birim *newDepartment = birimOlustur("Elektrik Elektronik Muhendisligi", 26754);

    // çalışanları birime ekleyelim
    birimeCalisanEkle(newDepartment, newEmp1);
    birimeCalisanEkle(newDepartment, newEmp2);
    birimeCalisanEkle(newDepartment, newEmp3);

    // çalışanları "calisanlar"a ekleyelim
    calisaniEkle(&calisanlar, newEmp1);
    calisaniEkle(&calisanlar, newEmp2);
    calisaniEkle(&calisanlar, newEmp3);

    // birimi "birimler"e ekleyelim
    birimiEkle(&birimler, newDepartment);

    // yeni guncellemelerle dizileri dosyalara aktaralım
    dosyayaYaz(argc, argv, birimler, calisanlar);

    // tahsis edilen bellekleri serbest bırakalım
    freeAll(birimler, calisanlar);

    return 0;
}