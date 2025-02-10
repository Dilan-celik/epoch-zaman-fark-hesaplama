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
    int yil_farki, ay_farki, gun_farki, saat_farki, dakika_farki, saniye_farki, salise_farki;

    // Kullanıcıdan birinci tarih ve saat bilgisi al
    printf("Birinci tarih ve saat bilgilerini giriniz:\n");
    tarihAl(&tarih1);
    zamanAl(&zaman1);

    // Kullanıcıdan ikinci tarih ve saat bilgisi al
    printf("\nIkinci tarih ve saat bilgilerini giriniz:\n");
    tarihAl(&tarih2);
    zamanAl(&zaman2);

    // Epoch zamanini hesapla
    epoch1 = epochHesapla(tarih1, zaman1);
    epoch2 = epochHesapla(tarih2, zaman2);

    // Zaman farkini hesapla
    fark = difftime(epoch2, epoch1);

    // Gün, saat, dakika, saniye ve salise farklarını hesapla
    gun_farki = fark / (60 * 60 * 24);
    saat_farki = ((int)fark % (60 * 60 * 24)) / (60 * 60);
    dakika_farki = ((int)fark % (60 * 60)) / 60;
    saniye_farki = (int)fark % 60;
    salise_farki = ((epoch2 - epoch1) * 1000) % 1000; // Milisaniye farkı için

    // Yıl ve ay farkını hesapla
    yil_farki = tarih2.yil - tarih1.yil;
    ay_farki = (tarih2.ay + yil_farki * 12) - tarih1.ay;

    // Sonuçları ekrana yazdır
    printf("\nBirinci Tarihin Epoch Zamani: %ld\n", epoch1);
    printf("Ikinci Tarihin Epoch Zamani: %ld\n", epoch2);
    printf("Iki tarih arasindaki fark:\n");
    printf("%d yil, %d ay, %d gun, %d saat, %d dakika, %d saniye, %d salise\n",
           yil_farki, ay_farki, gun_farki, saat_farki, dakika_farki, saniye_farki, salise_farki);

    return 0;
}
