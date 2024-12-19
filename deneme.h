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
#define SATIR 256

#define calisan_file "calisanlar.txt"
#define birim_file "birimler.txt"

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
birim *birimOlustur(char *birimAdi, unsigned short int birimKodu);
void birimeCalisanEkle(birim *department, calisan *employee);
void birimiEkle(birim ***birimListesi, birim *birim);
void calisanEkle(calisan ***calisanListesi, calisan *newCalisan);
void calisanBilgileriniYazdir(calisan *employee);
void birimBilgileriniYazdir(birim *department);
void dinamikBirimYazdir(birim **birimListesi);
float birimMaasOrtHesapla(birim *department);
void yuksekMaasliCalisanListele(birim *department, float ortalamaMaas);
void enYuksekMaaslar(birim **birimListesi);
void maasiGuncelle(birim *birim, int yeniMaas, int suankiYil);
void dosyayaYazdir(birim **yeniBirimListesi, const char *calisanlar_dosyasi, const char* birimler_dosyasi);

birim*** dosyadanDiziyeAktar(const char *birim_calisanlar_dosyasi, birim ***yeniBirimListesi);
//calisan **calisaniDiziyeAktar(const char *dosyaAdi);

#endif // DENEME_H