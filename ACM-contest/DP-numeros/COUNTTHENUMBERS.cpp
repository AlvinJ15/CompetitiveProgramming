#include <bits/stdc++.h>
#include <sstream>
using namespace std;
int numeros[11];
int sub[2];
long long memo1[11][2][2];
long long memo2[11][2][11];
long long memo3[11][2][11][11];
int N=10;
long long dp1(int pos,int cnt ,bool flag,int var){
  
  if(pos==N)
    return (cnt==1&&var==1)?1:0;
  if(memo1[pos][cnt][var]!=-1 && !flag)return memo1[pos][cnt][var];
  long long ans=0;
  if(flag){
    for(int i=0;i<numeros[pos];i++){
      if(var==0 && i==0)ans+=dp1(pos+1,0,false,0);
      else
        if(cnt==1)ans+=dp1(pos+1,1,false,1);
        else
          if(i==sub[2])
            ans+=dp1(pos+1,1,false,1);
          else
            ans+=dp1(pos+1,0,false,1);
    }
    if(var==0 && numeros[pos]==0)ans+=dp1(pos+1,0,true,0);
    else
      if(cnt==1)ans+=dp1(pos+1,1,true,1);
      else
        if(numeros[pos]==sub[2])
          ans+=dp1(pos+1,1,true,1);
        else
          ans+=dp1(pos+1,0,true,1);
  }
  else{
    for(int i=0;i<10;i++){
      if(var==0 && i==0)ans+=dp1(pos+1,0,false,0);
      else
        if(cnt==1)ans+=dp1(pos+1,1,false,1);
        else
          if(i==sub[2])
            ans+=dp1(pos+1,1,false,1);
          else
            ans+=dp1(pos+1,0,false,1);
    }
  
  }
  if(flag)return ans;
  else return memo1[pos][cnt][var]=ans;
}
long long dp2(int pos,int cnt,int ant,bool flag){
  if(pos==N)
    return cnt==1?1:0;
  if(ant!=-1 && memo2[pos][cnt][ant]!=-1 && !flag)return memo2[pos][cnt][ant];
  long long ans=0;
  if(flag){
    for(int i=0;i<numeros[pos];i++){
      if(cnt==1)ans+=dp2(pos+1,1,i,false);
      else
        if(i==sub[2] && ant==sub[1])
          ans+=dp2(pos+1,1,i,false);
        else
          ans+=dp2(pos+1,0,i,false);
    }
    if(cnt==1)ans+=dp2(pos+1,1,numeros[pos],true);
    else
      if(numeros[pos]==sub[2] && ant==sub[1] )
        ans+=dp2(pos+1,1,numeros[pos],true);
      else
        ans+=dp2(pos+1,0,numeros[pos],true);
  }
  else{
    for(int i=0;i<10;i++){
      if(cnt==1)ans+=dp2(pos+1,1,i,false);
      else
        if(i==sub[2] && ant==sub[1])
          ans+=dp2(pos+1,1,i,false);
        else
          ans+=dp2(pos+1,0,i,false);
    }
  }
  if(flag||ant==-1)return ans;
  else return memo2[pos][cnt][ant]=ans;
}
long long dp3(int pos,int cnt,int a,int b,bool flag){
  if(pos==N)return (cnt==1)?1:0;
  if(a!=-1 && b!=-1 && memo3[pos][cnt][a][b]!=-1 && !flag)return memo3[pos][cnt][a][b];
  long long ans=0;
  if(flag){
    for(int i=0;i<numeros[pos];i++){
      if(cnt==1)ans+=dp3(pos+1,1,b,i,false);
      else
        if(i==sub[2] && b==sub[1] && a==sub[0])
          ans+=dp3(pos+1,1,b,i,false);
        else
          ans+=dp3(pos+1,0,b,i,false);
    }
    if(cnt==1)ans+=dp3(pos+1,1,b,numeros[pos],true);
    else
      if(numeros[pos]==sub[2] && sub[1]==b && sub[0]==a)
        ans+=dp3(pos+1,1,b,numeros[pos],true);
      else
        ans+=dp3(pos+1,0,b,numeros[pos],true);
  }
  else{
    for(int i=0;i<10;i++){
      if(cnt==1)ans+=dp3(pos+1,1,b,i,false);
      else
        if(i==sub[2] && b==sub[1] && a==sub[0])
          ans+=dp3(pos+1,1,b,i,false);
        else
          ans+=dp3(pos+1,0,b,i,false);
    }
  }
  if(flag || a==-1 || b==-1)return ans;
  else
    return memo3[pos][cnt][a][b]=ans;
}
string abc(int x){
  if(x==0)return "0";
  if(x==1)return "1";
  if(x==2)return "2";
  if(x==3)return "3";
  if(x==4)return "4";
  if(x==5)return "5";
  if(x==6)return "6";
  if(x==7)return "7";
  if(x==8)return "8";
  if(x==9)return "9";
}
string toStrin(int x){
  string r="";
  ostringstream convert;
  int a; 
  for(int i=0;i<10;i++){
    a=x%10;
    r=abc(a)+r;
    x/=10;
  }
  return r;
}
main(){
  int  A,B,X;
  int T;
  string a,b,x;
  long long resultado;
  int var,temp;
  while(scanf("%d%d%d",&A,&B,&X),A!=-1){
    if(A==0 && B==0 && X==0){
      printf("1\n");
      continue;
    }
    var=X;
    temp=10-((int)(log10(B))+1);
    resultado=0;
    a=toStrin(A);
    b=toStrin(B);
    if(X>=100)T=3;
    else if(X>=10)T=2;
    else T=1;
    if(T==1){
      for(int i=0,j=2;i<T;i++,j--){
        sub[j]=X%10;
        X/=10;
      }
      memset(memo1,-1,sizeof memo1);
      for(int i=0;i<10;i++)
         numeros[i]=b[i]-'0';
      if(var!=0)
        resultado=dp1(0,0,true,0);
      else
        resultado=dp1(temp,0,true,0);
      if(A!=0)
        temp=10-((int)(log10(A))+1);
      else
        temp=10-((int)(log10(1))+1);
      for(int i=0;i<10;i++)
        numeros[i]=a[i]-'0';
      if(var!=0)
        resultado-=dp1(0,0,true,0);
      else{
        memset(memo1,-1,sizeof memo1);
        resultado-=dp1(temp,0,true,0);
      }
      var=A;
      while(A){
        if(A%10==sub[2]){
          resultado++;
          break;
        }
        A/=10;
      }
      if(var==0 && var==0)resultado++;
     
      printf("%lld\n",resultado);
    }
    if(T==2){
      for(int i=0,j=2;i<T;i++,j--){
        sub[j]=X%10;
        X/=10;
       }
      memset(memo2,-1,sizeof memo2);
      for(int i=0;i<10;i++)
         numeros[i]=b[i]-'0';
      resultado=dp2(0,0,-1,true);
      for(int i=0;i<10;i++)
        numeros[i]=a[i]-'0';
      resultado-=dp2(0,0,-1,true);
      while(A){
        if((A%100)/10==sub[1] && A%10==sub[2]){
          resultado++;
          break;
        }
        A/=10;
      }
      printf("%lld\n",resultado);
    }
    if(T==3){
      for(int i=0,j=2;i<T;i++,j--){
        sub[j]=X%10;
        X/=10;
       }
      memset(memo3,-1,sizeof memo3);
      for(int i=0;i<10;i++)
         numeros[i]=b[i]-'0';
      resultado=dp3(0,0,-1,-1,true);
      for(int i=0;i<10;i++)
        numeros[i]=a[i]-'0';
      resultado-=dp3(0,0,-1,-1,true);
      while(A){
        if((A%1000)/100==sub[0]&& (A%100)/10==sub[1] && A%10==sub[2]){
          resultado++;
          break;
        }
        A/=10;
      }
      printf("%lld\n",resultado);

    
    }

  }


}
