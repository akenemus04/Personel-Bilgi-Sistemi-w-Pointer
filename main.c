
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char isim[50];
    int yas;
    int maas;
} Personel;

int main()
{
    FILE *fp, *fp2;
    int secim,i=0;
    char secim2,aranan[30];
    Personel personel2 ;
    Personel personel;

    fp=fopen("per.dat","wb+");
    printf("\t\t\t*****PERSONEL BILGI SISTEMI*****\n");
    while(1==1)
    {

        printf("\n\t1-KAYIT EKLE\n");
        printf("\t2-LISTELE\n");
        printf("\t3-DUZENLE\n");
        printf("\t4-SIL\n");
        printf("\t5-CIKIS\n");
        printf("\tSecimini Yap <1-5> :");
        scanf("%d",&secim);

        if(1>secim || secim>5)
        {
            printf("Yanlis bir secim yaptiniz ! \n");
        }

        switch(secim)
        {
        case 1 :

            do
            {
                printf("\n Isim :");
                scanf("%s",personel.isim);
                printf("\n Yas :");
                scanf("%d",&personel.yas);
                printf("\n Maas :");
                scanf("%d",&personel.maas);
                printf("\n Yeni kayit yapmak ister misiniz? Hayir->n  Evet->y  :");
                scanf("%s",&secim2);

                fwrite(&personel,sizeof(personel),1,fp);
            }
            while(secim2=='y' || secim2=='Y');

            break;

        case 2 :

            rewind(fp);
            while(fread(&personel2,sizeof(personel2),1,fp)!=0)
            {
                    printf(" %s\n %d\n %d\n",personel2.isim,personel2.yas,personel2.maas);
            }

            break;
        case 3 :
            rewind(fp);
            printf("\n Duzenlemek istediginiz kayit ismi:");
            scanf("%s",aranan);

            while(fread(&personel2,sizeof(personel2),1,fp)==1)
            {
                    if (strcmp(aranan,personel2.isim) == 0)
                    {
                        fseek(fp, 0 - sizeof(personel2),SEEK_CUR);
                        printf("\n Yeni ad,yas ve maas bilgilerini giriniz :");
                        scanf("%s %d %d",personel2.isim,&personel2.yas,&personel2.maas);
                        fwrite(&personel2,sizeof(personel2),1,fp);
                        break;
                    }
            }
            break;
            case 4:
                {
                    do{
                    fclose(fp);
                    fp=fopen("per.dat","rb+");
                    fp2=fopen("per2.dat","wb+");

                    printf("\n Kaydi silinecek personelin adini giriniz: ");
                    scanf("%s",personel.isim);

                    int kontrol=0;

                    while(fread(&personel2,sizeof(personel2),1,fp) == 1)
                    {
                        if(strcmp(personel2.isim,personel.isim) == 0)
                            kontrol++;

                        else
                            fwrite(&personel2,sizeof(personel2),1,fp2);
                    }
                fclose(fp);
                fclose(fp2);
                remove("per.dat");
                rename("per2.dat","per.dat");

                if ( kontrol != 0)
                {
                    printf("\n Kayit basariyla silindi !\n");
                    printf("\n Baska kayit silmek istiyor musunuz? Evet->y  Hayir->n : ");
                    scanf("%s",&secim2);
                }
                else
                {
                    printf("\n Aranan kayit bulunamadi !\n");
                    break;
                }
                fp=fopen("per.dat","rb+");

                }while(secim2 == 'y'|| secim2 == 'Y');
                } break;
            case 5:
                exit(0);

        }
    }
    return 0;

}

