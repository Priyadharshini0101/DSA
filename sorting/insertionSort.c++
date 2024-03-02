#include <iostream>
#include <bits/stdc++.h>

int main(){
	int n;
	std::cout<<"Enter the numbers of the elements";
	std::cin>>n;
	int a[n];
	for(int i=0;i<n;i++){
		std::cin>>a[i];
	}
	for(int i=1;i<n;i++){
		int temp=a[i],j=i-1;
		while(j>=0 && a[j]>temp){
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=temp;
	}
	for(int i=0;i<n;i++){
		std::cout<<a[i]<<" ";
	}
	return 0;
}