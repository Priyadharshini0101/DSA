#include <iostream>
#include <bits/stdc++.h>

int main(){
	int n;
	std::cout<<"Enter the number of elements:";
	std::cin>>n;
	int a[n];
	std::cout<<"Enter the elements:";
	for(int i=0;i<n;i++){
		std::cin>>a[i];
	}
	int temp=0;
	bool flag;
	for(int i=0;i<n-1;i++){
		flag=true;
		for(int j=0;j<n-1-i;j++){
			if(a[j]>a[j+1]){
				flag=false;
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
		if(flag){
			break;
		}
	}
	for(int i=0;i<n;i++){
		std::cout<<a[i]<<" ";
	}
}

