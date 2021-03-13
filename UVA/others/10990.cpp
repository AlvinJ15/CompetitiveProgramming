#include <bits/stdc++.h>
using namespace std;

#define MAX_N 2000005 
bool isP[MAX_N] ;
int phi[MAX_N];
int memo[MAX_N];
int partialsum[MAX_N];

void Sieve(){
  memset ( isP , true , sizeof isP) ;
  long long i, j ;
  isP[0] = isP[1] = false ;
  for ( i  = 2 ; i <= MAX_N ; i++)
    if (isP[i]){
       for ( j = i ; j <= MAX_N ; j += i){
        phi[j] = phi[j]/i*(i-1);
        isP[j] = false ;
       }
    }
}
int dp(int num){
    if(num==1)return 0;
    if(memo[num]!=-1)return memo[num];
    return memo[num]=1+dp(phi[num]);
}

int main() {
    memset(memo,-1,sizeof memo);
    int i, j, k;
    for(i = 2; i < MAX_N; i++)
        phi[i] = i;
    Sieve();

    partialsum[0]=0;
    for(int i =1;i<MAX_N;i++){
        partialsum[i]=partialsum[i-1] + dp(i);
    }
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%d %d", &i, &j);
        printf("%d\n", partialsum[j]-partialsum[i-1]);
    }

    return 0;
}