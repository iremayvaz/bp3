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
#include "deneme.h" // kendi yazdığım kütüphane   %[^\n]

// ilgili değerlerle calisan struct döndüren fonksiyon
calisan *calisanOlustur(char *calisanAdi, char *calisanSoyadi, unsigned short int birimKodu, int maas, int girisYili){ 
    calisan *yeniCalisan = (calisan *)malloc(sizeof(calisan)); // yeniCalisan icin bellek tahsisi

    yeniCalisan->calisanAdi = (char *)malloc((strlen(calisanAdi) + 1) * sizeof(char)); // calisan ismi icin bellek tahsisi
    yeniCalisan->calisanSoyadi = (char *)malloc((strlen(calisanSoyadi) + 1) * sizeof(char)); // calisan soyismi icin bellek tahsisi

    strcpy(yeniCalisan->calisanAdi, calisanAdi); 
    strcpy(yeniCalisan->calisanSoyadi, calisanSoyadi);
    yeniCalisan->birimKodu = birimKodu;
    yeniCalisan->maas = maas;
    yeniCalisan->girisYili = girisYili;

    return yeniCalisan; // yeni calisan
}

// ilgili değerlerle birim struct döndüren fonksiyon
birim *birimOlustur(char *birimAdi, unsigned short int birimKodu){ 
    birim *yeniBirim = (birim *)malloc(sizeof(birim)); // yeniBirim icin bellek tahsisi

    yeniBirim->birimAdi = (char *)malloc((strlen(birimAdi) + 1) * sizeof(char)); // birim adi icin bellek tahsisi
    yeniBirim->birimCalisanlar = (calisan**) calloc(CALISAN_BIRIM_SIZE, sizeof(calisan *)); // birim calisanlari icin bellek tahsisi

    strcpy(yeniBirim->birimAdi, birimAdi); // birim adını ekle
    yeniBirim->birimKodu = birimKodu; // birim kodunu ekle

    return yeniBirim; // yeni birim
}

// oluşturulan çalışanı ilgili birime ekleme
void birimeCalisanEkle(birim *department, calisan *employee){ // main'den birim referans alınır
    for (size_t eleman = 0; eleman < CALISAN_BIRIM_SIZE; eleman++) // birimin "birimCalisanlar"inda dolaşıyoruz
    {
        if(department->birimCalisanlar[eleman] == NULL){ // birimCalisanlardaki bos yere geldik
            department->birimCalisanlar[eleman] = employee; // calisani yerlestirdik
            break; // donguden ciktik
        }
    }
    // guncellenmis birim
}

// oluşturulan birimi "birimListesi"ne ekleme
void birimiEkle(birim ***birimListesi, birim *birim){ // main'den birimListesi dizisi referans alınır
    for (size_t eleman = 0; eleman < CALISAN_BIRIM_SIZE; eleman++) // birim listesinde gez
    {
        if((*birimListesi)[eleman] == NULL){ // boş yere 
            (*birimListesi)[eleman] = birim; // yeni birimi yerleştir
            break; // döngüden çık
        }
    }
    // guncellenmis birim listesi
}

// olusturulan calisani "calisanListesi"ne ekle
void calisanEkle(calisan ***calisanListesi, calisan *newCalisan){ // main'den calisanListesi dizisi referans alınır
    for (size_t eleman = 0; eleman < CALISAN_BIRIM_SIZE; eleman++) // calisan listesinde gez
        {
            if((*calisanListesi)[eleman] == NULL){ // boş yere 
                (*calisanListesi)[eleman] = newCalisan; // yeni calisani yerleştir
                break; // döngüden çık
            }
        }
    
}

// Calisan türündeki değişen bilgilerini yazdırma
void calisanBilgileriniYazdir(calisan *employee){ 
    printf("Çalışan: %s %s\n", employee->calisanAdi, employee->calisanSoyadi);
    printf("Birim: %u\n", employee->birimKodu);
    printf("Maas: %d\n", employee->maas);
    printf("Giris Yili: %d\n", employee->girisYili);
}

