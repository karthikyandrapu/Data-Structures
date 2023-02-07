#include<stdio.h>
#include<stdlib.h>
void adjust(int a[],int i,int n)
{
    int j,key;
    key=a[i];
    j=2*i;
    while(j<=n)
    {
        if(j<n && a[j]<a[j+1])
            j++;
        if(key>a[j])
            break;
        a[j/2]=a[j];
        j=2*j;
    }
    a[j/2]=key;
}
void heapify(int a[],int n)
{
    int i;
    for(i=n/2; i>=1; i--)
        adjust(a,i,n);
}
void heapsort(int a[],int n)
{
    int i,temp;
    heapify(a,n);
    for(i=n; i>=2; i--)
    {
        temp=a[i];
        a[i]=a[1];
        a[1]=temp;
        adjust(a,1,i-1);
    }
}
void main()
{
    int a[20],i,n;
    printf("Enter the size of the array:");
    scanf("%d",&n);
    printf("Enter array elements:\n");
    for(i=1; i<=n; i++)
        scanf("%d",&a[i]);
    printf("Sorted list is:");
    heapsort(a,n);
    for(i=1; i<=n; i++)
        printf("%d ",a[i]);
    printf("\n");
}
