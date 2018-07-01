#include <stdio.h>

void myswap(int* x, int* y);

int main()
{
	int array[] = {5,4,2,1,8,10,23,6};
	int i = 0;
	int j = 0;
	for(i=0;i<7;i++)
	{
		for(j=0;j<7-i;j++)
		{
			if(array[j] > array[j+1])
				myswap(array+j,array+j+1);
		}
	}
	for(i = 0; i<8;i++)
	{
		printf("%d\n",array[i]);
	}
	return 0;
}

void myswap(int* x, int* y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}