// Birim türündeki değişen bilgilerini yazdırma
void birimBilgileriniYazdir(birim *department){ 
    printf("Birim Adi: %s\n", department->birimAdi);
    printf("Birim Kodu: %u\n", department->birimKodu);

    printf("Birim Calisanlari:\n");

    for (size_t eleman = 0; eleman < CALISAN_BIRIM_SIZE; eleman++)
    {
        if(department->birimCalisanlar[eleman] == NULL){
            break;
        }
        printf("\tÇalışan %d: %s %s\n", eleman + 1, department->birimCalisanlar[eleman]->calisanAdi, 
                                     department->birimCalisanlar[eleman]->calisanSoyadi);
        printf("\tMaas: %d\n", department->birimCalisanlar[eleman]->maas);
        printf("\tGiris Yili: %d\n", department->birimCalisanlar[eleman]->girisYili);
    }
}

// Birim türünden dinamik dizi bilgilerini yazdırma
void dinamikBirimYazdir(birim **birimListesi){
    for (size_t eleman = 0; eleman < CALISAN_BIRIM_SIZE; eleman++) // birimListesini gez
    {
        if(birimListesi[eleman] == 0){ // yazdirilacak birim yoksa
            break; // donguden cik
        }
        // varsa
        birimBilgileriniYazdir(birimListesi[eleman]);
        
        for (size_t i = 0; i < CALISAN_BIRIM_SIZE; i++) // birimCalisanlarini geziyoruz
        {
            if(birimListesi[eleman]->birimCalisanlar[i] == 0){ // "birimCalisanlar"inda gosterilecek eleman yoksa
                break; // donguden cik
            }
            // varsa
            calisanBilgileriniYazdir(birimListesi[eleman]->birimCalisanlar[i]);
        }
    }
}

// Birimin çalışanlarının maaş ort.unu hesaplama 
float birimMaasOrtHesapla(birim *department){
    int count = 0; // kişi sayısı belirlemek için
    int total = 0; // kişilerin toplam maaşı

    for (size_t eleman = 0; eleman < CALISAN_BIRIM_SIZE; eleman++) // birimdeki "birimCalisanlar"ı geziyoruz
    {
        if(department->birimCalisanlar[eleman] != 0){ // calisan varsa
            total += department->birimCalisanlar[eleman]->maas; // calisanlarin maaslarinin toplami
            count++; // calisan sayisi
        }
    }

    return (float)(total / count);
}

// Birimdeki ort maaştan yüksek maaş alan çalışanları listeleme
void yuksekMaasliCalisanListele(birim *department, float ortalamaMaas){
    for (size_t eleman = 0; eleman < CALISAN_BIRIM_SIZE; eleman++)
    {
        if(department->birimCalisanlar[eleman] != 0){
            if(department->birimCalisanlar[eleman]->maas > ortalamaMaas){ // calisan maasi, ort maastan yüksekse
                printf("\nÇalışan: %s %s\n", department->birimCalisanlar[eleman]->calisanAdi, 
                                                         department->birimCalisanlar[eleman]->calisanSoyadi);
                printf("Birim: %u\n", department->birimCalisanlar[eleman]->birimKodu);
                printf("Maas: %d\n", department->birimCalisanlar[eleman]->maas);
                printf("Giris Yili: %d\n", department->birimCalisanlar[eleman]->girisYili);
            }
        }
    }
}

// her birimin ayrı ayrı en yüksek maaşlı çalışanlarını listeleme
void enYuksekMaaslar(birim **birimListesi){
    calisan *maxMaasliCalisan = (calisan *)malloc(sizeof(calisan)); // en yüksek maas icin default calisan

    for (size_t b = 0; b < CALISAN_BIRIM_SIZE; b++) // "birimListesi"ndeki birimleri dolaşıyoruz
    {
        if(birimListesi[b] == 0){ // yazdirilacak birim yoksa
            break; // donguden cik
        }

        maxMaasliCalisan = birimListesi[b]->birimCalisanlar[0]; // her birimin en yuksek maasi icin default

        for (size_t c = 0; c < CALISAN_BIRIM_SIZE; c++) // her birimdeki "birimCalisanlar"i dolasiyoruz
        {
            if(birimListesi[b]->birimCalisanlar[c] == 0){ // "birimCalisanlar"inda gosterilecek eleman yoksa
                break; // donguden cik
            }

            if(maxMaasliCalisan->maas < birimListesi[b]->birimCalisanlar[c]->maas){ // birimdeki calisan maasi, default maastan yüksekse
                maxMaasliCalisan = birimListesi[b]->birimCalisanlar[c]; // default maxMaasi değiş
            }
        }
        // Birimin en yüksek maasini alan calisan bilgilerini yazdir
        printf("\n%u kodlu biriminin yüksek maaşlı\n", maxMaasliCalisan->birimKodu);
        printf("Çalışanı: %s %s\n", maxMaasliCalisan->calisanAdi, maxMaasliCalisan->calisanSoyadi);
        printf("Birim: %u\n", maxMaasliCalisan->birimKodu);
        printf("Maas: %d\n", maxMaasliCalisan->maas);
        printf("Giris Yili: %d\n", maxMaasliCalisan->girisYili);
    }
}

