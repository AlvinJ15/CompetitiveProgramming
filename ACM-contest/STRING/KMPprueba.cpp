#include <bits/stdc++.h>
using namespace std;
#define MAX_N 10010
char T[MAX_N],P[MAX_N];
int b[MAX_N],n,m;
void kmpPreprocess(){
  int i=0,j=-1;b[0]=-1;
  while(i<m){
    while(j>=0 &&P[i]!=P[j])j=b[j];
    i++;j++;
    b[i]=j;
  }
}

main(){
  while(true){
    scanf("%1000010s",P);
    m=(int)strlen(P);
    cout<<m<<endl;
    kmpPreprocess();
    for(int i=0;i<m+1;i++){
      printf("%d ",b[i]);
    }
  cout<<endl;

  }
}
