#include <bits/stdc++.h>
using namespace std;
int main(){
  int N;
    string palabra;
  cin>>N;
  cin>>palabra;
  int hash[27];
  memset(hash,0,sizeof hash);
  for(int i=0;i<palabra.size();i++){
    hash[palabra[i]-'a']++;
  }
  for(int i=0;i<26;i++){
    if((hash[i]%N)!=0){
      printf("-1\n");
      return 0;
    }
  }
  for(int h=0;h<N;h++){
    for(int i=0;i<26;i++){
      if(hash[i]==0)continue;
      for(int j=0;j<hash[i]/N;j++)
        printf("%c",i+'a');
    }
  }
  printf("\n");


}