// 10 yıldan fazla çalışanların maaşı parametre olarak verilen maaştan düşükse maaşı güncelleme
birim *maasiGuncelle(birim *birim, int yeniMaas, int suankiYil){
    for (size_t eleman = 0; eleman < CALISAN_BIRIM_SIZE; eleman++) // "calisanListesi"nde dolaşıyoruz
    {
        if(birim->birimCalisanlar[eleman] == 0){ // yazdirilacak calisan yoksa
            break; // donguden cik
        }
        
        if(suankiYil - birim->birimCalisanlar[eleman]->girisYili > 10){ // calisan 10 yildan fazla calistiysa
            if(birim->birimCalisanlar[eleman]->maas < yeniMaas){ // ve maasi, parametre olarak gönderilen maastan dusukse
                birim->birimCalisanlar[eleman]->maas = yeniMaas; // maasi guncelle
            }
        }
    }

    return birim;
}

// Tüm Birim ve Calisan bilgilerini dosyaya yazdırma
void dosyayaYazdir(birim **birimListesi, const char* birim_calisanlar_dosyasi){
    FILE *birimFile = fopen(birim_calisanlar_dosyasi, "w"); // dosyaya yazma modu

    if(birimFile == NULL){ // dosya bossa?
        printf("birim Dosya bulunamadı");
        exit(EXIT_FAILURE);
    }

    for (size_t eleman = 0; eleman < CALISAN_BIRIM_SIZE; eleman++) // "birimListesi"ni dolaşıyoruz
    {
        if(birimListesi[eleman] == 0){ // yazdirilicak birim kalmadiysa
            break;
        }

        fprintf(birimFile, "Birim Adi: %s\n", birimListesi[eleman]->birimAdi); // birim adı
        fprintf(birimFile, "Birim Kodu: %u\n", birimListesi[eleman]->birimKodu); // birim kodu
        fprintf(birimFile, "Birim Calisanlar:\n");
        for (size_t calisanlarSize = 0; calisanlarSize < CALISAN_BIRIM_SIZE; calisanlarSize++) // birimin "birimCalisanlar"ini dolasiyoruz
        {
            if(birimListesi[eleman]->birimCalisanlar[calisanlarSize] == 0){ // yazdirilacak calisan kalmadiysa
                break;
            }

            fprintf(birimFile, "\tÇalışan: %s %s\n", birimListesi[eleman]->birimCalisanlar[calisanlarSize]->calisanAdi, // birimdeki calisanin adi
                                                                    birimListesi[eleman]->birimCalisanlar[calisanlarSize]->calisanSoyadi); // birimdeki calisanin soyadi
            fprintf(birimFile, "\tMaas: %d\n", birimListesi[eleman]->birimCalisanlar[calisanlarSize]->maas); // birimdeki calisanin maasi
            fprintf(birimFile, "\tGiris Yili: %d\n", birimListesi[eleman]->birimCalisanlar[calisanlarSize]->girisYili); // birimdeki calisanin giris yili
        }
    }
}

