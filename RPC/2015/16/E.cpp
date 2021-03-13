#include <bits/stdc++.h>
using namespace std;
main(){
  int test,G,falta,a,b,N,i,j;
  bool flag;
  scanf("%d",&test);
  pair<int,int> elementos[1000002];
  while(test--){
    scanf("%d",&N);
    for(i=0;i<N;i++){
      scanf("%d%d",&a,&b);
      elementos[i]=make_pair(a,b);
    }
    G=0;
    i=10%N,j=10%N;
    falta=0;
    flag=true;
    do{
      if(flag){
        if(G+elementos[j].first-elementos[j].second<0){
          flag=false;
          G=G+elementos[j].first-elementos[j].second;
          i=(i-1+N)%N;
        }
        else{
          G=G+elementos[j].first-elementos[j].second;
          j=(j+1)%N;
        }
      }
      else{
        if(elementos[i].first-elementos[i].second+G>=0){
          j=(j+1)%N;
          flag=true;
          G=elementos[i].first-elementos[i].second+G;
        }
        else{
          G+=elementos[i].first-elementos[i].second;
          i=(i-1+N)%N;
        }
      }
    }
    while(i!=j);
    int g=0;
    flag=true;
    do{
      g+=elementos[j].first-elementos[j].second;
      if(g<0){flag=false;continue;}
      j=(j+1)%N;
    }
    while(i!=j && flag);
    if(G>=0&&flag){
      printf("%d\n",i+1);
    
    }
    else{
      printf("IMPOSSIBLE\n");
    }
  }




}
