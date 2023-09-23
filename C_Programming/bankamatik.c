#include <stdio.h>


struct Hesap 
{
    char hesapAdi[50];
    double bakiye;
};


void hesapGoruntule(struct Hesap hesap) 
{
    printf("Hesap Adi: %s\n", hesap.hesapAdi);
    printf("Bakiye: %.2lf TL\n", hesap.bakiye);
}


void paraCek(struct Hesap *hesap, double miktar) 
{
    if (miktar <= hesap->bakiye) 
	{
        hesap->bakiye -= miktar;
        printf("%.2lf TL çekildi.\n", miktar);
    } 
	else 
	{
        printf("Yetersiz bakiye.\n");
    }
}

int main() 
{
    struct Hesap hesap1 = {"Hesap 1", 1000.0};
    
    int secim;
    double miktar;

    printf("Bankamatik Uygulamasýna Hoþ Geldiniz!\n");

    do {
        printf("\n1. Hesap Bilgilerini Goruntule\n");
        printf("2. Para Cek\n");
        printf("3. Cikis\n");
        printf("Seciminizi yapin: ");
        scanf("%d", &secim);

        switch (secim) 
		{
            case 1:
                hesapGoruntule(hesap1);
                break;
            case 2:
                printf("Cekmek istediginiz miktari girin: ");
                scanf("%lf", &miktar);
                paraCek(&hesap1, miktar);
                break;
            case 3:
                printf("Cikiþ yapiliyor...\n");
                break;
            default:
                printf("Gecersiz secim. Tekrar deneyin.\n");
        }
    } 
	while (secim != 3);

    return 0;
}

