#include <bits/stdc++.h>
using namespace std;
string A,B;
int memo[90][90];
int N,M,R;
vector<string> pila;
vector<string> respuestas;
string p;
void recur(int i,int j,int t){
  if(t==R){
    p="";
    for(int a=0;a<R;a++)
      p+=pila[a];
    respuestas.push_back(p);
    return;
  }
  if(i==N||j==M)return;
  if(A[i]==B[j]){
    string s(1,A[i]);
    pila.push_back(s);
    recur(i+1,j+1,t+1);
    pila.pop_back();
  }
  else{
    if(memo[i+1][j]==memo[i][j+1]){
      recur(i+1,j,t);recur(i,j+1,t);
    }
    else{
      if(memo[i+1][j]>memo[i][j+1])
        recur(i+1,j,t);
      else
        recur(i,j+1,t);
    }
  }
}
struct node{
  int x,y,z;
};
main(){
  int test,cases=1;
  scanf("%d",&test);
  stack<node> pila2;
	while(test--){
    memset(memo,0,sizeof memo);
    cin>>A>>B;
    N=A.size();
    M=B.size();
    for(int i=N-1;i>=0;i--){
      for(int j=M-1;j>=0;j--){
        if(A[i]==B[j])
          memo[i][j]=1+memo[i+1][j+1];
        else
          memo[i][j]=max(memo[i+1][j],memo[i][j+1]);
      }
    }
    R=memo[0][0];
    respuestas.clear();
    pila.clear();
    //arecur(0,0,0);
    node var;
    int i,j,t;
    var.x=0;
    var.y=0;
    var.z=0;
    pila2.push(var);
    while(!pila2.empty()){
      var=pila2.top();pila2.pop();
      i=var.x;j=var.y;t=var.z;
      if(var.z==R){
        p="";
        for(int a=0;a<R;a++)
          p+=pila[a];
        respuestas.push_back(p);
        continue;
      }
      if(i==N||j==M)continue;
      if(A[var.x]==B[var.y]){
        string s(1,A[var.x]);
        pila.push_back(s);
        recur(i+1,j+1,t+1);
        pila.pop_back();
      }
      else{
        if(memo[i+1][j]==memo[i][j+1]){
          recur(i+1,j,t);recur(i,j+1,t);
        }
        else{
          if(memo[i+1][j]>memo[i][j+1])
            recur(i+1,j,t);
          else
            recur(i,j+1,t);
        }
      }
    }
    sort(respuestas.begin(),respuestas.end());
    respuestas.erase(unique(respuestas.begin(),respuestas.end()),respuestas.end());
    if(cases!=1)printf("\n");
    for(int i=0;i<respuestas.size();i++)
      printf("%s\n",respuestas[i].c_str());
    cases++;
  }


}
