#include <bits/stdc++.h>
using namespace std;
bool gana(char a,char b){
  if(a=='R'&& b=='S')return true;
  if(a=='S'&& b=='P')return true;
  if(a=='P' && b =='R')return true;
  return false;
}
main(){
  int x4[]={-1,0,0,1};
  int y4[]={0,-1,1,0};
  int T;
  char arr[100][100];
  char aux[100][100];
  cin>>T;
  int F,C,N;
  int cases=1;
  while(T--){
    scanf("%d%d%d",&F,&C,&N);
    for(int i=0;i<F;i++){
      scanf("%100s",arr[i]);
    }
    memset(aux,0,sizeof aux);
    for(int i=0;i<N;i++){
      for(int j=0;j<F;j++){
        for(int k=0;k<C;k++){
          for(int l=0;l<4;l++){
            int xx=j+x4[l];
            int yy=k+y4[l];
            if(xx>=0 && xx<F && yy>=0 && yy<C)
              if(gana(arr[j][k],arr[xx][yy]))
                aux[xx][yy]=arr[j][k];
          }
        }
      }
      for(int j=0;j<F;j++){
        for(int k=0;k<C;k++){
          if(aux[j][k]!=0)
          arr[j][k]=aux[j][k];
        }
      }
      memset(aux,0,sizeof aux);
    }
    if(cases!=1)
      printf("\n");
    for(int j=0;j<F;j++){
      for(int k=0;k<C;k++){
        printf("%c",arr[j][k]);
      }
      printf("\n");
    }
      cases++;
  }
}
