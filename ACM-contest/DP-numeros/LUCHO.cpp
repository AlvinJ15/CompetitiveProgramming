#include <bits/stdc++.h>
using namespace std;
string A,B;
int memo[1000][1000];
#define eliminar 2
#define insertar 3
#define right 0
#define replace 4
main(){
  getline(cin,A);
  getline(cin,B);
  int N=A.size();
  int M=B.size();
  for(int i=0;i<N+5;i++)
    for(int j=0;j<M+5;j++)
      memo[i][j]=1<<30;

  //for(int i=0;i<M+1;i++)

  memo[N][M]=0;
  for(int i=N;i>=0;i--){
    for(int j=M;j>=0;j--){
      if(j<M && i<N&& A[i]==B[j]){
        memo[i][j]=right+memo[i+1][j+1];
      }
      else{
        memo[i][j]=min(memo[i][j],replace+memo[i+1][j+1]);
        memo[i][j]=min(memo[i][j],insertar+memo[i][j+1]);
        memo[i][j]=min(memo[i][j],eliminar+memo[i+1][j]);
      }
    }
  }
  /*for(int i=0;i<=N+3;i++){
    for(int j=0;j<=M+3;j++)
      cout<<memo[i][j]<<" ";
    cout<<endl;
  }*/
  printf("%d\n",memo[0][0]);


}
