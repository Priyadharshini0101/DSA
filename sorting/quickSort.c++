#include <iostream>
#include <bits/stdc++.h>

int Partition(int a[],int start,int end){
	int pivot=a[start];
	int lb=start;
	int  temp=0;
	while(start<end){
		while(a[start]<=pivot){
		start++;
		}
		while(a[end]>pivot){
			end--;
		}
		if(start<end){
			temp=a[start];
			a[start]=a[end];
			a[end]=temp;
		}
	}
	temp=a[lb];
	a[lb]=a[end];
	a[end]=temp;
	return end;
}

void quickSort(int a[],int lb,int ub){
	if(lb<ub){
		int loc=Partition(a,lb,ub);
		quickSort(a,lb,loc-1);
		quickSort(a,loc+1,ub);
	}
}

int main(){
	int n;
	std::cout<<"Enter the numbers of elements:";
	std::cin>>n;
	int a[n];
	std::cout<<"Enter the elements";
	for(int i=0;i<n;i++){
		std::cin>>a[i];
	}
	quickSort(a,0,n-1);
	for(int i=0;i<n;i++){
		std::cout<<a[i]<<" ";
	}
	return 0;
}