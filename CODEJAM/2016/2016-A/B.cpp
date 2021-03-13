#include <bits/stdc++.h>
using namespace std;
vector<int> resp;
int N;
int arr[50][50];
int grid[50][50];
bool foo(int i,int j){
  for(int a=0;a<N;a++){
    if(arr[i][a]==arr[j][a])
      return false;
  }
  return true;
}
bool NC(int i){
  for(int a=0;a<resp.size();a++)
    if(resp[a]==i)return false;
  return true;
}
bool foo2(int j){
  int b;
  for(int a=0;a<2*N;a++){
    if(NC(a)){
      for(b=0;b<N;b++){
        if(arr[a][b]!=grid[b][j])
          break;
      }
      if(b==N)return true;
    }
  }
  return false;
}
main(){
	int T,cases=1;
  scanf("%d",&T);
  while(T--){
    scanf("%d",&N);
    for(int i=0;i<2*N-1;i++){
      for(int j=0;j<N;j++){
        scanf("%d",&arr[i][j]);
      }
    }
    resp.clear();
    resp.push_back(0);
    for(int i=1;i<2*N-1;i++){
      if(foo(0,i)){
        resp.push_back(i);
      }
    }
    for(int i=0;i<resp.size();i++)cout<<resp[i]<<endl;
    for(int i=0;i<resp.size();i++){
      for(int j=0;j<N;j++){
        grid[i][j]=arr[resp[i]][j];
      }
    }
    if(cases!=1)printf("\n");
    printf("Case #%d:",cases++);
    for(int i=0;i<N;i++){
      if(!foo2(i)){
        for(int j=0;j<N;j++)
          printf(" %d",grid[j][i]);
      }
    }
    

  }


}
