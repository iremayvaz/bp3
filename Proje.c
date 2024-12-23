/*  
* @file             Proje.c
* @description      Yeni çalışan ve birim oluşturulur.
                    Oluşturulan çalışan ilgili birime eklenir.
                    Oluşturulan çalışanlar ve birimler tüm çalışanların ve birimlerin tutulduğu dizilere eklenir.
                    Oluşturulan çalışanın, birimin ve birim listelerinin bilgileri yazdırılır.
                    İlgili birimin maaş ortalaması hesaplanır.
                    İlgili birimin ortalama maaşından yüksek maaş alan çalışanlarının bilgileri yazdırılır.
                    Tüm birimlerdeki birimin en yüksek maaşını alan çalışan bilgileri yazdırılır.
                    İlgili birimdeki çalışanlardan 10 yıldan fazladır çalışıp alınan parametreden düşük maaş alanların maaşlarını güncelleme
                    Tüm birim ve çalışan bilgilerini birimler ve çalışanlar dosyasına yazdırma
                    Tüm birim bilgilerini dosyadan diziye aktarma
                    Tüm çalışan bilgilerini ilgili birime aktarma ve dosyadan diziye aktarma
* @assignment       1
* @date             11.12.2024
* @author           İrem AYVAZ  irem.ayvaz@stu.fsm.edu.tr
*/

#include <stdio.h>
#include <float.h>
#include <string.h>
#include <stdlib.h>
#include "Proje.h" // kendi yazdığım kütüphane

int birimlerSize = 0; // birimler dizisi uzunluğu
int calisanlarSize = 0; // calisanlar dizisi uzunluğu

// ilgili değerlerle calisan struct döndüren fonksiyon
calisan *calisanOlustur(char *calisanAdi, char *calisanSoyadi, unsigned short int birimKodu, int maas, int girisYili){ 
    calisan *yeniCalisan = (calisan *)malloc(sizeof(calisan)); // yeniCalisan icin bellek tahsisi

    //if(yeniCalisan->calisanAdi == NULL){
        yeniCalisan->calisanAdi = (char *)malloc((strlen(calisanAdi) + 1) * sizeof(char)); // calisan ismi icin bellek tahsisi
    //} else {
    //    yeniCalisan->calisanAdi = calisanAdi;
    //}

    //if(yeniCalisan->calisanSoyadi == NULL){
        yeniCalisan->calisanSoyadi = (char *)malloc((strlen(calisanSoyadi) + 1) * sizeof(char)); // calisan soyismi icin bellek tahsisi
    //} else {
    //    yeniCalisan->calisanSoyadi = calisanSoyadi;
    //}

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

    //if(yeniBirim->birimAdi == NULL){
        yeniBirim->birimAdi = (char *)malloc((strlen(birimAdi) + 1) * sizeof(char)); // birim adi icin bellek tahsisi
    //} 
    //else
    //{
    //    yeniBirim->birimAdi = birimAdi;
    //}
    
    yeniBirim->birimCalisanlar = (calisan**)calloc(CALISAN_BIRIM_SIZE, sizeof(calisan *)); // birim calisanlari icin bellek tahsisi

    strcpy(yeniBirim->birimAdi, birimAdi); // birim adını ekle
    yeniBirim->birimKodu = birimKodu; // birim kodunu ekle

    return yeniBirim; // yeni birim
}

// oluşturulan çalışanı ilgili birime ekleme
void birimeCalisanEkle(birim *department, calisan *employee){ // main'den birim referans alınır
    for (size_t c = 0; c < CALISAN_BIRIM_SIZE; c++) // birimin birim calisanlarinda geziyoruz
    {
        if(department->birimCalisanlar[c] == NULL){ // calisan olmayan yere
            department->birimCalisanlar[c] = employee; // calisani yerlestirdik
            break;
        }
    }
    // guncellenmis birim
}

// oluşturulan birimi "yeniBirimListesi"ne ekleme
void birimiEkle(birim ***yeniBirimListesi, birim *department){ // main'den dizi referans alınır
    if((*yeniBirimListesi)[birimlerSize] == NULL){ // boş yere 
        (*yeniBirimListesi)[birimlerSize] = department; // yeni birimi yerleştir
        birimlerSize++;
        (*yeniBirimListesi) = realloc((*yeniBirimListesi), (birimlerSize + 1) * sizeof(birim*));
    } else {
        printf("Birim, birimler listesine eklenemedi.\n");
    }
    // guncellenmis birim listesi
}

