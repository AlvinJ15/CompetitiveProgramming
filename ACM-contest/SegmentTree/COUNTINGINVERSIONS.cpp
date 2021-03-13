#include <bits/stdc++.h>
using namespace std;
#define II <<1)+1
#define DD <<1)+2
#define mid (R+L)>>1)
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
int indices[50002];
inline void build(int index,int L,int R){
  if(L==R){
    indices[L]=index;
  }
  else{
    build((index<<1)+1,L,(mid);
    build((index<<1)+2,(mid+1,R);
  }
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

int S[300000];
inline int consultar(int index,int L,int R,int i,int j){
  if(L>=i&&R<=j)return S[index];
  if(R<i || L>j)return 0;
  return consultar((index II,L,(mid,i,j)+consultar((index DD,(mid+1,R,i,j);
}
/*inline int actualizar(int index,int L,int R,int i,int j,int val){
  if(L>=i && R<=j)return S[index]+=val;
  if(R<i || L>j)return S[index];
  return S[index]=actualizar((index II,L,(mid,i,j,val)+actualizar((index DD,(mid+1,R,i,j,val);
}
int act2(int index,int L,int R,int i,int j,int val,int D){
  if(L>=i && R<=j)return ST[D][index]+=val;
  if(R<i || L>j)return ST[D][index];
  return ST[D][index]=act2((index II,L,(mid,i,j,val,D)+act2((index DD,(mid+1,R,i,j,val,D);
}
int consultar(int index,int L,int R,int i,int j,int D){
  if(L>=i && R<=j)return ST[D][index];
  if(R<i || L>j)return 0;
  return consultar((index II,L,(mid,i,j,D)+consultar((index DD,(mid+1,R,i,j,D);
}*/
int arr[250005];
vector<int>::iterator it;
inline int contar(int a,int b){
  int var=a/raiz;
  int res=0;
  for(int i=0;i<var;i++){
    it=upper_bound(SEG[i].begin(),SEG[i].end(),b);
    res+=SEG[i].size()-(it-SEG[i].begin());
    //res+=consultar(0,0,50002,b+1,50002,i);
  }
  for(int i=var*raiz;i<a;i++){
    if(arr[i]>b)
      res++;
  }
  return res;
}
inline int foo(int a,int b){
  int var=a/raiz;
  int res=0;
  for(int i=0;i<var;i++){
    it=lower_bound(SEG[i].begin(),SEG[i].end(),b);
    res+=(it-SEG[i].begin());
    //res+=consultar(0,0,50002,0,b-1,i);
  }
  for(int i=var*raiz;i<a;i++){
    if(b>arr[i])
      res++;
  }
  return res;
}

int divisiones[250002];
void lower(int i,int f,int elem,int&pos,int s){
  int medio=(i+f)/2;
  if(f<i)return;
  if(SEG[s][medio]>=elem){
    pos=min(pos,medio);
    lower(i,medio-1,elem,pos,s);
  }
  else
    lower(medio+1,f,elem,pos,s);
}
inline int contar2(int a,int b){
  int var =(raiz-(a%raiz))%raiz;
  int resp=0;
  for(int i=0;i<var&&a<N;i++,a++){
    if(arr[a]<b)
      resp++;
  }
  //var=a/raiz;
  //if(var*raiz!=var)
   // var+=1;
  var=ceil(a/(double)raiz);
  //var=divisiones[a];
  //var=0;
  int pos=1<<30;
  for(int i=var;i<segmentos;i++){
    pos=SEG[i].size();;
    lower(0,SEG[i].size()-1,b,pos,i);
    resp+=pos;
    //it=lower_bound(SEG[i].begin(),SEG[i].end(),b);
    //resp+=(it-SEG[i].begin());
  }
  return resp;
}
inline void update(int index){
  if(!index)return;
  int var;
  while(index){
    var=(index-1)>>1;
    S[var]=S[(var<<1)+1]+S[(var<<1)+2];
    index=var;
  }
  S[0]=S[1]+S[2];
}
vector<long long > A;
int querys[10000][2];
main(){
  int a,b,var;
  long long total,resp;
  inp(N);
  raiz=sqrt(N);
  memset(S,0,sizeof S);
  //memset(ST,0,sizeof ST);
  total=0;
  build(0,0,50002);
  for(int i=0;i<N;i++)
    inp(arr[i]);
  for(int i=N-1;i>=0;i--){
    total+=consultar(0,0,50002,0,arr[i]-1);
    S[indices[arr[i]]]++;
    update(indices[arr[i]]);
    //actualizar(0,0,50002,arr[i],arr[i],1);
  }
  segmentos=ceil(N/((double)raiz));
  var=N/raiz;
  for(int i=0;i<N;i++){
      SEG[i/raiz].push_back(arr[i]);
  //  act2(0,0,50002,arr[i],arr[i],1,i/raiz);
  }
  for(int i=0;i<segmentos;i++)
    sort(SEG[i].begin(),SEG[i].end());
  // var=N-var*raiz;
  inp(M);
  int aux;
  int R=(N/raiz)*raiz;
  for(int i=0;i<M;i++){
    inp(querys[i][0]);
    inp(querys[i][1]);
  }
  for(int o=0;o<M;o++){
   // writeInt(M);
    //writeInt('\n');
    resp=0;
    a=querys[o][0];
    b=querys[o][1];
    //inp(a);
    //inp(b);
    total-=contar2(a,arr[a-1]);
    total-=contar(a,arr[a-1]);
    total+=contar2(a,b);
    //total+=contar2(a,b)-(contar(a,arr[a-1])+contar2(a,arr[a-1]));
    //if(a<=R){
      aux=(a-1)/raiz;
    for(int i=0;i<SEG[aux].size();i++){
        if(SEG[aux][i]==arr[a-1]){
          SEG[aux][i]=b;
          if(SEG[aux][i]<arr[a-1]){
            for(int j=i;j>0&&b<SEG[aux][j-1];j--){
              swap(SEG[aux][j],SEG[aux][j-1]);
            }
          }
          else{
            for(int j=i;j<SEG[aux].size()-1&&b>SEG[aux][j+1];j++){
              swap(SEG[aux][j],SEG[aux][j+1]);
            }
          }
          break;
        }
     // }
     // sort(SEG[aux].begin(),SEG[aux].end());
      //act2(0,0,50002,arr[a-1],arr[a-1],-1,a/raiz);
      //act2(0,0,50002,b,b,1,a/raiz);
    }
    arr[a-1]=b;
    total+=contar(a,b);
    A.push_back(total);
   // writeInt(total);
   // pc('\n');

  }
  for(int i=0;i<A.size();i++){
    writeInt(A[i]);
    pc('\n');
  //  printf("%lld\n",A[i]);
  }



}
