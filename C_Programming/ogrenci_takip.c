#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Ogrenci 
{
    int numara;
    char ad[50];
    char soyad[50];
    float notOrtalamasi;
};


void ogrenciGoruntule(struct Ogrenci ogrenci) 
{
    printf("Öðrenci No: %d\n", ogrenci.numara);
    printf("Ad: %s\n", ogrenci.ad);
    printf("Soyad: %s\n", ogrenci.soyad);
    printf("Not Ortalamasý: %.2f\n", ogrenci.notOrtalamasi);
}

int main() 
{
    struct Ogrenci ogrenciler[100];
    int ogrenciSayisi = 0;
    int secim;

    printf("Öðrenci Kayýt Sistemi\n");

    do 
	{
        printf("\n1. Yeni Öðrenci Ekle\n");
        printf("2. Öðrenci Bilgilerini Görüntüle\n");
        printf("3. Öðrenci Bilgilerini Güncelle\n");
        printf("4. Öðrenci Sil\n");
        printf("5. Çýkýþ\n");
        printf("Seçiminizi yapýn: ");
        scanf("%d", &secim);

        switch (secim) 
		{
            case 1:
                if (ogrenciSayisi < 100) 
				{
                    printf("Öðrenci No: ");
                    scanf("%d", &ogrenciler[ogrenciSayisi].numara);
                    printf("Ad: ");
                    scanf("%s", ogrenciler[ogrenciSayisi].ad);
                    printf("Soyad: ");
                    scanf("%s", ogrenciler[ogrenciSayisi].soyad);
                    printf("Not Ortalamasý: ");
                    scanf("%f", &ogrenciler[ogrenciSayisi].notOrtalamasi);
                    ogrenciSayisi++;
                    printf("Öðrenci baþarýyla eklendi.\n");
                } 
				else 
				{
                    printf("Öðrenci sýnýrýna ulaþýldý. Daha fazla öðrenci eklenemez.\n");
                }
                break;
            case 2:
                if (ogrenciSayisi > 0)
				 {
                    printf("Öðrenci No: ");
                    int ogrenciNo;
                    scanf("%d", &ogrenciNo);
                    int bulundu = 0;
                    int i;
                    for (i = 0; i < ogrenciSayisi; i++)
					 {
                        if (ogrenciler[i].numara == ogrenciNo) 
						{
                            ogrenciGoruntule(ogrenciler[i]);
                            bulundu = 1;
                            break;
                        }
                    }
                    if (!bulundu)
					 {
                        printf("Öðrenci bulunamadý.\n");
                    }
                } 
				else 
				{
                    printf("Henüz öðrenci kaydý yok.\n");
                }
                break;
            case 3:
                
                break;
            case 4:
                
                break;
            case 5:
                printf("Çýkýþ yapýlýyor...\n");
                break;
            default:
                printf("Geçersiz seçim. Tekrar deneyin.\n");
        }
    } while (secim != 5);

    return 0;
}


