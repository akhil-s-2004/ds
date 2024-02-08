#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node*next;
};
struct node*top=0;
void PUSH(int item)
{
    struct node*newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=item;
    newnode->next=top;
    top=newnode;
}
void POP()
{
    struct node*temp;
    if(top==0)
    {
        printf("STACK UNDERFLOE!!!");
    }
    else{
        temp=top;
        top=top->next;
        free(temp);
    }
}
void DISPLAY()
{
    struct node*temp;
    if(top==0)
    {
        printf("STACK EMPTY!!!");
    }
    else{
        temp=top;
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
    printf("STACK OPERATIONS\n1.PUSH\n2.POP\n3.DISPLAY\n");
    while(ch=='y'||ch=='Y')
    {
        printf("Enter your choice: ");
        scanf("%d",&op);
        switch(op)
        {
            case 1: printf("Enter data to be pushed: ");
                    scanf("%d",&item);
                    PUSH(item);
                    break;
            case 2: POP();
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
