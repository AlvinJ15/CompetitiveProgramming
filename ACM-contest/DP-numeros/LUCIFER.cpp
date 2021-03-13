#include <bits/stdc++.h>
using namespace std;
int numero[9];
int memo[38][38][10][2][2];
int N;
bool primos[100];
bool isPrime(int n){
  if(n==1)return false;
  int var=sqrt(n);
  for(int i=2;i<=var;i++){
    if(!(n%i))
      return false;
  }
  return true;
}
int RAONE(int par,int impar,int index,bool flag,int var,int op){
  if(index>=N)
    //return (par-impar==1)?1:0;
    if(primos[par-impar])
      return 1;
    else return 0;
  if(memo[par][impar][index][var][op]>=0 && !flag)
    return memo[par][impar][index][var][op];
  int ans=0;
  if(flag){
    for(int i=0;i<numero[index];i++){
        if(op&&var)
          ans+=(!(index%2))?RAONE(par+i,impar,index+1,false,var,op):RAONE(par,impar+i,index+1,false,var,op);
        else if(op&&!var)
          ans+=(!(index%2))?RAONE(par,impar+i,index+1,false,var,op):RAONE(par+i,impar,index+1,false,var,op);
        else {
          if(!i)
            ans+=(!(index%2))?RAONE(par+i,impar,index+1,false,!var,op):RAONE(par,impar+i,index+1,false,!var,op);
          else{
            if(var)
              ans+=(!(index%2))?RAONE(par+i,impar,index+1,false,var,!op):RAONE(par,impar+i,index+1,false,var,!op);
            else
              ans+=(!(index%2))?RAONE(par,impar+i,index+1,false,var,!op):RAONE(par+i,impar,index+1,false,var,!op);
          }
        }

    }

        if(op&&var)
          ans+=(!(index%2))?RAONE(par+numero[index],impar,index+1,true,var,op):RAONE(par,impar+numero[index],index+1,true,var,op);
        else if(op&&!var)
          ans+=(!(index%2))?RAONE(par,impar+numero[index],index+1,true,var,op):RAONE(par+numero[index],impar,index+1,true,var,op);
        else {
          if(!numero[index])
            ans+=(!(index%2))?RAONE(par+impar+numero[index],impar,index+1,true,!var,op):RAONE(par,impar+numero[index],index+1,true,!var,op);
          else{
            if(var)
              ans+=(!(index%2))?RAONE(par+numero[index],impar,index+1,true,var,!op):RAONE(par,impar+numero[index],index+1,true,var,!op);
            else
              ans+=(!(index%2))?RAONE(par,impar+numero[index],index+1,true,var,!op):RAONE(par+numero[index],impar,index+1,true,var,!op);
          }
        }
  }
  else{
    for(int i=0;i<10;i++){
        if(op&&var)
          ans+=(!(index%2))?RAONE(par+i,impar,index+1,false,var,op):RAONE(par,impar+i,index+1,false,var,op);
        else if(op&&!var)
          ans+=(!(index%2))?RAONE(par,impar+i,index+1,false,var,op):RAONE(par+i,impar,index+1,false,var,op);
        else 
          if(!i)
            ans+=(!(index%2))?RAONE(par+i,impar,index+1,false,!var,op):RAONE(par,impar+i,index+1,false,!var,op);
          else
            ans+=(!(index%2))?RAONE(par+i,impar,index+1,false,var,!op):RAONE(par,impar+i,index+1,false,var,!op);
    }
  }
  return memo[par][impar][index][var][op]=ans;

}
main(){
  int test,temp,resp;
	cin>>test;
  string a,b;

  memset(primos,false,sizeof primos);
  for(int i=1;i<100;i++){
    if(isPrime(i))
      primos[i]=true;
  }
  while(test--){
    temp=0;
    
    cin>>a>>b;
    N=b.size();
    for(int i=0;i<N;i++)
      numero[i]=b[i]-'0';
    memset(memo,-1,sizeof memo);
    resp=RAONE(0,0,0,true,!(N%2),0);
    N=a.size();
    memset(memo,-1,sizeof memo);
    bool flag=true;
    for(int i=0;i<N;i++){
      numero[i]=a[i]-'0';
      if(N%2==0){
        if(i%2==0)
        temp+=numero[i];
        else
        temp-=numero[i];
      }
      else{
        if(i%2==0)
        temp-=numero[i];
        else
        temp+=numero[i];
      }
    }
    int al=RAONE(0,0,0,true,!(N%2),0);
    resp-=al;
    if(primos[temp])
      resp++;
    printf("%d\n",resp);

  }


}
