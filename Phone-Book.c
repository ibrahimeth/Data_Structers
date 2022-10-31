#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 50

struct rehber
{
    char name[MAX];
    char surname[MAX];
    char tel[MAX];
    char Email[MAX];
    struct rehber *adres ;
};
typedef struct rehber rehber ;

rehber *first =NULL ;
void AppendLast(rehber**) ;
void Listele();
void Search(char a[MAX]);
void Remove(char name[MAX]);
void RemoveFirst();
void RemoveLast();
int main(void)
{
    int secim ;
    char name[MAX], surname[MAX], Email[MAX], tel[MAX] ;
    while (1)
    {
        for (int i = 0; i < 15; i++)
            printf("----");
        printf("\n1 - Kişi kaydet\n2 - Kişileri Listele\n3 - Kişi Ara\n4 - Kişi sil\n5 - Çık\n");
        for (int i = 0; i < 15; i++)
            printf("----");
        do
        {
            secim = 0 ;
            printf("\n>>>>> ");
            scanf("%d", &secim);
        } while ((secim < 1 ) || (secim > 5));
        system("clear");
        if(secim == 1)
        {
            rehber *gecici = (rehber*)malloc(sizeof(rehber)) ;
            printf("İsim :");   
            scanf("%s", &gecici->name);
            printf("soyisim :");
            scanf("%s", &gecici->surname );
            printf("Telefon numaranız:");
            scanf("%s", &gecici->tel);
            printf("Email adresiniz :");
            scanf("%s", &gecici->Email) ;
            gecici->adres = NULL;
            AppendLast(&gecici);
        }
        else if(secim == 2)
        {
            Listele();
        }
        else if (secim == 3)
        {
            char ad[MAX];
            printf("Bulmak istediğiniz Kişinin Adı veya Soyadı :");
            scanf("%s", &ad);
            Search(ad);
        }
        else if(secim == 4)
        {
            char ad[MAX] ;
            printf("silemk istediğiniz kişinin adı : ");
            scanf("%s",&ad);
            Remove(ad);
        }
        else if (secim == 5)
        {
            printf("Rehber verileri silindi...!");
            break;
        }
        else
        {
            printf("Lütfen 1 ila 5 arasında bir sayı giriniz !");
        }
    }
    return 0 ;
}
void AppendLast(rehber **llad) 
{
    if (first == NULL){
        first = *llad ;
    }
    else 
    {
        rehber *temp = first ;
        while (temp->adres != NULL)
        {
            temp = temp->adres ;
        } 
        temp->adres = *llad ;
        
    }
    printf("\n\t\tKayit oluşturuldu!\n"); 
}
void Search(char tep[MAX])
{
    rehber *temp = first;
    int sayac = 1;
    while (temp != NULL)
    {
        if ((!strcmp(tep,temp->name)) || (!strcmp(tep,temp->surname)))
        {
            printf("\n\t\t\t%d. Sırada Bulundu\n", sayac);
            printf("\t\t\t%s | %s | %s | %s\n",temp->name, temp->surname, temp->tel, temp->Email);
        }
        temp = temp->adres ;
        sayac++ ;
    }
    printf("\nMaalesef Aradığınız isime veya soyisime sahip bir kayıt Bulunamadı!\n");
}
void Listele()
{
    rehber *temp = first ;
    printf("\nNo\t\tName\t\tSurname\t\tPhone\t\tEmail\n");
    for (int i = 0; i < 5; i++)
        printf("-------\t\t");
    printf("\n");
    int sayac =1;
    do
    {
        printf("%d\t\t%s\t \t%s\t \t%s\t \t%s\n", sayac, temp->name, temp->surname, temp->tel, temp->Email);
        if (temp->adres == NULL)
        {
            printf("\n\t\t\tListe  Sonu\n");
            break;
        }
        temp = temp->adres ;
        sayac++ ;
    } while (temp != NULL);    
}
void RemoveFirst()
{
    if(first == NULL){
		printf("Listede silinecek eleman yoktur!");
	}
	else if(first -> adres == NULL){
		first = NULL;
	}
	else{
		rehber *ikinci = first -> adres;
		free(first); 
		first = ikinci;
	}
}
void RemoveLast()
{
    rehber *temp = first;
	while(temp -> adres -> adres != NULL)
		temp = temp -> adres;
	free(temp -> adres);
	temp -> adres = NULL;
}
void Remove(char name[MAX]) 
{
    rehber *temp = first ; 
    if (!strcmp(first->name, name))
    {
        RemoveFirst();
    }
    rehber *Previous =  NULL;
    rehber *next = NULL ;
    while (temp->adres != NULL)
    {
        if (!strcmp(temp->adres->name, name))
        {
            free(temp->adres);
            temp->adres = temp->adres->adres ;
            break;
        }
        temp = temp->adres ;
    }
    if (!strcmp(temp->name, name))
    {
        RemoveLast();
    }
    Listele();
}