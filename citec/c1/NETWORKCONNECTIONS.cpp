#include <bits/stdc++.h>
using namespace std;
int padre[1000005];
int find(int x){
  if(x==padre[x])
    return x;
  else return find(padre[x]);
}
void unio(int x,int y){
  int xx= find(x);
  int yy=find(y);
  padre[xx]=yy;
}
main(){
	int test,N,a,b,sucess,unsucess;
  char c;
  scanf("%d",&test);
  int var=test;
  for(int k=0;k<test;k++){
    sucess=unsucess=0;
    for(int i=0;i<1000005;i++)
      padre[i]=i;
    scanf("%d",&N);
    scanf("\n");
    while(scanf("%c",&c),c=='c'||c=='q'){
      scanf("%d%d",&a,&b);
      a--;b--;
      if(c=='c'){
        unio(a,b);
      }
      else{
        if(find(a)==find(b))
          sucess++;
        else
          unsucess++;
      }
    c='a';  
    scanf("\n");
    }
    if(k==0)
      printf("%d,%d\n",sucess,unsucess);
    else
      printf("\n%d,%d\n",sucess,unsucess);
  }


}
