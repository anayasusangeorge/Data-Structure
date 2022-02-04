#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node*next;
}*top=NULL;
void push(int);
void pop();
void display();
void main()
{
    int val,choice;
    while(1)
    {

      printf("\n 1.push\n 2.pop\n 3.display\n");
      printf("\nEnter the choice:");
      scanf("%d",&choice);
      switch(choice)
      {

         case 1: printf("enter the value to be inserted:");
                 scanf("%d",&val);
                 push(val);
                 display();
                 break;
         case 2:
                pop();
                display();
                break;
         case 3:display();
                break;
         printf("\n Exit \n");
      }
    }
}

void push(int val)
{
    struct node*newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=val;

    if(top==NULL)
    {
        newnode->next=NULL;
        top=newnode;
    }
    else
    {
        newnode->next=top;
        top=newnode;
    }
}

void pop()
{

    if(top==NULL)
    {
        printf("Empty stack");
    }
    else
    {
        struct node*temp;
        temp=top;

            top=temp->next;
            free(temp);

    }
}
void display()
{
    if(top==NULL)
    {
        printf(" \n Stack is empty\n");
    }
    else
    {
        struct node*temp;
        temp=top;
        while(temp->next!=NULL)
        {
            printf("%d--->",temp->data);
            temp=temp->next;
        }
        printf("%d-->NULL",temp->data);
    }
}
