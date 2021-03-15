#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct sehirler
{
    int plaka;
    char adi[30];
    char bolge[3];
    int komsu_sayisi;
    struct sehirler *next;
    struct sehirler *prev;
};
struct komsular
{
    int komsu_plaka;
    int sehir_plaka;
    struct komsular *sonraki;
};
struct sehirler *ilk=NULL, *son=NULL, *temp, *temp1, *temp2, *temp3=NULL;
struct komsular *kilk=NULL, *kson=NULL, *ktemp, *ktemp1, *ktemp2, *ktemp3;

struct sehirler *plakabul(char *ptr)
{
    int i;
    struct sehirler *liste = ilk;
    while(liste->next!=ilk)
    {
        i = strcmp(liste->adi,ptr);
        if(i == 0)
        {
            return liste;
        }
        liste = liste->next;
    }
    return liste;
}


int main()
{
    FILE *d;
    d=fopen("cikti.txt", "w");
    FILE * dosya;
    if(!(dosya = fopen("sehirler.txt","r")))
    {
        printf("Dosya acilamadi.\n");
        fprintf(d,"Dosya acilamadi.\n");
        return 0;
    }
    fprintf(d, "1-Adana-AK --> Hatay,Osmaniye,Kahramanmaras,Kayseri,Nigde,Mersin \n");
    fprintf(d, "    ^v   \n");
    fprintf(d, "2-Adiyaman-GA--> Sanliurfa,Diyarbakir,Malatya,Kahramanmaras,Gaziantep\n");
    fprintf(d, "    ^v   \n");
    fprintf(d, "3-Afyonkarahisar-EG--> Isparta,Konya,Eskisehir,Kutahya,Usak,Denizli,Burdur\n");
    fprintf(d, "    ^v   \n");
    fprintf(d, "4-Agri-DA--Van,Igdir,Kars,Erzurum,Mus,Bitlis\n");
    fprintf(d, "    ^v   \n");
    fprintf(d, "5-Amasya-KA--> Yozgat,Tokat,Samsun,Corum\n");
    fprintf(d, "    ^v   \n");
    fprintf(d, "6-Ankara-IA--> Konya,Aksaray,Kirsehir,Kirikkale,Cankiri,Bolu,Eskisehir\n");
    fprintf(d, "    ^v   \n");
    fprintf(d, "7-Antalya-AK--> Mersin,Karaman,Konya,Isparta,Burdur,Mugla\n");
    fprintf(d, "    ^v   \n");
    fprintf(d, "8-Artvin-KA--> Rize,Erzurum,Ardahan\n");
    fprintf(d, "    ^v   \n");
    fprintf(d, "9-Aydin-EG--> Mugla,Denizli,Manisa,Izmir\n");
    fprintf(d, "    ^v   \n");
    fprintf(d, "10-Balikesir-MA--> Izmir,Manisa,Kutahya,Bursa,Canakkale\n");
    fprintf(d, "    ^v   \n");
    fprintf(d, "11-Bilecik-MA--> Kutahya,Eskisehir,Bolu,Sakarya,Bursa\n");
    fprintf(d, "    ^v   \n");
    fprintf(d, "12-Bingol-DA--> Diyarbakir,Mus,Erzurum,Erzincan,Tunceli,Elazig\n");
    fprintf(d, "    ^v   \n");
    fprintf(d, "13-Bitlis-DA--> Siirt,Van,Agri,Mus,Batman\n");
    fprintf(d, "    ^v   \n");
    fprintf(d, "14-Bolu-KA--> Eskisehir,Ankara,Cankiri,Zonguldak,Duzce,Sakarya,Bilecik,Karabuk\n");
    fprintf(d, "    ^v   \n");
    fprintf(d, "15-Burdur-AK--> Mugla,Antalya,Isparta,Afyonkarahisar,Denizli\n");
    fprintf(d, "    ^v   \n");
    fprintf(d, "16-Bursa-MA--> Balikesir,Kutahya,Bilecik,Sakarya,Kocaeli,Yalova\n");
    fprintf(d, "    ^v   \n");
    fprintf(d, "17-Canakkale-MA--> Balikesir,Tekirdag,Edirne\n");
    fprintf(d, "    ^v   \n");
    fprintf(d, "18-Cankiri-IA--> Ankara,Kirikkale,Corum,Kastamonu,Bolu,Karabuk\n");
    fprintf(d, "    ^v   \n");
    fprintf(d, "19-Corum-KA--> Yozgat,Amasya,Samsun,Sinop,Kastamonu,Cankiri,Kirikkale\n");
    fprintf(d, "    ^v   \n");
    fprintf(d, "20-Denizli-EG--> Mugla,Burdur,Afyonkarahisar,Usak,Manisa,Aydin\n");
    fprintf(d, "    ^v   \n");
    fprintf(d, "21,Diyarbakir,GA--> Sanliurfa,Mardin,Batman,Mus,Bingol,Elazig,Malatya,Adiyaman\n");
    fprintf(d, "    ^v   \n");
    fprintf(d, "22-Edirne-MA--> Canakkale,Tekirdag,Kirikkale\n");
    fprintf(d, "    ^v   \n");
    fprintf(d, "23-Elazig-DA--> Diyarbakir,Bingol,Tunceli,Erzincan,Malatya\n");
    fprintf(d, "    ^v   \n");
    fprintf(d, "24-Erzincan-DA--> Elazig,Tunceli,Bingol,Erzurum,Bayburt,Gumushane,Giresun,Sivas,Malatya\n");
    fprintf(d, "    ^v   \n");
    fprintf(d, "25-Erzurum-DA--> Bingol,Mus,Agri,Kars,Ardahan,Artvin,Rize,Bayburt,Erzincan\n");
    fprintf(d, "    ^v   \n");
    fprintf(d, "26-Eskisehir-IA--> Afyonkarahisar,Konya,Ankara,Bolu,Bilecik,Kutahya\n");
    fprintf(d, "    ^v   \n");
    fprintf(d, "27-Gaziantep-GA--> Kilis,Sanliurfa,Adiyaman,Kahramanmaras,Osmaniye,Hatay\n");
    fprintf(d, "    ^v   \n");
    fprintf(d, "28-Giresun-KA--> Gumushane,Trabzon,Erzincan,Sivas,Ordu\n");
    fprintf(d, "    ^v   \n");
    fprintf(d, "29-Gumushane-KA--> Erzincan,Bayburt,Trabzon,Giresun\n");
    fprintf(d, "    ^v   \n");
    fprintf(d, "30-Hakkari-DA--> Van,Sirnak\n");
    fprintf(d, "    ^v   \n");
    fprintf(d, "31-Hatay-AK--> Gaziantep,Osmaniye,Adana\n");
    fprintf(d, "    ^v   \n");
    fprintf(d, "32-Isparta-AK--> Antalya,Konya,Afyonkarahisar,Burdur\n");
    fprintf(d, "    ^v   \n");
    fprintf(d, "33-Mersin-AK--> Adana,Nigde,Konya,Karaman,Antalya\n");
    fprintf(d, "    ^v   \n");
    fprintf(d, "34-Istanbul-MA--> Kocaeli,Tekirdag\n");
    fprintf(d, "    ^v   \n");
    fprintf(d, "35-Izmir-EG--> Aydin,Manisa,Balikesir\n");
    fprintf(d, "    ^v   \n");
    fprintf(d, "36-Kars-DA--> Agri,Igdir,Ardahan,Erzurum\n");
    fprintf(d, "    ^v   \n");
    fprintf(d, "37-Kastamonu-KA--> Corum,Sinop,Cankiri,Bartin,Karabuk\n");
    fprintf(d, "    ^v   \n");
    fprintf(d, "38-Kayseri-IA--> Adana,Kahramanmaras,Sivas,Yozgat,Nevsehir,Nigde\n");
    fprintf(d, "    ^v   \n");
    fprintf(d, "39-Kirklareli-MA--> Edirne,Tekirdag\n");
    fprintf(d, "    ^v   \n");
    fprintf(d, "40-Kirsehir-IA--> Nevsehir,Yozgat,Kirikkale,Ankara,Aksaray\n");
    fprintf(d, "    ^v   \n");
    fprintf(d, "41-Kocaeli-MA--> Yalova,Istanbul,Bursa,Sakarya\n");
    fprintf(d, "    ^v   \n");
    fprintf(d, "42-Konya-IA--> Antalya,Karaman,Mersin,Nigde,Aksaray,Ankara,Eskisehir,Afyonkarahisar,Isparta\n");
    fprintf(d, "    ^v   \n");
    fprintf(d, "43-Kutahya-EG--> Manisa,Usak,Afyonkarahisar,Eskisehir,Bilecik,Bursa,Balikesir\n");
    fprintf(d, "    ^v   \n");
    fprintf(d, "44-Malatya-DA--> Kahramanmaras,Adiyaman,Diyarbakir,Elazig,Erzincan,Sivas\n");
    fprintf(d, "    ^v   \n");
    fprintf(d, "45-Manisa-EG--> Izmir,Aydin,Denizli,Usak,Kutahya,Balikesir\n");
    fprintf(d, "    ^v   \n");
    fprintf(d, "46-Kahramanmaras-AK--> Gaziantep,Adiyaman,Malatya,Sivas,Kayseri,Adana,Osmaniye\n");
    fprintf(d, "    ^v   \n");
    fprintf(d, "47-Mardin-GA--> Sanliurfa,Diyarbakir,Batman,Siirt,Sirnak\n");
    fprintf(d, "    ^v   \n");
    fprintf(d, "48-Mugla-EG--> Antalya,Burdur,Denizli,Aydin\n");
    fprintf(d, "    ^v   \n");
    fprintf(d, "49-Mus-DA--> Diyarbakir,Batman,Bitlis,Agri,Erzurum,Bingol\n");
    fprintf(d, "    ^v   \n");
    fprintf(d, "50-Nevsehir-IA--> Nigde,Kayseri,Yozgat,Kirsehir,Aksaray\n");
    fprintf(d, "    ^v   \n");
    fprintf(d, "51-Nigde-IA--> Nevsehir,Kayseri,Adana,Mersin,Konya,Aksaray\n");
    fprintf(d, "    ^v   \n");
    fprintf(d, "52-Ordu-KA--> Samsun,Tokat,Giresun,Sivas\n");
    fprintf(d, "    ^v   \n");
    fprintf(d, "53-Rize-KA--> Artvin,Erzurum,Bayburt,Trabzon\n");
    fprintf(d, "    ^v   \n");
    fprintf(d, "54-Sakarya-MA--> Duzce,Bolu,Bilecik,Bursa,Kocaeli\n");
    fprintf(d, "    ^v   \n");
    fprintf(d, "55-Samsun-KA--> Ordu,Tokat,Amasya,Corum,Sinop\n");
    fprintf(d, "    ^v   \n");
    fprintf(d, "56-Siirt-GA--> Van,Bitlis,Batman,Mardin,Sirnak\n");
    fprintf(d, "    ^v   \n");
    fprintf(d, "57-Sinop-KA--> Samsun,Corum,Kastamonu\n");
    fprintf(d, "    ^v   \n");
    fprintf(d, "58-Sivas-IA--> Kayseri,Kahramanmaras,Malatya,Erzincan,Giresun,Ordu,Tokat,Yozgat\n");
    fprintf(d, "    ^v   \n");
    fprintf(d, "59-Tekirdag-MA--> Istanbul,Kirklareli,Edirne,Canakkale\n");
    fprintf(d, "    ^v   \n");
    fprintf(d, "60-Tokat-KA--> Sivas,Ordu,Samsun,Amasya,Yozgat\n");
    fprintf(d, "    ^v   \n");
    fprintf(d, "61-Trabzon-KA--> Rize,Bayburt,Gumushane,Giresun\n");
    fprintf(d, "    ^v   \n");
    fprintf(d, "62-Tunceli-DA--> Elazig,Bingol,Erzincan\n");
    fprintf(d, "    ^v   \n");
    fprintf(d, "63-Sanliurfa-GA--> Gaziantep,Adiyaman,Diyarbakir,Mardin\n");
    fprintf(d, "    ^v   \n");
    fprintf(d, "64-Usak-EG--> Manisa,Denizli,Afyonkarahisar,Kutahya\n");
    fprintf(d, "    ^v   \n");
    fprintf(d, "65-Van-DA--> Hakkari,Sirnak,Siirt,Bitlis,Agri\n");
    fprintf(d, "    ^v   \n");
    fprintf(d, "66-Yozgat-IA--> Kayseri,Sivas,Tokat,Amasya,Corum,Kirikkale,Kirsehir,Nevsehir\n");
    fprintf(d, "    ^v   \n");
    fprintf(d, "67-Zonguldak-KA--> Bartin,Bolu,Duzce,Karabuk\n");
    fprintf(d, "    ^v   \n");
    fprintf(d, "68-Aksaray-IA--> Nigde,Nevsehir,Kirsehir,Ankara,Konya\n");
    fprintf(d, "    ^v   \n");
    fprintf(d, "69-Bayburt-KA--> Erzincan,Erzurum,Rize,Trabzon,Gumushane\n");
    fprintf(d, "    ^v   \n");
    fprintf(d, "70-Karaman-IA--> Mersin,Konya,Antalya\n");
    fprintf(d, "    ^v   \n");
    fprintf(d, "71-Kirikkale-IA--> Kirsehir,Yozgat,Corum,Cankiri,Ankara\n");
    fprintf(d, "    ^v   \n");
    fprintf(d, "72-Batman-GA--> Mardin,Siirt,Bitlis,Mus,Diyarbakir\n");
    fprintf(d, "    ^v   \n");
    fprintf(d, "73-Sirnak-GA--> Mardin,Siirt,Van,Hakkari\n");
    fprintf(d, "    ^v   \n");
    fprintf(d, "74-Bartin-KA--> Kastamonu,Zonguldak,Karabuk\n");
    fprintf(d, "    ^v   \n");
    fprintf(d, "75-Ardahan-DA--> Kars,Erzurum,Artvin\n");
    fprintf(d, "    ^v   \n");
    fprintf(d, "76-Igdir-DA--> Agri,Kars\n");
    fprintf(d, "    ^v   \n");
    fprintf(d, "77-Yalova-MA--> Kocaeli,Bursa\n");
    fprintf(d, "    ^v   \n");
    fprintf(d, "78-Karabuk-KA--> Zonguldak,Bartin,Kastamonu,Cankiri,Bolu\n");
    fprintf(d, "    ^v   \n");
    fprintf(d, "79-Kilis-GA--> Gaziantep\n");
    fprintf(d, "    ^v   \n");
    fprintf(d, "80-Osmaniye-AK--> Gaziantep,Kahramanmaras,Adana,Hatay\n");
    fprintf(d, "    ^v   \n");
    fprintf(d, "81-Duzce-KA--> Zonguldak,Bolu,Sakarya\n");
    fprintf(d, "\n\n\n\n");



    char dizi[300];
    char *ptr;
    int t;
    struct sehirler *yeni_sehir;
    struct komsular *yeni_komsu;
    // sehirler dugumu ekleniyor
    while(!feof(dosya))
    {
        fgets(dizi,100,dosya);
        ptr = strtok(dizi,",");
        t = 0;
        struct sehirler *yeni_sehir = (struct sehirler*) malloc(sizeof(struct sehirler));
        while(ptr != NULL)
        {
            if(t == 0)
            {
                yeni_sehir->plaka = atoi(ptr);

            }
            else if(t == 1)
            {
                strcpy(yeni_sehir->adi,ptr);
                //printf("%s\n", yeni_sehir->adi);
            }
            else if(t == 2)
            {
                strcpy(yeni_sehir->bolge,ptr);
            }
            ptr = strtok(NULL,",");
            t++;
        }
        yeni_sehir->komsu_sayisi = t-3; //komsu sayisini buldum
        if(ilk==NULL)
        {
            ilk=yeni_sehir;
            son=yeni_sehir;
            ilk->prev=NULL;
            ilk->next=NULL;
        }
        else
        {
            son->next=yeni_sehir;
            yeni_sehir->prev=son;
            yeni_sehir->next=NULL;
            son=yeni_sehir;
        }
    }
    son = son->prev;
    son->next = NULL;
    // sehirler dugumu eklendi son.

    FILE * dosya2;

    if(!(dosya2 = fopen("sehirler.txt","r")))
    {
        printf("Dosya acilamadi.\n");
        return 0;
    }
    // komsular okunuyor ve ekleniyor
    while(!feof(dosya2))
    {
        fgets(dizi,300,dosya2);
        ptr = strtok(dizi,",");
        t = 0;
        int sehrin_plakasi;
        struct sehirler *shr;
        while(ptr != NULL)
        {
            if(t == 0)
            {
                sehrin_plakasi = atoi(ptr);
            }
            else if(t>2)
            {
                struct komsular *yeni_komsu = (struct komsular*) malloc(sizeof(struct komsular));
                yeni_komsu->sehir_plaka = sehrin_plakasi;

                int j=0;
                char *p;
                char array[50];
                strcpy(array,ptr);
                p = strchr(array,'\n');
                if(p!=NULL)
                {
                    while(*(ptr+j)!=NULL)
                    {
                        j++;
                    }
                    *(ptr+j-1) = NULL;
                }
                shr = plakabul(ptr);
                yeni_komsu->komsu_plaka = shr->plaka;
                //	printf("Aranan : %s - Plaka Kodu : %d\n",ptr,shr->plaka);

                if(kilk==NULL)
                {
                    kilk=yeni_komsu;
                    kson=yeni_komsu;
                    kson->sonraki=NULL;
                }
                else
                {
                    kson->sonraki=yeni_komsu;
                    kson=yeni_komsu;
                    kson->sonraki=NULL;
                }
            }
            ptr = strtok(NULL,",");
            t++;


        }

    }

burayagel:
    printf("-------------------Islem Menusu-------------------\n");
    printf("1) Yeni sehir, komsuluk ekleme\n");
    printf("2) Arama yapma\n");
    printf("3) Sehir, komsuluk silme\n");
    printf("4) Istenilen bolgedeki sehirler\n");
    printf("5) Belli bir komsu sayisi kriterine uyan sehirler\n");
    printf("6) Listele\n");
    printf("--------------------------------------------------\n\n");
    fprintf(d,"-------------------Islem Menusu-------------------\n");
    fprintf(d,"1) Yeni sehir, komsuluk ekleme\n");
    fprintf(d,"2) Arama yapma\n");
    fprintf(d,"3) Sehir, komsuluk silme\n");
    fprintf(d,"4) Istenilen bolgedeki sehirler\n");
    fprintf(d,"5) Belli bir komsu sayisi kriterine uyan sehirler\n");
    fprintf(d,"6) Listele\n");
    fprintf(d,"--------------------------------------------------\n\n");


    int secim,bolgesecim,aramasecim,plakaarama,a,syc1=0,syc2=0,syc3=0,syc4=0,syc5=0,syc6=0,syc7=0,syc8=0,syc9=0,plkekle,plakasil,silmesecim,kriter,kritersayi,ekleme,plk,kms,komsuplaka;
    char isimarama[20],sehirsilme[20],komsusilme[20],sehirekleme[20],bolgekodu[20],komsuekleme[20];
    printf("Yapmak istediginiz islemi secin : ");
    fprintf(d,"Yapmak istediginiz islemi secin : ");
    scanf("%d", &secim);
    fprintf(d,"%d",secim);
    printf("\n");
    fprintf(d,"\n");

    if(secim==1)
    {
        printf("Hangisini eklemek istiyorsunuz\n");
        printf("1 - Yeni Sehir\n");
        printf("2 - Yeni Komsuluk\n");
        printf("Secim : ");
        fprintf(d,"Hangisini eklemek istiyorsunuz\n");
        fprintf(d,"1 - Yeni Sehir\n");
        fprintf(d,"2 - Yeni Komsuluk\n");
        fprintf(d,"Secim : ");
        scanf("%d",&ekleme);
        fprintf(d,"%d",ekleme);
        if(ekleme==1)
        {
            printf("Eklemek istediginiz sehrin plakasini girin : ");
            fprintf(d,"Eklemek istediginiz sehrin plakasini girin : ");
            scanf("%d",&plk);
            fprintf(d,"%d",plk);
            yeni_sehir = ilk;
            while(yeni_sehir != NULL)
            {
                if(yeni_sehir->plaka == plk)
                {
                    printf("%d plakali bir sehir zaten mevcut.\n",plk);
                    fprintf(d,"%d plakali bir sehir zaten mevcut.\n",plk);
                    printf("Menuye yonlendiriliyorsunuz...\n\n");
                    fprintf(d,"Menuye yonlendiriliyorsunuz...\n\n");
                    goto burayagel;
                }
                yeni_sehir = yeni_sehir->next;
            }

            printf("Yeni sehrin ismini girin : ");
            fprintf(d,"Yeni sehrin ismini girin : ");
            scanf("%s",&sehirekleme);
            fprintf(d,"%s",sehirekleme);
            temp = ilk;
            while(temp != NULL)
            {
                if(strcmp(temp->adi,sehirekleme)==0)
                {
                    printf("Boyle bir sehir zaten mevcut.\n");
                    printf("Lobiye yonlendiriliyorsunuz...\n\n");
                    fprintf(d,"Boyle bir sehir zaten mevcut.\n");
                    fprintf(d,"Lobiye yonlendiriliyorsunuz...\n\n");
                    goto burayagel;
                }
                temp = temp->next;
            }
            printf("Yeni sehrin bolge kodunu girin : ");
            fprintf(d,"Yeni sehrin bolge kodunu girin : ");
            scanf("%s",&bolgekodu);
            fprintf(d,"%s",bolgekodu);
            char dizi[7][20] = {"AK","MA","EG","KA","DA","GA","IA"};
            for(int i=0 ; i<7 ; i++)
            {
                if(strcmp(bolgekodu,dizi[i])==0)
                {
                    syc9++;
                }
            }
            if(syc9==0){
                printf("Boyle bir bolgemiz mevcut degil.\n");
                printf("Menuye yonlendiriliyorsunuz...\n\n");
                fprintf(d,"Boyle bir bolgemiz mevcut degil.\n");
                fprintf(d,"Menuye yonlendiriliyorsunuz...\n\n");
                goto burayagel;
            }

            printf("Yeni sehrin komsu sayisini girin : ");
            fprintf(d,"Yeni sehrin komsu sayisini girin : ");
            scanf("%d",&kms);
            fprintf(d,"%d",kms);
            printf("Komsular�n plakasini girin :\n");
            fprintf(d,"Komsular�n plakasini girin :\n");
            for(int i=0 ; i<kms ; i++)
            {
                printf("%d. komsunun plakasi : ",i+1);
                fprintf(d,"%d. komsunun plakasi : ",i+1);
                scanf("%d",&komsuplaka);
                fprintf(d,"%d",komsuplaka);
                ktemp = kilk;
                while(ktemp != NULL)
                {
                    if(ktemp->komsu_plaka == komsuplaka)
                    {
                        syc6++;
                    }
                    ktemp = ktemp->sonraki;
                }
                if(syc6==0)
                {
                    printf("Boyle bir sehir yoktur.\n");
                    printf("Men�ye y�nlendiriliyorsunuz...\n");
                    printf("\n");
                    fprintf(d,"Boyle bir sehir yoktur.\n");
                    fprintf(d,"Men�ye y�nlendiriliyorsunuz...\n");
                    fprintf(d,"\n");
                    goto burayagel;
                }
                struct komsular *yeni_komsu = (struct komsular*) malloc(sizeof(struct komsular));
                kson->sonraki = yeni_komsu;
                yeni_komsu->sonraki = NULL;
                yeni_komsu->sehir_plaka = plk;
                yeni_komsu->komsu_plaka = komsuplaka;
                kson = yeni_komsu;

                syc6=0;
            }

            struct sehirler *yeni_sehir = (struct sehirler*) malloc(sizeof(struct sehirler));
            yeni_sehir->plaka = plk;
            strcpy(yeni_sehir->adi,sehirekleme);
            strcpy(yeni_sehir->bolge,bolgekodu);
            yeni_sehir->komsu_sayisi = kms;

            if(yeni_sehir->plaka < ilk->plaka)
            {
                ilk->prev = yeni_sehir;
                yeni_sehir->next = ilk;
                yeni_sehir->prev = NULL;
                ilk = yeni_sehir;
            }
            else if(yeni_sehir->plaka > son->plaka)
            {
                son->next = yeni_sehir;
                yeni_sehir->prev = son;
                yeni_sehir->next = NULL;
                son = yeni_sehir;
            }
            else if(yeni_sehir->plaka>ilk->plaka && yeni_sehir->plaka<son->plaka)
            {
                temp = ilk;
                while(temp != NULL)
                {
                    if(temp->plaka > yeni_sehir->plaka)
                    {
                        temp->prev->next = yeni_sehir;
                        yeni_sehir->prev = temp->prev;
                        yeni_sehir->next = temp;
                        temp->prev = yeni_sehir;
                        break;
                    }
                    temp = temp->next;
                }
            }
            goto burayagel;
        }
        if(ekleme==2)
        {
            printf("Hangi sehre komsuluk eklemek istiyorsunuz : ");
            fprintf(d,"Hangi sehre komsuluk eklemek istiyorsunuz : ");
            scanf("%s",&komsuekleme);
            fprintf(d,"%s",komsuekleme);
            temp = ilk;
            while(temp != NULL)
            {
                if(strcmp(temp->adi,komsuekleme)==0)
                {
                    a = temp->plaka;
                    syc7++;
                }
                temp = temp->next;
            }
            if(syc7==0)
            {
                printf("Boyle bir sehir mevcut degil.\n");
                printf("Menuye yonlendiriliyorsunuz...\n\n");
                fprintf(d,"Boyle bir sehir mevcut degil.\n");
                fprintf(d,"Menuye yonlendiriliyorsunuz...\n\n");
                goto burayagel;
            }
            printf("Eklemek istediginiz komsunun plakasini girin : ");
            fprintf(d,"Eklemek istediginiz komsunun plakasini girin : ");
            scanf("%d",&plkekle);
            fprintf(d,"%d",plkekle);
            ktemp = kilk;
            while(ktemp != NULL)
            {
                if(ktemp->komsu_plaka == plkekle)
                {
                    syc8++;
                }
                ktemp = ktemp->sonraki;
            }
            if(syc8==0)
            {
                printf("Komsu olarak ekleyebileceginiz boyle bir sehir yoktur.\n");
                printf("Menuye yonlendiriliyorsunuz...\n\n");
                fprintf(d,"Komsu olarak ekleyebileceginiz boyle bir sehir yoktur.\n");
                fprintf(d,"Menuyeye yonlendiriliyorsunuz...\n\n");
                goto burayagel;
            }
            struct komsular *yeni_komsu = (struct komsular*) malloc(sizeof(struct komsular));
            yeni_komsu->sehir_plaka = a;
            yeni_komsu->komsu_plaka = plkekle;
            kson->sonraki = yeni_komsu;
            kson = yeni_komsu;
            kson->sonraki = NULL;

            temp = ilk;
            while(temp != NULL)
            {
                if(strcmp(temp->adi,komsuekleme)==0)
                {
                    temp->komsu_sayisi++;
                }
                temp = temp->next;
            }

            goto burayagel;
        }
    }
    if(secim==2)
    {
        printf("1 - Plaka ile arama\n");
        printf("2 - Isim ile arama\n");
        printf("Secim : ");
        fprintf(d,"1 - Plaka ile arama\n");
        fprintf(d,"2 - Isim ile arama\n");
        fprintf(d,"Secim : ");
        scanf("%d",&aramasecim);
        fprintf(d,"%d",aramasecim);
        printf("\n");
        fprintf(d,"\n");

        if(aramasecim==1)
        {
            printf("Plaka girin : ");
            fprintf(d,"Plaka girin : ");
            scanf("%d",&plakaarama);
            fprintf(d,"%d",plakaarama);
            printf("\n");
            fprintf(d,"\n");
            yeni_sehir = ilk;
            while(yeni_sehir != NULL)
            {
                if(yeni_sehir->plaka == plakaarama)
                {
                    syc1++;
                    printf("%d %s %s %d\n",yeni_sehir->plaka,yeni_sehir->adi,yeni_sehir->bolge,yeni_sehir->komsu_sayisi);
                    printf("Komsu bilgileri\n");
                    fprintf(d,"%d %s %s %d\n",yeni_sehir->plaka,yeni_sehir->adi,yeni_sehir->bolge,yeni_sehir->komsu_sayisi);
                    fprintf(d,"Komsu bilgileri\n");
                    yeni_komsu = kilk;
                    while(yeni_komsu != NULL)
                    {
                        if(yeni_komsu->sehir_plaka == plakaarama)
                        {
                            a = yeni_komsu->komsu_plaka;
                            temp = ilk;
                            while(temp != NULL)
                            {
                                if(temp->plaka == a)
                                {
                                    printf("%d %s %s %d\n",temp->plaka,temp->adi,temp->bolge,temp->komsu_sayisi);
                                    fprintf(d,"%d %s %s %d\n",temp->plaka,temp->adi,temp->bolge,temp->komsu_sayisi);
                                }
                                temp = temp->next;
                            }
                        }
                        yeni_komsu = yeni_komsu->sonraki;
                    }
                    break;
                }
                else
                    yeni_sehir = yeni_sehir->next;
            }
            if(syc1==0)
            {
                printf("Yazdiginiz plaka ile eslesen sehir bulunamadi, eklemek icin menuden \"Yeni sehir, komsuluk ekleme\" kismini secin.\n");
                fprintf(d,"Yazdiginiz plaka ile eslesen sehir bulunamadi, eklemek icin menuden \"Yeni sehir, komsuluk ekleme\" kismini secin.\n");
            }

            printf("\n");
            fprintf(d,"\n");
            goto burayagel;
        }
        else if(aramasecim==2)
        {
            printf("Sehir ismi girin : ");
            fprintf(d,"Sehir ismi girin : ");
            scanf("%s",&isimarama);
            fprintf(d,"%s",isimarama);
            printf("\n");
            fprintf(d,"\n");
            yeni_sehir = ilk;
            while(yeni_sehir != NULL)
            {
                if(strcmp(yeni_sehir->adi,isimarama)==0)
                {
                    syc2++;
                    printf("%d %s %s %d\n",yeni_sehir->plaka,yeni_sehir->adi,yeni_sehir->bolge,yeni_sehir->komsu_sayisi);
                    printf("Komsu bilgileri\n");
                    fprintf(d,"%d %s %s %d\n",yeni_sehir->plaka,yeni_sehir->adi,yeni_sehir->bolge,yeni_sehir->komsu_sayisi);
                    fprintf(d,"Komsu bilgileri\n");
                    yeni_komsu = kilk;
                    while(yeni_komsu != NULL)
                    {
                        if(yeni_komsu->sehir_plaka == yeni_sehir->plaka)
                        {
                            a = yeni_komsu->komsu_plaka;
                            temp = ilk;
                            while(temp != NULL)
                            {
                                if(temp->plaka == a)
                                {
                                    printf("%d %s %s %d\n",temp->plaka,temp->adi,temp->bolge,temp->komsu_sayisi);
                                    fprintf(d,"%d %s %s %d\n",temp->plaka,temp->adi,temp->bolge,temp->komsu_sayisi);
                                    break;
                                }
                                temp = temp->next;
                            }
                        }
                        yeni_komsu = yeni_komsu->sonraki;
                    }
                    break;
                }
                yeni_sehir = yeni_sehir->next;
            }
            if(syc2==0)
            {
                printf("Yazdiginiz isim ile eslesen sehir bulunamadi, eklemek icin menuden \"Yeni sehir, komsuluk ekleme\" kismini secin.\n");
                fprintf(d,"Yazdiginiz isim ile eslesen sehir bulunamadi, eklemek icin menuden \"Yeni sehir, komsuluk ekleme\" kismini secin.\n");
            }
            printf("\n");
            fprintf(d,"\n");
            goto burayagel;
        }

    }
    else if(secim==3)
    {
        printf("Hangisini silmek istiyorsunuz\n");
        printf("1 - Sehir\n");
        printf("2 - Komsuluk\n");
        printf("Secim : ");
        fprintf(d,"Hangisini silmek istiyorsunuz\n");
        fprintf(d,"1 - Sehir\n");
        fprintf(d,"2 - Komsuluk\n");
        fprintf(d,"Secim : ");
        scanf("%d",&silmesecim);
        fprintf(d,"%d",silmesecim);
        printf("\n");
        fprintf(d,"\n");
        if(silmesecim==1)
        {
            printf("Silmek istediginiz sehrin plakasini girin : ");
            fprintf(d,"Silmek istediginiz sehrin plakasini girin : ");
            scanf("%d",&plakasil);
            fprintf(d,"%d",plakasil);
            printf("\n");
            fprintf(d,"\n");

            yeni_sehir = ilk;
            while(yeni_sehir != NULL)
            {
                if(yeni_sehir->plaka == plakasil)
                {
                    syc3++;

                    if(yeni_sehir==ilk)
                    {
                        ilk = ilk->next;
                        ilk->prev = NULL;
                        free(yeni_sehir);
                    }
                    else if(yeni_sehir==son)
                    {
                        son = son->prev;
                        son->next = NULL;
                        free(yeni_sehir);
                    }
                    else
                    {
                        temp1 = yeni_sehir->prev;
                        temp2 = yeni_sehir->next;
                        free(yeni_sehir);
                        temp1->next = temp2;
                        temp2->prev = temp1;
                    }
                }
                yeni_sehir = yeni_sehir->next;
            }
            if(syc3==0)
            {
                printf("Zaten boyle bir sehir kaydi bulanmamaktadir.\n\n");
                fprintf(d,"Zaten boyle bir sehir kaydi bulanmamaktadir.\n\n");

            }
            ktemp = kilk;
            while(ktemp != NULL)
            {
                if(ktemp->sehir_plaka == plakasil)
                {
                    if(ktemp == kilk)
                    {
                        kilk = kilk->sonraki;
                        free(ktemp);
                    }
                    else if(ktemp == kson)
                    {
                        ktemp1 = kilk;
                        while(ktemp1 != NULL)
                        {
                            if(ktemp1->sonraki->sonraki == NULL)
                            {
                                free(ktemp);
                                kson = ktemp1;
                                kson->sonraki = NULL;
                            }
                            ktemp1 = ktemp1->sonraki;
                        }
                    }
                    else
                    {
                        ktemp2 = kilk;
                        while(ktemp2 != NULL)
                        {
                            if(ktemp2->sonraki == ktemp)
                            {
                                ktemp2->sonraki = ktemp2->sonraki->sonraki;
                                free(ktemp);
                            }
                            ktemp2 = ktemp2->sonraki;
                        }
                    }
                }
                ktemp = ktemp->sonraki;
            }
            printf("Sehir basariyla silindi.\n\n");
            fprintf(d,"Sehir basariyla silindi.\n\n");
            goto burayagel;

        }
        if(silmesecim==2)
        {
            printf("Hangi sehrin komsusunu silmek istiyorsunuz : ");
            fprintf(d,"Hangi sehrin komsusunu silmek istiyorsunuz : ");
            scanf("%s",&sehirsilme);
            fprintf(d,"%s",sehirsilme);
            yeni_sehir = ilk;
            while(yeni_sehir != NULL)
            {
                if(strcmp(yeni_sehir->adi,sehirsilme)==0)
                {
                    syc4++;
                    break;
                }
                yeni_sehir = yeni_sehir->next;
            }
            if(syc4==0)
            {
                printf("Boyle bir sehir kaydi bulunmamaktadir.\n");
                fprintf(d,"Boyle bir sehir kaydi bulunmamaktadir.\n");
                goto burayagel;
            }
            printf("%s sehrinin hangi komsusunu silmek istiyorsunuz : ",yeni_sehir->adi);
            fprintf(d,"%s sehrinin hangi komsusunu silmek istiyorsunuz : ",yeni_sehir->adi);
            scanf("%s",&komsusilme);
            fprintf(d,"%s",komsusilme);
            printf("\n");
            fprintf(d,"\n");
            temp = ilk;
            while(temp != NULL)
            {
                if(strcmp(temp->adi,komsusilme)==0)
                {
                    a = temp->plaka;
                    break;
                }
                temp = temp->next;
            }
            ktemp = kilk;
            while(ktemp != NULL)
            {
                if(ktemp->komsu_plaka == a && ktemp->sehir_plaka == yeni_sehir->plaka)
                {
                    syc5++;
                    break;
                }
                ktemp = ktemp->sonraki;
            }
            if(syc5==0)
            {
                printf("%s sehrinin boyle bir komsusu zaten yoktur.\n",yeni_sehir->adi);
                fprintf(d,"%s sehrinin boyle bir komsusu zaten yoktur.\n",yeni_sehir->adi);
                goto burayagel;
            }
            if(ktemp == ilk)
            {
                kilk = kilk->sonraki;
                free(ktemp);
                yeni_sehir->komsu_sayisi--;
                printf("Komsuluk basariyla silindi.\n\n");
                fprintf(d,"Komsuluk basariyla silindi.\n\n");
            }
            else if(ktemp == kson)
            {
                ktemp1 = kilk;
                while(ktemp1 != NULL)
                {
                    if(ktemp1->sonraki->sonraki == NULL)
                    {
                        free(ktemp1->sonraki);
                        kson = ktemp1;
                    }
                    ktemp1 = ktemp->sonraki;
                }
                yeni_sehir->komsu_sayisi--;
                printf("Komsuluk basariyla silindi.\n\n");
                fprintf(d,"Komsuluk basariyla silindi.\n\n");
            }
            else
            {
                ktemp2 = kilk;
                while(ktemp2 != NULL)
                {
                    if(ktemp2->sonraki == ktemp)
                    {
                        ktemp3 = ktemp;
                        ktemp2->sonraki = ktemp2->sonraki->sonraki;
                        free(ktemp3);
                    }
                    ktemp2 = ktemp2->sonraki;
                }
                yeni_sehir->komsu_sayisi--;
                printf("Komsuluk basariyla silindi.\n\n");
                fprintf(d,"Komsuluk basariyla silindi.\n\n");
            }
            goto burayagel;
        }
    }
    else if(secim==4)
    {
        printf("Hangi bolgedeki sehirleri gormek istiyorsunuz \n");
        printf("1 - Akdeniz Bolgesi\n");
        printf("2 - Marmara Bolgesi\n");
        printf("3 - Ege Bolgesi\n");
        printf("4 - Karadeniz Bolgesi\n");
        printf("5 - Dogu Anadolu Bolgesi\n");
        printf("6 - Guneydogu Anadolu Bolgesi\n");
        printf("7 - Ic Anadolu Bolgesi\n");
        printf("Secim : ");
        fprintf(d,"Hangi bolgedeki sehirleri gormek istiyorsunuz \n");
        fprintf(d,"1 - Akdeniz Bolgesi\n");
        fprintf(d,"2 - Marmara Bolgesi\n");
        fprintf(d,"3 - Ege Bolgesi\n");
        fprintf(d,"4 - Karadeniz Bolgesi\n");
        fprintf(d,"5 - Dogu Anadolu Bolgesi\n");
        fprintf(d,"6 - Guneydogu Anadolu Bolgesi\n");
        fprintf(d,"7 - Ic Anadolu Bolgesi\n");
        fprintf(d,"Secim : ");
        scanf("%d",&bolgesecim);
        fprintf(d,"%d",bolgesecim);
        printf("\n");
        fprintf(d,"\n");

        if(bolgesecim==1)
        {
            printf("Akdeniz Bolgesindeki iller\n");
            fprintf(d,"Akdeniz Bolgesindeki iller\n");
            yeni_sehir = ilk;
            while(yeni_sehir != NULL)
            {
                if(strcmp(yeni_sehir->bolge,"AK")==0)
                {
                    printf("%d %s %s %d\n",yeni_sehir->plaka,yeni_sehir->adi,yeni_sehir->bolge,yeni_sehir->komsu_sayisi);
                    fprintf(d,"%d %s %s %d\n",yeni_sehir->plaka,yeni_sehir->adi,yeni_sehir->bolge,yeni_sehir->komsu_sayisi);
                    yeni_sehir = yeni_sehir->next;
                }
                else
                    yeni_sehir = yeni_sehir->next;
            }
            printf("\n");
            fprintf(d,"\n");
            goto burayagel;
        }
        else if(bolgesecim==2)
        {
            printf("Marmara Bolgesindeki iller\n");
            fprintf(d,"Marmara Bolgesindeki iller\n");
            yeni_sehir = ilk;
            while(yeni_sehir != NULL)
            {
                if(strcmp(yeni_sehir->bolge,"MA")==0)
                {
                    printf("%s\n",yeni_sehir->adi);
                    fprintf(d,"%s\n",yeni_sehir->adi);
                    yeni_sehir = yeni_sehir->next;
                }
                else
                    yeni_sehir = yeni_sehir->next;
            }
            printf("\n");
            fprintf(d,"\n");
            goto burayagel;
        }
        else if(bolgesecim==3)
        {
            printf("Ege Bolgesindeki iller\n");
            fprintf(d,"Ege Bolgesindeki iller\n");
            yeni_sehir = ilk;
            while(yeni_sehir != NULL)
            {
                if(strcmp(yeni_sehir->bolge,"EG")==0)
                {
                    printf("%s\n",yeni_sehir->adi);
                    fprintf(d,"%s\n",yeni_sehir->adi);
                    yeni_sehir = yeni_sehir->next;
                }
                else
                    yeni_sehir = yeni_sehir->next;
            }
            printf("\n");
            fprintf(d,"\n");
            goto burayagel;
        }
        else if(bolgesecim==4)
        {
            printf("Karadeniz Bolgesindeki iller\n");
            fprintf(d,"Karadeniz Bolgesindeki iller\n");
            yeni_sehir = ilk;
            while(yeni_sehir != NULL)
            {
                if(strcmp(yeni_sehir->bolge,"KA")==0)
                {
                    printf("%s\n",yeni_sehir->adi);
                    fprintf(d,"%s\n",yeni_sehir->adi);
                    yeni_sehir = yeni_sehir->next;
                }
                else
                    yeni_sehir = yeni_sehir->next;
            }
            printf("\n");
            fprintf(d,"\n");
            goto burayagel;
        }
        else if(bolgesecim==5)
        {
            printf("Dohu Anadolu Bolgesindeki iller\n");
            fprintf(d,"Dohu Anadolu Bolgesindeki iller\n");
            yeni_sehir = ilk;
            while(yeni_sehir != NULL)
            {
                if(strcmp(yeni_sehir->bolge,"DA")==0)
                {
                    printf("%s\n",yeni_sehir->adi);
                    fprintf(d,"%s\n",yeni_sehir->adi);
                    yeni_sehir = yeni_sehir->next;
                }
                else
                    yeni_sehir = yeni_sehir->next;
            }
            printf("\n");
            fprintf(d,"\n");
            goto burayagel;
        }
        else if(bolgesecim==6)
        {
            printf("Guneydogu Anadolu Bolgesindeki iller\n");
            fprintf(d,"Guneydogu Anadolu Bolgesindeki iller\n");
            yeni_sehir = ilk;
            while(yeni_sehir != NULL)
            {
                if(strcmp(yeni_sehir->bolge,"GA")==0)
                {
                    printf("%s\n",yeni_sehir->adi);
                    fprintf(d,"%s\n",yeni_sehir->adi);
                    yeni_sehir = yeni_sehir->next;
                }
                else
                    yeni_sehir = yeni_sehir->next;
            }
            printf("\n");
            fprintf(d,"\n");
            goto burayagel;
        }
        else if(bolgesecim==7)
        {
            printf("Ic Anadolu Bolgesindeki iller\n");
            fprintf(d,"Ic Anadolu Bolgesindeki iller\n");
            yeni_sehir = ilk;
            while(yeni_sehir != NULL)
            {
                if(strcmp(yeni_sehir->bolge,"IA")==0)
                {
                    printf("%s\n",yeni_sehir->adi);
                    fprintf(d,"%s\n",yeni_sehir->adi);
                    yeni_sehir = yeni_sehir->next;
                }
                else
                    yeni_sehir = yeni_sehir->next;
            }
            printf("\n");
            fprintf(d,"\n");
            goto burayagel;
        }
    }
    else if(secim==5)
    {
        printf("1 - Bir sayidan fazla komsu sayisina sahip sehirler\n");
        printf("2 - Bir sayidan az komsu sayisina sahip sehirler\n");
        printf("Secim : ");
        fprintf(d,"1 - Bir sayidan fazla komsu sayisina sahip sehirler\n");
        fprintf(d,"2 - Bir sayidan az komsu sayisina sahip sehirler\n");
        fprintf(d,"Secim : ");
        scanf("%d",&kriter);
        fprintf(d,"%d",kriter);
        if(kriter==1)
        {
            printf("Kactan fazla komsu sayisina sahip olan sehirleri gormek istiyorsunuz : ");
            fprintf(d,"Kactan fazla komsu sayisina sahip olan sehirleri gormek istiyorsunuz : ");
            scanf("%d",&kritersayi);
            fprintf(d,"%d",kritersayi);
            printf("\n%d sayisindan fazla komsusu olan sehirler listeleniyor...\n",kritersayi);
            fprintf(d,"\n%d sayisindan fazla komsusu olan sehirler listeleniyor...\n",kritersayi);
            yeni_sehir = ilk;
            while(yeni_sehir != NULL)
            {
                if(yeni_sehir->komsu_sayisi > kritersayi)
                {
                    printf("%d %s %s %d\n",yeni_sehir->plaka,yeni_sehir->adi,yeni_sehir->bolge,yeni_sehir->komsu_sayisi);
                    fprintf(d,"%d %s %s %d\n",yeni_sehir->plaka,yeni_sehir->adi,yeni_sehir->bolge,yeni_sehir->komsu_sayisi);
                }
                yeni_sehir = yeni_sehir->next;
            }
        }
        else if(kriter==2)
        {
            printf("Kactan az komsu sayisina sahip olan sehirleri gormek istiyorsunuz : ");
            fprintf(d,"Kactan az komsu sayisina sahip olan sehirleri gormek istiyorsunuz : ");
            scanf("%d",&kritersayi);
            fprintf(d,"%d",kritersayi);
            printf("\n%d sayisindan az komsusu olan sehirler listeleniyor...\n",kritersayi);
            fprintf(d,"\n%d sayisindan az komsusu olan sehirler listeleniyor...\n",kritersayi);
            yeni_sehir = ilk;
            while(yeni_sehir != NULL)
            {
                if(yeni_sehir->komsu_sayisi < kritersayi)
                {
                    printf("%d %s %s %d\n",yeni_sehir->plaka,yeni_sehir->adi,yeni_sehir->bolge,yeni_sehir->komsu_sayisi);
                    fprintf(d,"%d %s %s %d\n",yeni_sehir->plaka,yeni_sehir->adi,yeni_sehir->bolge,yeni_sehir->komsu_sayisi);
                }
                yeni_sehir = yeni_sehir->next;
            }
        }
        printf("\n");
        fprintf(d,"\n");
        goto burayagel;
    }
    else if(secim==6)
    {
        printf("Listeleniyor...\n\n");
        fprintf(d,"Listeleniyor...\n\n");
        yeni_sehir = ilk;
        while(yeni_sehir != NULL)
        {
            printf("%d %s %s %d\n",yeni_sehir->plaka,yeni_sehir->adi,yeni_sehir->bolge,yeni_sehir->komsu_sayisi);
            printf("Komsu Bilgileri\n");
            fprintf(d,"%d %s %s %d\n",yeni_sehir->plaka,yeni_sehir->adi,yeni_sehir->bolge,yeni_sehir->komsu_sayisi);
            fprintf(d,"Komsu Bilgileri\n");
            yeni_komsu = kilk;
            while(yeni_komsu != NULL)
            {
                if(yeni_komsu->sehir_plaka == yeni_sehir->plaka)
                {
                    a = yeni_komsu->komsu_plaka;
                    temp = ilk;
                    while(temp != NULL)
                    {
                        if(temp->plaka == a)
                        {
                            printf("%d %s %s %d\n",temp->plaka,temp->adi,temp->bolge,temp->komsu_sayisi);
                            fprintf(d,"%d %s %s %d\n",temp->plaka,temp->adi,temp->bolge,temp->komsu_sayisi);
                            break;
                        }
                        temp = temp->next;
                    }
                }
                yeni_komsu = yeni_komsu->sonraki;
            }
            printf("\n");
            fprintf(d,"\n");
            yeni_sehir = yeni_sehir->next;

        }
        goto burayagel;
    }
    else
    {
        return 0;
    }
}
