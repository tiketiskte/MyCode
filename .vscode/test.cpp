

#include<iostream>
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
using namespace std;


#define ARRAYLENGTH 40
#define INF 0x3f3f3f3f

void InsertionSort(int * nums, int arrayLength);

void MergeSort(int * nums, int p, int r);

void Merge(int * nums1, int p, int q, int r);


int main(int argc, char* argv[])
{
	int nums1[ARRAYLENGTH];

	for (int i = 0; i < ARRAYLENGTH; i++)
	{
		nums1[i] = rand() % 10000;
	}
	cout << "arraylength = " << ARRAYLENGTH << endl;
	cout << "Before Sorting" << endl;
	for (int i = 0; i < ARRAYLENGTH; i++)
	{
		cout << nums1[i] << "\t";
	}
	cout << endl;

	clock_t startTime1 = clock();
	InsertionSort(nums1, ARRAYLENGTH);
	clock_t endTime1 = clock();

	cout << "Running Time for Insertion Sort is " << (endTime1 - startTime1) / 1000 << endl;
	for (int i = 0; i < ARRAYLENGTH; i++)
	{
		cout << nums1[i] << "\t";
	}
	cout << endl;
	cout << "After Insertion Sorting" << endl;


	for (int i = 0; i < ARRAYLENGTH; i++)
	{
		nums1[i] = rand() % 10000;
	}

	clock_t startTime2 = clock();
	MergeSort(nums1, 0, ARRAYLENGTH);

	clock_t endTime2 = clock();
	cout << "Running Time for Merge Sort is " << (endTime1 - startTime1) / 1000 << endl;

	for (int i = 0; i < ARRAYLENGTH; i++)
	{
		cout << nums1[i] << "\t";
	}
	cout << endl;
	cout << "After Merge Sorting" << endl;
	system("pause");
	getchar();
}

void InsertionSort(int * numList, int numListrrnumListyLength)
{
	// your code here
}

void MergeSort(int Array[], int p, int r)
{
    // your code here
    if(p < r)
    {
        int q = (p + r) / 2;
        MergeSort(Array, p, q);
        MergeSort(Array, q+1, r);
        Merge(Array,p, q, r);
    }
}

void Merge(int Array[], int p, int q, int r)
{
    // your code here
    int i, j, k;
    int n1 = q - p + 1;
    int n2 = r - q;
    int *L = new int[n1 + 1];
    int *R = new int[n2 + 1];
    for(i = 0; i < n1; i++)
        L[i] = Array[i + p];
    for(j = 0; j < n2; j++)
        R[j] = Array[j + q + 1];
    L[n1] = INF;
    R[n2] = INF;
    i = 0;
    j = 0;
    for(k = p ;k <= r; k++)
    {
        if(L[i] <= R[j])
            Array[k] = L[i++];
        else
            Array[k] = R[j++];
    }
}