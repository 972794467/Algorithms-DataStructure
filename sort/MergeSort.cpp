/**
 * 归并排序 两路归并
 * author:xwhdlm
 */

#include <iostream>
#include <stdlib.h>
using namespace std;

void arrMerge(int *arr,int *arrTemp,const int left,const int mid,const int right)
{
    // arr[left:mid] 与arr[mid+1:right] 是有序表，归并为一个
    for(int i = left;i<=right;i++)
    {
        arrTemp[i] = arr[i];
    }
    int cursor1 = left,cursor2 = mid+1,cursor3=left;
    while(cursor1 <= mid && cursor2 <= right){
        if(arrTemp[cursor1]<=arrTemp[cursor2]){
            arr[cursor3++] = arrTemp[cursor1++];
        }else{
            arr[cursor3++] = arrTemp[cursor2++];
        }
    }
    while(cursor1<=mid){
        arr[cursor3++] = arrTemp[cursor1++];
    }
    while(cursor2<=right){
        arr[cursor3++] = arrTemp[cursor2++];
    }
}

void mergeSort(int *arr,int *arrTemp,int left,int right)
{
    if(left >= right){
        return;
    }
    int mid = (left+right)/2;
    mergeSort(arr,arrTemp,left,mid);
    mergeSort(arr,arrTemp,mid+1,right);
    arrMerge(arr,arrTemp,left,mid,right);
}

int main()
{
    int arr[10] = {4,6,9,1,23,345,75,1,354,87};
    int *arrTemp = new int[10];
    mergeSort(arr,arrTemp,0,10);
    for(int i=0; i<10; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}
