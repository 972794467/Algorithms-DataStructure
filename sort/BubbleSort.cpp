/**
 * 冒泡排序
 * author:xwhdlm
 */

#include <iostream>

using namespace std;

void bubbleSort(int *arr,int length)
{
    for(int i=0;i<length;i++){
        for(int j=i;j<length;j++){
            if(arr[i]>arr[j]){
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int main()
{
    int arr[10] = {4,6,9,1,23,345,75,1,354,87};
    bubbleSort(arr,10);
    for(int i=0; i<10; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}
