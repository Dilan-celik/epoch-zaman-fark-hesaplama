#include <stdio.h>
#include <time.h>

// Tarih ve saat bilgisi i�in struct
struct DateTime {
    int yil, ay, gun, saat, dakika, saniye;
};

// Struct ve epoch zaman�n� ayn� bellek alan�nda saklamak i�in union
union TimeData {
    struct DateTime dt;
    time_t epoch;
};

// Kullan�c�dan tarih ve saat bilgisi alma fonksiyonu
void tarihBilgisiAl(struct DateTime *dt) {
    printf("Yil: ");
    scanf("%d", &dt->yil);
    printf("Ay: ");
    scanf("%d", &dt->ay);
    printf("Gun: ");
    scanf("%d", &dt->gun);
    printf("Saat: ");
    scanf("%d", &dt->saat);
    printf("Dakika: ");
    scanf("%d", &dt->dakika);
    printf("Saniye: ");
    scanf("%d", &dt->saniye);
}

// Tarih bilgisini epoch zaman�na �eviren fonksiyon
time_t tariheDonustur(struct DateTime dt) {
    struct tm t = {0};
    t.tm_year = dt.yil - 1900;  // Y�l 1900'den ba�lar
    t.tm_mon = dt.ay - 1;       // Aylar 0'dan ba�lar
    t.tm_mday = dt.gun;
    t.tm_hour = dt.saat;
    t.tm_min = dt.dakika;
    t.tm_sec = dt.saniye;

    return mktime(&t);
}

int main() {
    union TimeData bayram1, bayram2;
    double fark;

    // Kullan�c�dan ilk bayram tarihi
    printf("Birinci bayramin tarihini giriniz:\n");
    tarihBilgisiAl(&bayram1.dt);

    // Kullan�c�dan ikinci bayram tarihi
    printf("\nIkinci bayramin tarihini giriniz:\n");
    tarihBilgisiAl(&bayram2.dt);

    // Bayram tarihlerini epoch zaman�na �evir
    bayram1.epoch = tariheDonustur(bayram1.dt);
    bayram2.epoch = tariheDonustur(bayram2.dt);

    // Zaman fark�n� hesapla
    fark = difftime(bayram2.epoch, bayram1.epoch);

    // Sonu�lar� ekrana yazd�r
    printf("\nBirinci Bayram Epoch Zamani: %ld\n", bayram1.epoch);
    printf("Ikinci Bayram Epoch Zamani: %ld\n", bayram2.epoch);
    printf("Iki bayram arasindaki fark: %.0f saniye\n", fark);
    printf("Iki bayram arasindaki fark: %.0f gun\n", fark / (60 * 60 * 24));

    return 0;
}

