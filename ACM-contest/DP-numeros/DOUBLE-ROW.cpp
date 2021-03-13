#include <bits/stdc++.h>
using namespace std;
vector<int> A;
vector<int> B;
int memo[2][50006];
int N;
vector<int> H1[100005];
vector<int> H2[100005];
int hash[50006];
main(){
  int var,tam1,tam2;
  scanf("%d",&N);
  for(int i=0;i<N;i++){
    scanf("%d",&var);
    H1[var].push_back(i);
    A.push_back(var);
  }
  for(int i=0;i<N;i++){
    scanf("%d",&var);
    H2[var].push_back(i);
    B.push_back(var);
  }
  tam1=0;
  memset(hash,0,sizeof hash);
  for(int i=0;i<100005;i++){
    if(H1[i].size()>1){
      tam1+=H1[i].size()-1;
      for(int j=0;j<H1[i].size();j++){
        hash[H1[i][j]]=1;
      }
    }
  }
  for(int i=0;i<100005;i++){
    if(H2[i].size()>1){
      tam1+=H2[i].size()-1;
      for(int j=0;j<H2[i].size();j++)
        if(hash[H2[i][j]]){
          tam1--;
          break;
        }
        
    }

  }

  printf("%d\n",tam1);

}
