#include <iostream>
#include <bits/stdc++.h>

int main(){
	int n;
	std::cout<<"Enter the number of elements";
	std::cin>>n;
	int a[n];
	std::cout<<"Enter the elements";
	for(int i=0;i<n;i++){
		std::cin>>a[i];
	}
	int temp=0;
	for(int gap=n/2;gap>=1;gap=gap/2){
		for(int j=gap;j<n;j++){
			for(int i=j-gap;i>=0;i=i-gap){
				if(a[i+gap]<a[i]){
					temp=a[i+gap];
					a[i+gap]=a[i];
					a[i]=temp;
				}else{
					break;
				}
			}
		}
	}
	for(int i=0;i<n;i++){
		std::cout<<a[i]<<" ";
	}
	return 0;
}