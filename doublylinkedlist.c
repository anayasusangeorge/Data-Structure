
  #include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
    struct node *prev;
};
struct node *head=NULL;
struct node *next;
struct node *prev;
void traversal();
void display();
void insert();
void delet();
void search();
int choice,a;
void beg()
{

            int value;
            printf("\n enter the value\n");
            scanf("%d",&value);
            struct node *newNode;
            newNode = (struct node *)malloc(sizeof(struct node*));
            newNode->data = value;
            newNode->next = head;
            newNode->prev=NULL;
            head= newNode;
            printf("\n value inserted\n");

}
void end()
{
    if(head==NULL)
    {
        beg();
    }
    else
        {
            int value;
            printf("\n enter the value\n");
            scanf("%d",&value);
            struct node *newNode;
            newNode = (struct node *)malloc(sizeof(struct node*));
            newNode->data = value;
            newNode->next = NULL;
            newNode->prev=NULL;

            struct node *temp = head;
            while(temp->next != NULL){
                temp = temp->next;
            }
             temp->next = newNode;
             newNode->prev=temp;
             printf("\n value inserted\n");}
}
void pos()
{

//if(head==NULL&&head->next==NULL)
//{
    //printf("\n insertion at [position is not possible please choose begning or end\n");
//}
//else{

            int value;
            printf("\n enter the value\n");
            scanf("%d",&value);
            struct node *newNode;
            newNode = (struct node *)malloc(sizeof(struct node*));
            newNode->data = value;
            newNode->next=NULL;
            newNode->prev=NULL;
            int position;

            struct node *temp = head;
            struct node *temp1;
            printf("\n enter the position\n");
            scanf("%d",&position);

            for(int i=2; i < position; i++) {
                if(temp->next != NULL) {
                    temp = temp->next;

                }
            }
            temp1=temp->next;
            temp->next=newNode;
            newNode->next = temp1;
            temp1->prev=newNode;
            newNode->prev=temp;
            printf("\n value inserted\n");

}
//}

void delbeg()
{
    head = head->next;
    head->prev=NULL;
    printf("\n node deleted\n");

}
void delend()
{
    struct node *temp = head;
    struct node *temp1;
    while(temp->next->next!=NULL)
        {
            temp = temp->next;
        }
    temp1=temp->next;
    temp->next = NULL;
    temp1->prev=NULL;
    free(temp1);
    printf("\n deleted sucessfully\n");

}
void delpos()
{
    struct node *ptr, *temp;
    int val;
    printf("\n Enter the previous node data which the next node is to be deleted:\n ");
    scanf("%d", &val);
    ptr = head;
    while(ptr -> data != val)
    ptr = ptr -> next;
    if(ptr -> next == NULL)
    {
        printf("\nCan't delete\n");
    }
    else if(ptr -> next -> next == NULL)
    {
        ptr ->next = NULL;
    }
    else
    {
        temp = ptr -> next;
        ptr -> next = temp -> next;
        temp -> next -> prev = ptr;
        free(temp);
        printf("\nnode deleted\n");
    }
}

void main()
          {

while(1)
{


              printf("\n choose an operation from below\n\t1.display\n\t2.insertion\n\t3.deletion\n\t4.search\n\t5.exit\n");
              scanf("%d",&choice);


                switch(choice)
              {
                  case 1: traversal();
                            break;
                  case 2: insert();
                            break;
                  case 3: delet();
                            break;
                  case 4: search();
                  break;
                  case 5: exit(0);
                  break;

                  default: printf("\nwrong input\n");
              }

          }
          }
    void traversal()
    {
        if(head==NULL)
        {
            printf("\n list is enmpty\n");

        }
        else{

            struct node *temp = head;
            printf("\n\nList elements are - \n");
            while(temp != NULL) {
            printf("%d --->",temp->data);
            temp = temp->next;
    }printf("NULL");}
    }
    void insert()
    {
        //int d;
        printf("choose one\n\t1.at beg\n\t2.at end\n\t3.at posiotion\n");
        scanf("%d",&a);

        switch(a)
        {

        case 1:beg();
        break;
        case 2:end();
        break;
        case 3:pos();
            break;
        default: printf("wrong\n");
        }
    }
    void delet()
    {
         printf("choose one\ndeletion\n\t1.at beg\n\t2.at end\n\t3.at posiotion\n");
        scanf("%d",&a);

        switch(a)
        {

        case 1:delbeg();
        break;
        case 2:delend();
        break;
        case 3:delpos();
            break;
        default: printf("wrong\n");
        }
    }
void search()
{
    int ele,flag=0;
    struct node *temp = head;
    traversal();
    printf("\n enter the element to be searched\n");
    scanf("%d",&ele);
    while(temp!=NULL)
    {
        if(temp->data==ele)
        {
            flag=1;
        }
        temp=temp->next;
    }
    if(flag==1)
        {
            printf("\n element found");

        }
    else
        {
            printf("\nnot found\n");
        }

}

