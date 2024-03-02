#include <iostream>
#include <bits/stdc++.h>

void merge(int a[],int start,int mid,int end){
	int i=start,j=mid+1,k=start;
	int b[100];
	while(i<=mid && j<=end){
		if(a[i]<=a[j]){
			b[k]=a[i];
			i++;
		}else{
			b[k]=a[j];
			j++;
		}
		k++;
	}
	if(i>mid){
	  while(j<=k){
	  	b[k]=a[j];
	  	j++;
	  	k++;
	  }	
	}else{
		while(i<=mid){
			b[k]=a[i];
			i++;
			k++;
		}
	}
	for(int i=start;i<=end;i++){
		a[i]=b[i];
	}
}

void mergeSort(int a[],int lb,int ub){
	int mid;
	if(lb<ub){
		mid=(lb+ub)/2;
		mergeSort(a,lb,mid);
		mergeSort(a,mid+1,ub);
		merge(a,lb,mid,ub);
  }
}

int main(){
	int n;
	std::cout<<"Enter the numbers of elements:";
	std::cin>>n;
	std::cout<<"Enter the elements";
	int a[n];
	for(int i=0;i<n;i++){
		std::cin>>a[i];
	}
	mergeSort(a,0,n-1);
	for(int i=0;i<n;i++){
		std::cout<<a[i]<<" ";
	}
}