#include <iostream>
#include <bits/stdc++.h>

void countSort(int a[],int n,int k){
int b[n]={ },count[k+1]={ };
	for(int i=0;i<n;i++){
	    ++count[a[i]];
	}
	for(int i=1;i<=k;i++){
		count[i]=count[i]+count[i-1];
	}
	for(int i=n-1;i>=0;i--){
		b[--count[a[i]]]=a[i];
	}
	for(int i=0;i<n;i++){
	   a[i]=b[i];
	}
}

int getMaxElement(int a[],int n){
	int m=a[0];
	for(int i=1;i<n;i++){
		if(a[i]>m){
			m=a[i];
		}
	}
	return m;
}

int main(){
	int n,k;
	std::cout<<"Enter the number of elements:";
	std::cin>>n;
	int a[n];
	std::cout<<"Enter the elements:";
	for(int i=0;i<n;i++){
		std::cin>>a[i];
	}
	k=getMaxElement(a,n);
	countSort(a,n,k);
	for(int i=0;i<n;i++){
		std::cout<<a[i]<<" ";
	}	
	return 0;
}

