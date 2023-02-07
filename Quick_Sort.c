#include<stdio.h>
int partition(int a[20],int l,int h);
void quicksort(int a[20],int low,int high);
int main()
{
    int a[10],n,i,low,high;
    printf("Enter array size:");
    scanf("%d",&n);
    printf("Enter array elements\n");
    for(i=0; i<n; i++)
        scanf("%d",&a[i]);
    low=0,high=n-1;
    quicksort(a,low,high);
    for(i=0; i<n; i++)
        printf("%d ",a[i]);
}
void quicksort(int a[20],int low,int high)
{
    int j;
    if(low<=high)
    {
        j=partition(a,low,high);
        quicksort(a,low,j-1);
        quicksort(a,j+1,high);
    }
}
int partition(int a[20],int l,int h)
{
    int key,i,j,temp;
    key=a[l];
    i=l+1;
    j=h;
    while(i<=j)
    {
        while(i<=h&&key>=a[i])
            i++;
        while(j>l&&key<=a[j])
            j--;
        if(i<j)
        {   temp=a[i];
            a[i]=a[j];
            a[j]=temp;
        }
    }
    temp=a[j];
    a[j]=a[l];
    a[l]=temp;
    return j;
}
