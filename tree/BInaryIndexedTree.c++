#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int getNext(int index){
    return index + (index & -index);
}
int getParent(int index){
    return index - (index & -index);
}
int getSum(int  BITree[],int index){
    int sum = 0;
    index = index + 1;
    while(index > 0){
        sum += BITree[index];
        index = getParent(index);
    }
    return sum;
}
void updateBIT(int BITree[],int n,int index,int val){
    index = index + 1;
    while(index <= n){
        BITree[index] += val;
        index = getNext(index);
    }
}
int *constructBITree(int arr[],int n){
    int *BITree = new int[n+1];
    for(int i=1;i<=n;i++){
        BITree[i] = 0;
    }
    for(int i=0;i<n;i++){
        updateBIT(BITree,n,i,arr[i]);
    }
    return BITree;
}

void display(int BITree[],int n){
     for(int i=0;i<n + 1;i++){
        std::cout<<BITree[i]<<" ";
    }
}
int main()
{
    int n;
    std::cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        std::cin>>arr[i];
    }
    int *BITree = constructBITree(arr,n);
    display(BITree,n);
    std::cout<<"\n";
    std::cout<<getSum(BITree,5)<<"\n";
    std::cout<<getSum(BITree,6)<<"\n";
    std::cout<<getSum(BITree,9)<<"\n";
    return 0;
}
