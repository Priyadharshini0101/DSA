#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void heapify(vector<int>&arr, int n, int i){
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if(left < n && arr[left] > arr[largest]){
        largest = left;
    }
    if(right < n && arr[right] > arr[largest]){
        largest = right;
    }
    if(largest != i){
        swap(arr[i], arr[largest]);
        heapify(arr,n, largest);
    }
}

void push(vector<int>& pq, int value){
    pq.push_back(value);
    int i = pq.size() - 1;
    while(i > 0 && pq[(i - 1) / 2] < pq[i]){
        swap(pq[i],pq[(i - 1) / 2]);
        i = (i - 1)/2;
    }
}

void pop(vector<int>& pq){
    if(pq.empty()){
        std::cout<<"Priority queue is empty!";
    }
    pq[0] = pq.back();
    pq.pop_back();
    heapify(pq,pq.size(),0);
}

int top(vector<int>&pq){
    if(pq.empty()){
        std::cout<<"Priority queue is empty!";
    }
    return pq[0];
}

bool isEmpty(vector<int>& pq){
    return pq.empty();
}

void display(vector<int>& pq){
    for(int p:pq){
        std::cout<<p<<" ";
    }
}
int main(){
    vector<int> pq;
    while(1){
        int choice;
        std::cout<<"Enter your choice\n1.Push\n2.Pop\n3.Top\n4.Display\n5.IsEmpty";
        std::cin>>choice;
        switch(choice){
            case 1:
            int d;
            std::cin>>d;
            push(pq,d);
            break;
            case 2:
            pop(pq);
            break;
            case 3:
            std::cout<<"Top Element:"<<top(pq);
            break;
            case 4:
            if(isEmpty(pq)){
                std::cout<<"Empty";
            }else{
                std::cout<<"Not Empty";
            }
            break;
            case 5:
            display(pq);
            break;
            default:
            exit(0);
        }
    }
    return 0;
}