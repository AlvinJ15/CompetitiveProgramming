#include <bits/stdc++.h>
using namespace std;
main(){
  string c;
  map<string,int> mapa;
  mapa.insert(make_pair("+x",1));
  mapa.insert(make_pair("-x",-1));
  mapa.insert(make_pair("+y",2));
  mapa.insert(make_pair("-y",-2));
  mapa.insert(make_pair("+z",3));
  mapa.insert(make_pair("-z",-3));
  mapa.insert(make_pair("No",0));
  int inicio,N;
	 while(scanf("%d",&N),N){
     inicio=1;
     for(int i=0;i<N-1;i++){
        cin>>c;
        if(mapa[c]==0)continue;
        if(inicio==1||inicio==-1)
          inicio=mapa[c]*inicio;
        else if(inicio==2||inicio==-2){
          if(mapa[c]==2||mapa[c]==-2){
             inicio=mapa[c]/-inicio;
          }
        }
        else{
          if(mapa[c]==3||mapa[c]==-3){
            inicio=mapa[c]/-inicio;
          }
        }
          
     }
   printf((inicio<0?"-":"+"));
   printf("%c\n",abs(inicio)+'x'-1);
   }


}
