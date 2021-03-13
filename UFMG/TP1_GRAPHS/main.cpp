#include <bits/stdc++.h>
using namespace std;

#define INF 1000000
int adj[300][300];
int path[300][300];

vector<int> getPath(int u,int v, vector<int> vertexs){
    int k = path[u][v];
    if(k!=-1){
        vertexs = getPath(u,k, vertexs);
        vertexs.push_back(k);
        vertexs = getPath(k,v, vertexs);
        return vertexs;
    }

    return vertexs;
}

int main(){
    int n,m,u,v;
    while(scanf("%d%d", &n,&m)!=EOF){
        memset(path,-1, sizeof path);
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++){
                adj[i][j]=i!=j?INF:0;
            }

        while(m--){
            scanf("%d%d", &u,&v);
            scanf("%d", &adj[u-1][v-1]);
            adj[v-1][u-1]=adj[u-1][v-1];
        }
        
        int max_u, max_v;
        int max_diameter = -1;
         for (int k = 0; k < n; k++)  
            for (int i = 0; i < n; i++)  
                for (int j = 0; j < n; j++)
                    if(adj[i][j] > adj[i][k] + adj[k][j]){
                        adj[i][j] = adj[i][k]+adj[k][j];
                        if (k!=j && k!=i)
                            path[i][j] = k;
                    }

        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++){
                if(adj[i][j] > max_diameter && adj[i][j] < INF){
                    max_diameter = adj[i][j];
                    max_u=i;
                    max_v=j;
                }
            }

        printf("%d\n", max_diameter);
        printf("%d %d\n", max_u+1, max_v+1);
        
        vector<int> vertex;
        vertex = getPath(max_u,max_v, vertex);
        printf("%d\n", (int)vertex.size()+2);

        printf("%d", max_u+1);
        for (int i=0; i<vertex.size();i++)
            if(path[i])
                printf(" %d", vertex[i]+1);
            
        printf(" %d\n", max_v+1);
    }

    return 0;
}

