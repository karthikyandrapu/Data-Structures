#include<stdio.h>
void insertionsort(int a[20],int n)
{
    int i,temp,pos;
    for(i=1; i<n; i++)
    {
        temp=a[i];
        pos=i;
        while((pos>0)&&(a[pos-1]>temp))
        {   a[pos]=a[pos-1];
            pos--;
        }
        a[pos]=temp;
    }
}

int itrpsearch(int a[],int low,int high,int key)
{
    int pos;
    if(low<=high)
    {
        pos=low+((high-low)*(key-a[low])/(a[high]-a[low]));
        if(key==a[pos])
            return pos;
        else if(key<a[pos])
            return itrpsearch(a,low,pos-1,key);
        else
            return itrpsearch(a,pos+1,high,key);
    }
    return -1;
}

int main()
{
    int a[20],n,i,key,x;
    printf("Enter array size:");
    scanf("%d",&n);
    printf("Enter array elements\n");
    for(i=0; i<n; i++)
        scanf("%d",&a[i]);
    printf("Sorted list is:");
    insertionsort(a,n);
    for(i=0; i<n; i++)
        printf("%d ",a[i]);
    printf("\n");
    printf("Enter key element:");
    scanf("%d",&key);
    x=itrpsearch(a,0,n-1,key);
    if(x==-1)
        printf("Key element is not found");
    else
        printf("Key element is found at %d position",x+1);
}
