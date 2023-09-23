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
    printf("��renci No: %d\n", ogrenci.numara);
    printf("Ad: %s\n", ogrenci.ad);
    printf("Soyad: %s\n", ogrenci.soyad);
    printf("Not Ortalamas�: %.2f\n", ogrenci.notOrtalamasi);
}

int main() 
{
    struct Ogrenci ogrenciler[100];
    int ogrenciSayisi = 0;
    int secim;

    printf("��renci Kay�t Sistemi\n");

    do 
	{
        printf("\n1. Yeni ��renci Ekle\n");
        printf("2. ��renci Bilgilerini G�r�nt�le\n");
        printf("3. ��renci Bilgilerini G�ncelle\n");
        printf("4. ��renci Sil\n");
        printf("5. ��k��\n");
        printf("Se�iminizi yap�n: ");
        scanf("%d", &secim);

        switch (secim) 
		{
            case 1:
                if (ogrenciSayisi < 100) 
				{
                    printf("��renci No: ");
                    scanf("%d", &ogrenciler[ogrenciSayisi].numara);
                    printf("Ad: ");
                    scanf("%s", ogrenciler[ogrenciSayisi].ad);
                    printf("Soyad: ");
                    scanf("%s", ogrenciler[ogrenciSayisi].soyad);
                    printf("Not Ortalamas�: ");
                    scanf("%f", &ogrenciler[ogrenciSayisi].notOrtalamasi);
                    ogrenciSayisi++;
                    printf("��renci ba�ar�yla eklendi.\n");
                } 
				else 
				{
                    printf("��renci s�n�r�na ula��ld�. Daha fazla ��renci eklenemez.\n");
                }
                break;
            case 2:
                if (ogrenciSayisi > 0)
				 {
                    printf("��renci No: ");
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
                        printf("��renci bulunamad�.\n");
                    }
                } 
				else 
				{
                    printf("Hen�z ��renci kayd� yok.\n");
                }
                break;
            case 3:
                
                break;
            case 4:
                
                break;
            case 5:
                printf("��k�� yap�l�yor...\n");
                break;
            default:
                printf("Ge�ersiz se�im. Tekrar deneyin.\n");
        }
    } while (secim != 5);

    return 0;
}


