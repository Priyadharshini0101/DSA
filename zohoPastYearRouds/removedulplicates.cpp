#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cout<<"Enter the numbers of elements:";
    cin>>t;
    int a[t];
    std::cout<<"Enter the elements:";
    for(int d=0;d<t;d++){
        cin>>a[d];
    }

    for(int i=0;i<t-1;i++){
        for(int j=i+1;j<t;j++){
            if(a[i]==a[j]){
                for(int k=i;k<t-1;k++){
                    a[k]=a[k+1];
                }
                --t;
            }
        }
    }

     for(int r=0;r<t;r++){
        cout<<a[r]<<" ";
    }


   return 0;
}