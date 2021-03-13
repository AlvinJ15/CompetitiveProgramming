#include <bits/stdc++.h>
using namespace std;
long long memo[70][80][70];
int N=62;
int numeros[70];
int contar(long long x){
  int r=0;
  for(int i=0;i<63;i++){
    if(x&1)
      r++;
    x>>=1;
  }
  return r;
}
string DecimalToBinaryString(long long a)
{
   string binary = "";
   for(int i=0;i<62;i++){
     if(a&1)
       binary="1"+binary;
     else
       binary="0"+binary;
     a>>=1;
   }
   return binary;
}
long long dp(int pos,int cnt,int K,bool flag){
  if(pos==N)
    return (cnt==K)?1:0;
  if(!flag && memo[K][pos][cnt]!=-1){
 //   cout<<pos<<" "<<cnt<<" "<<K<<endl;
    return memo[K][pos][cnt];}
  long long ans=0;
  if(flag){
    if(numeros[pos]==1){
      ans+=dp(pos+1,cnt+1,K,true);
      ans+=dp(pos+1,cnt,K,false);
    }
    else{
      ans+=dp(pos+1,cnt,K,true);
    }
  }
  else{
        ans+=dp(pos+1,cnt+1,K,false);
        ans+=dp(pos+1,cnt,K,false);
    
  }
  if(!flag)
    return memo[K][pos][cnt]=ans;
  else
    return ans;
}
main(){
  int X,contador;
  long long resultado,A,B;
  string a,b;
  int var;
  vector<int> elems[13];
  for(int i=0;i<=10;i++){
    for(int j=1;j<=63;j++){
      var=j;
      contador=0;
      while(var!=1){
        contador++;
        var=contar(var);
      }
      if(contador+1==i)
        elems[i].push_back(j);
    }
  }
  
  memset(memo,-1,sizeof memo);
  while(scanf("%lld%lld%d",&A,&B,&X),A|B|X){
    if(X==0 && 1==A ){printf("1\n");continue;}
    a=DecimalToBinaryString(A);
    b=DecimalToBinaryString(B);
    for(int i=0;i<b.size();i++)
      numeros[i]=b[i]-'0';
    resultado=0;
    if(1==X && 1==A ){resultado=-1;}
    int K;
    for(int i=0;i<elems[X].size();i++){
      K=elems[X][i];
      resultado+=dp(0,0,K,true);
    }
    for(int i=0;i<a.size();i++)
      numeros[i]=a[i]-'0';
    for(int i=0;i<elems[X].size();i++){
      K=elems[X][i];
      resultado-=dp(0,0,K,true);
    }
    var=contar(A);
    for(int i=0;i<elems[X].size();i++){
      if(var==elems[X][i]){
        resultado++;
        break;
      }
    }
    printf("%lld\n",resultado);

   
  }


}
