#include <bits/stdc++.h>
using namespace std;
int arr[18][14];
struct node{
  int precio;
  vector<int> camas;
  bool operator < (node x)const{
    return precio<x.precio;
  }
};
vector<node> elem;
main(){
  int N,B,H,W,v,cm,costo;
  node var;
  vector<int> precios;
  while(scanf("%d%d%d%d",&N,&B,&H,&W)!=EOF){
  int minimo=1<<30;
    for(int i=0;i<H;i++){
      scanf("%d",&costo);
      for(int j=0;j<W;j++){
        scanf("%d",&cm);
        if(cm>=N)
          minimo=min(minimo,costo);
      }
    }
    if(minimo==1<<30||minimo*N>B)
      printf("stay home\n");
    else
      printf("%d\n",minimo*N);
    
  

  }	


}
