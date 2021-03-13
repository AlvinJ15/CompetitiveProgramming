#include <bits/stdc++.h>
    using namespace std;

    int main(){
        int n;
        int tamano=1000025;
        int arr[tamano];
        scanf("%d",&n);
        int num,resp=0;
        memset(arr,0,sizeof(int)*tamano);
        for(int i=0;i<n;i++){
            scanf("%d",&num);
            arr[num]++;
        }
        for(int i=0;i<tamano;i++){
            resp+=arr[i]%2;
            arr[i+1]+=arr[i]/2;
        }

        printf("%d\n",resp);
    }