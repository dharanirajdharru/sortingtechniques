#include<stdio.h>
#define size 10 //size of the array


void printarray(int a[],int ,int);
void mergesort(int a[],int ,int ,int );
void divide(int a[],int ,int );
int main()
{
 int a[size],i;
 printf("enter 10 elements to the array");
 //collecting array elements
 for(i=0;i<size;i++)
 {
  scanf("%d",&a[i]);
  }
 divide(a,0,size-1);
 printf("the sorted elements are");
 printarray(a,0,size);
}


void divide(int arr[],int start,int end)
{
 int mid_value;
 if(start<end)
 { 
  mid_value=(start+end)/2;
  divide(arr,start,mid_value);
  divide(arr,mid_value+1,end);
  mergesort(arr,start,mid_value,end);
 }
}

void mergesort(int arr[],int l,int m,int r)
{
 int i,j,k,l1,l2;
  l1=m-l+1;       //length of temparray1
  l2=r-m;         //length of temparray2
  int L[l1],R[l2];//temporary arrays
  for (i = 0; i < l1; i++)
        L[i] = arr[l+i];
  for (j = 0; j < l2; j++)
        R[j] = arr[m + 1 + j];
  i=0;
  j=0;
  k=l;
  while (i < l1 && j < l2) 
  {
        if (L[i] <= R[j]) 
        {
            arr[k] = L[i];
            i++;
        }
        else 
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
 
    // Copy the remaining elements of L[], if there are any
    while (i < l1) 
    {
        arr[k] = L[i];
        i++;
        k++;
    }
 
    // Copy the remaining elements of R[], if there are any 
    while (j < l2) 
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}


void printarray(int a[],int start,int end)
{
 int i;
  for(i=start;i<end;i++)
  {
   printf("%d ",a[i]);
  }
 printf("\n");
}
