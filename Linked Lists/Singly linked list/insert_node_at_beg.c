#include<stdio.h>
#include<stdlib.h>

/* it is very easy to insert node at beginning
you need to:
1) create a linked list
2) make the first node of the linked list linked to the new node
3) Remove the head from the original first node
4) make the new node as the head of the linked list
*/

// Creating a linked list
struct Node 
{
    int data;
    struct Node* next;
};

void push(struct Node** head_ref, int new_data)
{
    // allocate node
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data=new_data;
    new_node->next=(*head_ref);
    (*head_ref)=new_node;
}

int main()
{
    typedef struct Node NODE;
    NODE *head, *first, *temp;
    int count=0;
    int choice=1;
    first=NULL;
    while(choice)
    {
        head = (NODE*)malloc(sizeof(NODE));
        printf("enter data");
        scanf("%d",&head->data);
    
        if(first!=NULL)
        {
            temp->next=head;
            temp=head;
        }
        else
        {
            first=temp=head;
        }
        printf("do you want to continue\n0 to stop\n1 to continue");
        scanf("%d",&choice);

    }
        temp->next=NULL;
        temp=first;
        printf("status of linked list is:");
        while(temp!=NULL)
        {
            printf("%d->",temp->data);
            count++;
            temp = temp->next;
        }
        printf("NULL\n");
        printf("No. of nodes in the list is %d",count);

}    



