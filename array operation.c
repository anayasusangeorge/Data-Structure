
#include <stdio.h>
#include <stdlib.h>
void  main()
{
   int a[100], i, x, pos, n, c;
    printf("  enter the number of elements:\n");
    scanf("%d",&n);
    printf("\n enter the elements: \n");
    for (i=0; i< n; i++)
        scanf("%d",&a[i]);
        while(1)
    {
      printf("\n Enter the choice\n 1.Traversal\n 2.Insertion\n 3.Deletion\n 4.Searching\n 0. Exit\n ");
     scanf("%d",&c);
      switch(c)
      {
            case 1 : traversal(a,n);
                    break;
            case 2 :insertion(a,n);
                    break;
            case 3 : deletion(a,n);
                     break;
            case 4 : search(a,n);
                    break;
            case 0 : exit(0);

               default : printf(" wrong input\n");
                         break;

                }
        }
    }


    void traversal(int a[100],int n)
    {
        int i;
            printf(" \n the elements are: \n");
            for (int i = 0; i < n; i++)
            {
                printf("%d\n ", a[i]);
            }
        }
    void insertion(int a[100],int n)
    {
       int i,x,pos =n ;
            printf("enter the elements to be insert:\n");
            scanf("%d",&x);

            for(i=0;i<n;i++)
            {
                printf("%d--",a[i]);
            }
            printf("\n");
            printf("enter the position of the element to insert\n");
            scanf("%d",&pos);
            n++;
            for (i = n-1; i >= pos; i--)
            {
                a[i+1] = a[i];
                a[pos - 1] = x;
            printf("the  resultant array is \n\n");
            for (i = 0; i < n; i++)
                printf(" %d \n",a[i]);
            }

}

void deletion(int a[100],int n)
{
    int i,x,pos=n ;
    printf("Enter the position where you wish to delete element:\n");
   scanf("%d", &pos);

   if (pos >= n+1)
      printf("Deletion not possible.\n");
   else
   {
      for (i = pos - 1; i < n - 1; i++)
      {
         a[i] = a[i+1];
      }
      printf("Resultant array:\n");

      for (i = 0; i < n - 1; i++)
      {
        printf("%d\t",a[i]);
      }

   }
}

void search(int a[100],int n)
{
    int i,item,flag ;

        printf("\n enter the elements to be searched\n");
        scanf("%d",&item);
        for(i=0;i<=n;i++)
        {
            if(a[i]==item)

                flag=i;
        }
        if(flag!=0)
             printf("\n the he element %d is found at position %d\n",item,flag);
        else
            printf("not found");
}
