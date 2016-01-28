#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>

using namespace std;
#define pb push_back
int L,N;
vector<char> letras;
vector<int> resp;
int pc(int x){
  x= (x&0x55555555) + ((x>>1)&0x55555555);
  x= (x&0x33333333) + ((x>>2)&0x33333333);
  x= (x&0x0F0F0F0F) + ((x>>4)&0x0F0F0F0F);
  x= (x&0x00FF00FF) + ((x>>8)&0x00FF00FF);
  x= (x&0x0000FFFF) + ((x>>16)&0x0000FFFF);
  return x;
}
void recur(int bitmask,int pos,int count){
  if(count==L){
    resp.pb(bitmask);
    return;
  }
  if(L-count==N-pos){
    resp.pb(bitmask|((1<<(N-pos))-1));
    return;
  }
  recur(bitmask,pos+1,count);
  recur(bitmask|(1<<(N-pos-1)),pos+1,count+1);
}
main(){
  char c;
  scanf("%d%d",&L,&N);
  scanf("\n");
  for(int i=0;i<N;i++){
    scanf("%c ",&c);
    letras.pb(c);
  }
  sort(letras.begin(),letras.begin()+N);
  reverse(letras.begin(),letras.end());
  int vocal=0;
  int novocal=0;
  for(int i=0;i<letras.size();i++){
    if(letras[i]=='a'||letras[i]=='e'||letras[i]=='i'||letras[i]=='o'||letras[i]=='u'){
      vocal|=1<<i;
    }
    else
      novocal|=1<<i;
  }
  recur(0,0,0);
  int a=resp.size();
  reverse(resp.begin(),resp.end());
  for(int i=0;i<a;i++){
    if(pc(resp[i]&vocal)>=1 && pc(resp[i]&novocal)>=2){
      for(int j=N-1;j>=0;j--){
        if(resp[i]&(1<<j))
          printf("%c",letras[j]);
      }
      printf("\n");
    }

  }


}
