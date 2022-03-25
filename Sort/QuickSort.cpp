#include <iostream>

using namespace std;

int  QuickSortPart(int arry[], int start, int end)
{
    int i = start, j = end, temp = arry[start];
    while(i < j)
    {
        while(i < j &&  temp <= arry[j]) j--;
        if (i < j)  arry[i++] = arry[j];
        while(i < j && arry[i] <= temp) i++;
        if (i < j) arry[j--] = arry[i];    
    }
    arry[i] = temp;
    return i;
}
void QuickSort(int arry[], int start, int end)
{
    if (start >= end) return;
    int i = QuickSortPart(arry, start, end);
    QuickSort(arry, start, i - 1);
    QuickSort(arry, i + 1, end);
}
int main()
{
    cout <<"hello"<<endl;
    int arry[] = {2,1,3,5,9,7,8,6};
    int nLen = sizeof(arry)/sizeof(int);
    QuickSort(arry, 0, nLen - 1);
    for(int i = 0; i < nLen; i++)
        cout<<arry[i] <<" =>";
    return 0;
}