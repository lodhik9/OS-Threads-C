#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int arr[1000];



void * MyThreadFunc(void * arg)
{
        	int *start=NULL;
       		int *sum=NULL;

		start= (int *)arg;
		for(int i=0;i<100;i++)
		{
		sum=sum+arr[*start];
		start++;
		}
		return (void*)sum;
}

int main(){

       void* val[10];

   pthread_t arrOfThreads[10];
	int *sum2=NULL;
	int m=0;
    int *ptr2=NULL;
	for(int k=1;k<=1000;k++)
	{
	    arr[m]=m;
		m++;
	}



   for(int i=0;i<10;i++)
   {
        *ptr2=i*100;
        pthread_create(arrOfThreads[i] ,NULL,MyThreadFunc, (void*)(ptr2));
   }
   for(int j=0;j<10;j++)
   {
        pthread_join(arrOfThreads[j] , &val[j]);
   }


   for(int k=0;k<10;k++)
   {

        sum2=val[k];
        printf("%d",*sum2);
   }




   printf("Exiting the main function.\n");
   return 0;
   }
