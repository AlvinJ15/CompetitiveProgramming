#include <bits/stdc++.h>
using namespace std;
main(){
  string p;
  vector<char> arr;
  while(cin>>p){
    arr.clear();
    for(int i=0;i<p.size();i++){
      char c = p[i];
      if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u')
        arr.push_back(c);
    }
    bool flag=true;
    for(int i=0;i<arr.size()/2;i++){
      if(arr[i]!=arr[arr.size()-1-i])
        flag=false;
    }
    if(flag){
      printf("S\n");
    }
    else{
    
      printf("N\n");}
  }	



}
