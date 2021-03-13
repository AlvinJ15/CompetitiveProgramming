#include <bits/stdc++.h>
using namespace std;
int numero[9];
bool primos[90];
int memo[90][10];
int N;
bool isPrime(int n){
  if(n==1)return false;
  int var=sqrt(n);
  for(int i=2;i<=var;i++){
    if(!(n%i))
      return false;
  }
  return true;
}
int gone(int sum,int index,bool flag){
  
   if(index==N)
     return primos[sum]?1:0;
   if(memo[sum][index]>=0 && !flag){
     return memo[sum][index];
   }
   int ans=0;
   if(flag){
     for(int i=0;i<numero[index];i++){
       ans+=gone(sum+i,index+1,false);
     }
     ans+=gone(sum+numero[index],index+1,true);
   }
   else{
     for(int i=0;i<10;i++){
       ans+=gone(sum+i,index+1,false);
     }
   }
   return memo[sum][index]=ans;

}
main(){
	
  int test,resp,temp;
  cin>>test;
  string a,b;
  memset(primos,false,sizeof primos);
  for(int i=1;i<90;i++){
    if(isPrime(i))
      primos[i]=true;
  }
  while(test--){
    temp=0;
    cin>>a>>b;
    N=b.size();
    for(int i=0;i<N;i++){
      numero[i]=b[i]-'0';
    }
    memset(memo,-1,sizeof memo);
    resp=gone(0,0,true);
    N=a.size();
    for(int i=0;i<N;i++){
      numero[i]=a[i]-'0';
      temp+=numero[i];
    }
    memset(memo,-1,sizeof memo);
    int al=gone(0,0,true);
    resp-=al;
    primos[temp]?resp++:resp;
    printf("%d\n",resp);
  }

}
