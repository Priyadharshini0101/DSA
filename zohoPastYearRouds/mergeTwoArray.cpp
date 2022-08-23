#include <iostream>
#include <bits\stdc++.h>
using namespace std;
void mergeSortedArray(int arr1[],int arr2[],int m,int n,int arr3[]){
    int i=0,j=0,k=0;
    while(i<m && j<n){
        if(arr1[i]<arr2[j]){
            arr3[k++]=arr1[i++];
        }else{
            arr3[k++]=arr2[j++];
        }
    }
    while(i<m){
        arr3[k++]=arr1[i++];
    }

    while(j<n){
       arr3[k++]=arr2[j++];
   }
}

int main(){
    int t;
    cout<<"Enter the number of elements in the array A:";
    cin>>t;
    int a[t];
    cout<<"Enter the elements in the array A:";
    for(int i=0;i<t;i++){
        cin>>a[i];
    }
    int t1;
  cout<<"Enter the number of elements in the array B:";
    cin>>t1;
   int b[t1];
       cout<<"Enter the elements in the array B:";
    for(int j=0;j<t1;j++){
        cin>>b[j];
    }
    int t2=t+t1;
    int c[t2];
mergeSortedArray(a,b,t,t1,c);

for(int i=0;i<t2;i++){
    cout<<c[i]<<" ";
}
return 0;


}