#include <bits/stdc++.h>
using namespace std;
#define II *2+1
#define DD *2+2
#define mid (R+L)/2
int N,M,raiz,segmentos;
//long long ST[501][300000];
vector<int> SEG[501];
#define getcx getchar_unlocked
#define pc(x) putchar_unlocked(x);
    inline void writeInt (long long n)
      {
                long long N = n, rev, count = 0;
                        rev = N;
                                if (N == 0) { pc('0'); pc('\n'); return ;}
                                        while ((rev % 10) == 0) { count++; rev /= 10;} //obtain the count of the number of 0s
                                                rev = 0;
                                                        while (N != 0) { rev = (rev<<3) + (rev<<1) + N % 10; N /= 10;}  //store reverse of N in rev
                                                                while (rev != 0) { pc(rev % 10 + '0'); rev /= 10;}
                                                                        while (count--) pc('0');
                                                                            }
inline void inp(int&n){
  n=0;
  int ch=getcx();int sign=1;
  while(ch<'0'||ch>'9'){
    if(ch=='-')sign=-1;ch=getcx();
  }
  while(ch>='0'&&ch<='9')
    n=(n<<3)+(n<<1)+ch-'0',ch=getcx();
  n=n*sign;

}                                                                            
long long ST[501][300000];
int S[300000];
inline int consultar(int index,int L,int R,int i,int j){
  if(L>=i&&R<=j)return S[index];
  if(R<i || L>j)return 0;
  return consultar(index II,L,mid,i,j)+consultar(index DD,mid+1,R,i,j);
}
inline int actualizar(int index,int L,int R,int i,int j,int val){
  if(L>=i && R<=j)return S[index]+=val;
  if(R<i || L>j)return S[index];
  return S[index]=actualizar(index II,L,mid,i,j,val)+actualizar(index DD,mid+1,R,i,j,val);
}
inline int act2(int index,int L,int R,int i,int j,int val,int D){
  if(L>=i && R<=j)return ST[D][index]+=val;
  if(R<i || L>j)return ST[D][index];
  return ST[D][index]=act2(index II,L,mid,i,j,val,D)+act2(index DD,mid+1,R,i,j,val,D);
}
inline int consultar(int index,int L,int R,int i,int j,int D){
  if(L>=i && R<=j)return ST[D][index];
  if(R<i || L>j)return 0;
  return consultar(index II,L,mid,i,j,D)+consultar(index DD,mid+1,R,i,j,D);
}
int arr[250005];
inline int contar(int a,int b){
  int var=a/raiz;
  int res=0;
  for(int i=0;i<var;i++){
    res+=consultar(0,0,50002,b+1,50002,i);
  }
  for(int i=var*raiz;i<a;i++){
    if(arr[i]>b)
      res++;
  }
  return res;
}
int foo(int a,int b){
  int var=a/raiz;
  int res=0;
  for(int i=0;i<var;i++){
    res+=consultar(0,0,50002,0,b-1,i);
  }
 
  for(int i=var*raiz;i<a;i++){
    if(b>arr[i])
      res++;
  }
  return res;
}
inline int contar2(int a,int b){
  int var =(raiz-(a%raiz))%raiz;
  int resp=0;
  for(int i=0;i<var&&a<N;i++,a++){
    if(arr[a]<b)
      resp++;
  }
  var=ceil(a/(double)raiz);
  for(int i=var;i<segmentos;i++){
    resp+=consultar(0,0,50002,0,b-1,i);
  }
  return resp;
}
/*int contar2(int a,int b){
  return foo(N,b)-foo(a,b);
}*/
vector<long long> A;
main(){
  int a,b,var;
  long long total,resp;
 inp(N);
  raiz=sqrt(N);
  segmentos=ceil(N/((double)raiz));
  memset(S,0,sizeof S);
  memset(ST,0,sizeof ST);
  total=0;
  for(int i=0;i<N;i++)
    inp(arr[i]);
  for(int i=N-1;i>=0;i--){
    total+=consultar(0,0,50002,0,arr[i]-1);
    actualizar(0,0,50002,arr[i],arr[i],1);
  }
  var=N/raiz;
  for(int i=0;i<N;i++){
    act2(0,0,50002,arr[i],arr[i],1,i/raiz);
  }
 // var=N-var*raiz;
  inp(M);
  while(M--){
    resp=0;
    inp(a);
    inp(b);
    total-=contar(a,arr[a-1]);
    total-=contar2(a,arr[a-1]);
    total+=contar2(a,b);
   // if(a<=(N/raiz)*raiz){
      act2(0,0,50002,arr[a-1],arr[a-1],-1,a/raiz);
      act2(0,0,50002,b,b,1,a/raiz);
    //}
    arr[a-1]=b;
    total+=contar(a,b);
    A.push_back(total);

  }
  for(int i=0;i<A.size();i++){
    writeInt(A[i]);
    pc('\n');
  }



}
