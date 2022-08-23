#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void leftArray(int arr[],int T){
    int temp=arr[0];
    for(int j=0;j<T-1;j++){
        arr[j]=arr[j+1];
    }

    arr[T-1]=temp;
}

void rightArray(int arr[],int T){
    int temp=arr[T-1];
    for(int k=T-1;k>=0;k--){
        arr[k]=arr[k-1];
    }
    arr[0]=temp;
    }
void leftRotation(int arr[],int Times,int T){
       for(int j=0;j<Times;j++){
           leftArray(arr,T);
       }
}

void rightRotation(int arr[],int Times,int T){
       for(int k=0;k<Times;k++){
           rightArray(arr,T);
       }
}

int main(){
    int t;
    cout<<"Enter the number of elements in the array:";
    cin>>t;
    int a[t];
    cout<<"Enter the elements in the array:";
    for(int i=0;i<t;i++){
        cin>>a[i];
    }
    int rotation,times;
    cout<<"Enter the rotation direction 1 <left> 2 <right>:";
    cin>>rotation;
    cout<<"Enter times to  rotate:";
    cin>>times;
    if(rotation==1){
        leftRotation(a,times,t);
    }else{
        rightRotation(a,times,t);
    }

    for(int f=0;f<t;f++){
        cout<<a[f]<<" ";
    }

    return 0;
    
}