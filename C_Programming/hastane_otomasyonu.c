#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct Hasta 
{
    int hastaNo;
    char ad[50];
    char soyad[50];
    int yas;
    char cinsiyet[10];
};


struct Randevu 
{
    int randevuNo;
    int hastaNo;
    char doktor[50];
    char tarih[20];
    char saat[10];
};


struct Hasta hastalar[100];
int hastaSayisi = 0;


struct Randevu randevular[100];
int randevuSayisi = 0;


void hastaGoruntule(struct Hasta hasta) 
{
    printf("Hasta No: %d\n", hasta.hastaNo);
    printf("Ad: %s\n", hasta.ad);
    printf("Soyad: %s\n", hasta.soyad);
    printf("Yaþ: %d\n", hasta.yas);
    printf("Cinsiyet: %s\n", hasta.cinsiyet);
}


void randevuGoruntule(struct Randevu randevu) 
{
    printf("Randevu No: %d\n", randevu.randevuNo);
    printf("Hasta No: %d\n", randevu.hastaNo);
    printf("Doktor: %s\n", randevu.doktor);
    printf("Tarih: %s\n", randevu.tarih);
    printf("Saat: %s\n", randevu.saat);
}

int main() 
{
    int secim;

    printf("Hastane Otomasyonu\n");

    do 
	{
        printf("\n1. Yeni Hasta Ekle\n");
        printf("2. Hasta Bilgilerini Görüntüle\n");
        printf("3. Yeni Randevu Ekle\n");
        printf("4. Randevu Bilgilerini Görüntüle\n");
        printf("5. Çýkýþ\n");
        printf("Seçiminizi yapýn: ");
        scanf("%d", &secim);

        switch (secim) 
		{
            case 1: 
			{
                int no, yas;
                char ad[50], soyad[50], cinsiyet[10];
                printf("Hasta No: ");
                scanf("%d", &no);
                printf("Ad: ");
                scanf("%s", ad);
                printf("Soyad: ");
                scanf("%s", soyad);
                printf("Yaþ: ");
                scanf("%d", &yas);
                printf("Cinsiyet: ");
                scanf("%s", cinsiyet);

                struct Hasta hasta;
                hasta.hastaNo = no;
                strcpy(hasta.ad, ad);
                strcpy(hasta.soyad, soyad);
                hasta.yas = yas;
                strcpy(hasta.cinsiyet, cinsiyet);
                hastalar[hastaSayisi] = hasta;
                hastaSayisi++;
                printf("Hasta baþarýyla eklendi.\n");
                break;
            }
            case 2: 
			{
                int hastaNo;
                printf("Hasta No: ");
                scanf("%d", &hastaNo);
                int bulundu = 0;
                int i = 0; 
                do 
				{
                    if (hastalar[i].hastaNo == hastaNo) 
					{
                        hastaGoruntule(hastalar[i]);
                        bulundu = 1;
                        break;
                    }
                    i++;
                } 
				while (i < hastaSayisi);
                if (!bulundu) 
				{
                    printf("Hasta bulunamadý.\n");
                }
                break;
            }
            case 3: 
			{
                int no, hNo;
                char doktor[50], tarih[20], saat[10];
                printf("Randevu No: ");
                scanf("%d", &no);
                printf("Hasta No: ");
                scanf("%d", &hNo);
                printf("Doktor: ");
                scanf("%s", doktor);
                printf("Tarih: ");
                scanf("%s", tarih);
                printf("Saat: ");
                scanf("%s", saat);

                struct Randevu randevu;
                randevu.randevuNo = no;
                randevu.hastaNo = hNo;
                strcpy(randevu.doktor, doktor);
                strcpy(randevu.tarih, tarih);
                strcpy(randevu.saat, saat);

                randevular[randevuSayisi] = randevu;
                randevuSayisi++;
                printf("Randevu baþarýyla eklendi.\n");
                break;
            }
            case 4: 
			{
                int randevuNo;
                printf("Randevu No: ");
                scanf("%d", &randevuNo);
                int bulundu = 0;
                int i = 0; 
                do {
                    if (randevular[i].randevuNo == randevuNo) 
					{
                        randevuGoruntule(randevular[i]);
                        bulundu = 1;
                        break;
                    }
                    i++;
                }
				 while (i < randevuSayisi);
                if (!bulundu) 
				{
                    printf("Randevu bulunamadý.\n");
                }
                break;
            }
            case 5:
                printf("Çýkýþ yapýlýyor...\n");
                break;
            default:
                printf("Geçersiz seçim. Tekrar deneyin.\n");
        }
    } while (secim != 5);

    return 0;
}

