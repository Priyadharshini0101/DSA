#include <iostream>
#include <bits/stdc++.h>

void countSortbuckets(int a[],int n,int pos){
	int count[n]={};
	int b[n]={};
	for(int i=0;i<n;i++){
		++count[(a[i]/pos)%10];
	}
	for(int i=1;i<n;i++){
		count[i]=count[i]+count[i-1];
	}		
	for(int i=n-1;i>=0;i--){
		b[--count[(a[i]/pos)%10]]=a[i];
	}				
	for(int i=0;i<n;i++){
	a[i]=b[i];
	}
}

void radixSort(int a[],int n,int k){
	for(int pos=1;(k/pos)>0;pos=pos*10){
		countSortbuckets(a,n,pos);
	}
}

int getMaxElement(int a[],int n){
	int temp=a[0];
	for(int i=1;i<n;i++){
		if(temp<a[i]){
			temp=a[i];
		}
	}
	return temp;
}

int main(){
	int n,k;
	std::cout<<"Enter the number of elements:";
	std::cin>>n;
	int a[n];
	std::cout<<"Enter the elements";
	for(int i=0;i<n;i++){
		std::cin>>a[i];
	}
	k=getMaxElement(a,n);
	radixSort(a,n,k);
	for(int i=0;i<n;i++){
		std::cout<<a[i]<<" ";
	}
	return 0;
}