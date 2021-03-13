#include <bits/stdc++.h>
using namespace std;
main(){
  int T;
  scanf("%d",&T);
  string input;
  int hash[3];
  scanf("\n");
  while(T--){
    memset(hash,0,sizeof hash);
    getline(cin,input);
    for(int i=0;i<input.size();i+=3){
      if(input[i]==' ')i-=2;
      if(input[i]=='F'&&input[i+1]=='F')
        hash[0]++;
      else if(input[i]=='M'&&input[i+1]=='M')
        hash[1]++;
      else
        hash[2]++;
    }
    if((hash[0]!=hash[1])||input.size()==2)
      printf("NO LOOP\n");
    else
      printf("LOOP\n");
    
  }


}
