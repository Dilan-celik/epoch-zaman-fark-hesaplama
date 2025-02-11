#include <stdio.h>
#include <time.h>

// Tarih bilgisi için struct
struct Tarih {
    int yil, ay, gun;
};

// Zaman bilgisi için struct
struct Zaman {
    int saat, dakika, saniye, salise;
};

// Epoch ve zaman farkı için union
union EpochZaman {
    time_t epoch;
    double fark;
};

// Kullanıcıdan tarih bilgisi alma fonksiyonu
void tarihAl(struct Tarih *tarih) {
    printf("Yil: ");
    scanf("%d", &tarih->yil);
    printf("Ay: ");
    scanf("%d", &tarih->ay);
    printf("Gun: ");
    scanf("%d", &tarih->gun);
}

// Kullanıcıdan zaman bilgisi alma fonksiyonu
void zamanAl(struct Zaman *zaman) {
    printf("Saat: ");
    scanf("%d", &zaman->saat);
    printf("Dakika: ");
    scanf("%d", &zaman->dakika);
    printf("Saniye: ");
    scanf("%d", &zaman->saniye);
    printf("Salise: ");
    scanf("%d", &zaman->salise);
}

// Tarih ve zaman bilgisini epoch zamanına çeviren fonksiyon
time_t epochHesapla(struct Tarih tarih, struct Zaman zaman) {
    struct tm t = {0};
    t.tm_year = tarih.yil - 1900;
    t.tm_mon = tarih.ay - 1;
    t.tm_mday = tarih.gun;
    t.tm_hour = zaman.saat;
    t.tm_min = zaman.dakika;
    t.tm_sec = zaman.saniye;
    
    return mktime(&t);
}

int main() {
    struct Tarih tarih1, tarih2;
    struct Zaman zaman1, zaman2;
    union EpochZaman epoch1, epoch2, fark;
    int gun_farki, saat_farki, dakika_farki, saniye_farki;

    // Kullanıcıdan birinci tarih ve saat bilgisi al
    printf("Birinci tarih ve saat bilgilerini giriniz:\n");
    tarihAl(&tarih1);
    zamanAl(&zaman1);

    // Kullanıcıdan ikinci tarih ve saat bilgisi al
    printf("\nIkinci tarih ve saat bilgilerini giriniz:\n");
    tarihAl(&tarih2);
    zamanAl(&zaman2);

    // Epoch zamanlarını hesapla
    epoch1.epoch = epochHesapla(tarih1, zaman1);
    epoch2.epoch = epochHesapla(tarih2, zaman2);

    // Zaman farkını hesapla
    fark.epoch = epoch2.epoch - epoch1.epoch;

    // Gün, saat, dakika ve saniye farklarını hesapla
    gun_farki = fark.epoch / (60 * 60 * 24);
    saat_farki = (fark.epoch % (60 * 60 * 24)) / (60 * 60);
    dakika_farki = (fark.epoch % (60 * 60)) / 60;
    saniye_farki = fark.epoch % 60;

    // Sonuçları ekrana yazdır
    printf("\nBirinci Tarihin Epoch Zamani: %ld\n", epoch1.epoch);
    printf("Ikinci Tarihin Epoch Zamani: %ld\n", epoch2.epoch);
    printf("Iki tarih arasindaki fark:\n");
    printf("%d gun, %d saat, %d dakika, %d saniye\n", gun_farki, saat_farki, dakika_farki, saniye_farki);
    
    return 0;
}
