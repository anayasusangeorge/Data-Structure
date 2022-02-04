#include<stdio.h>
#include<stdlib.h>

#define max 5

int cq[max],rear=-1,front=-1;

void enque(int n)
{
	if(front==(rear+1)%max)
		printf("Circular Queue is Full !....");
	else if(front==-1 && rear==-1)
	{
		front=0;
		rear=0;
		cq[rear]=n;
	}
	else
	{
		rear=(rear+1)%max;
		cq[rear]=n;
	}
}

void deque()
{
	if(front==-1)
		printf("\nCircular Queue is Empty !....");
	else
	{
		printf("\nThe deleted Element is %d ",cq[front]);
		if(front==rear)
		{
			front=-1;
			rear=-1;
		}
		else
			front=(front+1)%max;
	}
}

void display()
{
	int f;
	if(front==-1)
		printf("\nCircular Queue is Empty !....");
	else
	{
		printf("\nQueue contents :  ");
		if(front<=rear)
		{
			f=front;
			while(f<=rear)
			{
				printf("%3d",cq[f]);
				f++;
			}
		}
		else if(rear<front)
		{
			f=front;
			while(f<max)
			{
				printf("%3d",cq[f]);
				f++;
			}
			f=0;
			while(f<=rear)
	{
				printf("%3d",cq[f]);
				f++;
			}
		}
	}
}
void search()
{
    int f=front;
    if(front==-1)
		printf("\nCircular Queue is Empty !....");
	else
	{
	    int ele,flag;
	    printf("\n enter the element to be searched\n");
	    scanf("%d",&ele);
	    /*while(f!=rear)
        {
            if(f==ele)
            {
                flag=1;
            }
            else
            {
                flag=0;
            }
            front++;

        }
        for(int i=0;i<max;i++)
        {
            if(f==ele)
            {
                flag=1;
            }
            else
            {
                flag=0;
            }
            f++;
        }
        */
	for (int i=0;i<rear;i++)
    {
        for(f=front;f<rear;f++)
        {
            if(cq[f]==ele)
            {
                flag=1;
            }
            else
            {
                flag=0;
            }
        }
    }
    if(flag==1)
        {
            printf("\n element found\n");

        }
        else
        {
            printf("\nnot found\n");
        }

	}
}

void main()
{
	int ch,n;

	while(1)
	{
printf("\n1.Insertion\n2.Deletion\n3.Display\n4.search\n5.exit/nEnter your choice\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: if(front==(rear+1)%max)
					printf("Circular Queue is Full !....");
					else
					{
					printf("\nEnter the number to be inserted : ");
						scanf("%d",&n);
						enque(n);
						printf("\n value inserted\n");
					}
					break;
			case 2:	deque();
					break;
			case 3:	display();
					break;
			case 4:search();
			break;
			case 5: exit(0);
			break;
			default:printf("\n wrong input\n");
		}
	}
}
