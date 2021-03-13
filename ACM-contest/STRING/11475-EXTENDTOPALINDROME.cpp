#include <bits/stdc++.h>
using namespace std;
#define MAX_N 100010
char T[MAX_N],P[MAX_N];
int b[MAX_N],n,m;
int i,j;
void kmpPreprocess(){
  memset(b,0,sizeof b);
  i=0;j=-1;b[0]=-1;
  while(i<m){
    while(j>=0 &&P[i]!=P[j])j=b[j];
    i++;j++;
    b[i]=j;
  }
}
void kmpSearch(){

  i=0,j=0;
  while(i<n){
    while(j>=0 && T[i]!=T[n-1-j]){j=b[j];
    }
    i++;j++;
    if(i==n-1-j || i-1==n-1-j){
      break;
    }
  }
}
main(){
	while(scanf("%100010s",T)!=EOF){
    int tam = strlen(T);
    n=tam;
    m=tam;
    for(int h=0;h<tam;h++){
      P[h]=T[tam-h-1];
    }
    kmpPreprocess();
    kmpSearch();
    printf("%s",T);
    //cout<<i<<" "<<j<<endl;
    for(int h=i-j-1;h>=0;h--){
        printf("%c",T[h]);
    }
    printf("\n");
    memset(T,0,sizeof T);
    memset(P,0,sizeof P);

  }

}
