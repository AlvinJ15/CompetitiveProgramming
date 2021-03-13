#include <bits/stdc++.h>
using namespace std;
#define MAXN 1000005
int N,M,X,Y,C;
long long memo[2][MAXN];
vector<int> values;
#define INFINITE 1e15

int log_table[MAXN+1];
int array_distances[MAXN];
#define K 20
int STONES_N;
/*bool st[MAXN][K + 1];
int i_st[MAXN][K+1];*/
bool t[5*MAXN];
int i_t[5*MAXN];
void buildRMQ(){
/*
    log_table[1] = 0;
    for (int i = 2; i <= STONES_N; i++)
        log_table[i] = log_table[i/2] + 1;

    for (int i = 0; i < STONES_N; i++){
        st[i][0] = array_distances[i];
        i_st[i][0] =i;
    }

    for (int j = 1; j <= K; j++)
        for (int i = 0; i + (1 << j) <= STONES_N; i++){
            int c=i+(1 <<(j-1));
            if(st[i][j-1] < st[c][j-1]){
                st[i][j]= st[i][j-1];
                i_st[i][j] = i_st[i][j-1];
            }
            else{
                st[i][j]= st[c][j-1];
                i_st[i][j] = i_st[c][j-1];
            }
        }

*/
    int n= STONES_N;
  for (int i = n - 1; i > 0; --i){
      if(t[i<<1]< t[i<<1|1]){
        t[i] = t[i<<1];
        i_t[i] = t[i<<1];
      }
      else{
        t[i] = t[i<<1|1];
        i_t[i] = t[i<<1|1];
      }
  }
}

int queryRMQ(int L, int R){
    /*int j = log_table[R - L + 1];
    if(st[L][j] < st[R-(1<<j)+1][j]){
        return i_st[L][j];
    }
    else{
        return i_st[R-(1<<j)+1][j];
    }*/

    int res = 1e9;
    int ind = -1;
    int n= STONES_N;
    int l=L;
    int r=R+1;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
        if (l&1){
           if(t[l++]<res){
              res = t[l-1];
              ind = i_t[l-1];
           }     
        }
        if (r&1){
            if(t[--r]<res){
                res = t[r];
                ind = i_t[r];
            }
        
        } 
    }
    return ind;
}

int main(){
    int val;
    scanf("%d%d",&N,&M);
    memset(memo,-1,sizeof(memo));
    values.push_back(1);
    for(int i=0;i<N;i++){
        scanf("%d",&val);
        values.push_back(val);
    }
    N=N+2;
    STONES_N=N;
    values.push_back(M);

    scanf("%d%d",&X,&Y);

    memo[0][N-1]=0;
    memo[1][N-1]=0;
    
    memset(array_distances,0,sizeof(array_distances));
    for(int i=1;i<N;i++){
        //array_distances[i]=(values[i]-values[i-1])<=X?0:1;
        t[i+N]=(values[i]-values[i-1])<=X?0:1;
        i_t[i+N]=i;
    }
    buildRMQ();
    for(int n=N-2;n>=0;n--){
        for(int flag=0;flag<2;flag++){
            if(flag){
                int lower_index = lower_bound(values.begin(),values.end(), values[n]+X)-values.begin();
                if(values[lower_index] != values[n]+X)
                    lower_index--;
                if(lower_index==n){
                    memo[flag][n] = INFINITE;
                }else{
                    memo[flag][n]=1+memo[!flag][lower_index];
                }
            }
            else{
                int lower_index_X = lower_bound(values.begin(),values.end(), values[n]+X)-values.begin();
                if(values[lower_index_X] != values[n]+X)
                    lower_index_X--;
                int lower_index_Y = lower_bound(values.begin(), values.end(), values[n]+Y)-values.begin();
                if(values[lower_index_Y] != values[n]+Y)
                    lower_index_Y--;
                if(lower_index_X == n){
                    if(lower_index_Y == n){
                        memo[flag][n] = INFINITE;       
                    }
                    else{
                        memo[flag][n] = 1+memo[!flag][lower_index_Y];
                        int index = queryRMQ(n+1, lower_index_Y);
                        if(array_distances[index]==0){
                            if(index-1>n){
                                memo[flag][n] = min(memo[flag][n], 1+ memo[!flag][index-1]);
                            }
                        }
                    }
                }
                else{
                    if(lower_index_Y == n){
                        memo[flag][n] = 1+memo[flag][lower_index_X];
                    }
                    else{
                        memo[flag][n]=1+min(memo[flag][lower_index_X],memo[!flag][lower_index_Y]);
                        int index = queryRMQ(n+1, lower_index_Y);
                        if(array_distances[index]==0){
                            if(index-1>n){
                                memo[flag][n] = min(memo[flag][n], 1+ memo[!flag][index-1]);
                            }
                        }
                    }
                }
            }
        }
    }

    long long resp = memo[0][0];
    if(memo[0][0]<1 || memo[0][0]>= 1e12){
        resp=-1;
    }
    printf("%lld\n", resp);
}
