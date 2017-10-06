/**
 * 二分查找
 * author:xwhdlm
 */

#include <iostream>

using namespace std;


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
// 二分查找,迭代
int binarySearchIteration(int *arr,int start,int end,int x)
{
    int mid = (start + end)/2;
    while(start <= end){
        if(arr[mid] == x){
            return mid;
        }else if(arr[mid] < x){
            start = mid + 1;
            mid = (start + end)/2;
        }else{
            end = mid - 1;
            mid = (start + end)/2;
        }
    }
    return -1;
}

// 二分查找,递归
int binarySearchRecursion(int *arr,int start,int end,int x)
{
    if(end < start){return -1;}
    int mid = (start + end)/2;
    if(arr[mid] == x){
        return mid;
    }else if(arr[mid] > x){
        return binarySearchRecursion(arr,start,mid-1,x);
    }else{
        return binarySearchRecursion(arr,mid+1,end,x);
    }
}


int main()
{
    int arr[10] = {4,6,9,1,23,345,75,1,354,87};
    //insertSort(arr,0,10);
    binaryInsertSort(arr,0,10);
    for(int i=0; i<10; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    int x;
    cin >> x;
    int index = binarySearchRecursion(arr,0,10,x);
    cout << endl << index << endl;
    return 0;
}
