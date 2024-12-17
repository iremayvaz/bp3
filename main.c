/*
* @file
* @description      
* @assignment       1
* @date             11.12.2024
* @author           İrem AYVAZ  irem.ayvaz@stu.fsm.edu.tr
*/

#include <stdio.h>
#include <float.h>
#include <string.h>
#include <stdlib.h>
#include "deneme.h" // kendi yazdığım kütüphane

int main(){
    calisan **calisanListesi = (calisan **)calloc(CALISAN_BIRIM_SIZE, sizeof(calisan *)); // tüm calisanlar
    birim **birimListesi = (birim **)calloc(CALISAN_BIRIM_SIZE, sizeof(birim *)); // tüm birimler

    calisan *calisan1 = calisanOlustur("İrem", "Ayvaz", 21221, 20000, 2022); // "calisan1" adinda yeni calisan olusturuyoruz
    calisanBilgileriniYazdir(calisan1); // calisan1'in bilgilerini görelim

    printf("\n"); // satir atla

    calisan *calisan2 = calisanOlustur("Hatice Hande", "Dereli", 21221, 25000, 2022); // "calisan2" adinda yeni calisan olusturuyoruz
    calisanBilgileriniYazdir(calisan2); // calisan2'nin bilgilerini görelim

    printf("\n"); // satir atla

    calisan *calisan3 = calisanOlustur("Beyza", "Yilmaz", 21221, 35000, 2022); // "calisan3" adinda yeni calisan olusturuyoruz
    calisanBilgileriniYazdir(calisan3); // calisan3'ün bilgilerini görelim

    printf("\n"); // satir atla

    calisan *calisan4 = calisanOlustur("Erva Sara", "Ozdal", 21221, 30000, 2022); // "calisan4" adinda yeni calisan olusturuyoruz
    calisanBilgileriniYazdir(calisan4); // calisan4'ün bilgilerini görelim

    printf("\n"); // satir atla

    calisan **blmCalisanlari = (calisan **)calloc(CALISAN_BIRIM_SIZE, sizeof(calisan *)); // bolum calisanlari listesi
    blmCalisanlari = calisaniEkle(blmCalisanlari, calisan1); // calisan1'i blmCalisanlari'na ekliyoruz
    blmCalisanlari = calisaniEkle(blmCalisanlari, calisan2); // calisan2'yi blmCalisanlari'na ekliyoruz
    blmCalisanlari = calisaniEkle(blmCalisanlari, calisan3); // calisan3'ü blmCalisanlari'na ekliyoruz
    blmCalisanlari = calisaniEkle(blmCalisanlari, calisan4); // calisan4'ü blmCalisanlari'na ekliyoruz

    printf("\n"); // satir atla

    birim *birim1 = birimOlustur("Bilgisayar Muhendisligi", 21221, blmCalisanlari); // "birim1" adında yeni birim olusturuyoruz
    birimBilgileriniYazdir(birim1); // birim bilgilerini yazdiriyoruz.

    printf("\n"); // satir atla

    float ortMaas = birimMaasOrtHesapla(birim1);
    printf("BLM Ort: %.2f", ortMaas);

    printf("\n"); // satir atla

    yuksekMaasliCalisanListele(birim1, ortMaas);

    printf("\n"); // satir atla

    calisan **imCalisanlari = (calisan **)calloc(CALISAN_BIRIM_SIZE, sizeof(calisan *)); // bolum calisanlari listesi
    calisan *calisan5 = calisanOlustur("Ebrar", "Birinci", 21312, 40000, 2022); // "calisan1" adinda yeni calisan olusturuyoruz
    calisanBilgileriniYazdir(calisan5); // calisan1'in bilgilerini görelim

    printf("\n"); // satir atla

    calisan *calisan6 = calisanOlustur("Safak", "Kilic", 21312, 45000, 2022); // "calisan2" adinda yeni calisan olusturuyoruz
    calisanBilgileriniYazdir(calisan6); // calisan2'nin bilgilerini görelim

    printf("\n"); // satir atla

    calisan *calisan7 = calisanOlustur("Sude", "Dogan", 21312, 35000, 2022); // "calisan3" adinda yeni calisan olusturuyoruz
    calisanBilgileriniYazdir(calisan7); // calisan3'ün bilgilerini görelim

    printf("\n"); // satir atla

    imCalisanlari = calisaniEkle(imCalisanlari, calisan5);
    imCalisanlari = calisaniEkle(imCalisanlari, calisan6);
    imCalisanlari = calisaniEkle(imCalisanlari, calisan7);

    birim *birim2 = birimOlustur("İnsaat Muhendisligi", 21312, imCalisanlari); // "birim1" adında yeni birim olusturuyoruz
    birimBilgileriniYazdir(birim2); // birim bilgilerini yazdiriyoruz.

    printf("\n"); // satir atla

    float ortMaas2 = birimMaasOrtHesapla(birim2);
    printf("IM Ort: %.2f", ortMaas2);

    printf("\n"); // satir atla

    yuksekMaasliCalisanListele(birim2, ortMaas2);

    printf("\n"); // satir atla

    birimListesi = birimiEkle(birimListesi, birim1);
    birimListesi = birimiEkle(birimListesi, birim2);

    printf("\n"); // satir atla

    dinamikBirimYazdir(birimListesi);
    
    printf("\n"); // satir atla

    enYuksekMaaslar(birimListesi);

    printf("\n"); // satir atla
    calisan **ayvaz = (calisan **)calloc(CALISAN_BIRIM_SIZE, sizeof(calisan *)); // bolum calisanlari listesi

    calisan *calisan8 = calisanOlustur("Mesut", "Ayvaz", 61287, 70000, 1997); // "calisan8" adinda yeni calisan olusturuyoruz
    calisanBilgileriniYazdir(calisan8); // calisan8'in bilgilerini görelim

    printf("\n"); // satir atla

    calisan *calisan9 = calisanOlustur("Penbe", "Ayvaz", 61287, 30000, 1997); // "calisan9" adinda yeni calisan olusturuyoruz
    calisanBilgileriniYazdir(calisan9); // calisan9'un bilgilerini görelim
    
    printf("\n"); // satir atla

    calisan *calisan10 = calisanOlustur("Emre", "Ayvaz", 61287, 55000, 2021); // "calisan10" adinda yeni calisan olusturuyoruz
    calisanBilgileriniYazdir(calisan10); // calisan10'un bilgilerini görelim

    printf("\n"); // satir atla

    calisan *calisan11 = calisanOlustur("Seyma", "Akbal Ayvaz", 61287, 60000, 2020); // "calisan11" adinda yeni calisan olusturuyoruz
    calisanBilgileriniYazdir(calisan11); // calisan11'in bilgilerini görelim

    printf("\n"); // satir atla

    calisan *calisan12 = calisanOlustur("Ahmet", "Ayvaz", 61287, 2000, 2010); // "calisan12" adinda yeni calisan olusturuyoruz
    calisanBilgileriniYazdir(calisan12); // calisan12'nin bilgilerini görelim

    ayvaz = calisaniEkle(ayvaz, calisan8);
    ayvaz = calisaniEkle(ayvaz, calisan9);
    ayvaz = calisaniEkle(ayvaz, calisan10);
    ayvaz = calisaniEkle(ayvaz, calisan11);
    ayvaz = calisaniEkle(ayvaz, calisan12);

    birim *birim3 = birimOlustur("Ayvaz Ailesi", 61287, ayvaz); // "birim1" adında yeni birim olusturuyoruz
    birimBilgileriniYazdir(birim3); // birim bilgilerini yazdiriyoruz.

    printf("\n"); // satir atla

    float ortMaas3 = birimMaasOrtHesapla(birim3);
    printf("Ayvaz Ort: %.2f", ortMaas3);

    printf("\n"); // satir atla

    yuksekMaasliCalisanListele(birim3, ortMaas3);

    printf("\n"); // satir atla

    birimListesi = birimiEkle(birimListesi, birim3);

    printf("\n");

    enYuksekMaaslar(birimListesi);

    printf("\n"); // satir atla

    ayvaz = maasiGuncelle(ayvaz, 100000, 2024);
    birimBilgileriniYazdir(birim3);

    blmCalisanlari = maasiGuncelle(blmCalisanlari, 99999, 2024);
    birimBilgileriniYazdir(birim1);

    calisan *calisan13 = calisanOlustur("Rana", "Orten", 21221, 90000, 2022);
    blmCalisanlari = calisaniEkle(blmCalisanlari, calisan13);

    for (size_t eleman = 0; eleman < CALISAN_BIRIM_SIZE; eleman++) // calisanListesinde dolaşıyoruz
    {
        printf("Çalışan %d: %s %s\n", eleman + 1, blmCalisanlari[eleman]->calisanAdi, blmCalisanlari[eleman]->calisanSoyadi);
        printf("Birim: %u\n", blmCalisanlari[eleman]->birimKodu);
        printf("Maas: %d\n", blmCalisanlari[eleman]->maas);
        printf("Giris Yili: %d\n", blmCalisanlari[eleman]->girisYili);
    }
    
    return 0;
}