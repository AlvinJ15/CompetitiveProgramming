#include <bits/stdc++.h>
using namespace std;
int letras[26];
int contar(string a){
   
  int tam = a.size();
  for(int i=0;i<26;i++){
    letras[i]=0;
  }
  int count=0;
  for(int i=0;i<tam;i++){
    letras[a[i]-'a']++;
  }
  for( int i=0;i<26;i++){
    if(letras[i]!=0)
      count++;
  }
  return count;
}
main(){
  int n,resp,maximo=0;

  vector<string> palabras;
  string p;
  scanf("%d",&n);
  for(int i =0;i<n;i++){
    cin>>p;
    if(contar(p)<=2)
      palabras.push_back(p);
  }
  int k;
  for(int i='a';i<='z';i++){
    for(int j=i+1;j<='z';j++){
      resp=0;
      for(int h=0;h<palabras.size();h++){
        for(k=0;k<palabras[h].size();k++){
           if(palabras[h][k]==i || palabras[h][k]==j)
            continue;
          else
            break;
        }
        if(k==palabras[h].size())
          resp+=palabras[h].size(); 
      }
      maximo=max(maximo,resp);
    }
  }

 
  printf("%d\n",maximo);



}
