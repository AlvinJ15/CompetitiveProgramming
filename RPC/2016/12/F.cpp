#include <bits/stdc++.h>
using namespace std;
char p[1000][105];
main(){
  	int T;
    cin>>T;
    vector<char> aux;
    int nD=0;int nR=0;int nDR=0;
    int dual=0;
    for(int i=0;i<T;i++){
      scanf("%105s",p[i]);
      int n = strlen(p[i]);
      aux.clear();
      for(int j=0;j<n;j++){
        if(p[i][j]=='D' || p[i][j]=='R')
          aux.push_back(p[i][j]);
      }
      for(int j=0;j<aux.size();j++){
        if(j>0){
          if(aux[j]=='R' && aux[j-1]=='D'){
            nDR+=1;
          }
        }
      } 
      bool a=false;bool b=false;
     if(aux.size()>0&&aux[0]=='R'){nR++;a=true;}
     if(aux.size()>0 && aux[aux.size()-1]=='D' ){nD++;b=true;}
     if(a&&b){
       nR--;nD--;
      dual++;
     }
    
     
    }
    int y = min(nD,nR);
    if(dual < y){
      nDR+=dual*2;
      nD-=dual;
      nR-=dual;
      dual=0;

    }
    else{
      dual-=y;
      nDR+=y*2;
      nD-=y;
      nR-=y;
    }
    int x = abs(nD-nR);
    if(x<=dual){
      nDR+=max(nD,nR);
      nDR+=(dual-x)/2;
    }
    else{
      if(nD<nR){
        nD+=dual;
      }
      else{
        nR+=dual;
      }
      nDR+=min(nD,nR);
    }
    cout<<nDR<<endl;
    


    

}
