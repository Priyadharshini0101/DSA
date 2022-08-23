#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cout<<"Enter the dimensional of the matrix:";
    cin>>t;
    cout<<"Enter the elements:";
    int a[t][t];
    for(int i=0;i<t;i++){
        for(int j=0;j<t;j++){
            cin>>a[i][j];
        }
    }
    int expected;
     cout<<"Enter the expecte output:";
     cin>>expected;
    for(int i=0;i<t;i++){
        for(int j=i;j<t;j++){
             for(int m=0;m<t;m++){
                 for(int n=m;n<t;n++){
                     int sum=a[j+1][n+1]+a[j+1][m]+a[i][n+1]+a[i][m];
                     
                     if(sum==expected){
                         cout<<a[i][n+1]<<" "<<a[i][m]<<"\n"<<a[j+1][n+1]<<" "<<a[j+1][m]<<"\n"<<"Sum is "<<expected<<"\n";
                     }
                 }
             }
        }
    }
    return 0;
}