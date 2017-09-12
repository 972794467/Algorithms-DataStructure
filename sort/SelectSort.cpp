/**
 * 选择排序
 * author:xwhdlm
 */

#include <iostream>

using namespace std;

// 直接选择排序,传下标
void selectSort(int *arr,int start,int end)
{
    int temp,minCursor,min;
    for(int i=start;i<end;i++){
        min = arr[i];
        minCursor = i;
        for(int j=i;j<end;j++){
            if(arr[j] < min){
                min = arr[j];
                minCursor = j;
            }
        }
        if(i == minCursor){
            continue;
        }
        temp = arr[i];
        arr[i] = arr[minCursor];
        arr[minCursor] = temp;
    }
}

int main()
{
    int arr[10] = {4,6,9,1,23,345,75,1,354,87};

    selectSort(arr,0,10);
    //insertSort(arr,0,10);
    for(int i=0; i<10; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}
