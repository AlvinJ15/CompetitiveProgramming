#include <bits/stdc++.h>
using namespace std;
int B[500][500];
int W[500][500];
int getSumaB(int i,int j,int k,int l){
  int sum = B[k][l];
  if(i>0)sum-=B[i-1][l];
  if(j>0)sum-=B[k][j-1];
  if(i>0 && j>0)sum+=B[i-1][j-1];
  return sum;
}
int getSumaW(int i,int j,int k,int l){
  int sum = W[k][l];
  if(i>0)sum-=W[i-1][l];
  if(j>0)sum-=W[k][j-1];
  if(i>0 && j>0)sum+=W[i-1][j-1];
  return sum;
}
main(){
  int N,P,x,y,sumitaW,sumitaB;
  while(scanf("%d%d",&N,&P)!=EOF){
    memset(B,0,sizeof B);
    memset(W,0,sizeof W);
    for(int i=0;i<P;i++){
      scanf("%d%d",&x,&y);
      B[x-1][y-1]=1;
    }
    for(int i=0;i<P;i++){
      scanf("%d%d",&x,&y);
      W[x-1][y-1]=1;
    }
    for(int i=0;i<N;i++){
      for(int j=0;j<N;j++){
        if(i>0){
          B[i][j]+=B[i-1][j];
          W[i][j]+=W[i-1][j];
        }
        if(j>0){
          B[i][j]+=B[i][j-1];
          W[i][j]+=W[i][j-1];
        }
        if(i>0 && j>0){
          B[i][j]-=B[i-1][j-1];
          W[i][j]-=W[i-1][j-1];
        }
      }
    }
    int totalB=0,totalW=0;
    for(int i=0;i<N;i++){
      for(int j=0;j<N;j++){
        for(int h=i;h<N;h++){
          if(j+h-i>=N)break;
          sumitaB=getSumaB(i,j,h,j+(h-i));
          sumitaW=getSumaW(i,j,h,j+(h-i));
          if(sumitaB>0 && sumitaW==0)totalB++;
          if(sumitaW>0)break;
        }
      }
    }
    for(int i=0;i<N;i++){
      for(int j=0;j<N;j++){
        for(int h=i;h<N;h++){
          if(j+h-i>=N)break;
          sumitaB=getSumaW(i,j,h,j+(h-i));
          sumitaW=getSumaB(i,j,h,j+(h-i));
          if(sumitaB>0 && sumitaW==0)totalW++;
          if(sumitaW>0)break;
        }
      }
    }
    printf("%d %d\n",totalB,totalW);
  }

}
