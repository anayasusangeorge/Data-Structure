#include<stdio.h>
void main()
{
    int a,b,c,k,temp;
    printf("Enter the limit of array 1:\n");
    scanf("%d",&a);
    printf("Enter the limit of array 2:\n");
    scanf("%d",&b);
    c=a+b;
    int arr[a],arr1[b],arr2[c];
    printf("Enter the elements in array 1:\n");
    for(int i=0;i<a;i++)
    {
         scanf("%d",&arr[i]);
         arr2[i]=arr[i];
    }
    k=a;
    printf("Enter the elements in array 2:\n");

    for(int j=0;j<b;j++)
    {
         scanf("%d",&arr1[j]);
         arr2[k]=arr1[j];
         k++;
    }
    printf(" the merged array is:\n");
    for(int i=0;i<c;i++)
    {
        printf(" %d\n",arr2[i]);
    }
    printf("After sorting:\n");
    for(int i=0;i<c;i++)
    {

        for(int j=i+1;j<c;j++)
        {
            if(arr2[i]<arr2[j])
            {
                temp=arr2[i];
                arr2[i]=arr2[j];
                arr2[j]=temp;

            }
        }

    }
    for(int i=c-1;i>=0;i--)
    {
        printf(" %d",arr2[i]);
    }
}
