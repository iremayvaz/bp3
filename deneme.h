/*
* @file
* @description      
* @assignment       1
* @date             11.12.2024
* @author           İrem AYVAZ  irem.ayvaz@stu.fsm.edu.tr
*/

#ifndef DENEME_H
#define DENEME_H

// Gerekli kütüphaneleri dahil et
#include <stdio.h>
#include <float.h>
#include <string.h>
#include <stdlib.h>

#define AD_SOYAD_SIZE 30 // Birim adı, Çalışan adı ve soyadı için karakter sınırlaması
#define CALISAN_BIRIM_SIZE  20 // Birim ve çalışan listeleri için eleman sınırlaması
#define file_name "birimCalisanlar.txt" // Dosya adı

// YAPILAR (STRUCT)
typedef struct {
    char *calisanAdi;
    char *calisanSoyadi;
    unsigned short int birimKodu;
    int maas;
    int girisYili;
} calisan;

typedef struct {
    char *birimAdi;
    unsigned short int birimKodu;
    calisan **birimCalisanlar;
} birim;

// FONKSİYONLAR
calisan *calisanOlustur(char *calisanAdi, char *calisanSoyadi, unsigned short int birimKodu, int maas, int girisYili);
birim *birimOlustur(char *birimAdi, unsigned short int birimKodu, calisan **birimCalisanlar);
calisan **calisaniEkle(calisan **calisanListesi, calisan *calisan);
birim **birimiEkle(birim **birimListesi, birim *birim);
void calisanBilgileriniYazdir(calisan *employee);
void birimBilgileriniYazdir(birim *department);
void dinamikBirimYazdir(birim **birimListesi);
float birimMaasOrtHesapla(birim *department);
void yuksekMaasliCalisanListele(birim *department, float ortalamaMaas);
void enYuksekMaaslar(birim **birimListesi);
calisan **maasiGuncelle(calisan **calisanListesi, int yeniMaas, int suankiYil);
/*
void dosyayaYazdir(birim **birimListesi, const char* dosya, int size);
birim **dosyadanDiziyeAktar(birim **yeniBirimListesi, const char *dosya);
*/
#endif // DENEME_H