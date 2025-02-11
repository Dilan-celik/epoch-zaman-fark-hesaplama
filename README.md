# epoch-zaman-fark-hesaplama
Tarih ve Zaman Farkı Hesaplama Programı

Bu program, kullanıcıdan iki farklı tarih ve zaman bilgisi alarak, aralarındaki farkı yıl, ay, gün, saat, dakika, saniye ve salise cinsinden hesaplar.

Kullanılan Veri Yapıları

Program, tarih ve zaman bilgisini saklamak için iki farklı yapı kullanır. Bunlar, yıl, ay ve günü içeren Tarih yapısı ile saat, dakika, saniye ve salise bilgisini içeren Zaman yapısıdır.

Çalışma Mantığı

Kullanıcıdan birinci ve ikinci tarih ile saat bilgisi alınır.

Girilen tarih ve zaman bilgileri, Unix zamanına dönüştürülür.

İki zaman damgası arasındaki fark hesaplanır.

Bu fark yıl, ay, gün, saat, dakika, saniye ve salise cinsinden ekrana yazdırılır.

Programın Kullanımı

Programı çalıştırmak için öncelikle bir C derleyicisi kullanarak kodu derleyin ve ardından çalıştırın. Kullanıcıdan istenen bilgileri girdikten sonra, iki tarih arasındaki fark detaylı şekilde görüntülenecektir.

Örnek Girdi ve Çıktı

Kullanıcıdan alınan örnek tarih ve saat bilgileri:

Birinci tarih: 10 Şubat 2023, saat 14:30:45.500

İkinci tarih: 15 Mayıs 2024, saat 18:15:30.250

Bu bilgiler ışığında, program aşağıdaki farkı hesaplar:

1 yıl, 15 ay, 95 gün, 3 saat, 44 dakika, 45 saniye, 750 salise

Notlar

Program hatalı giriş bilgilerini hesaplayamaz

Epoch zaman dönüşümü için mktime fonksiyonu kullanılmış olup, salise farkı ayrıca hesaplanmaktadır.
