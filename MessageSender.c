//contributed by ibrahimeth
// Queue structure example given in data structures course
// sending messages via internet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#define MAX 100 

struct message
{
    char veri[MAX] ;
    struct message *adres ;
};
typedef struct message message_Node ;

message_Node *front = NULL;
message_Node *rear = NULL;
void enqueue(message_Node**);
void List_of_Queue(void);
int dequeue(void);

int main(void)
{
    int veri ;
    char isOnline ;
    while (1)
    {
        message_Node *mesaj = (message_Node*)malloc(sizeof(message_Node)) ;
        printf("mesajınızı giriniz :");
        gets(mesaj->veri);
        if (!strcmp(mesaj->veri,"quit"))
        {
            break;
        }
        fflush(stdin);
        printf("internet var mı ? (e/h)") ;
        scanf("%c", &isOnline) ;
        mesaj->adres == NULL;
        if (isOnline == 'e')
        {
            enqueue(&mesaj);
            int x = dequeue();
            if (x != 0)
            {
                while (x != 0 )
                {
                    sleep(1);
                    x = dequeue();
                }
            }
            else 
            {
                printf("Kuyrruk boş ve seri port temiz\n") ;
            }
            printf("Kuyruktaki mesajların hepsi gönderildi.\n");
        }
        else if (isOnline == 'h')
        {
            enqueue(&mesaj);
            List_of_Queue();
        }
        else
        {
            printf("Lütfen (e/h) notasyonunu kullanınız.\n");
        }
    }
    return 0;
}
void enqueue(message_Node **Node)
{
    message_Node *Old_Node = *Node ;
    if (rear == NULL)
    {
        rear = (message_Node*)malloc(sizeof(message_Node));
        strcpy(rear->veri, Old_Node->veri);
        rear->adres = NULL ;
        front = rear ;
    }
    else {
        message_Node *temp = (message_Node*)malloc(sizeof(message_Node));
        rear->adres = temp ;
        strcpy(temp->veri, Old_Node->veri);
        temp->adres = NULL;
        rear = temp ;
    }
}
int dequeue()
{
    char mesaj[MAX];
    message_Node *front_Temp = front ;
    if (front_Temp == NULL)
    {
        printf("Kuyruk Boş durumdadır.\n");
        return 0 ;
    }
    else
    {
        if (front_Temp -> adres != NULL)
        {
            front_Temp = front_Temp->adres;
            printf("%s (gönderildi ++ )\n",front->veri);
            free(front);
            front = front_Temp ;
        }
        else
        {
            printf("%s (gönderildi ++ )\n",front->veri);
            free(front);
            front = NULL ;
            rear = NULL ;
            return 0;
        }
    }
}
void List_of_Queue()
{
    message_Node *front_temp = front;
    printf("Kuyruktaki mesajlar listeleniyor\n");
    if ((front_temp == NULL) && (rear == NULL))
    {
        printf("Kuyruk bos durumdadır.\n");
		return;
    }
    else {
		while(front_temp != rear) {
			printf("%s\n", front_temp -> veri);
			front_temp = front_temp -> adres;
		}
	}
    if (front_temp == rear)
    {
        printf("%s\n", front_temp->veri);
    }
}
