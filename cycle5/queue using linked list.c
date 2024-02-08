#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node*next;
};
struct node*f=0;
struct node*r=0;
void ENQUEUE(int item)
{
    struct node*newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=item;
    newnode->next=0;
    if(f==0&&r==0)
    {
        f=r=newnode;
    }
    else
    {
        r->next=newnode;
        r=newnode;
    }
}
void DEQUEUE()
{
    struct node*temp;
    if(f==0)
    {
        printf("QUEUE UNDERFLOW!!!");
    }
    else{
        temp=f;
        printf("Dequeued element is: %d",f->data);
        f=f->next;
        free(temp);
    }
}
void DISPLAY()
{
    struct node*temp;
    if(f==0)
    {
        printf("QUEUE EMPTY!!!");
    }
    else{
        temp=f;
        while(temp!=0)
        {
            printf("%d",temp->data);
            temp=temp->next;
        }
    }
}
void main()
{
    int op,item;
    char ch='y';
    printf("QUEUE OPERATIONS\n1.ENQUEUE\n2.DEQUEUE\n3.DISPLAY\n");
    while(ch=='y'||ch=='Y')
    {
        printf("Enter your choice: ");
        scanf("%d",&op);
        switch(op)
        {
            case 1: printf("Enter data to be enqueued: ");
                    scanf("%d",&item);
                    ENQUEUE(item);
                    break;
            case 2: DEQUEUE();
                    break;
            case 3: DISPLAY();
                    break;
            default:
                    printf("Wrong Entry!!!");
                    break;
        }
        printf("Do you want to continue: ");
        scanf("%s",&ch);
    }
}
