#include <bits/stdc++.h>

using namespace std;


#define ARRAYLENGTH 40


void InsertionSort(int * nums, int arrayLength);

int main(void)
{
	int nums1[ARRAYLENGTH];

	for (int i = 0; i < ARRAYLENGTH; i++)
	{
		nums1[i] = rand() % 500;
	}
	cout << "arraylength = " << ARRAYLENGTH << endl;
	cout << "Before Sorting" << endl;
	for (int i = 0; i < ARRAYLENGTH; i++)
	{
		cout << nums1[i] << "\t";
	}
	cout << endl;


	InsertionSort(nums1, ARRAYLENGTH);

	cout << "After Insertion Sorting" << endl;
	for (int i = 0; i < ARRAYLENGTH; i++)
	{
		cout << nums1[i] << "\t";
	}
	cout << endl;


	getchar();
    system("pause");
    return 0;
}

void InsertionSort(int * numList, int arrayLength)
{
	// your code here
    int i, j;
    for(i = 0; i <= arrayLength; i++)
    {
        int temp = numList[i];
        for(j = i; numList[j - 1] > temp; j-- )
        {
            numList[j] = numList[j - 1];
        }
        numList[j] = temp;
    }
}


