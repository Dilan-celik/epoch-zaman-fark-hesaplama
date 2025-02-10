#include <stdio.h>
#include <time.h>

// Tarih ve saat bilgisi için struct
struct DateTime {
    int yil, ay, gun, saat, dakika, saniye;
};

// Struct ve epoch zamanını aynı bellek alanında saklamak için union
union TimeData {
    struct DateTime dt;
    time_t epoch;
};

// Kullanıcıdan tarih ve saat bilgisi alma fonksiyonu
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

// Tarih bilgisini epoch zamanına çeviren fonksiyon
time_t tariheDonustur(struct DateTime dt) {
    struct tm t = {0};
    t.tm_year = dt.yil - 1900;  // Yıl 1900'den başlar
    t.tm_mon = dt.ay - 1;       // Aylar 0'dan başlar
    t.tm_mday = dt.gun;
    t.tm_hour = dt.saat;
    t.tm_min = dt.dakika;
    t.tm_sec = dt.saniye;

    return mktime(&t);
}

int main() {
    union TimeData bayram1, bayram2;
    double fark;
    int yil_farki, ay_farki, gun_farki, saat_farki, dakika_farki, saniye_farki;

    // Kullanıcıdan ilk bayram tarihi
    printf("Birinci bayramin tarihini giriniz:\n");
    tarihBilgisiAl(&bayram1.dt);

    // Kullanıcıdan ikinci bayram tarihi
    printf("\nIkinci bayramin tarihini giriniz:\n");
    tarihBilgisiAl(&bayram2.dt);

    // Bayram tarihlerini epoch zamanına çevir
    bayram1.epoch = tariheDonustur(bayram1.dt);
    bayram2.epoch = tariheDonustur(bayram2.dt);

    // Zaman farkını hesapla
    fark = difftime(bayram2.epoch, bayram1.epoch);

    // Gün, saat, dakika ve saniye farklarını hesapla
    gun_farki = fark / (60 * 60 * 24);
    saat_farki = ((int)fark % (60 * 60 * 24)) / (60 * 60);
    dakika_farki = ((int)fark % (60 * 60)) / 60;
    saniye_farki = (int)fark % 60;

    // Yıl ve ay farkını hesapla
    yil_farki = bayram2.dt.yil - bayram1.dt.yil;
    ay_farki = (bayram2.dt.ay + yil_farki * 12) - bayram1.dt.ay;

    // Sonuçları ekrana yazdır
    printf("\nBirinci Bayram Epoch Zamani: %ld\n", bayram1.epoch);
    printf("Ikinci Bayram Epoch Zamani: %ld\n", bayram2.epoch);
    printf("Iki bayram arasindaki fark:\n");
    printf("%d yil, %d ay, %d gun, %d saat, %d dakika, %d saniye\n",
           yil_farki, ay_farki, gun_farki, saat_farki, dakika_farki, saniye_farki);

    return 0;
}
