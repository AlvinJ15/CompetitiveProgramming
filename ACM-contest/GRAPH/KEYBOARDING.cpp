#include <bits/stdc++.h>
using namespace std;
#define mp(a,b) make_pair(a,b)
typedef pair<int,int> ii;
int px[]={0,-1,0,1};
int py[]={-1,0,1,0};
int N,M,xx,yy;
char grid[51][51];
int pre[51][51][51][51];
bool marcados[51][51][51][51];
int memo[10005][51][51];
ii var;
int dis,tam;
queue< ii > colita;
vector< ii > hash[28];
string palabra;
int dp(int pos,int i,int j){
  if(pos==tam){
    return 0;
  }
  int ans=1<<30;
  //if(memo[pos][i][j]!=-1)return memo[pos][i][j];
  for(int k=0;k<hash[palabra[pos]-'A'].size();k++){
    ii a=hash[palabra[pos]-'A'][k];
    //ans=min(ans,abs(i-a.first)+abs(j-a.second)+dp(pos+1,a.first,a.second));
    ans=min(ans,pre[i][j][a.first][a.second]+dp(pos+1,a.first,a.second));
  }
  return memo[pos][i][j]=ans;
}
main(){
  while(scanf("%d%d",&N,&M)!=EOF){

    memset(pre,0,sizeof pre);
    memset(marcados,0,sizeof marcados);
    memset(memo,-1,sizeof memo);
    for(int i=0;i<27;i++)
      hash[i].clear();
    for(int i=0;i<N;i++){
      scanf("\n");
      for(int j=0;j<M;j++){
        scanf("%c",&grid[i][j]);
        if(grid[i][j]=='*')
          grid[i][j]='[';
      }
    }
    scanf("\n");
    cin>>palabra;
    palabra+="[";
    tam=palabra.size();
    for(int k=0;k<28;k++){
      for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
          if(k+'A'==grid[i][j]){
            hash[k].push_back(mp(i,j));
          }
        }
      }
    }
    
    for(int i=0;i<N;i++){
      for(int j=0;j<M;j++){
        colita.push(mp(i,j));
        marcados[i][j][i][j]=1;
        while(!colita.empty()){
          var=colita.front();colita.pop();
          for(int  h=0;h<4;h++){
            xx=(var.first+px[h]+N)%N;
            yy=(var.second+py[h]+M)%M;
            if(marcados[i][j][xx][yy])continue;
            pre[i][j][xx][yy]=pre[i][j][var.first][var.second]+1;
            marcados[i][j][xx][yy]=1;
            colita.push(mp(xx,yy));
          }
        }
      }
    }
    printf("%d\n",dp(0,0,0)+(int)palabra.size());
  }
	


}
