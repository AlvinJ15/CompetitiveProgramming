#include <bits/stdc++.h>
using namespace std;
int K,N;
int numero[10];
int memo[90][10000][10];
int recur(int sum,int mod,int index,bool flag){
  if(index==N)
    return ((!(sum%K))&&!(mod%K))?1:0;
  if(memo[sum][mod][index]>=0&&!flag)
    return memo[sum][mod][index];
  int ans=0;
  if(flag){
    for(int i =0;i<numero[index];i++){
      ans+=recur(sum+i,mod+((int)(pow(10,N-index-1)*i)%K),index+1,false);
    }
    ans+=recur(sum+numero[index],mod+((int)(pow(10,N-index-1)*numero[index])%K),index+1,true);
  }
  else{
    for(int i =0;i<10;i++)
      ans+=recur(sum+i,mod+((int)(pow(10,N-index-1)*i)%K),index+1,false);
  }
  return memo[sum][mod][index]=ans;
  
  

}
main(){
	
  int test;
  cin>>test;
  string a,b;
  int resp;
  while(test--){
    memset(memo,-1,sizeof memo);
    cin>>a>>b;
    scanf("%d",&K);
    N=b.size();
    for(int i =0;i<N;i++)
      numero[i]=b[i]-'0';
    resp = recur(0,0,0,true);
    N=a.size();
    memset(memo,-1,sizeof memo);
    int temp=0,mod=0;
    for(int i=0;i<N;i++){
      numero[i]=a[i]-'0';
      temp+=numero[i];
      mod+=(int)(numero[i]*pow(10,N-i-1))%K;
    }
    resp-=recur(0,0,0,true);
    (!(temp%K)&&!(mod%K))?resp++:resp;
    printf("%d\n",resp);

  
  }

}
