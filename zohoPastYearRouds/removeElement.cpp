#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cout<<"Enter the number of elements:";
    cin>>t;
    cout<<"Enter the elements";
    int a[t];
    for(int i=0;i<t;i++){
        cin>>a[i];
    }
   int key;
    cout<<"Enter the element to be removed:";
    cin>>key;
    for(int i=0;i<t;i++){
        if(a[i]==key){
            continue;
        }
        cout<<a[i]<<" ";
    }

}