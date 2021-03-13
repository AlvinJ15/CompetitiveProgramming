#include <bits/stdc++.h>
    using namespace std;

    int main(){
        vector<long long> vec;
        vector<long long> divisores;
        int j;
        long long num;

        scanf("%I64d",&num);
        if(num==1){printf("%d",1);return 0;}
        for(int i=2;i<sqrt(num);i++){
            if(!(num%i)){
                vec.push_back(i);
                vec.push_back(num/i);
            }
        }

        long long n  = (long long)sqrt(num);
    
        vec.push_back(num);
        if(n*n==num)
            vec.push_back(n);
        sort(vec.begin(),vec.begin()+vec.size());
        //imprimir(vec);
        for(int i=vec.size()-1;i>=0;i--){
            divisores.clear();
            for(j=i;j>=0;j--){
                if(!(vec[i]%vec[j])){
                    divisores.push_back(vec[j]);
                }
            }
            //imprimir(divisores);
            for(j=0;j<divisores.size();j++){
                n = (long long)sqrt(divisores[j]);
                if(n*n==divisores[j]){
                    break;
                }
            }
            if(j==divisores.size()){
                printf("%I64d\n",vec[i]);
                return 0;
            }
        }
    }