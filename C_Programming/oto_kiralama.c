#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Araba 
{
    int arabaID;
    char marka[50];
    char model[50];
    int yil;
    int ucret;
    int kiralandi;
};

struct Araba arabalar[100];
int arabaSayisi = 0;

void arabalariListele() 
{
    printf("Arabalar:\n");
    int i = 0;
    while (i < arabaSayisi) 
	{
        printf("ID: %d\n", arabalar[i].arabaID);
        printf("Marka: %s\n", arabalar[i].marka);
        printf("Model: %s\n", arabalar[i].model);
        printf("Yýl: %d\n", arabalar[i].yil);
        printf("Kiralýk: %s\n", arabalar[i].kiralandi ? "Hayýr" : "Evet");
        printf("Ücret: %d TL/gün\n", arabalar[i].ucret);
        printf("----------------------------\n");
        i++;
    }
}

int main() 
{
    
    struct Araba araba1 = {1, "BMW", "X5", 2022, 500, 0};
    struct Araba araba2 = {2, "Toyota", "Camry", 2023, 300, 0};
    struct Araba araba3 = {3, "Nissan", "Altima", 2022, 350, 0};

    arabalar[arabaSayisi++] = araba1;
    arabalar[arabaSayisi++] = araba2;
    arabalar[arabaSayisi++] = araba3;

    int secim;

    do 
	{
        printf("\nOto Kiralama Sistemi\n");
        printf("1. Arabalarý Listele\n");
        printf("2. Araba Kirala\n");
        printf("3. Çýkýþ\n");
        printf("Seçiminizi yapýn: ");
        scanf("%d", &secim);

        switch (secim) 
		{
            case 1:
                arabalariListele();
                break;
            case 2: 
			{
                int arabaID;
                printf("Kiralayacak arabayý seçin (ID): ");
                scanf("%d", &arabaID);

                int bulundu = 0;
                int i = 0;
                do 
				{
                    if (arabalar[i].arabaID == arabaID) 
					{
                        if (arabalar[i].kiralandi) 
						{
                            printf("Bu araba zaten kiralandý.\n");
                        } 
						else 
						{
                            printf("Araba kiralama baþarýlý. Ýyi yolculuklar!\n");
                            arabalar[i].kiralandi = 1;
                        }
                        bulundu = 1;
                        break;
                    }
                    i++;
                } 
				while (i < arabaSayisi);

                if (!bulundu) 
				{
                    printf("Araba bulunamadý veya zaten kiralanmýþ.\n");
                }

                break;
            }
            case 3:
                printf("Çýkýþ yapýlýyor...\n");
                break;
            default:
                printf("Geçersiz seçim. Tekrar deneyin.\n");
        }
    } while (secim != 3);

    return 0;
}

