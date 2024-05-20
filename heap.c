#include <stdio.h>
#include <stdlib.h>
#include <math.h>
typedef struct Tree{
    int* arr;
    int size;
}Tree;
Tree* create_tree(){
    Tree* temp = (Tree*)malloc(sizeof(Tree));
    temp->arr = (int*)malloc(sizeof(int));
    temp->size = 0;
    return temp;
}
void swap(Tree* tree, int child, int parent){
    tree->arr[child] = tree->arr[child] + tree->arr[parent];
    tree->arr[parent] = tree->arr[child] - tree->arr[parent];
    tree->arr[child] = tree->arr[child] - tree->arr[parent];
}
void heapify(Tree* tree){
    int i = tree->size-1;
    while(i > 0 && tree->arr[i] > tree->arr[(i-1)/2]){
        int parent = (i-1)/2;
        swap(tree, i, parent);
        i = parent;
    }

}
void increase_size(Tree* tree){
    tree->arr = (int*)realloc(tree->arr, sizeof(int)*(tree->size+1));
}
void printheap(Tree* tree){
    printf("arr- ");
    for (int i=0; i < tree->size; i++){
        printf("%d, ",tree->arr[i]);
    }
    printf("\n");
    
}
void insert_node(Tree* tree, int value){
    increase_size(tree);    
    tree->arr[tree->size++] = value;
    heapify(tree);
    printheap(tree);

}

void inorder(Tree* tree, int index){
    if (index < tree->size){
        inorder(tree, index*2+1);
        printf("%d ", tree->arr[index]);
        inorder(tree, index*2+2);
    }
}
void preorder(Tree* tree, int index){
    if (index < tree->size){
        printf("%d ", tree->arr[index]);
        preorder(tree, index*2+1);
        preorder(tree, index*2+2);
    }
}
void postorder(Tree* tree, int index){
    if (index < tree->size){
        postorder(tree, index*2+1);
        postorder(tree, index*2+2);
        printf("%d ", tree->arr[index]);
    }
}



int main(){
    Tree* tree = create_tree(0);
    insert_node(tree, 3);
    insert_node(tree, 17);
    insert_node(tree, 12);
    insert_node(tree, 6);
    insert_node(tree, 15);
    insert_node(tree, 19);
    insert_node(tree, 18);
    insert_node(tree, 21);

   /*
    int n;
    printf("enter number of data: ");
    scanf("%d", &n);
    int data;
    for (int i=0; i < n; i++){
        printf("enter data: ");
        scanf("%d", &data);
        insert_node(tree, data);
    }*/
    printheap(tree);
    printf("inorder traversal\n");
    inorder(tree,0);
    printf("\n");
    printf("preorder traversal\n");
    preorder(tree, 0);
    printf("\n");
    printf("postorder traversal\n");
    postorder(tree, 0);
    printf("\n");
    free(tree->arr);
    free(tree);
}
