#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void intoBinaryString(int arr[],int x,int index){
    int i=0,binaryNum[32];
    while(x>0){
        binaryNum[i]=x%2;
        x=x/2;
        i++;
    }
     int count=0;
    for(int j=i-1;j>=0;j--){
         if(binaryNum[j]==1){
             count++;
         }
    }
   arr[index]=count;
}
int main(){
    
    int t;
    cout<<"Enter the number of elements in the array:";
    cin>>t;
    cout<<"Enter the elements:";
    int a[t],b[t];
    for(int i=0;i<t;i++){
        cin>>a[i];
    }
    for(int j=0;j<t;j++){
        int value=a[j];
        intoBinaryString(b,value,j);
    }

int temp=0;
    for(int i=0;i<t-1;i++){
        for(int j=i+1;j<t;j++){
            if((b[i]>b[j]) || (a[i]>a[j])){
                temp=b[i];
                b[i]=b[j];
                b[j]=temp;

                temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }
        }
    }
       
       for(int i=0;i<t;i++){
           cout<<a[i]<<" ";
       }
return 0;
}