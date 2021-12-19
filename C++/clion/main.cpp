#include <bits/stdc++.h>
#include "binarysearchtree.cpp"

using namespace std;

template<class T>
void IS_EMPTY(TreeType<T> &treeNode) {
    cout << (treeNode.IsEmpty() ? "Tree is empty" : "Tree is not empty") << endl;
}

template<class T>
void INSERT(TreeType<T> &treeNode, T *arr, int size) {
    for (int i = 0; i < size; ++i) {
        treeNode.InsertItem(arr[i]);
    }
}

template<class T>
void FIND(TreeType<T> &treeNode, T x) {
    bool found;
    treeNode.RetrieveItem(x, found);
    cout << (found ? "Item is found" : "Item is not found") << endl;
}

template<class T>
void PRINT(TreeType<T> &treeNode, OrderType orderType) {
    bool finished = treeNode.IsEmpty();
    T item;
    treeNode.ResetTree(orderType);
    while (!finished) {
        treeNode.GetNextItem(item, orderType, finished);
        cout << item << " ";
    }
    cout << endl;
}

template<class T>
void Task_1(T type) {
    TreeType<T> treeNode;

    IS_EMPTY(treeNode);

    T arr[] = {4, 9, 2, 7, 3, 11, 17, 0, 5, 1};
    INSERT(treeNode, arr, sizeof(arr) / sizeof(arr[0]));

    IS_EMPTY(treeNode);

    cout << treeNode.LengthIs() << endl;

    FIND(treeNode, 9);

    FIND(treeNode, 13);

    PRINT(treeNode, IN_ORDER);

    PRINT(treeNode, PRE_ORDER);

    PRINT(treeNode, POST_ORDER);

    treeNode.MakeEmpty();
}

template<class T>
TreeNode<T> *MinSpan(T *arr, int start, int end) {
    if (start > end)return nullptr;
    int mid = (end + start) / 2;
    auto *treeNode = new TreeNode<T>;
    treeNode->info = arr[mid];
    treeNode->left = MinSpan(arr, start, mid - 1);
    treeNode->right = MinSpan(arr, mid + 1, end);
    return treeNode;
}

void preOrder(TreeNode<int> *treeNode) {
    if (treeNode == nullptr)return;
    cout << treeNode->info << " ";
    preOrder(treeNode->left);
    preOrder(treeNode->right);
}

template<class T>
void Task_2(T type) {
    T arr[] = {11, 9, 4, 2, 7, 3, 17, 0, 5, 1};
    sort(arr, arr + (sizeof(arr) / sizeof(arr[0])));
    TreeNode<T> *treeNode = MinSpan(arr, 0, (sizeof(arr) / sizeof(arr[0])) - 1);
    preOrder(treeNode);
}

int main() {
    Task_1(INT32_C(0));
    Task_2(INT32_C(0));
}