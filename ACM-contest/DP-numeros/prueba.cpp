#include <bits/stdc++.h>
using namespace std;
int  N;
int cont;
int numero[19];
long long memo[164][20];
long long recur(int sum,int index,bool flag){

  (index==N)?(return sum==cont?1:0);
  
  if(memo[sum][index]>=0&&!flag){
    return memo[sum][index];}
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
    return memo[sum][index]=ans;
}
main(){
  long long test,resp,var,X,temp;
	cin>>test;
  string a,b;
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
      memset(memo,-1,sizeof memo);
      for(int i =0;i<b.size();i++){
        numero[i]=b[i]-'0';
      }
      N=b.size();
      temp=0;
      var=recur(0,0,1);
      memset(numero,0,sizeof numero);
      for(int i=b.size()-a.size(),j=0;i<N;i++,j++){
        numero[i]=a[j]-'0';
        temp+=numero[i];
      }
      if(temp==cont)var++;
      long long rangoA =recur(0,b.size()-a.size(),1);
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



