#include <stdio.h>
void bubblesort(int[], int);
int binarysearch(int[], int, int);
int main()
{
    int n, a[20], i, key, pos;
    printf("Enter size of the array");
    scanf("%d", &n);
    printf("Enter elements");
    for(i=0; i<n; i++)
        scanf("%d", &a[i]);
    bubblesort(a,n);
    printf("Enter key element");
    scanf("%d",&key);
    pos=binarysearch(a,n,key);
    if(pos==-1)
    {
        printf ("Entered key element is not present in the list");
    }
    else
    {
        printf("Entered element found at position %d",pos+1);
    }
}
void bubblesort(int a[], int n)
{
    int t, i, j;
    for(i=0; i<n-1; i++)
    {
        for(j=0; j<n-i-1; j++)
        {
            if (a[j]> a[j+1])
            {
                t=a[j];
                a[j]=a[j+1];
                a[j+1]=t;
            }
        }
    }
    for(i=0;i<n;i++)
    printf("%d ",a[i]);
    printf("\n");
}
int binarysearch(int a[20], int n, int key)
{
    int low, high, mid;
    low=0,high=n-1;
    while (low<=high)
    {
        mid=(low+high)/2;
        if (key==a[mid])
            return mid;
        else if(key<a[mid])
            high=mid-1;
        else
            low=mid+1;
    }
    return -1;
}
