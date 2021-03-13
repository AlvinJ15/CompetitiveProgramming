#include <bits/stdc++.h>
using namespace std;
int main(){
	int N,cuadros=0;
  char palabra[100];
  string palabrota;
  char grid[10][10];
  char aux[10][10];
  char resp[10][10];
  vector<char> p;
  scanf("%d",&N);
  for(int i=0;i<N;i++){
    scanf("\n");
    for(int j=0;j<N;j++){
      scanf("%c",&grid[i][j]);
      if(grid[i][j]=='.')cuadros++;
    }
  }
  cin>>palabrota;
  int c=0,al=0;
  for(int m=0;m<ceil(palabrota.size()/N*N);m++){
    for(int i=0;i<N*N;i++){
      if(al<palabrota.size())
      palabra[i]=palabrota[al++];
      else
        palabra[i]='*';
    }
  c=0;

  memset(resp,0,sizeof resp);
  for(int h=0;h<4;h++){
    for(int i=0;i<N;i++){
      for(int j=0;j<N;j++){
        if(grid[i][j]=='.'){
          if(resp[i][j]==0){
            resp[i][j]=palabra[c++];
          }
          else{
            if(resp[i][j]!=palabra[c++]){
              printf("invalid grille\n");
              return 0;
            }
          }
        }
      }
    }
    for(int i=0;i<N;i++){
      for(int j=0;j<N;j++){
        aux[i][j]=grid[j][i];
      }
    }
    for(int i=0;i<N;i++){
      for(int j=0;j<N/2;j++){
        swap(aux[i][j],aux[i][N-j-1]);
      }
    }
    for(int i=0;i<N;i++){
      for(int j=0;j<N;j++){
        grid[i][j]=aux[i][j];
      }
    }
  }
  
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      if(resp[i][j]==0&&palabra[i*N+j]!='*'){
        printf("invalid grille\n");
        return 0;
      }
      else{
        p.push_back(resp[i][j]);
      }
    }
  }
  }
  for(int i=0;i<p.size();i++){
    if(p[i]!='*')
    printf("%c",p[i]);
  }
  printf("\n");



}
