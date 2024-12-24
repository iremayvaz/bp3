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
#include "Proje1.h" // kendi yazdığım kütüphane

int birimlerSize = 0; // birimler dizisi uzunluğu
int calisanlarSize = 0; // calisanlar dizisi uzunluğu

// ilgili değerlerle calisan struct döndüren fonksiyon
calisan *calisanOlustur(char *calisanAdi, char *calisanSoyadi, unsigned short int birimKodu, int maas, int girisYili){ 
    calisan *yeniCalisan = (calisan *)malloc(sizeof(calisan)); // yeniCalisan icin bellek tahsisi
    
    yeniCalisan->calisanAdi = strdup(calisanAdi); 
    yeniCalisan->calisanSoyadi = strdup(calisanSoyadi);
    yeniCalisan->birimKodu = birimKodu;
    yeniCalisan->maas = maas;
    yeniCalisan->girisYili = girisYili;

    return yeniCalisan; // yeni calisan
}

// ilgili değerlerle birim struct döndüren fonksiyon
birim *birimOlustur(char *birimAdi, unsigned short int birimKodu){ 
    birim *yeniBirim = (birim *)malloc(sizeof(birim)); // yeniBirim icin bellek tahsisi
    
    yeniBirim->birimCalisanlar = (calisan**)calloc(birimCalisanlarSize, sizeof(calisan *)); // birim calisanlari icin 20 birimlik bellek tahsisi

    yeniBirim->birimAdi = strdup(birimAdi); // birim adını ekle
    yeniBirim->birimKodu = birimKodu; // birim kodunu ekle

    return yeniBirim; // yeni birim
}

// oluşturulan çalışanı ilgili birime ekleme
void birimeCalisanEkle(birim *department, calisan *employee){ // main'den birim ve calisan referans alınır
    if(department->birimKodu == employee->birimKodu)
    {
        for (size_t c = 0; c < (birimCalisanlarSize - 1); c++) // birimin birim calisanlarinda geziyoruz
        {
                if(department->birimCalisanlar[c] == NULL){ // calisan olmayan yere
                    department->birimCalisanlar[c] = employee; // calisani yerlestirdik
                    printf("Çalışan birime yerleştirildi.\n"); // kullanıcıyı bilgilendirme
                    break;
                }
        }
    } else {
        printf("Çalışan yanlış birime eklenmeye çalışılıyor!");
    }
}

// oluşturulan birimi "yeniBirimListesi"ne ekleme
void birimiEkle(birim ***yeniBirimListesi, birim *department){ // main'den dizi referans alınır
    (*yeniBirimListesi) = realloc((*yeniBirimListesi), (birimlerSize + 1) * sizeof(birim*));

    if((*yeniBirimListesi)[birimlerSize] == NULL){ // boş yere 
        (*yeniBirimListesi)[birimlerSize] = department; // yeni birimi yerleştir
        birimlerSize++;
    } else {
        printf("Birim, birimler listesine eklenemedi.\n");
    }
    // guncellenmis birim listesi
}

// olusturulan calisani "calisanListesi"ne ekle
void calisaniEkle(calisan ***calisanListesi, calisan *newCalisan){ // main'den dizi referans alınır
    (*calisanListesi) = realloc((*calisanListesi), (calisanlarSize + 1) * sizeof(calisan *));
    if((*calisanListesi)[calisanlarSize] == NULL)
    { // boş yere 
        (*calisanListesi)[calisanlarSize] = newCalisan; // yeni calisani yerleştir
        calisanlarSize++;
    } else {
        printf("Çalışan, çalışanlar listesine eklenemedi.\n");
    }
}

// Calisan türündeki değişen bilgilerini yazdırma
void calisanBilgileriniYazdir(calisan *employee){
    printf("------------------------------------------\n");
    printf("Çalışan: %s %s\n", employee->calisanAdi, employee->calisanSoyadi);
    printf("Birim: %u\n", employee->birimKodu);
    printf("Maaş: %d\n", employee->maas);
    printf("Giriş Yılı: %d\n", employee->girisYili);
    printf("------------------------------------------\n");
}

