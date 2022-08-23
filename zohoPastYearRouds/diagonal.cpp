#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cout<<"Enter the dimensional of the array:";
    cin>>t;

    cout<<"Enter the elements:";
    int a[t][t];
    for(int i=0;i<t;i++){
        for(int j=0;j<t;j++){
            cin>>a[i][j];
        }

    }

    int temp=0;

    for(int i=0;i<t;i++){
        for(int j=i;j<i+1;j++){
           temp=a[i][j];
           a[i][j]=a[i][t-j-1];
           a[i][t-j-1]=temp;
        }
    }
    cout<<"\n";


    for(int i=0;i<t;i++){
        for(int j=0;j<t;j++){
            cout<<a[i][j]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}