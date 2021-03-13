#include <bits/stdc++.h>
using namespace std;
int numero[64];
int N=64;
long long memo[10][65];
long long recur(int prev,int index,bool flag){
  if(index==N){
    return 1;}
  if(prev>numero[index])return 0;
  
  if(memo[prev][index]>=0 && !flag)
    return memo[prev][index];
  long long ans=0;
  if(flag){
    for(int i=prev;i<numero[index];i++)
      ans+=recur(i,index+1,false);
    ans+=recur(numero[index],index+1,true);
  }
  else{
    for(int i =prev;i<10;i++){
      ans+=recur(i,index+1,false);
    }
  }
  if(flag)
    return ans;
  else
    return memo[prev][index]=ans;
}
main(){
  int test;
  long long resp;
  int a,b;
  cin>>test;
  memset(numero,9,sizeof numero);
  memset(memo,-1,sizeof memo);
  while(test--){
    cin>>a>>b;
    memset(numero,0,sizeof numero);
    for(int i =0,j=N-1;i<b;i++,j--){
      numero[j]=9;
    }
    resp=recur(0,N-b,true);
    cout<<a<<" ";
    printf("%lld\n",resp);
    
  }
	


}