// Birim türündeki değişen bilgilerini yazdırma
void birimBilgileriniYazdir(birim *department){ 
    printf("------------------------------------------\n");
    printf("Birim Adı: %s\n", department->birimAdi);
    printf("Birim Kodu: %u\n", department->birimKodu);

    printf("Birim Çalışanları:\n");

    for (size_t c = 0; c < birimCalisanlarSize; c++)
    {
        if(department->birimCalisanlar[c] == NULL){
            break;
        }
        printf("\tÇalışan %d: %s %s\n", c + 1, department->birimCalisanlar[c]->calisanAdi, 
                                               department->birimCalisanlar[c]->calisanSoyadi);
        printf("\tMaaş: %d\n", department->birimCalisanlar[c]->maas);
        printf("\tGiriş Yılı: %d\n", department->birimCalisanlar[c]->girisYili);
    }
    printf("------------------------------------------\n");
}

// Birim türünden dinamik dizi bilgilerini yazdırma
void dinamikBirimYazdir(birim **yeniBirimListesi){
    printf("------Birimler dizisi yazdırılıyor------\n");
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
    printf("---Birimin maaş ortalaması hesaplanıyor---\n");
    int count = 0; // kişi sayısı belirlemek için
    int total = 0; // kişilerin toplam maaşı

    for (size_t b = 0; b < birimCalisanlarSize; b++) // birimdeki "birimCalisanlar"ı geziyoruz
    {
        if(department->birimCalisanlar[b] != 0){ // calisan varsa
            total += department->birimCalisanlar[b]->maas; // çalışanların maaşlarının toplamı
            count++; // calisan sayisi
        }
    }

    return (float)(total / count);
}

// Birimdeki ort maaştan yüksek maaş alan çalışanları listeleme
void yuksekMaasliCalisanListele(birim *department, float ortalamaMaas){
    printf("--Birimin yüksek maaşlı çalışanları yazdırılıyor--\n");
    for (size_t c = 0; c < birimCalisanlarSize; c++)
    {
        if(department->birimCalisanlar[c] != NULL){ // çalışan varsa
            if(department->birimCalisanlar[c]->maas > ortalamaMaas){ // çalışan maaşı, ortalama maaştan yüksekse
                calisanBilgileriniYazdir(department->birimCalisanlar[c]);
            }
        }
    }
}

