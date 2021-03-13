#include <bits/stdc++.h>
using namespace std;
bool mark[100003];
main(){
  int T,N,K;
  scanf("%d",&T);
  int div;
  memset(mark,0,sizeof mark);
  vector<int> markados;
  for(int f=0;f<T;f++){
    scanf("%d",&N);
    markados.clear();
    int raiz = floor(sqrt(N));
    int sum=0;
    bool isSQRT = (raiz*raiz)==N;
    for(int i=2;i<=raiz;i++)
        if(N%i==0){
          sum+=2;
          div=i;
          for(int j=div*2;j<N;j+=div)
            if((N%j && !mark[j])){
              sum++;
              mark[j]=1;
              markados.push_back(j);
            }

          div=N/i;
          for(int j=div*2;j<N&&!isSQRT;j+=div)
            if((N%j&&!mark[j])){
              sum++;
              mark[j]=1;
              markados.push_back(j);
            }
        }
    if(raiz*raiz==N)sum--;
    for(int i=0;i<markados.size();i++){
      mark[markados[i]]=0;
    }
    printf("%d\n",N-sum-1);
  }


}
