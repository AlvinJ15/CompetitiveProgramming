#include <bits/stdc++.h>
using namespace std;
int  N=19;
int cont;
int numero[19];
long long memo[164][164][20];
long long recur(int sum,int index,bool flag){

  if(index==N)
    return sum==cont?1:0;
  
  if(memo[cont][sum][index]>=0&&!flag){
    return memo[cont][sum][index];}
 if(sum>cont)
    return 0;
  long long ans=0;
  if(flag){
    for(int i =0;i<numero[index];i++){
      ans+=recur(sum+i,index+1,false);
    }
    ans+=recur(sum+numero[index],index+1,true);
  }
  else{
    for(int i=0;i<10;i++){
      ans+=recur(sum+i,index+1,false);
    }
  }
  if(flag)
    return ans;
  else
    return memo[cont][sum][index]=ans;
}
main(){
  long long test,resp,var,X,temp;
	cin>>test;
  string a,b;
  memset(numero,0,sizeof numero);
  numero[0]=1;
  memset(memo,-1,sizeof memo);
  for(cont=1;cont<163;cont++){
    resp=recur(0,0,true);
  }
  int sizea,sizeb;
  while(test--){
    cin>>a>>b;
    resp=0;
    var=0;
    scanf("%lld",&X);
    for(cont=1;cont<163;cont++){
      temp=0;
      var=0;
      memset(numero,0,sizeof numero);
      for(int i =b.size()-1,j=N-1;i>=0;i--,j--){
        numero[j]=b[i]-'0';
      }
      temp=0;
      var=recur(0,N-b.size(),1);
     // cout<<var<<endl;
      memset(numero,0,sizeof numero);
      for(int i=a.size()-1,j=N-1;i>=0;i--,j--){
        numero[j]=a[i]-'0';
        temp+=numero[j];
      }
      if(temp==cont)var++;
      long long rangoA =recur(0,N-a.size(),1);
      var-=rangoA;
      if(X<cont)
        break;
      else{
        if(var*cont<=X){
          X-=var*cont;
          resp+=var;
          
        }
        else{
          resp+=X/cont;
          X-=(X/cont)*cont;
          break;
        }
      }
    }

    printf("%lld\n",resp);
  }
}



