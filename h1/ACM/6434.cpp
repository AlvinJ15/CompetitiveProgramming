#include <bits/stdc++.h>
using namespace std;
int numeros[100];
int memo [100][100];
int N,M,T;
int recur(int index , int m){
  if(m==1){
    if(index!=N-1)
      return numeros[N-1]-numeros[index];
    else{return 0;
    }
  }
  if(memo[index][m]>-0.5)
    return memo[index][m];
  int ans =1<<30; 
  for(int i=index;i<N-m+1;i++){
    if(index==i)
      ans=min(ans,0+recur(i+1,m-1));
    else
      ans=min(ans,numeros[i]-numeros[index]+recur(i+1,m-1));
  }
  
  return memo[index][m]=ans;
}
main(){
	
  cin >> T;
  int count =1;
  while(T--){
    memset(numeros,0,sizeof numeros);
    cin >> N>>M;
    memset(memo,-1,sizeof memo);
    for(int i =0;i<N;i++){
      scanf("%d",&numeros[i]);
    }
    sort(numeros,numeros+N);
    printf("Case #%d: %d\n",count++,recur(0,M));
  
  }

}
