#include<stdio.h>
void quicksort(int number[],int first,int last)
{
   int i, j, p, t;

   if(first<last){
      p=first;
      i=first;
      j=last;

      while(i<j)
      {
         while(number[i]<=number[p]&&i<last)
            i++;
         while(number[j]>number[p])
            j--;
         if(i<j){
            t=number[i];
            number[i]=number[j];
            number[j]=t;
         }
      }

      t=number[p];
      number[p]=number[j];
      number[j]=t;
      quicksort(number,first,j-1);
      quicksort(number,j+1,last);

   }
}

int main()
{
   int i, count, number[25];

   printf("How many elements are u going to enter?: ");
   scanf("%d",&count);

   printf("Enter %d elements: ", count);
   for(i=0;i<count;i++)
      scanf("%d",&number[i]);

   quicksort(number,0,count-1);

   printf("Order of Sorted elements: ");
   for(i=0;i<count;i++)
      printf(" %d",number[i]);

   return 0;
}

