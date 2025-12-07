# include<stdio.h>
# include<stdlib.h>
struct Node{
    int data; 
    struct Node*left;
    struct Node*right;
};

struct Node*new(int data)
{
    struct Node*node = (struct Node*)malloc(sizeof(struct Node));
        node->data = data;
        node->left = NULL;
        node->right = NULL;
        return node;
}

void preorder(struct Node*node)
{
    if(node == NULL) return;
    printf("%d",node->data);
    preorder(node->left);
    preorder(node->right);
}

void inorder(struct Node * node)
{
    if(node == NULL) return;
    inorder(node->left);
    printf("%d",node->data);
    inorder(node->right);
}

void postorder(struct Node * node)
{
    if(node == NULL) return;
    postorder(node->left);
    postorder(node->right);
    printf("%d",node->data);
}

int main()
{
    struct Node*root = new(1);
    root->left = new(2);
    root->right = new(3);
    root->left->left = new(4);
    root->left->right = new(5);
    
    printf("\nPreorder Traverse: ");
    preorder(root);
    printf("\n");
    
    printf("\nInorder Traverse: ");
    inorder(root);
    printf("\n");

    printf("\nPostorder: ");
    postorder(root);
    printf("\n");
}