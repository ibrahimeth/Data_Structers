
// C program to insert a node in AVL tree
#include<stdio.h>
#include<stdlib.h>
#include <time.h>
// An AVL tree node
struct Node
{
    int key;
    struct Node *left_node;
    struct Node *right_node;
    int tree_height;
};
typedef struct Node Node ;
int tree_height(Node*);
Node* newNode(int );
int max(int , int );
Node* newNode(int key);
Node *right_nodeRotate(Node *y);
Node *left_nodeRotate(Node *x);
int getBalance(Node *N);
Node* insert(Node* node, int key);
void preOrder(Node *root);
Node *search(Node* root, int key);
void findMathod(Node * root, int number);

/* Driver program to test above function*/
int main()
{
  while (1)
  {
    struct Node *root = NULL;
    clock_t start_t, end_t ;
    // preOrder(root);
    int sayi ;
    printf("\nAratmak istediğiniz elemani giriniz:");
    scanf("%d",&sayi);
    if (sayi == 0){
      break;
    }
    else {
      start_t = clock();
      for (int i = 1; i <= 10001; i++){
        root = insert(root, i);
      }
      search(root,sayi);
      end_t = clock();
      printf("\n%d eleman aratma %fsaniye", sayi,(double)(end_t - start_t)/CLOCKS_PER_SEC);
    }
  }

  return 0;
}

// A utility function to get the tree_height of the tree
int tree_height(Node *N)
{
    if (N == NULL)
        return 0;
    return N->tree_height;
}
 
// A utility function to get maximum of two integers
int max(int a, int b)
{
    return (a > b)? a : b;
}
 
/* Helper function that allocates a new node with the given key and
    NULL left_node and right_node pointers. */
Node* newNode(int key)
{
    Node* node = (Node*)
                        malloc(sizeof(Node));
    node->key   = key;
    node->left_node   = NULL;
    node->right_node  = NULL;
    node->tree_height = 1;  // new node is initially added at leaf
    return(node);
}
 
// A utility function to right_node rotate subtree rooted with y
// See the diagram given above.
Node *right_nodeRotate(Node *y)
{
    Node *x = y->left_node;
    Node *T2 = x->right_node;
 
    // Perform rotation
    x->right_node = y;
    y->left_node = T2;
 
    // Update tree_heights
    y->tree_height = max(tree_height(y->left_node),
                    tree_height(y->right_node)) + 1;
    x->tree_height = max(tree_height(x->left_node),
                    tree_height(x->right_node)) + 1;
 
    // Return new root
    return x;
}
 
// A utility function to left_node rotate subtree rooted with x
// See the diagram given above.
Node *left_nodeRotate(Node *x)
{
    Node *y = x->right_node;
    Node *T2 = y->left_node;
 
    // Perform rotation
    y->left_node = x;
    x->right_node = T2;
 
    //  Update tree_heights
    x->tree_height = max(tree_height(x->left_node),  
                    tree_height(x->right_node)) + 1;
    y->tree_height = max(tree_height(y->left_node),
                    tree_height(y->right_node)) + 1;
 
    // Return new root
    return y;
}
 
// Get Balance factor of node N
int getBalance(Node *N)
{
    if (N == NULL)
        return 0;
    return tree_height(N->left_node) - tree_height(N->right_node);
}
 
// Recursive function to insert a key in the subtree rooted
// with node and returns the new root of the subtree.
Node* insert(Node* node, int key)
{
    /* 1.  Perform the normal BST insertion */
    if (node == NULL)
        return(newNode(key));
 
    if (key < node->key)
        node->left_node  = insert(node->left_node, key);
    else if (key > node->key)
        node->right_node = insert(node->right_node, key);
    else // Equal keys are not allowed in BST
        return node;
 
    /* 2. Update tree_height of this ancestor node */
    node->tree_height = 1 + max(tree_height(node->left_node),
                        tree_height(node->right_node));
 
    /* 3. Get the balance factor of this ancestor
          node to check whether this node became
          unbalanced */
    int balance = getBalance(node);
 
    // If this node becomes unbalanced, then
    // there are 4 cases
 
    // left_node left_node Case
    if (balance > 1 && key < node->left_node->key)
        return right_nodeRotate(node);
 
    // right_node right_node Case
    if (balance < -1 && key > node->right_node->key)
        return left_nodeRotate(node);
 
    // left_node right_node Case
    if (balance > 1 && key > node->left_node->key)
    {
        node->left_node =  left_nodeRotate(node->left_node);
        return right_nodeRotate(node);
    }
 
    // right_node left_node Case
    if (balance < -1 && key < node->right_node->key)
    {
        node->right_node = right_nodeRotate(node->right_node);
        return left_nodeRotate(node);
    }
 
    /* return the (unchanged) node pointer */
    return node;
}
 
// A utility function to print preorder traversal
// of the tree.
// The function also prints tree_height of every node
void preOrder(Node *root)
{
    if(root != NULL)
    {
        printf("%d ", root->key);
        preOrder(root->left_node);
        preOrder(root->right_node);
    }
}
Node *search(Node* root, int key){
    // Base Cases: root is null or key is present at root
    if (root == NULL || root->key == key)
       return root;

    // Key is greater than root's key
    if (root->key < key)
       return search(root->right_node, key);

    // Key is smaller than root's key
    return search(root->left_node, key);
}
void findMathod(Node * root, int number)
{
  if(root == NULL)
  {
          printf("\nThe number could not found!");
          return;
  }
  else if(root -> key < number)
          findMathod(root -> right_node, number);
  else if(root -> key > number)
          findMathod(root -> left_node, number);
  else if(root -> key == number)
          printf("\nThe number found => (%d)", root->key);
}
