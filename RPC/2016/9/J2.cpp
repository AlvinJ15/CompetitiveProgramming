#include <bits/stdc++.h>
using namespace std;
int N;
int arr[500];
long long memo[505][255];
long long BU[505][255];
long long DP(int index,int cant){
  if(!cant)return 0;
  if(index<0||cant<0)return -1000000000000000000;
  if(memo[index][cant]!=-1)return memo[index][cant];
  memo[index][cant]=max(arr[index]+DP(index-1,cant-1),max(DP(index-1,(index)/2+(!(index-1))),DP(index,cant-1)));
  return memo[index][cant];
}
main(){
  int T,cases=1;
  cin>>T;
  while(T--){
    scanf("%d",&N);
    for(int i=0;i<N;i++){
      scanf("%d",&arr[i]);
    }
    memset(memo,-1,sizeof memo);
    memo[0][1]=arr[0];
    long long maximo = arr[0];
    for(int i=3;i<N;i++){
      for(int j=3;j<i;j++)
        maximo=max(maximo,arr[i]+DP(j,(j+1)/2-((j%2)&&!(j-i+1))));
    }
    printf("Spree #%d: %lld\n",cases++,maximo);
  }


}
