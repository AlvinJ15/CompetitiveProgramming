#include <bits/stdc++.h>
using namespace std;
#define II *2+1
#define DD *2+2
#define mid (R+L)/2
#define MAX_N 2000001
int arr[MAX_N];
int ST[20000000];
int lazy[20000000];
int elem[1000001];
int N;
#define getcx getchar_unlocked
#define pc(x) putchar_unlocked(x);
    inline void writeInt (long long n)
      {
                long long N = n, rev, count = 0;
                        rev = N;
                                if (N == 0) { pc('0'); return ;}
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
inline void push(int index,int L,int R){
  if(!index)return;
  ST[index II]+=lazy[index];
  ST[index DD]+=lazy[index];
  lazy[index II]+=lazy[index];
  lazy[index DD]+=lazy[index];
  lazy[index]=0;
}
inline int build(int index,int L,int R){
  if(R==L)
    return ST[index]=arr[R];
  return ST[index]=min(build(index II,L,mid),build(index DD,mid+1,R));
}
inline int consultar(int index,int L,int R,int i,int j){
  if(L>=i && R<=j)
    return ST[index];
  if(R<i || L>j)return 1<<30;
  push(index,L,R);
  return min(consultar(index II,L,mid,i,j),consultar(index DD,mid+1,R,i,j));
}
inline int actualizar(int index,int L,int R,int i,int j,int val){
  if(L>=i && R<=j){
    lazy[index]+=val;
    return ST[index]+=val;
  }
  if(R<i || L>j)return ST[index];
  push(index,L,R);
  return ST[index]=min(actualizar(index II,L,mid,i,j,val),actualizar(index DD,mid+1,R,i,j,val));
}
main(){
	while(true){
    inp(N);
    if(!N)break;
    memset(arr,0,sizeof arr);
    memset(ST,0,sizeof ST);
    memset(lazy,0,sizeof lazy);
    int total=0;
    for(int i=0;i<N;i++){
      inp(elem[i]);
      total+=elem[i];
    }
    for(int i=0;i<N;i++){
      if(i==0)arr[i]=elem[i];
      else
      arr[i]=arr[i-1]+elem[i];
    }
    build(0,0,N*2-1);
    int R=0;
    for(int i=0;i<N;i++){
      if(consultar(0,0,N*2-1,i,N-1+i)>=0){
        R++;
      }
      actualizar(0,0,N*2-1,N+i,N+i,total);
      actualizar(0,0,N*2-1,i+1,N-1+i,-elem[i]);
    }
    writeInt(R);
    pc('\n');
  }


}
