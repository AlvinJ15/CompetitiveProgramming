#include <bits/stdc++.h>
using namespace std;
#define II *2+1
#define DD *2+2
#define mid (R+L)/2
int arr[100004];
int elem[100004];
int contar(int n){
   int a=arr[n],c=0;
   while(arr[n]==a){
     c++;
     n++;
   }
   return c;
}
map<int,pair<int,int> > mapa;
int ST[400000];
int build(int index,int L,int R){
  if(L==R)
    return ST[index]=elem[L];
  else{
    return ST[index]=max(build(index II,L,mid),build(index DD,mid+1,R));
  }
}
int consultar(int index,int L,int R,int l,int r){
  if(l>r)return -1;
  if(L>=l && R<=r)
    return ST[index];
  if(R<l || L>r)
    return -1;
  return max(consultar(index II,L,mid,l,r),consultar(index DD,mid+1,R,l,r));
}
int max3(int a,int b,int c){
  return max(a,max(b,c));
}
main(){
  int N,Q,a,b,l,r;
  pair<int,int> first,second;
  while(scanf("%d%d",&N,&Q),N!=0){
    for(int i=0;i<N;i++){
      scanf("%d",&arr[i]);
    }
    memset(elem,0,sizeof elem);
    mapa.clear();

    for(int i=0;i<N;i++){
      if(elem[i]==0){
        int var=contar(i);
        mapa.insert(make_pair(arr[i],make_pair(i,i+var-1)));
        for(int j=0;j<var;j++){
          elem[i+j]=var;
        }
      }
    }
    build(0,0,N-1);
    while(Q--){
      scanf("%d%d",&a,&b);
      a--;b--;
      first=mapa[arr[a]];
      second=mapa[arr[b]];
  //      cout<<first.first<<" "<<first.second<<endl;
    //    cout<<second.first<<" "<<second.second<<endl;
      if(first.first==a && second.second==b){
        printf("%d\n",consultar(0,0,N-1,a,b));
        
      }
      else{
        if(arr[a]==arr[b]){
          printf("%d\n",b-a+1);
          continue;
        }
        l=a;r=b;
        if(first.first!=a)
          l=first.second+1;
        if(second.second!=b)
          r=second.first-1;
        int R=max3(l-a,b-r,consultar(0,0,N-1,l,r));
        printf("%d\n",R);
      }
    }
  }

}
