# epoch-zaman-fark-hesaplama

Bu proje, kullanıcıdan alınan iki farklı tarih ve zaman bilgisinin farkını hesaplayan bir C programıdır. Program, girilen tarihleri ve saatleri Epoch (Unix) zamanına çevirir ve bu zamanlar arasındaki farkı yıl, ay, gün, saat, dakika, saniye ve salise olarak hesaplar.

Programı çalıştırdığınızda, önce birinci tarih ve saat bilgisini giriyorsunuz. Ardından ikinci bir tarih ve saat bilgisi giriyorsunuz. Program bu bilgileri alıp, Epoch zamanına dönüştürüyor ve ardından iki tarih arasındaki farkı hesaplıyor. Fark, gün, saat, dakika, saniye ve salise olarak hesaplanıp ekrana yazdırılıyor.
Programın kullanımı şu şekilde: İlk olarak, yıl, ay, gün, saat, dakika, saniye ve salise bilgilerini giriyorsunuz. Örneğin, 10 Mayıs 2023, saat 14:30:15.500 ve 15 Haziran 2025, saat 18:45:10.250 gibi iki farklı tarih giriyorsanız, program bu iki tarih arasındaki farkı hesaplayarak "2 yıl, 13 ay, 767 gün, 4 saat, 14 dakika, 55 saniye, 750 salise" gibi bir sonuç veriyor.

Hesaplama yaparken, program yıl farkını doğrudan, ay farkını ise yıl farkı ile birlikte hesaplıyor. Gün, saat, dakika ve saniye farkı da Epoch zamanından elde edilen verilere dayanarak bulunuyor. Salise farkı ise milisaniye olarak hesaplanıyor.
