#include <stdio.h>
#include <stdlib.h>

  struct tree{

  struct tree *left;
  int data;
  struct tree *right;

  };
  struct tree *root=NULL;


  void insert(int x){

  struct tree *temp;
  struct tree *ptr;
  ptr=root;
  temp =malloc(sizeof(struct tree));
  temp->data=x;
  temp->left=NULL;
  temp->right=NULL;

  if(root==NULL){
        root=temp;
        return;
  }
  while(1){
    if(ptr->data<temp->data){

        if(ptr->right==NULL){
        ptr->right=temp;
        return;
        }else
         ptr=ptr->right;

  }
  if(ptr->data>temp->data){

        if(ptr->left==NULL){
        ptr->left=temp;
        return;
        }else
         ptr=ptr->left;

  }
  }
  }

  void inorder(struct tree *ptr){

      if(ptr==NULL)
        return;
      inorder(ptr->left);
      printf("%d\t",ptr->data);
      inorder(ptr->right);

  }
  void preorder(struct tree *ptr){

      if(ptr==NULL)
        return;
      printf("%d\t",ptr->data);
      preorder(ptr->left);
      preorder(ptr->right);

  }
  void postorder(struct tree *ptr){

      if(ptr==NULL)
        return;
      postorder(ptr->left);
      postorder(ptr->right);
      printf("%d\t",ptr->data);

  }

  void delete(int x){

  struct tree *ptr;
  ptr=root;
  if(ptr==NULL)
    return;

  if(ptr->left==NULL && ptr->right==NULL && ptr->data==x){
      root=NULL;
      return;
  }

  struct tree *prev=NULL;

  while(1){
  if(ptr->data>x){
    prev=ptr;
    ptr=ptr->left;
  }else if(ptr->data<x){
  prev=ptr;
  ptr=ptr->right;

  }else if (ptr->data==x){
     if(ptr->left==NULL && ptr->right==NULL) {
         if(prev->left==ptr){
        prev->left==NULL;
        free(ptr);
        return;
     }else{

       prev->right==NULL;
       free(ptr);
       return;
     }
     }else if ( ptr->left!=NULL && ptr->right==NULL)
    {
        if(prev->left==ptr){
            prev->left==ptr->left;
             free(ptr);
             return;
        }else {

          prev->right==ptr->left;
          free(ptr);
          return;
        }


    }else if ( ptr->left==NULL && ptr->right!=NULL)
    {
        if(prev->left==ptr){
            prev->left==ptr->right;
             free(ptr);
             return;
        }else {

          prev->right==ptr->right;
          free(ptr);
          return;
        }

    }

  }

  }


  }

int main()
{

    int choice;
    int value;
    do{
    printf("\nselect the choice \n1.insert \n2.inorder traverse\n3.preorder traverse\n4.postorder traverse\n5.delete a node\n");
    scanf("%d",&choice);

    switch(choice){
        case 1:
        printf("give  a value to insert \n ");
        scanf("%d",&value);
        insert(value);
        break;
        case 2:
        inorder(root);
        break;
        case 3:
        preorder(root);
        break;
        case 4:
        postorder(root);
        break;
        case 5:
        printf("give  a value to delete \n ");
        scanf("%d",&value);
        delete(value);
        break;
        default :
        printf("invalid input \n");

    }

    }while(choice!=0);



    return 0;
}