// Tüm Birim ve Calisan bilgilerini dosyadan diziye aktarma
birim **dosyadanDiziyeAktar(birim **yeniBirimListesi, const char *birim_calisanlar_dosyasi){
    FILE *file = fopen(birim_calisanlar_dosyasi, "r"); // dosyadan okuma modu

    if(file == NULL){ // dosya bossa?
        printf("Dosya acilamadi");
        exit(EXIT_FAILURE);
    }

    char satir[256]; // Her satırı okumak için buffer
    int birimSayisi = -1; // birim sayisi
    int calisanSayisi = 0; // calisan sayisi

    while (fgets(satir, sizeof(satir), file)) // dosyadaki satirlari okuyoruz
    {
        if (strncmp(satir, "Birim Adi: ", 10) == 0) // birim adi
        {
            birimSayisi++;

            // birim listesindeki birim için bellek
            yeniBirimListesi[birimSayisi] = (birim *)malloc(sizeof(birim)); 
            // birim listesindeki birimin adi icin bellek
            yeniBirimListesi[birimSayisi]->birimAdi = (char *)malloc(AD_SOYAD_SIZE * sizeof(char)); 
            // birim listesindeki birimin calisanlari icin bellek
            yeniBirimListesi[birimSayisi]->birimCalisanlar = (calisan **)malloc(CALISAN_BIRIM_SIZE * sizeof(calisan*));

            // birim adini "yeniBirimListesi"ndeki birimin adina atama
            sscanf(satir, "Birim Adi: %s\n", yeniBirimListesi[birimSayisi]->birimAdi); 
            
        }
        else if (strncmp(satir, "Birim Kodu: ", 11) == 0) // birim kodu
        {
            // birim kodunu "yeniBirimListesi"ndeki birimin koduna atama
            sscanf(satir, "Birim Kodu: %u\n", yeniBirimListesi[birimSayisi]->birimKodu); 
        } 
        else if (strncmp(satir, "Birim Calisanlar:\n", 8) == 0) // birimin calisanlari
        {
            // Çalışan için bellek ayırma
            yeniBirimListesi[birimSayisi]->birimCalisanlar[calisanSayisi] = (calisan *)malloc(sizeof(calisan));
                // birim listesindeki birimin calisanlarindaki calisanin adi icin bellek
            yeniBirimListesi[birimSayisi]->birimCalisanlar[calisanSayisi]->calisanAdi = (char *)malloc(AD_SOYAD_SIZE * sizeof(char));
                // birim listesindeki birimin calisanlarindaki calisanin soyadi icin bellek
            yeniBirimListesi[birimSayisi]->birimCalisanlar[calisanSayisi]->calisanSoyadi = (char *)malloc(AD_SOYAD_SIZE * sizeof(char));
        } 
        else if (strncmp(satir, "\tÇalışan:\n", 8) == 0) // birimin calisanlari
        {
            // calisan adini "yeniBirimListesi"ndeki "birimCalisanlar"daki calisanin adina atama
            // calisan soyadini "yeniBirimListesi"ndeki "birimCalisanlar"daki calisanin soyadina atama
            sscanf(satir, "\tÇalışan: %s %s\n", yeniBirimListesi[birimSayisi]->birimCalisanlar[calisanSayisi]->calisanAdi, 
                                                yeniBirimListesi[birimSayisi]->birimCalisanlar[calisanSayisi]->calisanSoyadi); 
        } 
        else if (strncmp(satir, "\tMaas: ", 5) == 0) // calisanin maasi
        {
            // calisan maasini "yeniBirimListesi"ndeki "birimCalisanlar"daki calisanin maasina atama
            sscanf(satir, "\tMaas: %d\n", yeniBirimListesi[birimSayisi]->birimCalisanlar[calisanSayisi]->maas); 
        } 
        else if (strncmp(satir, "\tGiris Yili: ", 10) == 0) // calisanin giris yili
        {
            // calisan giris yilini "yeniBirimListesi"ndeki "birimCalisanlar"daki calisanin giris yilina atama
            sscanf(satir, "\tGiris Yili: %d\n", yeniBirimListesi[birimSayisi]->birimCalisanlar[calisanSayisi]->girisYili); 
            calisanSayisi++; // Bir çalışanın tüm verilerini okuduktan sonra sayaç artırıyoruz
        }
        
    }

    //free(yeniBirimListesi); // ??
    fclose(file);

    return yeniBirimListesi;
}