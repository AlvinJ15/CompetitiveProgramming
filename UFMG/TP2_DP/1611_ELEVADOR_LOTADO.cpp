#include <bits/stdc++.h>
using namespace std;

int main(){
    int T,C,M,N;
    int floor;
    long long total;
    scanf("%d",&T);
    while(T--){
        vector<int> to_visit;
        scanf("%d%d%d", &N, &C, &M);
        while(M--){
            scanf("%d", &floor);
            to_visit.push_back(floor);
        }

        sort(to_visit.begin(),to_visit.end());
        reverse(to_visit.begin(),to_visit.end());
        total=0UL;
        for(int i=0;i<to_visit.size();i+=C){
            total+=2*to_visit[i];
        }

        printf("%lld\n", total);
    }
}
