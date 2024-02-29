#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *link;
};

struct node* rev(struct node* head){
    if(head == NULL){
        printf("The list is already empty\n");
        return NULL;
    }
    else if(head->link == NULL){
        printf("Deleting the only node in the list\n");
        free(head);
        head = NULL;
    }
    else{
        struct node*prev =NULL;
        struct node*next = NULL;
        while(head !=NULL){
            next=head->link;
            head->link=prev;
            prev = head;
            head = next;
        }
        head = prev;
    }
    return head;
}

int main(){
    struct node* head = NULL;
    struct node* current;
    int data;
    char ch;
    int n;
    scanf("%d",&n);
    printf("Do you want to enter a node (y/n)? ");
    scanf(" %c", &ch);
    for(int i=0;i<=n;i++){
        current = (struct node*) malloc(sizeof(struct node));
        printf("Enter the  data: ");
        scanf("%d", &data);
        current->data = data;
        current->link = head;
        head = current;
     
    }
    head = rev(head);
    struct node* ptr = head;
    while(ptr!=NULL){
        printf("%d ",ptr->data);
        ptr = ptr->link;
    }
    return 0;
}
