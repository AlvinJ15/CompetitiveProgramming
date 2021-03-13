#include <bits/stdc++.h>
using namespace std;
int hash[27];
int sgt;
bool flag;
int S;
pair<int,int> maxim;
vector<char> resp;
int sumar(){
  int r=0;

  for(int i=0;i<27;i++)
    r+=hash[i];
  return r;
}
pair<int,int> mayor(){
  pair<int,int> a=make_pair(-1,0);
  for(int i=0;i<27;i++){
    if(a.first<hash[i]){
      a.first=hash[i];
      a.second=i;
    }
  }
  return a;
}
int siguiente(int pos){
  for(int i=0;i<27;i++){
    if(pos==i)continue;
    if(hash[i]>0)return i;
  }
  return pos;
}
void recur(int i){
  S=sumar();
  if(S==0)return;
  if(S==1){
    resp.push_back(i+'a');
    return;
  }
  maxim=mayor();
  if(i==maxim.second)
    maxim.first--;
  if(S-maxim.first>=maxim.first){
    resp.push_back(i+'a');
    hash[i]--;
    if(sumar()==0)return;
    sgt=siguiente(i);
    if(i==sgt){
      flag=false;
      return;
    }
    else{
      recur(sgt);
    }
  }
  else{
    if(S-maxim.first+1==maxim.first){
       resp.push_back(maxim.second+'a');
       hash[maxim.second]--;
       recur(siguiente(maxim.second));
    }
    else{
      flag=false;
      return;
    }
  }
}
main(){
  int test,cnt;
  char c,val;
  scanf("%d",&test);
  scanf("\n");
  while(test--){
    memset(hash,0,sizeof hash);
    resp.clear();
    flag=true;
    cnt=0;
    while(scanf("%c",&c),c!='\n'&&c!=EOF){
      hash[c-'a']++;
      val=c;
      cnt++;
    }
    maxim=mayor();
    S=sumar();
    if(val==0){printf("%c\n",c);continue;}
    if(S-maxim.first>=maxim.first){
      recur(siguiente(-1));
    }
    else{
      if(S-maxim.first+1==maxim.first){
        resp.push_back(maxim.second+'a');
        hash[maxim.second]--;
        recur(siguiente(maxim.second));
      }
      else{
        printf("IMPOSSIBLE\n");
        continue;
      }
    }
    if(flag){
      for(int i=1;i<resp.size();i++){
        if(resp[i]==resp[i-1])
          flag=false;
      }
      if(!flag){printf("IMPOSSIBLE\n");continue;}
      for(int i=0;i<resp.size();i++)
        printf("%c",resp[i]);
      printf("\n");
    }
    else
      printf("IMPOSSIBLE\n");

  }
}
