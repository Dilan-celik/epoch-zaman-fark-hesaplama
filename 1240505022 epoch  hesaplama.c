#include <stdio.h>
#include <time.h>

// Tarih bilgisi icin struct
struct Tarih {
    int yil, ay, gun;
};

// Zaman bilgisi icin struct
struct Zaman {
    int saat, dakika, saniye, salise;
};

// Kullanýcýdan tarih bilgisi alma fonksiyonu
void tarihAl(struct Tarih *tarih) {
    printf("Yil: ");
    scanf("%d", &tarih->yil);
    printf("Ay: ");
    scanf("%d", &tarih->ay);
    printf("Gun: ");
    scanf("%d", &tarih->gun);
}

// Kullanýcýdan zaman bilgisi alma fonksiyonu
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

// Tarih ve zaman bilgisini epoch zamanina ceviren fonksiyon
time_t epochHesapla(struct Tarih tarih, struct Zaman zaman) {
    struct tm t = {0};
    t.tm_year = tarih.yil - 1900;  // Yil 1900'den baslar
    t.tm_mon = tarih.ay - 1;       // Aylar 0'dan baslar
    t.tm_mday = tarih.gun;
    t.tm_hour = zaman.saat;
    t.tm_min = zaman.dakika;
    t.tm_sec = zaman.saniye;

    // Salise hesaplamasini yapmak icin mktime'e ekleme
    time_t epoch = mktime(&t);
    return epoch + zaman.salise / 1000; // Salise milisaniye olarak eklenir
}

int main() {
    struct Tarih tarih1, tarih2;
    struct Zaman zaman1, zaman2;
    time_t epoch1, epoch2;
    double fark;

    // Kullanýcýdan birinci tarih ve saat bilgisi al
    printf("Birinci tarih ve saat bilgilerini giriniz:\n");
    tarihAl(&tarih1);
    zamanAl(&zaman1);

    // Kullanýcýdan ikinci tarih ve saat bilgisi al
    printf("\nIkinci tarih ve saat bilgilerini giriniz:\n");
    tarihAl(&tarih2);
    zamanAl(&zaman2);

    // Epoch zamanini hesapla
    epoch1 = epochHesapla(tarih1, zaman1);
    epoch2 = epochHesapla(tarih2, zaman2);

    // Zaman farkini hesapla
    fark = difftime(epoch2, epoch1);

    // Sonuclari ekrana yazdir
    printf("\nBirinci Tarihin Epoch Zamani: %ld\n", epoch1);
    printf("Ikinci Tarihin Epoch Zamani: %ld\n", epoch2);
    printf("Iki tarih arasindaki fark: %.0f saniye\n", fark);

    return 0;
}

