#include <bits/stdc++.h>
using namespace std;
#define II *2+1
#define DD *2+2
#define mid (L+R)/2
int ST[4000000];
  int n;
  int arr[1000000];
  int k;
int build(int index,int L,int R){
  if(L==R){
    return ST[index]=arr[L];
  }
  else{
    return ST[index]=max(build(index II,L,mid),build(index DD,mid+1,R));
  }
}
int consultar(int index,int L,int R,int l,int r){
  if(L>=l && R<=r)return ST[index];
  if(L>r || R<l)return -100000000;
  return max(consultar(index II,L,mid,l,r),consultar(index DD,mid+1,R,l,r));
}
main(){
  scanf("%d",&n);
  for(int i=0;i<n;i++){
    scanf("%d",&arr[i]);
  }
  build(0,0,n-1);
  scanf("%d",&k);
  int pos=0;
  for(int i=k-1;i<n;i++,pos++){
    printf("%d ",consultar(0,0,n-1,pos,i));
    
  }
  



}
