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
        printf("Y�l: %d\n", arabalar[i].yil);
        printf("Kiral�k: %s\n", arabalar[i].kiralandi ? "Hay�r" : "Evet");
        printf("�cret: %d TL/g�n\n", arabalar[i].ucret);
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
        printf("1. Arabalar� Listele\n");
        printf("2. Araba Kirala\n");
        printf("3. ��k��\n");
        printf("Se�iminizi yap�n: ");
        scanf("%d", &secim);

        switch (secim) 
		{
            case 1:
                arabalariListele();
                break;
            case 2: 
			{
                int arabaID;
                printf("Kiralayacak arabay� se�in (ID): ");
                scanf("%d", &arabaID);

                int bulundu = 0;
                int i = 0;
                do 
				{
                    if (arabalar[i].arabaID == arabaID) 
					{
                        if (arabalar[i].kiralandi) 
						{
                            printf("Bu araba zaten kiraland�.\n");
                        } 
						else 
						{
                            printf("Araba kiralama ba�ar�l�. �yi yolculuklar!\n");
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
                    printf("Araba bulunamad� veya zaten kiralanm��.\n");
                }

                break;
            }
            case 3:
                printf("��k�� yap�l�yor...\n");
                break;
            default:
                printf("Ge�ersiz se�im. Tekrar deneyin.\n");
        }
    } while (secim != 3);

    return 0;
}

