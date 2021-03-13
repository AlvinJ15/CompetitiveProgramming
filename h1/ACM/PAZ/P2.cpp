#include <bits/stdc++.h>
using namespace std;
bool isP( long long n){
  int arr[15];
  int c=0;
  while(n){
    arr[c++]=n%10;
    n/=10;
  }
  for(int i=0;i<c/2;i++){
    if(arr[i]!=arr[c-i-1])return false;
  }
  return true;
}
long long inv(long long n){
  long long sum=0;
  while(n){
    sum= sum*10+n%10;
    n/=10;
  }
  return sum;
}
main(){
  int T;
  cin>>T;
  long long n;
  while(T--){
    int it=0;
    scanf("%lld",&n);
    while(true){

      if(isP(n)&&it!=0){
        break;
      }
      n+=inv(n);
      it++;
    }
    printf("%d %lld\n",it,n);
    
  }
}
