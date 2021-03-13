#include <bits/stdc++.h>
using namespace std;
#define MOD 5318008
int memo[5000][5000];
int x4[]={0,1,1,1,-1,-1,-1,0};
int y4[]={1,1,0,-1,1,0,-1,-1};
int numPasos(int x,int y,int xx,int yy){
  return max(abs(xx-x),abs(yy-y));
}
int N;
int a,b,c,d;
int dp(int x,int y){
  if(x==c&&y==d)return 1;
  if(memo[x][y]!=-1)return memo[x][y];
  int ans=0;
  for(int i=0;i<4;i++){
    int xx=x+x4[i];
    int yy=y+y4[i];
    if(xx<N && yy<N &&yy>=0 &&xx>=0&& numPasos(x,y,c,d)==1+numPasos(xx,yy,c,d)){
      ans+=dp(xx,yy)%MOD;
    }
  }
  return memo[x][y]=ans%MOD;
}
main(){
	int test;
  cin>>test;
  while(test--){
    memset(memo,-1,sizeof memo);
    scanf("%d",&N);
    scanf("%d%d%d%d",&a,&b,&c,&d);
    if(b>d){
      swap(a,c);
      swap(b,d);
    }
    if(c<a){
      swap(a,c);
    }
    a--;b--;c--;d--;
    //cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
    printf("%d\n",dp(a,b));

  }



}
