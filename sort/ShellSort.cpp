/**
 * 希尔排序
 * author:xwhdlm
 */

#include <iostream>
#include <stdlib.h>
using namespace std;

void shellSort(int *arr,int left,int right)
{
    int i,j;
    int gap = right - left + 1;   //gap 为间隔值,将数组分成gap个子序列，距离为gap的放在同一子序列中
    int temp;
    do{
        gap = gap/3 + 1;
        for(i = left + gap;i <= right;i++){
            // 子序列插入排序
            if(arr[i] < arr[i-gap]){
                temp = arr[i];
                j = i - gap;
                do{
                    arr[j+gap] = arr[j];
                    j = j - gap;
                } while(j >= left && temp < arr[j]);
                arr[j+gap] = temp;
            }
        }
    }while(gap > 1);
};

int main()
{
    int arr[10] = {4,6,9,1,23,345,75,1,354,87};
    shellSort(arr,0,9);
    for(int i=0; i<10; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}
