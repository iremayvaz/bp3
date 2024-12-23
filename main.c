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
    // birimi farketmeksizin tum çalışanların ekleneceği dizi
    calisan **calisanListesi = (calisan **)calloc(calisanlarSize, sizeof(calisan *)); 
    // tüm birimler
    birim **birimListesi = (birim **)calloc(birimlerSize, sizeof(birim *)); 

    // çalışan oluştur
    calisan *calisan1 = calisanOlustur("İrem", "Ayvaz", 21221, 20000, 2022); // "calisan1" adinda yeni calisan olusturuyoruz
    calisan *calisan2 = calisanOlustur("Hatice Hande", "Dereli", 21221, 25000, 2022); // "calisan2" adinda yeni calisan olusturuyoruz
    calisan *calisan3 = calisanOlustur("Beyza", "Yilmaz", 21221, 35000, 2022); // "calisan3" adinda yeni calisan olusturuyoruz
    calisan *calisan4 = calisanOlustur("Erva Sara", "Ozdal", 21221, 30000, 2022); // "calisan4" adinda yeni calisan olusturuyoruz
    calisan *calisan5 = calisanOlustur("Mesut", "Ayvaz", 21221, 70000, 1997); // "calisan5" adinda yeni calisan olusturuyoruz
    
    // birim oluştur
    birim *bm = birimOlustur("Bilgisayar Muhendisligi", 21221); // "birim1" adında yeni birim olusturuyoruz
    
    // çalışanları birime ekle
    birimeCalisanEkle(bm, calisan1); // calisan1'i birim1'e ekliyoruz
    birimeCalisanEkle(bm, calisan2); // calisan2'yi birim1'e ekliyoruz
    birimeCalisanEkle(bm, calisan3); // calisan3'ü birim1'e ekliyoruz
    birimeCalisanEkle(bm, calisan4); // calisan4'ü birim1'e ekliyoruz
    birimeCalisanEkle(bm, calisan5); // calisan4'ü birim1'e ekliyoruz

    // yeni çalışan oluştur
    calisan *calisan6 = calisanOlustur("Ebrar", "Birinci", 21312, 40000, 2022); // "calisan6" adinda yeni calisan olusturuyoruz
    calisan *calisan7 = calisanOlustur("Safak", "Kilic", 21312, 45000, 2022); // "calisan7" adinda yeni calisan olusturuyoruz
    calisan *calisan8 = calisanOlustur("Sude", "Dogan", 21312, 35000, 2022); // "calisan8" adinda yeni calisan olusturuyoruz
    
    // yeni birim oluştur
    birim *im = birimOlustur("İnsaat Muhendisligi", 21312); // "birim1" adında yeni birim olusturuyoruz 

    // çalışanları birime ekle
    birimeCalisanEkle(im, calisan6);
    birimeCalisanEkle(im, calisan7);
    birimeCalisanEkle(im, calisan8);

    // birimleri tüm birimler dizisine ekle
    birimiEkle(&birimListesi, bm);
    birimiEkle(&birimListesi, im);

    // çalışanları tüm çalışanlar dizisine ekle
    calisaniEkle(&calisanListesi, calisan1);
    calisaniEkle(&calisanListesi, calisan2);
    calisaniEkle(&calisanListesi, calisan3);
    calisaniEkle(&calisanListesi, calisan4);
    calisaniEkle(&calisanListesi, calisan5);
    calisaniEkle(&calisanListesi, calisan6);
    calisaniEkle(&calisanListesi, calisan7);
    calisaniEkle(&calisanListesi, calisan8);

    // "calisanListesi"ni gez
    printf("------------------------------------------\n");
    printf("-------Tüm çalışanlar yazdırılıyor--------\n");
    printf("------------------------------------------\n");
    for (size_t c = 0; c < calisanlarSize; c++) // yeniBirimListesini gez
    {
        if(calisanListesi[c] == 0){ // yazdırılacak çalışan yoksa
            break; // donguden cik
        }
        // varsa
        calisanBilgileriniYazdir(calisanListesi[c]); // çalışan yazdır
    }
    printf("------------------------------------------\n");
    printf("-------------Çalışanlar bitti-------------\n");
    printf("------------------------------------------\n");

    printf("------------------------------------------\n");
    printf("-----------------Birimler-----------------\n");
    printf("------------------------------------------\n");
    for (size_t b = 0; b < calisanlarSize; b++) // yeniBirimListesini gez
    {
        if(birimListesi[b] == 0){ // yazdırılacak çalışan yoksa
            break; // donguden cik
        }
        // varsa
        birimBilgileriniYazdir(birimListesi[b]); // birim yazdır
    }
    printf("------------------------------------------\n");
    printf("--------------Birimler bitti--------------\n");
    printf("------------------------------------------\n");


    // tüm birimleri tutan "birimlerListesi"ni yazdır
    printf("------------------------------------------\n");
    printf("--------Tüm birimler yazdırılıyor---------\n");
    printf("------------------------------------------\n");
    dinamikBirimYazdir(birimListesi);
    printf("------------------------------------------\n");
    printf("--------------Birimler bitti--------------\n");
    printf("------------------------------------------\n");

    // birimin maaş ortalaması
    float bm_avg = birimMaasOrtHesapla(bm);
    float im_avg = birimMaasOrtHesapla(im);

    // birimlerin belli bir maaş değerinden yüksek olan çalışanları
    yuksekMaasliCalisanListele(bm, bm_avg);
    yuksekMaasliCalisanListele(im, im_avg);

    // tüm birimlerdeki en yüksek maaşlar
    enYuksekMaaslar(birimListesi);

    // şu anki yıla göre 10 seneden fazladır çalışanların maaşı
    // eğer parametre alınan maaştan düşükse
    maasiGuncelle(bm, 99999, 2024);
    maasiGuncelle(im, 77777, 2024);

    // yapılanlar dosyaya eklenir
    dosyayaYaz(argc, argv, birimListesi, calisanListesi);
    
    // dosyadaki verilerimi dizilere aktarıyorum.
    birim **yeniBirimListesi = (birim **)calloc(birimCalisanlarSize, sizeof(birim*)); // tüm birimleri aktaracağım liste
    calisan **yeniCalisanListesi = (calisan **)calloc(birimCalisanlarSize, sizeof(calisan *)); // tüm çalışanları aktaracağım liste
    
    // dosyadan dizilere aktarıyorum.
    diziyeAktar(argc, argv, &yeniBirimListesi, &yeniCalisanListesi);

    // dosyadan diziye aktarılan birimleri görelim
    dinamikBirimYazdir(yeniBirimListesi);

    // dosyada bazı güncellemeler yapacağım.
    // yeni çalışan oluştur
    calisan *calisan9 = calisanOlustur("Rana", "Orten", 12345, 20000, 2000); // "calisan9" adinda yeni calisan olusturuyoruz
    calisan *calisan10 = calisanOlustur("Dilara", "Kuloglu", 12345, 4000, 2024); // "calisan10" adinda yeni calisan olusturuyoruz
    calisan *calisan11 = calisanOlustur("Ekrem", "Bas", 12345, 40000, 2020); // "calisan11" adinda yeni calisan olusturuyoruz
    calisan *calisan12 = calisanOlustur("Umit", "Ozteker", 12345, 30000, 2000); // "calisan12" adinda yeni calisan olusturuyoruz
    calisan *calisan13 = calisanOlustur("Mehmet Enes", "Erden", 12345, 35000, 2014); // "calisan13" adinda yeni calisan olusturuyoruz
    calisan *calisan14 = calisanOlustur("Muhammet Mustafa", "Sağlam", 12345, 90000, 2001); // "calisan14" adinda yeni calisan olusturuyoruz

    // çalışanları çalışanlar dizisine ekle
    calisaniEkle(&calisanListesi, calisan9);
    calisaniEkle(&calisanListesi, calisan10);
    calisaniEkle(&calisanListesi, calisan11);
    calisaniEkle(&calisanListesi, calisan12);
    calisaniEkle(&calisanListesi, calisan13);
    calisaniEkle(&calisanListesi, calisan14);

    // yeni birim oluştur
    birim *yeniNesil = birimOlustur("Yeni Nesil", 12345);

    // birimi birimler dizisine ekle
    birimiEkle(&birimListesi, yeniNesil);

    // çalışanları birime ekle
    birimeCalisanEkle(yeniNesil, calisan9);
    birimeCalisanEkle(yeniNesil, calisan10);
    birimeCalisanEkle(yeniNesil, calisan11);
    birimeCalisanEkle(yeniNesil, calisan12);
    birimeCalisanEkle(yeniNesil, calisan13);
    birimeCalisanEkle(yeniNesil, calisan14);

    // yapılan güncellemeleri dosyaya aktaralım
    dosyayaYaz(argc, argv, birimListesi, calisanListesi);

    // yapılan bellek tahsislerini serbest bırakma
    freeAll(birimListesi, calisanListesi);
    freeAll(yeniBirimListesi, yeniCalisanListesi);
    
    return 0;
}