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
    for (size_t b = 0; b < CALISAN_BIRIM_SIZE; b++) // birimin "birimCalisanlar"inda dolaşıyoruz
    {
        if(department->birimCalisanlar[b] == NULL){ // birimCalisanlardaki bos yere geldik
            department->birimCalisanlar[b] = employee; // calisani yerlestirdik
            break; // donguden ciktik
        }
    }
    // guncellenmis birim
}

// oluşturulan birimi "yeniBirimListesi"ne ekleme
void birimiEkle(birim **yeniBirimListesi, birim *birim){ // main'den yeniBirimListesi dizisi referans alınır
    for (size_t b = 0; b < CALISAN_BIRIM_SIZE; b++) // birim listesinde gez
    {
        if(yeniBirimListesi[b] == NULL){ // boş yere 
            yeniBirimListesi[b] = birim; // yeni birimi yerleştir
            break; // döngüden çık
        }
    }
    // guncellenmis birim listesi
}

// olusturulan calisani "calisanListesi"ne ekle
void calisanEkle(calisan **calisanListesi, calisan *newCalisan){ // main'den calisanListesi dizisi referans alınır
    for (size_t b = 0; b < CALISAN_BIRIM_SIZE; b++) // calisan listesinde gez
        {
            if(calisanListesi[b] == NULL){ // boş yere 
                calisanListesi[b] = newCalisan; // yeni calisani yerleştir
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

    for (size_t b = 0; b < CALISAN_BIRIM_SIZE; b++)
    {
        if(department->birimCalisanlar[b] == NULL){
            break;
        }
        printf("\tÇalışan %d: %s %s\n", b + 1, department->birimCalisanlar[b]->calisanAdi, 
                                     department->birimCalisanlar[b]->calisanSoyadi);
        printf("\tMaas: %d\n", department->birimCalisanlar[b]->maas);
        printf("\tGiris Yili: %d\n", department->birimCalisanlar[b]->girisYili);
    }
}

// Birim türünden dinamik dizi bilgilerini yazdırma
void dinamikBirimYazdir(birim **yeniBirimListesi){
    for (size_t b = 0; b < CALISAN_BIRIM_SIZE; b++) // yeniBirimListesini gez
    {
        if(yeniBirimListesi[b] == 0){ // yazdirilacak birim yoksa
            break; // donguden cik
        }
        // varsa
        birimBilgileriniYazdir(yeniBirimListesi[b]);
    }
}

// Birimin çalışanlarının maaş ort.unu hesaplama 
float birimMaasOrtHesapla(birim *department){
    int count = 0; // kişi sayısı belirlemek için
    int total = 0; // kişilerin toplam maaşı

    for (size_t b = 0; b < CALISAN_BIRIM_SIZE; b++) // birimdeki "birimCalisanlar"ı geziyoruz
    {
        if(department->birimCalisanlar[b] != 0){ // calisan varsa
            total += department->birimCalisanlar[b]->maas; // calisanlarin maaslarinin toplami
            count++; // calisan sayisi
        }
    }

    return (float)(total / count);
}

// Birimdeki ort maaştan yüksek maaş alan çalışanları listeleme
void yuksekMaasliCalisanListele(birim *department, float ortalamaMaas){
    for (size_t b = 0; b < CALISAN_BIRIM_SIZE; b++)
    {
        if(department->birimCalisanlar[b] != 0){
            if(department->birimCalisanlar[b]->maas > ortalamaMaas){ // calisan maasi, ort maastan yüksekse
                calisanBilgileriniYazdir(department->birimCalisanlar[b]);
            }
        }
    }
}

// her birimin ayrı ayrı en yüksek maaşlı çalışanlarını listeleme
void enYuksekMaaslar(birim **yeniBirimListesi){
    calisan *maxMaasliCalisan = (calisan *)malloc(sizeof(calisan)); // en yüksek maas icin default calisan

    for (size_t b = 0; b < CALISAN_BIRIM_SIZE; b++) // "yeniBirimListesi"ndeki birimleri dolaşıyoruz
    {
        if(yeniBirimListesi[b] == 0){ // yazdirilacak birim yoksa
            break; // donguden cik
        }

        maxMaasliCalisan = yeniBirimListesi[b]->birimCalisanlar[0]; // her birimin en yuksek maasi icin default

        for (size_t c = 0; c < CALISAN_BIRIM_SIZE; c++) // her birimdeki "birimCalisanlar"i dolasiyoruz
        {
            if(yeniBirimListesi[b]->birimCalisanlar[c] == 0){ // "birimCalisanlar"inda gosterilecek b yoksa
                break; // donguden cik
            }

            if(maxMaasliCalisan->maas < yeniBirimListesi[b]->birimCalisanlar[c]->maas){ // birimdeki calisan maasi, default maastan yüksekse
                maxMaasliCalisan = yeniBirimListesi[b]->birimCalisanlar[c]; // default maxMaasi değiş
            }
        }
        // Birimin en yüksek maasini alan calisan bilgilerini yazdir
        calisanBilgileriniYazdir(maxMaasliCalisan);
    }
}

// 10 yıldan fazla çalışanların maaşı parametre olarak verilen maaştan düşükse maaşı güncelleme
void maasiGuncelle(birim *birim, int yeniMaas, int suankiYil){
    for (size_t b = 0; b < CALISAN_BIRIM_SIZE; b++) // "calisanListesi"nde dolaşıyoruz
    {
        if(birim->birimCalisanlar[b] == 0){ // yazdirilacak calisan yoksa
            break; // donguden cik
        }
        
        if(suankiYil - birim->birimCalisanlar[b]->girisYili > 10){ // calisan 10 yildan fazla calistiysa
            if(birim->birimCalisanlar[b]->maas < yeniMaas){ // ve maasi, parametre olarak gönderilen maastan dusukse
                birim->birimCalisanlar[b]->maas = yeniMaas; // maasi guncelle
            }
        }
    }
}

// Tüm Birim ve Calisan bilgilerini dosyaya yazdırma
void dosyayaYazdir(birim **yeniBirimListesi, const char *calisanlar_dosyasi, const char* birimler_dosyasi){
    FILE *calisanlar = fopen(calisanlar_dosyasi, "w"); // dosyaya yazma modu
    FILE *birimler = fopen(birimler_dosyasi, "w");

    if (calisanlar == NULL || birimler == NULL)
    { // dosya bossa?
        printf("birim Dosya bulunamadı");
        exit(EXIT_FAILURE);
    }

    for (size_t b = 0; b < CALISAN_BIRIM_SIZE; b++) // "yeniBirimListesi"ni dolaşıyoruz
    {
        if(yeniBirimListesi[b] == 0){ // yazdirilicak birim kalmadiysa
            break;
        }

        fprintf(birimler, "%s, %u\n", yeniBirimListesi[b]->birimAdi,   // birim adi
                                         yeniBirimListesi[b]->birimKodu); // birim kodu
    
        for (size_t c = 0; c < CALISAN_BIRIM_SIZE; c++) // birimin "birimCalisanlar"ini dolasiyoruz
        {
            if(yeniBirimListesi[b]->birimCalisanlar[c] == 0){ // yazdirilacak calisan kalmadiysa
                break;
            }

            fprintf(calisanlar, "\t%s %s, %u, %d, %d\n",  yeniBirimListesi[b]->birimCalisanlar[c]->calisanAdi, // birimdeki calisanin adi
                                                          yeniBirimListesi[b]->birimCalisanlar[c]->calisanSoyadi, // birimdeki calisanin soyadi
                                                          yeniBirimListesi[b]->birimCalisanlar[c]->birimKodu, // birimdeki calisanin birim kodu
                                                          yeniBirimListesi[b]->birimCalisanlar[c]->maas, // birimdeki calisanin maasi
                                                          yeniBirimListesi[b]->birimCalisanlar[c]->girisYili); // birimdeki calisanin giris yili
        }
    }
}

// Tüm Birim ve Calisan bilgilerini dosyadan diziye aktarma
birim** dosyadanDiziyeAktar(const char *birim_calisanlar_dosyasi, birim **yeniBirimListesi){
    FILE *file = fopen(birim_calisanlar_dosyasi, "r"); // dosyadan okuma modu
    
    if(file == NULL){ // dosya bossa?
        printf("Dosya acilamadi");
        exit(EXIT_FAILURE);
    }

    if(yeniBirimListesi == NULL){ // dosya bossa?
        printf("Bellek acilamadi");
        exit(EXIT_FAILURE);
    }
    
    char satir[SATIR]; // Her satırı okumak için buffer
    int birimSayisi = -1; // birim sayisi
    int calisanSayisi = 0; // calisan sayisi

    char yeniCalisanAdi[AD_SOYAD_SIZE];
    char yeniCalisanSoyadi[AD_SOYAD_SIZE];
    int yeniMaas;
    int yeniGirisYili;

    birim *tempDept = NULL;

    while (fgets(satir, SATIR, file)) // dosyadaki satirlari okuyoruz
    {
        char yeniBirimAdi[AD_SOYAD_SIZE];
        unsigned short int yeniBirimKodu;
        
        if (sscanf(satir, "%s, %u\n", yeniBirimAdi, &yeniBirimKodu) == 2) // birim adi
        {
            printf("Birim satiri okundu\n");
            tempDept = NULL;
            calisanSayisi = 0;

            birim *newDept = birimOlustur(yeniBirimAdi, yeniBirimKodu);
            if(newDept == NULL){
                printf("bellek acilamadi");
                break;
            }
            birimBilgileriniYazdir(newDept);
            birimSayisi++;

            tempDept = newDept;

            birimiEkle(yeniBirimListesi, newDept);
        }
        else 
        {
            printf("Satir okunamadi");
        }
    }

    fclose(file);

    return yeniBirimListesi;
}

/*
calisan **calisaniDiziyeAktar(const char* dosyaAdi){
    FILE *file; // dosyadan okuma modu

    if((file = fopen(dosyaAdi, "r")) == NULL){
        printf("Dosya bulunamadi");
        exit(EXIT_FAILURE);
    }
    else
    {

    }
}
*/