// her birimin ayrı ayrı en yüksek maaşlı çalışanlarını listeleme
void enYuksekMaaslar(birim **yeniBirimListesi){
    calisan *maxMaasliCalisan = (calisan *)malloc(sizeof(calisan)); // en yüksek maaş icin default çalışan

    printf("-En yüksek maaşlı çalışanlar yazdırılıyor-\n");

    for (size_t b = 0; b < birimlerSize; b++) // "yeniBirimListesi"ndeki birimleri dolaşıyoruz
    {
        if(yeniBirimListesi[b] == 0){ // yazdirilacak birim yoksa
            break; // donguden cik
        }

        maxMaasliCalisan = yeniBirimListesi[b]->birimCalisanlar[0]; // her birimin en yüksek maaşı için default

        for (size_t c = 0; c < birimCalisanlarSize; c++) // her birimdeki "birimCalisanlar"i dolaşıyoruz
        {
            if(yeniBirimListesi[b]->birimCalisanlar[c] == 0){ // "birimCalisanlar"ında gösterilecek çalışan yoksa
                break; // döngüden çık
            }

            if(maxMaasliCalisan->maas < yeniBirimListesi[b]->birimCalisanlar[c]->maas){ // birimdeki çalışan maaşı, default maaştan yüksekse
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
    printf("----------Maaşlar güncelleniyor----------\n");
    for (size_t c = 0; c < birimCalisanlarSize; c++) // "calisanListesi"nde dolaşıyoruz
    {
        if(birim->birimCalisanlar[c] == 0){ // yazdirilacak calisan yoksa
            break; // donguden cik
        }
        
        if(suankiYil - birim->birimCalisanlar[c]->girisYili > 10){ // calisan 10 yildan fazla calistiysa
            if(birim->birimCalisanlar[c]->maas < yeniMaas){ // ve maasi, parametre olarak gönderilen maastan dusukse
                birim->birimCalisanlar[c]->maas = yeniMaas; // maasi guncelle
                printf("Çalışan %d maaşı başarıyla güncellendi.\n", (c + 1));
            }
        }
    }
}

// Tüm Birim ve Calisan bilgilerini dosyaya yazdırma
void dosyayaYaz(int argc, char *argv[], birim **birimListesi, calisan **calisanListesi){
    // dosyaya yazdirma modu
    FILE *birimFile = fopen(argv[1], "w");
    FILE *calisanFile = fopen(argv[2], "w");

    if (calisanFile == NULL || birimFile == NULL)
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

        fprintf(birimFile, "%s, %u\n", birimListesi[b]->birimAdi,   // birim adi
                                       birimListesi[b]->birimKodu); // birim kodu
    }

    fclose(birimFile);

    // CALISANLAR
    for (size_t c = 0; c < calisanlarSize; c++) // "calisanListesi"ni dolasiyoruz
    {
        if(calisanListesi[c] == 0){ // yazdirilacak calisan kalmadiysa
            break;
        }

        fprintf(calisanFile, "%s, %s, %u, %d, %d\n", calisanListesi[c]->calisanAdi, // calisanin adi
                                                     calisanListesi[c]->calisanSoyadi, // calisanin soyadi
                                                     calisanListesi[c]->birimKodu, // calisanin birim kodu
                                                     calisanListesi[c]->maas, // calisanin maasi
                                                     calisanListesi[c]->girisYili); // calisanin giris yili
    }

    fclose(calisanFile);
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

    // BIRIMLER
    char satir[SATIR]; // Her satırı okumak için buffer

    while (fgets(satir, SATIR, birimler)) // birim dosyasındaki satirlari okuyoruz
    {
        char yeniBirimAdi[SATIR];
        unsigned short int yeniBirimKodu;
        
        if (sscanf(satir, "%[^,], %u", yeniBirimAdi, &yeniBirimKodu) == 2) // birim adi
        {
            printf("Birim satiri okundu\n");

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

    fclose(birimler);

    // CALİSANLAR

    while (fgets(satir, SATIR, calisanlar)) // dosyadaki satirlari okuyoruz
    {
        char yeniCalisanAdi[256]; // calisanAdi icin 30 birimlik bellek ayirildi
        char yeniCalisanSoyadi[256]; // calisanAdi icin 30 birimlik bellek ayirildi
        unsigned short int yeniBirimKodu;
        int yeniMaas;
        int yeniGirisYili;

        if (sscanf(satir, "%[^,], %[^,], %u, %d, %d\n", yeniCalisanAdi, yeniCalisanSoyadi, &yeniBirimKodu, &yeniMaas, &yeniGirisYili) == 5) // birim adi
        {
            printf("Calisan satiri okundu\n");

            // dosyadan alinan verilerden yeni calisan olusturma
            calisan *newEmp = calisanOlustur(yeniCalisanAdi, yeniCalisanSoyadi, yeniBirimKodu, yeniMaas, yeniGirisYili);

            //calisanBilgileriniYazdir(newEmp);
            if (newEmp == NULL)
            {
                printf("bellek acilamadi");
                break;
            }

            calisaniEkle(yeniCalisanListesi, newEmp);

            for (size_t i = 0; i < birimlerSize; i++) // birimler listesini geziyoruz
            {
                if(((*yeniBirimListesi)[i]) == NULL){
                    printf("Birim bos");
                    break;
                }

                if(newEmp->birimKodu == (*yeniBirimListesi)[i]->birimKodu){ // çalışanın birim kodu ile eşleşen birim bulununca
                    birimeCalisanEkle((*yeniBirimListesi)[i], newEmp); // çalışanı birime ekle
                    break;
                }
            }
        }
        else 
        {
            printf("Calisan satiri okunamadi\n");
        }

    }

    fclose(calisanlar);
}

// Bellek tahsislerini free'le
void freeAll(birim **departments, calisan **employees) {
    if (departments == NULL) {
        printf("\nDepartments zaten bos\n");
        return;
    }

    if (employees == NULL) {
        printf("\nEmployees zaten bos\n");
        return;
    }

    for (size_t b = 0; b < birimlerSize; b++) 
    {
        free(departments[b]->birimCalisanlar);
        free(departments[b]->birimAdi);
        free(departments[b]);
    }

    free(departments);

    
    for (size_t c = 0; c < calisanlarSize; c++) {    
        free(employees[c]->calisanAdi);
        free(employees[c]->calisanSoyadi);
        free(employees[c]);
    }
    
    free(employees);
    
    printf("Tüm bellek serbest bırakıldı.\n");
}