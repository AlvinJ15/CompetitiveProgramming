#include <bits/stdc++.h>
using namespace std;
main(){
  int n,k,z;
  cin>>n>>k;
  string numeros[n];
  for(int i=0;i<n;i++){
    cin>>numeros[i];
  }
  vector<int> perm(k);
  for(int i=0;i<k;i++){
    perm[i]=i;
  }
  vector<int> elementos;
  int var,minimo=1<<30;
  do{
    elementos.clear();
    for(int i=0;i<n;i++){
      var=0;
      for(int j=0;j<k;j++){
        var=var*10+numeros[i][perm[j]];
      }
      elementos.push_back(var);
    }
    sort(elementos.begin(),elementos.begin()+n);
    minimo=min(minimo,abs(elementos[0]-elementos[n-1]));

  }
  while(next_permutation(perm.begin(),perm.end()));
  printf("%d\n",minimo);

}
