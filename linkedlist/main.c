#include <stdio.h>

struct node{
    int data;
    struct node *link;
};

struct node * start=NULL;

void traverse(){
    struct node *ptr;
    ptr=start;
    if(start==NULL){
        printf("empty");
    }
    else{

    while(ptr!=NULL)
    {
        printf("%d\t",ptr->data);
        ptr=ptr->link;


    }
    }

}

void insert_at_end(int key){

    struct node * temp;
    struct node *ptr;
    ptr=start;
    temp=malloc(sizeof(struct node));

    temp->data=key;
    temp->link=NULL;

     if(start==NULL){
       start=temp;
    }else
    {

    while(ptr->link!=NULL)
    ptr=ptr->link;
    ptr->link=temp;
    }



}

void insert_at_beginning(int key){

    struct node *temp;
    temp=malloc(sizeof(struct node ));
    temp->data=key;

    temp->link=start;
    start=temp;

}

void insert_at_position(int key , int position ){
    struct node *temp;
    struct node *ptr;
    temp=malloc(sizeof(struct node ));
    ptr=start;
    int count=0;


    if(position==0)
    insert_at_beginning(key);
    else
    {
        while(ptr!=NULL){
           count++;
           if(count==position){
            temp->data=key;
            temp->link=ptr->link;
            ptr->link=temp;
            break;
           }
           ptr=ptr->link;
        }

    }
}

void delete_at_beginning(){

    struct node *ptr;
    ptr=start;

    if(start==NULL)
    {
        printf("list already empty\n");
        return;
    }
    start=start->link;
    free(ptr);

}

void delete_at_end(){

    struct node *ptr;
    ptr=start;

    if(start==NULL)
       {
            printf("list already empty\n");
        return;
       }
    if(ptr->link==NULL)
            delete_at_beginning();
            return;
    while(ptr->link->link!=NULL)
        ptr=ptr->link;
    free(ptr->link);
    ptr->link=NULL;

}

void reverse(){
    struct node *previous,*current,*next;
    current=start;
    previous=NULL;
    if(start==NULL || start->link==NULL)
        return ;
    while(current!=NULL){

        next=current->link;
        current->link=previous;
        previous=current;
        current=next;

    }
    start=previous;


}

int main() {

    int choice;
    int value;
    int pos;
    do{
    printf("\nselect the choice \n1.insert at end\n2.insert at beginning\n3.insert at a position\n4.delete at beginning\n5.delete at end\n6.display\n7.reverse the linked list");
    scanf("%d",&choice);

    switch(choice){
        case 1:

        printf("give  a value to insert at end\n ");
        scanf("%d",&value);
        insert_at_end(value);
        break;
        case 2:
        printf("give  a value to insert at beginning\n ");
        scanf("%d",&value);
        insert_at_beginning(value);
        break;
        case 3:
        printf("position after\n ");
        scanf("%d",&pos);
        printf("give  a value to insert after position %d \n ",pos);
        scanf("%d",&value);
        insert_at_position(value,pos);
        break;
        case 6:
        traverse();
        break;
        case 4:
        delete_at_beginning();
        break;
        case 5:
        delete_at_end();
        break;
        case 7:
        reverse();
        break;
        default :
        printf("invalid input \n");

    }

    }while(choice!=0);

    return 0;
}
