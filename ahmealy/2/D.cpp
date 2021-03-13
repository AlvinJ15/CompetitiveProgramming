#include <bits/stdc++.h>
using namespace std;
main(){
  int n;
  int sum=0;
  vector<int> divisores;
  cin>>n;
  int arr[n];
  for(int i=0;i<n;i++){
    scanf("%d",&arr[i]);
    sum+=arr[i];
  }
  int var=(int)sqrt(n);
  for(int i=1;i<=var;i++){
    if(i==var && i*i==n){
      divisores.push_back(i);
      continue;
    }
    if(n%i==0){
      divisores.push_back(i);
      divisores.push_back(n/i);
    }
  }
  sort(divisores.begin(),divisores.begin()+divisores.size());
  int sum2;
  for(int i=1;i<divisores.size()-1;i++){
    sum2=0;
    if(n>=divisores[i]*3){
      for(int j=0;j<divisores[i];j++){
        sum2=0;
        for(int k=j;k<n;k+=divisores[i]){
          sum2+=arr[k];
        }
        sum=max(sum,sum2);
      }
    }
  }
  cout<<sum<<endl;
}
