#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *link;
};

struct node* del(struct node* head){
    if(head == NULL){
        printf("The list is already empty\n");
        return NULL;
    }
    else{
        struct node* temp = head;
        head = head->link;
        free(temp);
        temp = NULL;
    }
    return head;
}

int main(){
    struct node* head = NULL;
    struct node* current;
    int n ;
    printf("Enter the no. of numbers in linked list: ");
    scanf("%d",&n);
    int data;
    char ch;
    printf("Do you want to enter a node (y/n)? ");
    scanf(" %c", &ch);
    for(int i=0;i<=n;i++){
        current = (struct node*) malloc(sizeof(struct node));
        printf("Enter the data: ");
        scanf("%d", &data);
        current->data = data;
        current->link = head;
        head = current;
    }
    head = del(head);
    struct node* ptr = head;
    
    while(ptr!=NULL){
        printf("%d ",ptr->data);
        ptr = ptr->link;
    }
    return 0;
}
