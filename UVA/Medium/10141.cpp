#include <bits/stdc++.h>
using namespace std;
main(){
	int N,M,R,cases=1;
  char p[100];
  vector<string> carro;
  double precio;
  int resp;
  double maximo=-1;
  double complice;
  int i=0;
  double PM=-1;
  string p2;
  while(scanf("%d%d",&N,&M),N|M){
    maximo=-1;
    PM=-1;
    scanf("\n");
    carro.clear();
    if(cases!=1)
      printf("\n");

    for(i=0;i<N;i++){
      getline(cin,p2);
    }
    i=0;
    for(int h=0;h<M;h++){
      getline(cin,p2);
      carro.push_back(p2);
      scanf("%lf%d",&precio,&R);
      scanf("\n");
      for(int j=0;j<R;j++){
        getline(cin,p2);
      }
      complice =R/(double)N;
      if(complice>maximo){
        PM=precio;
        maximo=complice;
        resp=i;
      }
      else{
        if(complice==maximo){
          if(precio<PM){
            PM=precio;
            resp=i;
          }
        }
      }
      i++;
    }
    printf("RFP #%d\n",cases++);
    cout<<carro[resp]<<endl;
  }

}
