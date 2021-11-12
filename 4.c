#include<stdio.h>
#include<omp.h>
#include<stdlib.h>

long factorial(int n)
{
	if(n==0||n==1)
		return 1;
	long fact=1;
	for(int i=2;i<=n;i++)
		fact=fact*i;
	return fact;
}

void main()
{
	int i,n=10;
	long *x;
	x=(long*)malloc(sizeof(long)*(n+1));

	for(i=0;i<=n;i++)
		x[i]=factorial(i);

	#pragma omp parallel for firstprivate(x)
	for(i=1;i<=n;i++)
		x[i]=i*x[i-1];

	for(i=1;i<=n;i++)
		printf("Factorial(%d) = %ld x[%d]=%ld\n",i,x[i-1],i,x[i]);	
}
