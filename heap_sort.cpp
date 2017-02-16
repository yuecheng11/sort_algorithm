#include <iostream>
using namespace std;
//#define SIZE 10
void print(int *arr,int len)
{
	for(int i = 0;i < len;i++)
	{
		cout<<i+1<<" : "<<arr[i]<<endl;
	}

	cout<<endl<<endl;
}

void heapAjust(int *arr,int s,int m)
{
	int temp,j;
	temp = arr[s];

	//m's maxsize = lenth -1
	for(j = s*2 + 1;j < m - 1;j= (j*2 + 1))
	{
	    if(j<m - 1 && arr[j]<arr[j+1])
	    {
	    	++j;
	    }
		if(temp >= arr[j])
		{
			break;
		}
		arr[s] = arr[j];
		s = j;
	}
	cout<<"s : "<<s<<endl;
	arr[s] = temp;
}

void swap(int *arr, int i,int j)
{
	int temp;
	temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}

void heap_sort(int *arr,int lenth)
{
	int i;
	//build maxheap
	//   0<=i<=(lenth-1)/2
	for(i = (lenth - 2)/2; i >= 0 ; i--)
	{
		heapAjust(arr,i,lenth);
		
		cout<<endl;
	}

	cout<<"after 1stheapsort sort: "<<endl;
	print(arr,lenth);
		
	for(i = lenth;i>1;i--)
	{
		swap(arr,0,i -1);
		heapAjust(arr,0,i - 1);
	}

	if(arr[0]>arr[i])
	{
		int temp;
		temp = arr[0];
		arr[0] = arr[1];
		arr[1] = temp;
	}
	/*
	if(i= 0)
	{
		arr[i]
	}
	*/
}
int main()
{
	int arr[9] = {50,10,90,30,70,40,80,60,20};
	int len = sizeof(arr)/sizeof(arr[0]);
	cout<<"len: "<<len<<endl;
	cout<<"print arr"<<endl;
	print(arr,len);

	//len = arr size
	heap_sort(arr,len);
	cout<<"after heap sort"<<endl;
	print(arr,len);

	cout<<endl;
	cout<<"sort end"<<endl;
	return 0;
}
