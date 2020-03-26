

#include<iostream>
#include<stdio.h>
#include<time.h>
#include <stdlib.h>
using namespace std;


#define ARRAYLENGTH 100
int nums1[ARRAYLENGTH];

void InsertionSort(int * nums, int arrayLength);

void MergeSort(int * nums, int p, int r);

void Merge(int * nums1, int p, int q, int r);


int main(int argc, char* argv[])
{
	for (int i = 0; i < ARRAYLENGTH; i++)
	{
		nums1[i] = rand() % 10000;
	}
	cout << "arraylength = " << ARRAYLENGTH << endl;
	cout << "Before Sorting" << endl;

	cout << endl;
	clock_t startTime1 = clock();
	InsertionSort(nums1, ARRAYLENGTH);
	clock_t endTime1 = clock();

	cout << "Running Time for Insertion Sort is " << (endTime1 - startTime1)<< endl;

	cout << endl;
	cout << "After Insertion Sorting" << endl;


	for (int i = 0; i < ARRAYLENGTH; i++)
	{
		nums1[i] = rand() % 10000;
	}
	/* for (int i = 0; i < ARRAYLENGTH; i++)
	{
		cout << nums1[i] << " ";
	}
	cout << endl; */

	clock_t startTime2 = clock();
	MergeSort(nums1, 0, ARRAYLENGTH);

	/* for (int i = 0; i < ARRAYLENGTH; i++)
	{
		cout << nums1[i] << " ";
	}
	cout << endl; */

	clock_t endTime2 = clock();
	cout << "Running Time for Merge Sort is " << (endTime2 - startTime2)<< endl;


	cout << endl;
	cout << "After Merge Sorting" << endl;
	system("pause");
	getchar();
}

void InsertionSort(int * numList, int arrayLength)
{
	int i,j,k;
	for(i=0;i<ARRAYLENGTH;i++)
	{
		for(j=i;j>0;j--)
		{
			if(numList[j]<numList[j-1])
			{
				k=numList[j];
				numList[j]=numList[j-1];
				numList[j-1]=k;
			}
		}
	}
	// your code here
}

void MergeSort(int * numList, int p, int r)
{
	int q;
    if(p<r)
	{
        q=(p+r)/2;
		MergeSort(numList,p,q);
		MergeSort(numList,q+1,r);
		Merge(numList,p,q,r);
	}
	// your code here
}

void Merge(int * nums1, int p, int q, int r)
{
	int n1 = q - p + 1;
	int n2 = r - q;
	int * nums2 = new int[n1 + 1];
	int * nums3 = new int[n2 + 1];
	int i,j,k;
	for(i=0;i<n1;i++){
        nums2[i]=nums1[p+i];
    }
    for(j=0;j<n2;j++){
        nums3[j]=nums1[q+j+1];
    }
	nums2[n1]=10000;
    nums3[n2]=10000;
    i=0;
    j=0;
    for(k=p;k<=r;k++){
        if(nums2[i]<=nums3[j]){
            nums1[k]=nums2[i++];
        }else{
            nums1[k]=nums3[j++];
        }
    }
	// your code here
}
