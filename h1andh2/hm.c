///////////////////////////////////////////////////////////////////////////////////////////
//   student number:
//
//    name:
//
////////////////////////////////////////////////////////////////////////////////////////////

#include "stdio.h"
#include "stdlib.h"
#define N 30
#define M 15
void getdata(int *a,int *m,int *n);//get random data
void sortdata(int *a,int n);
int delrepeat(int *a,int n);//del repeated data from array
int mergedata(int *a,int m,int n);//merge the two part of array and make array ordered and has no repeated one
void outputdata(int *a,int m);//show the array
main()
{
	int a[N],m=0,n=0;
	getdata(a,&m,&n);
        printf("the original data is:\n");
	outputdata(a,m+n);
	printf("m=%d,n=%d\n",m,n);
	m=mergedata(a,m,n);
	printf("after merge,the data is:\n");
	outputdata(a,m);
}



///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//get random data and obtain an array whose first part has m ordered elements and no repeated one, and its next part
//has n ordered elements and still no repeated one, the array is disordered in general.
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void getdata(int *a,int *m,int *n)
{
	int b[M],c[M],i;
	for(i=0;i<M;i++)
	{       // initializing 
		b[i]=rand()%20;
		c[i]=rand()%20;
	}
                 //sorting
	sortdata(b,M);
	sortdata(c,M);
                // delete repeated size may decrease and returns size of array
	*m=delrepeat(b,M);
	*n=delrepeat(c,M);
               //assigning first 
	for(i=0;i<*m;i++)
		a[i]=b[i];
	for(;i<(*m+*n);i++)
		a[i]=c[i-*m];
          
          
}
// a is array n is size of array
void sortdata(int *a,int n)
{
	int i=n-1,j,lastindex,t;
	while(i>0)
	{
		lastindex=0;
		for(j=0;j<i;j++)
		{
			if(a[j]>a[j+1])
			{     //bubble sort
				lastindex=j;
				t=a[j];
				a[j]=a[j+1];
				a[j+1]=t;
			}
		}
		i=lastindex;
	}
}
int delrepeat(int *a,int n)//remove the repeated one from the array and return the length of array
{
	int i,k;
	for(i=1,k=1;i<n;i++)
	{
		if(a[i]!=a[i-1])
		{
			a[k]=a[i];
			k++;
		}
	}
	return k;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//now the array is only locally ordered in its two part. Please merge this two ordered parts together and make the array ordered in  
//general.The array can not have any repeated one after merge.
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int mergedata(int *a,int m,int n)
//a is array and m is... and n is ...
{
int k,i=0;
sortdata(a,m+n);
k=delrepeat(a,m+n);
return k;
}
void outputdata(int *a,int m)//show the array
{
	int i;
	for(i=0;i<m;i++)
		printf("%4d",a[i]);
	printf("\n");
}
