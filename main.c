/*
* @file             Main.c
* @description      
* @assignment       1
* @date             11.12.2024
* @author           İrem AYVAZ  irem.ayvaz@stu.fsm.edu.tr
*/

#include <stdio.h>
#include <float.h>
#include <string.h>
#include <stdlib.h>
#include "Proje.h" // kendi yazdığım kütüphane

int main(int argc, char *argv[]){
    // calisan **calisanListesi = (calisan **)calloc(CALISAN_BIRIM_SIZE, sizeof(calisan *)); // tüm calisanlar
    // birim **birimListesi = (birim **)calloc(CALISAN_BIRIM_SIZE, sizeof(birim *)); // tüm birimler

    // calisan *calisan1 = calisanOlustur("İrem", "Ayvaz", 21221, 20000, 2022); // "calisan1" adinda yeni calisan olusturuyoruz
    // calisan *calisan2 = calisanOlustur("Hatice Hande", "Dereli", 21221, 25000, 2022); // "calisan2" adinda yeni calisan olusturuyoruz
    // calisan *calisan3 = calisanOlustur("Beyza", "Yilmaz", 21221, 35000, 2022); // "calisan3" adinda yeni calisan olusturuyoruz
    // calisan *calisan4 = calisanOlustur("Erva Sara", "Ozdal", 21221, 30000, 2022); // "calisan4" adinda yeni calisan olusturuyoruz

    // birim *birim1 = birimOlustur("Bilgisayar Muhendisligi", 21221); // "birim1" adında yeni birim olusturuyoruz
    // birimeCalisanEkle(birim1, calisan1); // calisan1'i birim1'e ekliyoruz
    // birimeCalisanEkle(birim1, calisan2); // calisan2'yi birim1'e ekliyoruz
    // birimeCalisanEkle(birim1, calisan3); // calisan3'ü birim1'e ekliyoruz
    // birimeCalisanEkle(birim1, calisan4); // calisan4'ü birim1'e ekliyoruz

    // calisan *calisan8 = calisanOlustur("Mesut", "Ayvaz", 61287, 70000, 1997); // "calisan8" adinda yeni calisan olusturuyoruz
    // birimeCalisanEkle(birim1, calisan8); // calisan4'ü birim1'e ekliyoruz

    // calisan *calisan5 = calisanOlustur("Ebrar", "Birinci", 21312, 40000, 2022); // "calisan1" adinda yeni calisan olusturuyoruz
    // calisan *calisan6 = calisanOlustur("Safak", "Kilic", 21312, 45000, 2022); // "calisan2" adinda yeni calisan olusturuyoruz
    // calisan *calisan7 = calisanOlustur("Sude", "Dogan", 21312, 35000, 2022); // "calisan3" adinda yeni calisan olusturuyoruz
    
    // birim *birim2 = birimOlustur("İnsaat Muhendisligi", 21312); // "birim1" adında yeni birim olusturuyoruz 
    // birimeCalisanEkle(birim2, calisan5);
    // birimeCalisanEkle(birim2, calisan6);
    // birimeCalisanEkle(birim2, calisan7);

    // birimiEkle(&birimListesi, birim1);
    // birimiEkle(&birimListesi, birim2);

    //dinamikBirimYazdir(birimListesi);
    
    //dosyayaYazdir(birimListesi, file_name);
    //dinamikBirimYazdir(birimListesi);
    //maasiGuncelle(birim1, 99999, 2024);

    //dosyayaYazdir(birimListesi, calisan_file, birim_file);

    printf("Gönderilen parametreler:\n");
    for (int i = 1; i < argc; i++) { // command line parameter
        printf("  %s\n", argv[i]);
    }

    // birim **yeniBirimListesi = (birim **)calloc(CALISAN_BIRIM_SIZE, sizeof(birim*));
    // calisan **yeniCalisanListesi = (calisan **)calloc(CALISAN_BIRIM_SIZE, sizeof(calisan *));

    // birimiDosyadanDiziyeAktar(birim_file, &yeniBirimListesi);
    // calisaniDosyadanDiziyeAktar(calisan_file, &yeniCalisanListesi, &yeniBirimListesi);

    // for (size_t b = 0; b < CALISAN_BIRIM_SIZE; b++) // yeniBirimListesini gez
    // {
    //     if(yeniCalisanListesi[b] == 0){ // yazdirilacak birim yoksa
    //         break; // donguden cik
    //     }
    //     // varsa
    //     calisanBilgileriniYazdir(yeniCalisanListesi[b]);
    // }

    // dinamikBirimYazdir(yeniBirimListesi);
    return 0;
}