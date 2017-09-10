/**
 * 插入排序
 * author:xwhdlm
 */

#include <iostream>

using namespace std;

// 直接插入排序,传下标
void insertSort(int *arr,int start,int end)
{
    for(int i = start + 1;i <= end;i++){
        if(arr[i] < arr[i - 1]){
            int temp = arr[i];
            int j = i - 1;
            do{
                arr[j + 1] = arr[j];
                j--;
            }while(j >= start && temp < arr[j]);
            arr[j+1] = temp;
        }
    }
}

// 二分折半插入排序
void binaryInsertSort(int *arr,int start,int end)
{
    for(int i = start + 1;i <= end;i++){
        if(arr[i] < arr[i - 1]){
            int temp = arr[i];
            int j = i;

            int low = start;
            int hight = i - 1;
            int mid;
            while(low <= hight){
                mid = (low + hight) / 2;
                if(temp < arr[mid]){
                    hight = mid - 1;
                }else{
                    low = mid + 1;
                }
            }
            while(j >= mid){
                arr[j] = arr[j-1];
                j--;
            }
            arr[mid] = temp;
        }
    }
}

int main()
{
    int arr[10] = {4,6,9,1,23,345,75,1,354,87};

    binaryInsertSort(arr,0,10);
    //insertSort(arr,0,10);
    for(int i=0; i<10; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}
