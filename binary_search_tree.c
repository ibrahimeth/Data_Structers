//contributed by ibrahimeth
//Binary_Search_tree Serach Time to compare 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Binary Search Tree Node yapısı
struct Node {
    int data ;
    struct Node *Left_node ;
    struct Node *right_node ;
};

// fonksiyon tanıtımları
typedef struct Node Node ;
Node *Create_Node(int) ;
Node *insert(Node *, int);
Node *search(Node *, int);

//fonksiyonların testi için ana fonksiyonumuz
int main(void){

    Node *Root = NULL ;
    for(int i = 1 ; i <=150000; i++){
        Root = insert(Root, i);
        // printf("%d ", i);  cihazınınız üzerinden agaca eklenilen her bir elemanı görüntüleyin.
     }
    int sayi;
    while (1)
    {
        printf("Aratmak istediğiniz elemani giriniz:");
        scanf("%d",&sayi);
        if (sayi == 0)
        {
            break;
        }
        else{
            clock_t start_t, end_t ;
            start_t = clock();
            search(Root, sayi) ;
            end_t = clock();
            printf("\n%d elemanini %f saniyede bulundu.\n", sayi ,(double)(end_t - start_t)/CLOCKS_PER_SEC);
        }
    }
    return 0 ;
}

//Agac üzerindeki her bir Node'nin bellek üzerinden yer tahsis işlemi
Node *Create_Node(int Data){
    Node *Temp = (Node*)malloc(sizeof(Node));
    Temp->data = Data ;
    Temp->Left_node = Temp->right_node = NULL ;
    return Temp ;
}

//Recursive(özyinelemeli fonsiyonlarla) agaç üzerinde dolanarak agcın sonuna eleman ekliyor.
Node *insert(Node *Node, int Data){
    if (Node == NULL)
        return Create_Node(Data);
    if (Data > Node->data)
    {
        Node->right_node = insert(Node->right_node, Data);
    }
    else if(Data < Node->data){
        Node->Left_node = insert(Node->Left_node, Data);
    }
    return Node;
}
//Arama algoritması Agac üzerinde recursive olarak gezerek istenilen elemanı bulmamızı sağlıyor.
Node *search(Node* root, int key)
{
    // Base Cases: root is null or key is present at root
    if (root == NULL || root->data == key)
       return root;

    // Key is greater than root's key
    if (root->data < key)
       return search(root->right_node, key);

    // Key is smaller than root's key
    return search(root->Left_node, key);
}