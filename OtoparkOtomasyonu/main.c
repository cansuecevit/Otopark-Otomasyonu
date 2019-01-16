#include <stdio.h>
#include <stdlib.h>
int aas=0;//aas:otoparkta bulunan araç sayýsý.
int araclar[10][6];//otoparktaki araçları gösteren matris.
int arac[5],aracplakasi;
void tipekleme(); void plakaekleme(); void saatekleme(); void aracgiris();
void araclistele(); int ucrethesapla(int aracplakasi); int maksUcretBul(); int minUcretBul();
int main()
{
    int secim;
    printf("\nYapmak istediginiz islemi secin:\n");
    printf("1:Arac ekleme\n");
    printf("2:Arac listele\n");
    printf("3:Ucret hesaplama\n");
    printf("4:Maksimum ve minumum ucret\n");
    printf("\t");
    scanf("%d",&secim);
    if(secim==1)
    {
        if(aas>=10)
            printf("10 arac girilmis.Baska arac giremezsiniz!\n");
            else{
        tipekleme();
        plakaekleme();
        saatekleme();
        aracgiris();}
    }
    if(secim==2)
    {
      araclistele();
    }
    if(secim==3)
    {
      printf("Ucretinin hesaplanmasini istediginiz aracin plakasini girin: ");
      scanf("%d",&aracplakasi);
      while(aracplakasi<1||aracplakasi>81)
                {
            printf("Yanlis plaka degeri!\n");
            printf("Aracin plakasini girin:");
            scanf("%d",&aracplakasi);
                }
      printf("Odenecek tutar: %d ",ucrethesapla(aracplakasi));
    }
    if(secim==4)
    {
       printf("Maksimum ucret: %d ",maksUcretBul());
       printf("\nMinumum ucret: %d",minUcretBul());
    }
    if(secim<1||secim>4)
        printf("Yanlis deger girdiniz.1 ile 4 arasinda secim yapiniz!\n");
 main();
    return 0;
}
void tipekleme()
{
    printf("Ekleyeceginiz aracin tipini belirleyin: 1-2-3\n");
        scanf("%d",&arac[0]);
        while(arac[0]<1||arac[0]>3)
            {
            printf("Yanlis deger girdiniz.Lutfen 1-2-3 degerlerinden birini girin!\n");
            printf("Ekleyeceginiz aracin tipini belirleyin: 1-2-3\n");
            scanf("%d",&arac[0]);
            }
}
void plakaekleme()
{
    printf("\nAracin plakasini girin: ");
    scanf("%d",&arac[1]);
        while(arac[1]<1||arac[1]>81)
            {
            printf("Yanlis plaka degeri!\n");
            printf("Aracin plakasini girin:");
            scanf("%d",&arac[1]);
            }
}
void saatekleme()
{
    printf("\nAracin giris saati(Sadece saat girin):");
    scanf("%d",&arac[2]);
       while(arac[2]>24||arac[2]<0)
          {
           printf("\nLutfen 1-24 araliginda bir saat girin!\n");
           printf("\nAracin giris saati(Sadece saat girin):");
           scanf("%d",&arac[2]);
          }
    printf("\nAracin cikis saati(Sadece saat girin):");
    scanf("%d",&arac[3]);
        while(arac[3]>24||arac[3]<0)
            {
            printf("\nLutfen 1-24 araliginda bir saat girin!");
            printf("\nAracin cikis saati(Sadece saat girin):");
            scanf("%d",&arac[3]);
            }
        while(arac[3]<arac[2])
            {
            printf("\nCikis saati giris saatinden once olamaz!Tekrar deneyin.\n");
            printf("\nAracin giris saati(Sadece saat girin):");
            scanf("%d",&arac[2]);
            printf("\nAracin cikis saati(Sadece saat girin):");
            scanf("%d",&arac[3]);
            }
}
void aracgiris()
{
    araclar[aas][0]=aas;
    araclar[aas][1]=arac[0];
    araclar[aas][2]=arac[1];
    araclar[aas][3]=arac[2];
    araclar[aas][4]=arac[3];
    aas++;
}
void araclistele()
{
    int i;
    for(i=0;i<aas;i++)
    {
    printf("%d tipi-%d plakali arac :\n",araclar[i][1],araclar[i][2]);
    printf("Giris saati: %d , Cikis saati: %d",araclar[i][3],araclar[i][4]);
    printf("\n");
    }
}
int ucrethesapla(int aracplakasi)
{
    int i;
    for(i=0;i<aas;i++)
    {
        if(araclar[i][1]==1)
        araclar[i][5]=5+((araclar[i][4]-araclar[i][3])*1);
        else if(araclar[i][1]==2)
        araclar[i][5]=5+((araclar[i][4]-araclar[i][3])*2);
        else if(araclar[i][1]==3)
        araclar[i][5]=5+((araclar[i][4]-araclar[i][3])*3);
        if(araclar[i][2]==aracplakasi)
        {
          arac[4]=araclar[i][5];
        }
    } return arac[4];

}
int maksUcretBul()
{
    int i,maksUcret=araclar[0][5];
    for(i=0;i<aas;i++)
    {
        if(araclar[i][5]>maksUcret)
            maksUcret= araclar[i][5];
    }
    return maksUcret;
}
int minUcretBul()
{
    int i,minUcret=araclar[0][5];
    for(i=0;i<aas;i++)
    {
        if(araclar[i][5]<minUcret)
        {
            minUcret=araclar[i][5];
        }
    }
    return minUcret;
}
