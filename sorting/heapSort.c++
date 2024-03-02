#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void heapify(vector<int> &arr, int &n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }
    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }
    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void insert(vector<int> &arr,int &n,int value){
    n = n+1;
    arr.push_back(value);
    int i = n-1;
    while(i > 0){
       int parent = i/2;
       if(arr[parent] < arr[i]){
           swap(arr[parent],arr[i]);
           i = parent;
       }else{
           return;
       }
    }
}

void deleteNode(vector<int> &arr, int &n) {
    if (n == 0) {
        cout << "Heap is empty." << endl;
        return;
    }
    swap(arr[0], arr[n - 1]);
    n = n - 1;
    heapify(arr, n, 0);
}

void display(vector<int> arr,int n){
    for(int i=0;i<n;i++){
        std::cout<<arr[i]<<" ";
    }
}

int main(){
    vector<int> arr;
    int n = 0;
    while(1){
        int choice;
        std::cout<<"Enter your choice:\n1.Insert\n2.Delete\n3.Display\n";
        std::cin>>choice;
        switch(choice){
            case 1:
            int d;
            std::cout<<"Enter the data";
            std::cin>>d;
            insert(arr,n,d);
            break;
            case 2:deleteNode(arr,n);
            break;
            case 3:display(arr,n);
            break;
            default:
                exit(0);
        }
    }
    return 0;
}