// olusturulan calisani "calisanListesi"ne ekle
void calisaniEkle(calisan ***calisanListesi, calisan *newCalisan){ // main'den dizi referans alınır
    if((*calisanListesi)[calisanlarSize] == NULL){ // boş yere 
        (*calisanListesi)[calisanlarSize] = newCalisan; // yeni calisani yerleştir
        calisanlarSize++;
        (*calisanListesi) = realloc((*calisanListesi), (calisanlarSize + 1) * sizeof(calisan *));
    } else {
        printf("Calisan calisanlar listesine eklenemedi.\n");
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

    for (size_t c = 0; c < CALISAN_BIRIM_SIZE; c++)
    {
        if(department->birimCalisanlar[c] == NULL){
            break;
        }
        printf("\tÇalışan %d: %s %s\n", c + 1, department->birimCalisanlar[c]->calisanAdi, 
                                               department->birimCalisanlar[c]->calisanSoyadi);
        printf("\tMaas: %d\n", department->birimCalisanlar[c]->maas);
        printf("\tGiris Yili: %d\n", department->birimCalisanlar[c]->girisYili);
    }
}

// Birim türünden dinamik dizi bilgilerini yazdırma
void dinamikBirimYazdir(birim **yeniBirimListesi){
    for (size_t b = 0; b < birimlerSize; b++) // yeniBirimListesini gez
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
    for (size_t c = 0; c < CALISAN_BIRIM_SIZE; c++)
    {
        if(department->birimCalisanlar[c] != 0){
            if(department->birimCalisanlar[c]->maas > ortalamaMaas){ // calisan maasi, ort maastan yüksekse
                calisanBilgileriniYazdir(department->birimCalisanlar[c]);
            }
        }
    }
}

// her birimin ayrı ayrı en yüksek maaşlı çalışanlarını listeleme
void enYuksekMaaslar(birim **yeniBirimListesi){
    calisan *maxMaasliCalisan = (calisan *)malloc(sizeof(calisan)); // en yüksek maas icin default calisan

    for (size_t b = 0; b < birimlerSize; b++) // "yeniBirimListesi"ndeki birimleri dolaşıyoruz
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

    free(maxMaasliCalisan); // bellek tahsisi free edildi
}

// 10 yıldan fazla çalışanların maaşı parametre olarak verilen maaştan düşükse maaşı güncelleme
void maasiGuncelle(birim *birim, int yeniMaas, int suankiYil){
    for (size_t c = 0; c < CALISAN_BIRIM_SIZE; c++) // "calisanListesi"nde dolaşıyoruz
    {
        if(birim->birimCalisanlar[c] == 0){ // yazdirilacak calisan yoksa
            break; // donguden cik
        }
        
        if(suankiYil - birim->birimCalisanlar[c]->girisYili > 10){ // calisan 10 yildan fazla calistiysa
            if(birim->birimCalisanlar[c]->maas < yeniMaas){ // ve maasi, parametre olarak gönderilen maastan dusukse
                birim->birimCalisanlar[c]->maas = yeniMaas; // maasi guncelle
            }
        }
    }
}

// Tüm Birim ve Calisan bilgilerini dosyaya yazdırma
void dosyayaYaz(int argc, char *argv[], birim **birimListesi, calisan **calisanListesi){
    // dosyaya yazdirma modu
    FILE *birim = fopen(argv[1], "w");
    FILE *calisan = fopen(argv[2], "w");

    if (calisan == NULL || birim == NULL)
    { // dosya bossa?
        printf("birim Dosya bulunamadı");
        exit(EXIT_FAILURE);
    }

    // BIRIMLER
    for (size_t b = 0; b < birimlerSize; b++) // "birimListesi"ni dolaşıyoruz
    {
        if(birimListesi[b] == 0){ // yazdirilicak birim kalmadiysa
            break;
        }

        fprintf(birim, "%s, %u\n", birimListesi[b]->birimAdi,   // birim adi
                                   birimListesi[b]->birimKodu); // birim kodu
    }

    // CALISANLAR
    for (size_t c = 0; c < calisanlarSize; c++) // "calisanListesi"ni dolasiyoruz
    {
        if(calisanListesi[c] == 0){ // yazdirilacak calisan kalmadiysa
            break;
        }

        fprintf(calisan, "%s, %s, %u, %d, %d\n", calisanListesi[c]->calisanAdi, // calisanin adi
                                                 calisanListesi[c]->calisanSoyadi, // calisanin soyadi
                                                 calisanListesi[c]->birimKodu, // calisanin birim kodu
                                                 calisanListesi[c]->maas, // calisanin maasi
                                                 calisanListesi[c]->girisYili); // calisanin giris yili
    }
    
}

// Tüm Birim ve Calisan bilgilerini dosyadan diziye aktarma
void diziyeAktar(int argc, char *argv[], birim ***yeniBirimListesi, calisan ***yeniCalisanListesi){
    // dosyadan okuma modu
    FILE *birimler = fopen(argv[1], "r");
    FILE *calisanlar = fopen(argv[2], "r");

    if (birimler == NULL || calisanlar == NULL)
    { // dosya bossa?
        printf("Dosya acilamadi");
        exit(EXIT_FAILURE);
    }

    if((*yeniBirimListesi) == NULL || (*yeniCalisanListesi) == NULL){ // liste bossa?
        printf("Bellek acilamadi");
        exit(EXIT_FAILURE);
    }

    // BIRIMLER
    char birimSatiri[SATIR]; // Her satırı okumak için buffer

    while (fgets(birimSatiri, SATIR, birimler)) // birim dosyasındaki satirlari okuyoruz
    {
        char *yeniBirimAdi = (char *)calloc(AD_SOYAD_SIZE, sizeof(char)); // 30 birimlik bellek ayırıldı
        unsigned short int yeniBirimKodu;
        
        if (sscanf(birimSatiri, "%[^,], %u", yeniBirimAdi, &yeniBirimKodu) == 2) // birim adi
        {
            printf("Birim satiri okundu\n");

            // realloc
            int length = 0; // birimAdi uzunlugu

            for (size_t i = 0; i < AD_SOYAD_SIZE; i++)
            {
                if(yeniBirimAdi[i] == 0){
                    break;
                }
                length++;
            }

            yeniBirimAdi = realloc(yeniBirimAdi, (length + 1) * sizeof(char)); // satirdan okunan verinin uzunluğuyla realloc

            if(yeniBirimAdi == NULL){ // newDept olusturulabildi mi?
                printf("birim adi bellegi acilamadi");
                break;
            }

            // dosyadan okunan verilerle yeni birim olusturma
            birim *newDept = birimOlustur(yeniBirimAdi, yeniBirimKodu);

            if(newDept == NULL){ // newDept olusturulabildi mi?
                printf("yeni birim icin bellek acilamadi");
                break;
            }

            birimiEkle(yeniBirimListesi, newDept); // yeni olusturulan birimi listeye ekleme
        }
        else // dosyadaki satir okunamadiysa
        {
            printf("Birim satiri okunamadi");
        }
    }

    // CALİSANLAR
    char calisanSatiri[SATIR]; // Her satırı okumak için buffer

    while (fgets(calisanSatiri, SATIR, calisanlar)) // dosyadaki satirlari okuyoruz
    {
        char *yeniCalisanAdi = (char*)calloc(AD_SOYAD_SIZE, sizeof(char)); // calisanAdi icin 30 birimlik bellek ayirildi
        char *yeniCalisanSoyadi = (char*)calloc(AD_SOYAD_SIZE, sizeof(char)); // calisanAdi icin 30 birimlik bellek ayirildi
        unsigned short int yeniBirimKodu;
        int yeniMaas;
        int yeniGirisYili;
        
        if(yeniCalisanAdi == NULL){
            printf("Ad icin bellek ayiramadim\n");
            break;
        }else {
            printf("Ad ayirdim\n");
        }
        if(yeniCalisanSoyadi == NULL){
            printf("Soyad icin bellek ayiramadim\n");
            break;
        }else {
            printf("Soyad ayirdim\n");
        }

        if (sscanf(calisanSatiri, "%[^,], %[^,], %u, %d, %d\n", yeniCalisanAdi, yeniCalisanSoyadi, &yeniBirimKodu, &yeniMaas, &yeniGirisYili) == 5) // birim adi
        {
            printf("Calisan satiri okundu\n");

            // calisan adi icin realloc
            int adLength = 0; // birimAdi uzunlugu
            for (size_t i = 0; i < AD_SOYAD_SIZE; i++)
            {
                if(yeniCalisanAdi[i] == 0){
                    break;
                }
                adLength++;
            }
            yeniCalisanAdi = realloc(yeniCalisanAdi, (adLength + 1) * sizeof(char));

            if(yeniCalisanAdi == NULL){ // newDept olusturulabildi mi?
                printf("calisan adi bellegi acilamadi");
                break;
            }

            // calisan soyadi icin realloc
            int soyadLength = 0;
            for (size_t i = 0; i < AD_SOYAD_SIZE; i++)
            {
                if(yeniCalisanSoyadi[i] == 0){
                    break;
                }
                soyadLength++;
            }
            yeniCalisanSoyadi = realloc(yeniCalisanSoyadi, (soyadLength + 1) * sizeof(char));

            if(yeniCalisanSoyadi == NULL){ // newDept olusturulabildi mi?
                printf("calisan soyadi bellegi acilamadi");
                break;
            }

            // dosyadan alinan verilerden yeni calisan olusturma
            calisan *newEmp = calisanOlustur(yeniCalisanAdi, yeniCalisanSoyadi, yeniBirimKodu, yeniMaas, yeniGirisYili);

            //calisanBilgileriniYazdir(newEmp);
            if (newEmp == NULL)
            {
                printf("bellek acilamadi");
                break;
            }

            calisaniEkle(yeniCalisanListesi, newEmp);
            for (size_t i = 0; i < CALISAN_BIRIM_SIZE; i++)
            {
                if(((*yeniBirimListesi)[i]) == NULL){
                    printf("Birim bos");
                    break;
                }

                if(newEmp->birimKodu == (*yeniBirimListesi)[i]->birimKodu){
                    birimeCalisanEkle((*yeniBirimListesi)[i], newEmp);
                    break;
                }
            }
        }
        else 
        {
            printf("Calisan satiri okunamadi\n");
        }

    }

    fclose(birimler);
    fclose(calisanlar);
}

// Bellek tahsislerini free'le
void freeAll(birim **departments, calisan **employees) {
    if (departments == NULL) {
        printf("\nDepartments zaten bos\n");
        return;
    }

    for (size_t b = 0; b < birimlerSize; b++) {
        if (departments[b] != NULL) {
            if (departments[b]->birimCalisanlar != NULL) {
                /*for (size_t c = 0; c < CALISAN_BIRIM_SIZE; c++) {
                    if (departments[b]->birimCalisanlar[c] != NULL) {
                        if (departments[b]->birimCalisanlar[c]->calisanAdi != NULL) {
                            free(departments[b]->birimCalisanlar[c]->calisanAdi);
                            departments[b]->birimCalisanlar[c]->calisanAdi = NULL;
                        }

                        if (departments[b]->birimCalisanlar[c]->calisanSoyadi != NULL) {
                            free(departments[b]->birimCalisanlar[c]->calisanSoyadi);
                            departments[b]->birimCalisanlar[c]->calisanSoyadi = NULL;
                        }

                        free(departments[b]->birimCalisanlar[c]);
                        departments[b]->birimCalisanlar[c] = NULL;
                    }
                }*/
                free(departments[b]->birimCalisanlar);
                departments[b]->birimCalisanlar = NULL;
            }

            if (departments[b]->birimAdi != NULL) {
                free(departments[b]->birimAdi);
                departments[b]->birimAdi = NULL;
            }

            free(departments[b]);
            departments[b] = NULL;
        }
    }

    free(departments);
    departments = NULL;

    if (employees != NULL) {
        for (size_t c = 0; c < calisanlarSize; c++) {
            if (employees[c] != NULL) {
                if (employees[c]->calisanAdi != NULL) {
                    free(employees[c]->calisanAdi);
                    employees[c]->calisanAdi = NULL;
                }

                if (employees[c]->calisanSoyadi != NULL) {
                    free(employees[c]->calisanSoyadi);
                    employees[c]->calisanSoyadi = NULL;
                }

                free(employees[c]);
                employees[c] = NULL;
            }
        }
        free(employees);
        employees = NULL;
    }

    printf("Tüm bellek serbest bırakıldı.\n");
}