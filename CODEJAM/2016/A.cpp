#include <bits/stdc++.h>
using namespace std;
int solve(int N){
  int hash[10],j;
  memset(hash,0,sizeof hash);
  int var;
  for(int i=1;i<100000;i++){
    var=N*i;
    while(var){
      hash[var%10]++;
      var/=10;
    }
    for(j=0;j<10;j++){
      if(hash[j]==0)
        break;
    }
    if(j==10)return i;
  }
  return 0;
}
main(){
  int T,N,ans,cases=1;
  scanf("%d",&T);
  while(T--){
    scanf("%d",&N);
    
    ans=solve(N);
    if(cases!=1)printf("\n");
    printf("Case #%d: ",cases++);
    if(!ans)
      printf("INSOMNIA");
    else
      printf("%d",ans*N);
  }


}
