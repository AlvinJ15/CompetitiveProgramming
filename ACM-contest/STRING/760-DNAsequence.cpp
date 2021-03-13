#include <bits/stdc++.h>
using namespace std;
#define MAX_N 1000
char T[MAX_N];
int n;
int RA[MAX_N],tempRA[MAX_N];
int SA[MAX_N],tempSA[MAX_N];
int c[MAX_N];
int Phi[MAX_N];
int LCP[MAX_N];
int PLCP[MAX_N];
void countingSort(int k){
  int i,sum,maxi=max(300,n);
  memset(c,0,sizeof c);
  for(i=0;i<n;i++){
    c[i+k<n?RA[i+k]:0]++;
  }
  for(i=sum=0;i<maxi;i++){
    int t=c[i];c[i]=sum;sum+=t;}
  for(i=0;i<n;i++)
    tempSA[c[SA[i]+k<n?RA[SA[i]+k]:0]++]=SA[i];
  for(i=0;i<n;i++)
    SA[i]=tempSA[i];
}
void constructSA(){
  int i,k,r;
  for(i=0;i<n;i++)RA[i]=T[i];
  for(i=0;i<n;i++){SA[i]=i;}
  for(k=1;k<n;k<<=1){
    countingSort(k);
    countingSort(0);
    tempRA[SA[0]]=r=0;
    for(i=1;i<n;i++)
      tempRA[SA[i]]=(RA[SA[i]]==RA[SA[i-1]]&&RA[SA[i]+k]==RA[SA[i-1]+k])?r:++r;
    for(i=0;i<n;i++)
      RA[i]=tempRA[i];
    if(RA[SA[n-1]]==n-1)break;
  }
}
void computeLCP(){
  int i,L;
  Phi[SA[0]]=-1;
  for(i=1;i<n;i++)
    Phi[SA[i]]=SA[i-1];
  for(i=L=0;i<n;i++){
    if(Phi[i]==-1){PLCP[i]=0;continue;}
    while(T[i+L]==T[Phi[i]+L])L++;
    PLCP[i]=L;
    L=max(L-1,0);
  }
  for(i=0;i<n;i++)
    LCP[i]=PLCP[SA[i]];
}
int fact(int num){
  int sum=1;
  while(num){
    sum*=num--;
  }
  return sum;
}
char T2[1000];
main(){
  int cases=1;
  while(scanf("%310s",T)!=EOF){
    if(cases!=1)
      printf("\n");
    cases++;
    n=(int)strlen(T);
    if(T[0]=='*')break;
    T[n++]='$';
    int prev = n-1;
    scanf("%310s",T2);
    int n2 = strlen(T2);
    for(int i=0;i<n2;i++){
      T[n++]=T2[i];
    }
    T[n++]='#';
    constructSA();
    computeLCP();
    int num=0;
    bool flag=true;
    vector<int> elems;
    vector<string> resp;
    int maxim=-1;
    for(int i=1;i<n;i++){
      if(((SA[i]<prev && SA[i-1]>prev)||(SA[i]>prev && SA[i-1]<prev))&&LCP[i]!=0){
        maxim=max(LCP[i],maxim);
        elems.push_back(i);
      }
    }
    if(elems.size()==0){
     printf("No common sequence.\n");
     continue;
    }
    for(int i=0;i<elems.size();i++){
      if(LCP[elems[i]]==maxim){
        string aux="";
        for(int j=0;j<LCP[elems[i]];j++){
          aux+=T[SA[elems[i]]+j];
          //printf("%c",T[SA[elems[i]]+j]);
        }
        resp.push_back(aux);
      //printf("\n");
      }
    }
    cout<<resp[0]<<endl;
    for(int i=1;i<resp.size();i++){
      if(resp[i-1].compare(resp[i])!=0)
        cout<<resp[i]<<endl;
    }
  // printf("\n");
   /* for(int i=1;i<n;i++){
      if(LCP[i]!=LCP[i-1]&&LCP[i]!=0){
        flag=false;
        num+=1;//LCP[i];
      }
    }
*/
 //   for(int i=0;i<n;i++)printf("%2d\t%s\t%2d\n",SA[i],T+SA[i],LCP[i]);
 
    }	


}
