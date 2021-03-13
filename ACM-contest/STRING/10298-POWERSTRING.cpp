#include <bits/stdc++.h>
using namespace std;
#define MAX_N 1000010
vector<int> divisores;
char T[MAX_N];
int n;
int RA[MAX_N],tempRA[MAX_N];
int SA[MAX_N],tempSA[MAX_N];
int Phi[MAX_N];
int PLCP[MAX_N];
int LCP[MAX_N];
int c[MAX_N];
int hashi[1000005];
void countingSort(int k){
  int i,sum,maxi=max(300,n);
  memset(c,0,sizeof c);
  for(i=0;i<n;i++)
    c[i+k<n?RA[i+k]:0]++;
  for(i=sum=0;i<maxi;i++){
    int t=c[i];c[i]=sum;sum+=t;
  }
  for(i=0;i<n;i++)
    tempSA[c[SA[i]+k<n?RA[SA[i]+k]:0]++]=SA[i];
  for(i=0;i<n;i++)
    SA[i]=tempSA[i];
}
void constructSA(){
  int i,k,r;
  for(i=0;i<n;i++)RA[i]=T[i];
  for(i=0;i<n;i++)SA[i]=i;
  for(k=1;k<n;k<<=1){
    countingSort(k);
    countingSort(0);
    tempRA[SA[0]]=r=0;
    for(i=1;i<n;i++){
      tempRA[SA[i]]=(RA[SA[i]]==RA[SA[i-1]]&&RA[SA[i]+k]==RA[SA[i-1]+k])?r:++r;
    }
    for(i=0;i<n;i++){
      RA[i]=tempRA[i];
    }
    if(RA[SA[n-1]]==n-1)break;
  }
}
void computeLCP(){
  
  int i,L;
  Phi[SA[0]]=-1;
  for(i=1;i<n;i++)
    Phi[SA[i]]=SA[i-1];
  for(i=L=0;i<n;i++){
    if(Phi[i]==-1){
      PLCP[i]=0;continue;
    }
    while(T[i+L]==T[Phi[i]+L])L++;
    PLCP[i]=L;
    L=max(L-1,0);
  }
  memset(hashi,0,sizeof hashi);
  for(i=0;i<n;i++){
    LCP[i]=PLCP[SA[i]];
    hashi[LCP[i]]++;
  }
}
char P[MAX_N];
int b[MAX_N],m;
void kmpPreprocess(){
  memset(b,0,sizeof b);
  int i=0,j=-1;b[0]=-1;
  while(i<m){
    while(j>=0 &&P[i]!=P[j])j=b[j];
    i++;j++;
    b[i]=j;
  }
}
void kmpPreprocess2(){
  memset(b,0,sizeof b);
  for(int i=1;i<m;i++){
    if(P[i]==P[b[i-1]]){
      b[i]=b[i-1]+1;
    }
    else b[i]=0;
  }
}
main(){
	while(true){
    //scanf("%1000010s",T);
    scanf("%1000010s",P);
   
    //  if(T[0]=='.')break;

    if(P[0]=='.')break;
    //n = (int)strlen(T);
    m=(int)strlen(P);

   /* int lon=(int)strlen(P);
   // T[n++]='$';
    //constructSA();
    int raiz = ceil(sqrt(lon));
   // computeLCP(); 
    divisores.clear();
    for(int i=1;i<raiz;i++){
          if(!(lon%i)){
            divisores.push_back(i);
            divisores.push_back(lon/i);
          }
    }
    if(raiz*raiz==lon)divisores.push_back(raiz);
    sort(divisores.begin(),divisores.end());
    for(int i=0;i<divisores.size();i++){
      int div = lon/divisores[i];
      bool flag=true;
      for(int j=0;j<div;j++){
        if(!hashi[divisores[i]*j]){
          flag=false;
          break;
        }
      }
      if(flag){
        printf("%d\n",div);
        break;
      }
    }
*/  if(m==1){printf("%d\n",1);
      continue;
      }

    kmpPreprocess();
    int contar=0;
    int pos=0;
    bool encontrado=false;
    for(int i=m;i>=1;i--){
      if(b[i]==0)break;
      else{
        if(b[i]==1){
          pos=i;
          encontrado=true;
          break;
        }
        if(b[i]!=b[i-1]+1){
          pos=i-1;
          encontrado=true;
          break;
        }
      }
    }
    if(!encontrado||pos==1){
      printf("%d\n",1);
      continue;
    }
    int tam = pos-1;
    if(m%tam!=0){
       printf("%d\n",1);
       continue;
    }
     else{
         printf("%d\n",m/tam);
    }


  }


}
