#include <iostream>
#include <bits/stdc++.h>

int main(){
	int n;
   std::cout<<"Enter the number of array elements:";
   std::cin>>n;
   std::cout<<"Enter the array elements:";
   int a[n];
   for(int i=0;i<n;i++){
   	 std::cin>>a[i];
   }
   int temp=0;
   for(int i=0;i<n-1;i++){
   	for(int j=i+1;j<n;j++){
   		if(a[i]>a[j]){	   
   		temp=a[i];
   		a[i]=a[j];
   		a[j]=temp;
   	    }
	 }
   }
   for(int i=0;i<n;i++){
   	std::cout<<a[i]<<" ";
   }
   std::cout<<"\n";
   return 0;
}