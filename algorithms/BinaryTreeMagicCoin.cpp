/**
 * author:xwhdlm
小易准备去魔法王国采购魔法神器,购买魔法神器需要使用魔法币,但是小易现在一枚魔法币都没有,但是小易有两台魔法机器可以通过投入x(x可以为0)个魔法币产生更多的魔法币。
魔法机器1:如果投入x个魔法币,魔法机器会将其变为2x+1个魔法币
魔法机器2:如果投入x个魔法币,魔法机器会将其变为2x+2个魔法币
小易采购魔法神器总共需要n个魔法币,所以小易只能通过两台魔法机器产生恰好n个魔法币,小易需要你帮他设计一个投入方案使他最后恰好拥有n个魔法币。
输入描述:
输入包括一行,包括一个正整数n(1 ≤ n ≤ 10^9),表示小易需要的魔法币数量。


输出描述:
输出一个字符串,每个字符表示该次小易选取投入的魔法机器。其中只包含字符'1'和'2'。

输入例子1:
10

输出例子1:
122

 */

#include <iostream>
#include <math.h>
#include <stack>
using namespace std;
class TreeNode
{
    public:
    int value;
    TreeNode* leftChild;
    TreeNode* rightChild;
    TreeNode* parent;
    TreeNode(int _value,TreeNode* _leftChild,TreeNode* _rightChile,TreeNode* _parent){
        value = _value;
        leftChild = _leftChild;
        rightChild = _rightChile;
        parent = _parent;
    }
};
class Tree
{
    public:
    TreeNode* root;
    TreeNode* end;
    TreeNode **nodes;
    int length;
    Tree(int * arr,int _length){
        //TreeNode *point;
        length = _length;
        TreeNode *nodeArr[_length];
        for(int i=0;i<=_length;i++){
            TreeNode *point = new TreeNode(arr[i],NULL,NULL,NULL);
            nodeArr[i] = point;
        }
        for(int i=0;i<=(_length-1)/2;i++){
            if(2*i + 1 <= _length){
                nodeArr[i]->leftChild = nodeArr[2*i+1];
                nodeArr[2*i+1]->parent = nodeArr[i];
            }
            if(2*i + 2 <= _length){
                nodeArr[i]->rightChild = nodeArr[2*i+2];
                nodeArr[2*i+2]->parent = nodeArr[i];
            }
        }
        root = nodeArr[0];
        end = nodeArr[_length];
        nodes = nodeArr;
    }
    stack<int> getPath()
    {
        TreeNode * point = end;
        stack<int> s;

        while(point->parent != NULL && point != root){
            if(point->parent->leftChild == point){
                s.push(1);
            }else{
                s.push(2);
            }
            point = point->parent;
        }
        return s;
    }


};

int main()
{
    int n;
    cin >> n;
    int *arr;
    arr = new int[n];
    for(int i=0;i<=n;i++){
        arr[i] = i;
    }
    Tree* tree = new Tree(arr,n);
    stack<int> s = tree->getPath();
    while(!s.empty()){
        cout << s.top();
        s.pop();
    }
    cout << endl;

    return 0;
}
