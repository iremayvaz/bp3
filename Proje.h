/*
* @file             Proje.h
* @description      Oluşturulan Proje.c dosyasını kütüphane formuna dönüştürme
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
void calisaniEkle(calisan ***calisanListesi, calisan *newCalisan);
void calisanBilgileriniYazdir(calisan *employee);
void birimBilgileriniYazdir(birim *department);
void dinamikBirimYazdir(birim **birimListesi);
float birimMaasOrtHesapla(birim *department);
void yuksekMaasliCalisanListele(birim *department, float ortalamaMaas);
void enYuksekMaaslar(birim **birimListesi);
void maasiGuncelle(birim *birim, int yeniMaas, int suankiYil);
void dosyayaYaz(int argc, char *argv[], birim **birimListesi, calisan **calisanListesi);
void diziyeAktar(int argc, char *argv[], birim ***yeniBirimListesi, calisan ***yeniCalisanListesi);

#endif // DENEME_H