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
	bool flag=false;
	int index;
	std::cout<<"Enter the elements in array";
	for(int i=0;i<n;i++){
		std::cin>>a[i];
		if(a[i]==key){
			flag=true;
			index=i;
		}
	}
	if(flag){
		std::cout<<"Element Found at the index"<<index<<"\n";
	}else{
		std::cout<<"Element Not found"<<"\n";
	}
	return 0;
}