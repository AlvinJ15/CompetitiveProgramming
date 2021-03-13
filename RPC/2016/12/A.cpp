#include <bits/stdc++.h>
using namespace std;
int main(){
  string p;
  cin>>p;
  for(int i=0;i<p.size();i++){
    if(p[i]=='i'){
      printf("N\n");
      return 0;
    }
  }
  printf("S\n");

}
