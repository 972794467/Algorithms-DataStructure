/**
 * 顺序查找
 * author:xwhdlm
 */

#include <iostream>
#include <vector>
using namespace std;

// 顺序查找
int iteraSearch(vector<int> arr,int x)
{
    int i = 0;
    int length = arr.size();
    while( i<length && arr[i] != x){
        i++;
    }
    if(arr[i] == x){
        return i;
    }else{
        return -1;
    }
}


// 顺序查找，监视哨
int iteraSearch2(vector<int> arr,int x)
{
    int i = 0;
    arr.push_back(x);
    int length = arr.size();
    while(arr[i] != x){
        i++;
    }
    if(arr[i] == x && i != length - 1){
        return i;
    }else{
        return -1;
    }
}


int main()
{
    int arr[10] = {4,6,9,1,23,345,75,1,354,87};

    size_t count=sizeof(arr)/sizeof(int);
    vector<int> v_arr(arr,arr+count);

    for(int i=0; i<10; i++)
    {
        cout<<v_arr[i]<<" ";
    }
    cout << endl;
    int x;
    cin >> x;
    int index = iteraSearch2(v_arr,x);
    cout << endl << index << endl;
    return 0;
}
