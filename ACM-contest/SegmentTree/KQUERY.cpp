#include <bits/stdc++.h>
using namespace std;
#define getcx getchar_unlocked
#define pc(x) putchar_unlocked(x);
inline void writeInt (int n)
{
  int N = n, rev, count = 0;
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

vector<int> ST[120000];
int elem[30005];
vector<int>::iterator low;
inline void build(int index,int L,int R){
  if(L==R){
    ST[index].push_back(elem[L]);
  }
  else{
    build((index<<1)+1,L,(R+L)>>1);
    build((index<<1)+2,((R+L)>>1)+1,R);
    ST[index]=vector<int>(R-L+1);
    merge(ST[(index<<1)+1].begin(),ST[(index<<1)+1].begin()+ST[(index<<1)+1].size(),ST[(index<<1)+2].begin(),ST[(index<<1)+2].begin()+ST[(index<<1)+2].size(),ST[index].begin());
  }
}
inline int consultar(int index,int L,int R,int l,int r,int k){
  if(L>=l && R<=r){
    low=upper_bound(ST[index].begin(),ST[index].end(),k);
    return ST[index].size()-(low-ST[index].begin());
  }
  if(R<l || L>r)return 0;
  return consultar((index<<1)+1,L,((R+L)>>1),l,r,k)+consultar((index<<1)+2,((R+L)>>1)+1,R,l,r,k);
}
main(){
  int N,Q,k,a,b;
  inp(N);
  for(int i=0;i<N;i++){
    inp(elem[i]);
  }
  build(0,0,N-1);
  inp(Q);
  vector<int> resp;
  for(int i=0;i<Q;i++){
    inp(a);
    inp(b);
    inp(k);
    resp.push_back(consultar(0,0,N-1,a-1,b-1,k));
  }
  for(int i=0;i<resp.size();i++){
    writeInt(resp[i]);
    pc('\n');
  }


}
