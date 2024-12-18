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
    calisan *calisan2 = calisanOlustur("Hatice Hande", "Dereli", 21221, 25000, 2022); // "calisan2" adinda yeni calisan olusturuyoruz
    calisan *calisan3 = calisanOlustur("Beyza", "Yilmaz", 21221, 35000, 2022); // "calisan3" adinda yeni calisan olusturuyoruz
    calisan *calisan4 = calisanOlustur("Erva Sara", "Ozdal", 21221, 30000, 2022); // "calisan4" adinda yeni calisan olusturuyoruz

    birim *birim1 = birimOlustur("Bilgisayar Muhendisligi", 21221); // "birim1" adında yeni birim olusturuyoruz
    birimeCalisanEkle(birim1, calisan1); // calisan1'i birim1'e ekliyoruz
    birimeCalisanEkle(birim1, calisan2); // calisan2'yi birim1'e ekliyoruz
    birimeCalisanEkle(birim1, calisan3); // calisan3'ü birim1'e ekliyoruz
    birimeCalisanEkle(birim1, calisan4); // calisan4'ü birim1'e ekliyoruz

    birimBilgileriniYazdir(birim1); // birim bilgilerini yazdiriyoruz.

    printf("\n"); // satir atla

    calisan *calisan8 = calisanOlustur("Mesut", "Ayvaz", 61287, 70000, 1997); // "calisan8" adinda yeni calisan olusturuyoruz
    birimeCalisanEkle(birim1, calisan8); // calisan4'ü birim1'e ekliyoruz

    birimBilgileriniYazdir(birim1);

    birim1 = maasiGuncelle(birim1, 100000, 2024);

    birimBilgileriniYazdir(birim1);

    calisan *calisan5 = calisanOlustur("Ebrar", "Birinci", 21312, 40000, 2022); // "calisan1" adinda yeni calisan olusturuyoruz
    calisan *calisan6 = calisanOlustur("Safak", "Kilic", 21312, 45000, 2022); // "calisan2" adinda yeni calisan olusturuyoruz
    calisan *calisan7 = calisanOlustur("Sude", "Dogan", 21312, 35000, 2022); // "calisan3" adinda yeni calisan olusturuyoruz
    
    birim *birim2 = birimOlustur("İnsaat Muhendisligi", 21312); // "birim1" adında yeni birim olusturuyoruz 
    birimeCalisanEkle(birim2, calisan5);
    birimeCalisanEkle(birim2, calisan6);
    birimeCalisanEkle(birim2, calisan7);

    birimBilgileriniYazdir(birim2); // birim bilgilerini yazdiriyoruz.

    printf("\n"); // satir atla

    birimiEkle(birimListesi, birim1);
    birimiEkle(birimListesi, birim2);

    printf("\n"); // satir atla

    dinamikBirimYazdir(birimListesi);
    
    printf("\n"); // satir atla

    dosyayaYazdir(birimListesi, birim_file, calisan_file);
    return 0;
}