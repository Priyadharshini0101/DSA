#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main(){
	int n;
	std::cout<<"Enter the number of elements:";
	std::cin>>n;
	int a[n];
	int key;
	std::cout<<"Enter the key:";
	std::cin>>key;
	std::cout<<"Enter the elements in array";
	for(int i=0;i<n;i++){
		std::cin>>a[i];
	}
	int first=0,last=n-1;
	bool flag=false;
	while(first<last){
		int mid=(first+last)/2;
		if(key==a[mid]){
			flag=true;
			break;
		}else{
			if(key>a[mid]){
				first=mid+1;
			}else{
				last=mid-1;
			}
		}
	}
	if(flag){
		std::cout<<"Element Found";
	}else{
		std::cout<<"Element Not Found";
	}
	return 0;
}