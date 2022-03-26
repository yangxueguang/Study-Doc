#include <iostream>

using namespace std;

void print(int arry[], int nLen)
{
    for(int i = 0; i < nLen; i++)
    cout<<arry[i] <<" =>";
}
void heapify(int arry[], int start, int end)
{
    int parent = start;
    int child = parent * 2 + 1;
    while (child <= end)
    {
        if (child + 1 <= end && arry[child] < arry[child + 1]) child++;
        if (arry[parent] > arry[child]) return;
        swap(arry[child], arry[parent]);
        parent = child;
        child = parent * 2 + 1;
    }
}

void  HeapSort(int arry[], int nLen)
{
    for (int i = nLen / 2 - 1; i >= 0; i--)
        heapify(arry, i, nLen);
    for (int i = nLen; i > 0; i--)
    {
        swap(arry[0], arry[i]);
        heapify(arry, 0, i - 1);
    }
}

int main()
{
    int arry[] = {2,1,3,5,9,7,8,6};
    int nLen = sizeof(arry)/sizeof(int);
    HeapSort(arry, nLen);
    print(arry,nLen);
    return 0;
}