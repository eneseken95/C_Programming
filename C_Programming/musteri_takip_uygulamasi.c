#include <stdio.h>
#include <string.h>


struct Musteri 
{
    char isim[50];
    char soyisim[50];
    int yas;
    char telefon[15];
};


void musteriGoruntule(struct Musteri musteri) 
{
    printf("Ýsim: %s\n", musteri.isim);
    printf("Soyisim: %s\n", musteri.soyisim);
    printf("Yaþ: %d\n", musteri.yas);
    printf("Telefon: %s\n", musteri.telefon);
}

int main() 
{
    struct Musteri musteriler[100];
    int musteriSayisi = 0;
    int secim;

    printf("Müþteri Takip Uygulamasýna Hoþ Geldiniz!\n");

    do 
	{
        printf("\n1. Yeni Müþteri Ekle\n");
        printf("2. Müþteri Bilgilerini Görüntüle\n");
        printf("3. Cýkýs\n");
        printf("Seçiminizi yapýn: ");
        scanf("%d", &secim);

        switch (secim) 
		{
            case 1:
                if (musteriSayisi < 100) 
				{
                    printf("Müþterinin Ýsmini Girin: ");
                    scanf("%s", musteriler[musteriSayisi].isim);
                    printf("Müþterinin Soyismini Girin: ");
                    scanf("%s", musteriler[musteriSayisi].soyisim);
                    printf("Müþterinin Yaþýný Girin: ");
                    scanf("%d", &musteriler[musteriSayisi].yas);
                    printf("Müþterinin Telefon Numarasýný Girin: ");
                    scanf("%s", musteriler[musteriSayisi].telefon);
                    musteriSayisi++;
                    printf("Müþteri baþarýyla eklendi.\n");
                } else {
                    printf("Müþteri sýnýrýna ulaþýldý. Daha fazla müþteri eklenemez.\n");
                }
                break;
            case 2:
                if (musteriSayisi > 0)
				 {
                    printf("Müþteri Numarasýný Girin (1-%d): ", musteriSayisi);
                    int numara;
                    scanf("%d", &numara);
                    if (numara >= 1 && numara <= musteriSayisi) 
					{
                        musteriGoruntule(musteriler[numara - 1]);
                    } else {
                        printf("Geçersiz müþteri numarasý.\n");
                    }
                } 
				else 
				{
                    printf("Henüz müþteri kaydý yok.\n");
                }
                break;
            case 3:
                printf("Çýkýþ yapýlýyor...\n");
                break;
            default:
                printf("Geçersiz seçim. Tekrar deneyin.\n");
        }
    } while (secim != 3);

    return 0;
}

