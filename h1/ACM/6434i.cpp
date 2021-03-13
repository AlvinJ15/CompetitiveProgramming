#include <bits/stdc++.h>
using namespace std;
int numeros[100];
int memo [100][100];
int N,M,T;

main(){
	
  cin >> T;
  int count =1;
  while(T--){
    cin >> N>>M;
    memset(memo,1<<31,sizeof memo);
    
    for(int i =0;i<N;i++){
      scanf("%d",&numeros[i]);
    }
    sort(numeros,numeros+N);
    for(int index=0;index<N;index++){
          if(index !=N-1)
            memo[index][1]=numeros[N-1]-numeros[index];
          else
            memo[index][1]=0;
    }
    int ans;
    int m=M;
    for(int m=2;m<M+1;m++){
      for(int index=0;index<N;index++){
        ans=1<<30;
        for(int i=index;i<N-m+1;i++){
          if(index==i)
            ans=min(ans,0+memo[i+1][m-1]);
          else
            ans=min(ans,numeros[i]-numeros[index]+memo[i+1][m-1]);
        }
        memo[index][m]=ans;
      }
    }
  /*  for(int i =0;i<N;i++){
      for(int j=0;j<M;j++)
        cout<<memo[i][j]<<" ";
      cout<<endl;
    }*/

    printf("Case #%d: %d\n",count++,memo[0][M]);
  
  }

}
