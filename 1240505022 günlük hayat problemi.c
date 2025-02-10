#include <stdio.h>
#include <time.h>

// Tarih ve saat bilgisi için struct
struct DateTime {
    int yil, ay, gun, saat, dakika, saniye;
};

// Struct ve epoch zamanýný ayný bellek alanýnda saklamak için union
union TimeData {
    struct DateTime dt;
    time_t epoch;
};

// Kullanýcýdan tarih ve saat bilgisi alma fonksiyonu
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

// Tarih bilgisini epoch zamanýna çeviren fonksiyon
time_t tariheDonustur(struct DateTime dt) {
    struct tm t = {0};
    t.tm_year = dt.yil - 1900;  // Yýl 1900'den baþlar
    t.tm_mon = dt.ay - 1;       // Aylar 0'dan baþlar
    t.tm_mday = dt.gun;
    t.tm_hour = dt.saat;
    t.tm_min = dt.dakika;
    t.tm_sec = dt.saniye;

    return mktime(&t);
}

int main() {
    union TimeData bayram1, bayram2;
    double fark;

    // Kullanýcýdan ilk bayram tarihi
    printf("Birinci bayramin tarihini giriniz:\n");
    tarihBilgisiAl(&bayram1.dt);

    // Kullanýcýdan ikinci bayram tarihi
    printf("\nIkinci bayramin tarihini giriniz:\n");
    tarihBilgisiAl(&bayram2.dt);

    // Bayram tarihlerini epoch zamanýna çevir
    bayram1.epoch = tariheDonustur(bayram1.dt);
    bayram2.epoch = tariheDonustur(bayram2.dt);

    // Zaman farkýný hesapla
    fark = difftime(bayram2.epoch, bayram1.epoch);

    // Sonuçlarý ekrana yazdýr
    printf("\nBirinci Bayram Epoch Zamani: %ld\n", bayram1.epoch);
    printf("Ikinci Bayram Epoch Zamani: %ld\n", bayram2.epoch);
    printf("Iki bayram arasindaki fark: %.0f saniye\n", fark);
    printf("Iki bayram arasindaki fark: %.0f gun\n", fark / (60 * 60 * 24));

    return 0;
}

