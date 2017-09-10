/**
 * 快速排序
 * author:xwhdlm
 */

#include <iostream>

using namespace std;

// start and end 为数组下标
void quickSort(int *arr,int start,int end)
{
    if(start < end)
    {
        int temp = arr[start];
        int fpoint = start;
        int bpoint = end;
        while(fpoint < bpoint)
        {
            while(fpoint < bpoint)
            {
                if(arr[bpoint] < temp)
                {
                    arr[fpoint] = arr[bpoint];
                    fpoint++;
                    break;
                }
                else
                {
                    bpoint--;
                }
            }
            while(fpoint < bpoint)
            {
                if(arr[fpoint] > temp)
                {
                    arr[bpoint] = arr[fpoint];
                    bpoint--;
                    break;
                }
                else
                {
                    fpoint++;
                }
            }
        }
        arr[fpoint] = temp;
        quickSort(arr,start,fpoint-1);
        quickSort(arr,bpoint+1,end);
    }
}

int main()
{
    int arr[10] = {4,6,9,1,23,345,75,1,354,87};
    quickSort(arr,0,10);
    for(int i=0; i<10; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}
