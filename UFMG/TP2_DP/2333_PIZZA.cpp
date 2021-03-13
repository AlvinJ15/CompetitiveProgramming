#include <bits/stdc++.h>
using namespace std;
int N;
int memo[2][2][3][200005];
int values[200005];
#define EMPTY_VALUE 1e9
#define NEGATIVE_INF -1e8
int dp(int left,int open, int segments, int n){
    if(segments>=3)
        return NEGATIVE_INF;
    if(left==1 && segments==0)
        return NEGATIVE_INF;
    if(segments>=2 && left==0)
        return NEGATIVE_INF;
    if(open==0 && segments==2)
        return NEGATIVE_INF;
    if(left==0 && segments>=2 && open==0)
        return NEGATIVE_INF;
    if(left==1&&segments==2&&open==0){
        return NEGATIVE_INF;}
    if(n==N)
        return 0;

    if(memo[left][open][segments][n]!=EMPTY_VALUE){
        return memo[left][open][segments][n];
    }

    if(n==0){
        if(left==0){
            if(open==0){
                if(segments==0){
                    return memo[left][open][segments][n] = max(values[n]+dp(!left,!open,segments+1,n+1), dp(left,open,segments,n+1));
                }
                else{
                    return memo[left][open][segments][n] = NEGATIVE_INF;
                }
            }
            else{
                return memo[left][open][segments][n] = NEGATIVE_INF;
            }
        }
        else{
            return memo[left][open][segments][n] = NEGATIVE_INF;
        }
    }
    else{
        if(left==0){
            if(open==0){
                if(segments==0){
                    return memo[left][open][segments][n] = max(values[n]+dp(left,!open,segments+1,n+1), dp(left, open, segments, n+1));
                }
                else{
                    return memo[left][open][segments][n] = max(values[n]+dp(left,!open,segments+1,n+1), dp(left,open,segments,n+1));
                }
            }
            else{
                if(segments==0){
                    return memo[left][open][segments][n] = NEGATIVE_INF;
                }
                else{
                    return memo[left][open][segments][n] = max(values[n]+dp(left,open,segments,n+1), dp(left,!open,segments,n+1));
                }
            }
        }
        else{
            if(open==0){
                if(segments==0){
                    return memo[left][open][segments][n] = NEGATIVE_INF;
                }
                else{
                    return memo[left][open][segments][n] = max(values[n]+dp(left,!open,segments+1,n+1),dp(left,open,segments,n+1));
                }
            }
            else{
                if(segments==0){
                    return memo[left][open][segments][n] = NEGATIVE_INF;
                }
                else{
                    return memo[left][open][segments][n] = max(values[n]+dp(left,open,segments,n+1), dp(left,!open,segments,n+1));
                }
            }
        }
    
    }

}

int main(){
    scanf("%d", &N);

    for(int i =0;i<N;i++){
        scanf("%d", &values[i]);
    }
    for(int i=0;i<2;i++)
        for(int j=0;j<2;j++)
            for(int h=0;h<3;h++)
                for(int k=0;k<N;k++)
                    memo[i][j][h][k]= EMPTY_VALUE;

    printf("%d\n", dp(0,0,0,0));
}
