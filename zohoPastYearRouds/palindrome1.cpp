#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(){
    string s="101",s1="1011";
    bool flag=true;
    int l1=s.length(),l2=s1.length();
    string s2,s3;
    cout<<"Input: "<<s;
    for(int i=s.length();i>=0;i++){
         s2+=s;
    }a

      if(s==s2){
          flag=true;
      }else{
          flag=false;
      }

      cout<<"Output: "<<flag<<"\n";
      
      cout<<"Input: 1011";
    for(int i=s1.length();i>=0;i++){
        s3+=s1[i];
      }    

      if(s1==s3){
          flag=true;
      }else{
          flag=false;
      }

      cout<<"Output: "<<flag<<"\n";
      
      return 0;
}