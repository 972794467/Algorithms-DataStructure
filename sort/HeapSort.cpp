/**
 * 堆排序
 * author:xwhdlm
 */

#include <iostream>
#include <stdlib.h>
using namespace std;
class Heap
{
private:
    //初始化时选择 1,最小堆 2,最大堆
    int heapType;
    int *heap;
    int currentSize;
    const static int maxSize=500;
public:
    Heap(int* arr,int size,int _heapType=1){
        heapType = _heapType;
        if(maxSize < size){
            exit(1);
        }
        heap = new int[maxSize];
        if(NULL == heap){
            exit(1);
        }
        for(int i=0;i<size;i++){
            heap[i] = arr[i];
        }

        currentSize = size;
        int initPos = (currentSize-2)/2;

        while(initPos >= 0){
            siftDown(initPos,currentSize-1);
            initPos--;
        }
    };
    void siftDown(int start,int end){
        // 从节点start开始到end，自上向下比较，
        // 如果子女的值小于父节点的值，则小的上浮，继续向下层
        int cursor = start,child = 2*cursor+1;
        int temp = heap[cursor];
        if(1 == heapType){
            // 最小堆
            while(child <= end){
                if(child < end - 1 && heap[child] > heap[child+1]){
                    child++;
                }
                if(temp <= heap[child]){
                    break;
                }else{
                    heap[cursor] = heap[child];
                    cursor = child;
                    child = 2 * child + 1;
                }
            }
        }else if(2 == heapType){
            // 最大堆
            while(child <= end){
                if(child < end && heap[child] < heap[child+1]){
                    child++;
                }
                if(temp >= heap[child]){
                    break;
                }else{
                    heap[cursor] = heap[child];
                    cursor = child;
                    child = 2 * child + 1;
                }
            }
        }
        heap[cursor] = temp;

    };
    void siftUp(int start){
        int cursor = start,parents = (cursor-1)/2;
        int temp = heap[cursor];
        if(1 == heapType){
            while(cursor > 0){
                if(heap[cursor] >= heap[parents]){
                    break;
                }else{
                    heap[cursor] = heap[parents];
                    cursor = parents;
                    parents = (cursor-1)/2;
                }

            }
        }else if(2 == heapType){
            while(cursor > 0){
                if(heap[cursor] <= heap[parents]){
                    break;
                }else{
                    heap[cursor] = heap[parents];
                    cursor = parents;
                    parents = (cursor-1)/2;
                }

            }
        }
        heap[cursor] = temp;
    };
    void printValues(){
        for(int i = 0;i<currentSize;i++){
            cout << heap[i] << " ";
        }
        cout << endl;
    }
    bool insertValue(int value){
        if(currentSize == maxSize){
            return 0;
        }
        heap[currentSize] = value;
        siftUp(currentSize);
        currentSize++;
        return 1;
    }
    int popValue(){
        int value = heap[0];
        heap[0] = heap[currentSize-1];
        currentSize--;
        siftDown(0,currentSize-1);
        return value;
    }
};
int main()
{
    int arr[10] = {4,6,9,1,23,345,75,1,354,87};
    Heap *heap = new Heap(arr,10,2);
    heap->printValues();
    heap->insertValue(50);
    heap->printValues();
    cout <<heap->popValue() << endl;
    heap->printValues();
    return 0;
}
