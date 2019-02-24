#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

struct dir{
    int data;
    struct dir* left;
    struct dir* right;
};

struct dir* newDir(int data){

    struct dir* dir = (struct dir*)malloc(sizeof(struct dir));
    dir->data = data;
    dir->left = NULL;
    dir->right = NULL;

    return(dir);
}

void printDir(struct dir* root){
    if (root != NULL){
        printDir(root->left);
        printf("%d\n",root->data);
        printDir(root->right);
    }
}

struct dir* insert(struct dir* dir, int data){

    if (dir == NULL) {
        printf("Number inserted\n");
        return newDir(data);
    }

    if(dir->data < data)
        dir->left = insert(dir->left,data);
    else if(dir->data > data)
        dir->right = insert(dir->right,data);
    else if (dir->data == data) printf("Value already exist\n");

    return dir;
}

struct dir* searchDir(struct dir* dir, int data){
    while(dir->data != data){
	
      if(dir != NULL) {
         printf("\n%d \n",dir->data);
			
         //go to left tree
         if(dir->data < data){
            dir = dir->left;
         }  //else go to right tree
         else {                
            dir = dir->right;
         }
			
         //not found
         if(dir == NULL){
            return NULL;
         }
      }			
   }
   return dir;
}

bool isNum(char* string){
    int length;
    length = strlen(string);
    for (int i=0;i<length-1; i++)
        if (!isdigit(string[i]))
        {
            printf ("Entered input is not a number\n");
            return false;
        }
     return true;
}

int main()
{
    struct dir *root = NULL;
    struct dir *node = NULL;
    root = insert(root,50);
    insert(root,80);
    insert(root,90);
    insert(root,70);
    insert(root,10);
    insert(root,120);
    insert(root,40);

    printDir(root);

    printf("\n\n\n");

    char command[256];
    int i = 1;

    while(i != 0){
        printf("Type your command:\n");
        fgets(command, sizeof(command), stdin);

         if (strcmp(command, "insert\n") == 0) {
             printf("Type the number:\n");
             fgets(command, sizeof(command), stdin);
             if(!isNum(command)){
                 printf("Only numbers here!\n");
             } else {
                 int num = atoi(command);
                 (insert(root,num));
             }
        } else if(strcmp(command,"show\n") == 0){
            printf("Lista de números:\n");
            printDir(root);
        } else if(strcmp(command, "exit\n") == 0){
            printf("Fechando console\n");
            i = 0;
        } else if(strcmp(command, "search\n") == 0){
            printf("Type the number:\n");
             fgets(command, sizeof(command), stdin);
             if(!isNum(command)){
                 printf("Only numbers here!\n");
             } else {
                 int num = atoi(command);
                 node = searchDir(root, num); 
                 if (node == NULL) printf("Ué?\n");
                 else printf("Achei o %d\n",node->data);
             }
        } else printf("Comando não encontrado\n");
    }
    
    return 0;
}