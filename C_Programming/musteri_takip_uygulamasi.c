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
    printf("�sim: %s\n", musteri.isim);
    printf("Soyisim: %s\n", musteri.soyisim);
    printf("Ya�: %d\n", musteri.yas);
    printf("Telefon: %s\n", musteri.telefon);
}

int main() 
{
    struct Musteri musteriler[100];
    int musteriSayisi = 0;
    int secim;

    printf("M��teri Takip Uygulamas�na Ho� Geldiniz!\n");

    do 
	{
        printf("\n1. Yeni M��teri Ekle\n");
        printf("2. M��teri Bilgilerini G�r�nt�le\n");
        printf("3. C�k�s\n");
        printf("Se�iminizi yap�n: ");
        scanf("%d", &secim);

        switch (secim) 
		{
            case 1:
                if (musteriSayisi < 100) 
				{
                    printf("M��terinin �smini Girin: ");
                    scanf("%s", musteriler[musteriSayisi].isim);
                    printf("M��terinin Soyismini Girin: ");
                    scanf("%s", musteriler[musteriSayisi].soyisim);
                    printf("M��terinin Ya��n� Girin: ");
                    scanf("%d", &musteriler[musteriSayisi].yas);
                    printf("M��terinin Telefon Numaras�n� Girin: ");
                    scanf("%s", musteriler[musteriSayisi].telefon);
                    musteriSayisi++;
                    printf("M��teri ba�ar�yla eklendi.\n");
                } else {
                    printf("M��teri s�n�r�na ula��ld�. Daha fazla m��teri eklenemez.\n");
                }
                break;
            case 2:
                if (musteriSayisi > 0)
				 {
                    printf("M��teri Numaras�n� Girin (1-%d): ", musteriSayisi);
                    int numara;
                    scanf("%d", &numara);
                    if (numara >= 1 && numara <= musteriSayisi) 
					{
                        musteriGoruntule(musteriler[numara - 1]);
                    } else {
                        printf("Ge�ersiz m��teri numaras�.\n");
                    }
                } 
				else 
				{
                    printf("Hen�z m��teri kayd� yok.\n");
                }
                break;
            case 3:
                printf("��k�� yap�l�yor...\n");
                break;
            default:
                printf("Ge�ersiz se�im. Tekrar deneyin.\n");
        }
    } while (secim != 3);

    return 0;
}

