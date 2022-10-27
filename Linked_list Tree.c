#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int Data ;
    struct Node *Locc ;                                //Declare Data Struct
};
typedef struct Node Node ;
void combine_Node(int, Node**);
void printfNodeALL(int);
void Compan(int);
Node *Node_Creat(int);
Node *FirstNode = NULL ;
Node *SecondNode = NULL ;                           //max 3 Node Chains
Node *ThirdNode = NULL ;
int main(void)
{
    int chains_piece, chains_link, info, j, i, queue, m;
    while (1)
    {
        printf("how many chains do you want to create >>");
        scanf("%d",&chains_piece);
        if (chains_piece > 3 )
        {
            printf("chain length cannot exceed 3cm\n");
        }
        if ((chains_piece < 4) && (chains_piece > 0) )
        {
            break;
        }
    }
    printf("How many links are there in each chain?>>");
    scanf("%d",&chains_link);
    for (i = 1 ; i <= chains_piece; i++)
    {
        printf("%d zinciri için %d sayıda veri giriniz >>\n", i, chains_link);
        for (j = 0; j < chains_link; j++)
        {
            scanf("%d", &info);
            switch (i)
            {
            case 1 :
                combine_Node(info, &FirstNode);
                break;
            case 2 :
                combine_Node(info, &SecondNode);
                break;
            case 3 :
                combine_Node(info, &ThirdNode);
                break;
            }
        }
    }
    printf("Hangi sırada zincirleri bastıralım ? >> ");
    for (m= 1; m <= chains_piece; m++)
    {
        scanf("%d", &queue);
        printfNodeALL(queue);
    }
    return 0;
}
void combine_Node(int info, Node **Begg)
{
    Node* lladd = Node_Creat(info);
    if (*Begg == NULL)
    {
        *Begg = lladd ;
    }
    else if(*Begg != NULL)
    {
        Node *Temp = *Begg ;
        while (Temp->Locc != NULL)
        {
            Temp = Temp->Locc ;
        }
        Temp -> Locc = lladd ;
    }
}
Node *Node_Creat(int info)
{
    Node *New_Node = (Node*)malloc(sizeof(Node));
    New_Node -> Data = info;
    New_Node -> Locc = NULL ;
    return New_Node ;
}
void printfNodeALL(int queue)
{
    Node *main ;
    switch (queue)
    {
    case 1 :
        main = FirstNode ;
        break;
    case 2 :
        main = SecondNode ;
        break;
    case 3 :
        main = ThirdNode ;
        break;
    default:
        break;
    }
    Node *temp = main ;
    while (temp != NULL)
    {
        printf("-> %d\n", temp->Data);
        temp = temp->Locc;
    }
}