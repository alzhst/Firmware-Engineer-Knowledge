#include <stdio.h>

int swap(int* x, int* y);
int bubblesort(int* array , int len);
int selectsort(int* array , int len);
int insertsort(int* array , int len);
int shellsort(int *array,int len);
int mergesort(int *array,int len);
int quicksort(int *array,int len);
int heapsort(int *array,int len);

int main()
{
	int i = 0;
	int array[] = {18,3,2,134,4,32,213,43,23,-234};
	int len = sizeof(array)/sizeof(int);
	heapsort(array,len);
	for (i = 0; i < len; i++)
	{
		printf("%d ",array[i]);
	}
	printf("\n");
	return 0;
}
 
//交换函数
int swap(int* x, int* y)
{
	if(x == NULL || y == NULL)
	{
		return -1;
	}
	int temp = *x;
	*x = *y;
	*y = temp;
	return 0;
}

//冒泡排序
int bubblesort(int* array , int len)
{
	int i = 0;
	int j = 0;
	int flag = 1;
	if(array == NULL)
	{
		return -1;
	}
	for(i = 0;i < len -1 && flag; i++)
	{
		flag = 0;
		for(j = 0; j <len-1-i;j++)
		{
			if(array[j] > array[j+1])
			{
				flag = 1;
				swap(array+j,array+j+1);
			}
		}
	}
	return 0;
}

//选择排序
int selectsort(int* array , int len)
{
	int i = 0;
	int j = 0;
	if(array == NULL)
	{
		return -1;
	}
	for(i = 0;i < len -1; i++)
	{
		int min = i;
		for(j = i+1; j < len; j++)
		{
			if(array[j] < array[min])
			{
				min = j;
			}
		}
		swap(array+i,array+min);
	}
	return 0;
}

//插入排序
int insertsort(int* array , int len)
{
	int i = 0;
	int j = 0;
	if(array == NULL)
	{
		return -1;
	}
	for(i = 0; i < len; i++)
	{
		int pre = i - 1;
		int current = array[i];
		while(pre >= 0 && current < array[pre])
		{
			array[pre+1] = array[pre];
			pre--;
		}
		array[pre+1] = current;
	}
	return 0;
}

//希尔排序 缩小增量的插入排序
int shellsort(int *array,int len)
{
    int gap = 0;
    int i = 0;
    int j = 0;
	int k = 0;
	int current = 0;
    for(gap = len / 2;gap > 0;gap /= 2)
    {
        for(i = 0; i < gap; i++)
        {
            for(j = gap + i; j < len; j += gap)
            {
                current = array[j];
                k = j - gap;
                while(k >= 0 && current < array[k])
                {
                    array[k+gap] = array[k];
                    k -= gap;
                }
                array[k+gap] = current;
            }
        }
    }
    return 0;
}

//将两个有序序列合并
void mergearray(int* a,int first,int mid,int last,int *temp)
{
	int k = 0;
	int i = first;
	int j = mid+1;
	while(i <= mid && j<=last)
	{
		if(a[i] < a[j])
			temp[k++] = a[i++];
		else
			temp[k++] = a[j++];
	}
	while(i <= mid)
		temp[k++] = a[i++];
	while(j <= last)
		temp[k++] = a[j++];
	for(i = 0 ;i < k;i++)
		a[first+i] = temp[i];
}

int msort(int *a,int first,int last,int *temp)
{
	if(first < last)
	{
		int mid = (last+first)/2;
		msort(a,first,mid,temp);
		msort(a,mid+1,last,temp);
		mergearray(a,first,mid,last,temp);
	}
}

//归并排序
int mergesort(int *array,int len)
{
	int temp[len];
	msort(array,0,len,temp);
}



int qsort(int *array,int first,int last)
{
	if(first < last)
	{
		int i = first ;
		int j = last;
		int temp = array[first];
		while(i<j)
		{
			while(array[j] > temp && i < j)
				j--;
			if(i < j)
			{
				array[i++] = array[j];
			}
			while(array[i] < temp && i < j)
				i++;
			if(i < j)
			{
				array[j--] = array[i];
			}
		}
		array[i] = temp;
		qsort(array,first,i-1);
		qsort(array,i+1,last);
	}
}

//快速排序
int quicksort(int *array,int len)
{
	qsort(array,0,len);
}

void heapdowm(int* array,int i,int n)
{
    int j = 2*i+1;
    int temp = array[i];
    while(j < n)
    {
        if(j+1 < n && array[j] > array[j+1])
            j++;
        if(temp < array[j])
            break;
        array[i] = array[j];
        i = j;
        j = j*2+1;
    }
    array[i] = temp;
}

int heapsort(int * array,int len)
{
    //得到堆数组
    for(int i = (len-1)/2; i>=0;i--)
    {
        heapdowm(array,i,len);
    }
    //堆排序
    for(int i = len-1;i>0;i--)
    {
        swap(array,array+i);
        heapdowm(array,0,i);
    }
	return 0;
}






