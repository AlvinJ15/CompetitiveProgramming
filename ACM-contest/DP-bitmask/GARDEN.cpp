#include <bits/stdc++.h>
using namespace std;
int N,M,K;
char garden[100][100];
int memo[1<<8][8][8];
int losetas[8];
int path[201][201];
int AdjMat[201][201];
int datos[101][101];
int arrAux[201];
void returnPath(int i ,int j){
  if(i!=j)
    returnPath(i,path[i][j]);
  arrAux[j]=1;
      
}
void printPath(int i ,int j){
  if(i!=j)
    printPath(i,path[i][j]);
 // caminos[j]=1;
  garden[j/M][j%M]='X';
}
int dp(int bitmask,int act,int D,int caminos[]){
  if(bitmask==0)
    {
    int sum=0;
    for(int i=0;i<M*N;i++)
      if(caminos[i])
        sum+=datos[i/M][i%M];
    return sum;
  }//return datos[act/M][act%M];
    //return datos[losetas[act]/M][losetas[act]%M];
  /*if(memo[bitmask][act][D]!=-1)
    return memo[bitmask][act][D];*/
  int ans=1<<30;
  for(int p1=0;p1<K;p1++)
    if(bitmask&(1<<p1)){

      for(int i=0;i<N*M;i++){
        arrAux[i]=caminos[i];
      }
      returnPath(act,p1);
      int aux[N*M];
      for(int i=0;i<N*M;i++)
        aux[i]=arrAux[i];
      ans=min(ans,dp(bitmask&~(1<<p1),p1,D,aux));
      //ans=min(ans,AdjMat[losetas[act]][losetas[p1]]+dp(bitmask&~(1<<p1),p1,D)-AdjMat[losetas[act]][losetas[act]]);
    }  
  return memo[bitmask][act][D]=ans;
}
void imprimir(){

  cout<<"asdsa"<<endl;
}
main(){
  scanf("%d%d%d",&N,&M,&K);
  memset(memo,-1,sizeof memo);
  int V=M*N;
  int x,y;
  int def=0; 
  for(int i=0;i<N;i++)
    for(int j=0;j<M;j++)
      scanf("%d",&datos[i][j]);
  for(int i=0;i<K;i++){
    scanf("%d%d",&x,&y);
    def+=datos[x-1][y-1];
    losetas[i]=(x-1)*M+y-1;
  }
  for(int i=0;i<201;i++)
    for(int j=0;j<201;j++)
      if(i==j)
        AdjMat[i][j]=0;
      else
        AdjMat[i][j]=1<<25;
  for(int i=0;i<N;i++)
    for(int j=0;j<M;j++){
      garden[i][j]='.';
      if(i>0)
        AdjMat[M*i+j][M*(i-1)+j]=datos[i][j];
      if(i<N-1)
        AdjMat[M*i+j][M*(i+1)+j]=datos[i][j];
      if(j>0)
        AdjMat[M*i+j][M*i+j-1]=datos[i][j];
      if(j<M-1)
        AdjMat[M*i+j][M*i+j+1]=datos[i][j];
    }
  for(int i=0;i<V;i++)
    for(int j=0;j<V;j++)
      path[i][j]=i;
  for(int k=0;k<V;k++)
    for(int i=0;i<V;i++)
      for(int j=0;j<V;j++)
        if(AdjMat[i][k]+AdjMat[k][j]<AdjMat[i][j]){
          AdjMat[i][j]=AdjMat[i][k]+AdjMat[k][j];
          path[i][j]=path[k][j];
        }
  for(int i=0;i<V;i++)
    for(int j=0;j<V;j++)
      if(i==j)
      AdjMat[i][j]+=datos[j/M][j%M];
      else
        AdjMat[i][j]+=datos[j/M][j%M];
  for(int i=0;i<V;i++){
    for(int j=0;j<V;j++)
      cout<<AdjMat[i][j]<<"\t";
    cout<<endl;
  }
  int var;
  int ans=1<<30;
  int D;
  int act;
  for(int i=0;i<K;i++){
    int arreglo[N*M];
    memset(arreglo,0,sizeof arreglo);
    garden[losetas[i]/M][losetas[i]%M]='X';
    var=dp((1<<K)-1,i,i,arreglo);
    cout<<var<<endl;
    if(ans>var){
      ans=var;
      D=i;
    }
  }
  int bitmask = (1<<K)-1;
  int menor;
  int indice=0;
  int temp=0;
  int rutaDP[K];
  while(bitmask!=0){
    menor=1<<20;
    for(int i=0;i<K;i++){
      if(bitmask&(1<<i)){
        var=memo[bitmask&(1<<i)][i][D];
        if(menor>var){
          menor=var;
          act=i;
        }
      }
    }
    temp=act;
    bitmask=bitmask&~(1<<temp);
    rutaDP[indice++]=losetas[temp];
  }
  cout<<"RUTA: ";
  for(int i=0;i<K;i++)
    cout<<rutaDP[i]<<" ";
  for(int i=0;i<K-1;i++){
    printPath(rutaDP[i],rutaDP[i+1]);
  }
  cout<<endl;
  int resp=0;
  for(int i=0;i<N;i++)
    for(int j=0;j<M;j++)
      if(garden[i][j]=='X')
        resp+=datos[i][j];
  cout<<resp<<endl;
  for(int i=0;i<N;i++){
    for(int j=0;j<M;j++)
      printf("%c",garden[i][j]);
    printf("\n");
  }

}
