#include <bits/stdc++.h>
using namespace std;
string board;
string cards[200];
int P[4];
string a;
bool win;
bool imprimir;
int N,B,C;
main(){
  while(scanf("%d%d%d",&N,&B,&C),N){
    cin>>board;
    memset(P,-1,sizeof P);
    imprimir=false;
    int i;
    for(i=0;i<C;i++){
      cin>>a;
      win=false;
      if(a.size()==1){
        for(int j=P[i%N]+1;j<B;j++){
          if(board[j]==a[0]){
            P[i%N]=j;
            win=true;
            break;
          }
        }

      }
      else{
        for(int j=P[i%N]+1;j<B;j++){
          if(board[j]==a[0]){
            P[i%N]=j;
            break;
          }
        }
        for(int j=P[i%N]+1;j<B;j++){
          if(board[j]==a[1]){
            P[i%N]=j;
            win=true;
            break;
          }
        }
      }
      if((!win||P[i%N]==B-1)&&!imprimir){
        printf("Player %d won after %d cards.\n",(i%N)+1,i+1);
        imprimir=true;
      }
    }
    if(i==C&&!imprimir){
      printf("No player won after %d cards.\n",C);
    }
  }	


}
