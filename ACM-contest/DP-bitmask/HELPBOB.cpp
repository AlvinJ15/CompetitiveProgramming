#include <bits/stdc++.h>
using namespace std;
int N;
int K;
int pizzas[20][50];
double hash[105];
int v;
int abc;
double precom[1<<16][16];
int hammin(int x){
  x=(x&0x55555555) + ((x>>1)&0x55555555);
  x=(x&0x33333333) + ((x>>2)&0x33333333);
  x=(x&0x0F0F0F0F) + ((x>>4)&0x0F0F0F0F);
  x=(x&0x00FF00FF) + ((x>>8)&0x00FF00FF);
  return x;
}
pair<double,double> memo[1<<16];
int abcde[1<<16];
void minimo(pair<int,int> &a,pair<int,int> b){
  if(a.first*b.second>b.first*a.second){
    a.first=b.first;
    a.second=b.second;}
}
pair<int,int> dp(int bitmask){
  if(hammin(bitmask)==N-K)
    return make_pair(0,0);
  if(abcde[bitmask]!=-1){
    return memo[bitmask];}
  pair<int,int> ans;
  pair<int,int> temp;
  ans=make_pair(1000000,1);
  for(int p1=0;p1<N;p1++){
    if(bitmask &(1<<p1)){
      temp=dp(bitmask&~(1<<p1));
      temp.first+=pizzas[p1][0]*precom[bitmask][p1];
      temp.second+=pizzas[p1][1];
      minimo(ans,temp);
    }
  }
  abcde[bitmask]=1;
  return memo[bitmask]=ans;
}
main(){
	int var;
  pair<int,int> t;
  for(int i=0;i<101;i++){
    hash[i]=(100-(double)i)/100;
  }
  while(scanf("%d",&N),N){
    for(int i=0;i<N;i++){
      scanf("%d%d%d",&pizzas[i][0],&pizzas[i][1],&pizzas[i][2]);
      var=3;
      for(int j=0;j<pizzas[i][2];j++,var+=2){
        scanf("%d%d",&pizzas[i][var],&pizzas[i][var+1]);
        pizzas[i][var]--;
      }
    }
    int max = 1<<N;
    for(int i=0;i<max;i++)
      for(int j=0;j<16;j++)
        precom[i][j]=1.0;
    for(int i=0;i<max;i++){
      for(int j=0;j<N;j++)
        if(!(i&(1<<j))){
          int v=3;
          int abc=pizzas[j][2];
          for(int k=0;k<abc;k++,v+=2)
            precom[i][pizzas[j][v]]*=hash[pizzas[j][v+1]];
       }
    }
    t = make_pair(10000000,1);
    for(int i=1;i<=N;i++){
      memset(abcde,-1,sizeof abcde);
      K=i;
      minimo(t,dp((1<<N)-1));
    }
    double respu=t.first/t.second;
    long long ao = (long long)((respu*10000)+0.5);
    respu=ao/10000.0;
    printf("%.4f\n",(double)t.first/t.second);
  }

}
