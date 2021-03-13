#include <bits/stdc++.h>
using namespace std;
#define M 1000000007
int N=51;
int numero[51];
long long memo[18][18][18][52];
long long recur(int n3,int n6,int n9,int index,bool flag){
  if(index==N)
    return (n3==n6 && n3==n9 && n3!=0)?1:0;
  if(n3>N/3||n6>N/3||n9>N/3)
    return 0;
 if(memo[n3][n6][n9][index]!=-1 && !flag ){
    return memo[n3][n6][n9][index]%M;}
  long long ans=0;
  if(flag){
    for(int i =0;i<numero[index];i++){
      if(i==3)
        ans=(ans+recur(n3+1,n6,n9,index+1,false))%M;
      if(i==6)
        ans=(ans+recur(n3,n6+1,n9,index+1,false))%M;
      if(i==9)
        ans=(ans+recur(n3,n6,n9+1,index+1,false))%M;
      if(i!=3 && i!=6 && i!=9)ans=(ans+recur(n3,n6,n9,index+1,false))%M;
    }
      if(numero[index]==3)
        ans=(ans+recur(n3+1,n6,n9,index+1,true))%M;
      else if(numero[index]==6)
        ans=(ans+recur(n3,n6+1,n9,index+1,true))%M;
      else if(numero[index]==9)
        ans=(ans+recur(n3,n6,n9+1,index+1,true))%M;
      else
        ans=(ans+recur(n3,n6,n9,index+1,true))%M;
  }
  else{
    for(int i=0;i<10;i++){
      if(i==3)
        ans=(ans+recur(n3+1,n6,n9,index+1,false))%M;
      if(i==6)
        ans=(ans+recur(n3,n6+1,n9,index+1,false))%M;
      if(i==9)
        ans=(ans+recur(n3,n6,n9+1,index+1,false))%M;
      if(i!=3 && i !=6 && i!=9)
        ans=(ans+recur(n3,n6,n9,index+1,false))%M;
    }
  }
  if(flag)
    return ans;
  else return memo[n3][n6][n9][index]=ans;
}
void imprimir(){
  for(int i=0;i<N;i++)
    cout<<numero[i]<<" ";
  cout<<endl;
}
main(){
  int test;
  int n3,n6,n9;
  long long resp,al;
  memset(numero,0,sizeof numero);
  memset(memo,-1,sizeof memo);
  numero[0]=1;
  //imprimir();
  resp=recur(0,0,0,0,true);
  //cout<<resp<<endl;
  string a,b;
  //cout<<"vlor:"<<memo[0][0][0][3]<<endl;
  cin>>test;
  while(test--){
    cin>>a>>b;
    n3=n6=n9=0;
    memset(numero,0,sizeof numero);
    for(int i =b.size()-1,j=N-1;i>=0;i--,j--){
      numero[j]=b[i]-'0';
    }
    //imprimir();
    resp=recur(0,0,0,N-b.size(),true);
    //cout<<resp<<endl;
    memset(numero,0,sizeof numero);
    for(int i=a.size()-1,j=N-1;i>=0;i--,j--){
      
      numero[j]=a[i]-'0';
      if(numero[j]==3)
        n3++;
      if(numero[j]==6)
        n6++;
      if(numero[j]==9)
        n9++;
    }
   // imprimir();

    al=recur(0,0,0,N-a.size(),true);
    resp=(resp-al+M)%M;
    if(n3==n6 && n3==n9&& n3!=0)
      resp++;
    printf("%lld\n",resp%M);
  }


}
